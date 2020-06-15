#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QSerialPortInfo>
#include <QComboBox>
#include <QDebug>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <QString>
#include <QFile>
#include <QMessageBox>
//#include <QSocketNotifier>
#include <QTimer>
#include <QTime>
//#include <termios.h>
//#include <sys/ioctl.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include "global.h"

#define CUTECOMM_BUFSIZE (1024)

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();


signals:
    void sendCheckCmd(unsigned char cmd);

private slots:
    void on_openSerialPortBtn_clicked();
    void timeUpdate();
    void on_closeSerialPortBtn_clicked();

  //  void on_checkStatusBtn_clicked();

    void on_checkParamStatusBtn_clicked();

    void on_outputClearBtn_clicked();

    void readData();

    void doOutput();
    void on_setParamsBtn_clicked();
    void execCmd(QByteArray &tmp_cmd);

    void on_allowEnterBtn_A_clicked();

   // void counter_passnumber();
    void on_polling_clicked();
    void on_auto_polling_clicked();

    void on_setModeBtn_clicked();

   // void on_auto_test_clicked();

  void on_reser_alarm_clicked();
    void on_moduleTestBtn_clicked();

   // void on_startTestBtn_clicked();

  //  void on_finishTestBtn_clicked();
  // void on_light_switch_clicked();

    void on_checkSwVerBtn_clicked();

    void moduleTestCommand();

    void on_auto_polling_B_stateChanged(int status);

   void on_sensorStatusCheckBox_stateChanged(int status);
   void on_pcm_check_stateChanged(int status);
  void on_pcm_polling_clicked();

    void on_allowEnterBtn_B_clicked();
 // void on_chuanganqi_a_clicked();
 // void on_chuanganqi_b_clicked();
  void on_AD_switch_clicked();
  void on_BD_switch_clicked();
  void on_getstatus_clicked();

private:
    void addOutput(const QString& text);
    bool sendString(const QString& s);
    void dataPro( unsigned char *dest, int &dest_len, unsigned char *src, int src_len);
    int UnpackData(unsigned char *pBuf, int iDataLen);

private:
    Ui::MainWindow *ui;
    int m_fd;
    QByteArray buffer;
    unsigned int m_hexBytes;
    //QSocketNotifier *m_notifier;
    QSerialPort *serial;
    unsigned char m_buf[CUTECOMM_BUFSIZE];
    QTimer m_outputTimer;
    QTime m_outputTimerStart;
    QString m_outputBuffer;
    unsigned char cmdNum;

    QTimer *checkStatusTimer;
    QTimer *polltimer;
     QTimer *pcmtimer;
     QTimer *recvtimer;
     QTimer *sensorStatusTimer;
    int m_iRecvLen;
    unsigned char m_mRecv[DEAL_DATA_SIZE];


};

#endif // MAINWINDOW_H
