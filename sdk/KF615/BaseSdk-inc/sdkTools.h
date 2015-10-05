/********************************************************************
文件名 : sdkTools.h
描  述 : Tools工具模块
版  权 : 长城开发
作  者 : 卢裕燕
修改记录:
    日期              修改人  修改内容
    2013-12-30 16:19  卢裕燕  创建
********************************************************************/
#ifndef BASE_SDKTOOLS_H_
#define BASE_SDKTOOLS_H_

#ifdef __cplusplus
    extern "C" {
#endif

s32 sdkAscToBcd(const u8* phexSrc, u32 uiLen, u8* phexDest);
s32 sdkAscToBcdR(const u8* phexSrc, u32 uiLen, u8* phexDest);
s32 sdkBcdToAsc(const u8* phexSrc, u32 uiLen, u8* phexDest);
s32 sdkBcdToU8 (u8 *punDest, const u8 *pbcSrc, u32 uiSrclen);
s32 sdkU8ToBcd(const u8  ucSrc,u32 uiDestLen, u8 *pbcDest);
s32 sdkBcdToU16(u16 *punDest, const u8 *pbcSrc, u32 uiSrclen);
s32 sdkU16ToBcd(u16 const unSrc, s32 uiDestlen, u8 *pbcDest);
s32 sdkBcdToU32(u32 *puiDest, const u8 *pbcSrc, u32 uiSrclen);
s32 sdkU32ToBcd(u32 const uiSrc, s32 uiDestlen, u8 *pbcDest);
s32 sdkHexToU16(u16 *punDest, const u8 * phexSrc, u32 uiSrclen);
s32 sdkU16ToHex(const u16 phexSrc,u32 uiLen, u8* phexDest);
s32 sdkHexToU32(u32 *puiDest, const u8 *pbcSrc, u32 uiSrclen);
s32 sdkU32ToHex(u32 const uiSrc, s32 uiDestlen, u8 * phexDest);
s32 sdkU8ToAsc(const u8 ucSrc,u32 uiDestLen, u8 *pasDest);
s32 sdkU16ToAsc(const u16 ucSrc,u32 uiDestLen, u8 *pasDest);
s32 sdkU32ToAsc(const u32 ucSrc,u32 uiDestLen, u8 *pasDest);
s32 sdkAscToDouble(const u8* phexSrc, u32 uiLen, double* phexDest);
BOOL sdkIsAscii(const u8* phexSrc);
s32 sdkFormatAmt(const u8* phexSrc, u8* phexDest);
s32 sdkRevFormatAmt(const u8* phexSrc, u8* phexDest);
s32 sdkRemoveSpace(const u8* phexSrc, u8* phexDest);
s32 sdkCutStr(const u8* phexSrc,u32 uiLen, u8* phexDest);
s32 sdkGetCarNO(const u8* pAscSrc, u8* pAscDest, u32* uiLen);
s32 sdkCardNOVerify(const u8* phexSrc);
s32 sdkBcdAdd(const u8* pbcSrc, u8* pbcDest, u32 uiLen);
s32 sdkBcdSub(const u8* pbcSrc, u8* pbcDest, u32 uiLen);
s32 sdkGetRand(void);
s32 sdkToolCheckIPAddr(s8 *pcInputBuf);

#ifdef __cplusplus
    }
#endif

#endif

