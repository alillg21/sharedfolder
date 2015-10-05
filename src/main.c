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


/**
 * this is debug tag table
 * configure your tag in this array
 */
static char const * gpTagList[]=
{
    "demo",
};
/**
 * this is debug filter structure
 * configure struct parameters
 */
static T_SDK_DEBUG_FILTER DebugFilter =
{
    FALSE,                                        //not test status
    TRUE,                                         //print tag,file,line info
    SDK_DEBUG_TARGET_COM,                         //uart print
};

#define TRs(s) (s8 *)s
#define TR(s) (u8 *)s

s32 SwitchApp()
{
    s32 iKey;

    sdkLcdClear();
    sdkLcdFillRow(SDK_LCD_LINE2, 0, (u8*)"Exit App?", SDK_LCD_MIDDLE);
    sdkLcdFillRow(SDK_LCD_LINE3, 0, (u8*)"Enter or Cancel", SDK_LCD_MIDDLE);
    sdkLcdBrushScreen();

    while(1)
    {
        iKey = sdkKbGetKey();
        if(iKey == SDK_KEY_ENTER)
        {
            exit(0);
        }
        else if(iKey == SDK_KEY_CANCEL)
        {
            break;
        }
    }

    return SDK_OK;
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

void DemoShowMainMenu(void)
{
	s32 key = 0;
	s32 timerid = 0;

	//get current timerid
	timerid = sdkSysGetTimerCount();
	while (1)
	{
		sdkLcdClear();
		sdkLcdFillRow(SDK_LCD_LINE1, 0, (u8 *)"DEMO APP", M_UCTR);
		sdkLcdFillRow(SDK_LCD_LINE3, 0, (u8 *)"[1]. REGISTRASI",  L_UCTR);
		sdkLcdFillRow(SDK_LCD_LINE4, 0, (u8 *)"[2]. SALDO KARTU",  L_UCTR);	
		sdkLcdFillRow(SDK_LCD_LINE5, 0, (u8 *)"[3]. TRANSAKSI",  L_UCTR);	
		
		sdkLcdFillRow(SDK_LCD_LINE8, 0, (u8 *)"PILIH NO",M_UCTR);
		sdkLcdBrushScreen();
		
		//timeout?
		if (sdkSysGetTimerEnd(timerid,AUTORET_TIME))
		{
			DemoShowWelCome();
			return;
		}
		
		key = sdkKbGetKey();
		switch(key)
		{
			case SDK_KEY_CANCEL:	
				DemoShowWelCome(); 
				break;
				
			case SDK_KEY_1:			
				DemoRegistrasi();  
				break;
				
			case SDK_KEY_2:			
				DemoSaldoCard();   
				break;

			case SDK_KEY_3:			
				DemoTransaksi();
				break;
				
			case SDK_KEY_MENU:		
				SwitchApp();	   
				break;

			default: 
				break;
		}
	}
}

	void DemoShowWelCome(void)
	{
	s32 key = 0;
	u8 sztemp[8] ,szbuf[32];
	s32 timerid = 0;

	//get current timerid
	timerid = sdkSysGetTimerCount();

	/* if your pos time is not correct,please set time call this function show below*/
	//memcpy(sztemp, "\x14\x05\x27\x15\x30\x00",6);
	//sdkSysSetTime(sztemp);

	while (1)
	{
	if (sdkSysGetTimerEnd(timerid,AUTORET_TIME))
	{
	//if not any operation on POS in welcome interface, POS will enter IDLE module
	//sdkSysBuzz(u8 ucType)
	//0x01 - press ENTER key to exit IDLE module
	//0x40 - if timeout,exit IDLE module
	//0x10 - if some external devices(USB...) insert, will exit IDLE module
	//0x06 - if serial port has data buffer ,will exit IDLE module
	sdkSysPowerIdle(0x01, 0);
	timerid = sdkSysGetTimerCount();
	}
	memset(sztemp,0,sizeof(sztemp));
	memset(szbuf,0,sizeof(szbuf));
	sdkSysGetTime(sztemp);//if time you got isn't correct,please call sdkSysSetTime first
	//printf("ʱ�䣺%02x %02x %02x \n", sztemp[0], sztemp[1], sztemp[2]);
	sprintf((s8 *)szbuf,"20%02X-%02X-%02X %02X:%02X:%02X", sztemp[0], sztemp[1], sztemp[2], sztemp[3], sztemp[4], sztemp[5]);
	sdkLcdClear();
	sdkLcdFillRow(SDK_LCD_LINE2, 0, (u8 *)"WELCOME", M_UCTR);
	sdkLcdFillRow(SDK_LCD_LINE3, 0, (u8 *)"DEMO APP",  M_UCTR);
	sdkLcdSetFont(FONT_COURIER_NEW, FONT_CHARSET_ASCII, 24);
	sdkLcdFillRow(SDK_LCD_LINE5, 0, szbuf, M_UCTR);
	sdkLcdBrushScreen();
	sdkLcdSetFont(FONT_COURIER_NEW, FONT_CHARSET_ASCII, 32);
	key = sdkKbGetKey();
	if (key > 0)
	{
	if(key == SDK_KEY_MENU)
	{
	SwitchApp();
	}
	else
	{
	DemoShowMainMenu();
	}
	}
	}
}

/****************************************************************************
*FuntionName:main
*Descriptions:
*Input:
*Output
*Return:
*Date:
*Author:
*Remark:
****************************************************************************/
int main(int argc,char *argv[])
{
	s32 iRet = -1;
    //u8 ucStatus = 0;

    sdkDebugInit(&DebugFilter, gpTagList,sizeof(gpTagList)/sizeof(char*));
    //iRet = sdkSysInit(&ucStatus);     //system initialization

    sdkSysSetLanguage(SDK_LANG_ENGLISH);
    iRet = sdkSysStart(0);
	iRet = sdkFPInitialize();
	iRet = sdkFPOpen();
    DemoShowMainMenu();
	iRet = sdkFPClose();
    return SDK_OK;
}

