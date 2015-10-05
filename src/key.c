/**
 * @file     main.c
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
void DemoEnterKeyModule(void)
{
	s32 key = 0;
	s32 timerid = 0;
	s32 timerover = AUTORET_TIME;

	sdkLcdClear();
	sdkLcdFillRow(SDK_LCD_LINE1,0, (u8 *)"KEY MODULE", M_UCTR);
	sdkLcdFillRow(SDK_LCD_LINE2,0, (u8 *)"1.KEY VALUE", L_UCTR);
    sdkLcdFillRow(SDK_LCD_LINE3,0, (u8 *)"2.IP INPUT", L_UCTR);
	sdkLcdBrushScreen();
	sdkKbFlush();
	timerid = sdkSysGetTimerCount();
	while (1)
	{
		if(sdkSysGetTimerEnd(timerid,timerover))
        {
          //DemoShowWelCome();
          return;
        }
		key = sdkKbGetKey();
		if (key == SDK_KEY_1 )
		{
			DemoGetKeyValueVerfy();
			return;
		}
		else if (key == SDK_KEY_2)
        {
            DemoKeyInputIpAddr();
            return;
        }
        else if (key == SDK_KEY_CANCEL)
        {
            DemoShowMainMenu();
            return;
        }
	}
	return ;
}

/****************************************************************************
*Descriptions:just like mainface,Standby interface.show welcome infomation
*Input:void
*Output:void
*Return:void
*Date:20140423
*Author:song
*Remark:none
****************************************************************************/
void DemoGetKeyValueVerfy(void)
{
	u16 key = 0;
	s32 timerid = 0;
	s32 timerover = AUTORET_TIME;
	s8 sztemp[32] = {0};
	u8 szshowkey[32] = {0};

	sdkLcdClear();
	sdkLcdFillRow(SDK_LCD_LINE1,0, (u8 *)"KEY VALUE VERIFY", M_UCTR);
	sdkLcdFillRow(SDK_LCD_LINE5,0, (u8 *)"PRESS ANY KEY", M_UCTR);
	sdkLcdBrushScreen();
	timerid = sdkSysGetTimerCount();
	sdkKbFlush();
	sdkKbLight(1);//open kbLight
	while (1)
	{
		memset(sztemp, 0, sizeof(sztemp));
		if (sdkSysGetTimerEnd(timerid,timerover))
        {
    		return DemoEnterKeyModule();;
        }

		key = sdkKbGetKey();
		switch (key)
		{
			case SDK_KEY_1:
				strcpy(sztemp, "1");
				break;
			case SDK_KEY_2:
				strcpy(sztemp, "2");
				break;
			case SDK_KEY_3:
				strcpy(sztemp, "3");
				break;
			case SDK_KEY_CANCEL:
				strcpy(sztemp, "CANCEL");
				break;
			case SDK_KEY_4:
				strcpy(sztemp, "4");
				break;
			case SDK_KEY_5:
				strcpy(sztemp, "5");
				break;
			case SDK_KEY_6:
				strcpy(sztemp, "6");
				break;
			case SDK_KEY_BACKSPACE://clear key
				strcpy(sztemp, "CLEAR");
				break;
			case SDK_KEY_7:
				strcpy(sztemp, "7");
				break;
			case SDK_KEY_8:
				strcpy(sztemp, "8");
				break;
			case SDK_KEY_9:
				strcpy(sztemp, "9");
				break;
			case SDK_KEY_ENTER:
				strcpy(sztemp, "ENTER");
				break;
			case SDK_KEY_UP:
				strcpy(sztemp, "UP");
				break;
			case SDK_KEY_0:
				strcpy(sztemp, "0");
				break;
			case SDK_KEY_DOWN:
				strcpy(sztemp, "DOWN");
				break;
			case SDK_KEY_MENU:
				strcpy(sztemp, "MENU");
				break;
			case SDK_KEY_FN:
				return;
			case SDK_KEY_ALPHA:
				strcpy(sztemp, "ALPHA");
				break;
			default:break;
		}

		if(key != 0)
		{
			memset(szshowkey, 0, sizeof(szshowkey));
			sprintf((s8 *)szshowkey, "KEY [%s]", sztemp);
			sdkLcdClear();
			sdkLcdFillRow(SDK_LCD_LINE1,0, (u8 *)"KEY VALUE TEST", M_UCTR);
			sdkLcdFillRow(SDK_LCD_LINE5,0,  szshowkey, M_UCTR);
			sdkLcdFillRow(SDK_LCD_LINE7,0,  (u8 *)"[FUNC] EXIT", M_UCTR);
			sdkLcdBrushScreen();
		}
	}
	return;
}
/****************************************************************************
*FuntionName:DemoKeyInputIpAddr
*Descriptions:must input ip address
*Input:void
*Output:void
*Return:void
*Date:20140423
*Author:song
*Remark:none
****************************************************************************/
void DemoKeyInputIpAddr(void)
{
    u8 szbuf[100] = {0};
	s32 siRet = 0;
	sdkLcdClear();
	sdkLcdBrushScreen();
    siRet = sdkKbInput(SDK_LCD_LINE3, 0, szbuf, 6, 26, SDK_INPUT_IP, AUTORET_TIME);
	return (SDK_OK == siRet) ? DemoEnterKeyModule() : DemoKeyInputIpAddr();
}

/* =================================================================== */
/* my function  */
/* =================================================================== */

void WaitKeyPress(void) {

}



