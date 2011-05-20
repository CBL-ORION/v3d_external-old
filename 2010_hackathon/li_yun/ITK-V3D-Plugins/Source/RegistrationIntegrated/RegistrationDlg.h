#ifndef RegistrationDlg_H
#define RegistrationDlg_H

#include <QtGui>
#include <QWidget>
#include <v3d_interface.h>

class QListWidget;
class QListWidgetItem;
class QStackedWidget;

class RegistrationDlg:public QDialog
{
    Q_OBJECT
public:
    RegistrationDlg();
    void SetCallback(V3DPluginCallback &callback);
    QString getTransformType();
    QString getInterpolateType();
    QString getMetricType();
    QString getOptimizerType();
public slots:
    void updateOptim(int i);
    void updateConfig();
    void Start();
    void Subtract();
    void Exit();
private:
    QLabel *TransformLabel;
    QComboBox *TransformMethod;
    QLabel *InterpolateLabel;
    QComboBox *InterpolateMethod;
    QLabel *MetricLabel;
    QComboBox *MetricMethod;
    QLabel *OptimizerLabel;
    QComboBox *OptimizerMethod;

    QLabel *RegTypeLabel;
    QComboBox *RegType;

    QLabel *FinalParameterLabel;
    QTextEdit *FinalParameterEdit;
    QLabel *RegSelectLabel;
    QListWidget *RegSelectList;

    QPushButton *StartBtn;
    QPushButton *SubtractBtn;
    QPushButton *ExitBtn;

    QString transform;
    QString interpolator;
    QString metric;
    QString optimizer;
    QString reg_str;

    V3DPluginCallback *callback;

};

#endif