////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
#ifndef _sdk_PINYIN_
#define _sdk_PINYIN_

#include "sdk_common.h"
//#include "FindCode.h"

#define  IME_TABLE_FILE  "/usr/font/PyBxCode.bin"  //输入法码表文件

#define TERMINAL_HARDTEST_CONFIG_FILE   "/app/Test/hardtest.cfg"

#define MONEY_FORMAT    0 //金额
#define NUMERAL_FORMAT  1 //十进制0..9
#define HEX_FORMAT      2 //16进制0..9,a..f,A..F
#define ALPHA_FORMAT    3 //可以输入数字和字符
#define ALPHA_HZ_FORMAT 4 //汉字 数字和字符
#define BINARY_FORMAT   5 //二进制0,1
#define PASSWORD_FORMAT 6 //密码显示*，十进制0..9

#define INPUT_MAX_LEN 128 //最大输入字节数

extern uchar g_ime_status_line;     //有中文输入法状态行 默认第1行
extern uchar g_ime_hz_line;     //有中文输入法汉字显示行 默认第2行
extern uchar g_ime_disp_num;//输入法最多一次显示拼音组数 默认为3

#ifdef __cplusplus
extern "C" {
#endif

//初始化输入法 在系统初始化时调用一次
//返回值:0成功; -1打开输入法码表文件失败; -2拼音输入法初始化失败
int sdk_IMEInit(void);

/*
name       :sdk_Input
desc.        :Get inputed mixed string including number, letter, special character blank, decimal, Chinesecharacter.
input para :    Max_len The maximal bytes to input
            Str The string to save, must have (Max_length + 1) bytes spare space
            Row Started coordinate to display
            number_flag allow numeric only when it's value is not 0, otherwise we can input numeric and character
return      :Key value
*/
uchar sdk_Input(uchar row, uchar col, char *str,uchar max_len,int format);

void sdk_ReadMachineType(unsigned char *info_buf);

#ifdef __cplusplus
}
#endif

#endif

