/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *frame_2;
    QPushButton *closeSerialPortBtn;
    QComboBox *serialPortCb;
    QLabel *label;
    QPushButton *openSerialPortBtn;
    QFrame *frame_3;
    QPushButton *checkSwVerBtn;
    QLabel *label_66;
    QLabel *label_67;
    QLabel *type;
    QLabel *swSerialNumLabel;
    QFrame *frame_4;
    QLabel *label_37;
    QListWidget *oldCmdsLb;
    QLabel *label_36;
    QTextBrowser *outputTb;
    QPushButton *outputClearBtn;
    QPushButton *inputClearBtn;
    QFrame *frame_8;
    QPushButton *polling;
    QPushButton *auto_polling;
    QCheckBox *auto_polling_B;
    QLabel *label_38;
    QPushButton *allowEnterBtn_A;
    QPushButton *allowEnterBtn_B;
    QLabel *label_2;
    QPushButton *reser_alarm;
    QFrame *line;
    QFrame *frame_12;
    QPushButton *setModeBtn;
    QLabel *label_23;
    QComboBox *runModeCB;
    QFrame *frame;
    QPushButton *moduleTestBtn;
    QLabel *label_39;
    QComboBox *testContentCB;
    QCheckBox *sensorStatusCheckBox;
    QFrame *frame_7;
    QCheckBox *checkBox_S5;
    QCheckBox *checkBox_S1;
    QCheckBox *checkBox_S3;
    QCheckBox *checkBox_S6;
    QCheckBox *checkBox_S4;
    QCheckBox *checkBox_S2;
    QCheckBox *checkBox_S15;
    QCheckBox *checkBox_S13;
    QCheckBox *checkBox_S16;
    QCheckBox *checkBox_S14;
    QLabel *label_68;
    QCheckBox *checkBox_S12;
    QCheckBox *checkBox_S8;
    QCheckBox *checkBox_S10;
    QCheckBox *checkBox_S9;
    QCheckBox *checkBox_S7;
    QCheckBox *checkBox_S11;
    QLabel *label_41;
    QFrame *line_2;
    QCheckBox *checkBox_S1_2;
    QCheckBox *checkBox_S2_2;
    QCheckBox *checkBox_S3_2;
    QCheckBox *checkBox_S4_2;
    QCheckBox *checkBox_S5_2;
    QCheckBox *checkBox_S6_2;
    QCheckBox *checkBox_S7_2;
    QCheckBox *checkBox_S8_2;
    QCheckBox *checkBox_S10_2;
    QCheckBox *checkBox_S9_2;
    QCheckBox *checkBox_S11_2;
    QCheckBox *checkBox_S13_2;
    QCheckBox *checkBox_S12_2;
    QCheckBox *checkBox_S14_2;
    QCheckBox *checkBox_S15_2;
    QCheckBox *checkBox_S16_2;
    QLabel *label_42;
    QFrame *frame_6;
    QPushButton *checkParamStatusBtn;
    QPushButton *setParamsBtn;
    QLineEdit *param11LE;
    QLineEdit *param4LE;
    QLabel *label_25;
    QLineEdit *param3LE;
    QLabel *label_30;
    QLineEdit *param7LE;
    QLabel *label_35;
    QLabel *label_27;
    QLabel *label_29;
    QLineEdit *param1LE;
    QLineEdit *param2LE;
    QLineEdit *param6LE;
    QLabel *label_28;
    QLabel *label_31;
    QLineEdit *param5LE;
    QLabel *label_26;
    QLabel *label_34;
    QLabel *label_40;
    QLineEdit *param11LE_2;
    QLineEdit *param7LE_2;
    QFrame *frame_11;
    QCheckBox *AD_M;
    QCheckBox *AD_R;
    QCheckBox *AD_G;
    QCheckBox *BD_M;
    QCheckBox *BD_R;
    QCheckBox *BD_G;
    QLabel *label_24;
    QPushButton *AD_switch;
    QPushButton *BD_switch;
    QPushButton *getstatus;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QCheckBox *pcm_check;
    QPushButton *pcm_polling;
    QLabel *label_4;
    QLineEdit *baojing;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1173, 670);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(910, 670));
        MainWindow->setMaximumSize(QSize(1500, 1300));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setMinimumSize(QSize(900, 660));
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(10, 20, 621, 41));
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Sunken);
        closeSerialPortBtn = new QPushButton(frame_2);
        closeSerialPortBtn->setObjectName(QStringLiteral("closeSerialPortBtn"));
        closeSerialPortBtn->setGeometry(QRect(470, 10, 98, 20));
        sizePolicy.setHeightForWidth(closeSerialPortBtn->sizePolicy().hasHeightForWidth());
        closeSerialPortBtn->setSizePolicy(sizePolicy);
        serialPortCb = new QComboBox(frame_2);
        serialPortCb->setObjectName(QStringLiteral("serialPortCb"));
        serialPortCb->setGeometry(QRect(60, 10, 121, 20));
        sizePolicy.setHeightForWidth(serialPortCb->sizePolicy().hasHeightForWidth());
        serialPortCb->setSizePolicy(sizePolicy);
        label = new QLabel(frame_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 30, 20));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(9);
        label->setFont(font);
        openSerialPortBtn = new QPushButton(frame_2);
        openSerialPortBtn->setObjectName(QStringLiteral("openSerialPortBtn"));
        openSerialPortBtn->setGeometry(QRect(260, 10, 98, 20));
        sizePolicy.setHeightForWidth(openSerialPortBtn->sizePolicy().hasHeightForWidth());
        openSerialPortBtn->setSizePolicy(sizePolicy);
        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(630, 20, 521, 41));
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Sunken);
        checkSwVerBtn = new QPushButton(frame_3);
        checkSwVerBtn->setObjectName(QStringLiteral("checkSwVerBtn"));
        checkSwVerBtn->setGeometry(QRect(30, 10, 111, 21));
        sizePolicy.setHeightForWidth(checkSwVerBtn->sizePolicy().hasHeightForWidth());
        checkSwVerBtn->setSizePolicy(sizePolicy);
        label_66 = new QLabel(frame_3);
        label_66->setObjectName(QStringLiteral("label_66"));
        label_66->setGeometry(QRect(170, 10, 91, 20));
        sizePolicy.setHeightForWidth(label_66->sizePolicy().hasHeightForWidth());
        label_66->setSizePolicy(sizePolicy);
        label_67 = new QLabel(frame_3);
        label_67->setObjectName(QStringLiteral("label_67"));
        label_67->setGeometry(QRect(330, 10, 91, 20));
        type = new QLabel(frame_3);
        type->setObjectName(QStringLiteral("type"));
        type->setGeometry(QRect(260, 10, 51, 20));
        swSerialNumLabel = new QLabel(frame_3);
        swSerialNumLabel->setObjectName(QStringLiteral("swSerialNumLabel"));
        swSerialNumLabel->setGeometry(QRect(420, 10, 101, 20));
        frame_4 = new QFrame(centralWidget);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(10, 60, 1141, 111));
        sizePolicy.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy);
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Sunken);
        label_37 = new QLabel(frame_4);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(10, 0, 20, 111));
        sizePolicy.setHeightForWidth(label_37->sizePolicy().hasHeightForWidth());
        label_37->setSizePolicy(sizePolicy);
        oldCmdsLb = new QListWidget(frame_4);
        oldCmdsLb->setObjectName(QStringLiteral("oldCmdsLb"));
        oldCmdsLb->setGeometry(QRect(30, 10, 531, 91));
        sizePolicy.setHeightForWidth(oldCmdsLb->sizePolicy().hasHeightForWidth());
        oldCmdsLb->setSizePolicy(sizePolicy);
        label_36 = new QLabel(frame_4);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(670, 0, 20, 101));
        sizePolicy.setHeightForWidth(label_36->sizePolicy().hasHeightForWidth());
        label_36->setSizePolicy(sizePolicy);
        outputTb = new QTextBrowser(frame_4);
        outputTb->setObjectName(QStringLiteral("outputTb"));
        outputTb->setGeometry(QRect(710, 10, 380, 91));
        sizePolicy.setHeightForWidth(outputTb->sizePolicy().hasHeightForWidth());
        outputTb->setSizePolicy(sizePolicy);
        outputClearBtn = new QPushButton(frame_4);
        outputClearBtn->setObjectName(QStringLiteral("outputClearBtn"));
        outputClearBtn->setGeometry(QRect(1100, 10, 20, 90));
        inputClearBtn = new QPushButton(frame_4);
        inputClearBtn->setObjectName(QStringLiteral("inputClearBtn"));
        inputClearBtn->setEnabled(true);
        inputClearBtn->setGeometry(QRect(570, 10, 21, 90));
        sizePolicy.setHeightForWidth(inputClearBtn->sizePolicy().hasHeightForWidth());
        inputClearBtn->setSizePolicy(sizePolicy);
        frame_8 = new QFrame(centralWidget);
        frame_8->setObjectName(QStringLiteral("frame_8"));
        frame_8->setGeometry(QRect(340, 340, 811, 211));
        sizePolicy.setHeightForWidth(frame_8->sizePolicy().hasHeightForWidth());
        frame_8->setSizePolicy(sizePolicy);
        frame_8->setFrameShape(QFrame::Box);
        frame_8->setFrameShadow(QFrame::Sunken);
        polling = new QPushButton(frame_8);
        polling->setObjectName(QStringLiteral("polling"));
        polling->setGeometry(QRect(150, 90, 93, 28));
        auto_polling = new QPushButton(frame_8);
        auto_polling->setObjectName(QStringLiteral("auto_polling"));
        auto_polling->setGeometry(QRect(290, 90, 93, 28));
        auto_polling_B = new QCheckBox(frame_8);
        auto_polling_B->setObjectName(QStringLiteral("auto_polling_B"));
        auto_polling_B->setGeometry(QRect(290, 140, 91, 19));
        label_38 = new QLabel(frame_8);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setGeometry(QRect(530, 40, 21, 101));
        sizePolicy.setHeightForWidth(label_38->sizePolicy().hasHeightForWidth());
        label_38->setSizePolicy(sizePolicy);
        allowEnterBtn_A = new QPushButton(frame_8);
        allowEnterBtn_A->setObjectName(QStringLiteral("allowEnterBtn_A"));
        allowEnterBtn_A->setGeometry(QRect(580, 40, 111, 31));
        sizePolicy.setHeightForWidth(allowEnterBtn_A->sizePolicy().hasHeightForWidth());
        allowEnterBtn_A->setSizePolicy(sizePolicy);
        allowEnterBtn_B = new QPushButton(frame_8);
        allowEnterBtn_B->setObjectName(QStringLiteral("allowEnterBtn_B"));
        allowEnterBtn_B->setGeometry(QRect(580, 110, 111, 31));
        sizePolicy.setHeightForWidth(allowEnterBtn_B->sizePolicy().hasHeightForWidth());
        allowEnterBtn_B->setSizePolicy(sizePolicy);
        label_2 = new QLabel(frame_8);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 10, 91, 17));
        reser_alarm = new QPushButton(frame_8);
        reser_alarm->setObjectName(QStringLiteral("reser_alarm"));
        reser_alarm->setGeometry(QRect(30, 90, 89, 25));
        line = new QFrame(frame_8);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(400, 0, 16, 211));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        frame_12 = new QFrame(centralWidget);
        frame_12->setObjectName(QStringLiteral("frame_12"));
        frame_12->setGeometry(QRect(620, 170, 251, 171));
        sizePolicy.setHeightForWidth(frame_12->sizePolicy().hasHeightForWidth());
        frame_12->setSizePolicy(sizePolicy);
        frame_12->setFrameShape(QFrame::Box);
        frame_12->setFrameShadow(QFrame::Sunken);
        setModeBtn = new QPushButton(frame_12);
        setModeBtn->setObjectName(QStringLiteral("setModeBtn"));
        setModeBtn->setGeometry(QRect(70, 39, 131, 31));
        sizePolicy.setHeightForWidth(setModeBtn->sizePolicy().hasHeightForWidth());
        setModeBtn->setSizePolicy(sizePolicy);
        label_23 = new QLabel(frame_12);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(20, 10, 61, 21));
        sizePolicy.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy);
        runModeCB = new QComboBox(frame_12);
        runModeCB->setObjectName(QStringLiteral("runModeCB"));
        runModeCB->setGeometry(QRect(30, 100, 201, 31));
        sizePolicy.setHeightForWidth(runModeCB->sizePolicy().hasHeightForWidth());
        runModeCB->setSizePolicy(sizePolicy);
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 550, 331, 111));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Plain);
        moduleTestBtn = new QPushButton(frame);
        moduleTestBtn->setObjectName(QStringLiteral("moduleTestBtn"));
        moduleTestBtn->setGeometry(QRect(20, 20, 98, 31));
        sizePolicy.setHeightForWidth(moduleTestBtn->sizePolicy().hasHeightForWidth());
        moduleTestBtn->setSizePolicy(sizePolicy);
        label_39 = new QLabel(frame);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setGeometry(QRect(10, 70, 66, 20));
        sizePolicy.setHeightForWidth(label_39->sizePolicy().hasHeightForWidth());
        label_39->setSizePolicy(sizePolicy);
        testContentCB = new QComboBox(frame);
        testContentCB->setObjectName(QStringLiteral("testContentCB"));
        testContentCB->setGeometry(QRect(80, 70, 231, 21));
        sizePolicy.setHeightForWidth(testContentCB->sizePolicy().hasHeightForWidth());
        testContentCB->setSizePolicy(sizePolicy);
        sensorStatusCheckBox = new QCheckBox(frame);
        sensorStatusCheckBox->setObjectName(QStringLiteral("sensorStatusCheckBox"));
        sensorStatusCheckBox->setGeometry(QRect(190, 20, 141, 19));
        frame_7 = new QFrame(centralWidget);
        frame_7->setObjectName(QStringLiteral("frame_7"));
        frame_7->setGeometry(QRect(340, 550, 811, 111));
        sizePolicy.setHeightForWidth(frame_7->sizePolicy().hasHeightForWidth());
        frame_7->setSizePolicy(sizePolicy);
        frame_7->setFrameShape(QFrame::Box);
        frame_7->setFrameShadow(QFrame::Sunken);
        checkBox_S5 = new QCheckBox(frame_7);
        checkBox_S5->setObjectName(QStringLiteral("checkBox_S5"));
        checkBox_S5->setGeometry(QRect(120, 70, 31, 20));
        sizePolicy.setHeightForWidth(checkBox_S5->sizePolicy().hasHeightForWidth());
        checkBox_S5->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(7);
        checkBox_S5->setFont(font1);
        checkBox_S5->setStyleSheet(QLatin1String("QCheckBox{  \n"
" spacing: 2px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 10px;\n"
"height: 10px;\n"
"};"));
        checkBox_S1 = new QCheckBox(frame_7);
        checkBox_S1->setObjectName(QStringLiteral("checkBox_S1"));
        checkBox_S1->setGeometry(QRect(10, 50, 31, 20));
        sizePolicy.setHeightForWidth(checkBox_S1->sizePolicy().hasHeightForWidth());
        checkBox_S1->setSizePolicy(sizePolicy);
        checkBox_S1->setFont(font1);
        checkBox_S1->setStyleSheet(QLatin1String("QCheckBox{  \n"
" spacing: 2px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 10px;\n"
"height: 10px;\n"
"};"));
        checkBox_S1->setIconSize(QSize(16, 16));
        checkBox_S3 = new QCheckBox(frame_7);
        checkBox_S3->setObjectName(QStringLiteral("checkBox_S3"));
        checkBox_S3->setGeometry(QRect(60, 50, 31, 20));
        sizePolicy.setHeightForWidth(checkBox_S3->sizePolicy().hasHeightForWidth());
        checkBox_S3->setSizePolicy(sizePolicy);
        checkBox_S3->setFont(font1);
        checkBox_S3->setStyleSheet(QLatin1String("QCheckBox{  \n"
" spacing: 2px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 10px;\n"
"height: 10px;\n"
"};"));
        checkBox_S6 = new QCheckBox(frame_7);
        checkBox_S6->setObjectName(QStringLiteral("checkBox_S6"));
        checkBox_S6->setGeometry(QRect(140, 10, 31, 20));
        sizePolicy.setHeightForWidth(checkBox_S6->sizePolicy().hasHeightForWidth());
        checkBox_S6->setSizePolicy(sizePolicy);
        checkBox_S6->setFont(font1);
        checkBox_S6->setStyleSheet(QLatin1String("QCheckBox{  \n"
" spacing: 2px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 10px;\n"
"height: 10px;\n"
"};"));
        checkBox_S4 = new QCheckBox(frame_7);
        checkBox_S4->setObjectName(QStringLiteral("checkBox_S4"));
        checkBox_S4->setGeometry(QRect(100, 20, 31, 20));
        sizePolicy.setHeightForWidth(checkBox_S4->sizePolicy().hasHeightForWidth());
        checkBox_S4->setSizePolicy(sizePolicy);
        checkBox_S4->setFont(font1);
        checkBox_S4->setStyleSheet(QLatin1String("QCheckBox{  \n"
" spacing: 2px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 10px;\n"
"height: 10px;\n"
"};"));
        checkBox_S2 = new QCheckBox(frame_7);
        checkBox_S2->setObjectName(QStringLiteral("checkBox_S2"));
        checkBox_S2->setGeometry(QRect(35, 50, 31, 20));
        sizePolicy.setHeightForWidth(checkBox_S2->sizePolicy().hasHeightForWidth());
        checkBox_S2->setSizePolicy(sizePolicy);
        checkBox_S2->setFont(font1);
        checkBox_S2->setStyleSheet(QLatin1String("QCheckBox{  \n"
" spacing: 2px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 10px;\n"
"height: 10px;\n"
"};"));
        checkBox_S2->setIconSize(QSize(16, 16));
        checkBox_S15 = new QCheckBox(frame_7);
        checkBox_S15->setObjectName(QStringLiteral("checkBox_S15"));
        checkBox_S15->setGeometry(QRect(340, 50, 31, 20));
        checkBox_S15->setFont(font1);
        checkBox_S15->setStyleSheet(QLatin1String("QCheckBox{  \n"
" spacing: 2px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 10px;\n"
"height: 10px;\n"
"};"));
        checkBox_S13 = new QCheckBox(frame_7);
        checkBox_S13->setObjectName(QStringLiteral("checkBox_S13"));
        checkBox_S13->setGeometry(QRect(290, 20, 31, 20));
        checkBox_S13->setFont(font1);
        checkBox_S13->setStyleSheet(QLatin1String("QCheckBox{  \n"
" spacing: 2px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 10px;\n"
"height: 10px;\n"
"};"));
        checkBox_S16 = new QCheckBox(frame_7);
        checkBox_S16->setObjectName(QStringLiteral("checkBox_S16"));
        checkBox_S16->setGeometry(QRect(370, 50, 31, 20));
        checkBox_S16->setFont(font1);
        checkBox_S16->setStyleSheet(QLatin1String("QCheckBox{  \n"
" spacing: 2px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 10px;\n"
"height: 10px;\n"
"};"));
        checkBox_S14 = new QCheckBox(frame_7);
        checkBox_S14->setObjectName(QStringLiteral("checkBox_S14"));
        checkBox_S14->setGeometry(QRect(310, 50, 31, 20));
        checkBox_S14->setFont(font1);
        checkBox_S14->setStyleSheet(QLatin1String("QCheckBox{  \n"
" spacing: 2px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 10px;\n"
"height: 10px;\n"
"};"));
        label_68 = new QLabel(frame_7);
        label_68->setObjectName(QStringLiteral("label_68"));
        label_68->setGeometry(QRect(210, 110, 111, 20));
        sizePolicy.setHeightForWidth(label_68->sizePolicy().hasHeightForWidth());
        label_68->setSizePolicy(sizePolicy);
        checkBox_S12 = new QCheckBox(frame_7);
        checkBox_S12->setObjectName(QStringLiteral("checkBox_S12"));
        checkBox_S12->setGeometry(QRect(260, 70, 31, 20));
        checkBox_S12->setFont(font1);
        checkBox_S12->setStyleSheet(QLatin1String("QCheckBox{  \n"
" spacing: 2px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 10px;\n"
"height: 10px;\n"
"};"));
        checkBox_S8 = new QCheckBox(frame_7);
        checkBox_S8->setObjectName(QStringLiteral("checkBox_S8"));
        checkBox_S8->setGeometry(QRect(170, 60, 31, 20));
        sizePolicy.setHeightForWidth(checkBox_S8->sizePolicy().hasHeightForWidth());
        checkBox_S8->setSizePolicy(sizePolicy);
        checkBox_S8->setFont(font1);
        checkBox_S8->setStyleSheet(QLatin1String("QCheckBox{  \n"
" spacing: 2px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 10px;\n"
"height: 10px;\n"
"};"));
        checkBox_S10 = new QCheckBox(frame_7);
        checkBox_S10->setObjectName(QStringLiteral("checkBox_S10"));
        checkBox_S10->setGeometry(QRect(210, 20, 31, 20));
        sizePolicy.setHeightForWidth(checkBox_S10->sizePolicy().hasHeightForWidth());
        checkBox_S10->setSizePolicy(sizePolicy);
        checkBox_S10->setFont(font1);
        checkBox_S10->setStyleSheet(QLatin1String("QCheckBox{  \n"
" spacing: 2px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 10px;\n"
"height: 10px;\n"
"};"));
        checkBox_S9 = new QCheckBox(frame_7);
        checkBox_S9->setObjectName(QStringLiteral("checkBox_S9"));
        checkBox_S9->setGeometry(QRect(210, 60, 31, 20));
        sizePolicy.setHeightForWidth(checkBox_S9->sizePolicy().hasHeightForWidth());
        checkBox_S9->setSizePolicy(sizePolicy);
        checkBox_S9->setFont(font1);
        checkBox_S9->setStyleSheet(QLatin1String("QCheckBox{  \n"
" spacing: 2px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 10px;\n"
"height: 10px;\n"
"};"));
        checkBox_S7 = new QCheckBox(frame_7);
        checkBox_S7->setObjectName(QStringLiteral("checkBox_S7"));
        checkBox_S7->setGeometry(QRect(170, 20, 31, 20));
        sizePolicy.setHeightForWidth(checkBox_S7->sizePolicy().hasHeightForWidth());
        checkBox_S7->setSizePolicy(sizePolicy);
        checkBox_S7->setFont(font1);
        checkBox_S7->setStyleSheet(QLatin1String("QCheckBox{  \n"
" spacing: 2px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 10px;\n"
"height: 10px;\n"
"};"));
        checkBox_S11 = new QCheckBox(frame_7);
        checkBox_S11->setObjectName(QStringLiteral("checkBox_S11"));
        checkBox_S11->setGeometry(QRect(250, 10, 31, 20));
        sizePolicy.setHeightForWidth(checkBox_S11->sizePolicy().hasHeightForWidth());
        checkBox_S11->setSizePolicy(sizePolicy);
        checkBox_S11->setFont(font1);
        checkBox_S11->setStyleSheet(QLatin1String("QCheckBox{  \n"
" spacing: 2px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 10px;\n"
"height: 10px;\n"
"};"));
        label_41 = new QLabel(frame_7);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setGeometry(QRect(10, 10, 81, 20));
        sizePolicy.setHeightForWidth(label_41->sizePolicy().hasHeightForWidth());
        label_41->setSizePolicy(sizePolicy);
        line_2 = new QFrame(frame_7);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(400, 0, 20, 111));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        checkBox_S1_2 = new QCheckBox(frame_7);
        checkBox_S1_2->setObjectName(QStringLiteral("checkBox_S1_2"));
        checkBox_S1_2->setGeometry(QRect(420, 50, 31, 20));
        sizePolicy.setHeightForWidth(checkBox_S1_2->sizePolicy().hasHeightForWidth());
        checkBox_S1_2->setSizePolicy(sizePolicy);
        checkBox_S1_2->setFont(font1);
        checkBox_S1_2->setStyleSheet(QLatin1String("QCheckBox{  \n"
" spacing: 2px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 10px;\n"
"height: 10px;\n"
"};"));
        checkBox_S1_2->setIconSize(QSize(16, 16));
        checkBox_S2_2 = new QCheckBox(frame_7);
        checkBox_S2_2->setObjectName(QStringLiteral("checkBox_S2_2"));
        checkBox_S2_2->setGeometry(QRect(450, 50, 31, 20));
        sizePolicy.setHeightForWidth(checkBox_S2_2->sizePolicy().hasHeightForWidth());
        checkBox_S2_2->setSizePolicy(sizePolicy);
        checkBox_S2_2->setFont(font1);
        checkBox_S2_2->setStyleSheet(QLatin1String("QCheckBox{  \n"
" spacing: 2px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 10px;\n"
"height: 10px;\n"
"};"));
        checkBox_S2_2->setIconSize(QSize(16, 16));
        checkBox_S3_2 = new QCheckBox(frame_7);
        checkBox_S3_2->setObjectName(QStringLiteral("checkBox_S3_2"));
        checkBox_S3_2->setGeometry(QRect(480, 50, 31, 20));
        sizePolicy.setHeightForWidth(checkBox_S3_2->sizePolicy().hasHeightForWidth());
        checkBox_S3_2->setSizePolicy(sizePolicy);
        checkBox_S3_2->setFont(font1);
        checkBox_S3_2->setStyleSheet(QLatin1String("QCheckBox{  \n"
" spacing: 2px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 10px;\n"
"height: 10px;\n"
"};"));
        checkBox_S4_2 = new QCheckBox(frame_7);
        checkBox_S4_2->setObjectName(QStringLiteral("checkBox_S4_2"));
        checkBox_S4_2->setGeometry(QRect(510, 20, 31, 20));
        sizePolicy.setHeightForWidth(checkBox_S4_2->sizePolicy().hasHeightForWidth());
        checkBox_S4_2->setSizePolicy(sizePolicy);
        checkBox_S4_2->setFont(font1);
        checkBox_S4_2->setStyleSheet(QLatin1String("QCheckBox{  \n"
" spacing: 2px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 10px;\n"
"height: 10px;\n"
"};"));
        checkBox_S5_2 = new QCheckBox(frame_7);
        checkBox_S5_2->setObjectName(QStringLiteral("checkBox_S5_2"));
        checkBox_S5_2->setGeometry(QRect(530, 80, 31, 20));
        sizePolicy.setHeightForWidth(checkBox_S5_2->sizePolicy().hasHeightForWidth());
        checkBox_S5_2->setSizePolicy(sizePolicy);
        checkBox_S5_2->setFont(font1);
        checkBox_S5_2->setStyleSheet(QLatin1String("QCheckBox{  \n"
" spacing: 2px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 10px;\n"
"height: 10px;\n"
"};"));
        checkBox_S6_2 = new QCheckBox(frame_7);
        checkBox_S6_2->setObjectName(QStringLiteral("checkBox_S6_2"));
        checkBox_S6_2->setGeometry(QRect(550, 10, 31, 20));
        sizePolicy.setHeightForWidth(checkBox_S6_2->sizePolicy().hasHeightForWidth());
        checkBox_S6_2->setSizePolicy(sizePolicy);
        checkBox_S6_2->setFont(font1);
        checkBox_S6_2->setStyleSheet(QLatin1String("QCheckBox{  \n"
" spacing: 2px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 10px;\n"
"height: 10px;\n"
"};"));
        checkBox_S7_2 = new QCheckBox(frame_7);
        checkBox_S7_2->setObjectName(QStringLiteral("checkBox_S7_2"));
        checkBox_S7_2->setGeometry(QRect(570, 30, 31, 20));
        sizePolicy.setHeightForWidth(checkBox_S7_2->sizePolicy().hasHeightForWidth());
        checkBox_S7_2->setSizePolicy(sizePolicy);
        checkBox_S7_2->setFont(font1);
        checkBox_S7_2->setStyleSheet(QLatin1String("QCheckBox{  \n"
" spacing: 2px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 10px;\n"
"height: 10px;\n"
"};"));
        checkBox_S8_2 = new QCheckBox(frame_7);
        checkBox_S8_2->setObjectName(QStringLiteral("checkBox_S8_2"));
        checkBox_S8_2->setGeometry(QRect(570, 70, 31, 20));
        sizePolicy.setHeightForWidth(checkBox_S8_2->sizePolicy().hasHeightForWidth());
        checkBox_S8_2->setSizePolicy(sizePolicy);
        checkBox_S8_2->setFont(font1);
        checkBox_S8_2->setStyleSheet(QLatin1String("QCheckBox{  \n"
" spacing: 2px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 10px;\n"
"height: 10px;\n"
"};"));
        checkBox_S10_2 = new QCheckBox(frame_7);
        checkBox_S10_2->setObjectName(QStringLiteral("checkBox_S10_2"));
        checkBox_S10_2->setGeometry(QRect(610, 30, 31, 20));
        sizePolicy.setHeightForWidth(checkBox_S10_2->sizePolicy().hasHeightForWidth());
        checkBox_S10_2->setSizePolicy(sizePolicy);
        checkBox_S10_2->setFont(font1);
        checkBox_S10_2->setStyleSheet(QLatin1String("QCheckBox{  \n"
" spacing: 2px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 10px;\n"
"height: 10px;\n"
"};"));
        checkBox_S9_2 = new QCheckBox(frame_7);
        checkBox_S9_2->setObjectName(QStringLiteral("checkBox_S9_2"));
        checkBox_S9_2->setGeometry(QRect(610, 70, 31, 20));
        sizePolicy.setHeightForWidth(checkBox_S9_2->sizePolicy().hasHeightForWidth());
        checkBox_S9_2->setSizePolicy(sizePolicy);
        checkBox_S9_2->setFont(font1);
        checkBox_S9_2->setStyleSheet(QLatin1String("QCheckBox{  \n"
" spacing: 2px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 10px;\n"
"height: 10px;\n"
"};"));
        checkBox_S11_2 = new QCheckBox(frame_7);
        checkBox_S11_2->setObjectName(QStringLiteral("checkBox_S11_2"));
        checkBox_S11_2->setGeometry(QRect(650, 10, 31, 20));
        sizePolicy.setHeightForWidth(checkBox_S11_2->sizePolicy().hasHeightForWidth());
        checkBox_S11_2->setSizePolicy(sizePolicy);
        checkBox_S11_2->setFont(font1);
        checkBox_S11_2->setStyleSheet(QLatin1String("QCheckBox{  \n"
" spacing: 2px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 10px;\n"
"height: 10px;\n"
"};"));
        checkBox_S13_2 = new QCheckBox(frame_7);
        checkBox_S13_2->setObjectName(QStringLiteral("checkBox_S13_2"));
        checkBox_S13_2->setGeometry(QRect(690, 30, 31, 20));
        checkBox_S13_2->setFont(font1);
        checkBox_S13_2->setStyleSheet(QLatin1String("QCheckBox{  \n"
" spacing: 2px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 10px;\n"
"height: 10px;\n"
"};"));
        checkBox_S12_2 = new QCheckBox(frame_7);
        checkBox_S12_2->setObjectName(QStringLiteral("checkBox_S12_2"));
        checkBox_S12_2->setGeometry(QRect(660, 80, 31, 20));
        checkBox_S12_2->setFont(font1);
        checkBox_S12_2->setStyleSheet(QLatin1String("QCheckBox{  \n"
" spacing: 2px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 10px;\n"
"height: 10px;\n"
"};"));
        checkBox_S14_2 = new QCheckBox(frame_7);
        checkBox_S14_2->setObjectName(QStringLiteral("checkBox_S14_2"));
        checkBox_S14_2->setGeometry(QRect(710, 50, 31, 20));
        checkBox_S14_2->setFont(font1);
        checkBox_S14_2->setStyleSheet(QLatin1String("QCheckBox{  \n"
" spacing: 2px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 10px;\n"
"height: 10px;\n"
"};"));
        checkBox_S15_2 = new QCheckBox(frame_7);
        checkBox_S15_2->setObjectName(QStringLiteral("checkBox_S15_2"));
        checkBox_S15_2->setGeometry(QRect(750, 50, 31, 20));
        checkBox_S15_2->setFont(font1);
        checkBox_S15_2->setStyleSheet(QLatin1String("QCheckBox{  \n"
" spacing: 2px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 10px;\n"
"height: 10px;\n"
"};"));
        checkBox_S16_2 = new QCheckBox(frame_7);
        checkBox_S16_2->setObjectName(QStringLiteral("checkBox_S16_2"));
        checkBox_S16_2->setGeometry(QRect(780, 50, 31, 20));
        checkBox_S16_2->setFont(font1);
        checkBox_S16_2->setStyleSheet(QLatin1String("QCheckBox{  \n"
" spacing: 2px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 10px;\n"
"height: 10px;\n"
"};"));
        label_42 = new QLabel(frame_7);
        label_42->setObjectName(QStringLiteral("label_42"));
        label_42->setGeometry(QRect(420, 10, 81, 20));
        sizePolicy.setHeightForWidth(label_42->sizePolicy().hasHeightForWidth());
        label_42->setSizePolicy(sizePolicy);
        frame_6 = new QFrame(centralWidget);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setGeometry(QRect(10, 170, 331, 381));
        sizePolicy.setHeightForWidth(frame_6->sizePolicy().hasHeightForWidth());
        frame_6->setSizePolicy(sizePolicy);
        frame_6->setFrameShape(QFrame::Box);
        frame_6->setFrameShadow(QFrame::Sunken);
        checkParamStatusBtn = new QPushButton(frame_6);
        checkParamStatusBtn->setObjectName(QStringLiteral("checkParamStatusBtn"));
        checkParamStatusBtn->setGeometry(QRect(180, 10, 91, 21));
        sizePolicy.setHeightForWidth(checkParamStatusBtn->sizePolicy().hasHeightForWidth());
        checkParamStatusBtn->setSizePolicy(sizePolicy);
        setParamsBtn = new QPushButton(frame_6);
        setParamsBtn->setObjectName(QStringLiteral("setParamsBtn"));
        setParamsBtn->setGeometry(QRect(10, 10, 81, 21));
        sizePolicy.setHeightForWidth(setParamsBtn->sizePolicy().hasHeightForWidth());
        setParamsBtn->setSizePolicy(sizePolicy);
        param11LE = new QLineEdit(frame_6);
        param11LE->setObjectName(QStringLiteral("param11LE"));
        param11LE->setGeometry(QRect(180, 320, 111, 20));
        sizePolicy.setHeightForWidth(param11LE->sizePolicy().hasHeightForWidth());
        param11LE->setSizePolicy(sizePolicy);
        param4LE = new QLineEdit(frame_6);
        param4LE->setObjectName(QStringLiteral("param4LE"));
        param4LE->setGeometry(QRect(180, 130, 81, 20));
        sizePolicy.setHeightForWidth(param4LE->sizePolicy().hasHeightForWidth());
        param4LE->setSizePolicy(sizePolicy);
        label_25 = new QLabel(frame_6);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(10, 40, 151, 20));
        sizePolicy.setHeightForWidth(label_25->sizePolicy().hasHeightForWidth());
        label_25->setSizePolicy(sizePolicy);
        param3LE = new QLineEdit(frame_6);
        param3LE->setObjectName(QStringLiteral("param3LE"));
        param3LE->setGeometry(QRect(180, 100, 81, 20));
        sizePolicy.setHeightForWidth(param3LE->sizePolicy().hasHeightForWidth());
        param3LE->setSizePolicy(sizePolicy);
        label_30 = new QLabel(frame_6);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(10, 160, 111, 20));
        sizePolicy.setHeightForWidth(label_30->sizePolicy().hasHeightForWidth());
        label_30->setSizePolicy(sizePolicy);
        param7LE = new QLineEdit(frame_6);
        param7LE->setObjectName(QStringLiteral("param7LE"));
        param7LE->setGeometry(QRect(180, 240, 111, 20));
        sizePolicy.setHeightForWidth(param7LE->sizePolicy().hasHeightForWidth());
        param7LE->setSizePolicy(sizePolicy);
        label_35 = new QLabel(frame_6);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(10, 320, 151, 20));
        sizePolicy.setHeightForWidth(label_35->sizePolicy().hasHeightForWidth());
        label_35->setSizePolicy(sizePolicy);
        label_27 = new QLabel(frame_6);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(10, 120, 151, 30));
        sizePolicy.setHeightForWidth(label_27->sizePolicy().hasHeightForWidth());
        label_27->setSizePolicy(sizePolicy);
        label_29 = new QLabel(frame_6);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(10, 190, 141, 41));
        sizePolicy.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy);
        param1LE = new QLineEdit(frame_6);
        param1LE->setObjectName(QStringLiteral("param1LE"));
        param1LE->setGeometry(QRect(180, 40, 81, 20));
        sizePolicy.setHeightForWidth(param1LE->sizePolicy().hasHeightForWidth());
        param1LE->setSizePolicy(sizePolicy);
        param2LE = new QLineEdit(frame_6);
        param2LE->setObjectName(QStringLiteral("param2LE"));
        param2LE->setGeometry(QRect(180, 70, 81, 20));
        sizePolicy.setHeightForWidth(param2LE->sizePolicy().hasHeightForWidth());
        param2LE->setSizePolicy(sizePolicy);
        param6LE = new QLineEdit(frame_6);
        param6LE->setObjectName(QStringLiteral("param6LE"));
        param6LE->setGeometry(QRect(180, 190, 81, 20));
        sizePolicy.setHeightForWidth(param6LE->sizePolicy().hasHeightForWidth());
        param6LE->setSizePolicy(sizePolicy);
        label_28 = new QLabel(frame_6);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(10, 100, 151, 20));
        sizePolicy.setHeightForWidth(label_28->sizePolicy().hasHeightForWidth());
        label_28->setSizePolicy(sizePolicy);
        label_31 = new QLabel(frame_6);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(10, 240, 101, 20));
        sizePolicy.setHeightForWidth(label_31->sizePolicy().hasHeightForWidth());
        label_31->setSizePolicy(sizePolicy);
        param5LE = new QLineEdit(frame_6);
        param5LE->setObjectName(QStringLiteral("param5LE"));
        param5LE->setGeometry(QRect(180, 160, 81, 20));
        sizePolicy.setHeightForWidth(param5LE->sizePolicy().hasHeightForWidth());
        param5LE->setSizePolicy(sizePolicy);
        label_26 = new QLabel(frame_6);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(10, 60, 141, 30));
        sizePolicy.setHeightForWidth(label_26->sizePolicy().hasHeightForWidth());
        label_26->setSizePolicy(sizePolicy);
        label_34 = new QLabel(frame_6);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(10, 280, 101, 20));
        sizePolicy.setHeightForWidth(label_34->sizePolicy().hasHeightForWidth());
        label_34->setSizePolicy(sizePolicy);
        label_40 = new QLabel(frame_6);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setGeometry(QRect(10, 350, 151, 20));
        sizePolicy.setHeightForWidth(label_40->sizePolicy().hasHeightForWidth());
        label_40->setSizePolicy(sizePolicy);
        param11LE_2 = new QLineEdit(frame_6);
        param11LE_2->setObjectName(QStringLiteral("param11LE_2"));
        param11LE_2->setGeometry(QRect(180, 350, 111, 20));
        sizePolicy.setHeightForWidth(param11LE_2->sizePolicy().hasHeightForWidth());
        param11LE_2->setSizePolicy(sizePolicy);
        param7LE_2 = new QLineEdit(frame_6);
        param7LE_2->setObjectName(QStringLiteral("param7LE_2"));
        param7LE_2->setGeometry(QRect(180, 280, 111, 20));
        sizePolicy.setHeightForWidth(param7LE_2->sizePolicy().hasHeightForWidth());
        param7LE_2->setSizePolicy(sizePolicy);
        frame_11 = new QFrame(centralWidget);
        frame_11->setObjectName(QStringLiteral("frame_11"));
        frame_11->setGeometry(QRect(870, 170, 281, 171));
        sizePolicy.setHeightForWidth(frame_11->sizePolicy().hasHeightForWidth());
        frame_11->setSizePolicy(sizePolicy);
        frame_11->setFrameShape(QFrame::Box);
        frame_11->setFrameShadow(QFrame::Sunken);
        AD_M = new QCheckBox(frame_11);
        AD_M->setObjectName(QStringLiteral("AD_M"));
        AD_M->setGeometry(QRect(10, 50, 91, 19));
        AD_M->setChecked(true);
        AD_R = new QCheckBox(frame_11);
        AD_R->setObjectName(QStringLiteral("AD_R"));
        AD_R->setGeometry(QRect(60, 50, 91, 19));
        AD_G = new QCheckBox(frame_11);
        AD_G->setObjectName(QStringLiteral("AD_G"));
        AD_G->setGeometry(QRect(100, 50, 91, 19));
        BD_M = new QCheckBox(frame_11);
        BD_M->setObjectName(QStringLiteral("BD_M"));
        BD_M->setGeometry(QRect(10, 100, 91, 19));
        BD_M->setChecked(true);
        BD_R = new QCheckBox(frame_11);
        BD_R->setObjectName(QStringLiteral("BD_R"));
        BD_R->setGeometry(QRect(60, 100, 91, 19));
        BD_G = new QCheckBox(frame_11);
        BD_G->setObjectName(QStringLiteral("BD_G"));
        BD_G->setGeometry(QRect(100, 100, 91, 19));
        label_24 = new QLabel(frame_11);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(30, 10, 151, 21));
        sizePolicy.setHeightForWidth(label_24->sizePolicy().hasHeightForWidth());
        label_24->setSizePolicy(sizePolicy);
        AD_switch = new QPushButton(frame_11);
        AD_switch->setObjectName(QStringLiteral("AD_switch"));
        AD_switch->setGeometry(QRect(160, 40, 93, 28));
        BD_switch = new QPushButton(frame_11);
        BD_switch->setObjectName(QStringLiteral("BD_switch"));
        BD_switch->setGeometry(QRect(160, 100, 93, 28));
        getstatus = new QPushButton(centralWidget);
        getstatus->setObjectName(QStringLiteral("getstatus"));
        getstatus->setGeometry(QRect(360, 190, 89, 25));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(370, 260, 67, 21));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(440, 260, 171, 25));
        pcm_check = new QCheckBox(centralWidget);
        pcm_check->setObjectName(QStringLiteral("pcm_check"));
        pcm_check->setGeometry(QRect(480, 230, 92, 23));
        pcm_polling = new QPushButton(centralWidget);
        pcm_polling->setObjectName(QStringLiteral("pcm_polling"));
        pcm_polling->setGeometry(QRect(480, 190, 111, 25));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(370, 300, 101, 17));
        baojing = new QLineEdit(centralWidget);
        baojing->setObjectName(QStringLiteral("baojing"));
        baojing->setGeometry(QRect(470, 300, 113, 25));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        closeSerialPortBtn->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\344\270\262\345\217\243", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\357\274\232", Q_NULLPTR));
        openSerialPortBtn->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        checkSwVerBtn->setText(QApplication::translate("MainWindow", "\350\275\257\344\273\266\347\211\210\346\234\254\346\237\245\350\257\242", Q_NULLPTR));
        label_66->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\347\261\273\345\236\213", Q_NULLPTR));
        label_67->setText(QApplication::translate("MainWindow", "\350\275\257\344\273\266\345\272\217\345\210\227\345\217\267", Q_NULLPTR));
        type->setText(QString());
        swSerialNumLabel->setText(QString());
        label_37->setText(QApplication::translate("MainWindow", "\345\217\221\n"
"\351\200\201\n"
"\345\214\272\n"
"\345\237\237", Q_NULLPTR));
        label_36->setText(QApplication::translate("MainWindow", "\346\216\245\n"
"\346\224\266\n"
"\345\214\272\n"
"\345\237\237", Q_NULLPTR));
        outputClearBtn->setText(QApplication::translate("MainWindow", "\346\270\205\n"
"\351\231\244\n"
"\346\230\276\n"
"\347\244\272", Q_NULLPTR));
        inputClearBtn->setText(QApplication::translate("MainWindow", "\346\270\205\n"
"\351\231\244\n"
"\346\230\276\n"
"\347\244\272", Q_NULLPTR));
        polling->setText(QApplication::translate("MainWindow", "\350\275\256\350\257\242", Q_NULLPTR));
        auto_polling->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\350\275\256\350\257\242", Q_NULLPTR));
        auto_polling_B->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\350\275\256\350\257\242", Q_NULLPTR));
        label_38->setText(QApplication::translate("MainWindow", "\351\200\232\n"
"\350\241\214\n"
"\346\216\210\n"
"\346\235\203", Q_NULLPTR));
        allowEnterBtn_A->setText(QApplication::translate("MainWindow", "A\345\220\221\350\277\233\345\205\245", Q_NULLPTR));
        allowEnterBtn_B->setText(QApplication::translate("MainWindow", "B\345\220\221\350\277\233\345\205\245", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226\346\223\215\344\275\234 ", Q_NULLPTR));
        reser_alarm->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\346\212\245\350\255\246", Q_NULLPTR));
        setModeBtn->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\346\250\241\345\274\217", Q_NULLPTR));
        label_23->setText(QApplication::translate("MainWindow", "\350\277\220\350\241\214\346\250\241\345\274\217\357\274\232", Q_NULLPTR));
        runModeCB->clear();
        runModeCB->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\232\202\345\201\234\346\234\215\345\212\241\346\250\241\345\274\217", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\217\214\351\227\250\345\217\214\345\220\221\345\217\227\346\216\247\346\250\241\345\274\217", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\273\264\346\212\244\346\250\241\345\274\217", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\350\275\257\344\273\266\347\264\247\346\200\245\346\250\241\345\274\217", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\217\227\346\216\247\350\277\233\347\253\231\346\250\241\345\274\217", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\217\227\346\216\247\345\207\272\347\253\231\346\250\241\345\274\217", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\217\227\346\216\247\350\277\233\347\253\231 / \345\205\215\350\264\271\345\207\272\347\253\231\346\250\241\345\274\217", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\205\215\350\264\271\350\277\233\347\253\231 / \345\217\227\346\216\247\345\207\272\347\253\231\346\250\241\345\274\217", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\205\215\350\264\271\350\277\233\347\253\231\346\250\241\345\274\217", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\205\215\350\264\271\345\207\272\347\253\231\346\250\241\345\274\217", Q_NULLPTR)
         << QApplication::translate("MainWindow", " \345\217\214\345\220\221\345\205\215\350\264\271\346\250\241\345\274\217", Q_NULLPTR)
        );
        moduleTestBtn->setText(QApplication::translate("MainWindow", "\346\250\241\345\235\227\346\265\213\350\257\225", Q_NULLPTR));
        label_39->setText(QApplication::translate("MainWindow", "\346\265\213\350\257\225\345\206\205\345\256\271\357\274\232", Q_NULLPTR));
        testContentCB->clear();
        testContentCB->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\344\274\240\346\204\237\345\231\250\346\265\213\350\257\225\345\221\275\344\273\244", Q_NULLPTR)
        );
        sensorStatusCheckBox->setText(QApplication::translate("MainWindow", "\344\274\240\346\204\237\345\231\250\345\256\232\346\227\266\346\237\245\350\257\242", Q_NULLPTR));
        checkBox_S5->setText(QApplication::translate("MainWindow", "S5", Q_NULLPTR));
        checkBox_S1->setText(QApplication::translate("MainWindow", "S1", Q_NULLPTR));
        checkBox_S3->setText(QApplication::translate("MainWindow", "S3", Q_NULLPTR));
        checkBox_S6->setText(QApplication::translate("MainWindow", "S6", Q_NULLPTR));
        checkBox_S4->setText(QApplication::translate("MainWindow", "S4", Q_NULLPTR));
        checkBox_S2->setText(QApplication::translate("MainWindow", "S2", Q_NULLPTR));
        checkBox_S15->setText(QApplication::translate("MainWindow", "S15", Q_NULLPTR));
        checkBox_S13->setText(QApplication::translate("MainWindow", "S13", Q_NULLPTR));
        checkBox_S16->setText(QApplication::translate("MainWindow", "S16", Q_NULLPTR));
        checkBox_S14->setText(QApplication::translate("MainWindow", "S14", Q_NULLPTR));
        label_68->setText(QApplication::translate("MainWindow", "\351\200\232\350\241\214\344\274\240\346\204\237\345\231\250\347\212\266\346\200\201", Q_NULLPTR));
        checkBox_S12->setText(QApplication::translate("MainWindow", "S12", Q_NULLPTR));
        checkBox_S8->setText(QApplication::translate("MainWindow", "S8", Q_NULLPTR));
        checkBox_S10->setText(QApplication::translate("MainWindow", "S10", Q_NULLPTR));
        checkBox_S9->setText(QApplication::translate("MainWindow", "S9", Q_NULLPTR));
        checkBox_S7->setText(QApplication::translate("MainWindow", "S7", Q_NULLPTR));
        checkBox_S11->setText(QApplication::translate("MainWindow", "S11", Q_NULLPTR));
        label_41->setText(QApplication::translate("MainWindow", "\344\274\240\346\204\237\345\231\250\347\212\266\346\200\201", Q_NULLPTR));
        checkBox_S1_2->setText(QApplication::translate("MainWindow", "S1", Q_NULLPTR));
        checkBox_S2_2->setText(QApplication::translate("MainWindow", "S2", Q_NULLPTR));
        checkBox_S3_2->setText(QApplication::translate("MainWindow", "S3", Q_NULLPTR));
        checkBox_S4_2->setText(QApplication::translate("MainWindow", "S4", Q_NULLPTR));
        checkBox_S5_2->setText(QApplication::translate("MainWindow", "S5", Q_NULLPTR));
        checkBox_S6_2->setText(QApplication::translate("MainWindow", "S6", Q_NULLPTR));
        checkBox_S7_2->setText(QApplication::translate("MainWindow", "S7", Q_NULLPTR));
        checkBox_S8_2->setText(QApplication::translate("MainWindow", "S8", Q_NULLPTR));
        checkBox_S10_2->setText(QApplication::translate("MainWindow", "S10", Q_NULLPTR));
        checkBox_S9_2->setText(QApplication::translate("MainWindow", "S9", Q_NULLPTR));
        checkBox_S11_2->setText(QApplication::translate("MainWindow", "S11", Q_NULLPTR));
        checkBox_S13_2->setText(QApplication::translate("MainWindow", "S13", Q_NULLPTR));
        checkBox_S12_2->setText(QApplication::translate("MainWindow", "S12", Q_NULLPTR));
        checkBox_S14_2->setText(QApplication::translate("MainWindow", "S14", Q_NULLPTR));
        checkBox_S15_2->setText(QApplication::translate("MainWindow", "S15", Q_NULLPTR));
        checkBox_S16_2->setText(QApplication::translate("MainWindow", "S16", Q_NULLPTR));
        label_42->setText(QApplication::translate("MainWindow", "\346\212\245\350\255\246\347\212\266\346\200\201", Q_NULLPTR));
        checkParamStatusBtn->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260\346\237\245\350\257\242", Q_NULLPTR));
        setParamsBtn->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260\350\256\276\347\275\256", Q_NULLPTR));
        param11LE->setText(QString());
        label_25->setText(QApplication::translate("MainWindow", "\346\211\207\351\227\250\345\205\263\351\227\255\350\266\205\346\227\266:", Q_NULLPTR));
        label_30->setText(QApplication::translate("MainWindow", "\347\246\273\345\274\200\351\200\232\351\201\223\350\266\205\346\227\266:", Q_NULLPTR));
        param7LE->setText(QString());
        label_35->setText(QApplication::translate("MainWindow", "\351\251\254\350\276\276\345\201\234\346\255\242\346\232\202\345\201\234\350\266\205\346\227\266:", Q_NULLPTR));
        label_27->setText(QApplication::translate("MainWindow", "\350\234\202\351\270\243\345\231\250\345\273\266\346\227\266\350\266\205\346\227\266:", Q_NULLPTR));
        label_29->setText(QApplication::translate("MainWindow", "\344\274\240\346\204\237\345\231\250\350\207\252\346\243\200\350\266\205\346\227\266:", Q_NULLPTR));
        param1LE->setText(QString());
        label_28->setText(QApplication::translate("MainWindow", "\350\234\202\351\270\243\345\231\250\346\211\223\345\274\200\350\266\205\346\227\266:", Q_NULLPTR));
        label_31->setText(QApplication::translate("MainWindow", "\350\275\256\350\257\242\346\243\200\346\265\213\350\266\205\346\227\266:", Q_NULLPTR));
        param5LE->setText(QString());
        label_26->setText(QApplication::translate("MainWindow", "\351\200\232\350\241\214\346\216\210\346\235\203\350\266\205\346\227\266:", Q_NULLPTR));
        label_34->setText(QApplication::translate("MainWindow", "\346\234\254\345\234\260\350\277\220\350\241\214\346\250\241\345\274\217:", Q_NULLPTR));
        label_40->setText(QApplication::translate("MainWindow", "\351\251\254\350\276\276\346\211\223\345\274\200\346\232\202\345\201\234\350\266\205\346\227\266:", Q_NULLPTR));
        param11LE_2->setText(QString());
        param7LE_2->setText(QString());
        AD_M->setText(QApplication::translate("MainWindow", "\351\273\230\350\256\244", Q_NULLPTR));
        AD_R->setText(QApplication::translate("MainWindow", "\347\272\242", Q_NULLPTR));
        AD_G->setText(QApplication::translate("MainWindow", "\347\273\277", Q_NULLPTR));
        BD_M->setText(QApplication::translate("MainWindow", "\351\273\230\350\256\244", Q_NULLPTR));
        BD_R->setText(QApplication::translate("MainWindow", "\347\272\242", Q_NULLPTR));
        BD_G->setText(QApplication::translate("MainWindow", "\347\273\277", Q_NULLPTR));
        label_24->setText(QApplication::translate("MainWindow", "\351\200\232\350\241\214\346\214\207\347\244\272\347\201\257\350\256\276\347\275\256", Q_NULLPTR));
        AD_switch->setText(QApplication::translate("MainWindow", "A\346\226\271\345\220\221\346\214\207\347\244\272\347\201\257", Q_NULLPTR));
        BD_switch->setText(QApplication::translate("MainWindow", "B\346\226\271\345\220\221\346\214\207\347\244\272\347\201\257", Q_NULLPTR));
        getstatus->setText(QApplication::translate("MainWindow", "\347\212\266\346\200\201\346\237\245\350\257\242", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\351\200\232\351\201\223\346\250\241\345\274\217", Q_NULLPTR));
        pcm_check->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\346\237\245\350\257\242", Q_NULLPTR));
        pcm_polling->setText(QApplication::translate("MainWindow", "PCM\345\256\232\346\227\266\346\237\245\350\257\242", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\344\274\240\346\204\237\345\231\250\346\212\245\350\255\246", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
