/**
 * @file     finger.c
 * @brief    SDK(software development kit) sample code
 * @author   henry
 * @date     2015/08/08
 * @version  V001
 */

#include "Global.h"

void DemoFingerPrint(void)
{
	u16 key = 0;
	s32 timerid = 0;
	s32 TimerOver = AUTORET_TIME;
	sdkLcdClear();
	sdkLcdFillRow (SDK_LCD_LINE1,0,(u8 *)"FINGER MODULE", M_UCTR);
	sdkLcdFillRow (SDK_LCD_LINE2,0,(u8 *)"1.Test Finger",   L_UCTR);
	sdkLcdFillRow (SDK_LCD_LINE3,0,(u8 *)"2.Verify Finger",	L_UCTR);
	sdkLcdFillRow (SDK_LCD_LINE4,0,(u8 *)"3.Write Finger",	 	L_UCTR);
	sdkLcdBrushScreen();
	sdkKbGetKey();
	timerid = sdkSysGetTimerCount();
	while (1) 
	{
		if (sdkSysGetTimerEnd(timerid, TimerOver))
		{
			DemoShowMainMenu();
			return;
		}
		key = sdkKbGetKey();
		switch(key)
		{
			case SDK_KEY_1:			DemoTestFingerModule();	  	break;		//Test Magnetic Card
			case SDK_KEY_2:			DemoVerifyFingerModule(); 		break;		//Test Mifare Card
			case SDK_KEY_3:			DemoWriteFingerModule();  		break;		//Test Psam Card
			case SDK_KEY_CANCEL:	DemoShowMainMenu();		  	break;		//back to mainmenu
			default: break;
		}
	}
		
		
}

BOOL DemoTestFingerModule(void)
{
	return TRUE;
}


void DemoVerifyFingerModule(void)
{

}

void DemoWriteFingerModule(void)
{

}


