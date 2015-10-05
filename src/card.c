/**
 * @file     card.c
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
void DemoEnterCardModule(void)
{
	u16 key = 0;
	s32 timerid = 0;
	s32 TimerOver = AUTORET_TIME;
	sdkLcdClear();
	sdkLcdFillRow (SDK_LCD_LINE1,0,(u8 *)"CARD MODULE", M_UCTR);
	sdkLcdFillRow (SDK_LCD_LINE2,0,(u8 *)"1.MAGCARD  2.RF",   L_UCTR);
	sdkLcdFillRow (SDK_LCD_LINE3,0,(u8 *)"3.PSAM  4.CARDSLOT",	L_UCTR);
	sdkLcdFillRow (SDK_LCD_LINE4,0,(u8 *)"5.4442  6.4428",	 	L_UCTR);
	sdkLcdFillRow (SDK_LCD_LINE5,0,(u8 *)"7.NFC",	L_UCTR);
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
			case SDK_KEY_1:			DemoMagcardModule();	break;		//Test Magnetic Card
			case SDK_KEY_2:			DemoEnterRfModule();	break;		//Test Mifare Card
			case SDK_KEY_3:			/*DemoPsamModule();	*/	break;		//Test Psam Card
			case SDK_KEY_4:			/*DemoCardslotModule();	*/break;		//Test IC Card Slot
			case SDK_KEY_5:			/*Demo4442CardModule();	*/break;		//Test 4442 Card
			case SDK_KEY_6:			/*Demo4428CardModule();	*/break;		//Test 4428 Card
			case SDK_KEY_7:			/*DEMONFCUpCard();	*/	break;		//Test up Card
			case SDK_KEY_8:			/*DemoSendAPDUToRF();	*/	break;		//Test up Card
			case SDK_KEY_CANCEL:	DemoShowMainMenu();		break;		//back to mainmenu
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
void DemoEnterRfModule(void)
{
	u16 key = 0;
	s32 timerid = 0;
	s32 TimerOver = AUTORET_TIME;
	sdkLcdClear();
	sdkLcdFillRow (SDK_LCD_LINE1,0,(u8 *)"RF MODULE", M_UCTR);
	sdkLcdFillRow (SDK_LCD_LINE2,0,(u8 *)"1.A/B/F",   L_UCTR);
	sdkLcdFillRow (SDK_LCD_LINE3,0,(u8 *)"2.M1",	L_UCTR);
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
			case SDK_KEY_1:			DemoABFCardModule();	break;		//Test Magnetic Card
			case SDK_KEY_2:			DemoMifareCardModule();	break;		//Test Mifare Card
			case SDK_KEY_CANCEL:	DemoEnterCardModule();	break;		//back to mainmenu
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
void DemoMagcardModule(void)
{
    s32 siRet = 0;
    u8 szTrack1[79+1] = {0};
    u8 szTrack2[40+1] = {0};
    u8 szTrack3[107+1] = {0};
    T_SDK_TRACK_DATA_INFO stTrackInfo;
    s32 timerid = 0;
    s32 TimerOver = AUTORET_TIME;

    memset(&stTrackInfo,0,sizeof(T_SDK_TRACK_DATA_INFO));
    siRet = sdkMagOpen();
    if (siRet != SDK_OK)
    {
        printf("sdkMagOpen siRet = %d!!!!!!!!!!!!!\n",siRet);
    }
    sdkMagClearData();
    timerid = sdkSysGetTimerCount();
    DemoDisplayInfo(SDK_LCD_LINE3, (u8 *)"PLS SWIPE CARD:", L_UCTR);
    while (1)
    {
        siRet = sdkMagIfBrush();
        if (SDK_OK == siRet)
        {
            siRet = sdkMagReadData(szTrack1 ,szTrack2, szTrack3);
            if (strlen((s8 *)szTrack2) > 0)
            {
                break;
            }
        }
        if (sdkSysGetTimerEnd(timerid, TimerOver))
		{
			DemoShowMainMenu();
			return;
		}
    }
    siRet = sdkMagParseData(szTrack1 ,szTrack2, szTrack3, &stTrackInfo);
    sdkMagClose();
    if (SDK_OK == siRet)
    {
        DemoDisplayCardNo(stTrackInfo.szCardNo);
    }
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
void DemoDisplayCardNo(const u8 *pstCardNO)
{
	if (NULL == pstCardNO)
	{
		return;
	}
	sdkLcdClear();
	sdkLcdFillRow (SDK_LCD_LINE2 , 0 , (u8 *)"CARD NO:" , 	   L_UCTR);
    sdkLcdSetFont(FONT_COURIER_NEW, FONT_CHARSET_ASCII, 24);
	sdkLcdFillRow (SDK_LCD_LINE4 , 0 , pstCardNO , 	   R_UCTR);
    sdkLcdSetFont(FONT_COURIER_NEW, FONT_CHARSET_ASCII, 32);
	sdkLcdFillRow (SDK_LCD_LINE5 , 0 , (u8 *)"PLS CONFIRM..." , M_UCTR);
	sdkLcdBrushScreen();
	return DemoWaitKeyToBack(DemoEnterCardModule);
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
void DemoMifareCardModule(void)
{
    s32 siRet = 0;
    u8 ucInCardType = 0x01|0x02|0x04;//01:A/B 02:M 04:C
    u8 szcardtype[4] = {0};
    u8 szserialnum[32] = {0};
    u8 szcid[12] = {0};
    u8 szother[32] = {0};
    u8 szbuf[32] = {0};
    u8 sztemp[64] = {0};
    s32 timerid = 0;
	s32 TimerOver = AUTORET_TIME;
    s32 key = 0;
    u32 len = 0;

    sdkRfSetType(1);//set internal RF device status
    siRet = sdkRfPowerOn();//power on
    if(SDK_OK != siRet)
    {
        DemoDisplayInfo(SDK_LCD_LINE3, (u8 *)"RF POWER ON ERROR", M_UCTR);
    }
    siRet = sdkRfReset();//reset
    if(SDK_OK != siRet)
    {
        DemoDisplayInfo(SDK_LCD_LINE3, (u8 *)"RF RESET ERROR", M_UCTR);
    }
    timerid = sdkSysGetTimerCount();
    while(1)
    {
        DemoDisplayInfo(SDK_LCD_LINE3, (u8 *)"PLS WAVE CARD:", L_UCTR);
        if(sdkRfSearchCard(ucInCardType, szcardtype, szserialnum, szcid, szother)== SDK_OK)
        {
            sdkLcdClear();
            sprintf((s8 *)szbuf,"CARD TYPE:%s",szcardtype);
            sdkLcdFillRow(SDK_LCD_LINE2, 0, szbuf, L_UCTR);
            memset(szbuf,0,sizeof(szbuf));
            sdkBcdToAsc(&szserialnum[1], szserialnum[0], szbuf);
            sdkLcdFillRow(SDK_LCD_LINE3, 0, (u8 *)"SERIAL NUMBER:", L_UCTR);
            sdkLcdFillRow(SDK_LCD_LINE4, 0, szbuf, R_UCTR);
            sdkLcdFillRow(SDK_LCD_LINE5, 0, (u8 *)"[ENTER]->NEXT", M_UCTR);
            sdkLcdBrushScreen();
            key = sdkKbWaitKey(SDK_KEY_MASK_ENTER | SDK_KEY_MASK_CANCEL, AUTORET_TIME);
            if(key != SDK_KEY_ENTER)
            {
                return DemoEnterCardModule();
            }
            else
            {
                break;
            }
        }
        if (sdkSysGetTimerEnd(timerid, TimerOver))
		{
			DemoShowMainMenu();
			return;
		}
    }
    siRet = sdkMifVerifyKey(1, 0x00, (u8 *)"\xFF\xFF\xFF\xFF\xFF\xFF", 6, &szserialnum[1]);
    if(SDK_OK == siRet)
    {
        sdkLcdClear();
        sdkLcdFillRow(SDK_LCD_LINE3, 0, (u8 *)"VERIFY KEY OK!", M_UCTR);
        sdkLcdFillRow(SDK_LCD_LINE5, 0, (u8 *)"[ENTER]->NEXT", M_UCTR);
        sdkLcdBrushScreen();
    }
    else
    {
        sdkLcdClear();
        sdkLcdFillRow(SDK_LCD_LINE3, 0, (u8 *)"VERIFY KEY ERROR!", M_UCTR);
        sdkLcdFillRow(SDK_LCD_LINE5, 0, (u8 *)"[ENTER]->NEXT", M_UCTR);
        sdkLcdBrushScreen();
    }
    key = sdkKbWaitKey(SDK_KEY_MASK_ENTER | SDK_KEY_MASK_CANCEL, AUTORET_TIME);
    if(key != SDK_KEY_ENTER)
    {
        return DemoEnterCardModule();
    }
    else
    {
        memset(szbuf,0,sizeof(szbuf));
        memset(sztemp,0,sizeof(sztemp));
        siRet = sdkMifReadBlock(25, szbuf, &len);
        sdkBcdToAsc(szbuf, len, sztemp);
        if(SDK_OK == siRet)
        {
            sdkLcdClear();
            sdkLcdFillRow(SDK_LCD_LINE3, 0, (u8 *)"READ BLOCK OK!", M_UCTR);
            sdkLcdFillRow(SDK_LCD_LINE4, 0, (u8 *)"BLOCK DATA:", L_UCTR);
            sdkLcdFillRow(SDK_LCD_LINE5, 0, sztemp, R_UCTR);
            sdkLcdBrushScreen();
        }
        else
        {
            sdkLcdClear();
            sdkLcdFillRow(SDK_LCD_LINE3, 0, (u8 *)"READ BLOCK ERROR!", M_UCTR);
            sdkLcdBrushScreen();
        }
    }
    return DemoWaitKeyToBack(DemoEnterCardModule);
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
void DemoABFCardModule(void)
{
    s32 siRet = 0;
    u8 ucInCardType = 0x01|0x02|0x04;//01:A/B 02:M 04:C
    u8 szcardtype[4] = {0};
    u8 szserialnum[32] = {0};
    u8 szcid[12] = {0};
    u8 szother[32] = {0};
    u8 szbuf[32] = {0};
    s32 timerid = 0;
	s32 TimerOver = AUTORET_TIME;
    s32 key = 0;
    u32 len = 0;

    sdkRfSetType(1);//set internal RF device status
    siRet = sdkRfPowerOn();//power on
    if(SDK_OK != siRet)
    {
        DemoDisplayInfo(SDK_LCD_LINE3, (u8 *)"RF POWER ON ERROR", M_UCTR);
    }
    siRet = sdkRfReset();//reset
    if(SDK_OK != siRet)
    {
        DemoDisplayInfo(SDK_LCD_LINE3, (u8 *)"RF RESET ERROR", M_UCTR);
    }
    timerid = sdkSysGetTimerCount();
    while(1)
    {
        DemoDisplayInfo(SDK_LCD_LINE3, (u8 *)"PLS WAVE CARD:", L_UCTR);
        if(sdkRfSearchCard(ucInCardType, szcardtype, szserialnum, szcid, szother)== SDK_OK)
        {
            sdkLcdClear();
            sprintf((s8 *)szbuf,"CARD TYPE:%s",szcardtype);
            sdkLcdFillRow(SDK_LCD_LINE2, 0, szbuf, L_UCTR);
            memset(szbuf,0,sizeof(szbuf));
            sdkBcdToAsc(&szserialnum[1], szserialnum[0], szbuf);
            sdkLcdFillRow(SDK_LCD_LINE3, 0, (u8 *)"SERIAL NUMBER:", L_UCTR);
            sdkLcdFillRow(SDK_LCD_LINE4, 0, szbuf, R_UCTR);
            sdkLcdFillRow(SDK_LCD_LINE5, 0, (u8 *)"[ENTER]->NEXT", M_UCTR);
            sdkLcdBrushScreen();
            key = sdkKbWaitKey(SDK_KEY_MASK_ENTER | SDK_KEY_MASK_CANCEL, AUTORET_TIME);
            if(key != SDK_KEY_ENTER)
            {
                return DemoEnterCardModule();
            }
            else
            {
                break;
            }
        }
        if (sdkSysGetTimerEnd(timerid, TimerOver))
		{
			DemoShowMainMenu();
			return;
		}
    }
    memset(szbuf,0,sizeof(szbuf));
    siRet = sdkRfSendData((u8 *)"\x06\x00\xFF\xFF\x01\x00", 6, szbuf, &len);
    if(SDK_OK == siRet)
    {
        sdkLcdClear();
        sdkLcdFillRow(SDK_LCD_LINE3, 0, (u8 *)"SEND DATA OK!", M_UCTR);
        sdkLcdFillRow(SDK_LCD_LINE4, 0, (u8 *)"PLS MOVE YOUR CARD!", M_UCTR);
        sdkLcdFillRow(SDK_LCD_LINE5, 0, (u8 *)"[ENTER]->NEXT", M_UCTR);
        sdkLcdBrushScreen();
    }
    else
    {
        sdkLcdClear();
        sdkLcdFillRow(SDK_LCD_LINE3, 0, (u8 *)"SEND DATA ERROR!", M_UCTR);
        sdkLcdFillRow(SDK_LCD_LINE4, 0, (u8 *)"PLS MOVE YOUR CARD!", M_UCTR);
        sdkLcdFillRow(SDK_LCD_LINE5, 0, (u8 *)"[ENTER]->NEXT", M_UCTR);
        sdkLcdBrushScreen();
    }
    key = sdkKbWaitKey(SDK_KEY_MASK_ENTER | SDK_KEY_MASK_CANCEL, AUTORET_TIME);
    if(key != SDK_KEY_ENTER)
    {
        return DemoEnterCardModule();
    }
    else
    {
        siRet = sdkRfPowerDown();
        if(SDK_OK == siRet)
        {
            sdkLcdClear();
            sdkLcdFillRow(SDK_LCD_LINE5, 0, (u8 *)"POWER DOWN OK!", M_UCTR);
            sdkLcdBrushScreen();
        }
        else
        {
            sdkLcdClear();
            sdkLcdFillRow(SDK_LCD_LINE5, 0, (u8 *)"POWER DOWN ERROR!", M_UCTR);
            sdkLcdBrushScreen();
        }
    }
    return DemoWaitKeyToBack(DemoEnterCardModule);
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
void DemoPSAMCardModule(void)
{
    DemoDisplayInfo(SDK_LCD_LINE3, (u8 *)"DEMO WAIT TO UPDATE...", M_UCTR);
	return DemoWaitKeyToBack(DemoEnterPinpadModule);
}


