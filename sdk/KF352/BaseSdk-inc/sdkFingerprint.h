/********************************************************************
文件名 : sdkFingerprint.h
描  述 : 指纹模块
版  权 : 长城开发
作  者 : 卢裕燕
修改记录: 
    日期              修改人  修改内容
    2014-03-17 18:52  卢裕燕  创建
********************************************************************/
#ifndef BASE_SDK_FINGERPRINT_H
#define BASE_SDK_FINGERPRINT_H

#ifdef __cplusplus
    extern "C" {
#endif

typedef struct 
{
  u32 Length;               ///< Length of Header + Opaque Data
  u8 HeaderVersion;         ///< Current version is 1
  u8 Type;                  ///< Type=4 (BioAPI_BIR_DATA_TYPE_PROCESSED)
  u16 FormatOwner;          ///< FormatOwner=0x12 (STMicroelectronics)
  u16 FormatID;             ///< FormatID=0
  s8 Quality;               ///< Quality=-2 (BioAPI_QUALITY is not supported)
  u8 Purpose;               ///< Purpose=3 (PT_PURPOSE_ENROLL)
  u32 FactorsMask;          ///< FactorsMask=0x08 (BioAPI_FACTOR_FINGERPRINT)
} T_SDK_PT_BIR_HEADER;

typedef struct
{
  T_SDK_PT_BIR_HEADER Header; 
  u8 Data[1]; ///< Minimal version required
} T_SDK_PT_BIR;

s32 sdkFPInitialize(void);
s32 sdkFPOpen(void);
s32 sdkFPClose(void);
s32 sdkFPSetGUICallback(void);
s32 sdkFPGrab(u8 *ppGrabbedData,u32 *uiLen);
s32 sdkFPEnroll(T_SDK_PT_BIR **pNewTemplate);
s32 sdkFPVerify(T_SDK_PT_BIR **pNewTemplate);
s32 sdkFPDeleteAllFingers();

#ifdef __cplusplus
    }
#endif

#endif

