/********************************************************************
文件名 : sdkLCD.h
描  述 : 和LCD屏幕相关的代码
版  权 : 长城开发
作  者 : DJ Chen
修改记录:
    日期              修改人  修改内容
    2013-12-26 08:53  DJ Chen  创建
********************************************************************/
#ifndef BASE_SDKLCD_H_
#define BASE_SDKLCD_H_

#ifdef __cplusplus
    extern "C" {
#endif

#define FONT_COURIER_NEW    "CourierNew"
#define FONT_SONG           "宋体"

#define FONT_CHARSET_ASCII   "ASCII"
#define FONT_CHARSET_GB18030 "GB18030"
#define FONT_CHARSET_UNICODE "UNICODE"

//字体高度
#define SDK_FONT_HIGHT_8    8
#define SDK_FONT_HIGHT_12   12      //当LCD屏为128*64的默认字体
#define SDK_FONT_HIGHT_16   16
#define SDK_FONT_HIGHT_24   24      //当LCD屏为(320*240)和(320*480)的默认字体
#define SDK_FONT_HIGHT_32   32

//显示属性
#define SDK_LCD_LEFT            0x01  //左对齐
#define SDK_LCD_RIGHT           0x02  //右对齐
#define SDK_LCD_MIDDLE          0x04  //居中
#define SDK_LCD_COL             0x08  //插入一列
#define SDK_LCD_REVERSE         0x10  //字符反显
#define SDK_LCD_BOX             0x20  //加框
#define SDK_LCD_OVERLINE        0x40  //加下划线
#define SDK_LCD_REVERSELINE     0x80  //整行反显 （如果设置此属性则字符反显将失效）

#define SDK_LCD_LINE1    0
#define SDK_LCD_LINE2    1
#define SDK_LCD_LINE3    2
#define SDK_LCD_LINE4    3
#define SDK_LCD_LINE5    4
#define SDK_LCD_LINE6    5
#define SDK_LCD_LINE7    6
#define SDK_LCD_LINE8    7
#define SDK_LCD_LINE9    8
#define SDK_LCD_LINE10   9
#define SDK_LCD_LINE11   10
#define SDK_LCD_LINE12   11
//
#define SDK_LCD_LINE13   12
#define SDK_LCD_LINE14   13
#define SDK_LCD_LINE15   14
#define SDK_LCD_LINE16   15
#define SDK_LCD_LINE17   16
#define SDK_LCD_LINE18   17
#define SDK_LCD_LINE19   18
#define SDK_LCD_LINE20   19
//
#define SDK_LCD_LINE21   20
#define SDK_LCD_LINE22   21
#define SDK_LCD_LINE23   22
#define SDK_LCD_LINE24   23
#define SDK_LCD_LINE25   24
#define SDK_LCD_LINE26   25
#define SDK_LCD_LINE27   26
#define SDK_LCD_LINE28   27

//LCD显示图标
#define  SDK_ICON_PHONE      1  // phone 电话
#define  SDK_ICON_SIGNAL     2  // wireless signal 信号
#define  SDK_ICON_PRINTER    3  // printer 打印机
#define  SDK_ICON_ICCARD     4  // smart card IC卡
#define  SDK_ICON_LOCK       5  // lock 锁
#define  SDK_ICON_BATTERY    6  // Battery电池图标
#define  SDK_ICON_EXTPWR     7  // 外电图标
#define  SDK_ICON_UP         8  // up 向上
#define  SDK_ICON_DOWN       9  // down 向下
#define  SDK_ICON_WIFI       10 // WIFI图标

//图标指定动作，1:点亮，0:熄灭。
#define  SDK_CLOSE_ICON    0    // 关闭图标[针对所有图标]
#define  SDK_OPEN_ICON     1   // 显示图标[针对打印机、IC卡、锁、电池、向上、向下]

//点亮摘机、挂机图标，则Mode的值设置如下：
#define  SDK_ICON_OFFHOOK    1  // hook off 摘机
#define  SDK_ICON_ONHOOK   2    // hook on  挂机

//点亮信号图标，则Mode的值设置为：[1，6]共6挡，1表示信号最弱（信号格全白），6表示信号最强（最大5格）
#define  SDK_ICON_INITSIGNAL   1  //初始信号强度 [最强信号为INITSIGNAL+5]

//点亮电池图标，则Mode的值设置为：[1，5]共5档，1表示电池最弱（电池外框），5表示电池最强（最大4格）
#define  SDK_ICON_INITBATTERY   1   //电池外框 [电池满为INITBATTERY+4]

//color, RGB
typedef enum
{
    COLOR_BLACK = 0x00000000,     //黑色
    COLOR_BLUE = 0X000000FF,      //蓝色
    COLOR_GREEN = 0X0000FF00,     //绿色
    COLOR_RED = 0X00FF0000,       //红色
    COLOR_WHITE = 0X00FFFFFF,     //白色
}E_SDK_LCD_COLOR;

s32 sdkLcdOpen(void);
s32 sdkLcdClose(void);

s32 sdkLcdSetFont(s8 *pszFontName, s8 *pszFontCharacter, u32 uiSize);
s32 sdkLcdFillRow(u32 uiRow, u32 uiCol, const u8 *pszStr, u8 ucAtr);
s32 sdkLcdRowAt(u32 uiRow, u32 uiCol, const u8 *pszStr, u8 ucAtr);
s32 sdkLcdPixel(u32 uiX, u32 uiY, u32 uiColor);
s32 sdkLcdLine(u32 uiStartX, u32 uiEndX, u32 uiStartY, u32 uiEndY, u32 uiColor);
s32 sdkLcdDrawFrame(u32 uiStartX, u32 uiStartY, u32 uiWidth, u32 uiHeight, u32 uiColor);
s32 sdkLcdClearRow(u8 ucRow);
s32 sdkLcdClearRows(u8 ucStartRow, u8 ucEndRow);
s32 sdkLcdClearLine(u8 ucRow, u32 uiStartCol, u32 uiEndCol);
s32 sdkLcdClear(void);
s32 sdkLcdBrushScreen(void);

s32 sdkLcdDispBmp(u32 uiX, u32 uiY, u8 *pBitmap);
s32 sdkLcdDispBmpFile(u32 uiX, u32 uiY, u8 *pFileName);
s32 sdkLcdProcessBar(u32 uiStartX, u32 uiStartY, u32 uiWidth, u32 uiHeight, u32 uiCurrentX);
s32 sdkLcdCaptureScreen(void);
s32 sdkLcdRestoreScreen(void);

s32 sdkLcdGetPixel(u32 *pucWidth, u32 *pucHeigh);
s32 sdkLcdGetMaxRow(u8 *pucMaxRow, u8 *pucMaxCharNum);
void sdkLcdSetContrast(u8 ucContrast);
void sdkLcdLight(BOOL bMode);
void sdkLcdSetIcon(u8 ucIconNo, u32 uiMode);
void sdkLcdSetFontColor(u32 uiColor);
void sdkLcdSetBgColor(u32 uiColor);
s32 sdkLcdDispBitmap(u32 uiX, u32 uiY, u8* pcLogoBitmap, u32 uiLogoWidth, u32 uiLogoHeight);

#ifdef __cplusplus
    }
#endif

#endif

