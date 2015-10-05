/********************************************************************
文件名 : sdkKBkey.h
描  述 : 按键相关的函数
版  权 : 长城开发
作  者 : DJ Chen
修改记录:
    日期              修改人  修改内容
    2013-12-24 16:42  DJ Chen  创建
********************************************************************/
#ifndef BASE_SDKKBKEY_H_
#define BASE_SDKKBKEY_H_

#ifdef __cplusplus
    extern "C" {
#endif

#define     SDK_KEY_0           '0'                             //  '0'
#define     SDK_KEY_1           '1'                             //  '1'
#define     SDK_KEY_2           '2'                             //  '2'
#define     SDK_KEY_3           '3'                             //  '3'
#define     SDK_KEY_4           '4'                             //  '4'
#define     SDK_KEY_5           '5'                             //  '5'
#define     SDK_KEY_6           '6'                             //  '6'
#define     SDK_KEY_7           '7'                             //  '7'
#define     SDK_KEY_8           '8'                             //  '8'
#define     SDK_KEY_9           '9'                             //  '9'

#define     SDK_KEY_BACKSPACE   0x08                            //  退格
#define     SDK_KEY_CLEAR       0x2E                            //  全部清除
#define     SDK_KEY_ALPHA       0x07                            //  字母
#define     SDK_KEY_UP          0x26                            //  向上
#define     SDK_KEY_DOWN        0x28                            //  向下
#define     SDK_KEY_LEFT        0x12        //  向左
#define     SDK_KEY_RIGHT       0x13        //  向右

#define     SDK_KEY_FN          0x15                            //  功能
#define     SDK_KEY_MENU        0x14                            //  菜单
#define     SDK_KEY_ENTER       0x0D                            //  确认
#define     SDK_KEY_CANCEL      0x1B                            //  取消
#define     SDK_KEY_PRNUP       0x19                            //  打印向上走纸
#define     SDK_KEY_INVALID     0xFF                            //  无效按键
#define     SDK_KEY_TIMEOUT     0X00                            //  超时无按键

s32 sdkKbOpen(void);
s32 sdkKbClose(void);

s32 sdkKbGetKey(void);
s32 sdkKbFlush(void);
s32 sdkKbBeep(u8 ucMode);
s32 sdkKbLight(u8 ucMode);

#ifdef  DJ_debug
void TestKB(void);
#endif

#ifdef __cplusplus
    }
#endif

#endif

