/**
 * @file     lcd.c
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
void DemoEnterLcdModule(void)
{
	s32 key = 0;
	s32 timerid = 0;
	s32 timerover = AUTORET_TIME;

	sdkLcdClear();
	sdkLcdFillRow(SDK_LCD_LINE1,0, (u8 *)"LCD MODULE", M_UCTR);
	sdkLcdFillRow(SDK_LCD_LINE2,0, (u8 *)"1.FRAME 2.PIXEL", L_UCTR);
    sdkLcdFillRow(SDK_LCD_LINE3,0, (u8 *)"3.PHOTO", L_UCTR);
    sdkLcdFillRow(SDK_LCD_LINE4,0, (u8 *)"4.PROGRESS BAR", L_UCTR);
    sdkLcdFillRow(SDK_LCD_LINE5,0, (u8 *)"5.ICON", L_UCTR);
	sdkLcdBrushScreen();
	sdkKbFlush();
	timerid = sdkSysGetTimerCount();
	while (1)
	{
		if (sdkSysGetTimerEnd(timerid,timerover))
        {
            //DemoShowWelCome();
            return;
        }
		key = sdkKbGetKey();
		switch (key)
		{
			case SDK_KEY_1:			DemoDrawFrame();		 break;	//draw frame
			case SDK_KEY_2:			DemoPixelsInfoDisplay(); 	 break;	//terminal screen pixels
			case SDK_KEY_3:			DemoPhotoDisplay(); 		 break;	//specified photo display
			case SDK_KEY_4:			DemoProgrssBarDisplay(); 	 break;	//progressbar display
			case SDK_KEY_5:			DemoIconDisplay(); 	 break;	//devices icon display
			case SDK_KEY_CANCEL:	DemoShowMainMenu();			 break;	//back to mainmenu
			default:break;
		}
	}
	return ;
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
void DemoDrawFrame(void)
{
	sdkLcdClear();
    sdkLcdDrawFrame(50,200,100,100,COLOR_WHITE);// x y width high color
    sdkLcdDrawFrame(200,200,50,50,COLOR_RED);
    sdkLcdDrawFrame(50,400,100,100,COLOR_WHITE);
    sdkLcdDrawFrame(200,400,50,50,COLOR_RED);
	sdkLcdBrushScreen();
	return DemoWaitKeyToBack(DemoEnterLcdModule);
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
void DemoPhotoDisplay(void)
{
	u8 fn[128] = {0};
	strcpy((s8 *)fn, "demo.bmp");
	sdkLcdClear();
	if(SDK_OK == sdkFileAccess(fn))
	{
		sdkLcdDispBmpFile(10,10,(u8 *)fn);
	}
	else
	{
		sdkLcdFillRow(SDK_LCD_LINE3,0, (u8 *)"NO THIS FILE", M_UCTR);
	}
	sdkLcdBrushScreen();
	return DemoWaitKeyToBack(DemoEnterLcdModule);
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
void DemoProgrssBarDisplay(void)
{
	u32 uiStartX = 5,uiStartY = 200,uiWidth = 300,uiHeight = 20,uiCurrentX = 0;
	sdkLcdClear();
    for(uiCurrentX = 0; uiCurrentX < 300; uiCurrentX++)
    {
        sdkLcdProcessBar(uiStartX,uiStartY,uiWidth,uiHeight,uiCurrentX);
        sdkLcdBrushScreen();
    }
	return DemoWaitKeyToBack(DemoEnterLcdModule);
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
void DemoPixelsInfoDisplay(void)
{
	s32 icol = 0;

	sdkLcdClear();//clear lcd
    for(icol = 0; icol < 300; icol += 10)
    {
        sdkLcdPixel(50,icol,COLOR_WHITE);//(x,y) = (50,icol)
        sdkLcdPixel(100,icol,COLOR_RED);//(x,y) = (100,icol)
        sdkLcdPixel(150,icol,COLOR_BLACK);//(x,y) = (150,icol)
        sdkLcdPixel(200,icol,COLOR_GREEN);//(x,y) = (200,icol)
        sdkLcdBrushScreen();
    }
	return DemoWaitKeyToBack(DemoEnterLcdModule);
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
void DemoIconDisplay(void)
{
    //these codes show below just for reference to operate devices ICON
    //you still can close it by change the second paramter to SDK_CLOSE_ICON
    //download your Icon to /data/res directory
    #if 0 //sy 20140606 11:11
    s32 siRet = 0;
    s32 sivalue = 0;
    siRet = sdkSysGetPowerStatus(&sivalue);
    switch(siRet)
    {
        case E_EXTERNAL_SUPPLY:
            break;
        case E_POWER_FULL:
            sdkLcdSetIcon(SDK_ICON_BATTERY,SDK_ICON_EXTPWR);
            break;
        case E_POWER_ONGOING:
            break;
    }
    #endif

    sdkLcdSetIcon(SDK_ICON_PHONE, SDK_OPEN_ICON);
    sdkLcdSetIcon(SDK_ICON_SIGNAL, SDK_OPEN_ICON);
    sdkLcdSetIcon(SDK_ICON_PRINTER, SDK_OPEN_ICON);
    sdkLcdSetIcon(SDK_ICON_ICCARD, SDK_OPEN_ICON);
    sdkLcdSetIcon(SDK_ICON_BATTERY, SDK_OPEN_ICON);
    sdkLcdSetIcon(SDK_ICON_EXTPWR, SDK_OPEN_ICON);
    sdkLcdSetIcon(SDK_ICON_UP, SDK_OPEN_ICON);
    sdkLcdSetIcon(SDK_ICON_DOWN, SDK_OPEN_ICON);
    sdkLcdSetIcon(SDK_ICON_LOCK, SDK_OPEN_ICON);
    sdkLcdSetIcon(SDK_ICON_WIFI, SDK_OPEN_ICON);
}


