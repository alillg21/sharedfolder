/********************************************************************
�ļ��� : sdkMngMem.h
��  �� : �ڴ����ͷ�ļ�
��  Ȩ : ���ǿ���
��  �� : ���Ѹ�
�޸ļ�¼:
    ����              �޸���  �޸�����
    2013-12-24 15:04  ������ ����
********************************************************************/
#ifndef BASE_SDKSYSMNG_H
#define BASE_SDKSYSMNG_H

#ifdef __cplusplus
    extern "C" {
#endif

//˽�� Ӧ�ò��������
void* PrivateGetMalloc(u32 uisize, const s8 *pcFile, s32 siLine);
s32 PrivateFreeMem(void* pMemblock, const s8 *pcFile, s32 siLine);

//���� Ӧ�õ���
#define sdkMemGet(uiMenSize) PrivateGetMalloc(uiMenSize,(const char *)__FILE__, __LINE__)
#define sdkMemFree(pMem) PrivateFreeMem((void *)pMem,(const char *)__FILE__, __LINE__)

#ifdef __cplusplus
    }
#endif

#endif

