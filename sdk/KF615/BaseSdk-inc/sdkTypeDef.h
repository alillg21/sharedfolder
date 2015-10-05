/********************************************************************
文件名 :
描  述 :
版  权 : 长城开发
作  者 : 张文晖
修改记录:
    日期              修改人  修改内容
    2013-12-24 10:04  张文晖  创建
********************************************************************/
#ifndef BASE_SDKSYSTYPEDEF_H_
#define BASE_SDKSYSTYPEDEF_H_

#ifdef __cplusplus
    extern "C" {
#endif

#ifndef u8
typedef unsigned char u8;
#endif
#ifndef s8
typedef char s8;
#endif
#ifndef u16
typedef unsigned short u16;
#endif
#ifndef s16
typedef short s16;
#endif
#ifndef u32
typedef unsigned int u32;
#endif
#ifndef s32
typedef int s32;
#endif

#ifndef BOOL
typedef unsigned char BOOL;
#endif


#undef      TRUE
#undef      FALSE
#define     TRUE     1
#define     FALSE    0

//为了避免与C++关键字冲突，屏蔽bool类型和trun&false的定义和声明
//#undef      true
//#undef      false
//#define     true     1
//#define     false    0

#define   SDK_OK     0
#define   SDK_ESC    -1
#define   SDK_ERROR  -2
#define   SDK_PARAMERR -3
#define   SDK_TIMEOUT  -4
#define   SDK_USER_DEFINE -10   /*各模块返回值如不满足的话，可以在此基础上累加定义
eg:#define SDK_PRN_PAPEROUT (SDK_USER_DEFINE-1)*/


#ifdef __cplusplus
    }
#endif


#endif

