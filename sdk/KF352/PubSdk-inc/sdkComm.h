/********************************************************************
文件名 : sdkComm.h
描  述 : 通讯模块
版  权 : 长城开发
作  者 : 陈伟明
修改记录:
    日期              修改人  修改内容
    2014-02-18 09:51  陈伟明  创建
********************************************************************/
#ifndef PUBLIC_SDKCOMM_H_
#define PUBLIC_SDKCOMM_H_

#ifdef __cplusplus
    extern "C" {
#endif

//通讯方式
typedef enum
{
    SDK_COMM_MODEM = 1,             //modem 拨号
    SDK_COMM_GPRS,                  //GPRS 无线
    SDK_COMM_CDMA,                  //CDMA 无线
    SDK_COMM_ETHERNET,              //以太网
    SDK_COMM_WIFI,                  //WIFI
}E_SDK_COMM_COMMMODE;

//无线 PPP 参数
typedef struct
{
    BOOL    bIsUsePpp;              //是否使用Ppp  0-不使用，1 使用
    BOOL    bIsNeedUser;            //是否需要用户  0-不需要，1 需要
    u8      szUsername[51];         //用户名
    u8      szPassword[51];         //密码
    u8      szGprsApn[51];          //APN 名称
    u8      szDialNum[16];          //拔号号码，对CDMA有效
}T_SDK_COMM_PPPWIRELESS;

//wifi参数
typedef struct 
{
    u8      szSSID[64];             //SSID             
    u8      szPassword[51];         //密码
}T_SDK_COMM_WIFI;


//以太网参数
typedef struct
{
    u8      szNetClientIP[16];      //本地 IP 地址
    u8      szNetGate[16];          //本地网关
    u8      szNetMask[16];          //本地子网掩码
    u8      szDnsIP[16];            //DNS 服务器 IP
    BOOL    bIsDhcp;                //是否使用 DHCP
}T_SDK_COMM_LANPARAM;

//MODEM 扩展参数
typedef struct
{
    BOOL    bIsCheckPhone;          //是否并机检测  0-不需要，1 需要默认需要
    u8      ucDtmfTime;             //DTMF双音多频拨号通断周期时间 (单位为 ms  默认 100  表示 100ms)
    BOOL    bIsCheckDialTone;       //是否检测拨号音  0-不需要，1 需要默认需要
    u8      ucDelayBeforeDial;      //不检测拨号音时拨号前的延时时间  (单位为 s  默认 1  表示 1s)
    u16     usChkToneTime;          //检测拨号音稳定时间(取值范围：10-255默认值：[90]单位：0.01秒)
    u16     usChkAnswerToneTime;    //检测应答音稳定时间(取值范围：10-255默认值：[90]单位：0.01秒)
    u16     usWaveLostTime;         //载波丢失时间(单位为 ms  默认 500  表示500ms)
    u8      ucSendLevel;            //发送电平  （发送方向上的信号衰减？）
    u8      ucDialMode;             //拨号模式:0x00: DTMF 0x01:PULSE
    u8      ucDialTimeout;          //拨号等待时间，单位：秒，0表示拨号成功后立即返回，默认为0.
    u8      ucRegion;               //国家区域码，不同国家或地域的modem线路制式可能不一样
    u8      ucRuf[8];               //保留
}T_SDK_COMM_MODEMEXPARAM;

//MODEM 参数
typedef struct
{
    BOOL    bLinkMode;              //0 -  同步  1 -  异步
    u8      asOutLineNo[32+1];         //外线号码最长 32 位
    u8      asPhone[3][27+1];         //电话号码最长 27 位
    BOOL    bIsNeedExParam;         //是否需要扩展参数  0-不需要，1 -  需要
    T_SDK_COMM_MODEMEXPARAM  tModemExParam;  //扩展参数
}T_SDK_COMM_MODEMPARAM;

//服务器参数类型
typedef struct
{
    u8      szServerIP[64];         //服务器 IP 地址
    u32     uiPort;                 //服务器端口号
}T_SDK_COMM_SERVERADDRESS;

typedef struct
{
    E_SDK_COMM_COMMMODE         eMode;              //通讯方式
    u8                          ucReDialTimes;      //重拨次数
    u8                          ucDialTime;         //拨号时间毫秒为单位为  0 默认 60000ms
    BOOL                        bSocketConnectMode; //Socket 连接方式  1:短连接  0:长连接
    T_SDK_COMM_MODEMPARAM       tModemInfo ;        //拨号 MODEM 参数
    T_SDK_COMM_PPPWIRELESS      tPppWireLessInfo;   //PPP 无线参数
    T_SDK_COMM_LANPARAM         tLanInfo ;          //LAN 参数
    T_SDK_COMM_WIFI             tWifiInfo;          //wifi参数
    T_SDK_COMM_SERVERADDRESS    tServerInfo;        //服务器参数
}T_SDK_COMM_COMMPARAM;


s32 sdkCommInit(const T_SDK_COMM_COMMPARAM *pstCommParam);
s32 sdkCommPre(void);
s32 sdkCommLink(void);
s32 sdkCommDelLink(void);
s32 sdkCommSendData(const u8 *phexData, u32 uiDataLen);
s32 sdkCommRecvData(u8 * phexData, u32 uiDataLen);
s32 sdkUartGetNum(void);


#ifdef __cplusplus
    }
#endif

#endif
