/********************************************************************
文件名 : sdkPrintExt.h
描  述 : 与打印机相关的接口
版  权 : 长城开发
作  者 : DJ Chen
修改记录: 
    日期              修改人  修改内容
    2014-02-19 09:02  DJ Chen  创建
********************************************************************/
#ifndef BASE_SDKPRINTEXT_H_
#define BASE_SDKPRINTEXT_H_
    
#ifdef __cplusplus
        extern "C" {
#endif

typedef enum 
{
    SDK_PRINT_LEFTALIGN = 0,       //左对齐
    SDK_PRINT_RIGHTALIGN = 1,      //右对齐
    SDK_PRINT_MIDDLEALIGN = 2      //居中对齐
}E_SDK_PRINT_ALIGNMODE;            //对齐方式

typedef enum 
{
    SDK_FONT_8,
    SDK_FONT_12,
    SDK_FONT_16,
    SDK_FONT_24,
    SDK_FONT_32,
    SDK_FONT_BMP = 13,     //热敏打印机.打印单色图片，384个点
    SDK_BARCODE_CODE39,     //一维条码 Code 39
    SDK_BARCODE_CODE128,    //一维条码 Code 128
    SDK_BARCODE_EAN13,      //一维条码 EAN 13 
    SDK_BARCODE_QRCode,     //二维条码 QR Code
    SDK_BARCODE_PDF417,     //二维条码 PDF417
}E_SDK_PRINT_FONT;

s32 sdkPrintStr(u8 *pszStr,E_SDK_PRINT_FONT eFont, BOOL bIsBold, E_SDK_PRINT_ALIGNMODE eAlign, u32 uiOffset, u32 uiRowGap);
s32 sdkPrintBitMap(const u8 *pszBmpFile, u32 uiOffset);
s32 sdkPrintSetLastRowGap(u32 uiDoit);
s32 sdkPrintStart(void);

    
#ifdef __cplusplus
        }
#endif
    
#endif



