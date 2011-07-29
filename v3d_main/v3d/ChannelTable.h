/*
 * Copyright (c)2006-2010  Hanchuan Peng (Janelia Farm, Howard Hughes Medical Institute).
 * All rights reserved.
 */


/************
                                            ********* LICENSE NOTICE ************

This folder contains all source codes for the V3D project, which is subject to the following conditions if you want to use it.

You will ***have to agree*** the following terms, *before* downloading/using/running/editing/changing any portion of codes in this package.

1. This package is free for non-profit research, but needs a special license for any commercial purpose. Please contact Hanchuan Peng for details.

2. You agree to appropriately cite this work in your related studies and publications.

Peng, H., Ruan, Z., Long, F., Simpson, J.H., and Myers, E.W. (2010) “V3D enables real-time 3D visualization and quantitative analysis of large-scale biological image data sets,” Nature Biotechnology, Vol. 28, No. 4, pp. 348-353, DOI: 10.1038/nbt.1612. ( http://penglab.janelia.org/papersall/docpdf/2010_NBT_V3D.pdf )

Peng, H, Ruan, Z., Atasoy, D., and Sternson, S. (2010) “Automatic reconstruction of 3D neuron structures using a graph-augmented deformable model,” Bioinformatics, Vol. 26, pp. i38-i46, 2010. ( http://penglab.janelia.org/papersall/docpdf/2010_Bioinfo_GD_ISMB2010.pdf )

3. This software is provided by the copyright holders (Hanchuan Peng), Howard Hughes Medical Institute, Janelia Farm Research Campus, and contributors "as is" and any express or implied warranties, including, but not limited to, any implied warranties of merchantability, non-infringement, or fitness for a particular purpose are disclaimed. In no event shall the copyright owner, Howard Hughes Medical Institute, Janelia Farm Research Campus, or contributors be liable for any direct, indirect, incidental, special, exemplary, or consequential damages (including, but not limited to, procurement of substitute goods or services; loss of use, data, or profits; reasonable royalties; or business interruption) however caused and on any theory of liability, whether in contract, strict liability, or tort (including negligence or otherwise) arising in any way out of the use of this software, even if advised of the possibility of such damage.

4. Neither the name of the Howard Hughes Medical Institute, Janelia Farm Research Campus, nor Hanchuan Peng, may be used to endorse or promote products derived from this software without specific prior written permission.

*************/



/*
 * channelTable.h
 *
 *  Created on: Jul 18, 2011
 *      Author: ruanz
 */

#ifndef CHANNELTABLE_H_
#define CHANNELTABLE_H_

#include <vector>
#include <QtGui>
#include "../basic_c_fun/color_xyz.h"
#include "v3d_core.h"


// lookup and mix multi-channel to RGBA8
#define OP_MAX	0
#define OP_SUM	1
#define OP_MEAN	2
#define OP_OIT	3
#define OP_INDEX	-1

struct Channel
{
	int n;				// index
	bool on;
	RGBA8 color;
	Channel() {n=0; on=true; color.r=color.g=color.b=color.a=255;}
};

struct MixOP
{
	int op;
	bool rescale;
	bool maskR, maskG, maskB;
	float brightness, contrast; //ratio
	MixOP() {op=OP_MAX; rescale=false; maskR=maskG=maskB=true;
			brightness=0; contrast=1;}
};


void make_linear_lut_one(RGBA8 color, vector<RGBA8>& lut);
void make_linear_lut(vector<RGBA8>& colors, vector< vector<RGBA8> >& luts);

inline RGB8 lookup_mix(vector<unsigned char>& mC, vector< vector<RGBA8> >& mLut, int op, RGB8 mask=XYZ(255,255,255));


template <class T> QPixmap copyRaw2QPixmap_Slice( //test function for 4 channels
		ImagePlaneDisplayType cplane,
		V3DLONG cpos,
		const T **** p4d,
		V3DLONG sz0,
		V3DLONG sz1,
		V3DLONG sz2,
		V3DLONG sz3,
		ImageDisplayColorType Ctype,
		bool bRescale,
		double *p_vmax,
		double *p_vmin)
{

	V3DLONG x,y,z,pp;

	int N = MIN(sz3, 4); ////////////////

	vector<float> vrange(N);
	for (int k=0; k<N; k++)
	{
		vrange[k] = p_vmax[k]-p_vmin[k];
		if (vrange[k]<=0) vrange[k] = 1;
	}

	//qDebug()<<"copyRaw2QPixmap_Slice switch (Ctype)"<<Ctype;

	//set lookup-table
	vector< vector<RGBA8> > luts(4);
	vector<RGBA8> lut(256);
	RGBA8 _Red		= XYZW(255,0,0,255);
	RGBA8 _Green	= XYZW(0,255,0,255);
	RGBA8 _Blue		= XYZW(0,0,255,255);
	RGBA8 _Gray		= XYZW(255,255,255,255);
	RGBA8 _Blank	= XYZW(0,0,0,0);
	switch (Ctype)
	{
		case colorGray: //070716
			make_linear_lut_one( _Gray, lut );
			luts[0] = lut;
			luts[1] = lut;
			luts[2] = lut;
			luts[3] = lut;
			break;

		case colorRedOnly:
			make_linear_lut_one( _Red, lut );
			luts[0] = lut;
			make_linear_lut_one( _Blank, lut );
			luts[1] = lut;
			luts[2] = lut;
			luts[3] = lut;
			break;

		case colorRed2Gray:
			make_linear_lut_one( _Gray, lut );
			luts[0] = lut;
			make_linear_lut_one( _Blank, lut );
			luts[1] = lut;
			luts[2] = lut;
			luts[3] = lut;
			break;

		case colorGreenOnly:
			make_linear_lut_one( _Green, lut );
			luts[1] = lut;
			make_linear_lut_one( _Blank, lut );
			luts[0] = lut;
			luts[2] = lut;
			luts[3] = lut;
			break;

		case colorGreen2Gray:
			make_linear_lut_one( _Gray, lut );
			luts[1] = lut;
			make_linear_lut_one( _Blank, lut );
			luts[0] = lut;
			luts[2] = lut;
			luts[3] = lut;
			break;

		case colorBlueOnly:
			make_linear_lut_one( _Blue, lut );
			luts[2] = lut;
			make_linear_lut_one( _Blank, lut );
			luts[0] = lut;
			luts[1] = lut;
			luts[3] = lut;
			break;

		case colorBlue2Gray:
			make_linear_lut_one( _Gray, lut );
			luts[2] = lut;
			make_linear_lut_one( _Blank, lut );
			luts[0] = lut;
			luts[1] = lut;
			luts[3] = lut;
			break;

		case colorRGB:
			make_linear_lut_one( _Red, lut );
			luts[0] = lut;
			make_linear_lut_one( _Green, lut );
			luts[1] = lut;
			make_linear_lut_one( _Blue, lut );
			luts[2] = lut;
			make_linear_lut_one( _Blank, lut );
			luts[3] = lut;
			break;

		case colorRG:
			make_linear_lut_one( _Red, lut );
			luts[0] = lut;
			make_linear_lut_one( _Green, lut );
			luts[1] = lut;
			make_linear_lut_one( _Blank, lut );
			luts[2] = lut;
			luts[3] = lut;
			break;

		case colorUnknown:
		default:
			break;
	}

	// transfer N channel's pixels
	int op =  (Ctype == colorGray)? OP_MEAN : OP_MAX;
	vector<unsigned char> mC(N);
	QImage tmpimg;

	//qDebug()<<"copyRaw2QPixmap_Slice switch (cplane)"<<cplane;

	switch (cplane) //QImage(w,h)
	{
	case imgPlaneX: //(Z,Y)
		pp = (cpos>sz0)? sz0-1:cpos-1;   pp = (pp<0)? 0:pp;
		tmpimg = QImage(sz2, sz1, QImage::Format_RGB32);

		for (y=0; y<sz1; y++)
		for (z=0; z<sz2; z++)
			{
				for (int k=0; k<N; k++)
				{
					float C = p4d[k][z][y][pp];
					mC[k] =  ( (! bRescale) ? C : floor((C-p_vmin[k])/vrange[k]*255) );
				}
				RGB8 o = lookup_mix(mC, luts, op);
				tmpimg.setPixel(z, y, qRgb(o.r, o.g, o.b));
				//qDebug("(x) y z = (%d/%d) %d/%d %d/%d", pp,sz0, y,sz1, z,sz2);
			}
		break;

	case imgPlaneY: //(X,Z)
		pp = (cpos>sz1)? sz1-1:cpos-1;   pp = (pp<0)? 0:pp;
		tmpimg = QImage(sz0, sz2, QImage::Format_RGB32);

		for (z=0; z<sz2; z++)
		for (x=0; x<sz0; x++)
			{
				for (int k=0; k<N; k++)
				{
					float C = p4d[k][z][pp][x];
					mC[k] =  ( (! bRescale) ? C : floor((C-p_vmin[k])/vrange[k]*255) );
				}
				RGB8 o = lookup_mix(mC, luts, op);
				tmpimg.setPixel(x, z, qRgb(o.r, o.g, o.b));
				//qDebug("x (y) z = %d/%d (%d/%d) %d/%d", x,sz0, pp,sz1, z,sz2);
			}
		break;

	case imgPlaneZ: //(X,Y)
		pp = (cpos>sz2)? sz2-1:cpos-1;   pp = (pp<0)? 0:pp;
		tmpimg = QImage(sz0, sz1, QImage::Format_RGB32);

		for (y=0; y<sz1; y++)
		for (x=0; x<sz0; x++)
			{
				for (int k=0; k<N; k++)
				{
					float C = p4d[k][pp][y][x];
					mC[k] =  ( (! bRescale) ? C : floor((C-p_vmin[k])/vrange[k]*255) );
				}
				RGB8 o = lookup_mix(mC, luts, op);
				tmpimg.setPixel(x, y, qRgb(o.r, o.g, o.b));
				//qDebug("x y (z) = %d/%d %d/%d (%d/%d)", x,sz0, y,sz1, pp,sz2);
			}
		break;
	}

	//qDebug()<<"copyRaw2QPixmap_Slice fromImage(tmpimg)"<<tmpimg.size();

	return QPixmap::fromImage(tmpimg);
}


template <class T> QPixmap copyRaw2QPixmap_Slice( //real function include brightness/contrast
		const QList<Channel> & listChannel,
		const MixOP & mixOp,
		ImagePlaneDisplayType cplane,
		V3DLONG cpos,
		T **** p4d,  //no const for using macro expansion
		V3DLONG sz0,
		V3DLONG sz1,
		V3DLONG sz2,
		V3DLONG sz3,
		double *p_vmax,
		double *p_vmin)
{

	V3DLONG x,y,z,pp;

	int N = MIN(sz3, listChannel.size()); ////////////////

	vector<float> vrange(N);
	for (int k=0; k<N; k++)
	{
		vrange[k] = p_vmax[k]-p_vmin[k];
		if (vrange[k]<=0)  vrange[k] = 1;
	}

	//qDebug()<<"copyRaw2QPixmap_Slice switch (Ctype)"<<Ctype;

	//set lookup-table
	vector< vector<RGBA8> > luts(N);
	vector<RGBA8> lut(256);
	for (int k=0; k<N; k++)
	{
		make_linear_lut_one( listChannel[k].color, lut );
		luts[k] = lut;
	}

	// transfer N channel's pixels
	bool bRescale = mixOp.rescale;
	float fb = mixOp.brightness;
	float fc = mixOp.contrast;
	int op =  mixOp.op;
	RGB8 mask;
	mask.r = (mixOp.maskR)? 255:0;
	mask.g = (mixOp.maskG)? 255:0;
	mask.b = (mixOp.maskB)? 255:0;

	vector<unsigned char> mC(N);
	QImage tmpimg;

	//qDebug()<<"copyRaw2QPixmap_Slice switch (cplane)"<<cplane;

#define BRIGHTEN_TRANSFORM( C ) \
	if (fc != 1 || fb != 0) \
	{ \
		C = C*(fc) + (fb*vrange[k]); \
		C = CLAMP(p_vmin[k], p_vmax[k], C); \
	}

	switch (cplane) //QImage(w,h)
	{
	case imgPlaneX: //(Z,Y)
		pp = (cpos>sz0)? sz0-1:cpos-1;   pp = (pp<0)? 0:pp;
		tmpimg = QImage(sz2, sz1, QImage::Format_RGB32);

		for (y=0; y<sz1; y++)
		for (z=0; z<sz2; z++)
			{
				for (int k=0; k<N; k++)
				{
					float C = p4d[k][z][y][pp];
					BRIGHTEN_TRANSFORM( C );
					mC[k] =  ( (! bRescale) ? C : floor((C-p_vmin[k])/vrange[k]*255) );
				}
				RGB8 o = lookup_mix(mC, luts, op, mask);
				tmpimg.setPixel(z, y, qRgb(o.r, o.g, o.b));
				//qDebug("(x) y z = (%d/%d) %d/%d %d/%d", pp,sz0, y,sz1, z,sz2);
			}
		break;

	case imgPlaneY: //(X,Z)
		pp = (cpos>sz1)? sz1-1:cpos-1;   pp = (pp<0)? 0:pp;
		tmpimg = QImage(sz0, sz2, QImage::Format_RGB32);

		for (z=0; z<sz2; z++)
		for (x=0; x<sz0; x++)
			{
				for (int k=0; k<N; k++)
				{
					float C = p4d[k][z][pp][x];
					BRIGHTEN_TRANSFORM( C );
					mC[k] =  ( (! bRescale) ? C : floor((C-p_vmin[k])/vrange[k]*255) );
				}
				RGB8 o = lookup_mix(mC, luts, op, mask);
				tmpimg.setPixel(x, z, qRgb(o.r, o.g, o.b));
				//qDebug("x (y) z = %d/%d (%d/%d) %d/%d", x,sz0, pp,sz1, z,sz2);
			}
		break;

	case imgPlaneZ: //(X,Y)
		pp = (cpos>sz2)? sz2-1:cpos-1;   pp = (pp<0)? 0:pp;
		tmpimg = QImage(sz0, sz1, QImage::Format_RGB32);

		for (y=0; y<sz1; y++)
		for (x=0; x<sz0; x++)
			{
				for (int k=0; k<N; k++)
				{
					float C = p4d[k][pp][y][x];
					BRIGHTEN_TRANSFORM( C );
					mC[k] =  ( (! bRescale) ? C : floor((C-p_vmin[k])/vrange[k]*255) );
				}
				RGB8 o = lookup_mix(mC, luts, op, mask);
				tmpimg.setPixel(x, y, qRgb(o.r, o.g, o.b));
				//qDebug("x y (z) = %d/%d %d/%d (%d/%d)", x,sz0, y,sz1, pp,sz2);
			}
		break;
	}

	//qDebug()<<"copyRaw2QPixmap_Slice fromImage(tmpimg)"<<tmpimg.size();

	return QPixmap::fromImage(tmpimg);
}

///////////////////////////////////////////////////////////////////////////////////////////
//widget for control channel's color

class ChannelTable;
class BrightenBox;

class ChannelTabWidget : public QTabWidget //QWidget
{
    Q_OBJECT;
	XFormWidget* xform;
	QTabWidget* tabOptions;
	ChannelTable *channelPage;
	BrightenBox *brightenPage;
	void createFirst();
	MixOP mixOp;

public:
	ChannelTabWidget(QWidget* parent=0) :QTabWidget(parent)
	{
		xform = (XFormWidget*)parent;
		tabOptions = 0;
		channelPage = 0;
		brightenPage = 0;
		createFirst();
	};
	virtual ~ChannelTabWidget() {};

public slots:
	void updateXFormWidget(int plane=-1);	//called by linkXFormWidgetChannel
	void linkXFormWidgetChannel();			//link updated channels of XFormWidget
};


class ChannelTable : public QWidget
{
    Q_OBJECT;

public:
	ChannelTable(MixOP& mixop, XFormWidget* xform, QWidget* parent=0) :QWidget(parent)
		, mixOp(mixop) /////
		, xform(xform) /////
	{
		init_member();
		linkXFormWidgetChannel();
		connect( this,SIGNAL(channelTableChanged()), this, SLOT(updateXFormWidget()) );
	};
	virtual ~ChannelTable() {};

signals:
	void channelTableChanged(); //trigger to update XFormWidget

public slots:
	void updateXFormWidget(int plane=-1);	//called by linkXFormWidgetChannel
	void linkXFormWidgetChannel();			//link updated channel
	void setChannelColorDefault(int N);
	int rowCount() {return (table)? table->rowCount() :0; };

protected slots:
	void pressedClickHandler(int row, int col);
	void doubleClickHandler(int row, int col);
	void pickChannel(int row, int col);

	void setMixOpMax();
	void setMixOpSum();
	void setMixOpMean();
	void setMixOpIndex();
	void setMixRescale();
	void setMixMaskR();
	void setMixMaskG();
	void setMixMaskB();
	void setDefault();

protected:
	MixOP & mixOp; //just a reference to ChannelTabWidget::mixOp
	XFormWidget* xform;
	QList<Channel> listChannel;

	QGridLayout *boxLayout;
	QTableWidget *table;
	QRadioButton *radioButton_Max, *radioButton_Sum, *radioButton_Mean, *radioButton_Index;
	QCheckBox *checkBox_Rescale, *checkBox_R, *checkBox_G, *checkBox_B;
	QPushButton *pushButton_Reset;
	void init_member()
	{
		boxLayout=0;
		table=0;
		radioButton_Max=radioButton_Sum=radioButton_Mean=radioButton_Index=0;
		checkBox_Rescale=checkBox_R=checkBox_G=checkBox_B=0;
		pushButton_Reset=0;
	}

	void createNewTable();  // called by linkXFormWidgetChannel
	void setMixOpControls();     //called by createNewTable
	void connectMixOpSignals();  //called by createNewTable

	QVector<bool> in_batch_stack;
	void begin_batch() {in_batch_stack.push_back(true);}
	void end_batch()   {in_batch_stack.pop_back();}
	void updatedContent(QTableWidget* t);
	QTableWidget* currentTableWidget();

	QTableWidget* createTableChannel();
	void updateTableChannel();

};

class BrightenBox : public QWidget
{
    Q_OBJECT;

public:
	BrightenBox(MixOP & mixop, XFormWidget* xform, QWidget* parent=0) :QWidget(parent)
		, mixOp(mixop) /////
		, xform(xform) /////
	{
		init_member();
		create();
		connect( this,SIGNAL(brightenChanged()), parent, SLOT(updateXFormWidget()) );
	};
	virtual ~BrightenBox() {};

signals:
	void brightenChanged(); //trigger to update XFormWidget

protected slots:
	void setBrightness(int);
	void setContrast(int);
	void reset();

protected:
	MixOP & mixOp; //just a reference to ChannelTabWidget::mixOp
	XFormWidget* xform;

	QSlider *slider_bright, *slider_contrast;
	QSpinBox *spin_bright, *spin_contrast;
	QPushButton *push_reset;
	int _bright, _contrast; //for stopping loop of setValue()
	void init_member()
	{
		slider_bright=slider_contrast=0;
		spin_bright=spin_contrast=0;
		push_reset=0;
	}
	void create();
};

#endif /* CHANNELTABLE_H_ */
