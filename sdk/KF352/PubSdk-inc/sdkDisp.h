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

s32 sdkDispMulLine(u8 ucStartRow, const u8 *pszStr);
s32 sdkDispDynamicList(const u8 *pszTitle, const u8 *pszDispData, u32 uiOvertimer);
s32 sdkDispMsgDlg(const u8 *pszStr, u32 uiOvertimer);

#ifdef __cplusplus
    }
#endif

#endif

