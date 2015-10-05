#include "Global.h"

void DemoRegistrasi(void) 
{
	u32 				uiLen;
	s32 				iRet;
	T_SDK_PT_BIR 	tBir;
	T_SDK_PT_BIR 	*pNewTemplate;
	T_SDK_PT_BIR 	*pFingerTemp;
	u8 				nik[1000], name[1000];
	u32 				uiMinLen 	= 1;
	u32 				uiMaxLen 	= 100;
	u32 				uiMode		=SDK_INPUT_CHAR;
	u32 				uiMode2		=SDK_INPUT_NUM;
	u32 				uiDispRow 	= SDK_LCD_LINE2;
	u32 				uiOvertimer = 0;
	u8 				szGrabbedData[5000];
	
	uiMode &= ~SDK_INPUT_LEFT;
	uiMode &= ~SDK_INPUT_DISP;

	memset(nik, 0x00, sizeof(nik));
	DemoDisplayInfo(SDK_LCD_LINE1, (u8 *)"INSERT NIK :", M_UCTR);
	sdkKbInput(uiDispRow, 0, nik, uiMinLen, uiMaxLen, uiMode2, uiOvertimer);

	memset(name, 0x00, sizeof(name));
	DemoDisplayInfo(SDK_LCD_LINE1, (u8 *)"INSERT NAME :", M_UCTR);
	sdkKbInput(uiDispRow, 0, name, uiMinLen, uiMaxLen, uiMode, uiOvertimer);
	
	iRet = sdkFPOpen();
	if(iRet != SDK_OK)
	{
		DemoDisplayInfo(SDK_LCD_LINE4, (u8 *)"FPOpen SDK FAILED..", M_UCTR);
		return;
	}
	else 
		DemoDisplayInfo(SDK_LCD_LINE4, (u8 *)"FPOpen SDK OK..", M_UCTR);

	iRet = sdkFPInitialize();
	if(iRet != SDK_OK)
	{
		DemoDisplayInfo(SDK_LCD_LINE4, (u8 *)"FPInitialize SDK FAILED..", M_UCTR);
		return;
	}
	else 
		DemoDisplayInfo(SDK_LCD_LINE4, (u8 *)"FPInitialize SDK OK..", M_UCTR);

	iRet = sdkFPDeleteAllFingers();
	if(iRet != SDK_OK)
	{
		DemoDisplayInfo(SDK_LCD_LINE4, (u8 *)"FPDeleteAllFingers SDK FAILED..", M_UCTR);
			return;
	}
	else 
		DemoDisplayInfo(SDK_LCD_LINE4, (u8 *)"FPDeleteAllFingers SDK OK..", M_UCTR);

	
	DemoDisplayInfo(SDK_LCD_LINE3, (u8 *)"PUT FINGER..", M_UCTR);
	memset(&tBir, 0, sizeof(T_SDK_PT_BIR));
	pNewTemplate = &tBir;
	iRet = sdkFPEnroll(&pNewTemplate);
	
	if(iRet != SDK_OK)
	{
		DemoDisplayInfo(SDK_LCD_LINE4, (u8 *)"FPEnroll SDK FAILED..", M_UCTR);
		return;
	}
	else 
		DemoDisplayInfo(SDK_LCD_LINE4, (u8 *)"FPEnroll SDK OK..", M_UCTR);
	
	pFingerTemp = (T_SDK_PT_BIR*)malloc(0x800);
	uiLen = pNewTemplate->Header.Length;
	memcpy(pFingerTemp, pNewTemplate, uiLen);
	iRet = sdkFPVerify(&pFingerTemp);
	if(iRet != SDK_OK)
	{
		DemoDisplayInfo(SDK_LCD_LINE4, (u8 *)"FPVerify SDK FAILED..", M_UCTR);
		return;
	}
	else 
		DemoDisplayInfo(SDK_LCD_LINE4, (u8 *)"FPVerify SDK OK..", M_UCTR);
	

	memset(szGrabbedData, 0, sizeof(szGrabbedData));
	iRet = sdkFPGrab(szGrabbedData, &uiLen);
	if(iRet == SDK_OK) 
	{
		sdkLcdFillRow (SDK_LCD_LINE4,0,(u8 *)"SDK_OK", M_UCTR);
	    	if (uiLen > 0)
	    	{
			DisplayFinger(szGrabbedData, uiLen);
			DemoPersoCard(szGrabbedData, nik, name);
			PrintData(REGISTRATION);
	    	}
	}
	else
		DemoDisplayInfo(SDK_LCD_LINE4, (u8 *)"SDK FAILED..", M_UCTR);
	
	sdkFPClose();
	return ;
}

void DisplayFinger(const u8 *pstFinger, u32 lenFinger)
{
	char dspBuf[5000];
	char dspLen[10];
	if (NULL == pstFinger)
	{
		return;
	}
	memset(dspLen, 0x00, sizeof(dspLen));
	memset(dspBuf, 0x00, sizeof(dspBuf));
	sprintf(dspLen,"\nLen = %u", lenFinger);

	printf(dspLen);
	ConvertDataToHexString(pstFinger, lenFinger, dspBuf);
	
	sdkLcdClear();
	sdkLcdFillRow (SDK_LCD_LINE2 , 0 , (u8 *)"FINGER:" , 	   L_UCTR);
    	sdkLcdSetFont(FONT_COURIER_NEW, FONT_CHARSET_ASCII, 24);
	sdkLcdFillRow (SDK_LCD_LINE4 , 0 , (const u8 *)dspBuf, 	   L_UCTR);
	sdkLcdFillRow (SDK_LCD_LINE6 , 0 , (const u8 *)dspLen, 	   L_UCTR);
    	sdkLcdSetFont(FONT_COURIER_NEW, FONT_CHARSET_ASCII, 32);
	
	sdkLcdFillRow (SDK_LCD_LINE7, 0 , (u8 *)"PLS CONFIRM..." , M_UCTR);
	sdkLcdBrushScreen();
	return DemoWaitKeyToBack(DemoShowMainMenu);
}

void ConvertDataToHexString (const s8 *in, u32 in_len, s8 *out)
{
	s32			i;
	s8			*ptr;

	ptr = out;
	for (i=0; i<in_len; i++)
	{
		sprintf (ptr,"%02X",(u8) *(in + i));
		ptr += 2;
	}
}



