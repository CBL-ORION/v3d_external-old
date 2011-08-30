//plugin_atlasguided_stranno_partial.cpp
// by Lei Qu
//2010-11-09
//2011-08-29. add download page info

#include <QtGui>

#include "stackutil.h"
#include "plugin_atlasguided_stranno_partial.h"
#include "../../v3d_main/jba/c++/convert_type2uint8.h"
#include "../celegans_straighten/q_celegans_straighten.h"
#include "../../v3d_main/worm_straighten_c/spline_cubic.h"
#include "../../v3d_main/basic_c_fun/basic_memory.cpp"
#include "q_atlasguided_seganno.h"
#include "q_paradialog_stranno.h"

//Q_EXPORT_PLUGIN2 ( PluginName, ClassName )
//The value of PluginName should correspond to the TARGET specified in the plugin's project file.
Q_EXPORT_PLUGIN2(plugin_atlasguided_stranno_partial, AtlasGuidedStrAnnoPartialPlugin);

const QString title = "AtlasGuidedStrAnnoPlugin demo";
CControlPanel* CControlPanel::panel=0;

void AtlasGuidedStrAnnoPartial(V3DPluginCallback &callback, QWidget *parent, int mode);
bool readCelloi_file(const QString &qs_filename,QList<QString> &ql_celloi);


void OpenDownloadPage(QWidget *parent)
{
    bool b_openurl_worked;
    b_openurl_worked=QDesktopServices::openUrl(QUrl("http://penglab.janelia.org/proj/celegans_seganno"));
    if (! b_openurl_worked)
        QMessageBox::warning(parent,
							 "Error opening download page", // title
							 "Please browse to\n"
							 "http://penglab.janelia.org/proj/celegans_seganno\n"
							 "to download the test data for this plugin");
	
}


//************************************************************************************************************************************
QStringList AtlasGuidedStrAnnoPartialPlugin::menulist() const
{
    return QStringList()
	
	<< tr("atlasguided_seganno...")
	<< tr("open suppelement-material web page")
/*	<< tr("atlasguided_stranno_parital...")
	<< tr("grid2image...")
	<< tr("atlas2image_affine_beforecrop...")
	<< tr("atlas2image_affine_aftercrop...")
	<< tr("test...")
*/
	;
}

void AtlasGuidedStrAnnoPartialPlugin::domenu(const QString &menu_name, V3DPluginCallback &callback, QWidget *parent)
{
	if(menu_name==tr("atlasguided_seganno..."))
	{
		AtlasGuidedStrAnnoPartial(callback,parent,-1);
	}
	else if(menu_name==tr("open suppelement-material web page"))
	{
		OpenDownloadPage(parent);
	}
	else if(menu_name==tr("atlasguided_stranno_parital..."))
	{
		AtlasGuidedStrAnnoPartial(callback,parent,0);
	}
	else if(menu_name==tr("grid2image..."))
	{
		AtlasGuidedStrAnnoPartial(callback,parent,1);
	}
	else if(menu_name==tr("atlas2image_affine_beforecrop..."))
	{
		AtlasGuidedStrAnnoPartial(callback,parent,2);
	}
	else if(menu_name==tr("atlas2image_affine_aftercrop..."))
	{
		AtlasGuidedStrAnnoPartial(callback,parent,3);
	}
	else if(menu_name==tr("test..."))
	{
		AtlasGuidedStrAnnoPartial(callback,parent,4);
	}
}

//************************************************************************************************************************************
void AtlasGuidedStrAnnoPartial(V3DPluginCallback &callback, QWidget *parent, int mode)
{
	CParaDialog_stranno DLG_stranno(callback,parent);
	if(DLG_stranno.exec()!=QDialog::Accepted)
		return;

	CSParas paras_str;
	//image and marker
	paras_str.b_imgfromV3D=1;
	paras_str.b_markerfromV3D=1;
	QString qs_filename_img="";
	QString qs_filename_marker_input="";
	QString qs_filename_strimg_output="";

	CParas paras_anno;
	//image and atlas
	QString qs_filename_atals_input=DLG_stranno.lineEdit_atlasfile->text();
	QString qs_filename_celloi_input=DLG_stranno.lineEdit_celloifile->text();
	QString qs_filename_celloi_2_input=DLG_stranno.lineEdit_celloifile_2->text();
	QString qs_filename_atals_output=DLG_stranno.lineEdit_atlas_output->text();
	QString qs_filename_seglabel_output=DLG_stranno.lineEdit_seglabel_output->text();
	//visualization
	paras_anno.b_showatlas=DLG_stranno.checkBox_showatlas->isChecked();
	paras_anno.b_showsegmentation=DLG_stranno.checkBox_showsegmentation->isChecked();
	paras_anno.b_stepwise=1;
	//initial align
	paras_anno.d_fgthresh_factor=DLG_stranno.lineEdit_fgthresh->text().toDouble();
	paras_anno.l_refchannel=DLG_stranno.lineEdit_refchannel->text().toLong();
	paras_anno.d_downsampleratio=DLG_stranno.lineEdit_downsampleratio->text().toDouble();
	paras_anno.d_T=DLG_stranno.lineEdit_temp_ini->text().toDouble();
	paras_anno.d_T_min=DLG_stranno.lineEdit_temp_min->text().toDouble();
	paras_anno.d_annealingrate=DLG_stranno.lineEdit_annealingrate->text().toDouble();
	paras_anno.l_niter_pertemp=DLG_stranno.lineEdit_niter_pertemp->text().toLong();
	//refine align
	paras_anno.b_ref_simplealign=1;
	paras_anno.d_ref_T=0.1;
	paras_anno.l_ref_cellradius=8;
	paras_anno.l_ref_maxiter=100;
	paras_anno.d_ref_minposchange=1.0;
	//mode
	paras_anno.l_mode=mode;
	paras_anno.qw_rootparent=parent;

	//------------------------------------------------------------------------------------------------------------------------------------
	printf("1. Import image. \n");
	unsigned char *p_img_input=0;
	long *sz_img_input=0;
	int datatype_input=0;
	if(!paras_str.b_imgfromV3D)
	{
		if(qs_filename_img.isEmpty())
		{
			v3d_msg(QString("invalid image path!"));
			return;
		}
		if(!loadImage((char *)qPrintable(qs_filename_img),p_img_input,sz_img_input,datatype_input))
		{
			v3d_msg(QString("open file [%1] failed!").arg(qs_filename_img));
			return;
		}
		printf("\t>>read image file [%s] complete.\n",qPrintable(qs_filename_img));
	}
	else
	{
		printf("\t>>import image from V3D. \n");
		v3dhandleList h_wndlist=callback.getImageWindowList();
		if(h_wndlist.size()<1)
		{
			v3d_msg(QString("Make sure there are at least 1 image in V3D!"));
			return;
		}
		Image4DSimple* image=callback.getImage(callback.currentImageWindow());
		p_img_input=image->getRawData();
		sz_img_input=new long[4]();
		sz_img_input[0]=image->getXDim();	sz_img_input[1]=image->getYDim();	sz_img_input[2]=image->getZDim();	sz_img_input[3]=image->getCDim();
		datatype_input=image->getDatatype();
	}
	printf("\t\timage size: [w=%ld, h=%ld, z=%ld, c=%ld]\n",sz_img_input[0],sz_img_input[1],sz_img_input[2],sz_img_input[3]);
	printf("\t\tdatatype: %d\n",datatype_input);

	//------------------------------------------------------------------------------------------------------------------------------------
	printf("2. Convert image datatype to uint8. \n");
	unsigned char * p_img_8u=0;
	{
	long l_npixels=sz_img_input[0]*sz_img_input[1]*sz_img_input[2]*sz_img_input[3];
	p_img_8u=new unsigned char[l_npixels];
	if(!p_img_8u)
	{
		printf("ERROR: Fail to allocate memory. Do nothing. \n");
		if(p_img_input && !paras_str.b_imgfromV3D) 	{delete []p_img_input;		p_img_input=0;}
		if(sz_img_input)						 	{delete []sz_img_input;		sz_img_input=0;}
		return;
	}
	if(datatype_input==1)
	{
		printf("\t>>convert image data from uint8 to uint8. \n");
		for(long i=0;i<l_npixels;i++)
			p_img_8u[i]=p_img_input[i];
	}
	else if(datatype_input==2)
	{
		printf("\t>>convert image data from uint16 to uint8. \n");
		double min,max;
		if(!rescale_to_0_255_and_copy((unsigned short int *)p_img_input,l_npixels,min,max,p_img_8u))
		{
			printf("ERROR: rescale_to_0_255_and_copy() return false.\n");
			if(p_img_8u) 								{delete []p_img_8u;			p_img_8u=0;}
			if(p_img_input && !paras_str.b_imgfromV3D) 	{delete []p_img_input;		p_img_input=0;}
			if(sz_img_input)						 	{delete []sz_img_input;		sz_img_input=0;}
			return;
		}
	}
	else if(datatype_input==3)
	{
		printf("\t>>convert image data from float to uint8. \n");
		double min,max;
		if(!rescale_to_0_255_and_copy((float *)p_img_input,l_npixels,min,max,p_img_8u))
		{
			printf("ERROR: rescale_to_0_255_and_copy() return false.\n");
			if(p_img_8u)								{delete []p_img_8u;			p_img_8u=0;}
			if(p_img_input && !paras_str.b_imgfromV3D) 	{delete []p_img_input;		p_img_input=0;}
			if(sz_img_input)						 	{delete []sz_img_input;		sz_img_input=0;}
			return;
		}
	}
	else
	{
		v3d_msg(QString("Unknown datatype!\n"));
		if(p_img_8u) 								{delete []p_img_8u;			p_img_8u=0;}
		if(p_img_input && !paras_str.b_imgfromV3D) 	{delete []p_img_input;		p_img_input=0;}
		if(sz_img_input)						 	{delete []sz_img_input;		sz_img_input=0;}
		return;
	}
	}

	//------------------------------------------------------------------------------------------------------------------------------------
	printf("2. Import markers. \n");
	//get initial head and tail marker position from V3D
	vector< vector<double> > vec2d_markers;
	if(!paras_str.b_markerfromV3D)
	{
		if(qs_filename_marker_input.isEmpty())
		{
			v3d_msg(QString("Invalid marker path!"));
			if(p_img_8u) 								{delete []p_img_8u;			p_img_8u=0;}
			if(p_img_input && !paras_str.b_imgfromV3D) 	{delete []p_img_input;		p_img_input=0;}
			if(sz_img_input)						 	{delete []sz_img_input;		sz_img_input=0;}
			return;
		}
		QList<ImageMarker> ql_markers=readMarker_file(qs_filename_marker_input);
		printf("\t>>read %d markers from file: %s.\n",ql_markers.size(),qPrintable(qs_filename_marker_input));
		vector<double> vec_marker(3,0);
		for(long i=0;i<ql_markers.size();i++)
		{
			vec_marker[0]=ql_markers[i].x;
			vec_marker[1]=ql_markers[i].y;
			vec_marker[2]=ql_markers[i].z;
			vec2d_markers.push_back(vec_marker);
		}
	}
	else
	{
		printf("\t>>import markers from V3D. \n");
		v3dhandleList h_wndlist=callback.getImageWindowList();
		if(h_wndlist.size()<1)
		{
			v3d_msg(QString("Make sure there are at least 1 image in V3D!"));
			if(p_img_8u) 								{delete []p_img_8u;			p_img_8u=0;}
			if(p_img_input && !paras_str.b_imgfromV3D) 	{delete []p_img_input;		p_img_input=0;}
			if(sz_img_input)						 	{delete []sz_img_input;		sz_img_input=0;}
			return;
		}
		LandmarkList ml_makers=callback.getLandmark(callback.currentImageWindow());
		vector<double> vec_marker(3,0);
		for(long i=0;i<ml_makers.size();i++)
		{
			vec_marker[0]=ml_makers[i].x;
			vec_marker[1]=ml_makers[i].y;
			vec_marker[2]=ml_makers[i].z;
			vec2d_markers.push_back(vec_marker);
		}
	}

	//------------------------------------------------------------------------------------------------------------------------------------
	printf("3. Read atlas apo file. \n");
	QList<CellAPO> ql_atlasapo;
	ql_atlasapo=readAPO_file(qs_filename_atals_input);
	printf("\t>>read %d points from [%s]\n",ql_atlasapo.size(),qPrintable(qs_filename_atals_input));
	if(ql_atlasapo.size()<=0)
	{
		v3d_msg(QString("Given atlas file is empty or invalid!"));
		if(p_img_8u) 								{delete []p_img_8u;			p_img_8u=0;}
		if(p_img_input && !paras_str.b_imgfromV3D) 	{delete []p_img_input;		p_img_input=0;}
		if(sz_img_input) 							{delete []sz_img_input;		sz_img_input=0;}
		return;
	}

	//------------------------------------------------------------------------------------------------------------------------------------
	printf("4. Read interesting cell file. \n");
	QList<QString> ql_celloi_name;
	if(!readCelloi_file(qs_filename_celloi_input,ql_celloi_name))
	{
		printf("ERROR: readCelloi_file() return false! \n");
		if(p_img_8u) 								{delete []p_img_8u;			p_img_8u=0;}
		if(p_img_input && !paras_str.b_imgfromV3D) 	{delete []p_img_input;		p_img_input=0;}
		if(sz_img_input)						 	{delete []sz_img_input;		sz_img_input=0;}
		return;
	}

	printf("\t>>interesting cell:\n");
	for(long i=0;i<ql_celloi_name.size();i++)
		printf("\t\t%s\n",qPrintable(ql_celloi_name[i]));


	//------------------------------------------------------------------------------------------------------------------------------------
	printf("5. Do Straightening. \n");
	unsigned char *p_strimg=0;
	long *sz_strimg=0;
	vector< vector< vector< vector<long> > > > vec4d_mappingfield_str2ori;

	if(vec2d_markers.size()<2)
	{
		printf("\t>>marker num < 2, skip straightening.\n");
	}
	else
	{
		printf("\t>>marker num >= 2, do straightening.\n");

		long l_width=paras_str.l_radius_cuttingplane*2+1;
		QList<ImageMarker> ql_marker;
		for(unsigned long i=0;i<vec2d_markers.size();i++)
		{
			ImageMarker tmp;
			tmp.x=vec2d_markers[i][0];
			tmp.y=vec2d_markers[i][1];
			tmp.z=vec2d_markers[i][2];
			ql_marker.push_back(tmp);
		}

		if(!q_celegans_restacking_xy(
				p_img_8u,sz_img_input,
				ql_marker,l_width,
				p_strimg,sz_strimg,
				vec4d_mappingfield_str2ori))
		{
			printf("ERROR: q_celegans_restacking_xy() return false! \n");
			if(p_img_8u) 								{delete []p_img_8u;			p_img_8u=0;}
			if(p_img_input && !paras_str.b_imgfromV3D) 	{delete []p_img_input;		p_img_input=0;}
			if(sz_img_input)						 	{delete []sz_img_input;		sz_img_input=0;}
			return;
		}
	}

	//------------------------------------------------------------------------------------------------------------------------------------
	printf("6. Do Annotation. \n");
	QList<CellAPO> ql_musclecell_output;
	unsigned char *p_img8u_seglabel=0;
	COutputInfo outputinfo;

	{
	unsigned char *p_img_anno=0;
	long *sz_img_anno=0;
	if(vec2d_markers.size()<2)	//on non-straightened image
	{
		p_img_anno=p_img_input;
		sz_img_anno=sz_img_input;
	}
	else						//on straightened image
	{
		p_img_anno=p_strimg;
		sz_img_anno=sz_strimg;
	}

	if(paras_anno.l_mode==-1)	//non-partial annotation
	{
		if(!q_atlas2image(paras_anno,callback,
				p_img_anno,sz_img_anno,ql_atlasapo,ql_celloi_name,
				ql_musclecell_output,p_img8u_seglabel,outputinfo))
		{
			printf("ERROR: q_atlas2image() return false!\n");
			if(p_strimg)								{delete []p_strimg; 		p_strimg=0;}
			if(sz_strimg) 								{delete []sz_strimg;		sz_strimg=0;}
			if(p_img_8u) 								{delete []p_img_8u;			p_img_8u=0;}
			if(p_img_input && !paras_str.b_imgfromV3D) 	{delete []p_img_input;		p_img_input=0;}
			if(sz_img_input) 							{delete []sz_img_input;		sz_img_input=0;}
			return;
		}
	}
	else if(paras_anno.l_mode==4) //align dapi
	{
		if(!q_align_dapicells(paras_anno,callback,
				p_img_anno,sz_img_anno,ql_atlasapo,ql_celloi_name,
				ql_musclecell_output,outputinfo))
		{
			printf("ERROR: q_atlas2image_partial() return false!\n");
			if(p_strimg)								{delete []p_strimg; 		p_strimg=0;}
			if(sz_strimg) 								{delete []sz_strimg;		sz_strimg=0;}
			if(p_img_8u) 								{delete []p_img_8u;			p_img_8u=0;}
			if(p_img_input && !paras_str.b_imgfromV3D) 	{delete []p_img_input;		p_img_input=0;}
			if(sz_img_input) 							{delete []sz_img_input;		sz_img_input=0;}
			return;
		}
	}
	else			//partial annotation
	{
		if(!q_atlas2image_partial(paras_anno,callback,
				p_img_anno,sz_img_anno,ql_atlasapo,ql_celloi_name,
				ql_musclecell_output,outputinfo))
		{
			printf("ERROR: q_atlas2image_partial() return false!\n");
			if(p_strimg)								{delete []p_strimg; 		p_strimg=0;}
			if(sz_strimg) 								{delete []sz_strimg;		sz_strimg=0;}
			if(p_img_8u) 								{delete []p_img_8u;			p_img_8u=0;}
			if(p_img_input && !paras_str.b_imgfromV3D) 	{delete []p_img_input;		p_img_input=0;}
			if(sz_img_input) 							{delete []sz_img_input;		sz_img_input=0;}
			return;
		}
	}
	}

	if(outputinfo.b_rotate90)
		v3d_msg("The deformed atlas maybe wrongly 90 degree rotated!\nCheck result!\n");


	//------------------------------------------------------------------------------------------------------------------------------------
	//warping the secondary interesting cells if provided based on the TPS paras obtained from the first group result
	QList<CellAPO> ql_cellio2_tps;
	if(DLG_stranno.checkBox_celloi_2->isChecked() || !qs_filename_celloi_2_input.isEmpty())
	{
		printf("6~7. Warping the secondary interesting cells. \n");

		QList<QString> ql_celloi2_name;
		if(!readCelloi_file(qs_filename_celloi_2_input,ql_celloi2_name))
		{
			printf("ERROR: readCelloi_file() return false! \n");
			return;
		}

		vector<point3D64F> vec_cellio1_ori,vec_cellio1_tps,vec_cellio2_ori;
		QList<CellAPO> ql_cellio2_ori;
		point3D64F tmp;
		//extract first interesting cells
		for(long i=0;i<ql_atlasapo.size();i++)
		{
			QString qs_cellname=ql_atlasapo[i].name;
			qs_cellname=qs_cellname.simplified();
			qs_cellname=qs_cellname.toUpper();
			ql_atlasapo[i].name=qs_cellname;

			for(long j=0;j<ql_celloi_name.size();j++)
			{
				if(ql_celloi_name[j].contains("*"))
				{
					QString qs_cellnamevalid=ql_celloi_name[j];
					qs_cellnamevalid.remove("*");
					if(qs_cellname.contains(qs_cellnamevalid,Qt::CaseInsensitive))
					{
						tmp.x=ql_atlasapo[i].x; tmp.y=ql_atlasapo[i].y; tmp.z=ql_atlasapo[i].z;
						vec_cellio1_ori.push_back(tmp);
					}
				}
				else if(qs_cellname.compare(ql_celloi_name[j],Qt::CaseInsensitive)==0)
				{
					tmp.x=ql_atlasapo[i].x; tmp.y=ql_atlasapo[i].y; tmp.z=ql_atlasapo[i].z;
					vec_cellio1_ori.push_back(tmp);
				}
			}
		}
		for(long i=0;i<ql_musclecell_output.size();i++)
		{
			tmp.x=ql_musclecell_output[i].x;
			tmp.y=ql_musclecell_output[i].y;
			tmp.z=ql_musclecell_output[i].z;
			vec_cellio1_tps.push_back(tmp);
		}
		//extract secondary interesting cells
		for(long i=0;i<ql_atlasapo.size();i++)
		{
			QString qs_cellname=ql_atlasapo[i].name;
			qs_cellname=qs_cellname.simplified();
			qs_cellname=qs_cellname.toUpper();
			ql_atlasapo[i].name=qs_cellname;

			for(long j=0;j<ql_celloi2_name.size();j++)
			{
				if(ql_celloi2_name[j].contains("*"))
				{
					QString qs_cellnamevalid=ql_celloi2_name[j];
					qs_cellnamevalid.remove("*");
					if(qs_cellname.contains(qs_cellnamevalid,Qt::CaseInsensitive))
					{
						ql_cellio2_ori.push_back(ql_atlasapo[i]);
						tmp.x=ql_atlasapo[i].x; tmp.y=ql_atlasapo[i].y; tmp.z=ql_atlasapo[i].z;
						vec_cellio2_ori.push_back(tmp);
					}
				}
				else if(qs_cellname.compare(ql_celloi2_name[j],Qt::CaseInsensitive)==0)
				{
					ql_cellio2_ori.push_back(ql_atlasapo[i]);
					tmp.x=ql_atlasapo[i].x; tmp.y=ql_atlasapo[i].y; tmp.z=ql_atlasapo[i].z;
					vec_cellio2_ori.push_back(tmp);
				}
			}
		}
		ql_cellio2_tps=ql_cellio2_ori;
		printf("\t>>[%d] cells in the secondary intereting cell group.\n",ql_cellio2_ori.size());

		//compute TPS paras
		Matrix x4x4_affine,xnx4_c,xnxn_K;
		if(!q_TPS_cd(vec_cellio1_ori,vec_cellio1_tps,0,x4x4_affine,xnx4_c,xnxn_K))
		{
			printf("ERROR: q_TPS_cd() return false!\n");
			return;
		}
		//compute TPS kernal matrix
		Matrix xmxn_K;
		if(!q_TPS_k(vec_cellio2_ori,vec_cellio1_ori,xmxn_K))
		{
			printf("ERROR: q_TPS_k() return false!\n");
			return;
		}
		//warp the secondary cells
		Matrix x_ori(ql_cellio2_ori.size(),4),x_tps(ql_cellio2_ori.size(),4);
		for(long i=0;i<ql_cellio2_ori.size();i++)
		{
			x_ori(i+1,1)=1.0;
			x_ori(i+1,2)=ql_cellio2_ori[i].x;
			x_ori(i+1,3)=ql_cellio2_ori[i].y;
			x_ori(i+1,4)=ql_cellio2_ori[i].z;
		}
		x_tps=x_ori*x4x4_affine+xmxn_K*xnx4_c;
		for(long i=0;i<ql_cellio2_tps.size();i++)
		{
			ql_cellio2_tps[i].x=x_tps(i+1,2)/x_tps(1,1);
			ql_cellio2_tps[i].y=x_tps(i+1,3)/x_tps(1,1);
			ql_cellio2_tps[i].z=x_tps(i+1,4)/x_tps(1,1);
		}
	}

	//------------------------------------------------------------------------------------------------------------------------------------
	printf("7. Map the annotated cell back to non-straightened image. \n");
	QList<CellAPO> ql_musclecell_output_ori(ql_musclecell_output);

	//map back to non-straightened image
	if(vec2d_markers.size()>=2)
	{
		for(long i=0;i<ql_musclecell_output.size();i++)
		{
			long x=ql_musclecell_output[i].x;
			long y=ql_musclecell_output[i].y;
			long z=ql_musclecell_output[i].z;
			ql_musclecell_output_ori[i].x=vec4d_mappingfield_str2ori[y][x][z][0];
			ql_musclecell_output_ori[i].y=vec4d_mappingfield_str2ori[y][x][z][1];
			ql_musclecell_output_ori[i].z=vec4d_mappingfield_str2ori[y][x][z][2];
		}
	}

	if(DLG_stranno.checkBox_celloi_2->isChecked() || !qs_filename_celloi_2_input.isEmpty())
		ql_musclecell_output_ori.append(ql_cellio2_tps);

	//save deformed point cloud to apo file
	if(!qs_filename_atals_output.isEmpty())
		writeAPO_file(qPrintable(qs_filename_atals_output),ql_musclecell_output_ori);

	//show deformed atlas pts in V3D
	if(!(paras_anno.b_showatlas || paras_anno.b_showsegmentation))
	{
		v3dhandle curwin=callback.currentImageWindow();
		callback.open3DWindow(curwin);
		LandmarkList curlist;
		for(int i=0;i<ql_musclecell_output_ori.size();i++)
		{
			LocationSimple s;
			s.x=ql_musclecell_output_ori[i].x+1;//note: marker coord start from 1 instead of 0
			s.y=ql_musclecell_output_ori[i].y+1;//note: marker coord start from 1 instead of 0
			s.z=ql_musclecell_output_ori[i].z+1;//note: marker coord start from 1 instead of 0
			s.name=ql_musclecell_output_ori[i].name.toStdString();
			s.radius=10;

			curlist << s;
		}
		callback.setLandmark(curwin,curlist);
		callback.updateImageWindow(curwin);
		callback.pushObjectIn3DWindow(curwin);
	}

	//------------------------------------------------------------------------------------------------------------------------------------
	printf("8. Save segmentation label image to file. \n");
	if(!qs_filename_seglabel_output.isEmpty() && p_img8u_seglabel)
	{
		long sz_seglabelimg[4]={sz_img_input[0],sz_img_input[1],sz_img_input[2],1};
		saveImage(qPrintable(qs_filename_seglabel_output),p_img8u_seglabel,sz_seglabelimg,1);
	}

	//------------------------------------------------------------------------------------------------------------------------------------
	//free memory
	printf(">>Free memory\n");
	if(p_img8u_seglabel)						{delete []p_img8u_seglabel; p_img8u_seglabel=0;}
	if(p_strimg)								{delete []p_strimg; 		p_strimg=0;}
	if(sz_strimg) 								{delete []sz_strimg;		sz_strimg=0;}
	if(p_img_8u) 								{delete []p_img_8u;			p_img_8u=0;}
	if(p_img_input && !paras_str.b_imgfromV3D) 	{delete []p_img_input;		p_img_input=0;}
	if(sz_img_input) 							{delete []sz_img_input;		sz_img_input=0;}

	//------------------------------------------------------------------------------------------------------------------------------------
	v3d_msg("Program exit successfully!\n");
	return;
}

bool readCelloi_file(const QString &qs_filename,QList<QString> &ql_celloi)
{
	//check paras
	if(qs_filename.isEmpty())
	{
		printf("ERROR: Invalid input file name.\n");
		return false;
	}
	if(!ql_celloi.isEmpty())
	{
		printf("WARNING: ql_celloi is not empty, original data will be deleted.\n");
		ql_celloi.clear();
	}

	QFile qf_file(qs_filename);
	if(!qf_file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		printf("ERROR: open file error!\n");
		return false;
	}

    while(!qf_file.atEnd())
    {
		char curline[2000];
        qf_file.readLine(curline, sizeof(curline));

		QString qs_cellname=QString(curline).simplified().toUpper();
		if(qs_cellname.isEmpty())   	continue;
		if(qs_cellname.contains("#")) 	continue;

		ql_celloi.push_back(qs_cellname);
    }

	return true;
}
