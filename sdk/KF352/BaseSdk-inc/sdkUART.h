/********************************************************************
文件名 : sdkUART.h
描  述 :
版  权 : 长城开发
作  者 : 张志鹏
修改记录:
    日期              修改人  修改内容
    2014-01-06 11:01  张志鹏  创建
********************************************************************/
#ifndef BASE_SDKUART_H
#define BASE_SDKUART_H

#ifdef __cplusplus
    extern "C" {
#endif

//串口号
#define SDK_COM0    0        //内部模块（modem模块、无线模块）串口
#define SDK_COM1    1        //调试、下载口
#define SDK_COM2    2        //外设设备（Pinpad）接口
#define SDK_COM3    3        //串口3
#define SDK_COM4    4        //串口4
#define SDK_COM5    5        //串口5

s32 sdkUartOpen(u8 ucPortNo, u8 *PortPara);
s32 sdkUartClose(u8 ucPortNo);
s32 sdkUartSendData(u8 ucPortNo, u8 *Data, u32 DataLen);
s32 sdkUartRecvData(u8 ucPortNo, u8 *Data, u32 pDataLen);
s32 sdkUartClearBuf(u8 ucPortNo);

#ifdef __cplusplus
  }
#endif

#endif

