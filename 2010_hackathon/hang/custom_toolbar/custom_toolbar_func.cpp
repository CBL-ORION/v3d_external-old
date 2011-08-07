/* custom_toolbar_func.cpp
 * This plugin is used to define the toolbox by yourself
 * 2011-08-04 : by Hang Xiao
 */

#include <v3d_interface.h>
#include "v3d_message.h"
#include "custom_toolbar_func.h"
#include "custom_toolbar_gui.h"

const QString title = QObject::tr("Quick Button Plugin");

static int bar_num = 1;
bool isFirstLoading = true;
int custom_toolbar(V3DPluginCallback2 &callback, QWidget *parent)
{
	QList<CustomToolbarSetting*> & settingList = getToolBarSettingList();

	// loadToolBarSettings will return to  settingList
	if(isFirstLoading && loadToolBarSettings() && !settingList.empty())
	{
		bar_num = settingList.size() + 1;

		foreach(CustomToolbarSetting* cts, settingList)
		{
			CustomToolbar * ct = new CustomToolbar(cts, &callback, parent);
			if(!ct->showToMainWindow()) ct->show();
		}
	}
	else
	{
		qDebug()<<"start a new toolbar"<<endl;
		QString barTitle = bar_num > 1 ? QObject::tr("Custom Toolbar - %1").arg(bar_num) : QObject::tr("Custom Toolbar");

		CustomToolbar * ct = new CustomToolbar(barTitle, &callback, parent);

		if(!ct->showToMainWindow()) ct->show();

		settingList.push_back(ct->cts);

		bar_num++;
	}

	isFirstLoading = false;
	return 1;
}

