/********************************************************************
�ļ��� :
��  �� :
��  Ȩ : ���ڳ��ǿ���
��  �� : ��ΰΰ
�޸ļ�¼:
    ����              �޸���  �޸�����
    2013-12-31 13:03  ��ΰΰ  ����
********************************************************************/
#ifndef BASE_SDKMODEM_H_
#define BASE_SDKMODEM_H_

#ifdef __cplusplus
    extern "C" {
#endif

//modem״̬��
#define SDK_MDM_STATUS_NOT_INIT      0x01		//modemδ��ʼ��
#define SDK_MDM_STATUS_IDLE          0x02		//modem����
#define SDK_MDM_STATUS_DIALING       0x03		//modem������
#define SDK_MDM_STATUS_ON_LINE       0x04    	//modem��������״̬
#define SDK_MDM_STATUS_ON_HOOKING    0x05		//modem���ڹһ�
#define SDK_MDM_STATUS_INVALID       0x06		//modemʧЧ״̬


//MODEM ��չ����
typedef struct
{
    BOOL    bIsCheckPhone;      //�Ƿ񲢻����  0-����Ҫ��1 ��ҪĬ����Ҫ
    u8      ucDtmfTime;         //DTMF˫����Ƶ����ͨ������ʱ�� (��λΪ ms  Ĭ�� 100  ��ʾ 100ms)
    BOOL    bIsCheckDialTone;   //�Ƿ��Ⲧ����  0-����Ҫ��1 ��ҪĬ����Ҫ  Ԥ��
    u8      ucDelayBeforeDial;  //����Ⲧ����ʱ����ǰ����ʱʱ��  (��λΪ s  Ĭ�� 1  ��ʾ 1s)
    u16     usChkToneTime;      //��Ⲧ�����ȶ�ʱ��(ȡֵ��Χ��10-255     Ĭ��ֵ��[90]        ��λ��0.01��)
    u16     usChkAnswerToneTime;//���Ӧ�����ȶ�ʱ��(ȡֵ��Χ��10-255       Ĭ��ֵ��[90]        ��λ��0.01��)
    u16     usWaveLostTime;     //�ز���ʧʱ��(��λΪ ms  Ĭ�� 500  ��ʾ 500ms)
    u8      ucSendLevel;        //���͵�ƽ  �����ͷ����ϵ��ź�˥������
    u8      ucDialMode;         //����ģʽ:0x00: DTMF 0x01:PULSE
    u32     uiDialBaud;         //���Ų����ʣ�1200,2400,��
    u8      ucDialTimeout;      //���ŵȴ�ʱ�䣬��λ���룬0��ʾ���ųɹ����������أ�Ĭ��Ϊ0.
    u8      ucRegion;           //���������룬��ͬ���һ�����modem��·��ʽ���ܲ�һ��
    u8      ucRuf[8];           //����
} T_SDK_MODEM_EXPARAM;

//MODEM ����
typedef struct
{
    BOOL bLinkMode;                //0 -  ͬ��  1 -  �첽
    u8  asOutLineNo[16+1];              //���ߺ��벻����16
    u8  asPhone[3][28];              //�绰����� 25 λ
    BOOL bIsNeedExParam;            //�Ƿ���Ҫ��չ����  0-����Ҫ��1- ��Ҫ
    T_SDK_MODEM_EXPARAM tModemExParam;  //��չ����
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

