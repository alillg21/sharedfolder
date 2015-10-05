/********************************************************************
文件名 :
描  述 :
版  权 : 长城开发
作  者 : 张文晖
修改记录:
    日期              修改人  修改内容
    2014-2-18 10:04  张文晖  创建
********************************************************************/
#ifndef PUBLIC_SDKGLOBAL_H_
#define PUBLIC_SDKGLOBAL_H_

//C库
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#if(POS_TYPE != KF352)
#include <unistd.h>
#include <fcntl.h>
#endif


//SDK Public inc

#include "sdkComm.h"
#include "sdkCardOperate.h"

#include "sdkInput.h"
#include "sdkDisp.h"
#include "sdkPrintExt.h"
#include "sdkUI.h"
#include "sdkSys.h"
#include "sdkIni.h"




#endif

