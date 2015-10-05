/********************************************************************
�ļ��� :
��  �� :
��  Ȩ : ���ڳ��ǿ���
��  �� : ��ΰΰ
�޸ļ�¼:
    ����              �޸���  �޸�����
    2014-01-02 15:50  ��ΰΰ  ����
********************************************************************/
#ifndef BASE_SDKPPP_H_
#define BASE_SDKPPP_H_

#ifdef __cplusplus
    extern "C" {
#endif

//PPPʹ�õ��豸����
#define SDK_DEV_WNET     1  //Wireless
#define SDK_DEV_ETH      2  //Ethernet
#define SDK_DEV_WIFI     3  //Wifi
#define SDK_DEV_MODEM    4  //Modem

typedef struct
{
    u8 ucDevType;   //ģ������:
                    //0x01   PPPʹ�õ��豸Ϊ����ģ��
                    //0x02   PPPʹ�õ��豸Ϊ��̫��ģ��
                    //0x03   PPPʹ�õ��豸ΪWIFIģ��
                    //0x04   PPPʹ�õ��豸ΪMODEMģ��
    u8 szAPN[16];      //Apn�����
    u8 szDialNum[16];  //���ź���
    u8 szName[16];     //����
    u8 szPasswd[16];   //����
    u8 ucAuth;         //��֤��ʽ PPP_ALG_PAP/ PPP_ALG_CHAP	MSCHAPV1  / PPP_ALG_MSCHAPV2
    u8 ucTimeOut;      //��ʱʱ�� ��
} T_SDK_PPP_PARAM;

//��֤�㷨: ����Ҫ����һ�֣����ڰ�ȫ�Ŀ��ǣ�����ʹ��CHAP�㷨��
#define PPP_ALG_PAP	      0x01  //��֤ʱ����PAP�㷨
#define PPP_ALG_CHAP	  0x02  //��֤ʱ����CHAP�㷨
#define PPP_ALG_MSCHAPV1  0x04  //��֤ʱ����MSCHAPV1�㷨
#define PPP_ALG_MSCHAPV2  0x08  //��֤ʱ����MSCHAPV2�㷨

s32 sdkPppSetParam(T_SDK_PPP_PARAM *tPppParam);
s32 sdkPppStartLink(void);
s32 sdkPppStopLink(void);
s32 sdkPppGetLinkStatus(void);

#ifdef __cplusplus
    }
#endif

#endif

