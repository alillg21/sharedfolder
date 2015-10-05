/********************************************************************
文件名 :
描  述 :
版  权 : 深圳长城开发
作  者 : 吴伟伟
修改记录:
    日期              修改人  修改内容
    2013-12-31 13:03  吴伟伟  创建
********************************************************************/
#ifndef BASE_SDKMODEM_H_
#define BASE_SDKMODEM_H_

#ifdef __cplusplus
    extern "C" {
#endif

//modem状态：
#define SDK_MDM_STATUS_NOT_INIT      0x01		//modem未初始化
#define SDK_MDM_STATUS_IDLE          0x02		//modem空闲
#define SDK_MDM_STATUS_DIALING       0x03		//modem拨号中
#define SDK_MDM_STATUS_ON_LINE       0x04    	//modem在线连接状态
#define SDK_MDM_STATUS_ON_HOOKING    0x05		//modem正在挂机
#define SDK_MDM_STATUS_INVALID       0x06		//modem失效状态


//MODEM 扩展参数
typedef struct
{
    BOOL    bIsCheckPhone;      //是否并机检测  0-不需要，1 需要默认需要
    u8      ucDtmfTime;         //DTMF双音多频拨号通断周期时间 (单位为 ms  默认 100  表示 100ms)
    BOOL    bIsCheckDialTone;   //是否检测拨号音  0-不需要，1 需要默认需要  预留
    u8      ucDelayBeforeDial;  //不检测拨号音时拨号前的延时时间  (单位为 s  默认 1  表示 1s)
    u16     usChkToneTime;      //检测拨号音稳定时间(取值范围：10-255     默认值：[90]        单位：0.01秒)
    u16     usChkAnswerToneTime;//检测应答音稳定时间(取值范围：10-255       默认值：[90]        单位：0.01秒)
    u16     usWaveLostTime;     //载波丢失时间(单位为 ms  默认 500  表示 500ms)
    u8      ucSendLevel;        //发送电平  （发送方向上的信号衰减？）
    u8      ucDialMode;         //拨号模式:0x00: DTMF 0x01:PULSE
    u32     uiDialBaud;         //拨号波特率，1200,2400,…
    u8      ucDialTimeout;      //拨号等待时间，单位：秒，0表示拨号成功后立即返回，默认为0.
    u8      ucRegion;           //国家区域码，不同国家或地域的modem线路制式可能不一样
    u8      ucRuf[8];           //保留
} T_SDK_MODEM_EXPARAM;

//MODEM 参数
typedef struct
{
    BOOL bLinkMode;                //0 -  同步  1 -  异步
    u8  asOutLineNo[16+1];              //外线号码不超过16
    u8  asPhone[3][28];              //电话号码最长 25 位
    BOOL bIsNeedExParam;            //是否需要扩展参数  0-不需要，1- 需要
    T_SDK_MODEM_EXPARAM tModemExParam;  //扩展参数
} T_SDK_MODEM_PARAM;

s32 sdkModemOpen(void);
s32 sdkModemClose(void);
s32 sdkModemReadParam(T_SDK_MODEM_PARAM *ptModemParam);
s32 sdkModemSetParam(const T_SDK_MODEM_PARAM *ptModemParam);
s32 sdkModemStart(void);
s32 sdkModemPre(void);
s32 sdkModemSendData(u8 *pucData,u32 uiDataLen);
s32 sdkModemRecvData(u8 *pucData,u32 puiDataLen);
s32 sdkModemClearLink(void);

#ifdef __cplusplus
    }
#endif

#endif

