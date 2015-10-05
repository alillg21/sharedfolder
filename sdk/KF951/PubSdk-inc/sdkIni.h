/********************************************************************
文件名 : sdkIni.h
描  述 : 参数下载
版  权 : 长城开发
作  者 : 卢裕燕
修改记录: 
    日期              修改人  修改内容
    2014-02-18 10:40  卢裕燕  创建
********************************************************************/

#ifndef BASE_SDKINI_H_
#define BASE_SDKINI_H_

#ifdef __cplusplus
    extern "C" {
#endif


s32 sdkIniReadKey(const u8 *pszFilePath, const u8 *pszSel, const u8 *pszKey ,
                                u8 *pParam, u32 uiParamLen);


//测试代码
#if 0

s32 TESTPUBINI(void);

#endif


#ifdef __cplusplus
    }
#endif

#endif
        





