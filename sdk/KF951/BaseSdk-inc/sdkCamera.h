/********************************************************************
文件名 : SdkCamera.h
描  述 : 摄像头模块接口函数
版  权 : 长城开发
作  者 : DJ Chen
修改记录:
    日期              修改人  修改内容
    2014-03-07 11:34  DJ Chen  创建
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


