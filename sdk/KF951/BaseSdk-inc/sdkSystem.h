/********************************************************************
�ļ��� : sdkSystem.h
��  �� : ϵͳģ��ӿں���
��  Ȩ : ���ǿ���
��  �� : ���Ѹ�
�޸ļ�¼:
    ����              �޸���  �޸�����
    2013-12-24 15:04  ���Ѹ�  ����
********************************************************************/
#ifndef BASE_SDKSYSTEM_H
#define BASE_SDKSYSTEM_H

#ifdef __cplusplus
    extern "C" {
#endif

//ָʾ��ID
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
    u8 szBootVer[21]; //Bootloader�汾��
    u8 szKernelVer[21]; //�ں˰汾��
    u8 szRootfs[21]; //�ļ�ϵͳ�汾��
    u8 szLibDev[21]; //�ײ��汾
    u8 szS2BLVer[21]; //s2bl�汾��
    u8 szRFU[32];//����
}T_SDK_SYS_VER;


typedef struct
{
    s8  cModleInfo[16];          //�豸�ͺ�
    s8  cTermialTYpe;            //�ն�����
                                 // 1 - ̨ʽһ���
                                 // 2 - �ƶ��ֳֻ�
                                 // 3 - IC����������KF323��
    s8  cPrintType;             //��ӡ������
                                //'S'����ʽ��ӡ��  'T'��������ӡ��
    s8  cModemType;            //MODEMģ��������Ϣ
                                // 0����֧��MODEMͨ��ģ��
                                // ������MODEMģ���ͺű���
                                //   0x01-33.6k/9600
    s8  cModemSyncHightSpeed;   //MODEM���ͬ��������Ϣ
                                // 1--1200  2--2400  3--9600  4--14400  0--��֧��
    s8  cModemAsyncHightSpeed;  //MODEM����첽������Ϣ
                                // 1��1200    2��2400    3��4800    4��7200
                                // 5��9600    6��12000   7��14400   8��19200
                                // 9��24000   10��26400  11��28800  12��31200
                                // 13��33600  14��48000  15��56000   0 - ��֧��
    s8  cPCIInfo;            //PCI������Ϣ
                            // 0����֧������PCI��ȫģ��
                            // ������֧������PCI��ȫģ�飨�汾���룩
    s8  cUSBHostInfo;         //USB������HOST��������Ϣ
                            // 0����֧��USB�����ӿ�
                            // ������USB�����ӿڰ汾���루��֧��USB1.1��USB2.0��USB-OTG�ȣ�
    s8  cSlaveUSBInfo;      //USB�豸������Ϣ
                            // 0����֧�ִ�USB�ӿ�
                            // ������USB�豸�ӿڰ汾����
    s8    cEthernetInfo;   //LAN��TCP/IP��ģ��������Ϣ
                            // 0����֧��TCP/IPģ��
                            // ������TCP/IPģ��汾����
    s8    cGPRSInfo;       //GPRSģ��������Ϣ
                            // 0����֧��GPRSģ��
                            // ������GPRSģ��汾����
    s8    cCDMAInfo;       //CDMAģ��������Ϣ
                            // 0����֧��CDMAģ��
                            // ������CDMAģ��汾����
    s8    cWIFIInfo;       //WI-FIģ��������Ϣ
                            // 0����֧��WI-FIģ��
                            // ������WI-FIģ��汾����
    s8    cContactlessInfo;    //�ǽӴ�ʽ����ģ��������Ϣ
                            // 0����֧�ַǽӴ�ʽ����ģ��
                            // �������ǽӴ�ʽ����ģ��汾����
    s8    cWCDMAInfo;     //WCDMAģ��������Ϣ
                            // 0����֧��WCDMAģ��
                            // ������WCDMAģ��汾����
    s8    cWirelessModuleInfo;     //����ģ������
                            // 0����֧������ģ��
                            // ����������ģ�����ͣ�1:Telit; 2:��γ; 3:��Զ; 4:��Ϊ; ...
    s8    cBluetoothInfo;    //����ģ��������Ϣ
                            // 0����֧������ģ��
                            // ����������ģ��汾����
    s8    cFingerprintInfo;   //ָ��ģ��������Ϣ
                            // 0����֧��ָ��ģ��
                            // ������ָ��ģ��汾����
    s8    cBarcodeScanInfo;  //ɨ��ǹģ��������Ϣ
                            // 0����֧��ɨ��ǹģ��
                            // ������ɨ��ǹģ��汾����
    s8    cCameraInfo;     //����ͷģ��������Ϣ
                            // 0����֧������ͷģ��
                            // ����������ͷģ��汾����
    s8    cGpsInfo;        //GPSģ��������Ϣ
                            // 0����֧��GPSģ��
                            // ������GPSģ��汾����
    s8    cGeoSensorInfo;     //������ģ��������Ϣ
                            // 0����֧��������ģ��
                            // ������������ģ��汾����
    s8    cReserve2;       //����
    s8    cReserved[8];    //����
} T_SDK_SYS_DEVVER;

typedef struct
{
    u32 uiErrNo;            //������
    s8  szErrorInfo[65];    //����������Ϣ
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

