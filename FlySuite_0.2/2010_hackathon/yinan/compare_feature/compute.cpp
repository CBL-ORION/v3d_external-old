#include "compute.h"
#include <math.h>
#include <iostream>
using namespace std;

#define VOID 1000000000
#define PI 3.14159265359
#define min(a,b) (a)<(b)?(a):(b)
#define max(a,b) (a)>(b)?(a):(b)

double Width=0, Height=0, Depth=0, Diameter=0, Length=0, Volume=0, Surface=0, Hausdorff=0;
int N_node=0, N_stem=0, N_bifs=0, N_branch=0, N_tips=0, Max_Order=0;
double Pd_ratio=0, Contraction=0, Max_Eux=0, Max_Path=0, BifA_local=0, BifA_remote=0, Soma_surface=0, Fragmentation=0;
int rootidx=0;

void computeFeature(const NeuronTree & nt, double * features)
{
	Width=0, Height=0, Depth=0, Diameter=0, Length=0, Volume=0, Surface=0, Hausdorff=0;
	N_node=0, N_stem=0, N_bifs=0, N_branch=0, N_tips=0, Max_Order=0;
	Pd_ratio=0, Contraction=0, Max_Eux=0, Max_Path=0, BifA_local=0, BifA_remote=0, Soma_surface=0, Fragmentation=0;
	rootidx=0;
	
	QList<NeuronSWC> list = nt.listNeuron;
	QHash<int, int> LUT = QHash<int, int>();
	for (int i=0;i<list.size();i++)
		LUT.insert(list.at(i).n,i);

	//find the root
	rootidx = VOID;
	for (int i=0;i<list.size();i++)
		if (list.at(i).pn==-1) rootidx = i;
	if (rootidx==VOID){
		cerr<<"the input neuron tree does not have a root, please check your data"<<endl;
		return;
	}


	N_node = list.size();
	N_stem = getChild(rootidx,list,LUT).size();
	Soma_surface = 4*PI*(list.at(rootidx).r)*(list.at(rootidx).r);

	computeLinear(list, LUT);
	computeTree(list,LUT);
	Hausdorff = computeHausdorff(list,LUT);

	//feature # 0: Number of Nodes
	features[0] = N_node;
	//feature #1: Soma Surface
	features[1] = Soma_surface;
	//feature # 2: Number of Stems
	features[2] = N_stem;
	//feature # 3: Number of Bifurcations
	features[3] = N_bifs;
	//feature # 4: Number of Branches
	features[4] = N_branch;
	//feature # 5: Number of Tips
	features[5] = N_tips;
	//feature # 6: Overall Width
	features[6] = Width;
	//feature # 7: Overall Height
	features[7] = Height;
	//feature # 8: Overall Depth
	features[8] = Depth;
	//feature # 9: Average Diameter
	features[9] = Diameter;
	//feature # 10: Total Length
	features[10] = Length;
	//feature # 11: Total Surface
	features[11] = Surface;	
	//feature # 12: Total Volume
	features[12] = Volume;
	//feature # 13: Max Euclidean Distance
	features[13] = Max_Eux;
	//feature # 14: Max Path Distance
	features[14] = Max_Path;
	//feature # 15: Max Branch Order
	features[15] = Max_Order;
	//feature # 16: Average Contraction
	features[16] = Contraction;
	//feature # 17: Average Fragmentation
	features[17] = Fragmentation;
	//feature # 18: Average Parent-daughter Ratio
	features[18] = Pd_ratio;
	//feature # 19: Average Bifurcation Angle Local
	features[19] = BifA_local;
	//feature # 20: Average Bifurcation Angle Remote
	features[20] = BifA_remote;
	//feature # 21: Hausdorr Dimension
	features[21] = Hausdorff;
}

int getParent(int n, QList<NeuronSWC> & list, QHash<int,int> & LUT)
{
	int pid = list.at(n).pn;
	if (pid==-1) return VOID;
	return (LUT.value(pid));
}

QList<int> getChild(int t, QList <NeuronSWC> & list, QHash<int,int> & LUT)
{
	QList<int> childlist = QList<int>();
	int pan;
	for (int i=0;i<list.size();i++)
	{	
		pan = list.at(i).pn;
		if (pan==-1) continue;
		if (LUT.value(pan)==t)
			childlist.append(i);
	}
	return childlist;
}

QList<int> getRemoteChild(int t, QList <NeuronSWC> & list, QHash<int,int> & LUT)
{
	QList<int> rchildlist = QList<int>();
	int tmp;
	for (int i=0;i<getChild(t,list,LUT).size();i++)
	{
		tmp = getChild(t,list,LUT).at(i);
		while (getChild(tmp,list,LUT).size()==1)
			tmp = getChild(tmp,list,LUT).at(0);
		rchildlist.append(tmp);
	}
	return rchildlist;
}
//do a search along the list to compute overall width, height, depth, length, volume, surface, average diameter and max euclidean distance.
void computeLinear(QList<NeuronSWC> & list, QHash<int,int> & LUT)
{
	double xmin,ymin,zmin;
	xmin = ymin = zmin = VOID;
	double xmax,ymax,zmax;
	xmax = ymax = zmax = 0;

	for (int i=0;i<list.size();i++)
	{
		NeuronSWC curr = list.at(i);
		xmin = min(xmin,curr.x); ymin = min(ymin,curr.y); zmin = min(zmin,curr.z);
		xmax = max(xmax,curr.x); ymax = max(ymax,curr.y); zmax = max(zmax,curr.z);
		int parent = getParent(i,list,LUT);
		if (parent==VOID) continue;
		double l = dist(curr,list.at(parent));
		Diameter += 2*curr.r;
		Length += l;
		Surface += 2*PI*curr.r*l;
		Volume += PI*curr.r*curr.r*l;
		double lsoma = dist(curr,list.at(rootidx));
		Max_Eux = max(Max_Eux,lsoma);
	}
	Width = xmax-xmin;
	Height = ymax-ymin;
	Depth = zmax-zmin;
	Diameter /= list.size();
}

//do a search along the tree to compute N_bif, N_tips, N_branch, max path distance, max branch order,
//average Pd_ratio, average Contraction, average Fragmentation, average bif angle local & remote
void computeTree(QList<NeuronSWC> &list, QHash<int,int> & LUT)
{
	double * pathTotal = new double[list.size()];
	int * depth = new int[list.size()];
	for (int i=0;i<list.size();i++)
	{
		pathTotal[i] = 0;
		depth[i] = 0;
	}

	QStack<int> stack = QStack<int>();
	stack.push(rootidx);
	int t,tmp,fragment;
	double pathlength,eudist,max_local_ang,max_remote_ang;
	while (!stack.isEmpty())
	{
		t = stack.pop();
		QList<int> child = getChild(t,list,LUT);
		for (int i=0;i<child.size();i++)
		{
			N_branch++;
			tmp = child.at(i);
			Pd_ratio += list.at(tmp).r/list.at(t).r;
			pathlength = dist(list.at(tmp),list.at(t));

			fragment = 0;
			while (getChild(tmp,list,LUT).size()==1)
			{ 
				int ch = getChild(tmp,list,LUT).at(0);
				pathlength += dist(list.at(ch),list.at(tmp));
				fragment++;
				tmp = ch;
			}
			eudist = dist(list.at(tmp),list.at(t));
			Fragmentation += fragment;
			Contraction += eudist/pathlength;

			//we are reaching a tip point or another branch point, computation for this branch is over
			if (getChild(tmp,list,LUT).size()==0)//tip
				N_tips++;
			else //another branch
			{
				int chsz = getChild(tmp,list,LUT).size();
				N_bifs++;
				stack.push(tmp);

				//compute local bif angle and remote bif angle
				double local_ang,remote_ang;
				max_local_ang = 0;
				max_remote_ang = 0;
				int ch_local1 = getChild(tmp,list,LUT).at(0);
				int ch_local2 = getChild(tmp,list,LUT).at(1);
				local_ang = angle(list.at(tmp),list.at(ch_local1),list.at(ch_local2));

				int ch_remote1 = getRemoteChild(tmp,list,LUT).at(0);
				int ch_remote2 = getRemoteChild(tmp,list,LUT).at(1);
				remote_ang = angle(list.at(tmp),list.at(ch_remote1),list.at(ch_remote2));
				max_local_ang = max(max_local_ang,local_ang);
				max_remote_ang = max(max_remote_ang,remote_ang);

				BifA_local += max_local_ang;
				BifA_remote += max_remote_ang;
			}
			pathTotal[tmp] = pathTotal[t] + pathlength;
			depth[tmp] = depth[t] + 1;
		}
	}

	Pd_ratio /= N_branch;
	Fragmentation /= N_branch;
	Contraction /= N_branch;

	BifA_local /= N_bifs;
	BifA_remote /= N_bifs;

	for (int i=0;i<list.size();i++)
	{
		Max_Path = max(Max_Path,pathTotal[i]);
		Max_Order = max(Max_Order,depth[i]);
	}
	delete pathTotal; pathTotal = NULL;
	delete depth; depth = NULL;
}


//compute Hausdorff dimension
double computeHausdorff(QList <NeuronSWC> & list, QHash<int,int> & LUT)
{
#define LMINMAX 2
#define LMAXMIN 1
#define NCELL 5000        // max# nonempty lattice cells in Hausdorff analysis

	int n;

	short **r1, **r2;

	n = list.size();
	r1 = matrix(3,n);
	r2 = matrix(3,n);

	n = fillArray(list, LUT, r1,  r2);

	int i,  k, k1, l, m, cnt, dl, lmin , lmax;
	short r[3], rr[3], **cell;

	int scale;
	float dr[3], rt[3], total;
	float hd, measure[25], length;

	length=0;
	lmin=0;
	lmax=0;
	for (i=1; i<n; i++) 
		for (k=0; k<3; k++)
		{
			lmin += abs(r1[k][i]-r2[k][i]);
			if (lmax<abs(r2[k][i]-r1[k][1])) lmax=abs(r2[k][i]-r1[k][1]);
		}
	lmin /= LMINMAX*n;
	lmax /= 2;
	/*------------start with lattice cell >= lmin ------------*/
	if (lmin<1) lmin=1;
	else if (lmin>1)
	{
		lmax /= lmin;
		for (i=1; i<n; i++) for (k=0; k<3; k++)
		{
			r1[k][i] /= lmin;
			r2[k][i] /= lmin;
		}
	}
	if (lmax<=1) return(0.0);
	scale=lmin;
	cnt=0;

	cell = matrix(NCELL,3);
	/*-----------------------------------------------------main loop begin----------------------*/
	while (lmax>LMAXMIN)
	{
		for (k=0; k<3; k++) r[k]=r1[k][1];
		m = mark(0, r, cell);
		for (i=1; i<n; i++) if ((r1[0][i]!=r2[0][i]) ||
				(r1[1][i]!=r2[1][i]) ||
				(r1[2][i]!=r2[2][i]))
		{
			/*-------------------------tracing link-------*/
			total=0.0;
			for (k=0; k<3; k++) total += abs(r2[k][i]-r1[k][i]);
			for (k=0; k<3; k++) 
			{
				r[k]=r1[k][i];
				dr[k]=(r2[k][i]-r[k])/total;
				rt[k]=dr[k];
			}
			m=mark(m, r, cell);
			while((r[0]!=r2[0][i]) ||
					(r[1]!=r2[1][i]) ||
					(r[2]!=r2[2][i]))
			{
				l=0;
				k1=-1;
				for (k=0; k<3; k++) rr[k]=r2[k][i]-r[k];
				for (k=0; k<3; k++)
				{
					if ((rt[k]*rr[k]>0) && (abs(l)<abs(rr[k])))
					{
						l=rr[k];
						k1=k;
					}
				}
				if (l>0) 
				{
					r[k1]++;
					rt[k1]--;
				}
				else
				{
					r[k1]--;
					rt[k1]++;
				}
				for (k=0; k<3; k++) rt[k] += dr[k];
				m=mark(m, r, cell);
				if (m>=NCELL) cerr<<"maximal cell number reached"<<endl;;
				if (m>=NCELL) exit(1);
			}

		}
		measure[cnt]=m;
		cnt++;

		for (i=1; i<n; i++) for (k=0; k<3; k++)
		{
			r1[k][i] /= 2;
			r2[k][i] /= 2;
		}
		lmax /= 2;
		scale *=2;
	}
	/*-----------------------------main loop end-------------------------*/
	free_matrix(r1,3,n);
	free_matrix(r2,3,n);
	free_matrix(cell,NCELL,3);
	/*-----------------------------computing Hausdorff dimension---------*/
	hd=0;
	for (i=0; i<cnt; i++) hd += (i-0.5*(cnt-1))*log(measure[i]);
	hd *= -12.0/(cnt*(cnt*cnt-1.0))/log(2.0);
	return(hd);
}


int fillArray(QList<NeuronSWC> & list, QHash<int,int> & LUT, short** r1, short** r2){

	int siz = list.size();
	for (int t=0;t<siz;t++)
	{
		int s = getParent(t,list,LUT);
		if(s==VOID) s = t;
		int cst=1;
		r2[0][t]=(short)list.at(s).x+cst;
		r2[1][t]=(short)list.at(s).y+cst;
		r2[2][t]=(short)list.at(s).z+1;
		r1[0][t]=(short)list.at(t).x+cst;
		r1[1][t]=(short)list.at(t).y+cst;
		r1[2][t]=(short)list.at(t).z+1;

	}
	return siz;
}
short **matrix(int n,int m)
{
	int i;
	short **mat = new short*[n];
	for (int i=0;i<n;i++)
	{
		mat[i] = new short[m];
		for (int j=0;j<m;j++)
			mat[i][j] = 0;
	}
	/* Return pointer to array of pointers to rows. */
	return mat;

}

void free_matrix(short **mat,int n,int m)

	/* Free a float matrix allocated by matrix(). */
{
	int i;

	for (i = 0; i<n ; i++)
	{
		delete(mat[i]);
		mat[i] = NULL;
	}
	delete(mat);
	mat = NULL;
}
/*********************** mark lattice cell r, keep marked set ordered */
int mark(int m, short r[3], short ** c)
{
	int i, j, k;
	if (m<=0)
		for (k=0; k<3; k++) c[0][k]=r[k]; /*--initialize the pool of marked cells--*/
	else
	{
		for (i=0; i<m; i++) 
		{
			if (c[i][0]==r[0] &&
					c[i][1]==r[1] &&
					c[i][2]==r[2]) return(m); /*--- already marked ---*/
			if (c[i][0]>=r[0] &&
					c[i][1]>=r[1] &&
					c[i][2]>r[2]) break; /*--- insert into ordered set ---*/
		}
		if (i<m) for (j=m; j>i; j--) for (k=0; k<3; k++) c[j][k]=c[j-1][k];
		for (k=0; k<3; k++) c[i][k]=r[k];
	}

	return(m+1);

}


double dist(const NeuronSWC & s1, const NeuronSWC & s2)
{
	double x1 = s1.x, y1 = s1.y, z1 = s1.z;
	double x2 = s2.x, y2 = s2.y, z2 = s2.z;
	return (sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2)));
}

//as Frac_Dim is no longer computed, no need to do log-log regression
/*
   double loglog(QList<double> & x, QList<double> & y, int n)
   {
   double sumx=0, sumy=0, sumxy=0, sumx2=0;
   for (int i=0;i<n;i++)
   {
//cout<<i<<" "<<x.at(i)<<" "<<y.at(i)<<"\n";
double logx = log(x.at(i));
double logy = log(y.at(i));
sumx += logx; sumy += logy;
sumx2 += logx*logx;
sumxy += logx*logy;
}
if (n*sumx2-sumx*sumx==0) return VOID;
double b=(n*sumxy-sumx*sumy)/(n*sumx2-sumx*sumx);
return fabs(b);
}
*/
double angle(const NeuronSWC & ori, const NeuronSWC & s1, const NeuronSWC & s2)
{
	double x1 = s1.x-ori.x, y1 = s1.y-ori.y, z1 = s1.z-ori.z;
	double x2 = s2.x-ori.x, y2 = s2.y-ori.y, z2 = s2.z-ori.z;
	double param = (x1*x2+y1*y2+z1*z2)/(sqrt(x1*x1+y1*y1+z1*z1)*sqrt(x2*x2+y2*y2+z2*z2));
	return (acos(param)*180.0/PI);
}
