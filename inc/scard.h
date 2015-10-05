#ifndef _SCARD_H_
#define _SCARD_H_


BOOL initialize();    
BOOL selectFile(u8 HiAddr, u8 LoAddr);    
BOOL readRecord(u8 RecNo, u8 dataLen);    
BOOL writeRecord(s32 caseType, u8 RecNo, u8 maxLen, u8 DataLen, u8 * ApduIn);
BOOL PerformTransmitAPDU(u8 *, unsigned long);

extern void ReadCard(void);
extern void WriteCard(void);
extern void StatusCard(void);
extern void PowerOnCard(void);
extern void PowerResetCard(void);
extern void SendAPDUCard(void);

s8 pbRecvBuffer[1500];
u8 RxedData[250];

#endif
