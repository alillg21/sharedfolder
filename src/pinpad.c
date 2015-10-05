/**
 * @file     pinpad.c
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



/*
des type selection,3des/des
*/
static DEMO_PED_DES_TYPE E_PED_DES_TYPE = E_PED_DES_SINGLE;
/*
external pinpad or internal pinpad
default:external pinpad
*/
#define DEMO_EXTERNAL_PED 0x00 //external
#define DEMO_INTERNAL_PED 0x01 //internal

#define TRIPLE_DESKEY_LEN 32
#define SINGLE_DESKEY_LEN 16
#define PINPAD_SN_LEN  11

static u8 g_DemoSingleKeyBuf[8 + 1] = {0};
static u8 g_DemoTripleKeyBuf[16 + 1] = {0};
/****************************************************************************
*Descriptions:just like main face,Standby interface.show welcome infomation
*Input:void
*Output:void
*Return:void
*Date:20140423
*Author:song
*Remark:none
****************************************************************************/
void DemoEnterPinpadModule(void)
{
    s32 key = 0;
    s32 timerid = 0;
	s32 timerover = AUTORET_TIME;
    //get current timerid
    timerid = sdkSysGetTimerCount();
    while (1)
    {
        sdkLcdClear();
        sdkLcdFillRow(SDK_LCD_LINE1, 0, (u8 *)"PINPAD MODULE", M_UCTR);
        sdkLcdFillRow(SDK_LCD_LINE2, 0, (u8 *)"1.SET DESTYPE",  L_UCTR);
        sdkLcdFillRow(SDK_LCD_LINE3, 0, (u8 *)"2.TMK LOAD",  L_UCTR);
        sdkLcdFillRow(SDK_LCD_LINE4, 0, (u8 *)"3.TPK LOAD",  L_UCTR);
        sdkLcdFillRow(SDK_LCD_LINE5, 0, (u8 *)"4.DISP AMT",  L_UCTR);
        sdkLcdFillRow(SDK_LCD_LINE6, 0, (u8 *)"5.INPUT PIN",  L_UCTR);
        sdkLcdFillRow(SDK_LCD_LINE7, 0, (u8 *)"6.GET PEDSN",  L_UCTR);
        sdkLcdFillRow(SDK_LCD_LINE8, 0, (u8 *)"7.CALC MAC",  L_UCTR);
        sdkLcdFillRow(SDK_LCD_LINE9, 0, (u8 *)"8.DUKPT",  L_UCTR);
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
			case SDK_KEY_1:	    DemosdkSetDesType();        break;
			case SDK_KEY_2:     DemoUpdateTmk();            break;
			case SDK_KEY_3:     DemoUpdateWk();     break;
			case SDK_KEY_4:     DemoDisplayAmount();      break;
			case SDK_KEY_5:	    DemoInputPin();     break;
			case SDK_KEY_6:	    DemoGetPedSn();     break;
			case SDK_KEY_7:	    DemoCalcMac();      break;
			default: break;
        }
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
void DemosdkSetDesType(void)
{
	s32 key = 0;
	u8 buf[16] = {0};

	sdkLcdClear();
	sdkLcdFillRow (SDK_LCD_LINE1,0,(u8 *)"CHOOSE DES TYPE", M_UCTR);
	sdkLcdFillRow (SDK_LCD_LINE3,0,(u8 *)"PLS SELECT:", 		L_UCTR);
	sdkLcdFillRow (SDK_LCD_LINE5,0,(u8 *)"1-3DES   0-DES",   M_UCTR);
	memcpy(buf,"CUR:",4);
	if (E_PED_DES_TYPE == E_PED_DES_SINGLE)
	{
		strcat((s8 *)buf,"0");
	}
	else
	{
		strcat((s8 *)buf,"1");
	}
	sdkLcdFillRow(SDK_LCD_LINE4, 0, buf, R_UCTR);
    sdkLcdBrushScreen();
	while (1)
	{
		key = sdkKbWaitKey(SDK_KEY_MASK_0 | SDK_KEY_MASK_1 | SDK_KEY_MASK_CANCEL | SDK_KEY_MASK_ENTER, AUTORET_TIME);
	    if(key == SDK_KEY_ENTER || key == SDK_KEY_MASK_CANCEL)
	    {
	    	DemoEnterPinpadModule();
	        return ;
	    }
	    else if(key == '1')
	    {
	    	sdkLcdFillRow(SDK_LCD_LINE5, 0, (u8 *)"1", L_UCTR);
	        E_PED_DES_TYPE = E_PED_DES_TRIPLE;
	    }
	    else if(key == '0')
	    {
	        sdkLcdFillRow(SDK_LCD_LINE5, 0, (u8 *)"0", L_UCTR);
	        E_PED_DES_TYPE = E_PED_DES_SINGLE;
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
void DemoUpdateTmk(void)
{
	return (E_PED_DES_TYPE == E_PED_DES_TRIPLE)?(DemoUpdateTmkByTripleDes()):(DemoUpdateTmkBySingleDes());
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
void DemoUpdateWk(void)
{
	return (E_PED_DES_TYPE == E_PED_DES_TRIPLE)?(DemoUpdateWkByTripleDes()):(DemoUpdateWkBySingleDes());
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
void DemoUpdateTmkByTripleDes(void)
{
	u8 szbuf[128] = {0};
	u8 temp[64] = {0};
	s32 siRet = 0;

    sdkPedSetType(DEMO_EXTERNAL_PED); //still don't need call it ,because choose default ..external
	DemoDisplayInfo(SDK_LCD_LINE2,(u8 *)"INPUT TMK(32B):",L_UCTR);
    siRet = sdkKbInput(SDK_LCD_LINE3, 0, szbuf, 32,32, SDK_INPUT_NUM, AUTORET_TIME);
	if (SDK_OK == siRet)
	{
		sdkAscToBcd(&szbuf[1],TRIPLE_DESKEY_LEN,temp);
        memcpy(g_DemoTripleKeyBuf,temp,16);
		siRet = sdkPedUpMastKey(0, temp, 16, 0x00);
		if (SDK_OK == siRet)
		{
			DemoDisplayInfo(SDK_LCD_LINE3,(u8 *)"TMK DOWN OK!",M_UCTR);
		}
		else
		{
			DemoDisplayInfo(SDK_LCD_LINE3,(u8 *)"TMK DOWN FAILED!",M_UCTR);
		}
	}
	return DemoWaitKeyToBack(DemoEnterPinpadModule);
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
void DemoUpdateTmkBySingleDes(void)
{
	u16 key = 0;
	u8 szbuf[128] = {0};
	u8 temp[64] = {0};
	s32 siRet = 0;

	DemoDisplayInfo(SDK_LCD_LINE2,(u8 *)"INPUT TMK(16B):",L_UCTR);
	siRet = sdkKbInput(SDK_LCD_LINE3, 0, szbuf, 16,16, SDK_INPUT_NUM, AUTORET_TIME);
	if (SDK_KEY_ENTER == key)
	{
		sdkAscToBcd(&szbuf[1],SINGLE_DESKEY_LEN,temp);
		memcpy(g_DemoSingleKeyBuf,temp,8);
		siRet = sdkPedUpMastKey(0, temp, 8, 0x00);
		if (SDK_OK == siRet)
		{
			DemoDisplayInfo(SDK_LCD_LINE3,(u8 *)"TMK DOWN OK!",M_UCTR);
		}
		else
		{
			DemoDisplayInfo(SDK_LCD_LINE3,(u8 *)"TMK DOWN FAILED!",M_UCTR);
		}
	}
	return DemoWaitKeyToBack(DemoEnterPinpadModule);
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
void DemoUpdateWkByTripleDes(void)
{
    DemoDisplayInfo(SDK_LCD_LINE3, (u8 *)"WAIT TO UPDATE...", M_UCTR);
	return DemoWaitKeyToBack(DemoEnterPinpadModule);
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
void DemoUpdateWkBySingleDes(void)
{
    DemoDisplayInfo(SDK_LCD_LINE3, (u8 *)"WAIT TO UPDATE...", M_UCTR);
	return DemoWaitKeyToBack(DemoEnterPinpadModule);
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
void DemoDisplayAmount(void)
{
	s32 siRet = 0;
	siRet = sdkPedDispBalance((u8 *)"\x00\x00\x00\x11\x11\x11",6);
	if (SDK_OK == siRet)
	{
		DemoDisplayInfo(SDK_LCD_LINE3,(u8 *)"OPERATING OK!",M_UCTR);

	}
	else
	{
		DemoDisplayInfo(SDK_LCD_LINE3,(u8 *)"OPERATING FAILED!",M_UCTR);

	}
	return DemoWaitKeyToBack(DemoEnterPinpadModule);
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
void DemoInputPin(void)				//just for test,,,,,(TMK:1111111111111111,Wk,0x95 0x09 0x73 0x18 0x23 0x17 0xF8 0x0B)
{
    DemoDisplayInfo(SDK_LCD_LINE3, (u8 *)"WAIT TO UPDATE...", M_UCTR);
	return DemoWaitKeyToBack(DemoEnterPinpadModule);
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
void DemoCalcMac(void)
{
    DemoDisplayInfo(SDK_LCD_LINE3, (u8 *)"WAIT TO UPDATE...", M_UCTR);
	return DemoWaitKeyToBack(DemoEnterPinpadModule);
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
void DemoGetPedSn(void)
{
    u8 szbuf[32] = {0};
    s32 siRet = 0;

    siRet = sdkPedReadSerialNo(szbuf);
    if(SDK_OK == siRet)
    {
        sdkLcdClear();
        sdkLcdFillRow(SDK_LCD_LINE3, 0, (u8 *)"PINPED SN:", L_UCTR);
        sdkLcdFillRow(SDK_LCD_LINE4, 0, szbuf, M_UCTR);
        sdkLcdBrushScreen();
    }
    else
    {
        DemoDisplayInfo(SDK_LCD_LINE3, (u8 *)"GET PED SN ERROR!", M_UCTR);
    }
    return DemoWaitKeyToBack(DemoEnterPinpadModule);
}


