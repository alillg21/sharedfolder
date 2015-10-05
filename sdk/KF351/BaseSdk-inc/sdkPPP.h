/********************************************************************
文件名 :
描  述 :
版  权 : 深圳长城开发
作  者 : 吴伟伟
修改记录:
    日期              修改人  修改内容
    2014-01-02 15:50  吴伟伟  创建
********************************************************************/
#ifndef BASE_SDKPPP_H_
#define BASE_SDKPPP_H_

#ifdef __cplusplus
    extern "C" {
#endif

//PPP使用的设备类型
#define SDK_DEV_WNET     1  //Wireless
#define SDK_DEV_ETH      2  //Ethernet
#define SDK_DEV_WIFI     3  //Wifi
#define SDK_DEV_MODEM    4  //Modem

typedef struct
{
    u8 ucDevType;   //模块类型:
                    //0x01   PPP使用的设备为无线模块
                    //0x02   PPP使用的设备为以太网模块
                    //0x03   PPP使用的设备为WIFI模块
                    //0x04   PPP使用的设备为MODEM模块
    u8 szAPN[16];      //Apn接入点
    u8 szDialNum[16];  //拨号号码
    u8 szName[16];     //名称
    u8 szPasswd[16];   //密码
    u8 ucAuth;         //认证方式 PPP_ALG_PAP/ PPP_ALG_CHAP	MSCHAPV1  / PPP_ALG_MSCHAPV2
    u8 ucTimeOut;      //超时时间 秒
} T_SDK_PPP_PARAM;

//认证算法: 至少要采用一种，基于安全的考虑，建议使用CHAP算法。
#define PPP_ALG_PAP	      0x01  //认证时采用PAP算法
#define PPP_ALG_CHAP	  0x02  //认证时采用CHAP算法
#define PPP_ALG_MSCHAPV1  0x04  //认证时采用MSCHAPV1算法
#define PPP_ALG_MSCHAPV2  0x08  //认证时采用MSCHAPV2算法

s32 sdkPppSetParam(T_SDK_PPP_PARAM *tPppParam);
s32 sdkPppStartLink(void);
s32 sdkPppStopLink(void);
s32 sdkPppGetLinkStatus(void);

#ifdef __cplusplus
    }
#endif

#endif

