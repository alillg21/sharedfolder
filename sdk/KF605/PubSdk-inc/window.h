#ifndef __WINDOW_H__
#define __WINDOW_H__
#include <stdio.h>
#include <string.h>
#include "object.h"


#define WIN_SELL            0x00	//税控销售窗口
#define WIN_MENU            0x01	//税控菜单窗口
#define WIN_OTHER           0x02	//税控其他窗口
//======================    ======================
#define EFT_WIN_SELL        0x80	//银行销售窗口
#define EFT_WIN_MENU        0x81	//银行菜单窗口
#define EFT_WIN_OTHER       0x82	//银行其他窗口

#define NO_IDLE_REFRESH     0x00	//定义的 loop_idle 事件不需要对某控件进行显示刷新 2006-6-13 11:56
#define IDLE_REFRESH_AUTO   0x01	//定义的 loop_idle 事件需要对某控件进行实时显示刷新 2006-6-13 11:56
#define IDLE_REFRESH_PRESS  0x02	//已定义 loop_idle 事件，要求每次按键都要对某控件进行刷新 2006-6-13 11:57

typedef struct {
	unsigned char exec_limit;	//该窗口的执行权限限制 0无限制 0～3位分别限收款员、主管、经理和维修人员
	unsigned char type;	//窗口类型
	unsigned char wait_tip;	//如果窗口进入可能需要较长时间的准备，则建议将该标志置为1
	unsigned char showhint;	//提示显示标志
	unsigned char *hint;	//本窗口的提示信息
	unsigned char *tips;	//窗口提示信息
	unsigned char x;	//横坐标
	unsigned char y;	//纵坐标
	unsigned char w;	//宽度
	unsigned char h;	//高度
	unsigned char border_style;	//是否画边框
	unsigned char init_flag;
	unsigned char need_pretreatment;	//预处理标志 1:执行show_post 2:执行loop_pre 3:二者均执行
	object_t **sub_objs;	//此窗口的控件集合
	unsigned char objs_num;	//此窗口包含的控件数
	unsigned char tab_num;	//可聚焦的控件数，必须小于等于objs_num 2006-5-31
	unsigned char cur_tabstop;	//当前停在第几个可聚焦的控件上，必须小于tab_num，从0开始计数 2006-5-31
	unsigned char *tab_order;	//控件聚焦顺序 2006-5-31
	unsigned char exist_invisible_ctrl;	//该窗体存在不可见控件，如果LCD响应够快，则去掉此属性
	//==焦点控制属性组 start== jdzhou 2006-12-26
	unsigned char cur_obj;	//当前控件索引
	unsigned char refocus;	//是否重新聚焦         1:重新聚焦          其他:保留上次焦点
	unsigned char refocus_type;	//重新聚焦时初始值类型 1:采用init_obj的值  其他:自动搜索
	unsigned char init_obj;	//重新聚焦时指定聚焦控件索引，若非特别要求，不要更改此值
	//==焦点控制属性组 end  == jdzhou 2006-12-26
	unsigned char fixed_prev_win;	//prev_win不可更改标志（1：固定，否则：可更改）
	unsigned char idle_refresh;	//1:自动刷新; 2:按键刷新 有定义loop_idle成员函数，而且需要对idle_refresh所做的更改进行显示刷新 2006-6-9
	unsigned char idle_refresh_sn;	//idle_refresh定义为需要刷新时，指定需要刷新的控件序号 2006-6-12 11:06

	unsigned char para;	//在调用该窗口的地方,传给该窗口的参数 //modify by zjwu 2008-05-20

	void *prev_win;		//前一窗口，用于返回
	void (*init) (void *this);	//Attach the objs to a window, look at the demo
	void (*update) (void *this);	//Change the objs attr such as enabled ATTR
	void (*show_post) (void *this);
	//Message loop routines
	void (*loop_pre) (void *this);
	void (*loop_idle) (void *this, unsigned char keycode);	//发呆处理函数，无键值时为发呆，否则表示结束发呆
	void (*loop) (void *this, unsigned char keycode);
	void (*loop_post) (void *this);
	void (*close_query) (void *this);	//窗口关闭之前进行询问或处理
	//up/down/hang/pick/complete/F1/cancel/lock/print以及1..9这些键的特别处理
	void (*special_key) (void *this, unsigned char keycode);
} window_t;



//函 数 名: window_run
//描    述: 运行一个窗口
//全局变量: 无
//输入参数: window:指向一个窗口结构体的指针
//输出参数: 无
//返 回 值: 无			
//作    者: 周剑冬
//创建日期: 
//修 改 者: 吴志坚
//修改日期: 2009/8/26
//备    注: 
void window_run(window_t * window);

//函 数 名: show_spec_window
//描    述: 该函数单独使用并不显示一个窗口,需要与window_run函数配合使用,
//			技巧:先调用show_spec_window(win_a), 然后调用window_run(win_b), 这时
//			并不会显示win_b, 只会显示win_a
//全局变量: 无
//输入参数: window:指向一个窗口结构体的指针
//输出参数: 无
//返 回 值: 无			
//作    者: 周剑冬
//创建日期: 
//修 改 者: 吴志坚
//修改日期: 2009/8/26
//备    注: 
void show_spec_window(window_t * ap_win);

//如果在窗口定义时没有给init_flag附初始值0, 那么请在show该窗口之
//前先调用该函数, 然后在能show
void app_add_window(window_t * win);


//立即运行指定的窗口
void window_run_now(window_t * window);

#endif				/*  __WINDOW_H__  */
