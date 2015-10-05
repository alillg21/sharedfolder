/********************************************************************
文件名 : sdkWnet.h
描  述 : 有关GPRS/CMDA模块函数
版  权 : 长城开发
作  者 : 张友刚
修改记录: 
    日期              修改人  修改内容
    2013-12-31 10:30  张友刚  创建
********************************************************************/
#ifndef BASE_SDKWNET_H_
#define BASE_SDKWNET_H_

#ifdef __cplusplus
    extern "C" {
#endif

//网络类型
#define SDK_WNET_TYPE_GPRS   0x00   //NetType: GPRS
#define SDK_WNET_TYPE_CDMA   0x01   //NetType: CDMA
#define SDK_WNET_TYPE_WCDMA  0x02   //NetType: WCDMA

//Sim卡槽
#define SDK_SIM_SLOT1   0   //SIM1 (SimCard Slot 1)
#define SDK_SIM_SLOT2   1   //SIM2 (SimCard Slot 2)

s32 sdkWnetSetType(u8 ucType);
s32 sdkWnetSetSolt(u8 ucSlotNum);
s32 sdkWnetInit(void);
s32 sdkWnetClose(void);
s32 sdkWnetCheckSim(void);
s32 sdkWnetGetSignal(u32 *puiSignal);
s32 sdkWnetSetDnsServer(u8 * pszMDNS, u8 * pszSDNS);
s32 sdkWnetResolveDns(const u8 *pszName, u8 *pszIPAddr, u32 uiIPMaxLen);
s32 sdkWnetGetIMSI(u8 *pszIMSI);
s32 sdkWnetGetIMEI(u8 *pszIMEI);
s32 sdkWnetUssdCmd(s32 n, const void *pSendStr, s32 dcs, s32 *m, void *pRecvStr, s32 *pRecvDcs);
//
s32 sdkWnetSetAccount(u8 *pszAPN, u8 *pszDialNum, u8 *pszUserName, u8 *pszUserPwd, u32 uiTimeOutMs);
s32 sdkWnetStartNet(void);
s32 sdkWnetStopNet(void);
s32 sdkWnetTcpConnect(u8 *pszRemoteIP, u32 uiRemotePort);
s32 sdkWnetTcpSend(u8 *pucData, u32 uiDataLen);
s32 sdkWnetTcpRecv(u8 *pucData, u32 uiDataLen);
s32 sdkWnetTcpDisconnect(void);

#ifdef __cplusplus
    }
#endif

#endif

