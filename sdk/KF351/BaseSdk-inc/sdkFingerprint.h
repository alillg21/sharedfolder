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

//used to associate any arbitrary long data block with the length information.
typedef struct t_pt_data {
  unsigned int Length; 	///< Length of the Data field in bytes
  unsigned char Data[1]; 	///< The data itself, variable length
} T_SDK_PT_DATA;

//the callback function to deal with GUI state changes
typedef int (*SDK_PT_GUI_STATE_CALLBACK) (
    void *pGuiStateCallbackCtx,
    unsigned int dwGuiState,
    unsigned char *pbyResponse, //OUT
    unsigned int dwMessage,     //IN
    unsigned char byProgress,
    void *pSampleBuffer,
    T_SDK_PT_DATA *pData);

//The header of the BIR. This type is exactly equivalent to BioAPI's BioAPI_BIR_HEADER.
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

//A container for biometric data. BIR = Biometric Identification Record.
typedef struct
{
  T_SDK_PT_BIR_HEADER Header;
  u8 Data[1]; ///< Minimal version required
} T_SDK_PT_BIR;

s32 sdkFPInitialize(void);
s32 sdkFPOpen(void);
s32 sdkFPClose(void);
s32 sdkFPSetGUICallback(SDK_PT_GUI_STATE_CALLBACK pfnGuiStateCallback);
s32 sdkFPGrab(u8 *ppGrabbedData,u32 *uiLen);
s32 sdkFPEnroll(T_SDK_PT_BIR **pNewTemplate);
s32 sdkFPVerify(T_SDK_PT_BIR **pNewTemplate);
s32 sdkFPDeleteAllFingers(void);
s32 sdkFPSetScanTimes(u8 uiNumberOfTimes);

#ifdef __cplusplus
    }
#endif

#endif

