/**
 * @file     print.c
 * @brief    SDK(software development kit) sample code
 * @details  only for reference
 * @author   song
 * @date     2014/04/22
 * @version  V001
 * @par Copyright (c):
 *           KAIFA SHENZHEN CHINA
 * @par History:
 *   version: V001
 */

#include "Global.h"



/****************************************************************************
*Descriptions:just like main face,Standby interface.show welcome infomation
*Input:void
*Output:void
*Return:void
*Date:20140423
*Author:song
*Remark:none
****************************************************************************/
void DemoEnterPrintModule(void)
{
	s32 key = 0;
	s32 timerid = 0;
	s32 timerover = AUTORET_TIME;

	sdkLcdClear();
	sdkLcdFillRow(SDK_LCD_LINE1,0, (u8 *)"PRINT MODULE", M_UCTR);
	sdkLcdFillRow(SDK_LCD_LINE2,0, (u8 *)"1.PRINT TEST", L_UCTR);
    sdkLcdFillRow(SDK_LCD_LINE3,0, (u8 *)"2.PRINT PHOTO", L_UCTR);
    sdkLcdFillRow(SDK_LCD_LINE4,0, (u8 *)"3.PRINT QRCODE", L_UCTR);
    sdkLcdFillRow(SDK_LCD_LINE5,0, (u8 *)"4.PRINT BARCODE", L_UCTR);
	sdkLcdBrushScreen();

	sdkKbFlush();
	timerid = sdkSysGetTimerCount();
	while (1)
	{
		if (sdkSysGetTimerEnd(timerid,timerover))
        {
            DemoShowMainMenu();
            return;
        }
		key = sdkKbGetKey();
		switch (key)
		{
			case SDK_KEY_1:			DemoPrintTest();		 break;	//specified line display
			case SDK_KEY_2:			DemoPrintPhotoTest(); 	 break;	//terminal screen pixels
			case SDK_KEY_3:			DemoPrintQRcodeTest(); 		 break;	//specified photo display
			case SDK_KEY_4:			DemoPrintBarcodeTest(); 	 break;	//progressbar display
			case SDK_KEY_CANCEL:	DemoShowMainMenu();			 break;	//back to mainmenu
			default:break;
		}
	}
	return ;

}

/*========================================================================
**Function Name:DemoPrintTest
**Descriptions:print string test with different character
**Input Parameters:
**Returned Value:
**Creator:lingcongzeng
**Date:20140427
*========================================================================*/
void DemoPrintTest(void)
{
	LOGOINFO stinfo;
	s32 siRet = 0;

    siRet = sdkPrnStatus();//check printer status,SDK_PRN_STATUS_OK/SDK_PRN_STATUS_PAPEROUT/SDK_PRN_STATUS_TOOHEAT/SDK_PRN_STATUS_FAULT
    if (SDK_OK != siRet)
    {
        DemoDisplayInfo(SDK_LCD_LINE4,(u8 *)"PRINTER IS NOT READY!",M_UCTR);
    	return DemoWaitKeyToBack(DemoEnterPrintModule);
    }
    memset(&stinfo,0,sizeof(LOGOINFO));
    DemoInitTestContentInfo(&stinfo);
	sdkPrnSetFont(FONT_SONG, FONT_CHARSET_GB18030, 20);
	sdkPrnFillBuffer((u8*)"------------------START----------------------",PRN_MODE_MIDDLE,PRN_MODE_NORMAL,0);
	sdkPrnFillBuffer((u8*)stinfo.asCompany, PRN_MODE_MIDDLE, PRN_MODE_NORMAL, 0);
	sdkPrnFillBuffer((u8*)stinfo.asPhone, PRN_MODE_MIDDLE, PRN_MODE_NORMAL, 0);
	sdkPrnFillBuffer((u8*)stinfo.asFax, PRN_MODE_MIDDLE, PRN_MODE_NORMAL, 0);
	sdkPrnFillBuffer((u8*)stinfo.asWebsite, PRN_MODE_MIDDLE, PRN_MODE_NORMAL, 0);
	sdkPrnFillBuffer((u8*)"-------------------END---------------------",PRN_MODE_MIDDLE,PRN_MODE_NORMAL,0);
	DemoDisplayInfo(SDK_LCD_LINE3,(u8 *)"PRINTING...",M_UCTR);
    siRet = sdkPrintStart();//print buffer data ,start...
    if (SDK_OK == siRet)
    {
        DemoDisplayInfo(SDK_LCD_LINE4,(u8 *)"PRINT OK...",M_UCTR);
    }
    else
    {
        DemoDisplayInfo(SDK_LCD_LINE4,(u8 *)"PRINT ERROR...",M_UCTR);
    }
	return DemoWaitKeyToBack(DemoEnterPrintModule);
}

/*========================================================================
**Function Name:DemoInitTestContentInfo
**Descriptions:init printing string info
**Input Parameters:
**Returned Value:
**Creator:lingcongzeng
**Date:20140427
*========================================================================*/
void DemoInitTestContentInfo(LOGOINFO *pInfo)
{
	if (NULL == pInfo)
	{
		return;
	}
	strcpy(pInfo->asCompany,"Shenzhen Kaifa Technology Co., Ltd.");
	strcpy(pInfo->asPhone,"(+86)0755-83032000");
	strcpy(pInfo->asFax,"(+86)0755-83275054");
	strcpy(pInfo->asWebsite,"www.kaifa.cn");
	return ;
}

/*========================================================================
**Function Name:DemoPrintPhotoTest
**Descriptions:specified photo in corresponding directory,print it
**Input Parameters:
**Returned Value:
**Creator:lingcongzeng
**Date:20140427
*========================================================================*/
void DemoPrintPhotoTest(void)
{
	u8 fn[32] = {0};
	s32 siRet = 0;

	strcpy((s8 *)fn, "demo.bmp");//copy this bmp file to the directory that the same as app
	if(SDK_OK == sdkFileAccess(fn))
	{
		sdkPrintBitMap(fn, 0);
		siRet = sdkPrintStart();
        sdkPrnPaperForward(100);//paper forward 100 point line,only for reference
		if (SDK_OK == siRet)
		{
			DemoDisplayInfo(SDK_LCD_LINE3,(u8 *)"PRINT SUCCEED",M_UCTR);
		}
	}
	else
	{
		DemoDisplayInfo(SDK_LCD_LINE3,(u8 *)"NO THIS FILE",M_UCTR);
	}

	return DemoWaitKeyToBack(DemoEnterPrintModule);
}

/*========================================================================
**Function Name:DemoPrintPhotoTest
**Descriptions:specified photo in corresponding directory,print it
**Input Parameters:
**Returned Value:
**Creator:lingcongzeng
**Date:20140427
*========================================================================*/
void DemoPrintBarcodeTest(void)
{
	sdkLcdClear();
	sdkPrnBarcode((u8 *)"1234567890", 0x00, 0x00, 0);

	DemoDisplayInfo(SDK_LCD_LINE3,(u8 *)"PRINTING...",M_UCTR);
    sdkPrintStart();
    sdkPrnPaperForward(100);
	DemoDisplayInfo(SDK_LCD_LINE4,(u8 *)"PRINT OK...",M_UCTR);

	return DemoWaitKeyToBack(DemoEnterPrintModule);
}

/*========================================================================
**Function Name:DemoPrintPhotoTest
**Descriptions:specified photo in corresponding directory,print it
**Input Parameters:
**Returned Value:
**Creator:lingcongzeng
**Date:20140427
*========================================================================*/
void DemoPrintQRcodeTest(void)
{
	sdkLcdClear();
	sdkPrnQRCode((char *)"Chinese,English,123456",3,0);

	DemoDisplayInfo(SDK_LCD_LINE3,(u8 *)"PRINTING...",M_UCTR);
    	sdkPrintStart();
    	sdkPrnPaperForward(100);
	DemoDisplayInfo(SDK_LCD_LINE4,(u8 *)"PRINT OK...",M_UCTR);

	return DemoWaitKeyToBack(DemoEnterPrintModule);
}


s32 PrintData(s32 transaction)
{
	s32  iRet;

	iRet = sdkPrnOpen();
	if(iRet != SDK_OK)
		return 0;

	sdkPrnSetFont(FONT_SONG, FONT_CHARSET_GB18030, 20);
	DemoDisplayInfo(SDK_LCD_LINE3,(u8 *)"PRINTING...",M_UCTR);
	
	switch(transaction)
	{
		case REGISTRATION :
			RegistrationPrintData();
			break;
			
		default:
			break;
	}
	iRet = sdkPrintStart();
	sdkPrnClose();
	return 1;
}

void SalePrintData()
{
	sdkPrnFillBuffer((u8*)"SALE", PRN_MODE_MIDDLE, PRN_MODE_NORMAL, 0);
	sdkPrnFillBuffer((u8*)buffer1, PRN_MODE_LEFT, PRN_MODE_NORMAL, 0);
	sdkPrnFillBuffer((u8*)buffer2, PRN_MODE_LEFT, PRN_MODE_NORMAL, 0);
	sdkPrnFillBuffer((u8*)buffer3, PRN_MODE_LEFT, PRN_MODE_NORMAL, 0);
}

void RegistrationPrintData()
{
	s8		str1[200];
	s8		str2[200];
	s8		str3[200];

	memset(str1, 0x00, sizeof(str1));
	memset(str2, 0x00, sizeof(str2));
	memset(str3, 0x00, sizeof(str3));
	
	sprintf(str1,"NIK         : %s",buffer1);
	sprintf(str2,"NAMA        : %s",buffer2);
	sprintf(str3,"SALDO       : %s",buffer3);
	
	sdkPrnFillBuffer((u8*)"REGISTRATION", PRN_MODE_MIDDLE, PRN_MODE_NORMAL, 0);
	sdkPrnFillBuffer((u8*)str1, PRN_MODE_LEFT, PRN_MODE_NORMAL, 0);
	sdkPrnFillBuffer((u8*)str2, PRN_MODE_LEFT, PRN_MODE_NORMAL, 0);
	sdkPrnFillBuffer((u8*)str3, PRN_MODE_LEFT, PRN_MODE_NORMAL, 0);

	sdkPrnFillBuffer((u8*)"Jaga Kerahasian Kartu Anda", PRN_MODE_MIDDLE, PRN_MODE_NORMAL, 0);
}