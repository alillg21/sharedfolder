/********************************************************************
文件名 : sdkMngDebug.h
描  述 : 调试模块
版  权 : 长城开发
作  者 : 张文晖
修改记录:
    日期              修改人  修改内容
    2013-12-24 09:49  张文晖  创建
********************************************************************/
#ifndef BASE_SDKDEBUG_H_
#define BASE_SDKDEBUG_H_

#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#ifdef __cplusplus
    extern "C" {
#endif

//调试代码开关
#define ZWH_SDK_TEST

#define SDK_LOG_FILE "DebugLog.txt"

//调试信息输出目标
typedef enum
{
    SDK_DEBUG_TARGET_COM,     //串口
    SDK_DEBUG_TARGET_SCREEN,  //LCD屏幕
    SDK_DEBUG_TARGET_MINIUSB, //USB端口
    SDK_DEUBG_TARGET_PRINT,   //打印输出
    SDK_DEUBG_TARGET_LOG,     //保存日志
}E_SDK_DEBUG_OUT_TARGET;

typedef struct
{
    BOOL bIsInTest;                 //是否在测试状太下，如果在测试状下Assert不会断下来 1:Test 0:not test status
    BOOL bIsOutTag;                 //是否输出TAG,文件，行号信息 Assert不受影响
    E_SDK_DEBUG_OUT_TARGET eTarget; //输出目标//output target
}T_SDK_DEBUG_FILTER;


#ifdef KF_DEBUG
//此函数外部不能调
s32 PrivateDebugInit(const T_SDK_DEBUG_FILTER *ptDebugFilter, char const **ppasWhiteList, u32 uiWhiteListLen);
void PrivateAssert(const u8* pszFile, u32 uiLine);
void PrivateTraceHex(const u8 *pszTag, const u8 *pszInfo, const u8 *pszSrc, u32 uiLen);
void PrivateTrace(u8 const *pszTag, u8 const*  pszFile, u32 uiLine,  char const *phexFmt, ...);
void PrivateFinalErr(const u8 * pszMsn, const u8 *pszFile, u32 uiLine);

//SDK,APP请直接调用以下宏
#define sdkDebugInit(ptDebugFilter, ppasWhiteList, uiWhiteListLen) PrivateDebugInit(ptDebugFilter, ppasWhiteList, uiWhiteListLen)
#define sdkTrace(ptag, ...)  PrivateTrace((u8 const*)ptag, (u8 const*)__FILE__,  __LINE__, ##__VA_ARGS__)
#define sdkTraceHex(pszTag, pszInfo, phexDate, uiLen)   PrivateTraceHex((u8 const*)pszTag, (u8 const*)pszInfo, phexDate, uiLen)
#define sdkAssert(n) ((void)((n) || (PrivateAssert((const u8 *)__FILE__, __LINE__),0)))
#define sdkVerify(n)   (sdkAssert(n))
#define sdkFinalErr(pszMsn) ((PrivateFinalErr((u8 const*)pszMsn,(u8 const*)__FILE__, __LINE__)))
#else
#define sdkDebugInit(ptDebugFilter, ppasWhiteList, uiWhiteListLen) 
#define sdkTrace(ptag, ...) 
#define sdkTraceHex(pszTag, pszInfo, phexDate, uiLen) 
#define sdkAssert(n) (void)(n) 
#define sdkVerify(n) (void)(n) 
#define sdkFinalErr(pszMsn) 
#endif


#ifdef __cplusplus
    }
#endif

#endif

