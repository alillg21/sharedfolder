/********************************************************************
�ļ��� : sdkUART.h
��  �� :
��  Ȩ : ���ǿ���
��  �� : ��־��
�޸ļ�¼:
    ����              �޸���  �޸�����
    2014-01-06 11:01  ��־��  ����
********************************************************************/
#ifndef BASE_SDKUART_H
#define BASE_SDKUART_H

#ifdef __cplusplus
    extern "C" {
#endif

//���ں�
#define SDK_COM0    0        //�ڲ�ģ�飨modemģ�顢����ģ�飩����
#define SDK_COM1    1        //���ԡ����ؿ�
#define SDK_COM2    2        //�����豸��Pinpad���ӿ�
#define SDK_COM3    3        //����3
#define SDK_COM4    4        //����4
#define SDK_COM5    5        //����5

s32 sdkUartOpen(u8 ucPortNo, u8 *PortPara);
s32 sdkUartClose(u8 ucPortNo);
s32 sdkUartSendData(u8 ucPortNo, u8 *Data, u32 DataLen);
s32 sdkUartRecvData(u8 ucPortNo, u8 *Data, u32 pDataLen);
s32 sdkUartClearBuf(u8 ucPortNo);

#ifdef __cplusplus
  }
#endif

#endif

