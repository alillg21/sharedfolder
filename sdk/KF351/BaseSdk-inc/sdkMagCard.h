/********************************************************************
文件名 :
描  述 :
版  权 : 长城开发
作  者 : 陈伟明
修改记录:
    日期              修改人  修改内容
    2013-12-25 15:38  陈伟明  创建
********************************************************************/
#ifndef BASE_SDKMAGCARD_H_
#define BASE_SDKMAGCARD_H_

#ifdef __cplusplus
    extern "C" {
#endif

typedef struct
{
    u8  szCardNo[20+1];          //card number
    u8  szExpiredDate[4+1];      //expired date
    u8  szCardHolder[32+1];      //card holder name
    u8  szServiceCode[3+1];      //service code
} T_SDK_TRACK_DATA_INFO;

s32 sdkMagOpen(void);
void sdkMagClose(void);
s32 sdkMagIfBrush(void);
s32 sdkMagReadData(u8 *pTrack1, u8 *pTrack2, u8 *pTrack3);
s32 sdkMagClearData(void);
s32 sdkMagParseData(const u8 *pTrack1, const u8 *pTrack2, const u8 *pTrack3, T_SDK_TRACK_DATA_INFO *ptTrackInfo);

#ifdef __cplusplus
    }
#endif

#endif

