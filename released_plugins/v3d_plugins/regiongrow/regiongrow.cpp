/* regiongrow.cpp
 * adapted from Hanchuan's region growing code
 * 2010-04-02: create this program by Yang Yu
 */

#include <QtGui>

#include <cmath>
#include <stdlib.h>
#include <ctime>

#include <vector>

#include <sstream>
#include <iostream>

#include "regiongrow.h"

#include <basic_surf_objs.h>
#include <volimg_proc.h>
#include <img_definition.h>
#include <basic_landmark.h>

#define INF 1E9
#define PI 3.14159265

// extension to 3D from Hanchuan 2D region growing codes
#define UBYTE unsigned char
#define BYTE signed char

volatile V3DLONG phcDebugPosNum = 0;
volatile V3DLONG phcDebugRgnNum = 0;

class POS
{
public:
	V3DLONG pos;
	V3DLONG order;
	POS * next;
	POS() 
	{
		pos = -1;order=-1;
		next = 0;
		phcDebugPosNum++;
	}
	~POS()
	{
		phcDebugPosNum--;
	}
};

class RGN
{
public:
	V3DLONG layer;
	V3DLONG no;
	POS *poslist;
	V3DLONG poslistlen;
	RGN * next;
	RGN() 
	{
		layer=no=-1;
		poslistlen=0;poslist=0;
		next=0;
		phcDebugRgnNum++;
	}
	~RGN()
	{
		layer=no=-1;
		poslistlen = 0;
		phcDebugRgnNum--;
	}
};

//statistics of count of labeling
class STCL
{
public:
	
	V3DLONG count;
	V3DLONG no;
	V3DLONG *desposlist;
	STCL *next;
	
	STCL() 
	{
		count=no=-1;
		next=0;
		phcDebugRgnNum++;
	}
	~STCL()
	{
		count=no=-1;
		phcDebugRgnNum--;
	}
};

//function of swap
template <class T>
void swap (T& x, T& y)
{
	T tmp = x;	x = y; y = tmp;
}

//function of quickSort
template <class T>
void quickSort(T a[], int l, int r)
{
	if(l>=r) return;
	int i = l;
	int j = r+1;
	
	T pivot = a[l];
	while(true)
	{
		do{ i = i+1; } while(a[i]>pivot);
		do{ j = j-1; } while(a[j]<pivot);
		if(i >= j) break;
		swap(a[i], a[j]);
	}
	a[l] = a[j];
	a[j] = pivot;
	quickSort(a, l, j-1);
	quickSort(a, j+1, r);
}

//memory management
template <class T> int newIntImage3dPairMatlabProtocal(T *** & img3d,T * & img1d, V3DLONG imgdep, V3DLONG imghei,V3DLONG imgwid)
{
	V3DLONG totalpxlnum = imghei*imgwid*imgdep;
	
	try
	{
		img1d = new T [totalpxlnum];
		img3d = new T ** [imgdep];
		
		V3DLONG i,j;
		
		for (i=0;i<imgdep;i++) 
		{
			img3d[i] = new T * [imghei];
			for(j=0; j<imghei; j++)
				img3d[i][j] = img1d + i*imghei*imgwid + j*imgwid;
			
		}
		
		memset(img1d, 0, sizeof(T)*totalpxlnum);
	}
	catch(...)
	{
		if (img1d) {delete img1d;img1d=0;}
		if (img3d) {delete img3d;img3d=0;}
		printf("Fail to allocate mem in newIntImage2dPairMatlabProtocal()!");
		return 0; //fail
	}
	
	return 1; //succeed
}

template <class T> void deleteIntImage3dPairMatlabProtocal(T *** & img3d,T * & img1d)
{
	if (img1d) {delete img1d;img1d=0;}
	if (img3d) {delete img3d;img3d=0;}
}

// region growing class
class RgnGrow3dClass
{
public:
	RgnGrow3dClass()
	{
		ImgWid = 0, ImgHei = 0, ImgDep = 0;
		quantImg1d=0; quantImg3d=0;
		PHCDONEIMG3d = 0, PHCDONEIMG1d = 0;
		
		STACKCNT = -1, MAXSTACKSIZE = 16, IFINCREASELABEL=-1, PHCURLABEL=-1;
		PHCLABELSTACK3d = 0, PHCLABELSTACK1d = 0;
		PHCLABELSTACKPOS = 0;
		
		PHCURGNPOS = 0, PHCURGNPOS_head = 0;
		PHCURGN = 0, PHCURGN_head = 0;
		TOTALPOSnum = 0, TOTALRGNnum = 0;
	}
	
	~RgnGrow3dClass()
	{
		deleteIntImage3dPairMatlabProtocal(quantImg3d,quantImg1d);
		deleteIntImage3dPairMatlabProtocal(PHCLABELSTACK3d,PHCLABELSTACK1d);
		deleteIntImage3dPairMatlabProtocal(PHCDONEIMG3d,PHCDONEIMG1d);
		
		ImgWid = 0, ImgHei = 0, ImgDep = 0;
		
		STACKCNT = -1, MAXSTACKSIZE = 16, IFINCREASELABEL=-1, PHCURLABEL=-1;
		PHCLABELSTACKPOS = 0;
		
		PHCURGN = PHCURGN_head;
		for(V3DLONG i=0;i<TOTALRGNnum;i++)
		{
			RGN * pnextRgn = 0;
			if (PHCURGN)
			{
				pnextRgn = PHCURGN->next;
				PHCURGNPOS = PHCURGN->poslist;
				for(V3DLONG j=0;j<PHCURGN->poslistlen;j++)
				{
					POS *pnextPos = 0;
					if (PHCURGNPOS) 
					{
						pnextPos = PHCURGNPOS->next;
						delete PHCURGNPOS;
					}
					PHCURGNPOS = pnextPos;
				}
				delete PHCURGN;
			}
			PHCURGN = pnextRgn;
		}
		TOTALPOSnum = 0, TOTALRGNnum = 0;
	}
	
public:
	V3DLONG ImgWid, ImgHei, ImgDep;
	UBYTE * quantImg1d,  *** quantImg3d;
	BYTE *** PHCDONEIMG3d, * PHCDONEIMG1d;
	
	int STACKCNT;
	int MAXSTACKSIZE;
	int IFINCREASELABEL;
	V3DLONG PHCURLABEL;
	int ***PHCLABELSTACK3d, * PHCLABELSTACK1d;
	V3DLONG PHCLABELSTACKPOS;
	
	POS * PHCURGNPOS, * PHCURGNPOS_head;
	RGN * PHCURGN, * PHCURGN_head;
	
	V3DLONG TOTALPOSnum, TOTALRGNnum;
}; 

//generating an int image for any input image type
template <class T> void copyvecdata(T * srcdata, V3DLONG len, UBYTE * desdata, int& nstate, UBYTE &minn, UBYTE &maxx)
{
	if(!srcdata || !desdata)
	{
		printf("NULL points in copyvecdata()!\n");
		return;
	} 
	
	V3DLONG i;
	
	//note: originally I added 0.5 before rounding, however seems the negative numbers and 
	//      positive numbers are all rounded towarded 0; hence int(-1+0.5)=0 and int(1+0.5)=1;
	//      This is unwanted because I need the above to be -1 and 1.
	// for this reason I just round with 0.5 adjustment for positive and negative differently
	
	//copy data
	if (srcdata[0]>0)
		maxx = minn = int(srcdata[0]+0.5);
	else
		maxx = minn = int(srcdata[0]-0.5);
	
	int tmp;
	double tmp1;
	for (i=0;i<len;i++)
	{
		tmp1 = double(srcdata[i]);
		tmp = (tmp1>0)?(int)(tmp1+0.5):(int)(tmp1-0.5);//round to integers
		minn = (minn<tmp)?minn:tmp;
		maxx = (maxx>tmp)?maxx:tmp;
		desdata[i] = (UBYTE)tmp;
	}
	maxx = (UBYTE)maxx;
	minn = (UBYTE)minn;
	
	//return the #state
	nstate = (maxx-minn+1);
	
	return;
}

//
void rgnfindsub(int rowi,int colj, int depk, int direction,int stackinc, RgnGrow3dClass * pRgnGrow)
{
	if (pRgnGrow->STACKCNT >= pRgnGrow->MAXSTACKSIZE)
	{
		if (pRgnGrow->IFINCREASELABEL != 0)
			pRgnGrow->IFINCREASELABEL = 0;
		return;
	}
	
	BYTE *** flagImg = pRgnGrow->PHCDONEIMG3d;
	int ImgWid = pRgnGrow->ImgWid;
	int ImgHei = pRgnGrow->ImgHei;
	int ImgDep = pRgnGrow->ImgDep;
	
	if (stackinc==1)
	{
		//printf("STACKCNT=%i PHCLABELSTACKPOS=%i\n",STACKCNT,PHCLABELSTACKPOS);
		pRgnGrow->PHCLABELSTACK3d[0][0][pRgnGrow->PHCLABELSTACKPOS] = depk;
		pRgnGrow->PHCLABELSTACK3d[0][1][pRgnGrow->PHCLABELSTACKPOS] = colj;
		pRgnGrow->PHCLABELSTACK3d[0][2][pRgnGrow->PHCLABELSTACKPOS] = rowi;
		
		pRgnGrow->STACKCNT++;
		pRgnGrow->PHCLABELSTACKPOS++;
		
		flagImg[depk][colj][rowi] = -1;//pRgnGrow->PHCDONEIMG2d[coli][rowj] = -1;
		//PHCLABELIMG[coli][rowj] = PHCURLABEL;
		
		//set the current pos location and return the 
		if (pRgnGrow->PHCURGNPOS)
		{
			pRgnGrow->PHCURGNPOS->pos = (V3DLONG) depk*(pRgnGrow->ImgHei * pRgnGrow->ImgWid) + colj*(pRgnGrow->ImgWid) + rowi; //
			pRgnGrow->PHCURGNPOS->next = new POS;
			if (pRgnGrow->PHCURGNPOS->next==0)
			{printf("Fail to do: pRgnGrow->PHCURGNPOS->next = new POS; -->current phcDebugPosNum=%i.\n",phcDebugPosNum);}
			pRgnGrow->PHCURGNPOS = pRgnGrow->PHCURGNPOS->next;
			pRgnGrow->TOTALPOSnum++;
			//printf("current pixel: row=%i col=%i total_pxl_visted=%i \n",rowj,coli,pRgnGrow->TOTALPOSnum);
		}
		else
		{
			printf("PHCURGNPOS is null!!\n");
		}
	}
	else //%if stackinc==0,
	{
		//pRgnGrow->PHCDONEIMG[coli][rowj] = -2;
		flagImg[depk][colj][rowi] = -2;
	}
	
	// % search 26 direction orders
	
	// 1
	if (rowi>0 && flagImg[depk][colj][rowi-1]==1)
		rgnfindsub(rowi-1,colj,depk,1,1,pRgnGrow); 
	// 2
	if (rowi<ImgWid-1 && flagImg[depk][colj][rowi+1]==1)
		rgnfindsub(rowi+1,colj,depk,1,1,pRgnGrow); 
	// 3
	if (colj>0 && flagImg[depk][colj-1][rowi]==1)
		rgnfindsub(rowi,colj-1,depk,1,1,pRgnGrow); 
	// 4
	if (colj<ImgHei-1 && flagImg[depk][colj+1][rowi]==1)
		rgnfindsub(rowi,colj+1,depk,1,1,pRgnGrow); 
	// 5
	if (depk>0 && flagImg[depk-1][colj][rowi]==1)
		rgnfindsub(rowi,colj,depk-1,1,1,pRgnGrow); 
	// 6
	if (depk<ImgDep-1 && flagImg[depk+1][colj][rowi]==1)
		rgnfindsub(rowi,colj,depk+1,1,1,pRgnGrow); 
	// 7
	if (rowi>0 && colj>0 && flagImg[depk][colj-1][rowi-1]==1)
		rgnfindsub(rowi-1,colj-1,depk,1,1,pRgnGrow); 
	// 8
	if (rowi<ImgWid-1 && colj>0 && flagImg[depk][colj-1][rowi+1]==1)
		rgnfindsub(rowi+1,colj-1,depk,1,1,pRgnGrow); 
	// 9
	if (rowi>0 && colj<ImgHei-1 && flagImg[depk][colj+1][rowi-1]==1)
		rgnfindsub(rowi-1,colj+1,depk,1,1,pRgnGrow); 
	// 10
	if (rowi>ImgWid && colj<ImgHei-1 && flagImg[depk][colj+1][rowi+1]==1)
		rgnfindsub(rowi+1,colj+1,depk,1,1,pRgnGrow); 
	// 11
	if (rowi>0 && depk>0 && flagImg[depk-1][colj][rowi-1]==1)
		rgnfindsub(rowi-1,colj,depk-1,1,1,pRgnGrow); 
	// 12
	if (rowi<ImgWid-1 && depk>0 && flagImg[depk-1][colj][rowi+1]==1)
		rgnfindsub(rowi+1,colj,depk-1,1,1,pRgnGrow); 
	// 13
	if (rowi>0 && depk<ImgDep-1 && flagImg[depk+1][colj][rowi-1]==1)
		rgnfindsub(rowi-1,colj,depk+1,1,1,pRgnGrow); 
	// 14
	if (rowi<ImgWid-1 && depk<ImgDep-1 && flagImg[depk+1][colj][rowi+1]==1)
		rgnfindsub(rowi+1,colj,depk+1,1,1,pRgnGrow); 
	// 15
	if (colj>0 && depk>0 && flagImg[depk-1][colj-1][rowi]==1)
		rgnfindsub(rowi,colj-1,depk-1,1,1,pRgnGrow); 
	// 16
	if (colj<ImgHei-1 && depk>0 && flagImg[depk-1][colj+1][rowi]==1)
		rgnfindsub(rowi,colj+1,depk-1,1,1,pRgnGrow); 
	// 17
	if (colj>0 && depk<ImgDep-1 && flagImg[depk+1][colj-1][rowi]==1)
		rgnfindsub(rowi,colj-1,depk+1,1,1,pRgnGrow); 
	// 18
	if (colj<ImgHei-1 && depk<ImgDep-1 && flagImg[depk+1][colj+1][rowi]==1)
		rgnfindsub(rowi,colj+1,depk+1,1,1,pRgnGrow);
	// 19
	if (rowi>0 && colj>0 && depk>0 && flagImg[depk-1][colj-1][rowi-1]==1)
		rgnfindsub(rowi-1,colj-1,depk-1,1,1,pRgnGrow);
	// 20
	if (rowi<ImgWid-1 && colj>0 && depk>0 && flagImg[depk-1][colj-1][rowi+1]==1)
		rgnfindsub(rowi+1,colj-1,depk-1,1,1,pRgnGrow);
	// 21
	if (rowi>0 && colj<ImgHei-1 && depk>0 && flagImg[depk-1][colj+1][rowi-1]==1)
		rgnfindsub(rowi-1,colj+1,depk-1,1,1,pRgnGrow);
	// 22
	if (rowi>0 && colj>0 && depk<ImgDep-1 && flagImg[depk+1][colj-1][rowi-1]==1)
		rgnfindsub(rowi-1,colj-1,depk+1,1,1,pRgnGrow);
	// 23
	if (rowi<ImgWid-1 && colj<ImgHei-1 && depk>0 && flagImg[depk-1][colj+1][rowi+1]==1)
		rgnfindsub(rowi+1,colj+1,depk-1,1,1,pRgnGrow);
	// 24
	if (rowi<ImgWid-1 && colj>0 && depk<ImgDep-1 && flagImg[depk+1][colj-1][rowi+1]==1)
		rgnfindsub(rowi+1,colj-1,depk+1,1,1,pRgnGrow);
	// 25
	if (rowi>0 && colj<ImgHei-1 && depk<ImgDep-1 && flagImg[depk+1][colj+1][rowi-1]==1)
		rgnfindsub(rowi-1,colj+1,depk+1,1,1,pRgnGrow);
	// 26
	if (rowi<ImgWid-1 && colj<ImgHei-1 && depk<ImgDep-1 && flagImg[depk+1][colj+1][rowi+1]==1)
		rgnfindsub(rowi+1,colj+1,depk+1,1,1,pRgnGrow);

	
	return;
}

//Q_EXPORT_PLUGIN2 ( PluginName, ClassName )
//The value of PluginName should correspond to the TARGET specified in the plugin's project file.
Q_EXPORT_PLUGIN2(regiongrow, RegionGrowPlugin);

void regiongrowing(V3DPluginCallback2 &callback, QWidget *parent);

//plugin funcs
const QString title = "Region Growing";
QStringList RegionGrowPlugin::menulist() const
{
    return QStringList() << tr("Region Growing")
						 << tr("About");
}

void RegionGrowPlugin::domenu(const QString &menu_name, V3DPluginCallback2 &callback, QWidget *parent)
{
    if (menu_name == tr("Region Growing"))
    {
    	regiongrowing(callback, parent);
    }
	else if (menu_name == tr("About"))
	{
		QMessageBox::information(parent, "Version info", QString("Region Growing Plugin 1.1 (April 02, 2010) developed by Yang Yu. (Peng Lab, Janelia Research Farm Campus, HHMI)"));
		return;
	}
}

void regiongrowing(V3DPluginCallback2 &callback, QWidget *parent)
{
    v3dhandleList win_list = callback.getImageWindowList();
	
	if(win_list.size()<1) 
	{
		QMessageBox::information(0, title, QObject::tr("No image is open."));
		return;
	}
	
	int start_t = clock(); // record time point
	
	int i1=0;
	
	Image4DSimple* subject = callback.getImage(win_list[i1]);
	ROIList pRoiList=callback.getROI(win_list[i1]);
	
	QString m_InputFileName = callback.getImageName(win_list[i1]);
	
	qDebug() << "name of image ..." << m_InputFileName;
	
	if (!subject)
	{
		QMessageBox::information(0, title, QObject::tr("No image is open."));
		return;
	}
	if (subject->getDatatype()!=V3D_UINT8)
	{
		QMessageBox::information(0, title, QObject::tr("This demo program only supports 8-bit data. Your current image data type is not supported."));
		return;
	}
	
    unsigned char* pSbject = subject->getRawData();
	
	V3DLONG sz0 = subject->getXDim();
    V3DLONG sz1 = subject->getYDim();
    V3DLONG sz2 = subject->getZDim();
	V3DLONG sz3 = subject->getCDim();
	
	V3DLONG pagesz_sub = sz0*sz1*sz2;
	
	//---------------------------------------------------------------------------------------------------------------------------------------------------
	//finding the bounding box of ROI
	bool vxy=true,vyz=true,vzx=true; // 3 2d-views
	
	QRect b_xy = pRoiList.at(0).boundingRect();
	QRect b_yz = pRoiList.at(1).boundingRect();
	QRect b_zx = pRoiList.at(2).boundingRect();
	
	if(b_xy.left()==-1 || b_xy.top()==-1 || b_xy.right()==-1 || b_xy.bottom()==-1)
		vxy=false;
	if(b_yz.left()==-1 || b_yz.top()==-1 || b_yz.right()==-1 || b_yz.bottom()==-1)
		vyz=false;
	if(b_zx.left()==-1 || b_zx.top()==-1 || b_zx.right()==-1 || b_zx.bottom()==-1)
		vzx=false;
		
	V3DLONG bpos_x, bpos_y, bpos_z, bpos_c, epos_x, epos_y, epos_z, epos_c;
	
	// 8 cases
	if(vxy && vyz && vzx) // all 3 2d-views
	{
		bpos_x = qBound(V3DLONG(0), V3DLONG(qMax(b_xy.left(), b_zx.left())), sz0-1);
		bpos_y = qBound(V3DLONG(0), V3DLONG(qMax(b_xy.top(),  b_yz.top())), sz1-1);
		bpos_z = qBound(V3DLONG(0), V3DLONG(qMax(b_yz.left(), b_zx.top())), sz2-1);
		
		epos_x = qBound(V3DLONG(0), V3DLONG(qMin(b_xy.right(), b_zx.right())), sz0-1);
		epos_y = qBound(V3DLONG(0), V3DLONG(qMin(b_xy.bottom(), b_yz.bottom())), sz1-1);
		epos_z = qBound(V3DLONG(0), V3DLONG(qMin(b_yz.right(), b_zx.bottom())), sz2-1);
	}
	else if(!vxy && vyz && vzx) // 2 of 3
	{
		bpos_x = qBound(V3DLONG(0), V3DLONG(qMax(0, b_zx.left())), sz0-1);
		bpos_y = qBound(V3DLONG(0), V3DLONG(qMax(0,  b_yz.top())), sz1-1);
		bpos_z = qBound(V3DLONG(0), V3DLONG(qMax(b_yz.left(), b_zx.top())), sz2-1);
		
		epos_x = qBound(V3DLONG(0), V3DLONG(qMin((V3DLONG)(sz0-1), (V3DLONG)b_zx.right())), sz0-1);
		epos_y = qBound(V3DLONG(0), V3DLONG(qMin((V3DLONG)(sz1-1), (V3DLONG)b_yz.bottom())), sz1-1);
		epos_z = qBound(V3DLONG(0), V3DLONG(qMin(b_yz.right(), b_zx.bottom())), sz2-1);
	}
	else if(vxy && !vyz && vzx)
	{
		bpos_x = qBound(V3DLONG(0), V3DLONG(qMax(b_xy.left(), b_zx.left())), sz0-1);
		bpos_y = qBound(V3DLONG(0), V3DLONG(qMax(b_xy.top(),  0)), sz1-1);
		bpos_z = qBound(V3DLONG(0), V3DLONG(qMax(0, b_zx.top())), sz2-1);
		
		epos_x = qBound(V3DLONG(0), V3DLONG(qMin(b_xy.right(), b_zx.right())), sz0-1);
		epos_y = qBound(V3DLONG(0), V3DLONG(qMin((V3DLONG)b_xy.bottom(), (V3DLONG)(sz1-1))), sz1-1);
		epos_z = qBound(V3DLONG(0), V3DLONG(qMin((V3DLONG)(sz2-1), (V3DLONG)b_zx.bottom())), sz2-1);
	}
	else if(vxy && vyz && !vzx)
	{
		bpos_x = qBound(V3DLONG(0), V3DLONG(qMax(b_xy.left(), 0)), sz0-1);
		bpos_y = qBound(V3DLONG(0), V3DLONG(qMax(b_xy.top(),  b_yz.top())), sz1-1);
		bpos_z = qBound(V3DLONG(0), V3DLONG(qMax(b_yz.left(), 0)), sz2-1);
		
		epos_x = qBound(V3DLONG(0), V3DLONG(qMin((V3DLONG)b_xy.right(), (V3DLONG)(sz0-1))), sz0-1);
		epos_y = qBound(V3DLONG(0), V3DLONG(qMin(b_xy.bottom(), b_yz.bottom())), sz1-1);
		epos_z = qBound(V3DLONG(0), V3DLONG(qMin((V3DLONG)b_yz.right(), (V3DLONG)(sz2-1))), sz2-1);
	}
	else if(vxy && !vyz && !vzx) // only 1 of 3
	{
		bpos_x = qBound(V3DLONG(0), V3DLONG(qMax(b_xy.left(), 0)), sz0-1);
		bpos_y = qBound(V3DLONG(0), V3DLONG(qMax(b_xy.top(),  0)), sz1-1);
		bpos_z = 0;
		
		epos_x = qBound(V3DLONG(0), V3DLONG(qMin((V3DLONG)b_xy.right(), (V3DLONG)(sz0-1))), sz0-1);
		epos_y = qBound(V3DLONG(0), V3DLONG(qMin((V3DLONG)b_xy.bottom(), (V3DLONG)(sz1-1))), sz1-1);
		epos_z = sz2-1;
	}
	else if(!vxy && vyz && !vzx)
	{
		bpos_x = 0;
		bpos_y = qBound(V3DLONG(0), V3DLONG(qMax(0,  b_yz.top())), sz1-1);
		bpos_z = qBound(V3DLONG(0), V3DLONG(qMax(b_yz.left(), 0)), sz2-1);
		
		epos_x = sz0-1;
		epos_y = qBound(V3DLONG(0), V3DLONG(qMin((V3DLONG)(sz1-1), (V3DLONG)b_yz.bottom())), sz1-1);
		epos_z = qBound(V3DLONG(0), V3DLONG(qMin((V3DLONG)b_yz.right(), (V3DLONG)(sz2-1))), sz2-1);
	}
	else if(!vxy && !vyz && vzx)
	{
		bpos_x = qBound(V3DLONG(0), V3DLONG(qMax(0, b_zx.left())), sz0-1);
		bpos_y = 0;
		bpos_z = qBound(V3DLONG(0), V3DLONG(qMax(0, b_zx.top())), sz2-1);
		
		epos_x = qBound(V3DLONG(0), V3DLONG(qMin((V3DLONG)(sz0-1), (V3DLONG)b_zx.right())), sz0-1);
		epos_y = sz1-1;
		epos_z = qBound(V3DLONG(0), V3DLONG(qMin((V3DLONG)(sz2-1), (V3DLONG)b_zx.bottom())), sz2-1);
	}
	else // 0
	{
		bpos_x = 0;
		bpos_y = 0;
		bpos_z = 0;
		
		epos_x = sz0-1;
		epos_y = sz1-1;
		epos_z = sz2-1;
	}

	//qDebug("x %d y %d z %d x %d y %d z %d ",bpos_x,bpos_y,bpos_z,epos_x,epos_y,epos_z);

	//ROI extraction
	V3DLONG sx = (epos_x-bpos_x)+1;
    V3DLONG sy = (epos_y-bpos_y)+1;
    V3DLONG sz = (epos_z-bpos_z)+1;
	V3DLONG sc = sz3; // 0,1,2
	
	//choose the channel stack
	V3DLONG pagesz = sx*sy*sz;
	
	double meanv=0, stdv=0;
	
	V3DLONG offset_sub = 0;
	
	//------------------------------------------------------------------------------------------------------------------------------------
	
	unsigned char *data1d = new unsigned char [pagesz];
	if (!data1d) 
	{
		printf("Fail to allocate memory.\n");
		return;
	}
	else
	{
		for(V3DLONG k=bpos_z; k<=epos_z; k++)
		{
			V3DLONG offset_z = k*sz0*sz1;
			V3DLONG offset_crop_z = (k-bpos_z)*sx*sy;
			for(V3DLONG j=bpos_y; j<=epos_y; j++)
			{
				V3DLONG offset_y = j*sz0 + offset_z;
				V3DLONG offset_crop_y = (j-bpos_y)*sx + offset_crop_z;
				for(V3DLONG i=bpos_x; i<=epos_x; i++)
				{
					data1d[(i-bpos_x) + offset_crop_y] = pSbject[offset_sub + i+offset_y];
					
					meanv += data1d[(i-bpos_x) + offset_crop_y];
				}
			}
		}
	}
	meanv /= pagesz;
	
	for(V3DLONG i=0; i<pagesz; i++)
		stdv += (data1d[i] - meanv)*(data1d[i] - meanv);
	
	stdv /= (pagesz-1);
	stdv = sqrt(stdv);
	
	qDebug() << "meanv ..." << meanv << "stdv ..." << stdv;
	
	//----------------------------------------------------------------------------------------------------------------------------------
	
	// de-alloc
	//if (pSbject) {delete []pSbject; pSbject=0;} // image visualized in v3d now
	
	// bw
	unsigned char *bw = new unsigned char [pagesz];
	
	unsigned char threshold = meanv + stdv;
	
	for(V3DLONG i=0; i<pagesz; i++)
		bw[i] = (data1d[i]>threshold)?1:0;
	
	
	//
	V3DLONG offset_y, offset_z;
	
	offset_y=sx;
	offset_z=sx*sy;
	
	V3DLONG neighborhood_26[26] = {-1, 1, -offset_y, offset_y, -offset_z, offset_z,
								-offset_y-1, -offset_y+1, -offset_y-offset_z, -offset_y+offset_z, 
								offset_y-1, offset_y+1, offset_y-offset_z, offset_y+offset_z,
								offset_z-1, offset_z+1, -offset_z-1, -offset_z+1,
								-1-offset_y-offset_z, -1-offset_y+offset_z, -1+offset_y-offset_z, -1+offset_y+offset_z,
								1-offset_y-offset_z, 1-offset_y+offset_z, 1+offset_y-offset_z, 1+offset_y+offset_z}; 
	V3DLONG neighbors = 26;
	
	// eliminate volume with only one single voxel
	for(V3DLONG k = 0; k < sz; k++) 
	{				
		V3DLONG idxk = k*offset_z;
		for(V3DLONG j = 0;  j < sy; j++) 
		{
			V3DLONG idxj = idxk + j*offset_y;
			
			for(V3DLONG i = 0, idx = idxj; i < sx;  i++, idx++) 
			{
				
				if(i==0 || i==sx-1 || j==0 || j==sy-1 || k==0 || k==sz-1)
					continue;
				
				if(bw[idx])
				{
					bool one_point = true;
					for(int ineighbor=0; ineighbor<neighbors; ineighbor++)
					{
						V3DLONG n_idx = idx + neighborhood_26[ineighbor];
						
						if(bw[n_idx])
						{
							one_point = false;
							break;
						}
						
					}
					
					if(one_point==true)
						bw[idx] = 0;
				}
					
			}
		}
	}
	
	// display BW image
	Image4DSimple p4Dbw;
	p4Dbw.setData((unsigned char*)bw, sx, sy, sz, 1, V3D_UINT8);
	
	v3dhandle newwinbw = callback.newImageWindow();
	callback.setImage(newwinbw, &p4Dbw);
	callback.setImageName(newwinbw, "bw");
	callback.updateImageWindow(newwinbw);

	// 3D region growing
	//----------------------------------------------------------------------------------------------------------------------------------

	//declaration
	V3DLONG totalpxlnum=pagesz;
	
	RgnGrow3dClass * pRgnGrow = new RgnGrow3dClass;
	if (!pRgnGrow)
	{
		printf("Fail to allocate memory for RgnGrow3dClass().");
	}
	
	pRgnGrow->ImgDep = sz;
	pRgnGrow->ImgHei = sy;
	pRgnGrow->ImgWid = sx;
	
	newIntImage3dPairMatlabProtocal(pRgnGrow->quantImg3d,pRgnGrow->quantImg1d,pRgnGrow->ImgDep,pRgnGrow->ImgHei,pRgnGrow->ImgWid);
	
	int nstate;
	UBYTE minlevel,maxlevel;
	
	copyvecdata((unsigned char *)bw,totalpxlnum,pRgnGrow->quantImg1d,nstate,minlevel,maxlevel); 
	
	//don't count lowest level (background here = 0)
	minlevel = minlevel+1;
	if (minlevel>maxlevel) 
		minlevel = maxlevel; //at least do one level
	
	//begin computation
	phcDebugPosNum = 0;
	phcDebugRgnNum = 0;
	
	newIntImage3dPairMatlabProtocal(pRgnGrow->PHCLABELSTACK3d,pRgnGrow->PHCLABELSTACK1d,1,3,totalpxlnum);
	pRgnGrow->PHCLABELSTACKPOS = 0;
	
	pRgnGrow->PHCURGN = new RGN;
	if (!pRgnGrow->PHCURGN)
	{
		printf("Unable to do:pRgnGrow->PHCURGN = new RGN;  -->current phcDebugRgnNum=%i.\n",phcDebugRgnNum);
	}
	pRgnGrow->PHCURGN_head = pRgnGrow->PHCURGN;
	pRgnGrow->TOTALRGNnum = 1;
	
	deleteIntImage3dPairMatlabProtocal(pRgnGrow->PHCDONEIMG3d,pRgnGrow->PHCDONEIMG1d);
	newIntImage3dPairMatlabProtocal(pRgnGrow->PHCDONEIMG3d,pRgnGrow->PHCDONEIMG1d,pRgnGrow->ImgDep,pRgnGrow->ImgHei,pRgnGrow->ImgWid);
	
	for(int j=minlevel;j<=maxlevel;j++)
	{
		int depk, colj, rowi;
		
		BYTE * PHCDONEIMG1d = pRgnGrow->PHCDONEIMG1d;
		UBYTE * quantImg1d = pRgnGrow->quantImg1d;
		BYTE *** flagImg = pRgnGrow->PHCDONEIMG3d;
		for (V3DLONG tmpi=0; tmpi<totalpxlnum; tmpi++)
		{
			PHCDONEIMG1d[tmpi] = (quantImg1d[tmpi]==(UBYTE)j)?1:0;
		}
		
		pRgnGrow->PHCURLABEL = 0;
		
		for(depk=0; depk<pRgnGrow->ImgDep; depk++)
			for(colj=0; colj<pRgnGrow->ImgHei; colj++)
				for(rowi=0; rowi<pRgnGrow->ImgWid; rowi++)
				{
					if (flagImg[depk][colj][rowi]==1)
					{
						pRgnGrow->IFINCREASELABEL = 1;
						
						pRgnGrow->PHCURLABEL++;
						
						pRgnGrow->PHCLABELSTACKPOS = 0;
						
						pRgnGrow->PHCLABELSTACK3d[0][0][pRgnGrow->PHCLABELSTACKPOS] = depk;
						pRgnGrow->PHCLABELSTACK3d[0][1][pRgnGrow->PHCLABELSTACKPOS] = colj;
						pRgnGrow->PHCLABELSTACK3d[0][2][pRgnGrow->PHCLABELSTACKPOS] = rowi;
						
						//create pos memory
						pRgnGrow->PHCURGNPOS = new POS;
						if (pRgnGrow->PHCURGNPOS==0)
						{
							printf("Fail to allocate memory! -->cur phcDebugPosNum=%i.\n",phcDebugPosNum);
						}
						pRgnGrow->PHCURGNPOS_head = pRgnGrow->PHCURGNPOS;
						pRgnGrow->TOTALPOSnum = 1;
						
						while(1)
						{
							pRgnGrow->IFINCREASELABEL = 1;
							V3DLONG posbeg = pRgnGrow->PHCLABELSTACKPOS;
							V3DLONG mypos = posbeg;
							
							while (mypos>=0)
							{
								pRgnGrow->STACKCNT = 0;
								int curdep = pRgnGrow->PHCLABELSTACK3d[0][0][mypos];
								int curcol = pRgnGrow->PHCLABELSTACK3d[0][1][mypos];
								int currow = pRgnGrow->PHCLABELSTACK3d[0][2][mypos];
								
								if (flagImg[curdep][curcol][currow]==1)
								{
									rgnfindsub(currow,curcol,curdep,0,1,pRgnGrow);
								}
								else if(flagImg[curdep][curcol][currow]==-1)
								{
									rgnfindsub(currow,curcol,curdep,0,0,pRgnGrow);
								}
								
								V3DLONG posend = pRgnGrow->PHCLABELSTACKPOS;
								
								if (posend>posbeg) 
								{mypos = pRgnGrow->PHCLABELSTACKPOS;}
								else 
								{mypos = mypos-1;}
								posbeg = posend;
							}
							
							if (pRgnGrow->IFINCREASELABEL==1)
								break;
						}
						
						//set pos as member of current RGN
						pRgnGrow->PHCURGN->layer = j;
						pRgnGrow->PHCURGN->no = pRgnGrow->PHCURLABEL;
						pRgnGrow->PHCURGN->poslist = pRgnGrow->PHCURGNPOS_head;
						pRgnGrow->PHCURGN->poslistlen = pRgnGrow->TOTALPOSnum;
						
						pRgnGrow->TOTALPOSnum = 0;
						
						pRgnGrow->PHCURGN->next = new RGN;
						if(pRgnGrow->PHCURGN->next==0)
						{printf("fail to do --> pRgnGrow->PHCURGN->next = new RGN;\n");}
						pRgnGrow->PHCURGN = pRgnGrow->PHCURGN->next;
						pRgnGrow->TOTALRGNnum++;
					}
				} 
	}
	
	//
	int end_t = clock();
	
	qDebug() << "region growing time elapse ..." << end_t-start_t;
	
	
	//find the second big area in labeling
	STCL *staRegion = new STCL;
	STCL *staRegion_begin = staRegion;
	RGN *curRgn = pRgnGrow->PHCURGN_head;
	V3DLONG nrgncopied = 0; //num of rgn output
	
	std::vector<STCL> stclList;
	
	while(curRgn && curRgn->next)
	{
		V3DLONG i = nrgncopied;
		
		qDebug() << "num of rgn ..." << i << curRgn->no << curRgn->next->no;
		
		staRegion->no = curRgn->no;
		staRegion->count = 0;
		
		POS * curPos = curRgn->poslist;
		
		V3DLONG count = 0;
		staRegion->desposlist = new V3DLONG [curRgn->poslistlen-1];
		while(curPos && curPos->next)
		{
			staRegion->desposlist[count++] = curPos->pos;
			curPos = curPos->next;
		}
		staRegion->count = count;
		
		qDebug() << "pixels ..." << count;
		
		//
		if(stclList.size()<1)
			stclList.push_back(*staRegion);
		else
		{
			for(unsigned int it=stclList.size(); it!=0; it--)
			{
				if(staRegion->count<=stclList.at(it-1).count)
				{
					stclList.insert(stclList.begin() + it, 1, *staRegion);
					
					if(stclList.size()>5) // pick 5 points
						stclList.erase(stclList.end()-1);
					
					break;
				}
				else
					continue;
				
			}
			
			//
			if(staRegion->count>stclList.at(0).count) // pick 5 points
				stclList.insert(stclList.begin(), *staRegion);
			
			if(stclList.size()>5) // pick 5 points
				stclList.erase(stclList.end()-1);
		}
		
		//
		curRgn = curRgn->next;
		staRegion->next = new STCL;
		staRegion = staRegion->next;
		
		nrgncopied++; 
		
	}	
	//staRegion = staRegion_begin;
	
	// result pointer
	memset(data1d, 0, pagesz);
	
	V3DLONG length;
	
	V3DLONG n_rgn = stclList.size(); // qMin(5, nrgncopied);
	
	qDebug() << "display "<< n_rgn<<" rgns from "<< nrgncopied;
	
	LandmarkList cmList;
	
	for(int ii=0; ii<n_rgn; ii++)
	{
		length = stclList.at(ii).count; //a[ii];
		
		qDebug() << "region ..." << ii << length;
		
		// find idx
		V3DLONG *cutposlist = stclList.at(ii).desposlist;
		
		float scx=0,scy=0,scz=0,si=0;
		
		for(int i=0; i<length; i++)
		{
			//qDebug() << "idx ..." << i << cutposlist[i] << pagesz;
			
			data1d[ cutposlist[i] ] = 255;
			
			float cv = pSbject[ cutposlist[i] ];
			
			V3DLONG idx = cutposlist[i];
			
			V3DLONG k1 = idx/(sx*sy);
			V3DLONG j1 = (idx - k1*sx*sy)/sx;
			V3DLONG i1 = idx - k1*sx*sy - j1*sx;
			
			scz += k1*cv;
			scy += j1*cv;
			scx += i1*cv;
			si += cv;
		}
		
		if (si>0)
		{
			V3DLONG ncx = scx/si + 0.5 +1; 
			V3DLONG ncy = scy/si + 0.5 +1; 
			V3DLONG ncz = scz/si + 0.5 +1;
		
			LocationSimple pp(ncx, ncy, ncz);
			cmList.push_back(pp);

		}
		
	}
	
	int end_t_t = clock();
	
	qDebug() << "time elapse ..." << end_t_t - end_t;
	
	// display the biggest five regions
	Image4DSimple p4DImage;
	p4DImage.setData((unsigned char*)data1d, sx, sy, sz, 1, V3D_UINT8); // data1d
	
	v3dhandle newwin = callback.newImageWindow();
	callback.setImage(newwin, &p4DImage);
	callback.setImageName(newwin, "region_growing");
	callback.setLandmark(newwin, cmList); // center of mass
	callback.updateImageWindow(newwin);
	
}
