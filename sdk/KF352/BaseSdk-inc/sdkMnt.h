/********************************************************************
文件名 :
描  述 :
版  权 : 长城开发
作  者 : 陈伟明
修改记录:
    日期              修改人  修改内容
    2013-12-25 13:25  陈伟明  创建
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

