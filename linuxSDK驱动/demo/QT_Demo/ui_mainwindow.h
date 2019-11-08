/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Mar 21 14:29:24 2014
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *gvMain;
    QFrame *res_frame;
    QComboBox *res_combobox;
    QFrame *frame_2;
    QFrame *frame_3;
    QLabel *label;
    QSlider *gamma_horizontalSlider;
    QSlider *contrast_horizontalSlider;
    QLabel *label_2;
    QSpinBox *spinBox_gamma;
    QSpinBox *spinBox_contrast;
    QFrame *frame_trigger;
    QRadioButton *radioButton_collect;
    QPushButton *software_trigger_once_button;
    QRadioButton *radioButton_software_trigger;
    QRadioButton *radioButton_trigger_hardware;
    QFrame *flashlight;
    QRadioButton *flashlight_auto;
    QRadioButton *flashlight_manual;
    QFrame *flashlight_polarity;
    QRadioButton *flashlight_h;
    QRadioButton *flashlight_l;
    QLabel *label_26;
    QLabel *label_27;
    QFrame *frame_5;
    QFrame *frame_exposure_mode;
    QRadioButton *exposure_mode_auto;
    QRadioButton *exposure_mode_manual;
    QFrame *exposure_auto;
    QLabel *label_3;
    QSlider *AE_horizontalSlider;
    QCheckBox *flicker_checkBox;
    QRadioButton *radioButton_50HZ;
    QRadioButton *radioButton_60HZ;
    QSpinBox *AE_spinBox;
    QFrame *exposure_manual;
    QLabel *label_4;
    QLabel *label_5;
    QSlider *horizontalSlider_gain;
    QSlider *horizontalSlider_exposure_time;
    QSpinBox *spinBox_gain;
    QLineEdit *lineEdit_exposure_time;
    QFrame *frame_9;
    QLabel *label_6;
    QSlider *horizontalSlider_isp_acutance;
    QCheckBox *checkBox_isp_h;
    QCheckBox *checkBox_isp_v;
    QSpinBox *spinBox_isp_acutance;
    QFrame *frame_10;
    QPushButton *pushButton_para_save;
    QPushButton *pushButton_para_acquiesce;
    QPushButton *pushButton_para_load;
    QRadioButton *radioButton_A;
    QRadioButton *radioButton_C;
    QRadioButton *radioButton_D;
    QRadioButton *radioButton_B;
    QFrame *frame_wb;
    QLabel *label_7;
    QLabel *label_8;
    QRadioButton *radioButton_AWB_auto;
    QRadioButton *radioButton_13;
    QPushButton *AWB_once_button;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QSlider *horizontalSlider_gain_r;
    QSlider *horizontalSlider_gain_g;
    QSlider *horizontalSlider_gain_b;
    QSlider *horizontalSlider_saturation;
    QSpinBox *spinBox_gain_r;
    QSpinBox *spinBox_gain_g;
    QSpinBox *spinBox_gain_b;
    QSpinBox *spinBox_saturation;
    QFrame *frame_12;
    QPushButton *pushButton_snap_catch;
    QRadioButton *radioButton_16;
    QRadioButton *radioButton_17;
    QCheckBox *checkBox_4;
    QPushButton *pushButton_8;
    QPushButton *pushButton_snap_path;
    QCheckBox *checkBox_5;
    QLabel *label_19;
    QLabel *label_20;
    QRadioButton *radioButton_18;
    QRadioButton *radioButton_19;
    QRadioButton *radioButton_bmp;
    QRadioButton *radioButton_raw;
    QLabel *label_21;
    QLabel *label_22;
    QLineEdit *snap_path_lineEdit;
    QLineEdit *lineEdit_2;
    QFrame *frame_speed;
    QGroupBox *groupBox_speed;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1440, 640);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1440, 640));
        MainWindow->setMaximumSize(QSize(1440, 640));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gvMain = new QGraphicsView(centralWidget);
        gvMain->setObjectName(QString::fromUtf8("gvMain"));
        gvMain->setGeometry(QRect(10, 0, 800, 600));
        QBrush brush(QColor(127, 127, 127, 255));
        brush.setStyle(Qt::SolidPattern);
        gvMain->setBackgroundBrush(brush);
        res_frame = new QFrame(centralWidget);
        res_frame->setObjectName(QString::fromUtf8("res_frame"));
        res_frame->setGeometry(QRect(830, 20, 250, 45));
        res_frame->setFrameShape(QFrame::StyledPanel);
        res_frame->setFrameShadow(QFrame::Raised);
        res_combobox = new QComboBox(res_frame);
        res_combobox->setObjectName(QString::fromUtf8("res_combobox"));
        res_combobox->setGeometry(QRect(5, 10, 240, 30));
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(1090, 20, 330, 80));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(5, 5, 320, 70));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 40, 20));
        gamma_horizontalSlider = new QSlider(frame_3);
        gamma_horizontalSlider->setObjectName(QString::fromUtf8("gamma_horizontalSlider"));
        gamma_horizontalSlider->setGeometry(QRect(80, 10, 180, 20));
        gamma_horizontalSlider->setOrientation(Qt::Horizontal);
        contrast_horizontalSlider = new QSlider(frame_3);
        contrast_horizontalSlider->setObjectName(QString::fromUtf8("contrast_horizontalSlider"));
        contrast_horizontalSlider->setGeometry(QRect(80, 40, 180, 20));
        contrast_horizontalSlider->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 50, 20));
        spinBox_gamma = new QSpinBox(frame_3);
        spinBox_gamma->setObjectName(QString::fromUtf8("spinBox_gamma"));
        spinBox_gamma->setGeometry(QRect(260, 10, 50, 20));
        spinBox_contrast = new QSpinBox(frame_3);
        spinBox_contrast->setObjectName(QString::fromUtf8("spinBox_contrast"));
        spinBox_contrast->setGeometry(QRect(260, 40, 50, 20));
        frame_trigger = new QFrame(centralWidget);
        frame_trigger->setObjectName(QString::fromUtf8("frame_trigger"));
        frame_trigger->setGeometry(QRect(830, 90, 250, 100));
        frame_trigger->setFrameShape(QFrame::StyledPanel);
        frame_trigger->setFrameShadow(QFrame::Raised);
        radioButton_collect = new QRadioButton(frame_trigger);
        radioButton_collect->setObjectName(QString::fromUtf8("radioButton_collect"));
        radioButton_collect->setGeometry(QRect(10, 10, 100, 20));
        software_trigger_once_button = new QPushButton(frame_trigger);
        software_trigger_once_button->setObjectName(QString::fromUtf8("software_trigger_once_button"));
        software_trigger_once_button->setGeometry(QRect(5, 70, 100, 27));
        radioButton_software_trigger = new QRadioButton(frame_trigger);
        radioButton_software_trigger->setObjectName(QString::fromUtf8("radioButton_software_trigger"));
        radioButton_software_trigger->setGeometry(QRect(10, 30, 100, 20));
        radioButton_trigger_hardware = new QRadioButton(frame_trigger);
        radioButton_trigger_hardware->setObjectName(QString::fromUtf8("radioButton_trigger_hardware"));
        radioButton_trigger_hardware->setEnabled(true);
        radioButton_trigger_hardware->setGeometry(QRect(10, 50, 80, 20));
        flashlight = new QFrame(frame_trigger);
        flashlight->setObjectName(QString::fromUtf8("flashlight"));
        flashlight->setGeometry(QRect(110, 20, 130, 75));
        flashlight->setFrameShape(QFrame::StyledPanel);
        flashlight->setFrameShadow(QFrame::Raised);
        flashlight_auto = new QRadioButton(flashlight);
        flashlight_auto->setObjectName(QString::fromUtf8("flashlight_auto"));
        flashlight_auto->setGeometry(QRect(5, 5, 55, 22));
        flashlight_manual = new QRadioButton(flashlight);
        flashlight_manual->setObjectName(QString::fromUtf8("flashlight_manual"));
        flashlight_manual->setGeometry(QRect(60, 5, 55, 22));
        flashlight_polarity = new QFrame(flashlight);
        flashlight_polarity->setObjectName(QString::fromUtf8("flashlight_polarity"));
        flashlight_polarity->setGeometry(QRect(10, 40, 110, 30));
        flashlight_polarity->setFrameShape(QFrame::StyledPanel);
        flashlight_polarity->setFrameShadow(QFrame::Raised);
        flashlight_h = new QRadioButton(flashlight_polarity);
        flashlight_h->setObjectName(QString::fromUtf8("flashlight_h"));
        flashlight_h->setGeometry(QRect(5, 5, 40, 22));
        flashlight_l = new QRadioButton(flashlight_polarity);
        flashlight_l->setObjectName(QString::fromUtf8("flashlight_l"));
        flashlight_l->setGeometry(QRect(50, 5, 50, 22));
        label_26 = new QLabel(flashlight);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(10, 25, 62, 17));
        label_27 = new QLabel(frame_trigger);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(120, 5, 90, 17));
        frame_5 = new QFrame(centralWidget);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(830, 215, 270, 205));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        frame_exposure_mode = new QFrame(frame_5);
        frame_exposure_mode->setObjectName(QString::fromUtf8("frame_exposure_mode"));
        frame_exposure_mode->setGeometry(QRect(10, 10, 250, 35));
        frame_exposure_mode->setFrameShape(QFrame::StyledPanel);
        frame_exposure_mode->setFrameShadow(QFrame::Raised);
        exposure_mode_auto = new QRadioButton(frame_exposure_mode);
        exposure_mode_auto->setObjectName(QString::fromUtf8("exposure_mode_auto"));
        exposure_mode_auto->setGeometry(QRect(10, 10, 109, 22));
        exposure_mode_manual = new QRadioButton(frame_exposure_mode);
        exposure_mode_manual->setObjectName(QString::fromUtf8("exposure_mode_manual"));
        exposure_mode_manual->setGeometry(QRect(120, 10, 109, 22));
        exposure_auto = new QFrame(frame_5);
        exposure_auto->setObjectName(QString::fromUtf8("exposure_auto"));
        exposure_auto->setGeometry(QRect(10, 55, 250, 70));
        exposure_auto->setFrameShape(QFrame::StyledPanel);
        exposure_auto->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(exposure_auto);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 10, 60, 20));
        AE_horizontalSlider = new QSlider(exposure_auto);
        AE_horizontalSlider->setObjectName(QString::fromUtf8("AE_horizontalSlider"));
        AE_horizontalSlider->setGeometry(QRect(70, 10, 120, 20));
        AE_horizontalSlider->setMaximum(300);
        AE_horizontalSlider->setValue(99);
        AE_horizontalSlider->setOrientation(Qt::Horizontal);
        flicker_checkBox = new QCheckBox(exposure_auto);
        flicker_checkBox->setObjectName(QString::fromUtf8("flicker_checkBox"));
        flicker_checkBox->setGeometry(QRect(10, 40, 70, 20));
        radioButton_50HZ = new QRadioButton(exposure_auto);
        radioButton_50HZ->setObjectName(QString::fromUtf8("radioButton_50HZ"));
        radioButton_50HZ->setGeometry(QRect(90, 40, 60, 20));
        radioButton_60HZ = new QRadioButton(exposure_auto);
        radioButton_60HZ->setObjectName(QString::fromUtf8("radioButton_60HZ"));
        radioButton_60HZ->setGeometry(QRect(160, 40, 70, 20));
        AE_spinBox = new QSpinBox(exposure_auto);
        AE_spinBox->setObjectName(QString::fromUtf8("AE_spinBox"));
        AE_spinBox->setGeometry(QRect(190, 10, 50, 20));
        AE_spinBox->setMaximum(300);
        exposure_manual = new QFrame(frame_5);
        exposure_manual->setObjectName(QString::fromUtf8("exposure_manual"));
        exposure_manual->setEnabled(true);
        exposure_manual->setGeometry(QRect(10, 135, 250, 60));
        exposure_manual->setFrameShape(QFrame::StyledPanel);
        exposure_manual->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(exposure_manual);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 10, 60, 20));
        label_5 = new QLabel(exposure_manual);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 40, 60, 20));
        horizontalSlider_gain = new QSlider(exposure_manual);
        horizontalSlider_gain->setObjectName(QString::fromUtf8("horizontalSlider_gain"));
        horizontalSlider_gain->setGeometry(QRect(70, 10, 110, 20));
        horizontalSlider_gain->setOrientation(Qt::Horizontal);
        horizontalSlider_exposure_time = new QSlider(exposure_manual);
        horizontalSlider_exposure_time->setObjectName(QString::fromUtf8("horizontalSlider_exposure_time"));
        horizontalSlider_exposure_time->setGeometry(QRect(70, 40, 110, 20));
        horizontalSlider_exposure_time->setOrientation(Qt::Horizontal);
        spinBox_gain = new QSpinBox(exposure_manual);
        spinBox_gain->setObjectName(QString::fromUtf8("spinBox_gain"));
        spinBox_gain->setGeometry(QRect(180, 10, 65, 20));
        lineEdit_exposure_time = new QLineEdit(exposure_manual);
        lineEdit_exposure_time->setObjectName(QString::fromUtf8("lineEdit_exposure_time"));
        lineEdit_exposure_time->setGeometry(QRect(180, 35, 65, 25));
        frame_9 = new QFrame(centralWidget);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setEnabled(true);
        frame_9->setGeometry(QRect(830, 445, 270, 60));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        label_6 = new QLabel(frame_9);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 35, 60, 20));
        horizontalSlider_isp_acutance = new QSlider(frame_9);
        horizontalSlider_isp_acutance->setObjectName(QString::fromUtf8("horizontalSlider_isp_acutance"));
        horizontalSlider_isp_acutance->setGeometry(QRect(60, 35, 141, 20));
        horizontalSlider_isp_acutance->setOrientation(Qt::Horizontal);
        checkBox_isp_h = new QCheckBox(frame_9);
        checkBox_isp_h->setObjectName(QString::fromUtf8("checkBox_isp_h"));
        checkBox_isp_h->setGeometry(QRect(10, 10, 90, 20));
        checkBox_isp_v = new QCheckBox(frame_9);
        checkBox_isp_v->setObjectName(QString::fromUtf8("checkBox_isp_v"));
        checkBox_isp_v->setGeometry(QRect(160, 10, 90, 20));
        spinBox_isp_acutance = new QSpinBox(frame_9);
        spinBox_isp_acutance->setObjectName(QString::fromUtf8("spinBox_isp_acutance"));
        spinBox_isp_acutance->setGeometry(QRect(210, 35, 50, 20));
        frame_10 = new QFrame(centralWidget);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        frame_10->setGeometry(QRect(830, 525, 270, 70));
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        pushButton_para_save = new QPushButton(frame_10);
        pushButton_para_save->setObjectName(QString::fromUtf8("pushButton_para_save"));
        pushButton_para_save->setGeometry(QRect(120, 10, 70, 25));
        pushButton_para_acquiesce = new QPushButton(frame_10);
        pushButton_para_acquiesce->setObjectName(QString::fromUtf8("pushButton_para_acquiesce"));
        pushButton_para_acquiesce->setGeometry(QRect(190, 10, 70, 25));
        pushButton_para_load = new QPushButton(frame_10);
        pushButton_para_load->setObjectName(QString::fromUtf8("pushButton_para_load"));
        pushButton_para_load->setGeometry(QRect(120, 40, 140, 25));
        radioButton_A = new QRadioButton(frame_10);
        radioButton_A->setObjectName(QString::fromUtf8("radioButton_A"));
        radioButton_A->setGeometry(QRect(20, 10, 40, 20));
        radioButton_C = new QRadioButton(frame_10);
        radioButton_C->setObjectName(QString::fromUtf8("radioButton_C"));
        radioButton_C->setGeometry(QRect(20, 40, 40, 20));
        radioButton_D = new QRadioButton(frame_10);
        radioButton_D->setObjectName(QString::fromUtf8("radioButton_D"));
        radioButton_D->setGeometry(QRect(70, 40, 40, 20));
        radioButton_B = new QRadioButton(frame_10);
        radioButton_B->setObjectName(QString::fromUtf8("radioButton_B"));
        radioButton_B->setGeometry(QRect(70, 10, 40, 20));
        frame_wb = new QFrame(centralWidget);
        frame_wb->setObjectName(QString::fromUtf8("frame_wb"));
        frame_wb->setGeometry(QRect(1110, 120, 310, 235));
        frame_wb->setFrameShape(QFrame::StyledPanel);
        frame_wb->setFrameShadow(QFrame::Raised);
        label_7 = new QLabel(frame_wb);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 10, 290, 20));
        label_8 = new QLabel(frame_wb);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 40, 60, 20));
        radioButton_AWB_auto = new QRadioButton(frame_wb);
        radioButton_AWB_auto->setObjectName(QString::fromUtf8("radioButton_AWB_auto"));
        radioButton_AWB_auto->setGeometry(QRect(80, 40, 60, 20));
        radioButton_13 = new QRadioButton(frame_wb);
        radioButton_13->setObjectName(QString::fromUtf8("radioButton_13"));
        radioButton_13->setEnabled(false);
        radioButton_13->setGeometry(QRect(160, 40, 60, 20));
        AWB_once_button = new QPushButton(frame_wb);
        AWB_once_button->setObjectName(QString::fromUtf8("AWB_once_button"));
        AWB_once_button->setGeometry(QRect(10, 65, 285, 25));
        label_9 = new QLabel(frame_wb);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 110, 60, 20));
        label_10 = new QLabel(frame_wb);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 140, 60, 20));
        label_11 = new QLabel(frame_wb);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 170, 60, 20));
        label_12 = new QLabel(frame_wb);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(20, 200, 60, 20));
        horizontalSlider_gain_r = new QSlider(frame_wb);
        horizontalSlider_gain_r->setObjectName(QString::fromUtf8("horizontalSlider_gain_r"));
        horizontalSlider_gain_r->setGeometry(QRect(90, 110, 160, 20));
        horizontalSlider_gain_r->setMaximum(400);
        horizontalSlider_gain_r->setPageStep(10);
        horizontalSlider_gain_r->setOrientation(Qt::Horizontal);
        horizontalSlider_gain_g = new QSlider(frame_wb);
        horizontalSlider_gain_g->setObjectName(QString::fromUtf8("horizontalSlider_gain_g"));
        horizontalSlider_gain_g->setGeometry(QRect(90, 140, 160, 20));
        horizontalSlider_gain_g->setMaximum(400);
        horizontalSlider_gain_g->setOrientation(Qt::Horizontal);
        horizontalSlider_gain_b = new QSlider(frame_wb);
        horizontalSlider_gain_b->setObjectName(QString::fromUtf8("horizontalSlider_gain_b"));
        horizontalSlider_gain_b->setGeometry(QRect(90, 170, 160, 20));
        horizontalSlider_gain_b->setMaximum(400);
        horizontalSlider_gain_b->setOrientation(Qt::Horizontal);
        horizontalSlider_saturation = new QSlider(frame_wb);
        horizontalSlider_saturation->setObjectName(QString::fromUtf8("horizontalSlider_saturation"));
        horizontalSlider_saturation->setGeometry(QRect(90, 200, 160, 20));
        horizontalSlider_saturation->setMaximum(200);
        horizontalSlider_saturation->setOrientation(Qt::Horizontal);
        spinBox_gain_r = new QSpinBox(frame_wb);
        spinBox_gain_r->setObjectName(QString::fromUtf8("spinBox_gain_r"));
        spinBox_gain_r->setGeometry(QRect(250, 110, 50, 20));
        spinBox_gain_r->setMaximum(400);
        spinBox_gain_g = new QSpinBox(frame_wb);
        spinBox_gain_g->setObjectName(QString::fromUtf8("spinBox_gain_g"));
        spinBox_gain_g->setGeometry(QRect(250, 140, 50, 20));
        spinBox_gain_g->setMaximum(400);
        spinBox_gain_b = new QSpinBox(frame_wb);
        spinBox_gain_b->setObjectName(QString::fromUtf8("spinBox_gain_b"));
        spinBox_gain_b->setGeometry(QRect(250, 170, 50, 20));
        spinBox_gain_b->setMaximum(400);
        spinBox_saturation = new QSpinBox(frame_wb);
        spinBox_saturation->setObjectName(QString::fromUtf8("spinBox_saturation"));
        spinBox_saturation->setGeometry(QRect(250, 200, 50, 20));
        spinBox_saturation->setMaximum(200);
        frame_12 = new QFrame(centralWidget);
        frame_12->setObjectName(QString::fromUtf8("frame_12"));
        frame_12->setGeometry(QRect(1110, 375, 310, 165));
        frame_12->setFrameShape(QFrame::StyledPanel);
        frame_12->setFrameShadow(QFrame::Raised);
        pushButton_snap_catch = new QPushButton(frame_12);
        pushButton_snap_catch->setObjectName(QString::fromUtf8("pushButton_snap_catch"));
        pushButton_snap_catch->setGeometry(QRect(10, 10, 50, 45));
        radioButton_16 = new QRadioButton(frame_12);
        radioButton_16->setObjectName(QString::fromUtf8("radioButton_16"));
        radioButton_16->setEnabled(false);
        radioButton_16->setGeometry(QRect(80, 10, 130, 20));
        radioButton_17 = new QRadioButton(frame_12);
        radioButton_17->setObjectName(QString::fromUtf8("radioButton_17"));
        radioButton_17->setEnabled(false);
        radioButton_17->setGeometry(QRect(80, 35, 130, 20));
        checkBox_4 = new QCheckBox(frame_12);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setEnabled(false);
        checkBox_4->setGeometry(QRect(10, 60, 110, 22));
        pushButton_8 = new QPushButton(frame_12);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setEnabled(false);
        pushButton_8->setGeometry(QRect(230, 10, 70, 45));
        pushButton_snap_path = new QPushButton(frame_12);
        pushButton_snap_path->setObjectName(QString::fromUtf8("pushButton_snap_path"));
        pushButton_snap_path->setGeometry(QRect(220, 85, 50, 25));
        checkBox_5 = new QCheckBox(frame_12);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setEnabled(false);
        checkBox_5->setGeometry(QRect(10, 140, 81, 20));
        label_19 = new QLabel(frame_12);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 90, 50, 20));
        label_20 = new QLabel(frame_12);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(10, 115, 40, 20));
        radioButton_18 = new QRadioButton(frame_12);
        radioButton_18->setObjectName(QString::fromUtf8("radioButton_18"));
        radioButton_18->setEnabled(false);
        radioButton_18->setGeometry(QRect(60, 115, 50, 20));
        radioButton_19 = new QRadioButton(frame_12);
        radioButton_19->setObjectName(QString::fromUtf8("radioButton_19"));
        radioButton_19->setEnabled(false);
        radioButton_19->setGeometry(QRect(120, 115, 60, 20));
        radioButton_bmp = new QRadioButton(frame_12);
        radioButton_bmp->setObjectName(QString::fromUtf8("radioButton_bmp"));
        radioButton_bmp->setGeometry(QRect(190, 115, 60, 20));
        radioButton_raw = new QRadioButton(frame_12);
        radioButton_raw->setObjectName(QString::fromUtf8("radioButton_raw"));
        radioButton_raw->setGeometry(QRect(250, 115, 60, 20));
        label_21 = new QLabel(frame_12);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(110, 140, 40, 20));
        label_22 = new QLabel(frame_12);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(240, 140, 40, 20));
        snap_path_lineEdit = new QLineEdit(frame_12);
        snap_path_lineEdit->setObjectName(QString::fromUtf8("snap_path_lineEdit"));
        snap_path_lineEdit->setGeometry(QRect(60, 85, 150, 25));
        lineEdit_2 = new QLineEdit(frame_12);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        lineEdit_2->setGeometry(QRect(150, 140, 80, 20));
        frame_speed = new QFrame(centralWidget);
        frame_speed->setObjectName(QString::fromUtf8("frame_speed"));
        frame_speed->setGeometry(QRect(1110, 560, 310, 35));
        frame_speed->setFrameShape(QFrame::StyledPanel);
        frame_speed->setFrameShadow(QFrame::Raised);
        groupBox_speed = new QGroupBox(frame_speed);
        groupBox_speed->setObjectName(QString::fromUtf8("groupBox_speed"));
        groupBox_speed->setGeometry(QRect(0, 0, 310, 35));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(1130, 545, 62, 17));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(1130, 360, 62, 17));
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(1130, 105, 80, 17));
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(1110, 5, 90, 17));
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(840, 510, 62, 17));
        label_18 = new QLabel(centralWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(840, 430, 90, 17));
        label_23 = new QLabel(centralWidget);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(840, 200, 62, 17));
        label_24 = new QLabel(centralWidget);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(840, 75, 62, 17));
        label_25 = new QLabel(centralWidget);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(840, 5, 62, 17));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setMaximumSize(QSize(800, 16777215));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\344\274\275\351\251\254", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\351\245\261\345\222\214\345\272\246", 0, QApplication::UnicodeUTF8));
        radioButton_collect->setText(QApplication::translate("MainWindow", "\350\277\236\347\273\255\351\207\207\351\233\206", 0, QApplication::UnicodeUTF8));
        software_trigger_once_button->setText(QApplication::translate("MainWindow", "\350\275\257\344\273\266\350\247\246\345\217\221\344\270\200\346\254\241", 0, QApplication::UnicodeUTF8));
        radioButton_software_trigger->setText(QApplication::translate("MainWindow", "\350\275\257\350\247\246\345\217\221", 0, QApplication::UnicodeUTF8));
        radioButton_trigger_hardware->setText(QApplication::translate("MainWindow", "\347\241\254\350\247\246\345\217\221", 0, QApplication::UnicodeUTF8));
        flashlight_auto->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250", 0, QApplication::UnicodeUTF8));
        flashlight_manual->setText(QApplication::translate("MainWindow", "\346\211\213\345\212\250", 0, QApplication::UnicodeUTF8));
        flashlight_h->setText(QApplication::translate("MainWindow", "\351\253\230", 0, QApplication::UnicodeUTF8));
        flashlight_l->setText(QApplication::translate("MainWindow", "\344\275\216", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("MainWindow", "\346\234\211\346\225\210\346\236\201\346\200\247", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("MainWindow", "\351\227\252\345\205\211\347\201\257\346\216\247\345\210\266", 0, QApplication::UnicodeUTF8));
        exposure_mode_auto->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250", 0, QApplication::UnicodeUTF8));
        exposure_mode_manual->setText(QApplication::translate("MainWindow", "\346\211\213\345\212\250", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "\344\272\256\345\272\246\347\233\256\346\240\207", 0, QApplication::UnicodeUTF8));
        flicker_checkBox->setText(QApplication::translate("MainWindow", "\346\212\227\351\242\221\351\227\252", 0, QApplication::UnicodeUTF8));
        radioButton_50HZ->setText(QApplication::translate("MainWindow", "50HZ", 0, QApplication::UnicodeUTF8));
        radioButton_60HZ->setText(QApplication::translate("MainWindow", "60HZ", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "\345\242\236\347\233\212", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "\346\233\235\345\205\211\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "\351\224\220\345\272\246", 0, QApplication::UnicodeUTF8));
        checkBox_isp_h->setText(QApplication::translate("MainWindow", "\346\260\264\345\271\263\351\225\234\345\203\217", 0, QApplication::UnicodeUTF8));
        checkBox_isp_v->setText(QApplication::translate("MainWindow", "\345\236\202\347\233\264\351\225\234\345\203\217", 0, QApplication::UnicodeUTF8));
        pushButton_para_save->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        pushButton_para_acquiesce->setText(QApplication::translate("MainWindow", "\351\273\230\350\256\244", 0, QApplication::UnicodeUTF8));
        pushButton_para_load->setText(QApplication::translate("MainWindow", "\344\273\216\346\226\207\344\273\266\344\270\255\345\212\240\350\275\275", 0, QApplication::UnicodeUTF8));
        radioButton_A->setText(QApplication::translate("MainWindow", "A", 0, QApplication::UnicodeUTF8));
        radioButton_C->setText(QApplication::translate("MainWindow", "C", 0, QApplication::UnicodeUTF8));
        radioButton_D->setText(QApplication::translate("MainWindow", "D", 0, QApplication::UnicodeUTF8));
        radioButton_B->setText(QApplication::translate("MainWindow", "B", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "\350\257\245\347\233\270\346\234\272\346\230\257\351\273\221\347\231\275\347\233\270\346\234\272\357\274\214\346\237\220\344\272\233\345\217\202\346\225\260\346\227\240\346\263\225\350\260\203\350\212\202", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        radioButton_AWB_auto->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250", 0, QApplication::UnicodeUTF8));
        radioButton_13->setText(QApplication::translate("MainWindow", "\346\211\213\345\212\250", 0, QApplication::UnicodeUTF8));
        AWB_once_button->setText(QApplication::translate("MainWindow", "\344\270\200\351\224\256\347\231\275\345\271\263\350\241\241", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "\347\272\242\350\211\262\345\242\236\347\233\212", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "\347\273\277\350\211\262\345\242\236\347\233\212", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "\350\223\235\350\211\262\345\242\236\347\233\212", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "\351\245\261\345\222\214\345\272\246", 0, QApplication::UnicodeUTF8));
        pushButton_snap_catch->setText(QApplication::translate("MainWindow", "\346\215\225\350\216\267", 0, QApplication::UnicodeUTF8));
        radioButton_16->setText(QApplication::translate("MainWindow", "\345\222\214\351\242\204\350\247\210\345\210\206\350\276\250\347\216\207\347\233\270\345\220\214", 0, QApplication::UnicodeUTF8));
        radioButton_17->setText(QApplication::translate("MainWindow", "\350\207\252\345\256\232\344\271\211\346\212\223\346\213\215\345\210\206\350\276\250\347\216\207", 0, QApplication::UnicodeUTF8));
        checkBox_4->setText(QApplication::translate("MainWindow", "\345\277\275\347\225\245\345\217\240\345\212\240\345\206\205\345\256\271", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\345\210\206\350\276\250\347\216\207", 0, QApplication::UnicodeUTF8));
        pushButton_snap_path->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        checkBox_5->setText(QApplication::translate("MainWindow", "\345\256\232\346\227\266\346\215\225\350\216\267", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "\350\267\257\345\276\204\357\274\232", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "\346\240\274\345\274\217", 0, QApplication::UnicodeUTF8));
        radioButton_18->setText(QApplication::translate("MainWindow", "JPG", 0, QApplication::UnicodeUTF8));
        radioButton_19->setText(QApplication::translate("MainWindow", "PNG", 0, QApplication::UnicodeUTF8));
        radioButton_bmp->setText(QApplication::translate("MainWindow", "BMP", 0, QApplication::UnicodeUTF8));
        radioButton_raw->setText(QApplication::translate("MainWindow", "RAW", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "\345\221\250\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", "\346\257\253\347\247\222", 0, QApplication::UnicodeUTF8));
        groupBox_speed->setTitle(QString());
        label_13->setText(QApplication::translate("MainWindow", "\351\200\237\345\272\246\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "\346\212\223\346\213\215\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "ISP\351\242\234\350\211\262\345\244\204\347\220\206", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "\346\237\245\350\241\250\346\230\240\345\260\204\345\217\230\346\215\242", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260\347\273\204", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "ISP\345\233\276\345\203\217\345\244\204\347\220\206", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MainWindow", "\346\233\235\345\205\211\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MainWindow", "\350\247\246\345\217\221\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("MainWindow", "\345\210\206\350\276\250\347\216\207", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
