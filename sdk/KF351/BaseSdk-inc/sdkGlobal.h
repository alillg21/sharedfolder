/********************************************************************
文件名 :
描  述 :
版  权 : 长城开发
作  者 : 张文晖
修改记录:
    日期              修改人  修改内容
    2013-12-24 10:04  张文晖  创建
********************************************************************/
#ifndef BASE_SDKGLOBAL_H_
#define BASE_SDKGLOBAL_H_

//C库
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#if(POS_TYPE != KF352)
#include <unistd.h>
#include <fcntl.h>
#endif

//BaseSDK inc
#include "sdkTypeDef.h"
#include "sdkSystem.h"
#include "sdkMngMessage.h"
#include "sdkMngLink.h"
#include "sdkMngMem.h"
#include "sdkDebug.h"
//
#include "sdkMath.h"
#include "sdkTools.h"
#include "sdkFiles.h"
#include "sdkMnt.h"
//
#include "sdkKBkey.h"
#include "sdkLCD.h"
#include "sdkMagCard.h"
#include "sdkPrint.h"
#include "sdkGps.h"
//
#include "sdkUART.h"
#include "sdkModem.h"
#include "sdkEthernet.h"
#include "sdkPPP.h"
#include "sdkWnet.h"
#include "sdkWifi.h"
//
#include "sdkPed.h"
#include "sdkIcCard.h"
#include "sdkRfCard.h"
//
#include "sdkScanGun.h"
#include "sdkCamera.h"
#include "sdkFingerprint.h"
#include "sdkBluetooth.h"
#include "sdkVoice.h"
#include "sdkLED.h"

#endif

