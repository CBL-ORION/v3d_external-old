#include <QtGui>

#include <math.h>
#include <stdlib.h>

#include "BinaryShapeKeepNObjects.h"
#include "V3DITKFilterSingleImage.h"

// ITK Header Files
#include "itkBinaryShapeKeepNObjectsImageFilter.h"


// Q_EXPORT_PLUGIN2 ( PluginName, ClassName )
// The value of PluginName should correspond to the TARGET specified in the
// plugin's project file.
Q_EXPORT_PLUGIN2(BinaryShapeKeepNObjects, BinaryShapeKeepNObjectsPlugin)


QStringList BinaryShapeKeepNObjectsPlugin::menulist() const
{
  return QStringList() << QObject::tr("ITK BinaryShapeKeepNObjectsImageFilter")
                       << QObject::tr("about this plugin");
}

QStringList BinaryShapeKeepNObjectsPlugin::funclist() const
{
  return QStringList();
}


template <typename TInputPixelType, typename TOutputPixelType>
class MySpecialized : public V3DITKFilterSingleImage< TInputPixelType, TOutputPixelType >
{
  typedef V3DITKFilterSingleImage< TInputPixelType, TOutputPixelType >   Superclass;
  typedef typename Superclass::Input3DImageType                          ImageType;
	
  typedef itk::BinaryShapeKeepNObjectsImageFilter< ImageType > FilterType;
	
public:
	
  MySpecialized( V3DPluginCallback * callback ): Superclass(callback)
  {
    this->m_Filter = FilterType::New();
	this->RegisterInternalFilter(this->m_Filter,1.0);
  }
	
  virtual ~MySpecialized() {};
	
	
  void Execute(const QString &menu_name, QWidget *parent)
  {
    V3DITKGenericDialog dialog("BinaryShapeKeepNObjects");

    dialog.AddDialogElement("BackgroundValue",0.0, 0.0, 255.0);
    dialog.AddDialogElement("ForegroundValue",0.0, 0.0, 255.0);
    dialog.AddDialogElement("NumberOfObjects",100.0, 0.0, 50000.0);

    if( dialog.exec() == QDialog::Accepted )
      {
        this->m_Filter->SetFullyConnected( true );
        this->m_Filter->SetBackgroundValue( dialog.GetValue("BackgroundValue") );
        this->m_Filter->SetForegroundValue( dialog.GetValue("ForegroundValue") );
        this->m_Filter->SetNumberOfObjects( dialog.GetValue("NumberOfObjects") );
        this->m_Filter->SetReverseOrdering( false );
        this->m_Filter->SetAttribute( 0 );
        this->Compute(); 
      }
  }
	
  virtual void ComputeOneRegion()
  {
		
    this->m_Filter->SetInput( this->GetInput3DImage() );
		
    if( !this->ShouldGenerateNewWindow() )
      {
      }
		
    this->m_Filter->Update();

    this->SetOutputImage( this->m_Filter->GetOutput() );
  }
	
private:
	
  typename FilterType::Pointer   m_Filter;
	
};


#define EXECUTE_PLUGIN_FOR_ONE_IMAGE_TYPE( v3d_pixel_type, c_pixel_type ) \
  case v3d_pixel_type:                                                  \
  {                                                                     \
    MySpecialized< c_pixel_type, c_pixel_type > runner( &callback );    \
    runner.Execute( menu_name, parent );                                \
    break;                                                              \
  } 


void BinaryShapeKeepNObjectsPlugin::dofunc(const QString & func_name,
                                           const V3DPluginArgList & input, V3DPluginArgList & output, QWidget * parent)
{
  // empty by now
}


void BinaryShapeKeepNObjectsPlugin::domenu(const QString & menu_name, V3DPluginCallback & callback, QWidget * parent)
{
  if (menu_name == QObject::tr("about this plugin"))
    {
      QMessageBox::information(parent, "Version info", "ITK BinaryShapeKeepNObjects 1.0 (2010-July-15): this plugin is developed by Sophie Chen.");
      return;
    }
	
  v3dhandle curwin = callback.currentImageWindow();
  if (!curwin)
    {
      v3d_msg(tr("You don't have any image open in the main window."));
      return;
    }
	
  Image4DSimple *p4DImage = callback.getImage(curwin);
  if (! p4DImage)
    {
      v3d_msg(tr("The input image is null."));
      return;
    }
	
  EXECUTE_PLUGIN_FOR_ALL_PIXEL_TYPES; 
}

