/*!@file
********************************************************************************
Module: Common
file name: sdk_beep.h

function: system file
Author: CRD by Qiling Liu
version: 1.0.0
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
modify :
date              version          by           fixed
2010/02/23    1.0.0             Liu           create
*******************************************************************************/
#ifndef _sdk_BEEP_H_
#define _sdk_BEEP_H_

#ifdef __cplusplus
extern "C" {
#endif

//函 数 名: sdk_CloseBeep
//描    述: 打开蜂鸣器
//输入参数: 无
//输出参数: 无
//返 回 值: 0 成功, -1 打开蜂鸣器失败
//备    注:
int sdk_OpenBeep(void);

//函 数 名: sdk_CloseBeep
//描    述: 关闭蜂鸣器
//输入参数: 无
//输出参数: 无
//返 回 值: 0 成功, -1 关闭蜂鸣器失败
//备    注:
int sdk_CloseBeep(void);

/*
name       :sdk_Beep
desc.      :Beep with the current frequency during the default period(100 millisecond)
input para :None
return     :0   Success
            -1  Beeper is disabled
*/
int sdk_Beep();

#ifdef __cplusplus
}
#endif

#endif

