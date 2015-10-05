/********************************************************************
文件名 : sdkDisp.h
描  述 : public库里面和LCD有关的操作
版  权 : 长城开发
作  者 : DJ Chen
修改记录:
    日期              修改人  修改内容
    2014-02-18 14:35  DJ Chen  创建
********************************************************************/
#ifndef PUBLIC_SDKDISP_H_
#define PUBLIC_SDKDISP_H_

#ifdef __cplusplus
    extern "C" {
#endif

#define SDK_DISP_MAXLEN       50
#define SDK_DISP_MAXLINE       32

#define SDK_DISP_LINE   12

#define SDK_DISP_KEYINIT              0
#define SDK_DISP_KEYUP                1
#define SDK_DISP_KEYDOWN              2



typedef struct
{
    u8 szDispData[SDK_DISP_MAXLINE][SDK_DISP_MAXLEN];//多屏显示
    u8 szDispIndex[SDK_DISP_MAXLINE];           //索引
    u8 szCurDispAttr[SDK_DISP_MAXLINE];      //当前行显示属性
    u8 ucStartLine;        //开始显示的行
    u8 ucTotalDispLine;    //总共能够显示的行数
    u8 ucTotalDispNum;     //总共需要显示的行数
    u8 ucCurDispLine;      //当前显示的行数
    u8 ucEndDispLine;      //显示的结束行数

}T_SDK_MULT_DISP;


s32 sdkDispMsg(u8 ucStartRow, const u8 *pszStr);
s32 sdkDispMulLine(u8 ucStartRow, const u8 *pszStr);
s32 sdkDispDynamicList(const u8 *pszTitle, const u8 *pszDispData, u32 uiOvertimer);
s32 sdkDispMsgDlg(const u8 *pszStr, u32 uiOvertimer);

#ifdef __cplusplus
    }
#endif

#endif

