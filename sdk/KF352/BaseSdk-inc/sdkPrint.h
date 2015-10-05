/********************************************************************
文件名 : sdkPrint.h
描  述 : 和打印机相关的函数
版  权 : 长城开发
作  者 : DJ Chen
修改记录: 
    日期              修改人  修改内容
    2014-01-07 13:19  DJ Chen  创建
********************************************************************/
#ifndef BASE_SDKPRINT_H_
#define BASE_SDKPRINT_H_
#include "sdkTypeDef.h"


#ifdef __cplusplus
    extern "C" {
#endif

//  Font Mode
#define PRN_MODE_NORMAL   0x00 // normal height, normal width 正常
#define PRN_MODE_DBWIDTH  0x01 // normal height, double width 倍宽
#define PRN_MODE_DBHEIGHT 0x02 // double height, normal width 倍高
#define PRN_MODE_DBBOTH   0x03 // double height, double width 倍宽倍高

#define PRN_MODE_LEFT            0x01  //居左
#define PRN_MODE_MIDDLE          0x02  //居中
#define PRN_MODE_RIGHT           0x03  //居右

//打印机状态值
#define SDK_PRN_STATUS_OK 0
#define SDK_PRN_STATUS_PAPEROUT (SDK_USER_DEFINE-1)   //打印机缺纸
#define SDK_PRN_STATUS_TOOHEAT  (SDK_USER_DEFINE-2)   //温度过高
#define SDK_PRN_STATUS_FAULT    (SDK_USER_DEFINE-3)   //打印机设备故障

//条码类型
#define SDK_PRN_CODE39  0x00
#define SDK_PRN_CODE128 0x01
#define SDK_PRN_EAN13   0x02


//填充字符的结构
typedef struct{
    s8 *pcInfo;         //要打印的字符串
    u8 ucFont;          //字体 同LCD显示的字体
    u8 ucInterval;      //字间隔 单位:pixel 暂未实现
    u8 ucAtt;           //字属性 =0白底黑字 =FONT_CONTRAST黑底白字
    u8 ucBold;          //加粗
    u8 ucItalic;        //斜体
    u8 ucUnderline;     //下划线
}T_PRN_INFOATT;

s32 sdkPrnOpen(void);
s32 sdkPrnClose(void);

s32 sdkPrnSetGray(u8 ucGray);
s32 sdkPrnSetSpeed(u8 ucSpeed);
s32 sdkPrnSetFont(s8 *pFontName, s8 *pFontCharacter, u32 Size);
void sdkPrnSetRowGap(u32 uiRowGap);

s32 sdkPrnFillBuffer(u8  *pszBuf, u8 ucAlign, u32 uiFontZoom, u32 uiOffset);
s32 sdkPrnLogo(u8 *pBMPBuf, u32 uiOffset);
s32 sdkPrnBarcode (u8 *pBarcode, u8 ucBarcodeType,u32 uiPrintMode, u32 uiOffset);
s32 sdkPrnQRCode(const s8 *pszInput, s32 iMultiple, u32 uiOffset);
s32 sdkPrnStart(void);

s32 sdkPrnGetCurLine(void);
s32 sdkPrnDotStep(u8 ucDir,u32 uiDotLine);
s32 sdkPrnPaperForward(u32 uiPIXNum);
s32 sdkPrnStatus(void);

#ifdef __cplusplus
    }
#endif

#endif

