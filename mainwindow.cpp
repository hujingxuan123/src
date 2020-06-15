#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string.h>

unsigned char calc_bcc(unsigned char *buffer, int len)
{
    unsigned char bcc = 0;
    int i;

    for (i = 0; i < len; i++) {
        bcc = bcc^buffer[i];
    }
    return bcc;
}

int byteArrayToInt(QByteArray &arr, int mode)
{

    if(arr.size() < 4) {
        return 0;
    }

    int res = 0;

    if(mode == 0) {

        res =   arr.at(0)        & 0x000000FF;
        res |= (arr.at(1) << 8)  & 0x0000FF00;
        res |= (arr.at(2) << 16) & 0x00FF0000;
        res |= (arr.at(3) << 24) & 0xFF000000;

    } else if( mode == 1) {

        res =  (arr.at(0) << 24) & 0xFF000000;
        res |= (arr.at(1) << 16) & 0x00FF0000;
        res |= (arr.at(2) << 8)  & 0x0000FF00;
        res |= arr.at(3)         & 0x000000FF;

    }

    return res;

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
   ,m_fd(-1)
   ,m_hexBytes(0)
   ,m_outputTimer(this)
   ,cmdNum(0)
   ,m_iRecvLen(0)
{
    ui->setupUi(this);

    memset(m_mRecv, 0, DEAL_DATA_SIZE);

    ui->serialPortCb->clear();
    //通过QSerialPortInfo查找可用串口
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        ui->serialPortCb->addItem(info.portName());
    }

    serial = new QSerialPort(this);
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);
    polltimer = new QTimer(this);
    pcmtimer =new QTimer(this);
    sensorStatusTimer = new QTimer(this);
    recvtimer=new QTimer(this);
    ui->outputTb->setWordWrapMode(QTextOption::WrapAnywhere);
    ui->outputTb->document()->setMaximumBlockCount(100);

    ui->param1LE->setText("0");//0a
    ui->param2LE->setText("15");//00
    ui->param3LE->setText("10");//0f
    ui->param4LE->setText("20");//3c
    ui->param5LE->setText("20");//00
    ui->param6LE->setText("180");//64
    ui->param7LE->setText("70");//00
    //ui->param8LE->setText("3");//03
    //ui->param9LE->setText("3");//03
    ui->param7LE_2->setText("0");//00
    ui->param11LE->setText("20");//00
    ui->param11LE_2->setText("0");//00

    ui->param1LE->setValidator(new QIntValidator(1, 255, this));
    ui->param2LE->setValidator(new QIntValidator(0, 255, this));
    ui->param3LE->setValidator(new QIntValidator(1, 255, this));
    ui->param4LE->setValidator(new QIntValidator(1, 255, this));
    ui->param5LE->setValidator(new QIntValidator(0, 255, this));
    ui->param6LE->setValidator(new QIntValidator(0, 255, this));
    ui->param7LE->setValidator(new QIntValidator(0, 255, this));
    //ui->param8LE->setValidator(new QIntValidator(1, 4, this));
    //ui->param9LE->setValidator(new QIntValidator(1, 4, this));
    ui->param7LE_2->setValidator(new QIntValidator(0, 255, this));
    ui->param11LE->setValidator(new QIntValidator(0, 255, this));
    ui->param11LE_2->setValidator(new QIntValidator(0, 255, this));
  //  ui->counter_a->setValidator(new QIntValidator(0,1,this));
  //  ui->counter_b->setValidator(new QIntValidator(0,1,this));


    connect(&m_outputTimer, SIGNAL(timeout()), this, SLOT(doOutput()));
    connect(ui->inputClearBtn, SIGNAL(clicked()), ui->oldCmdsLb, SLOT(clear()));
    connect(recvtimer, SIGNAL(timeout()), this, SLOT(timeUpdate()));
    m_outputTimerStart.start();

   // checkStatusTimer = new QTimer(this);
   // sensorStatusTimer = new QTimer(this);
    //on_closeSerialPortBtn_clicked();

    ui->openSerialPortBtn->setEnabled(true);
    ui->closeSerialPortBtn->setEnabled(false);
    ui->openSerialPortBtn->setFocus();
    ui->serialPortCb->setEnabled(true);

    ui->checkSwVerBtn->setEnabled(false);

    ui->setParamsBtn->setEnabled(true);
    ui->checkParamStatusBtn->setEnabled(false);
    ui->allowEnterBtn_A->setEnabled(false);

    ui->allowEnterBtn_B->setEnabled(false);

    ui->setModeBtn->setEnabled(false);
    ui->runModeCB->setEnabled(false);
 //   ui->a_door->setEnabled(false);
 //   ui->b_door->setEnabled(false);
    //ui->aisleModeCB->setEnabled(false);

    ui->moduleTestBtn->setEnabled(false);
    ui->testContentCB->setEnabled(false);

    //addOutput("\n");

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::timeUpdate(){
    recvtimer->stop();

    if(buffer.length()!=0){

        qDebug()<<buffer;
    }
    buffer.clear();
}
void MainWindow::on_openSerialPortBtn_clicked()
{

    //设置串口名
    serial->setPortName(ui->serialPortCb->currentText());

    //设置波特率
    serial->setBaudRate(9600);
    //serial->setBaudRate(115200);

    //设置数据位数
    serial->setDataBits(QSerialPort::Data8);

    //设置奇偶校验
    serial->setParity(QSerialPort::NoParity);

    //设置停止位
    serial->setStopBits(QSerialPort::OneStop);

    //设置流控制
    serial->setFlowControl(QSerialPort::NoFlowControl);

    //打开串口
    if(!serial->open(QIODevice::ReadWrite)) {
        QMessageBox::about(NULL, "提示", "无法打开串口！");
        return;
    }

    m_hexBytes = 0;

    ui->openSerialPortBtn->setEnabled(false);
    ui->serialPortCb->setEnabled(false);
    ui->closeSerialPortBtn->setEnabled(true);

    ui->checkSwVerBtn->setEnabled(true);

    ui->setParamsBtn->setEnabled(true);
    ui->checkParamStatusBtn->setEnabled(true);
    ui->allowEnterBtn_A->setEnabled(true);

    ui->allowEnterBtn_B->setEnabled(true);

    ui->setModeBtn->setEnabled(true);
    ui->runModeCB->setEnabled(true);
  //  ui->a_door->setEnabled(true);
 //   ui->b_door->setEnabled(true);



    ui->moduleTestBtn->setEnabled(true);
    ui->testContentCB->setEnabled(true);


}

void MainWindow::on_closeSerialPortBtn_clicked()
{
    m_outputTimer.stop();
    m_outputBuffer = "";

    if(polltimer->isActive()) {
        polltimer->stop();
        polltimer->disconnect();
    }


    if(pcmtimer->isActive()) {
        pcmtimer->stop();
        pcmtimer->disconnect();
    }
    ui->openSerialPortBtn->setEnabled(true);
    ui->closeSerialPortBtn->setEnabled(false);
    ui->openSerialPortBtn->setFocus();
    ui->serialPortCb->setEnabled(true);

    ui->checkSwVerBtn->setEnabled(false);
   /* ui->initPCMBtn->setEnabled(false); */
   /* ui->checkStatusBtn->setEnabled(false);*/
    ui->setParamsBtn->setEnabled(false);
    ui->checkParamStatusBtn->setEnabled(false);
    ui->allowEnterBtn_A->setEnabled(false);

    ui->allowEnterBtn_B->setEnabled(false);

    ui->setModeBtn->setEnabled(false);
  //  ui->a_door->setEnabled(false);
  //  ui->b_door->setEnabled(false);
    ui->runModeCB->setEnabled(false);
    ui->moduleTestBtn->setEnabled(false);
    ui->testContentCB->setEnabled(false);

    //关闭串口
    if(serial->isOpen()) {
         serial->close();
    }

}

void MainWindow::readData()
{
    //从接收缓冲区中读取数据
    memset(m_buf,0x00,1024);
    unsigned char byData = 0;
    recvtimer->start(500);
    buffer.append(serial->readAll());
    int bytesRead = buffer.length();
  //  printf("bytesRead is %d",bytesRead);
    memcpy(m_buf, buffer, qMin(buffer.size(), (int)sizeof(m_buf)));
   /* printf("**************recvdata************\n");
    for (int i=0;i<bytesRead;i++){
        printf("%02x ",(unsigned char)buffer[i]);
    } */
    if (bytesRead < 0) {
       std::cerr << "read result: "<< bytesRead << std::endl;
       perror("read: \n");
       return;
    } else if (bytesRead == 0) { // if the device "disappeared", e.g. from USB, we get a read event for 0 bytes
       on_closeSerialPortBtn_clicked();
       return;
    }
  // if((m_buf[bytesRead-1]&0xf0)==0xE0){


       if((m_buf[bytesRead-1]&0xf0)==0xe0){
         UnpackData(m_buf, bytesRead);
         const unsigned char* c = m_buf;
         QString text;
         char buf[16];
         for (int i = 0; i < bytesRead; i++) {

            unsigned int b = *c;
            snprintf(buf, 16, "%02x ", b & 0xff);
            text += buf;

            m_hexBytes++;
            if ((m_hexBytes % 16) == 0) {
               //text += "\n";
            } else if ((m_hexBytes % 8) == 0) {
               //text += "  ";
            }

            c++;
         }

         addOutput(text);

     }





   for (int i=0;i<bytesRead;i++){


       if(m_buf[i]==0x41&&m_buf[i+1]==0x75){


        if(m_buf[i+2] & 0x01)
        {
            ui->checkBox_S13->setChecked(true);
        }
        else
        {
            ui->checkBox_S13->setChecked(false);
        }

        if(m_buf[i+2] & 0x02)
        {
            ui->checkBox_S14->setChecked(true);
        }
        else
        {
            ui->checkBox_S14->setChecked(false);
        }

        if(m_buf[i+2]& 0x04)
        {
            ui->checkBox_S15->setChecked(true);
        }
        else
        {
            ui->checkBox_S15->setChecked(false);
        }

        if(m_buf[i+2]& 0x08)
        {
            ui->checkBox_S16->setChecked(true);
        }
        else
        {
            ui->checkBox_S16->setChecked(false);
        }

        if(m_buf[i+3]& 0x01)
        {
            ui->checkBox_S9->setChecked(true);
        }
        else
        {
            ui->checkBox_S9->setChecked(false);
        }

        if(m_buf[i+3]& 0x02)
        {
            ui->checkBox_S10->setChecked(true);
        }
        else
        {
            ui->checkBox_S10->setChecked(false);
        }

        if(m_buf[i+3]&0x04)
        {
            ui->checkBox_S11->setChecked(true);
        }
        else
        {
            ui->checkBox_S11->setChecked(false);
        }

        if(m_buf[i+3]&0x08)
        {
            ui->checkBox_S12->setChecked(true);
        }
        else
        {
            ui->checkBox_S12->setChecked(false);
        }

        if(m_buf[i+4]&0x01)
        {
            ui->checkBox_S5->setChecked(true);
        }
        else
        {
            ui->checkBox_S5->setChecked(false);
        }

        if(m_buf[i+4]&0x02)
        {
            ui->checkBox_S6->setChecked(true);
        }
        else
        {
            ui->checkBox_S6->setChecked(false);
        }

        if(m_buf[i+4]&0x04)
        {
            ui->checkBox_S7->setChecked(true);
        }
        else
        {
            ui->checkBox_S7->setChecked(false);
        }

        if(m_buf[i+4]&0x08)
        {
            ui->checkBox_S8->setChecked(true);
        }
        else
        {
            ui->checkBox_S8->setChecked(false);
        }

        if(m_buf[i+5]&0x01)
        {
            ui->checkBox_S1->setChecked(true);
        }
        else
        {
            ui->checkBox_S1->setChecked(false);
        }

        if(m_buf[i+5]&0x02)
        {
            ui->checkBox_S2->setChecked(true);
        }
        else
        {
            ui->checkBox_S2->setChecked(false);
        }

        if(m_buf[i+5]&0x04)
        {
            ui->checkBox_S3->setChecked(true);
        }
        else
        {
            ui->checkBox_S3->setChecked(false);
        }

        if(m_buf[i+5]&0x08)
        {
            ui->checkBox_S4->setChecked(true);
        }
        else
        {
            ui->checkBox_S4->setChecked(false);
        }


        //  baojng

        if(m_buf[i+6] & 0x01)
        {
            ui->checkBox_S13_2->setChecked(true);
        }
        else
        {
            ui->checkBox_S13_2->setChecked(false);
        }

        if(m_buf[i+6] & 0x02)
        {
            ui->checkBox_S14_2->setChecked(true);
        }
        else
        {
            ui->checkBox_S14_2->setChecked(false);
        }

        if(m_buf[i+6]& 0x04)
        {
            ui->checkBox_S15_2->setChecked(true);
        }
        else
        {
            ui->checkBox_S15_2->setChecked(false);
        }

        if(m_buf[i+6]& 0x08)
        {
            ui->checkBox_S16_2->setChecked(true);
        }
        else
        {
            ui->checkBox_S16_2->setChecked(false);
        }

        if(m_buf[i+7]& 0x01)
        {
            ui->checkBox_S9_2->setChecked(true);
        }
        else
        {
            ui->checkBox_S9_2->setChecked(false);
        }

        if(m_buf[i+7]& 0x02)
        {
            ui->checkBox_S10_2->setChecked(true);
        }
        else
        {
            ui->checkBox_S10_2->setChecked(false);
        }

        if(m_buf[i+7]&0x04)
        {
            ui->checkBox_S11_2->setChecked(true);
        }
        else
        {
            ui->checkBox_S11_2->setChecked(false);
        }

        if(m_buf[i+7]&0x08)
        {
            ui->checkBox_S12_2->setChecked(true);
        }
        else
        {
            ui->checkBox_S12_2->setChecked(false);
        }

        if(m_buf[i+8]&0x01)
        {
            ui->checkBox_S5_2->setChecked(true);
        }
        else
        {
            ui->checkBox_S5_2->setChecked(false);
        }

        if(m_buf[i+8]&0x02)
        {
            ui->checkBox_S6_2->setChecked(true);
        }
        else
        {
            ui->checkBox_S6_2->setChecked(false);
        }

        if(m_buf[i+8]&0x04)
        {
            ui->checkBox_S7_2->setChecked(true);
        }
        else
        {
            ui->checkBox_S7_2->setChecked(false);
        }

        if(m_buf[i+8]&0x08)
        {
            ui->checkBox_S8_2->setChecked(true);
        }
        else
        {
            ui->checkBox_S8_2->setChecked(false);
        }

        if(m_buf[i+9]&0x01)
        {
            ui->checkBox_S1_2->setChecked(true);
        }
        else
        {
            ui->checkBox_S1_2->setChecked(false);
        }

        if(m_buf[i+9]&0x02)
        {
            ui->checkBox_S2_2->setChecked(true);
        }
        else
        {
            ui->checkBox_S2_2->setChecked(false);
        }

        if(m_buf[i+9]&0x04)
        {
            ui->checkBox_S3_2->setChecked(true);
        }
        else
        {
            ui->checkBox_S3_2->setChecked(false);
        }

        if(m_buf[i+9]&0x08)
        {
            ui->checkBox_S4_2->setChecked(true);
        }
        else
        {
            ui->checkBox_S4_2->setChecked(false);
        }





}

}

}



int MainWindow::UnpackData(unsigned char *pBuf, int iDataLen)
{

    int i = 0;
    int iDtIter = 0;
   // static unsigned char byCommState = RECV_DLE;                  //	通信状态
    unsigned char byData = 0;
    unsigned char paramone_high;
    unsigned char paramone_low;
    unsigned char paramtwo_high;
    unsigned char paramtwo_low;
    unsigned char paramthree_high;
    unsigned char paramthree_low;
    unsigned char paramfour_high;
    unsigned char paramfour_low;
    unsigned char paramfive_high;
    unsigned char paramfive_low;
    unsigned char paramsix_high;
    unsigned char paramsix_low;
    unsigned char paramseven_high;
    unsigned char paramseven_low;
    unsigned char parameight_high;
    unsigned char parameight_low;
    unsigned char paramnine_high;
    unsigned char paramnine_low;
    unsigned char paramten_high;
    unsigned char paramten_low;
    unsigned char paramone_sum;
    unsigned char paramtwo_sum;
    unsigned char paramthree_sum;
    unsigned char paramfour_sum;
    unsigned char paramfive_sum;
    unsigned char paramsix_sum;
    unsigned char paramseven_sum;
    unsigned char parameight_sum;
    unsigned char paramnine_sum;

    unsigned char paramten_sum;
    printf("pbuf is ");
 for (int i=0;i<iDataLen;i++){

     printf("%02x ",pBuf[i]);
   //   printf("%02x ",pBuf[22]);
     if (pBuf[3]==0x70&&pBuf[2]==0x41&&pBuf[92]==0xe0){

     if (pBuf[7]==0x81&&pBuf[11]==0x81&&pBuf[19]==0x89){


         ui->lineEdit->setText("暂停服务模式");
     }

       if (pBuf[23]==0x88){


        ui->baojing->setText("通行传感器故障");
     }


       if (pBuf[23]==0x80){

        ui->baojing->setText("通行传感器正常");
     }

       if (pBuf[7]==0x83&&pBuf[11]==0x83){

         ui->lineEdit->setText("双门双向受控模式");
     }

       if (pBuf[6]==0x82&&pBuf[7]==0x82&&pBuf[10]==0x82&&pBuf[11]==0x82&&pBuf[19]==0x88){

         ui->lineEdit->setText("维护模式");
     }


       if (pBuf[6]==0x82&&pBuf[7]==0x82&&pBuf[10]==0x88&&pBuf[11]==0x82&&pBuf[19]==0x88){

         ui->lineEdit->setText("软件紧急模式");
     }



       if (pBuf[7]==0x83&&pBuf[11]==0x81){

         ui->lineEdit->setText("受控进站模式");
     }


      if (pBuf[7]==0x81&&pBuf[11]==0x83){

         ui->lineEdit->setText("受控出站模式");
     }


       if (pBuf[7]==0x83&&pBuf[11]==0x82){

         ui->lineEdit->setText("受控进站 / 免费出站模式");
     }


       if (pBuf[7]==0x82&&pBuf[11]==0x83){

         ui->lineEdit->setText("免费进站 / 受控出站模式");
     }


       if (pBuf[7]==0x82&&pBuf[11]==0x81){

         ui->lineEdit->setText("免费进站模式");
     }
       if (pBuf[7]==0x81&&pBuf[11]==0x82){

         ui->lineEdit->setText("免费出站模式");
     }

      if (pBuf[6]==0x80&&pBuf[7]==0x82&&pBuf[10]==0x80&&pBuf[11]==0x82&&pBuf[19]==0x88){

        ui->lineEdit->setText("双向免费模式");
     }

















}




   /*  if(pBuf[i]==0x41&&pBuf[i+1]==0x75){

     printf("----------------");
      if(pBuf[i+2] & 0x01)
      {
          ui->checkBox_S13->setChecked(true);
      }
      else
      {
          ui->checkBox_S13->setChecked(false);
      }

      if(pBuf[i+2] & 0x02)
      {
          ui->checkBox_S14->setChecked(true);
      }
      else
      {
          ui->checkBox_S14->setChecked(false);
      }

      if(pBuf[i+2]& 0x04)
      {
          ui->checkBox_S15->setChecked(true);
      }
      else
      {
          ui->checkBox_S15->setChecked(false);
      }

      if(pBuf[i+2]& 0x08)
      {
          ui->checkBox_S16->setChecked(true);
      }
      else
      {
          ui->checkBox_S16->setChecked(false);
      }

      if(pBuf[i+3]& 0x01)
      {
          ui->checkBox_S9->setChecked(true);
      }
      else
      {
          ui->checkBox_S9->setChecked(false);
      }

      if(pBuf[i+3]& 0x02)
      {
          ui->checkBox_S10->setChecked(true);
      }
      else
      {
          ui->checkBox_S10->setChecked(false);
      }

      if(pBuf[i+3]&0x04)
      {
          ui->checkBox_S11->setChecked(true);
      }
      else
      {
          ui->checkBox_S11->setChecked(false);
      }

      if(pBuf[i+3]&0x08)
      {
          ui->checkBox_S12->setChecked(true);
      }
      else
      {
          ui->checkBox_S12->setChecked(false);
      }

      if(pBuf[i+4]&0x01)
      {
          ui->checkBox_S5->setChecked(true);
      }
      else
      {
          ui->checkBox_S5->setChecked(false);
      }

      if(pBuf[i+4]&0x02)
      {
          ui->checkBox_S6->setChecked(true);
      }
      else
      {
          ui->checkBox_S6->setChecked(false);
      }

      if(pBuf[i+4]&0x04)
      {
          ui->checkBox_S7->setChecked(true);
      }
      else
      {
          ui->checkBox_S7->setChecked(false);
      }

      if(pBuf[i+4]&0x08)
      {
          ui->checkBox_S8->setChecked(true);
      }
      else
      {
          ui->checkBox_S8->setChecked(false);
      }

      if(pBuf[i+5]&0x01)
      {
          ui->checkBox_S1->setChecked(true);
      }
      else
      {
          ui->checkBox_S1->setChecked(false);
      }

      if(pBuf[i+5]&0x02)
      {
          ui->checkBox_S2->setChecked(true);
      }
      else
      {
          ui->checkBox_S2->setChecked(false);
      }

      if(pBuf[i+5]&0x04)
      {
          ui->checkBox_S3->setChecked(true);
      }
      else
      {
          ui->checkBox_S3->setChecked(false);
      }

      if(pBuf[i+5]&0x08)
      {
          ui->checkBox_S4->setChecked(true);
      }
      else
      {
          ui->checkBox_S4->setChecked(false);
      }


      //  baojng

      if(pBuf[i+6] & 0x01)
      {
          ui->checkBox_S13_2->setChecked(true);
      }
      else
      {
          ui->checkBox_S13_2->setChecked(false);
      }

      if(pBuf[i+6] & 0x02)
      {
          ui->checkBox_S14_2->setChecked(true);
      }
      else
      {
          ui->checkBox_S14_2->setChecked(false);
      }

      if(pBuf[i+6]& 0x04)
      {
          ui->checkBox_S15_2->setChecked(true);
      }
      else
      {
          ui->checkBox_S15_2->setChecked(false);
      }

      if(pBuf[i+6]& 0x08)
      {
          ui->checkBox_S16_2->setChecked(true);
      }
      else
      {
          ui->checkBox_S16_2->setChecked(false);
      }

      if(pBuf[i+7]& 0x01)
      {
          ui->checkBox_S9_2->setChecked(true);
      }
      else
      {
          ui->checkBox_S9_2->setChecked(false);
      }

      if(pBuf[i+7]& 0x02)
      {
          ui->checkBox_S10_2->setChecked(true);
      }
      else
      {
          ui->checkBox_S10_2->setChecked(false);
      }

      if(pBuf[i+7]&0x04)
      {
          ui->checkBox_S11_2->setChecked(true);
      }
      else
      {
          ui->checkBox_S11_2->setChecked(false);
      }

      if(pBuf[i+7]&0x08)
      {
          ui->checkBox_S12_2->setChecked(true);
      }
      else
      {
          ui->checkBox_S12_2->setChecked(false);
      }

      if(pBuf[i+8]&0x01)
      {
          ui->checkBox_S5_2->setChecked(true);
      }
      else
      {
          ui->checkBox_S5_2->setChecked(false);
      }

      if(pBuf[i+8]&0x02)
      {
          ui->checkBox_S6_2->setChecked(true);
      }
      else
      {
          ui->checkBox_S6_2->setChecked(false);
      }

      if(pBuf[i+8]&0x04)
      {
          ui->checkBox_S7_2->setChecked(true);
      }
      else
      {
          ui->checkBox_S7_2->setChecked(false);
      }

      if(pBuf[i+8]&0x08)
      {
          ui->checkBox_S8_2->setChecked(true);
      }
      else
      {
          ui->checkBox_S8_2->setChecked(false);
      }

      if(pBuf[i+9]&0x01)
      {
          ui->checkBox_S1_2->setChecked(true);
      }
      else
      {
          ui->checkBox_S1_2->setChecked(false);
      }

      if(pBuf[i+9]&0x02)
      {
          ui->checkBox_S2_2->setChecked(true);
      }
      else
      {
          ui->checkBox_S2_2->setChecked(false);
      }

      if(pBuf[i+9]&0x04)
      {
          ui->checkBox_S3_2->setChecked(true);
      }
      else
      {
          ui->checkBox_S3_2->setChecked(false);
      }

      if(pBuf[i+9]&0x08)
      {
          ui->checkBox_S4_2->setChecked(true);
      }
      else
      {
          ui->checkBox_S4_2->setChecked(false);
      }






 }
     */



}



                if(pBuf[1]==0x71) {
                    if(pBuf[2]==0x80&&pBuf[3]==0x83){
                           ui->type->setText("扇门");

                    }
                    QByteArray sw1;
                    sw1.append(pBuf[4]);//(QString("%1").arg(m_mRecv[4]))
                    sw1.append(pBuf[5]);
                    sw1.append(pBuf[6]);
                    sw1.append(pBuf[7]);
                    ui->swSerialNumLabel->setText(sw1.toHex());
                }



                if(pBuf[1]==0x78) {
                   int paramone=0;
                   paramone_high= pBuf[2]&0x0f;
                   paramone_low= pBuf[3]&0x0f;
                   paramone_sum=(paramone_high<<4)|paramone_low;
                   QString a_num;
                   char a_buf[4];
                   bool ok;
                   snprintf(a_buf,4,"%02x",paramone_sum);
                   a_num+=a_buf;
                   paramone=a_num.toInt(&ok,16);
               //    printf("b is %d\n",paramone);
                   QString Param_one=QString::number(paramone);
                   ui->param1LE->setText((QString("%1").arg(Param_one)));

                   int paramtwo=0;
                    paramtwo_high= pBuf[4]&0x0f;
                    paramtwo_low= pBuf[5]&0x0f;
                    paramtwo_sum=(paramtwo_high<<4)|paramtwo_low;
                    QString param_two;
                    char param_two_buf[4];
                    snprintf(param_two_buf,4,"%02x",paramtwo_sum);
                    param_two+=param_two_buf;
                    paramtwo=param_two.toInt(&ok,16);
                 //   printf("b is %d\n",paramtwo);
                    QString Param_two=QString::number(paramtwo);
                    ui->param2LE->setText((QString("%1").arg(Param_two)));




                    int paramthree=0;
                    paramthree_high= pBuf[6]&0x0f;
                    paramthree_low= pBuf[7]&0x0f;
                    paramthree_sum=(paramthree_high<<4)|paramthree_low;

                    QString param_three;
                    char param_three_buf[4];
                    snprintf(param_three_buf,4,"%02x",paramthree_sum);
                    param_three+=param_three_buf;
                    paramthree=param_three.toInt(&ok,16);
               //     printf("b is %d\n",paramthree);
                    QString Param_three=QString::number(paramthree);

                    ui->param3LE->setText((QString("%1").arg(Param_three)));



                    int paramfour=0;
                    paramfour_high= pBuf[8]&0x0f;
                    paramfour_low= pBuf[9]&0x0f;
                    paramfour_sum=(paramfour_high<<4)|paramfour_low;

                    QString param_four;
                    char param_four_buf[4];
                    snprintf(param_four_buf,4,"%02x",paramfour_sum);
                    param_four+=param_four_buf;
                    paramfour=param_four.toInt(&ok,16);
             //       printf("b is %d\n",paramfour);
                    QString Param_four=QString::number(paramfour);
                    ui->param4LE->setText((QString("%1").arg(Param_four)));


                     int paramfive=0;

                    paramfive_high= pBuf[10]&0x0f;
                    paramfive_low= pBuf[11]&0x0f;
                    paramfive_sum=(paramfive_high<<4)|paramfive_low;

                    QString param_five;
                    char param_five_buf[4];
                    snprintf(param_five_buf,4,"%02x",paramfive_sum);
                    param_five+=param_five_buf;
                    paramfive=param_five.toInt(&ok,16);
                 //   printf("b is %d\n",paramfive);
                    QString Param_five=QString::number(paramfive);
                    ui->param5LE->setText((QString("%1").arg(Param_five)));


                    int paramsix=0;
                    paramsix_high= pBuf[12]&0x0f;
                    paramsix_low= pBuf[13]&0x0f;
                    paramsix_sum=(paramsix_high<<4)|paramsix_low;

                    QString param_six;
                    char param_six_buf[4];
                    snprintf(param_six_buf,4,"%02x",paramsix_sum);
                    param_six+=param_six_buf;
                    paramsix=param_six.toInt(&ok,16);
               //     printf("b is %d\n",paramsix);
                    QString Param_Six=QString::number(paramsix);

                    ui->param6LE->setText((QString("%1").arg(Param_Six)));




                   int paramseven=0;
                    paramseven_high= pBuf[14]&0x0f;
                    paramseven_low= pBuf[15]&0x0f;
                    paramseven_sum=(paramseven_high<<4)|paramseven_low;

                    QString param_seven;
                    char param_seven_buf[4];
                    snprintf(param_seven_buf,4,"%02x",paramseven_sum);
                    param_seven+=param_seven_buf;
                    paramseven=param_seven.toInt(&ok,16);
              //      printf("b is %d\n",paramseven);
                    QString Param_Seven=QString::number(paramseven);


                    ui->param7LE->setText((QString("%1").arg(Param_Seven)));


                    //ui->param8LE->setText((QString("%1").arg(m_mRecv[11])));
                    //ui->param9LE->setText((QString("%1").arg(m_mRecv[12])));

                    int parameight=0;

                    parameight_high= pBuf[16]&0x0f;
                    parameight_low= pBuf[17]&0x0f;
                    parameight_sum=(parameight_high<<4)|parameight_low;

                    QString param_eight;
                    char param_eight_buf[4];
                    snprintf(param_eight_buf,4,"%02x",parameight_sum);
                    param_eight+=param_eight_buf;
                    parameight=param_eight.toInt(&ok,16);
              //      printf("b is %d\n",parameight);
                    QString Param_Eight=QString::number(parameight);

                    ui->param7LE_2->setText((QString("%1").arg(Param_Eight)));


                    int paramnine=0;
                    paramnine_high= pBuf[18]&0x0f;
                    paramnine_low= pBuf[19]&0x0f;
                    paramnine_sum=(paramnine_high<<4)|paramnine_low;

                    QString param_nine;
                    char param_nine_buf[4];
                    snprintf(param_nine_buf,4,"%02x",paramnine_sum);
                    param_nine+=param_nine_buf;
                    paramnine=param_nine.toInt(&ok,16);
                //    printf("b is %d\n",paramnine);
                    QString Param_Nine=QString::number(paramnine);

                    ui->param11LE->setText((QString("%1").arg(Param_Nine)));


                    int paramten=0;
                    paramten_high= pBuf[20]&0x0f;
                    paramten_low= pBuf[21]&0x0f;
                    paramten_sum=(paramten_high<<4)|paramten_low;

                    QString param_ten;
                    char param_ten_buf[4];
                    snprintf(param_ten_buf,4,"%02x",paramten_sum);
                    param_ten+=param_ten_buf;
                    paramten=param_ten.toInt(&ok,16);
              //      printf("b is %d\n",paramten);
                    QString Param_Ten=QString::number(paramten);

                    ui->param11LE_2->setText((QString("%1").arg(Param_Ten)));
                }


    return 0;

}

void MainWindow::addOutput(const QString &text)
{
    m_outputBuffer.clear();
    m_outputBuffer += text;

    if (!m_outputTimer.isActive()) {
       doOutput();
       m_outputTimerStart.restart();
       m_outputTimer.setSingleShot(true);
       m_outputTimer.start(50);
    } else {
       if ((m_outputTimerStart.elapsed() > 400)
          || ((m_outputTimerStart.elapsed() > 200) && (m_outputBuffer.length() < 100))) {
          doOutput();
          m_outputTimerStart.restart();
       }
       m_outputTimer.setSingleShot(true);
       m_outputTimer.start(50);
    }
}

void MainWindow::doOutput()
{
   if (m_outputBuffer.isEmpty()) {
      return;
   }

   ui->outputTb->append(m_outputBuffer);
   m_outputBuffer.clear();
}

void MainWindow::execCmd(QByteArray &tmp_cmd)
{

    QString cmd = QString(tmp_cmd.toHex()).trimmed();

    if (!cmd.isEmpty()) {

        int n = cmd.length();

        while((n - 2) > 0) {

            n = n - 2;

            cmd.insert(n, " ");

        }

       if ((ui->oldCmdsLb->count() < 1) || (ui->oldCmdsLb->item(ui->oldCmdsLb->count() - 1)->text() != cmd)) {
          ui->oldCmdsLb->addItem(cmd);
          ui->oldCmdsLb->setCurrentRow(ui->oldCmdsLb->count() - 1);
          if (ui->oldCmdsLb->count() > 50) {
             ui->oldCmdsLb->removeItemWidget(ui->oldCmdsLb->item(0));
          }
       }
    }

    ui->oldCmdsLb->clearSelection();

    serial->write(tmp_cmd);

}

bool MainWindow::sendString(const QString &s)
{

    QString hex = s;
//    hex.remove(QRegExp("\\s"));
//    if ((hex.startsWith("0x")) || (hex.startsWith("0X")))
//    {
//       hex = hex.mid(2);
//    }

//    if (hex.length()%2 != 0)
//    {
//       hex="0" + hex;
//    }

//    for (int i=0; i < hex.length()/2; i++)
//    {
//       QString nextByte = hex.mid(i*2, 2);
//       bool ok = true;
//       nextByte.toUInt(&ok, 16);
//       if (!ok)
//       {
//          QMessageBox::information(this, tr("Invalid hex characters"), tr("The input string contains invalid hex characters: 0x%1").arg(nextByte));
//          return false;
//       }
//    }

    QByteArray data = hex.toLatin1();
    serial->write(data);

    return true;

}

void MainWindow::dataPro(unsigned char *dest, int &dest_len, unsigned char *src, int src_len)
{

    unsigned char bcc = 0;
    int i;
    for( i=0; i<src_len; i++ )
    {
        bcc ^= src[i];
    }
        bcc ^= SEND_ETX;
    unsigned char high_data = HIGH_CHK + (( bcc & 0xf0 ) >> 4);
    unsigned char low_data = LOW_CHK + ( bcc & 0x0f );
    printf("high data is %02x, low is %02x\n",high_data,low_data);


    int b = 0;

    for(int k = 0; k < src_len; k++) {
          dest[b++] = src[k];


    }
    dest[b++]=high_data;
    dest[b++]=low_data;
    dest[b++]=SEND_ETX;
    dest_len = b;

    for (int i=0;i<dest_len;i++){


        printf("last data is %02x",dest[i]);
    }

}

void MainWindow::on_checkSwVerBtn_clicked()
{
    unsigned char data[5];
    unsigned char dataPack[LEN_MAX];
    int dataPack_len = 5;
    memset(data, 0, sizeof(data));
    memset(dataPack, 0, LEN_MAX);
    data[0] = 0x21;
    data[1] = 0x71;
    data[2] = 0xA9;
    data[3] = 0xB0;
    data[4] = 0xC0;


    QByteArray ba((char*)data, dataPack_len);

    execCmd(ba);
}

void MainWindow::on_outputClearBtn_clicked()
{
    ui->outputTb->clear();
    m_hexBytes = 0;
}




void MainWindow::on_checkParamStatusBtn_clicked()
{
    unsigned char data[2];
    unsigned char dataPack[LEN_MAX];
    int dataPack_len = 0;
    memset(data, 0, sizeof(data));
    memset(dataPack, 0, LEN_MAX);
    data[0] = 0x21;
    data[1] = 0x78;

   dataPro(dataPack, dataPack_len, data, sizeof(data));

    QByteArray ba((char*)dataPack, dataPack_len);
    execCmd(ba);
    //serial->write(ba);

}

void MainWindow::on_setParamsBtn_clicked()
{

    unsigned char data[22];
    unsigned char dataPack[LEN_MAX];
    int dataPack_len = 0;
    bool ok;

    memset(data, 0, sizeof(data));
    memset(dataPack, 0, LEN_MAX);
    data[0]  =  0x21;
    data[1]  =  0x68;
   /* data[2]  =  QString("%1").arg((ui->param1LE->text().toInt(&ok,10)),1,16,QChar('0')).toInt(&ok,16);
    data[3]  =  QString("%1").arg((ui->param2LE->text().toInt(&ok,10)),1,16,QChar('0')).toInt(&ok,16);
    data[4]  =  QString("%1").arg((ui->param3LE->text().toInt(&ok,10)),1,16,QChar('0')).toInt(&ok,16);
    data[5]  =  QString("%1").arg((ui->param4LE->text().toInt(&ok,10)),1,16,QChar('0')).toInt(&ok,16);
    data[6]  =  QString("%1").arg((ui->param5LE->text().toInt(&ok,10)),1,16,QChar('0')).toInt(&ok,16);
    data[7]  =  QString("%1").arg((ui->param6LE->text().toInt(&ok,10)),1,16,QChar('0')).toInt(&ok,16);
    data[8]  =  QString("%1").arg((ui->param7LE->text().toInt(&ok,10)),1,16,QChar('0')).toInt(&ok,16);

    data[9] =  QString("%1").arg((ui->param10LE->text().toInt(&ok,10)),1,16,QChar('0')).toInt(&ok,16);
    data[10] =  QString("%1").arg((ui->param11LE->text().toInt(&ok,10)),1,16,QChar('0')).toInt(&ok,16);
    data[11] =  QString("%1").arg((ui->param11LE_2->text().toInt(&ok,10)),1,16,QChar('0')).toInt(&ok,16); */


    int first_para=ui->param1LE->text().toInt();
    int first_shi=first_para/16;
    int first_ge=first_para%16;
    unsigned char data_2=0x80 + first_shi;
    unsigned char data_3=0x80+first_ge;
    data[2]=data_2;
    data[3]=data_3;

    int second_para=ui->param2LE->text().toInt();
    int second_shi=second_para/16;
    int second_ge=second_para%16;
    unsigned char second_4=0x80 + second_shi;
    unsigned char second_5=0x80+second_ge;
    data[4]=second_4;
    data[5]=second_5;

    int third_para=ui->param3LE->text().toInt();
    int third_shi=third_para/16;
    int third_ge=third_para%16;
    unsigned char third_6=0x80 + third_shi;
    unsigned char third_7=0x80+third_ge;
    data[6]=third_6;
    data[7]=third_7;

    int fourth_para=ui->param4LE->text().toInt();
    int fourth_shi=fourth_para/16;
    int fourth_ge=fourth_para%16;
    unsigned char fourth_8=0x80 + fourth_shi;
    unsigned char fourth_9=0x80+fourth_ge;
    data[8]=fourth_8;
    data[9]=fourth_9;


    int fifth_para=ui->param5LE->text().toInt();
    int fifth_shi=fifth_para/16;
    int fifth_ge=fifth_para%16;
    unsigned char fifth_10=0x80 + fifth_shi;
    unsigned char fifth_11=0x80+fifth_ge;
    data[10]=fifth_10;
    data[11]=fifth_11;

    int sixth_para=ui->param6LE->text().toInt();
    int sixth_shi=sixth_para/16;
    int sixth_ge=sixth_para%16;
    unsigned char sixth_12=0x80 + sixth_shi;
    unsigned char sixth_13=0x80+sixth_ge;
    data[12]=sixth_12;
    data[13]=sixth_13;

    int seventh_para=ui->param7LE->text().toInt();
    int seventh_shi=seventh_para/16;
    int seventh_ge=seventh_para%16;
    unsigned char seventh_14=0x80 + seventh_shi;
    unsigned char seventh_15=0x80+seventh_ge;
    data[14]=seventh_14;
    data[15]=seventh_15;

    int eigth_para=ui->param7LE_2->text().toInt();
    int eigth_shi=eigth_para/16;
    int eigth_ge=eigth_para%16;
    unsigned char eigth_16=0x80 + eigth_shi;
    unsigned char eigth_17=0x80+eigth_ge;
    data[16]=eigth_16;
    data[17]=eigth_17;


    int ninth_para=ui->param11LE->text().toInt();
    int ninth_shi=ninth_para/16;
    int ninth_ge=ninth_para%16;
    unsigned char ninth_18=0x80 + ninth_shi;
    unsigned char ninth_19=0x80+ninth_ge;
    data[18]=ninth_18;
    data[19]=ninth_19;


    int tenth_para=ui->param11LE_2->text().toInt();
    int tenth_shi=tenth_para/16;
    int tenth_ge=tenth_para%16;
    unsigned char tenth_20=0x80 + tenth_shi;
    unsigned char tenth_21=0x80+tenth_ge;
    data[20]=tenth_20;
    data[21]=tenth_21;


    dataPro(dataPack,dataPack_len,data,sizeof(data));
    QByteArray ba((char*)dataPack, dataPack_len);

    execCmd(ba);
    //serial->write(ba);

}

void MainWindow::on_allowEnterBtn_A_clicked()
{
    unsigned char data[6];
    unsigned char dataPack[LEN_MAX];
    int dataPack_len = 0;
    memset(data, 0, sizeof(data));
    memset(dataPack, 0, LEN_MAX);
    int index1 = ui->runModeCB->currentIndex();
    switch(index1) {

        case 0://停止服务
        data[0] = 0x21;
        data[1] = 0x60;
        data[2] = 0x90;
        data[3] = 0x90;
        data[4] = 0x81;
        data[5] = 0x81;
            break;

    case 1://双向受控
    data[0] = 0x21;
    data[1] = 0x60;
    data[2] = 0x90;
    data[3] = 0x90;
    data[4] = 0x81;
    data[5] = 0x83;
        break;

    case 2://维护模式
    data[0] = 0x21;
    data[1] = 0x60;
    data[2] = 0x90;
    data[3] = 0x90;
    data[4] = 0x83;
    data[5] = 0x82;
        break;

    case 4://受控进站
    data[0] = 0x21;
    data[1] = 0x60;
    data[2] = 0x90;
    data[3] = 0x90;
    data[4] = 0x81;
    data[5] = 0x83;
        break;

    case 5://受控出站
    data[0] = 0x21;
    data[1] = 0x60;
    data[2] = 0x90;
    data[3] = 0x90;
    data[4] = 0x81;
    data[5] = 0x81;
        break;

    case 6://受控进站 / 免费出站模式
    data[0] = 0x21;
    data[1] = 0x60;
    data[2] = 0x90;
    data[3] = 0x90;
    data[4] = 0x81;
    data[5] = 0x83;
        break;

    case 7://免费进站 / 受控出站模式
    data[0] = 0x21;
    data[1] = 0x60;
    data[2] = 0x90;
    data[3] = 0x90;
    data[4] = 0x81;
    data[5] = 0x82;
        break;

    case 8://免费进站模式
    data[0] = 0x21;
    data[1] = 0x60;
    data[2] = 0x90;
    data[3] = 0x90;
    data[4] = 0x81;
    data[5] = 0x82;
        break;

    case 9://免费出站模式
    data[0] = 0x21;
    data[1] = 0x60;
    data[2] = 0x90;
    data[3] = 0x90;
    data[4] = 0x81;
    data[5] = 0x81;
        break;

    case 10://双向免费模式
    data[0] = 0x21;
    data[1] = 0x60;
    data[2] = 0x90;
    data[3] = 0x90;
    data[4] = 0x81;
    data[5] = 0x82;
        break;









        default:
            break;

    }



    dataPro(dataPack,dataPack_len,data,sizeof(data));
    QByteArray ba((char*)dataPack, dataPack_len);



    execCmd(ba);
    //serial->write(ba);

}

/*void MainWindow::counter_passnumber(){

    unsigned char data[2];
    unsigned char dataPack[LEN_MAX];
    int dataPack_len = 0;
    memset(data, 0, sizeof(data));
    memset(dataPack, 0, LEN_MAX);
    data[0] = 0x21;
    data[1] = 0x70;
    dataPro(dataPack,dataPack_len,data,sizeof(data));
    QByteArray ba((char*)dataPack, dataPack_len);



    execCmd(ba);

} */

void MainWindow::on_allowEnterBtn_B_clicked()
{

    unsigned char data[6];
    unsigned char dataPack[LEN_MAX];
    int dataPack_len = 0;
    memset(data, 0, sizeof(data));
    memset(dataPack, 0, LEN_MAX);
    int index1 = ui->runModeCB->currentIndex();
    switch(index1) {

        case 0://停止服务
        data[0] = 0x21;
        data[1] = 0x60;
        data[2] = 0x90;
        data[3] = 0x91;
        data[4] = 0x81;
        data[5] = 0x81;
            break;

    case 1://双向受控
    data[0] = 0x21;
    data[1] = 0x60;
    data[2] = 0x90;
    data[3] = 0x91;
    data[4] = 0x81;
    data[5] = 0x83;
        break;

    case 2://维护模式
    data[0] = 0x21;
    data[1] = 0x60;
    data[2] = 0x90;
    data[3] = 0x91;
    data[4] = 0x83;
    data[5] = 0x82;
        break;

    case 4://受控进站
    data[0] = 0x21;
    data[1] = 0x60;
    data[2] = 0x90;
    data[3] = 0x91;
    data[4] = 0x81;
    data[5] = 0x81;
        break;

    case 5://受控出站
    data[0] = 0x21;
    data[1] = 0x60;
    data[2] = 0x90;
    data[3] = 0x91;
    data[4] = 0x81;
    data[5] = 0x83;
        break;

    case 6://受控进站 / 免费出站模式
    data[0] = 0x21;
    data[1] = 0x60;
    data[2] = 0x90;
    data[3] = 0x91;
    data[4] = 0x81;
    data[5] = 0x82;
        break;

    case 7://免费进站 / 受控出站模式
    data[0] = 0x21;
    data[1] = 0x60;
    data[2] = 0x90;
    data[3] = 0x91;
    data[4] = 0x81;
    data[5] = 0x83;
        break;

    case 8://免费进站模式
    data[0] = 0x21;
    data[1] = 0x60;
    data[2] = 0x90;
    data[3] = 0x91;
    data[4] = 0x81;
    data[5] = 0x81;
        break;

    case 9://免费出站模式
    data[0] = 0x21;
    data[1] = 0x60;
    data[2] = 0x90;
    data[3] = 0x91;
    data[4] = 0x81;
    data[5] = 0x82;
        break;

    case 10://双向免费模式
    data[0] = 0x21;
    data[1] = 0x60;
    data[2] = 0x90;
    data[3] = 0x91;
    data[4] = 0x81;
    data[5] = 0x82;
        break;









        default:
            break;

    }

    dataPro(dataPack,dataPack_len,data,sizeof(data));
    QByteArray ba((char*)dataPack, dataPack_len);


    execCmd(ba);
    //serial->write(ba);

}


void MainWindow::on_setModeBtn_clicked()
{

    unsigned char data[10];
    unsigned char dataPack[LEN_MAX];
    int dataPack_len = 0;

    memset(data, 0, sizeof(data));
    memset(dataPack, 0, LEN_MAX);
    data[0] = 0x21;
    data[1] = 0x60;
    int index1 = ui->runModeCB->currentIndex();
    switch(index1) {

        case 0://暂停服务
            data[2] = 0x90;
            data[3] =0x90;
            data[4] =0x80;
            data[5] =0x81;
            data[6] =0x90;
            data[7] =0x91;
            data[8] =0x80;
            data[9] =0x81;
          //  data[10] =0xA5;
          //  data[11] =0XB0;
          //  data[12] =0XC0;
            break;
        case 1://双门双向受控模式
            data[2] = 0x90;
            data[3] =0x90;
            data[4] =0x80;
            data[5] =0x83;
            data[6] =0x90;
            data[7] =0x91;
            data[8] =0x80;
            data[9] =0x83;
         //   data[10] =0xA5;
          //  data[11] =0XB0;
         //   data[12] =0XC0;
            break;
        case 2://维护模式
            data[2] = 0x90;
            data[3] =0x90;
            data[4] =0x82;
            data[5] =0x82;
            data[6] =0x90;
            data[7] =0x91;
            data[8] =0X82;
             data[9] =0X82;


            break;
        case 3://软件紧急模式
            data[2] = 0x90;
            data[3] =0x90;
            data[4] =0x82;
            data[5] =0x82;
            data[6] =0x90;
            data[7] =0x91;
           data[8] =0X88;
           data[9] =0X82;
            break;
        case 4://受控进站模式
        data[2] = 0x90;
        data[3] =0x90;
        data[4] =0x80;
        data[5] =0x83;
        data[6] =0x90;
        data[7] =0x91;
        data[8] =0x80;
        data[9] =0x81;
    //    data[10] =0xA5;
    //    data[11] =0XB2;
     //   data[12] =0XC0;
            break;
        case 5://受控出站模式
        data[2] = 0x90;
        data[3] =0x90;
        data[4] =0x80;
        data[5] =0x81;
        data[6] =0x90;
        data[7] =0x91;
        data[8] =0x80;
        data[9] =0x83;
    //    data[10] =0xA5;
   //     data[11] =0XB2;
    //    data[12] =0XC0;
        break;
        case 6://受控进站 / 免费出站模式
        data[2] = 0x90;
        data[3] =0x90;
        data[4] =0x80;
        data[5] =0x83;
        data[6] =0x90;
        data[7] =0x91;
        data[8] =0x80;
        data[9] =0x82;
    //    data[10] =0xA5;
    //    data[11] =0XB1;
     //   data[12] =0XC0;
        break;
       case 7://免费进站 / 受控出站模式
        data[2] = 0x90;
        data[3] =0x90;
        data[4] =0x80;
        data[5] =0x82;
        data[6] =0x90;
        data[7] =0x91;
        data[8] =0x80;
        data[9] =0x83;
     //   data[10] =0xA5;
    //    data[11] =0XB0;
     //   data[12] =0XC0;
        break;
       case 8://免费进站模式
        data[2] = 0x90;
        data[3] =0x90;
        data[4] =0x80;
        data[5] =0x82;
        data[6] =0x90;
        data[7] =0x91;
        data[8] =0x80;
        data[9] =0x81;
    //    data[10] =0xA5;
     //   data[11] =0XB2;
    //    data[12] =0XC0;
        break;
        case 9://免费出站模式
        data[2] = 0x90;
        data[3] =0x90;
        data[4] =0x80;
        data[5] =0x81;
        data[6] =0x90;
        data[7] =0x91;
        data[8] =0x80;
        data[9] =0x82;
    //    data[10] =0xA5;
   //     data[11] =0XB3;
   //     data[12] =0XC0;
        break;
    case 10:// 双向免费模式
        data[2] = 0x90;
        data[3] =0x90;
        data[4] =0x80;
        data[5] =0x82;
        data[6] =0x90;
        data[7] =0x91;
        data[8] =0x80;
        data[9] =0x82;
     //   data[10] =0xA8;
    //    data[11] =0XB2;
    //    data[12] =0XC0;
    break;
        default:
            break;

    }
    dataPro(dataPack,dataPack_len,data,sizeof(data));
    QByteArray ba((char*)dataPack, dataPack_len);

    execCmd(ba);
    //serial->write(ba);

}


void MainWindow::moduleTestCommand()
{
    unsigned char data[2];
    unsigned char dataPack[LEN_MAX];
    int dataPack_len = 0;
    memset(data, 0, sizeof(data));
    memset(dataPack, 0, LEN_MAX);
    int index1 = ui->testContentCB->currentIndex();
    switch(index1) {

        case 0://传感器测试命令
        data[0] = 0x21;
        data[1] = 0x75;
            break;
        default:
            break;

    }


    dataPro(dataPack, dataPack_len, data, sizeof(data));

    QByteArray ba((char*)dataPack, dataPack_len);

    execCmd(ba);
    //serial->write(ba);
}

void MainWindow::on_moduleTestBtn_clicked()
{

    int command = ui->testContentCB->currentIndex();
    if((command == 0)&&ui->sensorStatusCheckBox->isChecked()){
        connect(sensorStatusTimer, SIGNAL(timeout()), this, SLOT(moduleTestCommand()));
        sensorStatusTimer->start(500);
        moduleTestCommand();
    }

}


void MainWindow::on_polling_clicked(){
  unsigned char data[1];
  data[0]=0x01;
  QByteArray ba((char*)data, 1);
  execCmd(ba);
}
void MainWindow::on_auto_polling_clicked(){


    if(ui->auto_polling_B->isChecked()){
        connect(polltimer, SIGNAL(timeout()), this, SLOT(on_polling_clicked()));
        polltimer->start(500);
    }


}

void MainWindow::on_auto_polling_B_stateChanged(int status){
    if(!ui->auto_polling_B->isChecked()) {
        polltimer->stop();
        polltimer->disconnect();
    }

}

void MainWindow::on_pcm_polling_clicked(){
    if(ui->pcm_check->isChecked()){


            connect(pcmtimer, SIGNAL(timeout()), this, SLOT(on_getstatus_clicked()));
            pcmtimer->start(500);
        }




}

void MainWindow::on_pcm_check_stateChanged(int status){

    if(!ui->pcm_check->isChecked()) {
        pcmtimer->stop();
        pcmtimer->disconnect();
    }
}


/*void MainWindow::on_auto_test_clicked(){

    unsigned char data[6];
    unsigned char dataPack[LEN_MAX];
    int dataPack_len = 0;
    memset(data, 0, sizeof(data));
    memset(dataPack, 0, LEN_MAX);

    if(ui->auto_test_on->isChecked()){

        data[0] = 0x21;
        data[1] = 0x65;
        data[2] = 0x80;
        data[3] = 0x80;
        data[4] = 0x80;
        data[5] = 0x83;

    }
    else if (ui->auto_test_off->isChecked()) {
        data[0] = 0x21;
        data[1] = 0x65;
        data[2] = 0x80;
        data[3] = 0x80;
        data[4] = 0x80;
        data[5] = 0x80;
    }

    dataPro(dataPack, dataPack_len, data, sizeof(data));

    QByteArray ba((char*)dataPack, dataPack_len);

    execCmd(ba);

}

*/


void MainWindow::on_sensorStatusCheckBox_stateChanged(int status)
{
    if(!ui->sensorStatusCheckBox->isChecked()) {
        sensorStatusTimer->stop();
        sensorStatusTimer->disconnect();
    }
}



/*void MainWindow::on_light_switch_clicked(){

    unsigned char data[6];
    unsigned char dataPack[LEN_MAX];
    int dataPack_len = 0;

    memset(data, 0, sizeof(data));
    memset(dataPack, 0, LEN_MAX);
    data[0] = 0x21;
    data[1] = 0x60;
    int index1 = ui->runModeCB->currentIndex();

    switch (index1) {
    case 0:
        //暂停服务模式
         if(ui->AD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x80;
             data[5]=0x81;
         }

         if(ui->AD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x82;
             data[5]=0x81;

         }
         if(ui->AD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x90;
          data[4]=0x88;
          data[5]=0x81;
         }
         if(ui->BD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x80;
             data[5]=0x81;
         }

         if(ui->BD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x82;
             data[5]=0x81;

         }
         if(ui->BD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x91;
          data[4]=0x88;
          data[5]=0x81;
         }

      break;

    case 1:
        //双向受控
         if(ui->AD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x80;
             data[5]=0x83;
         }

         if(ui->AD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x82;
             data[5]=0x83;

         }
         if(ui->AD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x90;
          data[4]=0x88;
          data[5]=0x83;
         }

         if(ui->BD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x80;
             data[5]=0x83;
         }

         if(ui->BD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x82;
             data[5]=0x83;

         }
         if(ui->BD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x91;
          data[4]=0x88;
          data[5]=0x83;
         }

      break;


    case 2:
        //维护模式
         if(ui->AD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x80;
             data[5]=0x82;
         }

         if(ui->AD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x82;
             data[5]=0x82;

         }
         if(ui->AD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x90;
          data[4]=0x88;
          data[5]=0x82;
         }

         if(ui->BD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x80;
             data[5]=0x82;
         }

         if(ui->BD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x82;
             data[5]=0x82;

         }
         if(ui->BD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x91;
          data[4]=0x88;
          data[5]=0x82;
         }

      break;

    case 3:
        //软件紧急模式
         if(ui->AD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x80;
             data[5]=0x82;
         }

         if(ui->AD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x82;
             data[5]=0x82;

         }
         if(ui->AD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x90;
          data[4]=0x88;
          data[5]=0x82;
         }

         if(ui->BD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x80;
             data[5]=0x82;
         }

         if(ui->BD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x82;
             data[5]=0x82;

         }
         if(ui->BD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x91;
          data[4]=0x88;
          data[5]=0x82;
         }

      break;

    case 4:
        //受控进站
         if(ui->AD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x80;
             data[5]=0x83;
         }

         if(ui->AD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x82;
             data[5]=0x83;

         }
         if(ui->AD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x90;
          data[4]=0x88;
          data[5]=0x83;
         }

         if(ui->BD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x80;
             data[5]=0x81;
         }

         if(ui->BD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x82;
             data[5]=0x81;

         }
         if(ui->BD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x91;
          data[4]=0x88;
          data[5]=0x81;
         }

      break;

    case 5:
        //受控出站
         if(ui->AD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x80;
             data[5]=0x81;
         }

         if(ui->AD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x82;
             data[5]=0x81;

         }
         if(ui->AD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x90;
          data[4]=0x88;
          data[5]=0x81;
         }

         if(ui->BD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x80;
             data[5]=0x83;
         }

         if(ui->BD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x82;
             data[5]=0x83;

         }
         if(ui->BD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x91;
          data[4]=0x88;
          data[5]=0x83;
         }

      break;

    case 6:
        //受控进站 / 免费出站模式
         if(ui->AD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x80;
             data[5]=0x83;
         }

         if(ui->AD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x82;
             data[5]=0x83;

         }
         if(ui->AD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x90;
          data[4]=0x88;
          data[5]=0x83;
         }

         if(ui->BD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x80;
             data[5]=0x82;
         }

         if(ui->BD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x82;
             data[5]=0x82;

         }
         if(ui->BD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x91;
          data[4]=0x88;
          data[5]=0x82;
         }

      break;

    case 7:
        //免费进站 / 受控出站模式
         if(ui->AD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x80;
             data[5]=0x82;
         }

         if(ui->AD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x82;
             data[5]=0x82;

         }
         if(ui->AD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x90;
          data[4]=0x88;
          data[5]=0x82;
         }

         if(ui->BD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x80;
             data[5]=0x83;
         }

         if(ui->BD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x82;
             data[5]=0x83;

         }
         if(ui->BD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x91;
          data[4]=0x88;
          data[5]=0x83;
         }

      break;

    case 8:
        //免费进站
         if(ui->AD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x80;
             data[5]=0x82;
         }

         if(ui->AD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x82;
             data[5]=0x82;

         }
         if(ui->AD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x90;
          data[4]=0x88;
          data[5]=0x82;
         }

         if(ui->BD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x80;
             data[5]=0x81;
         }

         if(ui->BD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x82;
             data[5]=0x81;

         }
         if(ui->BD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x91;
          data[4]=0x88;
          data[5]=0x81;
         }

      break;

    case 9:
        //免费出站
         if(ui->AD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x80;
             data[5]=0x81;
         }

         if(ui->AD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x82;
             data[5]=0x81;

         }
         if(ui->AD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x90;
          data[4]=0x88;
          data[5]=0x81;
         }

         if(ui->BD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x80;
             data[5]=0x82;
         }

         if(ui->BD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x82;
             data[5]=0x82;

         }
         if(ui->BD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x91;
          data[4]=0x88;
          data[5]=0x82;
         }

      break;


    case 10:
        //双向免费
         if(ui->AD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x80;
             data[5]=0x82;
         }

         if(ui->AD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x82;
             data[5]=0x82;

         }
         if(ui->AD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x90;
          data[4]=0x88;
          data[5]=0x82;
         }

         if(ui->BD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x80;
             data[5]=0x82;
         }

         if(ui->BD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x82;
             data[5]=0x82;

         }
         if(ui->BD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x91;
          data[4]=0x88;
          data[5]=0x82;
         }

      break;
    default:
        break;
    }
    dataPro(dataPack,dataPack_len,data,sizeof(data));
    QByteArray ba((char*)dataPack, dataPack_len);

    execCmd(ba);

}

*/



void MainWindow::on_AD_switch_clicked(){
    unsigned char data[6];
    unsigned char dataPack[LEN_MAX];
    int dataPack_len = 0;

    memset(data, 0, sizeof(data));
    memset(dataPack, 0, LEN_MAX);
    data[0] = 0x21;
    data[1] = 0x60;
    int index1 = ui->runModeCB->currentIndex();

    switch (index1) {
    case 0:
        //暂停服务模式
         if(ui->AD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x80;
             data[5]=0x81;
         }

         if(ui->AD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x82;
             data[5]=0x81;

         }
         if(ui->AD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x90;
          data[4]=0x88;
          data[5]=0x81;
         }

      break;

    case 1:
        //双向受控
         if(ui->AD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x80;
             data[5]=0x83;
         }

         if(ui->AD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x82;
             data[5]=0x83;

         }
         if(ui->AD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x90;
          data[4]=0x88;
          data[5]=0x83;
         }


      break;


    case 2:
        //维护模式
         if(ui->AD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x80;
             data[5]=0x82;
         }

         if(ui->AD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x82;
             data[5]=0x82;

         }
         if(ui->AD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x90;
          data[4]=0x88;
          data[5]=0x82;
         }



      break;

    case 3:
        //软件紧急模式
         if(ui->AD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x80;
             data[5]=0x82;
         }

         if(ui->AD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x82;
             data[5]=0x82;

         }
         if(ui->AD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x90;
          data[4]=0x88;
          data[5]=0x82;
         }


      break;

    case 4:
        //受控进站
         if(ui->AD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x80;
             data[5]=0x83;
         }

         if(ui->AD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x82;
             data[5]=0x83;

         }
         if(ui->AD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x90;
          data[4]=0x88;
          data[5]=0x83;
         }



      break;

    case 5:
        //受控出站
         if(ui->AD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x80;
             data[5]=0x81;
         }

         if(ui->AD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x82;
             data[5]=0x81;

         }
         if(ui->AD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x90;
          data[4]=0x88;
          data[5]=0x81;
         }



      break;

    case 6:
        //受控进站 / 免费出站模式
         if(ui->AD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x80;
             data[5]=0x83;
         }

         if(ui->AD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x82;
             data[5]=0x83;

         }
         if(ui->AD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x90;
          data[4]=0x88;
          data[5]=0x83;
         }

      break;

    case 7:
        //免费进站 / 受控出站模式
         if(ui->AD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x80;
             data[5]=0x82;
         }

         if(ui->AD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x82;
             data[5]=0x82;

         }
         if(ui->AD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x90;
          data[4]=0x88;
          data[5]=0x82;
         }



      break;

    case 8:
        //免费进站
         if(ui->AD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x80;
             data[5]=0x82;
         }

         if(ui->AD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x82;
             data[5]=0x82;

         }
         if(ui->AD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x90;
          data[4]=0x88;
          data[5]=0x82;
         }



      break;

    case 9:
        //免费出站
         if(ui->AD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x80;
             data[5]=0x81;
         }

         if(ui->AD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x82;
             data[5]=0x81;

         }
         if(ui->AD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x90;
          data[4]=0x88;
          data[5]=0x81;
         }



      break;


    case 10:
        //双向免费
         if(ui->AD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x80;
             data[5]=0x82;
         }

         if(ui->AD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x90;
             data[4]=0x82;
             data[5]=0x82;

         }
         if(ui->AD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x90;
          data[4]=0x88;
          data[5]=0x82;
         }



      break;
    default:
        break;
    }
    dataPro(dataPack,dataPack_len,data,sizeof(data));
    QByteArray ba((char*)dataPack, dataPack_len);

    execCmd(ba);


}


void MainWindow::on_BD_switch_clicked(){

    unsigned char data[6];
    unsigned char dataPack[LEN_MAX];
    int dataPack_len = 0;

    memset(data, 0, sizeof(data));
    memset(dataPack, 0, LEN_MAX);
    data[0] = 0x21;
    data[1] = 0x60;
    int index1 = ui->runModeCB->currentIndex();

    switch (index1) {
    case 0:
        //暂停服务模式

         if(ui->BD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x80;
             data[5]=0x81;
         }

         if(ui->BD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x82;
             data[5]=0x81;

         }
         if(ui->BD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x91;
          data[4]=0x88;
          data[5]=0x81;
         }

      break;

    case 1:
        //双向受控


         if(ui->BD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x80;
             data[5]=0x83;
         }

         if(ui->BD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x82;
             data[5]=0x83;

         }
         if(ui->BD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x91;
          data[4]=0x88;
          data[5]=0x83;
         }

      break;


    case 2:
        //维护模式


         if(ui->BD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x80;
             data[5]=0x82;
         }

         if(ui->BD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x82;
             data[5]=0x82;

         }
         if(ui->BD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x91;
          data[4]=0x88;
          data[5]=0x82;
         }

      break;

    case 3:
        //软件紧急模式

         if(ui->BD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x80;
             data[5]=0x82;
         }

         if(ui->BD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x82;
             data[5]=0x82;

         }
         if(ui->BD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x91;
          data[4]=0x88;
          data[5]=0x82;
         }

      break;

    case 4:
        //受控进站


         if(ui->BD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x80;
             data[5]=0x81;
         }

         if(ui->BD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x82;
             data[5]=0x81;

         }
         if(ui->BD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x91;
          data[4]=0x88;
          data[5]=0x81;
         }

      break;

    case 5:
        //受控出站


         if(ui->BD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x80;
             data[5]=0x83;
         }

         if(ui->BD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x82;
             data[5]=0x83;

         }
         if(ui->BD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x91;
          data[4]=0x88;
          data[5]=0x83;
         }

      break;

    case 6:
        //受控进站 / 免费出站模式

         if(ui->BD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x80;
             data[5]=0x82;
         }

         if(ui->BD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x82;
             data[5]=0x82;

         }
         if(ui->BD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x91;
          data[4]=0x88;
          data[5]=0x82;
         }

      break;

    case 7:
        //免费进站 / 受控出站模式


         if(ui->BD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x80;
             data[5]=0x83;
         }

         if(ui->BD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x82;
             data[5]=0x83;

         }
         if(ui->BD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x91;
          data[4]=0x88;
          data[5]=0x83;
         }

      break;

    case 8:
        //免费进站

         if(ui->BD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x80;
             data[5]=0x81;
         }

         if(ui->BD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x82;
             data[5]=0x81;

         }
         if(ui->BD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x91;
          data[4]=0x88;
          data[5]=0x81;
         }

      break;

    case 9:
        //免费出站


         if(ui->BD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x80;
             data[5]=0x82;
         }

         if(ui->BD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x82;
             data[5]=0x82;

         }
         if(ui->BD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x91;
          data[4]=0x88;
          data[5]=0x82;
         }

      break;


    case 10:
        //双向免费


         if(ui->BD_M->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x80;
             data[5]=0x82;
         }

         if(ui->BD_R->isChecked()){

             data[2]=0x90;
             data[3]=0x91;
             data[4]=0x82;
             data[5]=0x82;

         }
         if(ui->BD_G->isChecked()){
        //   21 60 90 90 88 81 A8 B8 C0

          data[2]=0x90;
          data[3]=0x91;
          data[4]=0x88;
          data[5]=0x82;
         }

      break;
    default:
        break;
    }
    dataPro(dataPack,dataPack_len,data,sizeof(data));
    QByteArray ba((char*)dataPack, dataPack_len);

    execCmd(ba);

}



void MainWindow::on_reser_alarm_clicked(){

    unsigned char data[11];
    unsigned char dataPack[LEN_MAX];
    int dataPack_len = 0;
    memset(data, 0, sizeof(data));
    memset(dataPack, 0, LEN_MAX);
    data[0] = 0x21;
    data[1] = 0x60;
    data[2] = 0x90;
    data[3] = 0x94;
    data[4] = 0x80;
    data[5] = 0x80;
    data[6] = 0x80;
    data[7] = 0x80;
    data[8] = 0xa8;
    data[9] = 0xb5;
    data[10] = 0xc0;



   //dataPro(dataPack, dataPack_len, data, sizeof(data));

    QByteArray ba((char*)data, 11);
    execCmd(ba);
    //serial->write(ba);


}


void MainWindow::on_getstatus_clicked(){


    unsigned char data[31];
    unsigned char dataPack[LEN_MAX];
    int dataPack_len = 0;
    memset(data, 0, sizeof(data));
    memset(dataPack, 0, LEN_MAX);
    data[0] = 0x21;
    data[1] = 0x70;
    data[2]=0x90;
    data[3]=0x90;
    data[4]=0x90;
    data[5]=0x91;
    data[6]=0x90;
    data[7]=0x92;
    data[8]=0x90;
    data[9]=0x93;
    data[10]=0x90;
    data[11]=0x94;
    data[12]=0x90;
    data[13]=0x95;
    data[14]=0x90;
    data[15]=0x96;
    data[16]=0x90;
    data[17]=0x97;
    data[18]=0x90;
    data[19]=0x98;
    data[20]=0x90;
    data[21]=0x99;
    data[22]=0x90;
    data[23]=0x9a;
    data[24]=0x90;
    data[25]=0x9b;
    data[26]=0x90;
    data[27]=0x9c;

    data[28] = 0xa9;
    data[29] = 0xbd;
    data[30] = 0xc0;

 //  dataPro(dataPack, dataPack_len, data, sizeof(data));

    QByteArray ba((char*)data, 31);
    execCmd(ba);
}
