/********************************************************************
�ļ��� : sdkMngLink.h
��  �� : ����ģ��ͷ�ļ�
��  Ȩ : ���ǿ���
��  �� : ������
�޸ļ�¼:
    ����              �޸���  �޸�����
    2013-12-24 15:04  ������ ����
********************************************************************/
#ifndef BASE_SDKSYSLINK_H
#define BASE_SDKSYSLINK_H

#ifdef __cplusplus
    extern "C" {
#endif

typedef void* T_SDK_LIST_HAND;

T_SDK_LIST_HAND sdkListCreate(void);
s32 sdkListDestroy(T_SDK_LIST_HAND Hand);
s32 sdkListAddEnd(T_SDK_LIST_HAND Hand, void  *const pData);
s32 sdkListAddFront(T_SDK_LIST_HAND Hand, void  *const pData);
s32 sdkListRemoveNode(T_SDK_LIST_HAND Hand,void const *pData);
s32 sdkListRemoveNodeByIndex(T_SDK_LIST_HAND Hand, u8 ucIndex);
void *sdkListReadNode(T_SDK_LIST_HAND Hand, u8 ucIndex);
void  sdkListInfo(T_SDK_LIST_HAND Hand);

#ifdef __cplusplus
    }
#endif

#endif

