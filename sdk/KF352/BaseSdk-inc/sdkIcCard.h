/********************************************************************
文件名 : sdkIcCard.h
描  述 : SDK base lib - ICC
版  权 : GW.KaiFa
作  者 : Ming
修改记录:
    日期              修改人  修改内容
    2013-12-25 13:36  Ming    创建
********************************************************************/
#ifndef BASE_SDKICCARD_H_
#define BASE_SDKICCARD_H_

#ifdef __cplusplus
    extern "C" {
#endif

//接触式IC卡卡座号
#define     SDK_ICC_USERCARD         0x00        // 标准大卡IC卡座
#define     SDK_ICC_SAM1             0x01        // SAM 1
#define     SDK_ICC_SAM2             0x02        // SAM 2
#define     SDK_ICC_SAM3             0x03        // SAM 3
#define     SDK_ICC_SAM4             0x04        // SAM 4

typedef enum
{
    ICC_CPU,//CPU卡
    ICC_AT24CXX,//At24cxx
    ICC_MEMORY,//MEMORY 卡
}E_SDK_ICC_MODLUETYPE;//卡类型

typedef struct
{
    E_SDK_ICC_MODLUETYPE eCardType; //卡类型: CPU卡/ At24cxx /MEMORY
    u8 ucSlotNo; //卡座号
}T_SDK_ICC_PARAM;  //卡参数

s32 sdkIccPowerOn(E_SDK_ICC_MODLUETYPE eCardType, u8 ucSlotNo);
s32 sdkIccPowerDown(E_SDK_ICC_MODLUETYPE eCardType, u8 ucSlotNo);
s32 sdkIccGetStatus(E_SDK_ICC_MODLUETYPE eCardType, u8 ucSlotNo);
s32 sdkIccReset(E_SDK_ICC_MODLUETYPE eCardType, u8 ucSlotNo, u32 *puiAtrLen, u8 *pucAtrData);
s32 sdkIccResetExt(E_SDK_ICC_MODLUETYPE eCardType, u8 ucSlotNo, s32 siCardVol, s32 siBaud, u32 *puiAtrLen, u8 *pucAtrData);
s32 sdkIccSendData(u8 ucSlotNo, const u8 *phexInBuf, u32 uiInLen, u8 *phexOutBuf, u32 *puiOutLen);
//
s32 sdkIccAt24cxxWrite(u8 ucSlotNo, u32 StartAddr, u32 uiLen, u8 *pucDataIn);
s32 sdkIccAt24cxxRead(u8 ucSlotNo, u32 uiStartAddr, u32 uiLen, u8 *pDataOut);
//
s32 sdkIccMemRead(u8 ucSlotNo ,u32 uiAddr, u32 puiLen ,u8 * phexBuf);
s32 sdkIccMemWrite(u8 ucSlotNo ,u32 uiAddr, u32 puiLen ,u8 * phexBuf);
s32 sdkIccMemGetPwdErrCnt(void);
s32 sdkIccMemCheckPwd(const u8 *phexPwd, u8 ucPwdLen, u8 *pucCnt);
s32 sdkIccMemModifyPwd(const u8 *phexNewPwd, u8 ucPwdLen);

#ifdef __cplusplus
    }
#endif

#endif

