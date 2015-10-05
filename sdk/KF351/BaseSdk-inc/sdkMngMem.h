/********************************************************************
文件名 : sdkMngMem.h
描  述 : 内存管理头文件
版  权 : 长城开发
作  者 : 张友刚
修改记录:
    日期              修改人  修改内容
    2013-12-24 15:04  张文晖 创建
********************************************************************/
#ifndef BASE_SDKSYSMNG_H
#define BASE_SDKSYSMNG_H

#ifdef __cplusplus
    extern "C" {
#endif

//私有 应用不允许调用
void* PrivateGetMalloc(u32 uisize, const s8 *pcFile, s32 siLine);
s32 PrivateFreeMem(void* pMemblock, const s8 *pcFile, s32 siLine);

//公有 应用调用
#define sdkMemGet(uiMenSize) PrivateGetMalloc(uiMenSize,(const char *)__FILE__, __LINE__)
#define sdkMemFree(pMem) PrivateFreeMem((void *)pMem,(const char *)__FILE__, __LINE__)

#ifdef __cplusplus
    }
#endif

#endif

