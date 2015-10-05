/********************************************************************
文件名 : sdkInput.h
描  述 : public库里面和按键输入有关的操作
版  权 : 长城开发
作  者 : DJ Chen
修改记录: 
    日期              修改人  修改内容
    2014-02-18 10:44  DJ Chen  创建
********************************************************************/
#ifndef BASE_SDKINPUT_H_
#define BASE_SDKINPUT_H_

#ifdef __cplusplus
    extern "C" {
#endif

//标准输入模式
#define SDK_INPUT_NUM     0x00000001        //输入数字
#define SDK_INPUT_CHAR    0x00000002        //输入字母
#define SDK_INPUT_SYMBOL  0x00000004        //输入特殊可见字符
#define SDK_INPUT_HEX     0x00000008        //输入16进制
#define SDK_INPUT_HZ      0x00000010        //输入输入汉字
#define SDK_INPUT_POINT   0x00000020        //输入带小数点数字(金额)
#define SDK_INPUT_PWD     0x00000040        //输入密码(回显为*)
#define SDK_INPUT_IP      0x00000080        //输入IP地址
#define SDK_INPUT_LEFT    0x00000100        //左对齐(为零则为右对齐)
#define SDK_INPUT_DISP    0x00000200        //反显(为零则为正显) 
#define SDK_INPUT_HANDWRITE 0x00000400      //手写

#define SDK_KEY_MASK_0       0x00000001  //'0'
#define SDK_KEY_MASK_1       0x00000002  //'1'
#define SDK_KEY_MASK_2       0x00000004  //'2'
#define SDK_KEY_MASK_3       0x00000008  //'3'
#define SDK_KEY_MASK_4       0x00000010  //'4'
#define SDK_KEY_MASK_5       0x00000020  //'5'
#define SDK_KEY_MASK_6       0x00000040  //'6'
#define SDK_KEY_MASK_7       0x00000080  //'7'
#define SDK_KEY_MASK_8       0x00000100  //'8'
#define SDK_KEY_MASK_9       0x00000200  //'9'
#define SDK_KEY_MASK_ENTER   0x00000400  //ENTER
#define SDK_KEY_MASK_CANCAL  0x00000800  //CANCAL
#define SDK_KEY_MASK_UP      0x00001000  
#define SDK_KEY_MASK_DOWN    0x00002000
#define SDK_KEY_MASK_CLEAR   0x00004000
#define SDK_KEY_MASK_FUN     0x00008000
#define SDK_KEY_MASK_MENU    0x00010000
#define SDK_KEY_MASK_ALPHA   0x00020000
#define SDK_KEY_MASK_BACKSPACE   0x00040000
#define SDK_KEY_MASK_LEFT    0x00080000
#define SDK_KEY_MASK_RIGHT   0x00100000
#define SDK_KEY_MASK_ALL     0x80000000  //所有键值有效


s32 sdkKbInput(u32 uiDispRow, u32 uiDispCol, u8 *pszOut, u32 uiMinLen, u32 uiMaxLen, u32 uiMode, u32 uiOvertimer);
s32 sdkKbWaitKey(u32 uiMask, u32 uiOvertimer);


#ifdef __cplusplus
    }
#endif
#endif







