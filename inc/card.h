/**
 * @file     Global.h
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
#ifndef CARD_H_
#define CARD_H_

extern void DemoEnterCardModule(void);

extern void DemoMagcardModule(void);
extern void DemoTestPsamModule(void);
extern void DemoTestCardslotModule(void);
extern void DemoTest4442CardModule(void);
extern void DemoTest4428CardModule(void);
extern void InitPASM(void);
extern void TestSdkPSAMCArd(void);
extern void DemoTestIccDispText(u8 const *pText);
extern void DemoTest4442CardModule(void);
extern void DemoTest4428CardModule(void);
extern void DemoDisplayCardNo(const u8 *pstCardNO);
extern void DemoMifareCardModule(void);
extern void DemoABFCardModule(void);
extern void DemoEnterRfModule(void);
#endif





