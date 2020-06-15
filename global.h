#ifndef GLOBAL_H
#define GLOBAL_H

#include <QMainWindow>


#define STX 0X02
#define ETX 0X03
#define DLE 0x10

#define LEN_MAX        40
#define SEND_STX  0x21
#define RECV_STX_DATE  0x41
#define SEND_ETX  0xC0
#define RECV_ETX_DATE  0xE5
#define SEND_CMD  0x60
#define RECV_CMD  0x70
#define DATA_ID   0x80
#define REG_ID	  0x90
#define HIGH_CHK  0xA0
#define LOW_CHK   0xB0

#define DLE_STX     0X02
#define DLE_ETX     0X03
#define DLE_DLE     0X10

//串口通讯中的通讯状态
#define RECV_DLE               0
#define RECV_DLE_NAK           1
#define RECV_STX               0
#define RECV_LEN               3
#define RECV_ETX               4
#define RECV_DATA              5
#define RECV_DATA_DLE          6
#define RECV_END               7
//end 串口通讯中的通讯状态


#define DEAL_DATA_SIZE 1024

    enum				///
    {
        PollingCmd = 0x01,

        RegSetCmd = 0x60,
        TestSetCmd = 0x65,
        ParamSetCmd = 0x68,

        RegReqCmd = 0x70,
        IdReqCmd = 0x71,
        SensorReqCmd = 0x75,
        ParamReqCmd = 0x78
    };

/*命令码*/
#define StatusQuery 0x81 //状态查询命令
#define ParaSetCmd  0x82 //参数设置命令
#define AuthorizedOrder 0x83 //通行授权命令
#define ModeSet 0x84 //模式设置命令
#define ClearRemainNumber 0x85 //清除剩余人数命令
#define ModeTestCmd 0x86 //模块测试命令
#define VersionQuery 0x87 //版本查询命令
#define ParamQuery 0x88 //参数查询命令
#define DirectionalLightSet 0x89//方向指示灯设置命令
#define FreeModeSet 0x90 //自由通行模式设置命令
#define UpdateFirmware 0x8a //更新 firmware 申请
#define EnsureWriteFileSize 0x8b //确认烧写文件大小
#define BootloaderSendData 0x8c //Bootloader发送数据
#define BootloaderSendDataEnd 0x8d //Bootloader发送数据完毕
#define ChangeToBootloaderMode 0x8e //切换到 Bootloader 模式


#endif // GLOBAL_H

