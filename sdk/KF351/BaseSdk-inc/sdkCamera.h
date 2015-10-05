/********************************************************************
�ļ��� : SdkCamera.h
��  �� : ����ͷģ��ӿں���
��  Ȩ : ���ǿ���
��  �� : DJ Chen
�޸ļ�¼:
    ����              �޸���  �޸�����
    2014-03-07 11:34  DJ Chen  ����
********************************************************************/
#ifndef BASE_SDKCAMERA_H_
#define BASE_SDKCAMERA_H_

#ifdef __cplusplus
    extern "C" {
#endif


s32 sdkCameraOpen(u32 uiWidth, u32 uiHeight, s8 cFormatFlag);
s32 sdkCameraClose(void);
s32 sdkCameraSetMode(u32 uiMode);
s32 sdkCameraPreview(void);
s32 sdkCameraTakePicture(u8 *pucFileName);
s32 sdkCameraGetMem(s8 *pcImgBuf, u32 *punBufLen);


#ifdef __cplusplus
    }
#endif

#endif


