/********************************************************************
�ļ��� : sdkIni.h
��  �� : ��������
��  Ȩ : ���ǿ���
��  �� : ¬ԣ��
�޸ļ�¼: 
    ����              �޸���  �޸�����
    2014-02-18 10:40  ¬ԣ��  ����
********************************************************************/

#ifndef BASE_SDKINI_H_
#define BASE_SDKINI_H_

#ifdef __cplusplus
    extern "C" {
#endif


s32 sdkIniReadKey(const u8 *pszFilePath, const u8 *pszSel, const u8 *pszKey ,
                                u8 *pParam, u32 uiParamLen);


//���Դ���
#if 0

s32 TESTPUBINI(void);

#endif


#ifdef __cplusplus
    }
#endif

#endif
        





