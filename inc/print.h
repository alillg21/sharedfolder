/** 
 * @file     print.h
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
#ifndef PRINT_H_
#define PRINT_H_

#define 	REGISTRATION 0
#define 	SALE 1

typedef struct _LOGOINFO
{
	s8 asCompany[127+1];
	s8 asPhone[127+1];
	s8 asFax[127+1];
	s8 asWebsite[127+1];
}LOGOINFO;



extern void DemoEnterPrintModule(void);
extern void DemoPrintPhotoTest(void);
extern void DemoInitTestContentInfo(LOGOINFO *pInfo);
extern void DemoPrintTest(void);
extern void DemoPrintQRcodeTest(void);
extern void DemoPrintBarcodeTest(void);

s32 	PrintData(s32 transaction);
void SalePrintData();
void RegistrationPrintData();

s8	buffer1[200];
s8	buffer2[200];
s8	buffer3[200];
s8	buffer4[200];
s8	buffer5[200];
s8	buffer6[200];
#endif





