/********************************************************************
文件名 : sdkEthernet.h
描  述 : 以太网(通讯)接口函数
版  权 : 长城开发
作  者 : 张志鹏
修改记录:
    日期              修改人  修改内容
    2014-01-08 14:37  张志鹏  创建
********************************************************************/
#ifndef BASE_SDKETHERNET_H
#define BASE_SDKETHERNET_H

#ifdef __cplusplus
    extern "C" {
#endif

//Network Param Config
typedef struct
{
    u8 szServerIP[64];              //服务器地址，支持IP和URL格式的数据
    u8 szPort[6];                   //服务端口号
    u8 szNetClientIP[16];           //本地 IP 地址
    u8 szNetGate[16];               //本地网关
    u8 szNetMask[16];               //本地子网掩码
    u8 szDnsIP1[16];                //DNS 域名解析服务器IP
    u8 szDnsIP2[16];                //DNS 域名解析服务器IP
    BOOL bIsDhcp;                   //是否使用 DHCP
    BOOL bIsPPPoe;                  //是否是 PPPoe 方式  0-否，1-是
    u8 szPPPoeUser[51];             //PPPoe 用户名称最长 50 个字节  ASCII
    u8 szPPPoeUserPwd[51];          //PPPoe 用户密码最长 50 个字节  ASCII
} T_SDK_NETPARAM;


s32 sdkNetReadParam(T_SDK_NETPARAM *ptNetParam);
s32 sdkNetSetParam(const T_SDK_NETPARAM *ptNetParam);
s32 sdkNetCreatLink(u32 uiTimeout);
s32 sdkNetClearLink(void);
s32 sdkNetSendData(u8 * pucData,u32 uiDataLen);
s32 sdkNetRecvData(u8 * pucData,u32 uiDataLen);
s32 sdkNetGetStatus(void);


#ifdef __cplusplus
    }
#endif

#endif

