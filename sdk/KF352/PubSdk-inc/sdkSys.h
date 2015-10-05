/********************************************************************
�ļ��� : sdkSys.h
��  �� : ϵͳ�������˳�
��  Ȩ : ���ǿ���
��  �� : ¬ԣ��
�޸ļ�¼: 
    ����              �޸���  �޸�����
    2014-02-18 10:39  ¬ԣ��  ����
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
    u8 ucKeyboard;      //����,1��ʾ�ɹ���2��ʾʧ��
    u8 ucLCD;           //LCD,1��ʾ�ɹ���2��ʾʧ��
    u8 ucPrint;         //��ӡ,1��ʾ�ɹ���2��ʾʧ��
    u8 ucMagCard;       //������,1��ʾ�ɹ���2��ʾʧ��
    u8 ucSerialPort;    //����,1��ʾ�ɹ���2��ʾʧ��
    u8 ucInsertCard;    //�Ӵ�ʽIC��,1��ʾ�ɹ���2��ʾʧ��
    u8 ucMFC;           //�ǽ�,1��ʾ�ɹ���2��ʾʧ��
    u8 ucPED;           //������̣�1��ʾ�ɹ���2��ʾʧ��
    u8 ucCommunica;     //ͨѶ��ʽ�������ͨѶģʽ��0��ʾû�д���ͨѶģʽ��1��ʾ�ɹ���2��ʾʧ��    
}T_SDK_SYS_STATUS;

s32 sdkSysStart(u8 ucMode);
s32 sdkSysQuit(void);
s32 sdkSysGetPubVer(u8 *pszVersion);
s32 sdkSysGetStatus(T_SDK_SYS_STATUS *pstStatus);

#ifdef __cplusplus
    }
#endif

#endif

