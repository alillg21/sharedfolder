/********************************************************************
�ļ��� : sdkMngMessage.h
��  �� : ��Ϣ����ģ��
��  Ȩ : ���ǿ���
��  �� : ������
�޸ļ�¼:
    ����              �޸���  �޸�����
    2014-02-12 19:30  ������  ����
********************************************************************/
#ifndef BASE_SDKMESSAGE_H_
#define BASE_SDKMESSAGE_H_

#ifdef __cplusplus
    extern "C" {
#endif

#define     SDK_MSG_OUT         0                   //����Ϣ������Ϻ�Ӷ������
#define     SDK_MSG_KEEP        1                   //����Ϣ������Ϻ��ƶ�������β��
#define     SDK_MSG_DISCARD     2                   //����Ϣ������Ϻ�ֱ�Ӷ���,�˳���Ϣѭ��

#define     SDK_MSG_NORMAL      0                   //��ͨ���ȼ�(ȱʡ)
#define     SDK_MSG_HIGH        1                   //�����ȼ�

#define     SDK_MSG_INIT        0                   //MSG��ʼ��״̬
#define     SDK_MSG_SERVICE     1                   //MSG��������״̬
#define     SDK_MSG_TERMINAL    2                   //MSG��ֹ״̬

typedef struct _MSG                                             //��Ϣ�ڵ�
{
    u8  Priority;                                               //��Ϣ���ȼ�
    u8  Status;                                                 //��Ϣ״̬
    s32 (*pFun)(struct _MSG *ptMsg);                             //��Ϣ��ں���
    u32 WParam;                                                 //��Ϣ�߲���
    u32 LParam;                                                 //��Ϣ�Ͳ���
}T_SDK_MSG;

typedef struct _SDKMSGNODE
{
    struct _MSG     *pMsg;                      //�ڴ�ڵ�
    struct _SDKMSGNODE *pNext;                  //��һ�ڴ��ڵ�ָ��
}T_SDK_MSG_NODE;

s32 sdkMsgPost(T_SDK_MSG *ptMsg);
s32 sdkMsgSend(T_SDK_MSG *ptMsg);
BOOL sdkMsgQuery(T_SDK_MSG **ptMsg);
s32 sdkMsgTerminate(void *pFun);
void sdkMsgListDisp(void);
void sdkMsgListDestroy(void);
void sdkMsgPack(u8 ucPrio,u8 ucStatus,s32 (*pFun)(struct _MSG *ptMsg),u32 uiWParam,u32 uiLParam);

#ifdef __cplusplus
    }
#endif

#endif

