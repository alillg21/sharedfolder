/********************************************************************
文件名 : sdkPinPad.h
描  述 : 密码键盘
版  权 : 长城开发
作  者 : 卢裕燕
修改记录:
    日期              修改人  修改内容
    2014-01-07 10:21  卢裕燕  创建
********************************************************************/
#ifndef BASE_SDKPED_H_
#define BASE_SDKPED_H_

#ifdef __cplusplus
        extern "C" {
#endif

typedef enum
{
    SDK_PED_EXTERNAL,    //External pinpad module
    SDK_PED_INTERNAL,    //Internal pinpad module
}E_SDK_PEDTYPE;

s32 sdkPedSetType(E_SDK_PEDTYPE ucType);
s32 sdkPedGetType(void);
s32 sdkPedInit(void);
s32 sdkPedUpMastKey(u32 uiKeyIndex, u8 *pKeyData, u8 ucKeyLen, u8 ucType);
s32 sdkPedUpWorkKey(u32 uiKeyIndex, u8 *pPinKey, u8 ucPinKeyLen, u8 *pMacKey,
                    u8 ucMacKeyLen, u8 *pTDK, u8 ucTDKLen, u8 *pKeyChkValue);
s32 sdkPedEncryptData(E_SDK_ENCRYPT_TYPE eEncrypt, u32 uiKeyId, u8 *phexInput, u8 *phexOutput);
s32 sdkPedLock(void);
s32 sdkPedUnLock(void);
s32 sdkPedSetDollarSign(u8 *pszSign);
s32 sdkPedRandom(u8 *phexRandom);
s32 sdkPedMac(u32 uiKeyId, u8 *pheSrcData, u32 ucLen, u8 *pheDestData, E_SDK_MAC_TYPE eType);
s32 sdkPedDispIdleMenu();
s32 sdkPedInputPrompt(u8 ucRow, u8 ucCol, u8 PinOutType, u8 ucPinCnt, u8 ucMode);
s32 sdkPedDispInfo(u8 *pszDisp);
s32 sdkPedDispBalance(u8 *pbcDisp, u8 ucLen);
s32 sdkPedChageLanguage(u8 ucType);
s32 sdkPedInputPin(u8 ucKeyId, u8 ucMinLen, u8 ucMaxLen, u8 *pszCardNo, u8 *pbMoney,
                    u8 ucMode, u32 uiTimeout, u8 *phexPinBlock);
//
s32 sdkPedDispAmount(u8 *pbcDisp, u8 ucLen);
s32 sdkPedReadSerialNo(u8 *pucSerialNo);
s32 sdkPedGetVersion(u8 *pucHardwareVer, u8 *pucSoftwareVer);

#ifdef __cplusplus
    }
#endif


#endif

