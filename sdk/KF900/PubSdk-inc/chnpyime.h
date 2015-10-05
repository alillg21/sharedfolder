////////////////////////////////////////////////////////
//文件名          : ChnPyIme.h
//版本            : 2.0.0
//目的及主要功能  : ChnPyIme.c的接口文件
//作者            : 周剑冬(jiandongzhou@yahoo.com)
//创建日期        : 2002-08-01 00:00
//修改者          : 周剑冬(jiandongzhou@yahoo.com)
//修改日期        : 2004-3-19 9:25
//修改说明        : 暂无
////////////////////////////////////////////////////////

/*===================================================
作者    : 周剑冬(jiandongzhou@yahoo.com)
编写年月: 2002年5月
功能    : 拼音输入法
修改者  : 周剑冬(jiandongzhou@yahoo.com)
修改日期: 2004年3月
未经作者许可，不得散发。
===================================================*/

#include "my_define.h"
#include "kbd_define.h"
#include "keymap.h"

//输入状态定义
#define IME_STATUS_PY       0	//拼音输入中文
#define IME_STATUS_BH       1	//笔画输入中文
#define IME_STATUS_ENG_CAP  2	//输入英文大写状态
#define IME_STATUS_ENG_LOW  3	//输入英文小写状态
#define IME_STATUS_DIGITS   4	//输入数字状态
#define IME_STATUS_SYMBOL   5	//输入符号状态
#define IME_STATUS_QW       6	//输入区位状态
#define IME_STATUS_PDA      7	//输入PDA状态 2006-6-20

//输入法运行级别定义
#define IME_RUN_LEVEL0      0	//输入法运行状态0: 码表文件未打开
#define IME_RUN_LEVEL1      1	//输入法运行状态1: 码表文件已打开
#define IME_RUN_LEVEL2      2	//输入法运行状态2: 码表未初始化成功
#define IME_RUN_LEVEL3      3	//输入法运行状态3: 码表已初始化成功

//键盘定义
#define IME_UP          KEY_UP		        //上键
#define IME_DOWN        KEY_DOWN	        //下键
#define IME_LEFT        KEY_LEFT	        //左键
#define IME_RIGHT       KEY_RIGHT	        //右键

#define IME_PgUp        KEY_PGUP	        //上页键
#define IME_PgDn        KEY_PGDN	        //下页键
#define IME_SUBTOTAL    0x72
#define IME_SHIFT_REV   0x7F	//借用【税目】键

#define IME_ENTER       KEY_ENTER
#define IME_VOID        KEY_ESC
#define IME_KEY_CLEAR   KEY_CLEAR

#define IME_TOTAL       0x5D
#define IME_SHIFT       KEY_TAB	//0x52

#define IME_BACKSPACE   KEY_BACK
#define IME_DOT         '.'	//输入法确认，小数点
#define IME_SPACE       '0'	//空格，0



//函 数 名: IME_InitMaBiao
//描    述: 初始化输入法码表
//全局变量: 无
//输入参数: sImeTableFile：码表文件所在路径
//输出参数: 无
//返 回 值: 成功返回0, 失败返回1
//作    者: 周剑冬
//创建日期: 2005/8/26
//修 改 者: 吴志坚
//修改日期:  
//备    注: 
extern unsigned char IME_InitMaBiao(char *sImeTableFile);



//函 数 名: IME_InitPYIndexTbl
//描    述: 初始化拼音输入法
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 成功返回0, 失败返回1
//作    者: 周剑冬
//创建日期: 2005/8/26
//修 改 者: 吴志坚
//修改日期: 
//备    注: 只有在输入法码表文件打开的情况下该函数才会起作用.
extern unsigned char IME_InitPYIndexTbl(void);




//================================================
// 函 数 名: GetString
// 功能描述: 输入中文、字母、数字、特殊符号、
//           空格、小数点 的混合字符串
// 全局变量: 无
// 输入参数:
//   Max_length: 允许输入的最大字节数
//   row, col: 为目标显示的起始行列坐标
// 输出参数:
//   rslt_str: 存储输入的混合字符串,应留有至少
//      (Max_length + 1)个字节的空间
// 返 回 值: 键值(如取消,合计,确认等)
// 作    者: 周剑冬
// 创建日期: 2002-06-XX
// 修 改 者: 周剑冬
// 修改日期: 2004-3-18 15:51
//================================================
extern uchar GetString(uchar Max_length, uchar * chinese_string, uchar row, uchar col);

extern uchar GetStringSub(uchar ime_status, uchar Max_length, uchar * rslt_str, uchar row, uchar col);
//函 数 名: input_use_method
//描    述: 使用拼音输入法输入字母、字符、数字、和汉字
//全局变量: 无
//输入参数: 无
//输出参数: 输入的字符串
//返 回 值: 字符串长度
//作    者: 吴 志 坚
//创建日期: 2010/4/14
//修 改 者: 
//修改日期: 
//备    注: 使用该函数前,必须先调用IME_InitMaBiao打开码表文件，然后
//			调用IME_InitPYIndexTbl初始化拼音输入法。
extern unsigned short input_use_method(unsigned char *inpt_str );
