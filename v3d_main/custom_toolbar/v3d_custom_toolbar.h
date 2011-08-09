#ifndef __CUSTOM_BUTTON_H__
#define __CUSTOM_BUTTON_H__

//#define  __v3d_custom_toolbar_plugin__

#include <QtGui>
#include <map>

#ifdef __v3d_custom_toolbar_plugin__
	#include <v3d_interface.h>
#else
	#include "../v3d/mainwindow.h"
	#include "../basic_c_fun/v3d_interface.h"
#endif

class EmptyClass{};

typedef void (EmptyClass::*VoidFunc)();
#ifndef __v3d_custom_toolbar_plugin__
typedef void (MainWindow::*MainWindowFunc)();
#endif
typedef void (TriviewControl::*TriviewFunc)();
typedef void (View3DControl::*View3DFunc)();
typedef void (V3DPluginCallback2::*Callback2Func)(v3dhandle);
typedef void (V3DPluginInterface2_1::*PluginMenuFunc)(const QString &menu_name, V3DPluginCallback2 &callback, QWidget *parent);

void getAllFiles(QString dirname, QStringList & fileList);
void getObjectList(QStringList & fileList,QList<QObject*> &objectList);

bool setPluginRootPath(QString);
bool setPluginRootPathAutomaticly();
bool setToolbarSettingFilePath(QString);
bool setToolbarSettingFilePathAutomaticly();

QList<std::pair<QString, VoidFunc> > getMainWindowButtonStringAndFuncList();

QStringList getTriViewButtonStringList();
QList<VoidFunc> getTriViewButtonFuncList();

QStringList getView3dButtonStringList();
QList<VoidFunc> getView3dButtonFuncList();

class CustomToolButton : public QObject
{
	Q_OBJECT
	public:
		QAction * button;

		void * slot_class;
		VoidFunc slot_func;
		int bt;  			// 0 mainwindow menu, 1 triview button, 2 view3d button, 3 plugin menu

		V3DPluginCallback2 * callback;
		QWidget * parent;   // parent should be v3d MainWindow type, when invoke QMainWindow menu action

		QString buttonName; // the identification of different button. With Format:
							// mainwindow menu : Full menu path,          eg. File::Open
							// triview button  : button's display label,  eg. See in 3D
							// view3d button   : button's display label,  eg. Sync Tri-view Objs
							// plugin menu     : plugin path + menu name, eg. /home/hang/Applications/v3d/plugin/ct3d/libct3d_debug.dylib::About

	public:
		CustomToolButton(QIcon * icon, const QString &text, QObject* parent)
		{
			if(!icon) button = new QAction(text, parent);
			else button = new QAction(*icon, text, parent);
			slot_class = 0;
			connect(button, SIGNAL(triggered(bool)), this, SLOT(run()));
		}
		~CustomToolButton()
		{
			delete button;
			button = 0;
			slot_class = 0;
		}

		public slots: 
			void setButtonText(const QString & text)
			{
				if(button && button->isVisible()) button->setText(text);
			}

		bool run();
};

class CustomToolbarSetting
{
	public:
		QToolBar * toolBar;
		QString toolBarTitle;                        // preloaded toolbar title
		Qt::ToolBarArea position;                    // preloaded toolbar position

		QStringList preLoadedNameList;      
		QStringList preLoadedAliasList;

		QList<CustomToolButton*> activeMainWindowButtonList;
		QList<CustomToolButton*> activeTriViewButtonList;
		QList<CustomToolButton*> activeView3dButtonList;
		QList<CustomToolButton*> activePluginButtonList;

		QList<CustomToolButton*> allActiveButtonList;

	public:
		CustomToolbarSetting(QString title)
		{
			toolBar = 0; 
			toolBarTitle = title;
			position = Qt::TopToolBarArea;
		}
		CustomToolbarSetting(QToolBar* _toolBar)
		{
			toolBar = _toolBar;
			toolBarTitle = toolBar->windowTitle();
			position = Qt::TopToolBarArea;
		}
		~CustomToolbarSetting()
		{
		}
};

bool loadToolBarSettings();
bool saveToolBarSettings();
QList<CustomToolbarSetting*>& getToolBarSettingList();
void setToolBarSettingList(QList<CustomToolbarSetting*> & _settingList);

class CustomToolbarSelectWidget : public QWidget
{
	Q_OBJECT

	public:
		CustomToolbarSelectWidget(CustomToolbarSetting * _cts, V3DPluginCallback2 *callback, QWidget * parent);

		~CustomToolbarSelectWidget();

		void setInitialToolBarButton();

		CustomToolButton * getButtonFromButtonName(QString buttonName);
		CustomToolButton * getButtonFromCheckbox(QCheckBox* checkbox);
		CustomToolButton * getButtonFromAction(QAction* action);

	public slots:
		void setToolBarButton(bool state);
		void saveToolBarState();
		void openMe();
	protected:
		void closeEvent(QCloseEvent *event);

	public:
		CustomToolbarSetting* cts;
		QToolBar * toolBar;

		QTabWidget * tabWidget;
		QWidget * pageMainWindow;
		QWidget * pageTriView;
		QWidget * pageView3d;
		QWidget * pagePlugin;

		QHBoxLayout * mainLayout;
		QVBoxLayout * pageMainWindowLayout;
		QVBoxLayout * pageTriViewLayout;
		QVBoxLayout * pageView3dLayout;
		QVBoxLayout * pagePluginLayout;

		QTreeWidget * mainWindowTreeWidget;
		QList<QLineEdit *> mainWindowEditorList;
		QList<QCheckBox *> mainWindowCheckboxList;
		QList<CustomToolButton *> mainWindowCustomToolButtonList;

		QTreeWidget * triViewTreeWidget;
		QList<QLineEdit *> triViewEditorList;
		QList<QCheckBox *> triViewCheckboxList;
		QList<CustomToolButton *> triViewCustomToolButtonList;

		QTreeWidget * view3dTreeWidget;
		QList<QLineEdit *> view3dEditorList;
		QList<QCheckBox *> view3dCheckboxList;
		QList<CustomToolButton *> view3dCustomToolButtonList;

		QTreeWidget * pluginTreeWidget;
		QList<QLineEdit *> pluginEditorList;
		QList<QCheckBox *> pluginCheckboxList;
		QList<CustomToolButton *> pluginCustomToolButtonList;
		QList<QPluginLoader *> pluginLoaderList;

		QIcon pluginIcon;
		QIcon interfaceIcon;
		QIcon menuIcon;
		QIcon funcIcon;

		QIcon toolButtonIcon;
};

class CustomToolbar : public QToolBar
{
public:
	CustomToolbar(QString title , V3DPluginCallback2 * callback, QWidget * parent);
	CustomToolbar(CustomToolbarSetting * _cts , V3DPluginCallback2 * callback, QWidget * parent);
	~CustomToolbar();

	bool showToMainWindow(QMainWindow* _mw = 0);
public:
	CustomToolbarSetting* cts;
	CustomToolbarSelectWidget* selectWidget;
};

#endif
