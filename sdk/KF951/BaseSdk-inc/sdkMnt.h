/********************************************************************
�ļ��� :
��  �� :
��  Ȩ : ���ǿ���
��  �� : ��ΰ��
�޸ļ�¼:
    ����              �޸���  �޸�����
    2013-12-25 13:25  ��ΰ��  ����
********************************************************************/
#ifndef BASE_SDKMNT_H_
#define BASE_SDKMNT_H_

#ifdef __cplusplus
    extern "C" {
#endif

typedef enum
{
    SDK_MNT_SD,
    SDK_MNT_USB,
} E_SDK_MNT_STORE;

s32 sdkMntOn(E_SDK_MNT_STORE eType);
s32 sdkMntOut(E_SDK_MNT_STORE eType);

#ifdef __cplusplus
    }
#endif

#endif

