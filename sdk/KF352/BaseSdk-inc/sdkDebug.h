/********************************************************************
�ļ��� : sdkMngDebug.h
��  �� : ����ģ��
��  Ȩ : ���ǿ���
��  �� : ������
�޸ļ�¼:
    ����              �޸���  �޸�����
    2013-12-24 09:49  ������  ����
********************************************************************/
#ifndef BASE_SDKDEBUG_H_
#define BASE_SDKDEBUG_H_

#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#ifdef __cplusplus
    extern "C" {
#endif

//���Դ��뿪��
#define ZWH_SDK_TEST

#define SDK_LOG_FILE "DebugLog.txt"

//������Ϣ���Ŀ��
typedef enum
{
    SDK_DEBUG_TARGET_COM,     //����
    SDK_DEBUG_TARGET_SCREEN,  //LCD��Ļ
    SDK_DEBUG_TARGET_MINIUSB, //USB�˿�
    SDK_DEUBG_TARGET_PRINT,   //��ӡ���
    SDK_DEUBG_TARGET_LOG,     //������־
}E_SDK_DEBUG_OUT_TARGET;

typedef struct
{
    BOOL bIsInTest;                 //�Ƿ��ڲ���״̫�£�����ڲ���״��Assert��������� 1:Test 0:not test status
    BOOL bIsOutTag;                 //�Ƿ����TAG,�ļ����к���Ϣ Assert����Ӱ��
    E_SDK_DEBUG_OUT_TARGET eTarget; //���Ŀ��//output target
}T_SDK_DEBUG_FILTER;


#ifdef KF_DEBUG
//�˺����ⲿ���ܵ�
s32 PrivateDebugInit(const T_SDK_DEBUG_FILTER *ptDebugFilter, char const **ppasWhiteList, u32 uiWhiteListLen);
void PrivateAssert(const u8* pszFile, u32 uiLine);
void PrivateTraceHex(const u8 *pszTag, const u8 *pszInfo, const u8 *pszSrc, u32 uiLen);
void PrivateTrace(u8 const *pszTag, u8 const*  pszFile, u32 uiLine,  char const *phexFmt, ...);
void PrivateFinalErr(const u8 * pszMsn, const u8 *pszFile, u32 uiLine);

//SDK,APP��ֱ�ӵ������º�
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

