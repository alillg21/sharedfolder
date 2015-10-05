#include "kbd_define.h"
#include "PosModel.h"

#ifndef __KEYMAP_H__
#define __KEYMAP_H__


//用这两个键来进纸和退纸
#ifdef KBD_5				//假定K5为针式打印机
#define KEY_FEED 0xFF
#define KEY_ROLLBACK 0xFE
#endif

#define KEY_0	'0'
#define KEY_1	'1'
#define KEY_2	'2'
#define KEY_3	'3'
#define KEY_4	'4'
#define KEY_5	'5'
#define KEY_6	'6'
#define KEY_7	'7'
#define KEY_8	'8'
#define KEY_9	'9'
#define KEY_00			0xFA
#define KEY_PLUS		0xFB
#define KEY_MINUS		0xFC
#define NULL_KEY 		0x00

#define KEY_ESC       0x81
#define KEY_BACK      0x82
#define KEY_ENTER     0x84	

#define KEY_HOME      0x92
#define KEY_END       0x93
#define KEY_UP        0x94
#define KEY_DOWN      0x95

#ifdef POS_KF600
  #define KEY_F1            0xA0
  #define KEY_F2            0xA1
  #define KEY_F3            0xA2
  #define KEY_F4            0xA4

  #define KEY_LEFT        KEY_F1
  #define KEY_RIGHT       KEY_F4
#else
#define KEY_LEFT      0x96
#define KEY_RIGHT     0x97
#endif

#define KEY_PGUP      KEY_MENU
#define KEY_PGDN      KEY_FUNC

#define KEY_CLEAR     0x9a
#define KEY_MENU      0x9d
#define KEY_FUNC      0x9E


#define KEY_TAB     	0xb1			//输入法/切换键
#define KEY_SHIFT_REV   KEY_SELLER		//反响切换,借用[营业员键]


//组合键定义
#define UNKEY_TAB1		0xD1			//组合键Tab+1
#define UNKEY_TAB2		0xD2			//组合键Tab+2
#define UNKEY_10		0xD3			//组合键1+0
#define UNKEY_ENTER1	0xD4			//组合键ENTER+1




//函 数 名: Set_bklt_dtime
//描    述: 设置背景灯延时关闭时间
//全局变量: 无
//输入参数: time
//			=0表示背景灯常关
//			=1表示背景灯常开
//			>1表示无动作时背景灯延时关闭的时间(以秒为单位)
//输出参数: 无
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/8/26
//修 改 者: 
//修改日期: 
//备    注: 
void Set_bklt_dtime(unsigned short time);


//函 数 名: Get_bklt_dtime
//描    述: 返回当前背景灯延时关闭所设置的时间值.
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 0-表示背景灯设置为常关
//			1-表示背景灯设置为常开
//			>1-表示无动作时延时关闭的时间值(以秒为单位)
//作    者: 吴 志 坚
//创建日期: 2009/8/26
//修 改 者: 
//修改日期: 
//备    注: 
unsigned short Get_bklt_dtime(void);


//函 数 名: back_light_contorl
//描    述: 参见sigfcn函数的描述
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/8/26
//修 改 者: 
//修改日期: 
//备    注: 
void back_light_contorl(void);


//函 数 名: LcdBackLightInit
//描    述: 从配置文件中读取背景灯延时开关值.同时打开背景灯.
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/8/26
//修 改 者: 
//修改日期: 
//备    注: 
void LcdBackLightInit(void);


//函 数 名: getch
//描    述: 返回当前从键盘读到的键码.
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 当前键码.
//作    者: 吴 志 坚
//创建日期: 2009/8/26
//修 改 者: 
//修改日期: 
//备    注: 无按键时返回0, 键码大于0x80(表示松开按键)时返回0
unsigned char getch(void);


//函 数 名: getkey
//描    述: 返回当前从键盘读到的键值.
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: keymap.h定义的键值.
//作    者: 吴 志 坚
//创建日期: 2009/8/26
//修 改 者: 
//修改日期: 
//备    注: 无按键时返回0
unsigned char getkey(void);


//函 数 名: press_key
//描    述: 读键盘直到有按键时才返回键值.
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: keymap.h定义的键值.
//作    者: 吴 志 坚
//创建日期: 2009/8/26
//修 改 者: 
//修改日期: 
//备    注: 
unsigned char press_key(void);


//函 数 名: key2asc
//描    述: 将键码翻译成按键值.
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: keymap.h定义的键值
//作    者: 吴 志 坚
//创建日期: 2009/8/26
//修 改 者: 
//修改日期: 
//备    注: 
unsigned char key2asc(unsigned char keycode);


//函 数 名: sigfcn
//描    述: 如果当前lcd背景灯延时控制开关不是设置为常闭,调用该函数会打开背景灯,
//			同时记录当前时间.该函数通常与函数back_light_contorl配合使用,当有按键或
//			其它动作时调用该函数打开背景灯,同时记录打开背景灯的时间,然后在其它的while循环中
//			调用back_light_contorl函数来判断当前无动作时间是否达到预先设定的值,如果达到设定值
//			则关掉背景灯.
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/8/26
//修 改 者: 
//修改日期: 
//备    注: 
void sigfcn(void);


//函 数 名: back_light_contorl
//描    述: 参见sigfcn函数的描述
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/8/26
//修 改 者: 
//修改日期: 
//备    注: 
void back_light_contorl(void);


//函 数 名: get_union_key
//描    述: 返回一个组合键. 组合键的键值如下(在keymap.h文件中定义):
//			#define UNKEY_TAB1		0xD1			//组合键Tab+1
//			#define UNKEY_TAB2		0xD2			//组合键Tab+2
//			#define UNKEY_10		0xD3			//组合键1+0
//			#define UNKEY_ENTER1	0xD4			//组合键ENTER+1
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: UNKEY_TAB1, UNKEY_TAB2, UNKEY_10, UNKEY_ENTER1
//作    者: 吴 志 坚
//创建日期: 2009/8/26
//修 改 者: 
//修改日期: 
//备    注: 
unsigned short get_union_key(void);

#endif
