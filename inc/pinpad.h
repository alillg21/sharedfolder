/**
 * @file     pinpad.h
 * @brief    SDK(software development kit) sample code
 * @details  head files
 * @author   song
 * @date     2014/04/22
 * @version  V001
 * @par Copyright (c):
 *           KAIFA SHENZHEN CHINA
 * @par History:
 *   version: V001
 */
#ifndef PINPAD_H_
#define PINPAD_H_

typedef enum
{
    E_PED_DES_SINGLE, //DES type
    E_PED_DES_TRIPLE  // 3DES type
} DEMO_PED_DES_TYPE;

extern void DemoUpdateTmk(void);
extern void DemoUpdateWk(void);
extern void DemoDisplayAmount(void);
extern void DemoGetPedSn(void);
extern void DemoInputPin(void);
extern void DemosdkSetDesType(void);
extern void DemoUpdateTmkByTripleDes(void);
extern void DemoUpdateTmkBySingleDes(void);
extern void DemoUpdateWkBySingleDes(void);
extern void DemoUpdateWkByTripleDes(void);
extern void DemoCalcKeyCheckValue(u8 *pcout,const u8 *pkey);
extern void DemoEnterPinpadModule(void);
extern void DemoCalcMac(void);
#endif





