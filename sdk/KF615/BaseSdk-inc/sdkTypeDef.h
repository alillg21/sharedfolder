/********************************************************************
�ļ��� :
��  �� :
��  Ȩ : ���ǿ���
��  �� : ������
�޸ļ�¼:
    ����              �޸���  �޸�����
    2013-12-24 10:04  ������  ����
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

//Ϊ�˱�����C++�ؼ��ֳ�ͻ������bool���ͺ�trun&false�Ķ��������
//#undef      true
//#undef      false
//#define     true     1
//#define     false    0

#define   SDK_OK     0
#define   SDK_ESC    -1
#define   SDK_ERROR  -2
#define   SDK_PARAMERR -3
#define   SDK_TIMEOUT  -4
#define   SDK_USER_DEFINE -10   /*��ģ�鷵��ֵ�粻����Ļ��������ڴ˻������ۼӶ���
eg:#define SDK_PRN_PAPEROUT (SDK_USER_DEFINE-1)*/


#ifdef __cplusplus
    }
#endif


#endif

