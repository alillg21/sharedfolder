/********************************************************************
文件名 : sdkMngMessage.h
描  述 : 消息机制模块
版  权 : 长城开发
作  者 : 张文晖
修改记录:
    日期              修改人  修改内容
    2014-02-12 19:30  张文晖  创建
********************************************************************/
#ifndef BASE_SDKMESSAGE_H_
#define BASE_SDKMESSAGE_H_

#ifdef __cplusplus
    extern "C" {
#endif

#define     SDK_MSG_OUT         0                   //本消息处理完毕后从对列清除
#define     SDK_MSG_KEEP        1                   //本消息处理完毕后移动到对列尾部
#define     SDK_MSG_DISCARD     2                   //本消息处理完毕后直接丢弃,退出消息循环

#define     SDK_MSG_NORMAL      0                   //普通优先级(缺省)
#define     SDK_MSG_HIGH        1                   //高优先级

#define     SDK_MSG_INIT        0                   //MSG初始化状态
#define     SDK_MSG_SERVICE     1                   //MSG正常服务状态
#define     SDK_MSG_TERMINAL    2                   //MSG终止状态

typedef struct _MSG                                             //消息节点
{
    u8  Priority;                                               //消息优先级
    u8  Status;                                                 //消息状态
    s32 (*pFun)(struct _MSG *ptMsg);                             //消息入口函数
    u32 WParam;                                                 //消息高参数
    u32 LParam;                                                 //消息低参数
}T_SDK_MSG;

typedef struct _SDKMSGNODE
{
    struct _MSG     *pMsg;                      //内存节点
    struct _SDKMSGNODE *pNext;                  //下一内存块节点指针
}T_SDK_MSG_NODE;

s32 sdkMsgPost(T_SDK_MSG *ptMsg);
s32 sdkMsgSend(T_SDK_MSG *ptMsg);
BOOL sdkMsgQuery(T_SDK_MSG **ptMsg);
s32 sdkMsgTerminate(void *pFun);
void sdkMsgListDisp(void);
void sdkMsgListDestroy(void);
void sdkMsgPack(u8 ucPrio,u8 ucStatus,s32 (*pFun)(struct _MSG *ptMsg),u32 uiWParam,u32 uiLParam);

#ifdef __cplusplus
    }
#endif

#endif

