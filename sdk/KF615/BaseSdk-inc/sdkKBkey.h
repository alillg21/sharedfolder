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
#define     SDK_KEY_CLEAR       0x2E                            //  清除
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

//等待按键类型
#define SDK_GETKEY_OK         0x01        //等待按键-确认键(SDK_KEY_ENTER)
#define SDK_GETKEY_CANCEL     0x02        //等待按键-取消键(SDK_KEY_CANCEL)
#define SDK_GETKEY_OKCANCEL   0x03        //等待按键-确认和取消键(SDK_KEY_ENTER|SDK_KEY_CANCEL)
#define SDK_GETKEY_BACK       0x04        //等待按键-退格键(SDK_KEY_BACKSPACE)
#define SDK_GETKEY_ALPHA      0x08        //等待按键-字母键(SDK_KEY_ALPHA)
#define SDK_GETKEY_FUNC       0x10        //等待按键-功能键(SDK_KEY_FN)
#define SDK_GETKEY_MENU       0x20        //等待按键-菜单键(SDK_KEY_MENU)
#define SDK_GETKEY_UP         0x40        //等待按键-向上键(SDK_KEY_UP)
#define SDK_GETKEY_DOWN       0x80        //等待按键-向下键(SDK_KEY_DOWN)
#define SDK_GETKEY_ANYKEY     0xFF        //等待按键-任意键

//输入模式
#define SDK_INPUT_MODE_REV      0x00000001      //显示模式:正（反）显示; 1表示反显,0表示正显
#define SDK_INPUT_MODE_DEC      0x00000002      //是否有小数点; 1表示有小数点,0表示无小数点
#define SDK_INPUT_MODE_LEFT     0x00000004      //对齐方式; 1表示左对齐,0表示右对齐
#define SDK_INPUT_MODE_PWD      0x00000008      //密码模式; 1表示密码方式,0表示非密码方式
#define SDK_INPUT_MODE_ALPHA    0x00000010      //允许输字符;   1表示能输字符,0表示不能输字符
#define SDK_INPUT_MODE_NUM      0x00000020      //允许输数字;   1表示能输数字,0表示不能输数字
#define SDK_INPUT_MODE_BOLD     0x00000040      //大小字体; 1表示大字体,0表示小字体
#define SDK_INPUT_MODE_PRE      0x00000080      //预设内容有效; 1表示显示预设内容,0表示不显示预设内容
#define SDK_INPUT_MODE_NEWLINE  0x00000100      //是否允许换行; 1表示允许左对齐输入换行显示,0表示不换行

//键盘背光灯模式
#define SDK_KBLT_OFF_TEMP    0x00    //背光省电模式（关闭背光，有按键、刷卡、插卡等操作时只点亮LCD背光）
#define SDK_KBLT_ON_TIMER    0x01    //背光定时模式（打开背光，进入定时模式，无按键超时时关闭背光）
#define SDK_KBLT_OFF_MODE    0x02    //背光常关，即使有按键、刷卡、插卡等操作时都不点亮
#define SDK_KBLT_ON_MODE     0x03    //背光常亮

//键盘按键音模式
#define SDK_KBBEEP_ON    0x01       //键盘按键音打开
#define SDK_KBBEEP_OFF   0x00       //键盘按键音关闭

s32 sdkKbOpen(void);
s32 sdkKbClose(void);
s32 sdkKbFlush(void);
//
s32 sdkKbGetKey(void);
s32 sdkKbGetKeyMs(u8 ucMsgType, s32 iTimeOutMs);
s32 sdkKbGetString(u8 ucRowNo, u8 ucColNo, u8 *pStrBuf, s32 MinLen, s32 MaxLen, u32 Mode, s32 TimeOutMs);
//
s32 sdkKbBeep(u8 ucMode);
s32 sdkKbLight(u8 ucMode);
void sdkKbSetLightTime(u32 uiLightTime);
u32 sdkKbGetLightTime(void);
u8 sdkKbGetLightMode(void);
u8 sdkKbGetBeepFlag(void);

#ifdef __cplusplus
    }
#endif

#endif

