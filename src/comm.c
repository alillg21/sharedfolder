/**
 * @file     comm.c
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
 * these communication parameters just for DEMO test,
 * only for reference,pls don't copy it!
 * pls write your code based the following sample code show below
 */
const static s8 DemoTestServerIpaddr[16] = "219.134.129.217";
const static s8 DemoTestModemOutline[8] = "9,,";
const static s8 DemoTestModemPhone1[28] = "913424318290";
const static s8 DemoTestModemPhone2[28] = "913424318290";
const static s8 DemoTestModemPhone3[28] = "913424318290";
const static s8 DemoTestLanLocalIp[16]  = "10.2.97.133";
const static s8 DemoTestLanGate[16] = "10.2.97.1";
const static s8 DemoTestLanMask[16] = "255.255.255.0";
const static s8 DemoTestLanDNSIP[16] = "10.2.232.191";
const static s8 DemoTestWifiSID[32] = "TP-LINK_CIBU_SBU1";
const static s8 DemoTestWifiPwd[16] = "kaifa0755123";
u32 DemoTestPort = 8004;

/****************************************************************************
*FuntionName:DemoEnterCommModule
*Descriptions:enter to communication module,and select comm type
*Input:void
*Output:void
*Return:void
*Date:20140423
*Author:song
*Remark:none
****************************************************************************/
void DemoEnterCommModule(void)
{
    s32 siRet = 0;
    T_SDK_COMM_COMMPARAM stCommPara;
    memset(&stCommPara,0,sizeof(T_SDK_COMM_COMMPARAM));
    //set communication model,Modem,GPRS/CDMA,LAN.and so on...
    DemoSetCommModel(&stCommPara);
    siRet = DemoCommFunSimulateTest(&stCommPara);//comm processing,init->link->send->receive->close
	if (SDK_OK != siRet)
	{
		DemoDisplayInfo(SDK_LCD_LINE3,(u8 *)"COMM TEST FAILED",M_UCTR);
	}
    else
    {
        DemoDisplayInfo(SDK_LCD_LINE3,(u8 *)"COMM TEST SUCCEED",M_UCTR);
    }
	return DemoWaitKeyToBack(DemoEnterCommModule);
}
/****************************************************************************
*FuntionName:DemoSetCommModel
*Descriptions:select comm type
*Input:void
*Output:void
*Return:void
*Date:20140423
*Author:song
*Remark:none
****************************************************************************/
void DemoSetCommModel(T_SDK_COMM_COMMPARAM *pstcommpara)
{
    s32 commtype = 0;
    if (NULL == pstcommpara)
    {
        return;
    }
    commtype = DemoCommModeSelect();
    return DemoCommSettingDetails(commtype,pstcommpara);		//comm model setting details
}
/****************************************************************************
*FuntionName:DemoCommModeSelect
*Descriptions:
*Input:void
*Output:void
*Return:void
*Date:20140423
*Author:song
*Remark:none
****************************************************************************/
s32 DemoCommModeSelect(void)
{
	s32 siRet = 0;
	s32 key = 0;
	sdkLcdClear();
	sdkLcdFillRow(SDK_LCD_LINE1,0, (u8 *)"COMM MODULE",M_UCTR);
	sdkLcdFillRow(SDK_LCD_LINE2,0, (u8 *)"1.MODERN", 	 L_UCTR);
	sdkLcdFillRow(SDK_LCD_LINE3,0, (u8 *)"2.CDMA 3.GPRS", L_UCTR);
	sdkLcdFillRow(SDK_LCD_LINE4,0, (u8 *)"4.LAN  5.WIFI", L_UCTR);
	sdkLcdBrushScreen();
	sdkKbFlush();
	key = sdkKbWaitKey(SDK_KEY_MASK_CANCEL | SDK_KEY_MASK_1 | SDK_KEY_MASK_2 | SDK_KEY_MASK_3 | SDK_KEY_MASK_4,0);
	switch (key)
	{
		case SDK_KEY_1:     siRet = SDK_COMM_MODEM;	    break;
		case SDK_KEY_2:	    siRet = SDK_COMM_CDMA;      break;
		case SDK_KEY_3:	    siRet = SDK_COMM_GPRS;      break;
		case SDK_KEY_4:	    siRet = SDK_COMM_ETHERNET;	break;
        case SDK_KEY_5:	    siRet = SDK_COMM_WIFI;	    break;
		case SDK_KEY_CANCEL:    DemoShowMainMenu();     break;
		default: break;
	}
	return siRet;
}
/****************************************************************************
*FuntionName:DemoCommSettingDetails
*Descriptions:config comm data
*Input:s32 commtype,T_SDK_COMM_COMMPARAM *pstcommpara
*Output:void
*Return:void
*Date:20140423
*Author:song
*Remark:none
****************************************************************************/
void DemoCommSettingDetails(s32 commtype,T_SDK_COMM_COMMPARAM *pstcommpara)
{
    if (commtype < 1 || commtype > 5 || (NULL == pstcommpara))
    {
        return;
    }
    pstcommpara->eMode = commtype;
    pstcommpara->ucReDialTimes = 3;//redial time
    pstcommpara->ucDialTime = 60;
    switch(commtype)
    {
        case SDK_COMM_ETHERNET:
        {
            pstcommpara->tLanInfo.bIsDhcp = FALSE;//whether to use dhcp model,true-use,false-don't use
            pstcommpara->bSocketConnectMode = 0;//socket connect type ,0-short,1-long
            strcpy((s8*)pstcommpara->tLanInfo.szNetClientIP,DemoTestLanLocalIp);//local ip
            strcpy((s8*)pstcommpara->tLanInfo.szNetGate,DemoTestLanGate);//local gateway
            strcpy((s8*)pstcommpara->tLanInfo.szNetMask,DemoTestLanMask);//local netmask
            strcpy((s8*)pstcommpara->tLanInfo.szDnsIP,DemoTestLanDNSIP);//local DNS ip
            //strcpy((s8*)pstcommpara->tLanInfo.szDemoTestLanDNSIP);//local DNS ip
            strcpy((s8*)pstcommpara->tServerInfo.szServerIP,DemoTestServerIpaddr);//server ip
            pstcommpara->tServerInfo.uiPort = DemoTestPort;//server port number
        }
            break;
        case SDK_COMM_CDMA:
        case SDK_COMM_GPRS:
        {
            pstcommpara->tWireLessInfo.bIsUsePPP = 0;//Whether to use PPP connection,1-use,0-dont use
            pstcommpara->tWireLessInfo.bIsNeedUser = 0;//whether to need user,1-need,0-not need
            strcpy((s8*)pstcommpara->tWireLessInfo.szUsername,"");//user name
            strcpy((s8*)pstcommpara->tWireLessInfo.szPassword,"");//user password
            strcpy((s8*)pstcommpara->tWireLessInfo.szGprsApn,"cmnet");//APN
            strcpy((s8*)pstcommpara->tWireLessInfo.szDialNum,"");//for CDMA dial
            strcpy((s8*)pstcommpara->tServerInfo.szServerIP,DemoTestServerIpaddr);//server ip
            pstcommpara->tServerInfo.uiPort = DemoTestPort;//server port number
        }
            break;
        case SDK_COMM_MODEM:
        {
		    pstcommpara->tModemInfo.bLinkMode = 1;//linkmode,0-Synchronous,1-Asynchronous
            pstcommpara->tModemInfo.bIsNeedExParam = 0;//whether to use expand paramters
            strcpy((s8*)pstcommpara->tModemInfo.asOutLineNo,DemoTestModemOutline) ;//outline number should be less 7 bits
            strcpy((s8*)pstcommpara->tModemInfo.asPhone[0],DemoTestModemPhone1) ;//telephone number1
            strcpy((s8*)pstcommpara->tModemInfo.asPhone[1],DemoTestModemPhone2) ;//telephone number2
            strcpy((s8*)pstcommpara->tModemInfo.asPhone[2],DemoTestModemPhone3) ;//telephone number3
        }
            break;
        case SDK_COMM_WIFI:
        {
            pstcommpara->tLanInfo.bIsDhcp = FALSE;//whether to use dhcp model,true-use,false-don't use
            pstcommpara->bSocketConnectMode=0;//socket connect type ,0-short,1-long
            strcpy((s8*)pstcommpara->tWifiInfo.szSSID, DemoTestWifiSID);
            strcpy((s8*)pstcommpara->tWifiInfo.szPassword, DemoTestWifiPwd);
            strcpy((s8*)pstcommpara->tServerInfo.szServerIP,DemoTestServerIpaddr);//server ip
            pstcommpara->tServerInfo.uiPort = DemoTestPort;//server port number
        }
            break;
        default:    break;
    }
    return;
}
/****************************************************************************
*FuntionName:DemoCommFunSimulateTest
*Descriptions:Simulate comm send or receive...
*Input:const T_SDK_COMM_COMMPARAM *pstcommpara
*Output:SDK_OK / SDK_ERROR
*Return:void
*Date:20140423
*Author:song
*Remark:none
****************************************************************************/
s32 DemoCommFunSimulateTest(const T_SDK_COMM_COMMPARAM *pstcommpara)
{
    //these codes show below just for reference,generally speaking,
    //when receive data from server should read time by second
    //for example:60,59,58,57,56...time out
	u8 szSendBuf[512] = {"send test data 111111111 from pos"};
	u8 szRecvBuf[512] = {0};
    u8 sztemp[8] = {0};
	s32 len = 0,siRet = 0,timerid = 0;
    s32 timerover = 1000;
    s32 i = 0,secnt = 0;
	if (NULL == pstcommpara)
	{
		return SDK_PARAMERR;
	}
    DemoDisplayInfo(SDK_LCD_LINE3,(u8 *)"CONFIGURING...",M_UCTR);
    /*communication initialization,configure comm paramters*/
    siRet = sdkCommInit(pstcommpara);
    if (siRet != SDK_OK)
    {
        sdkTrace("demo","sdkCommInit = %d\n",siRet);
        return SDK_ERROR;
    }
    DemoDisplayInfo(SDK_LCD_LINE3,(u8 *)"LINKING...",M_UCTR);
    /*communication connection processing*/
    siRet = sdkCommLink();
    if (siRet != SDK_OK)
    {
        sdkTrace("demo","sdkCommLink = %d\n",siRet);
        sdkCommDelLink();
        return SDK_ERROR;
    }
    len = strlen((s8 *)szSendBuf);
    DemoDisplayInfo(SDK_LCD_LINE3,(u8 *)"SENDING...",M_UCTR);
    /*communication send data processing*/
    siRet = sdkCommSendData(szSendBuf,len);
    if (siRet < 0)
    {
        sdkTrace("demo","sdkCommSendData = %d\n",siRet);
        sdkCommDelLink();
        return SDK_ERROR;
    }
    sdkLcdClear();
    sdkLcdFillRow(SDK_LCD_LINE3, 0, (u8 *)"RECEIVING...", M_UCTR);
    //DemoDisplayInfo(SDK_LCD_LINE3,(u8 *)"RECEIVING...",M_UCTR);
    timerid = sdkSysGetTimerCount();
    /*communication receive data processing*/
    while (1)
    {
        siRet = sdkCommRecvData(szRecvBuf,len);
        if (siRet == strlen((s8 *)szSendBuf))//test server, return the same data as send data
        {
            sdkTrace("demo","sdkCommRecvData = %d\n",siRet);
            DemoDisplayInfo(SDK_LCD_LINE3,(u8 *)"RECEIVING DATA OK!",M_UCTR);
            sdkSysSleep(2000);
            break;
        }
        if (sdkSysGetTimerEnd(timerid,timerover))
        {
            i = 60;//you can set other value
            if (i > secnt)
            {
                i = i - secnt;
            }
            else
            {
                DemoDisplayInfo(SDK_LCD_LINE3,(u8 *)"RECEIVING TIMEOUT!",M_UCTR);
                sdkSysSleep(2000);
                sdkCommDelLink();
                return SDK_ERROR;
            }
            secnt++;
            memset(sztemp,0,sizeof(sztemp));
            sprintf((s8 *)sztemp,"%d",i);
            sdkLcdClearRow(SDK_LCD_LINE4);
            sdkLcdFillRow(SDK_LCD_LINE4, 0, sztemp, M_UCTR);
            sdkLcdBrushScreen();
            timerid = sdkSysGetTimerCount();
        }
    }
    /*communication close processing*/
    sdkCommDelLink();
    DemoDisplayInfo(SDK_LCD_LINE3,(u8 *)"DONE...",M_UCTR);
    sdkSysSleep(2000);
	return SDK_OK;
}





