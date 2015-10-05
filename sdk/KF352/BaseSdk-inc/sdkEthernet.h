/********************************************************************
�ļ��� : sdkEthernet.h
��  �� : ��̫��(ͨѶ)�ӿں���
��  Ȩ : ���ǿ���
��  �� : ��־��
�޸ļ�¼:
    ����              �޸���  �޸�����
    2014-01-08 14:37  ��־��  ����
********************************************************************/
#ifndef BASE_SDKETHERNET_H
#define BASE_SDKETHERNET_H

#ifdef __cplusplus
    extern "C" {
#endif

//Network Param Config
typedef struct
{
    u8 szServerIP[64];              //��������ַ��֧��IP��URL��ʽ������
    u8 szPort[6];                   //����˿ں�
    u8 szNetClientIP[16];           //���� IP ��ַ
    u8 szNetGate[16];               //��������
    u8 szNetMask[16];               //������������
    u8 szDnsIP1[16];                //DNS ��������������IP
    u8 szDnsIP2[16];                //DNS ��������������IP
    BOOL bIsDhcp;                   //�Ƿ�ʹ�� DHCP
    BOOL bIsPPPoe;                  //�Ƿ��� PPPoe ��ʽ  0-��1-��
    u8 szPPPoeUser[51];             //PPPoe �û������ 50 ���ֽ�  ASCII
    u8 szPPPoeUserPwd[51];          //PPPoe �û������ 50 ���ֽ�  ASCII
} T_SDK_NETPARAM;


s32 sdkNetReadParam(T_SDK_NETPARAM *ptNetParam);
s32 sdkNetSetParam(const T_SDK_NETPARAM *ptNetParam);
s32 sdkNetCreatLink(u32 uiTimeout);
s32 sdkNetClearLink(void);
s32 sdkNetSendData(u8 * pucData,u32 uiDataLen);
s32 sdkNetRecvData(u8 * pucData,u32 uiDataLen);
s32 sdkNetGetStatus(void);


#ifdef __cplusplus
    }
#endif

#endif

