/********************************************************************
文件名 : sdkScanGun.h
描  述 : 扫描枪模块头文件
版  权 : 长城开发
作  者 : Ming
修改记录: 
    日期              修改人  修改内容
    2014-03-11 10:32  Ming      创建
********************************************************************/
#ifndef BASE_SCANGUN_H
#define BASE_SCANGUN_H
    
#ifdef __cplusplus
        extern "C" {
#endif


s32 sdkBarcodeScanOpen(void);
s32 sdkBarcodeScanClose(void);
s32 sdkBarcodeScanRead(u8 *pucScanBuf);


#ifdef __cplusplus
    }
#endif

#endif

