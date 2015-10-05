/**
 * @file     tool.c
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
void DemoEnterToolsModule(void)
{
    s32 key = 0;
    s32 timerid = 0;
	s32 timerover = AUTORET_TIME;
    timerid = sdkSysGetTimerCount();
    while (1)
    {
        sdkLcdClear();
        sdkLcdFillRow(SDK_LCD_LINE1, 0, (u8 *)"TOOLS MODULE", M_UCTR);
        sdkLcdFillRow(SDK_LCD_LINE2, 0, (u8 *)"1.DES ENCRYPTION",  L_UCTR);
        sdkLcdFillRow(SDK_LCD_LINE3, 0, (u8 *)"2.DES DECRYPTION",  L_UCTR);
        sdkLcdFillRow(SDK_LCD_LINE4, 0, (u8 *)"3.MD5 ENCRYPTION",  L_UCTR);
        sdkLcdFillRow(SDK_LCD_LINE5, 0, (u8 *)"4.RSA ENCRYPTION",  L_UCTR);
        sdkLcdFillRow(SDK_LCD_LINE6, 0, (u8 *)"5.RSA DECRYPTION",  L_UCTR);
        sdkLcdBrushScreen();
  	    //timeout?
        if (sdkSysGetTimerEnd(timerid,timerover))
        {
            //DemoShowWelCome();
            return;
        }
        key = sdkKbGetKey();
        switch(key)
        {
			case SDK_KEY_CANCEL:	DemoShowMainMenu();		    break;
			case SDK_KEY_1:
			case SDK_KEY_2:
			case SDK_KEY_3:
			case SDK_KEY_4:
			case SDK_KEY_5:
			default: break;
        }
     }

}
