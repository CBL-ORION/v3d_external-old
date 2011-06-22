/*
 * swc_to_maskimg.h
 *
 *  Created by Yang, Jinzhu on 11/27/10.
 *  Last change: by Hanchuan Peng, 2010-Dec-7. change some writing style of this Plugin header
 *
 */

#ifndef __SWC_SORT_H_
#define __SWC_SORT_H

#include <QtGui>
#include <stdio.h>
#include <stdlib.h>
#include "v3d_interface.h"
#include "../../../v3d_main/basic_c_fun/basic_surf_objs.h"

class SORT_SWCPlugin: public QObject, public V3DPluginInterface
{
    Q_OBJECT
    Q_INTERFACES(V3DPluginInterface);
	
public:
	QStringList menulist() const;
	void domenu(const QString &menu_name, V3DPluginCallback &callback, QWidget *parent);
	QStringList funclist() const {return QStringList();}
	void dofunc(const QString &func_name, const V3DPluginArgList &input, V3DPluginArgList &output, QWidget *parent) {}	
	
};

QHash<V3DLONG, V3DLONG> NeuronNextPn(const NeuronTree &neurons);
void DFS(bool** matrix, V3DLONG* neworder, V3DLONG node, V3DLONG* id, V3DLONG siz, bool* numbered);
QHash<V3DLONG, V3DLONG> ChildParent(const NeuronTree &neurons, QList<V3DLONG> & idlist);
void SortSWC(const NeuronTree & neurons, QList<NeuronSWC> & listNeuron, V3DLONG newrootid);
void sort_swc(V3DPluginCallback &callback, QWidget *parent, int method_code);


#endif


