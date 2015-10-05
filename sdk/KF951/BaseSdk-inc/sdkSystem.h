/********************************************************************
文件名 : sdkSystem.h
描  述 : 系统模块接口函数
版  权 : 长城开发
作  者 : 张友刚
修改记录:
    日期              修改人  修改内容
    2013-12-24 15:04  张友刚  创建
********************************************************************/
#ifndef BASE_SDKSYSTEM_H
#define BASE_SDKSYSTEM_H

#ifdef __cplusplus
    extern "C" {
#endif

//指示灯ID
#define SDK_LED_BLUE     0x01
#define SDK_LED_YELLOW   0x02
#define SDK_LED_GREEN    0x04
#define SDK_LED_RED      0x08
#define SDK_LED_ALL      0x0F

//Specical LED
#define SDK_LED_KEY     0x10    //keyboard backlight lamp
#define SDK_LED_CASH    0x20    //bill-checking device lamp
#define SDK_LED_FLASH   0x40    //camera flash lamp

typedef struct
{
    u8 szBootVer[21]; //Bootloader版本号
    u8 szKernelVer[21]; //内核版本号
    u8 szRootfs[21]; //文件系统版本号
    u8 szLibDev[21]; //底层库版本
    u8 szS2BLVer[21]; //s2bl版本号
    u8 szRFU[32];//保留
}T_SDK_SYS_VER;


typedef struct
{
    s8  cModleInfo[16];          //设备型号
    s8  cTermialTYpe;            //终端类型
                                 // 1 - 台式一体机
                                 // 2 - 移动手持机
                                 // 3 - IC卡读卡器（KF323）
    s8  cPrintType;             //打印机类型
                                //'S'－针式打印机  'T'－热敏打印机
    s8  cModemType;            //MODEM模块配置信息
                                // 0－不支持MODEM通信模块
                                // 其它－MODEM模块型号编码
                                //   0x01-33.6k/9600
    s8  cModemSyncHightSpeed;   //MODEM最高同步速率信息
                                // 1--1200  2--2400  3--9600  4--14400  0--不支持
    s8  cModemAsyncHightSpeed;  //MODEM最高异步速率信息
                                // 1－1200    2－2400    3－4800    4－7200
                                // 5－9600    6－12000   7－14400   8－19200
                                // 9－24000   10－26400  11－28800  12－31200
                                // 13－33600  14－48000  15－56000   0 - 不支持
    s8  cPCIInfo;            //PCI配置信息
                            // 0－不支持内置PCI安全模块
                            // 其它－支持内置PCI安全模块（版本编码）
    s8  cUSBHostInfo;         //USB主机（HOST）配置信息
                            // 0－不支持USB主机接口
                            // 其它－USB主机接口版本编码（如支持USB1.1，USB2.0，USB-OTG等）
    s8  cSlaveUSBInfo;      //USB设备配置信息
                            // 0－不支持从USB接口
                            // 其它－USB设备接口版本编码
    s8    cEthernetInfo;   //LAN（TCP/IP）模块配置信息
                            // 0－不支持TCP/IP模块
                            // 其它－TCP/IP模块版本编码
    s8    cGPRSInfo;       //GPRS模块配置信息
                            // 0－不支持GPRS模块
                            // 其它－GPRS模块版本编码
    s8    cCDMAInfo;       //CDMA模块配置信息
                            // 0－不支持CDMA模块
                            // 其它－CDMA模块版本编码
    s8    cWIFIInfo;       //WI-FI模块配置信息
                            // 0－不支持WI-FI模块
                            // 其它－WI-FI模块版本编码
    s8    cContactlessInfo;    //非接触式读卡模块配置信息
                            // 0－不支持非接触式读卡模块
                            // 其它－非接触式读卡模块版本编码
    s8    cWCDMAInfo;     //WCDMA模块配置信息
                            // 0－不支持WCDMA模块
                            // 其它－WCDMA模块版本编码
    s8    cWirelessModuleInfo;     //无线模块类型
                            // 0－不支持无线模块
                            // 其它－无线模块类型，1:Telit; 2:经纬; 3:移远; 4:华为; ...
    s8    cBluetoothInfo;    //蓝牙模块配置信息
                            // 0－不支持蓝牙模块
                            // 其它－蓝牙模块版本编码
    s8    cFingerprintInfo;   //指纹模块配置信息
                            // 0－不支持指纹模块
                            // 其它－指纹模块版本编码
    s8    cBarcodeScanInfo;  //扫描枪模块配置信息
                            // 0－不支持扫描枪模块
                            // 其它－扫描枪模块版本编码
    s8    cCameraInfo;     //摄像头模块配置信息
                            // 0－不支持摄像头模块
                            // 其它－摄像头模块版本编码
    s8    cGpsInfo;        //GPS模块配置信息
                            // 0－不支持GPS模块
                            // 其它－GPS模块版本编码
    s8    cGeoSensorInfo;     //陀螺仪模块配置信息
                            // 0－不支持陀螺仪模块
                            // 其它－陀螺仪模块版本编码
    s8    cReserve2;       //保留
    s8    cReserved[8];    //保留
} T_SDK_SYS_DEVVER;

typedef struct
{
    u32 uiErrNo;            //错误码
    s8  szErrorInfo[65];    //错误描述信息
}T_SDK_SYS_ErrInfo;

typedef enum
{
	SDK_LANG_CHINESE,   //Chinese
	SDK_LANG_ENGLISH,   //English
}E_SDK_LANGUAGE;

s32 sdkSysReadSDKVer(u8 *pszVersion);
s32 sdkSysGetSn(u8 *pszSerialNo);
s32 sdkSysGetVer(T_SDK_SYS_VER *ptVersion);
s32 sdkSysGetConfig(T_SDK_SYS_DEVVER *ptConfig);
s32 sdkSysInit(u8 *pcDevStatus);
s32 sdkSysSetTime(u8 *pbcdTime);
s32 sdkSysGetTime(u8 *pbcdTime);
u32 sdkSysGetTimerCount(void);
BOOL sdkSysGetTimerEnd(u32 uiTimeId,u32 uiOverTime);
void sdkSysSleep(u32 uiOverTime);
//
s32 sdkSysBuzz(u8 ucType);
s32 sdkSysGetMotion(s32 *pXaxis, s32 *pYaxis, s32 *pZaxis);
s32 sdkSysLedLightOn(u8 ucLedNumber);
s32 sdkSysLedLightOff(u8 ucLedNumber);
s32 sdkSysGetPowerStatus(s32 *pnPercent);
s32 sdkSysGetVolt(void);
s32 sdkSysPowerIdle(u8 ucWakeupMode, u32 uiTimeOutMs);
void sdkSysSetPowerIdleTime(u32 ucEnterSleepModeTime);
s32 sdkSysGetPowerIdleTime(void);
s32 sdkSysPowerOff(void);
s32 sdkSysReset(void);
s32 sdkSysUpdate(u32 uiUpdataMode);
//
s32 sdkSysGetLastErr(u8 *pszErrorInfo);
u8 sdkSysGetLanguage(void);
void sdkSysSetLanguage(u8 ucLangType);
s8* sdkSysGetModelName(void);
void sdkSysSetQTFlag(u8 ucQTFlag);
u8 sdkSysGetQTFlag(void);

#ifdef __cplusplus
    }
#endif

#endif

