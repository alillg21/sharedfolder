/********************************************************************
�ļ��� : sdkScanGun.h
��  �� : ɨ��ǹģ��ͷ�ļ�
��  Ȩ : ���ǿ���
��  �� : Ming
�޸ļ�¼: 
    ����              �޸���  �޸�����
    2014-03-11 10:32  Ming      ����
********************************************************************/
#ifndef BASE_SCANGUN_H
#define BASE_SCANGUN_H
    
#ifdef __cplusplus
        extern "C" {
#endif


s32 sdkBarcodeScanOpen(void);
s32 sdkBarcodeScanClose(void);
s32 sdkBarcodeScanRead(u8 *pucScanBuf);


#ifdef __cplusplus
    }
#endif

#endif

