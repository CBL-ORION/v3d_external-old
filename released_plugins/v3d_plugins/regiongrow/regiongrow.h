/* regiongrow.h
 * 2010-04-02: create this program by Yang Yu
 */


#ifndef __REGIONGROW_H__
#define __REGIONGROW_H__


//
#include <QtGui>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <v3d_interface.h>

class RegionGrowPlugin : public QObject, public V3DPluginInterface2_1
{
    Q_OBJECT
    Q_INTERFACES(V3DPluginInterface2_1);
	
public:
	QStringList menulist() const;
	void domenu(const QString &menu_name, V3DPluginCallback2 &callback, QWidget *parent);
	
	QStringList funclist() const {return QStringList();}
	bool dofunc(const QString &func_name, const V3DPluginArgList &input, V3DPluginArgList &output, V3DPluginCallback2 &callback, QWidget *parent)
        {return false;}
        float getPluginVersion() const {return 1.2f;}
};


//define a simple dialog for choose Region Growing parameters
class RegiongrowDialog : public QDialog
{
	Q_OBJECT
	
public:
	RegiongrowDialog(V3DPluginCallback2 &cb, QWidget *parent)
	{
		//create a dialog
		gridLayout = new QGridLayout();
		
		v3dhandleList win_list = cb.getImageWindowList();
		
		if(win_list.size()<1) 
		{
			QMessageBox::information(0, "Label Objects", QObject::tr("No image is open."));
			return;
		}
		
		image = cb.getImage(cb.currentImageWindow());
		pRoiList=cb.getROI(cb.currentImageWindow());
		QString imageName = cb.getImageName(cb.currentImageWindow());
		label_imagename = new QLabel(imageName.prepend("Your have selected the image [").append("]"));
		gridLayout->addWidget(label_imagename, 1,0,1,3); 
		
		int c = image->getCDim();
		label_channel = new QLabel(QObject::tr("Choose a channel: ")); 
		gridLayout->addWidget(label_channel, 2,0); 
		
		// channel info
		QStringList chList;
		if(c>=3)
			chList << "red" << "green" << "blue";
		else if(c==2)
			chList << "red" << "green";
		else if(c==1)
			chList << "red";
		combo_channel = new QComboBox(); combo_channel->addItems(chList);
		gridLayout->addWidget(combo_channel, 2,1);
		
		//
		label_th = new QLabel(QObject::tr("Choose a threshold: ")); 
		gridLayout->addWidget(label_th, 4,0); 
		
		QStringList thList;
		thList << "mean" << "mean+stdv" << "usr defined";
		
		combo_th = new QComboBox(); combo_th->addItems(thList);
		gridLayout->addWidget(combo_th, 4,1);
		
		//
		spin_th = new QDoubleSpinBox();
		gridLayout->addWidget(spin_th, 4,2);
		
		spin_th->setEnabled(false);
		spin_th->setMaximum(65535); spin_th->setMinimum(-65535); 
		
		//
		ok     = new QPushButton("OK");
		cancel = new QPushButton("Cancel");
		gridLayout->addWidget(cancel, 6,1); 
		gridLayout->addWidget(ok,     6,2);
		
		setLayout(gridLayout);
		setWindowTitle(QString("Label Objects"));
		
		//slot interface
		connect(ok,     SIGNAL(clicked()), this, SLOT(accept()));
		connect(cancel, SIGNAL(clicked()), this, SLOT(reject()));
		
		connect(combo_channel, SIGNAL(currentIndexChanged(int)), this, SLOT(update()));
		connect(combo_th, SIGNAL(currentIndexChanged(int)), this, SLOT(update()));
	
		connect(spin_th, SIGNAL(valueChanged(double)), this, SLOT(update()));
	}
	
	~RegiongrowDialog(){}
	
public slots:
	void update()
	{
		ch = combo_channel->currentIndex();
		
		th_idx = combo_th->currentIndex();
		
		if(th_idx == 2)
		{
			spin_th->setEnabled(true);
		}
		else
		{
			spin_th->setEnabled(false);
		}
		
		thresh = spin_th->text().toDouble();
	}
	
public:
	int ch;
	int th_idx;
	double thresh;
	Image4DSimple* image;
	ROIList pRoiList;
	
	QGridLayout *gridLayout;
	
	QLabel* label_imagename;
	QLabel* label_channel;
	QComboBox* combo_channel;
	
	QLabel* label_th;
	QComboBox* combo_th;

	QDoubleSpinBox* spin_th;
	
	QPushButton* ok;
	QPushButton* cancel;
};


#endif



