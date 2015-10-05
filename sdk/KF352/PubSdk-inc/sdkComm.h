/********************************************************************
�ļ��� : sdkComm.h
��  �� : ͨѶģ��
��  Ȩ : ���ǿ���
��  �� : ��ΰ��
�޸ļ�¼:
    ����              �޸���  �޸�����
    2014-02-18 09:51  ��ΰ��  ����
********************************************************************/
#ifndef PUBLIC_SDKCOMM_H_
#define PUBLIC_SDKCOMM_H_

#ifdef __cplusplus
    extern "C" {
#endif

//ͨѶ��ʽ
typedef enum
{
    SDK_COMM_MODEM = 1,             //modem ����
    SDK_COMM_GPRS,                  //GPRS ����
    SDK_COMM_CDMA,                  //CDMA ����
    SDK_COMM_ETHERNET,              //��̫��
    SDK_COMM_WIFI,                  //WIFI
}E_SDK_COMM_COMMMODE;

//���� PPP ����
typedef struct
{
    BOOL    bIsUsePpp;              //�Ƿ�ʹ��Ppp  0-��ʹ�ã�1 ʹ��
    BOOL    bIsNeedUser;            //�Ƿ���Ҫ�û�  0-����Ҫ��1 ��Ҫ
    u8      szUsername[51];         //�û���
    u8      szPassword[51];         //����
    u8      szGprsApn[51];          //APN ����
    u8      szDialNum[16];          //�κź��룬��CDMA��Ч
}T_SDK_COMM_PPPWIRELESS;

//wifi����
typedef struct 
{
    u8      szSSID[64];             //SSID             
    u8      szPassword[51];         //����
}T_SDK_COMM_WIFI;


//��̫������
typedef struct
{
    u8      szNetClientIP[16];      //���� IP ��ַ
    u8      szNetGate[16];          //��������
    u8      szNetMask[16];          //������������
    u8      szDnsIP[16];            //DNS ������ IP
    BOOL    bIsDhcp;                //�Ƿ�ʹ�� DHCP
}T_SDK_COMM_LANPARAM;

//MODEM ��չ����
typedef struct
{
    BOOL    bIsCheckPhone;          //�Ƿ񲢻����  0-����Ҫ��1 ��ҪĬ����Ҫ
    u8      ucDtmfTime;             //DTMF˫����Ƶ����ͨ������ʱ�� (��λΪ ms  Ĭ�� 100  ��ʾ 100ms)
    BOOL    bIsCheckDialTone;       //�Ƿ��Ⲧ����  0-����Ҫ��1 ��ҪĬ����Ҫ
    u8      ucDelayBeforeDial;      //����Ⲧ����ʱ����ǰ����ʱʱ��  (��λΪ s  Ĭ�� 1  ��ʾ 1s)
    u16     usChkToneTime;          //��Ⲧ�����ȶ�ʱ��(ȡֵ��Χ��10-255Ĭ��ֵ��[90]��λ��0.01��)
    u16     usChkAnswerToneTime;    //���Ӧ�����ȶ�ʱ��(ȡֵ��Χ��10-255Ĭ��ֵ��[90]��λ��0.01��)
    u16     usWaveLostTime;         //�ز���ʧʱ��(��λΪ ms  Ĭ�� 500  ��ʾ500ms)
    u8      ucSendLevel;            //���͵�ƽ  �����ͷ����ϵ��ź�˥������
    u8      ucDialMode;             //����ģʽ:0x00: DTMF 0x01:PULSE
    u8      ucDialTimeout;          //���ŵȴ�ʱ�䣬��λ���룬0��ʾ���ųɹ����������أ�Ĭ��Ϊ0.
    u8      ucRegion;               //���������룬��ͬ���һ�����modem��·��ʽ���ܲ�һ��
    u8      ucRuf[8];               //����
}T_SDK_COMM_MODEMEXPARAM;

//MODEM ����
typedef struct
{
    BOOL    bLinkMode;              //0 -  ͬ��  1 -  �첽
    u8      asOutLineNo[32+1];         //���ߺ���� 32 λ
    u8      asPhone[3][27+1];         //�绰����� 27 λ
    BOOL    bIsNeedExParam;         //�Ƿ���Ҫ��չ����  0-����Ҫ��1 -  ��Ҫ
    T_SDK_COMM_MODEMEXPARAM  tModemExParam;  //��չ����
}T_SDK_COMM_MODEMPARAM;

//��������������
typedef struct
{
    u8      szServerIP[64];         //������ IP ��ַ
    u32     uiPort;                 //�������˿ں�
}T_SDK_COMM_SERVERADDRESS;

typedef struct
{
    E_SDK_COMM_COMMMODE         eMode;              //ͨѶ��ʽ
    u8                          ucReDialTimes;      //�ز�����
    u8                          ucDialTime;         //����ʱ�����Ϊ��λΪ  0 Ĭ�� 60000ms
    BOOL                        bSocketConnectMode; //Socket ���ӷ�ʽ  1:������  0:������
    T_SDK_COMM_MODEMPARAM       tModemInfo ;        //���� MODEM ����
    T_SDK_COMM_PPPWIRELESS      tPppWireLessInfo;   //PPP ���߲���
    T_SDK_COMM_LANPARAM         tLanInfo ;          //LAN ����
    T_SDK_COMM_WIFI             tWifiInfo;          //wifi����
    T_SDK_COMM_SERVERADDRESS    tServerInfo;        //����������
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
