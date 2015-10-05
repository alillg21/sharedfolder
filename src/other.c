/**
 * @file     other.c
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
void DemoEnterOtherModule(void)
{
	u16 key = 0;
	s32 timerid = 0;
	s32 TimerOver = AUTORET_TIME;
	sdkLcdClear();
	sdkLcdFillRow (SDK_LCD_LINE1,0,(u8 *)"OTHER MODULE", M_UCTR);
	sdkLcdFillRow (SDK_LCD_LINE2,0,(u8 *)"1.UART",   L_UCTR);
	sdkLcdFillRow (SDK_LCD_LINE3,0,(u8 *)"2.GET POSSN",	 L_UCTR);
	sdkLcdFillRow (SDK_LCD_LINE4,0,(u8 *)"3.GET VERSION",L_UCTR);
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
		switch (key)
		{
			case SDK_KEY_1:			DemoEnterUartModule();  break;		//UART
			case SDK_KEY_2:			DemoGetPosSerialNumber();   break;	//get pos sn
			case SDK_KEY_3:			DemoGetLibVersion();	break;		//lib version
			case SDK_KEY_CANCEL:	DemoShowMainMenu();	    break;		//back to mainmenu
			default:break;
		}
	}
	return ;

}
/****************************************************************************
*Descriptions:just like main face,Standby interface.show welcome infomation
*Input:void
*Output:void
*Return:void
*Date:20140423
*Author:song
*Remark:none
****************************************************************************/
void DemoDisplayInfo(const s32 line,const u8 *pinfo,const u8 ucAtr)
{
	if ((NULL == pinfo) || (line <0 || line >10))
	{
		return;
	}
	sdkLcdClear();
    sdkLcdFillRow(line, 0, pinfo, ucAtr);
    sdkLcdBrushScreen();
}
/****************************************************************************
*Descriptions:just like main face,Standby interface.show welcome infomation
*Input:void
*Output:void
*Return:void
*Date:20140423
*Author:song
*Remark:none
****************************************************************************/
void DemoWaitKeyToBack(pfun psfun)
{
	u16 key = 0;
	if (NULL == psfun)
	{
		return;
	}
	key = sdkKbWaitKey(SDK_KEY_MASK_CANCEL | SDK_KEY_MASK_ENTER,AUTORET_TIME);
	if (key == SDK_KEY_CANCEL || key == SDK_KEY_ENTER)
	{
		psfun();
	}
}
/****************************************************************************
*FuntionName:DemoEnterUartModule
*Descriptions:only for reference
*Input:void
*Output:void
*Return:void
*Date:20140423
*Author:song
*Remark:none
****************************************************************************/
void DemoEnterUartModule(void)
{
    s32 siRet = 0;
    u8 szbuf[128] = {0},sztemp[8] = {0};
    u8 ucportno = 3;
    s32 timerover = 1000;
    s32 timerid = 0;
    s32 i = 0,secnt = 0;
    //open uart , and configure bourdrate ,stop bit,check bit...
    siRet = sdkUartOpen(ucportno, (u8 *)"115200,8,n,1,h");
    if(SDK_OK != siRet)
    {
        DemoDisplayInfo(SDK_LCD_LINE3, (u8 *)"OPEN UART FAILED", M_UCTR);
        return;
    }
    //clear uart buffer data
    siRet = sdkUartClearBuf(ucportno);
    if(SDK_OK != siRet)
    {
        DemoDisplayInfo(SDK_LCD_LINE3, (u8 *)"CLEAR UART FAILED", M_UCTR);
        return;
    }
    //try to send data to host
    siRet = sdkUartSendData(ucportno, (u8 *)"123456", strlen("123456"));
    if(0 > siRet)
    {
        DemoDisplayInfo(SDK_LCD_LINE3, (u8 *)"UART SEND FAILED", M_UCTR);
        return;
    }
    if(strlen("123456") == siRet)
    {
        sdkLcdClear();
        sdkLcdFillRow(SDK_LCD_LINE3, 0, (u8 *)"SEND DATA:", L_UCTR);
        sdkLcdFillRow(SDK_LCD_LINE4, 0, (u8 *)"123456", M_UCTR);
        sdkLcdFillRow(SDK_LCD_LINE5, 0, (u8 *)"READY TO RECEIVE:", L_UCTR);
    }
    timerid = sdkSysGetTimerCount();

    //try to receive data from host
    while (1)
    {
        //you still can create a queue to insert received data ,
        //when your data receive finished, you can break;
        siRet = sdkUartRecvData(ucportno, szbuf, strlen("123456"));
        if (strlen("123456") == siRet)
        {
            sdkLcdClear();
            sdkLcdFillRow(SDK_LCD_LINE3, 0, (u8 *)"RECEIVE DATA:", L_UCTR);
            sdkLcdFillRow(SDK_LCD_LINE4, 0, szbuf, M_UCTR);
            sdkLcdFillRow(SDK_LCD_LINE5, 0, (u8 *)"READY TO CLOSE:", L_UCTR);
            sdkLcdBrushScreen();
            sdkSysSleep(2000);
            break;
        }
        if (sdkSysGetTimerEnd(timerid,timerover))
        {
            i = 60;
            if (i > secnt)
            {
                i = i - secnt;
            }
            else
            {
                DemoDisplayInfo(SDK_LCD_LINE3,(u8 *)"RECEIVE TIMEOUT!",M_UCTR);
                sdkSysSleep(2000);
                break;
            }
            secnt++;
            memset(sztemp,0,sizeof(sztemp));
            sprintf((s8 *)sztemp,"%d",i);
            sdkLcdClearRow(SDK_LCD_LINE5);
            sdkLcdFillRow(SDK_LCD_LINE5, 0, sztemp, M_UCTR);
            sdkLcdBrushScreen();
            timerid = sdkSysGetTimerCount();
        }
    }
    //close uart
    siRet = sdkUartClose(ucportno);
    if (SDK_OK == siRet)
    {
        DemoDisplayInfo(SDK_LCD_LINE3, (u8 *)"UART CLOSE OK", M_UCTR);
    }
    return DemoWaitKeyToBack(DemoEnterOtherModule);
}
/****************************************************************************
*Descriptions:just like main face,Standby interface.show welcome infomation
*Input:void
*Output:void
*Return:void
*Date:20140423
*Author:song
*Remark:none
****************************************************************************/
void DemoGetPosSerialNumber(void)
{
    s32 siRet = 0;
    u8 szbuf[24] = {0};
    siRet = sdkSysGetSn(szbuf);
    if(SDK_OK == siRet)
    {
        //if you get correct return value ,but no serial number,maybe this
        //pos machine you have hasn't wrote by factory
        //so ,don't worry about it
        sdkLcdClear();
        sdkLcdFillRow(SDK_LCD_LINE2, 0,(u8 *)"POS SN:", L_UCTR);
        sdkLcdFillRow(SDK_LCD_LINE3, 0,szbuf, M_UCTR);
        sdkLcdBrushScreen();
    }
    else
    {
        DemoDisplayInfo(SDK_LCD_LINE3, (u8 *)"GET POS SN FAILED!", M_UCTR);
    }
    return DemoWaitKeyToBack(DemoEnterOtherModule);
}
/****************************************************************************
*Descriptions:just like main face,Standby interface.show welcome infomation
*Input:void
*Output:void
*Return:void
*Date:20140423
*Author:song
*Remark:none
****************************************************************************/
void DemoGetLibVersion(void)
{
    s32 siRet = 0;
    u8 szbuf[24] = {0};

    siRet = sdkSysReadSDKVer(szbuf);
    if(SDK_OK == siRet)
    {
        sdkLcdClear();
        sdkLcdFillRow(SDK_LCD_LINE2, 0,(u8 *)"SDK VER:", L_UCTR);
        sdkLcdFillRow(SDK_LCD_LINE3, 0,szbuf, M_UCTR);
        sdkLcdBrushScreen();
    }
    else
    {
        DemoDisplayInfo(SDK_LCD_LINE3, (u8 *)"READ VERSION FAILED!", M_UCTR);
    }
    return DemoWaitKeyToBack(DemoEnterOtherModule);
}

