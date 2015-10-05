/********************************************************************
文件名 : sdkSys.h
描  述 : 系统启动及退出
版  权 : 长城开发
作  者 : 卢裕燕
修改记录: 
    日期              修改人  修改内容
    2014-02-18 10:39  卢裕燕  创建
********************************************************************/
#ifndef PUBLIC_SDKSYS_H_
#define PUBLIC_SDKSYS_H_

#ifdef __cplusplus
    extern "C" {
#endif

#define SYS_INI_GPRS    0x01
#define SYS_INI_CDMA    0x02
#define SYS_INI_WIFI    0x03
#define SYS_INI_MODEM   0x04

typedef struct
{
    u8 ucKeyboard;      //键盘,1表示成功，2表示失败
    u8 ucLCD;           //LCD,1表示成功，2表示失败
    u8 ucPrint;         //打印,1表示成功，2表示失败
    u8 ucMagCard;       //磁条卡,1表示成功，2表示失败
    u8 ucSerialPort;    //串口,1表示成功，2表示失败
    u8 ucInsertCard;    //接触式IC卡,1表示成功，2表示失败
    u8 ucMFC;           //非接,1表示成功，2表示失败
    u8 ucPED;           //密码键盘，1表示成功，2表示失败
    u8 ucCommunica;     //通讯方式，传入的通讯模式，0表示没有传入通讯模式，1表示成功，2表示失败    
}T_SDK_SYS_STATUS;

s32 sdkSysStart(u8 ucMode);
s32 sdkSysQuit(void);
s32 sdkSysGetPubVer(u8 *pszVersion);
s32 sdkSysGetStatus(T_SDK_SYS_STATUS *pstStatus);

#ifdef __cplusplus
    }
#endif

#endif

