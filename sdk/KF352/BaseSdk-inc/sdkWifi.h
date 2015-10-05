/********************************************************************
文件名 : sdkWifi.h
描  述 : WIFI模块接口函数
版  权 : 长城开发
作  者 : 卢永宁
修改记录: 
    日期              修改人  修改内容
    2014-01-03 17:41  卢永宁  创建
********************************************************************/
#ifndef BASE_SDKWIFI_H_
#define BASE_SDKWIFI_H_

#ifdef __cplusplus
  extern "C" {
#endif

#define SDK_WIFI_SECURITY_NONE       0   //  No security;
#define SDK_WIFI_SECURITY_WEP64      1   //  WEP-64;
#define SDK_WIFI_SECURITY_WEP128     2   //  WEP-128;
#define SDK_WIFI_SECURITY_WPATKIP    3   //  WPA-TKIP;
#define SDK_WIFI_SECURITY_WPA2AES    4   //  WPA2-AES;
#define SDK_WIFI_SECURITY_WPATKIP_E  5 //  WPA-TKIP Enterprise PEAP-MSCHAPv2;
#define SDK_WIFI_SECURITY_WPA2AES_E  6 //  WPA2-AES Enterprise PEAP-MSCHAPv2;

//To power save, set.IchipPowerSave=5, .WLANPowerSave=5 are optimized.
typedef struct
{
    s32 IchipPowerSave;     //  Wi-Fi module (iChip) power save (0..255, 0:Disable Power Save mode, 1..255:seconds without any activity)
    s32 Channel;            //  Wireless LAN communication channel(0 - 13)
    s32 WLANPowerSave;      //  Wireless LAN Power Save. (0(default): WiFi chipset Power Save mode is disabled. 1-5:The number of beacon periods during chipset remains in Power Save mode.)
    s32 RoamingMode;        //  0(default):disable roaming mode, 1:enable roaming mode
    s32 PeriodicScanInt;    //  Periodic WiFi Scan Interval(1~3600, default=5)
    s32 RoamingLowSNR;      //  Sets a low SNR threshold for iChip in Roaming mode.(0 - 255dB, default:10dB)
    s32 RoamingHighSNR;     //  Sets a high SNR threshold for iChip in Roaming mode.(0 - 255dB, default:30dB)
}T_SDK_WIFI_CONFIG;         //  The parameters for Wi-Fi

typedef struct
{
    s8  SSID[64];           //  SSID
    s32 SecurityType;       //  Sets the Wireless LAN security type.(0:No security; 1:WEP-64; 2:WEP-128; 3:WPA-TKIP; 4:WPA2-AES)
    s8  WPAPSK[64];         //  Personal Shared Key Pass-Phrase.
    s8  WEPKey[32];         //  WEP Key
}T_SDK_WIFI_APx;            //  can be configured up to 10 sets(0~9), the default set is No.0.


#define SDK_WIFI_STATUS_NOTPRESENT    0  //  Wlan adapter not present
#define SDK_WIFI_STATUS_DISABLED      1  //  Wlan adapter disabled
#define SDK_WIFI_STATUS_SEARCHING     2  //  Searching for initial connection
#define SDK_WIFI_STATUS_CONNECTED     4  //  Connected
#define SDK_WIFI_STATUS_OUTOFRANGE    5   //  Out of range

typedef struct
{
    s32 Status;            /*  port status: 0:Wlan adapter not present;
                            1:Wlan adapter disabled;
                            2:Searching for initial connection;
                            4:Connected;
                            5:Out of range      */
    s32 XferRate;           //  Transfer rate in the range 1..54
    s32 SigLevel;           //  signal level [%], in the range 0..100
    s32 LnkQual;            //  Link quality [%], in the range 0..100
    s8  SSID[64];           //  SSID
    s32 SecurityType;       //  The Wireless LAN security type.(0:No security; 1:WEP-64; 2:WEP-128; 3:WPA-TKIP; 4:WPA2-AES)
    s32 Channel;            //  Current communication channel
}T_SDK_WIFI_STATUS;         // The status of Wi-Fi connection

typedef struct
{
    s8  SSID[64];           //  SSID
    s32 SecurityType;       //  The Wireless LAN security type.(0:No security; 1:WEP-64; 2:WEP-128; 3:WPA-TKIP; 4:WPA2-AES)
    s32 SigStrength;        //  Signal strength, 0-low, 1-good, 2-excellent
}T_SDK_WIFI_APINFO;         //  available ap info in surrounding area


s32 sdkWifiConfigParam(T_SDK_WIFI_CONFIG *tConfigParam);

s32 sdkWifiScanNetAp(u32 nListnum, T_SDK_WIFI_APINFO tAPlist[], u32 *pnAPNum);

s32 sdkWifiSetNetAp(T_SDK_WIFI_APx *ptAP);

s32 sdkWifiStartNet(void);

s32 sdkWifiGetStatus(T_SDK_WIFI_STATUS *tWifiStatus);

s32 sdkWifiGetIP(u8 *pcIP);

s32 sdkWifiGetMAC(s8 *pcMac);


#ifdef __cplusplus
  }
#endif

#endif

