/*!@file
********************************************************************************
Module: Common
file name: sdk_print.h

function: system file
Author: CRD by Zumiao Yu
version: 1.0.0
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
modify :
date              version          by           fixed
2010/02/23    1.0.0             Yu            create
*******************************************************************************/
#ifndef _SDK_PIRNT_H_
#include "sdk_font.h"

#define _SDK_PIRNT_H_
#define PRINT_FILENAME "/dev/lp0"

//  Font Mode
#define PRN_MODE_NORMAL   0 // normal height, normal width
#define PRN_MODE_DBWIDTH  1 // normal height, double width
#define PRN_MODE_DBHEIGHT 2 // double height, normal width
#define PRN_MODE_DBBOTH   3 // double height, double width

#define PRN_FONT12  0   //使用12x12字体打印
#define PRN_FONT16  1   //使用16x16字体打印
#define PRN_FONT24  2   //使用24x24字体打印
#define PRN_FONT2412 3

#define DEFAULT_DARKNESS    7                           //默认打印色深
#define DEFAULT_FONTTYPE    PRN_FONT12      //默认打印字体
#define DEFAULT_LINESPACE   2                           //默认行间距为4点行

#define MAX_DARKNESS    15                              //最大色深值
#define MIN_DARKNESS    1                                   //最小色深值

#define PRN_FAILURE                 -1
#define PRN_OUT_OF_PAPER            -2
#define PRN_ABORT_TEMP              -3
#define  PRINT_MAX_WIDTH 384    //一行打印最大宽度(单位:pixel),字节=PRINT_MAX_WIDTH/8

//填充字符的结构
typedef struct
{
    char *pcInfo;       //要打印的字符串
    unsigned char cFont;        //字体 同LCD显示的字体
    unsigned char cInterval;    //字间隔 单位:pixel 暂未实现
    unsigned char cAtt;         //字属性 =0白底黑字 =FONT_CONTRAST黑底白字
} __attribute__((packed)) T_PRN_INFOATT;

#define PRN_FAILURE                 -1  //打印失败
#define PRN_OUT_OF_PAPER            -2  //缺纸
#define PRN_ABORT_TEMP              -3  //温度过高

#define MAX_DARKNESS    15              //最大色深值
#define MIN_DARKNESS    1               //最小色深值

#ifdef __cplusplus
extern "C" {
#endif

//打印初始化
//返 回 值: 0成功
//          -1  设备初始化失败
int sdk_PrnOpen(void);

//打印设备关闭
//返 回 值: 0成功
//          -1  关闭设备失败
int sdk_PrnClose(void);

//设置打印灰度
//level : 色深值 MIN_DARKNESS>= level <=MAX_DARKNESS
//返 回 值: 0成功
//          -1  失败
//          -2  打印设备未初始化
//          -3  参数错误
int sdk_PrnSetGray(unsigned char level);

//设置打印速度
//mode : 1-快速; 2-慢速
//返 回 值: 0成功
//          -1  失败
//          -2  打印设备未初始化
//          -3  参数错误
//备注:
//  默认打印速度为快速打印
int sdk_PrnSetSpeed(int mode);

/*! @function
********************************************************************************
函数名: Sdk_FillPrnData
功能  : 填充字符串的打印buffer
参数  : ptPrnBoard 打印模板的结构；
        ptPrnStrAtt 打印图形的结构；
返回值:
        0 成功
        -1 出错
备注  :
*******************************************************************************/
int sdk_PrnFillStr(T_FONT_BOARD *ptPrnBoard, T_PRN_INFOATT* ptPrnStrAtt);

/*! @function
********************************************************************************
函数名: Sdk_FillPrnData
功能  : 填充图形的打印buffer
参数  : ptPrnBoard 打印模板的结构；
        ptPrnBitmapAtt 打印图形的结构；
返回值:
        0 成功
        -1 出错
备注  :
*******************************************************************************/
int sdk_PrnFillBitmap(T_FONT_BOARD *ptPrnBoard, T_FONT_BOARD *ptPrnBitmapAtt);

//启动打印机开始打印
//DotLine:打印buffer的点行数
//返 回 值: >=0 成功打印的数据长度
//          -1  打印失败
//          -2  缺纸
//          -3  温度过高
int sdk_PrnStart(unsigned char* pcPrnData, uint DotLine);

//获取当前打印状态
//返 回 值: 0成功
//          -1  打印设备未初始化
//          -2  缺纸
//          -3  温度过高
int sdk_PrnGetStatus(void);

//函 数 名: PRN_PaperForward
//描    述: 向前走指定点行的纸
//全局变量: 无
//输入参数: DotLine:走纸点行数
//输出参数: 无
//返 回 值: 0成功, -1失败,-2打印设备未初始化
int sdk_PrnPaperFeed(unsigned short DotLine);

//函 数 名: sdk_PrnFill
//描    述: 将str指定的字符串填入打印缓冲区
//全局变量: 无
//输入参数: str:要打印的字符串
//输出参数: 无
//返 回 值:
//          PRN_FAILURE(-1)         :打印失败
//          PRN_OUT_OF_PAPER(-2)    :缺纸
//          PRN_ABORT_TEMP(-3)      :温度过高
//          0                       :成功
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者:
//修改日期:
//备    注:
int sdk_PrnFill( unsigned char *str );

//函 数 名: sdk_PrnExecute
//描    述: 调用该函数将启动打印机打印缓存中的数据.
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值:
//          PRN_FAILURE(-1)         :打印失败
//          PRN_OUT_OF_PAPER(-2)    :缺纸
//          PRN_ABORT_TEMP(-3)      :温度过高
//          其它值:                 :成功打印的数据长度
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者:
//修改日期:
//备    注:
//          不管打印是否成功,打印缓存中的数据均会被清空.
int sdk_PrnExecute(void);

//函 数 名: sdk_PrnSetFontMode
//描    述: 设置打印字体模式
//全局变量: 无
//输入参数: mode:字体模式, 可以是下列值之一
//          PRN_MODE_NORMAL     :标准打印
//          PRN_MODE_DBWIDTH    :倍宽打印
//          PRN_MODE_DBHEIGHT   :倍高打印
//          PRN_MODE_DBBOTH     :倍宽倍高打印
//输出参数: 无
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者:
//修改日期:
//备    注: 如果不设置, 默认是PRN_MODE_NORMAL模式
void sdk_PrnSetFontMode(int mode );

/********************************************************************
函数功能: 获取打印字体模式
输入参数: 
输出参数: 
返 回 值: 打印字体模式
修改信息: 2014-05-15  吴雪良  创建
********************************************************************/
int sdk_PrnGetFontMode();

//函 数 名: sdk_PrnSetFontType
//描    述: 设置打印字体大小(目前支持:12x12, 16x16, 24x24)
//全局变量: 无
//输入参数: font_type:必须是下列值之一
//          PRN_FONT12
//          PRN_FONT16
//          PRN_FONT24
//输出参数: 无
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者:
//修改日期:
//备    注:
void sdk_PrnSetFontType( int font_type );

/********************************************************************
函数功能: 获取打印字体大小
输入参数: 
输出参数: 
返 回 值: 打印字体大小
修改信息: 2014-05-15  吴雪良  创建
********************************************************************/
int sdk_PrnGetFontType();

//函 数 名: sdk_PrnBlankDotLines
//描    述: 往打印缓存中填充空白点行
//全局变量: 无
//输入参数: dot_lines:要打印的点行数
//输出参数: 无
//返 回 值:
//          PRN_FAILURE(-1)             :打印失败
//          PRN_OUT_OF_PAPER(-2)    :缺纸
//          PRN_ABORT_TEMP(-3)      :温度过高
//          0                       :成功
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者:
//修改日期:
//备    注: 1.填充过程中若发现打印缓冲区满将自动打印,之后会继续填充数据
//          2.若打印过程出错,将中断填充过程并返回非0值
int sdk_PrnBlankDotLines( unsigned short dot_lines );

#ifdef __cplusplus
}
#endif

#endif

