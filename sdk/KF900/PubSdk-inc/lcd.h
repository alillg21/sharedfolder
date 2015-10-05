#ifndef _LCD_H_
#define _LCD_H_

#define GUI_WIN_HEIGHT 	8
#define GUI_WIN_WIDTH  	16
#define GUI_LINE0		0
#define GUI_LINE1		2
#define GUI_LINE2		4
#define GUI_LINE3		6


#define MSG_OK				0x01		//仅显示"确认",  返回1
#define MSG_OKCANCEL 		0x03		//显示"确认  取消", 确认返回1, 取消返回0
#define MSG_ANYKEY			0x7			//显示"按任意键返回",      返回1
#define MSG_OKCANCEL_TIME	0x8			//显示"xx秒后自动返回",    返回1
#define MSG_ANYKEY_TIME		0x9			//显示"xx秒后自动返回",    返回1
#define MSG_TIME			0x10

#define ICON_PHONE1		0x01		//电话图标的第一个(从上往下数,下同)
#define ICON_PHONE2		0x02		//电话图标的第二个
#define ICON_PHONE3     0x04		//电话图标的第三个

#define ICON_BAT		0x01		//电池图标外框
#define ICON_BAT1		0x02		//电池图标从右往左第一格
#define ICON_BAT2		0x04		//电池图标从右往左第二格
#define ICON_BAT3		0x08		//电池图标从右往左第三格
#define ICON_BAT4		0x10		//电池图标从右往左第四格

#define LCD_ALWAYS_ON	1
#define LCD_ALWAYS_OFF	0


//函 数 名: lcd_disp
//描    述: 在xaddr行, yaddr列的位置显示字符串
//全局变量: LCDHeight,LCDWidth
//输入参数: 
//			xaddr:行位置,以16个像素点为单位(即在垂直方向上16个像素为1行)。
//			yaddr:列位置,以8个像素点为单位(即在水平方向上8个像素为1列).
//			buf:要显示的字符串.
//输出参数: 
//返 回 值: 
//作    者: 周剑冬
//创建日期: 2009/8/24
//修 改 者: 
//修改日期: 
//备    注: 
extern unsigned char lcd_disp(unsigned char xaddr, unsigned char yaddr, const char *buf);


//函 数 名: con_disp
//描    述: 在xaddr行, yaddr列的位置反相显示字符串
//全局变量: LCDHeight,LCDWidth
//输入参数: 
//			xaddr:行位置,以16个像素点为单位(即在垂直方向上16个像素为1行)。
//			yaddr:列位置,以8个像素点为单位(即在水平方向上8个像素为1列).
//			buf:要显示的字符串.
//输出参数: 
//返 回 值: 
//作    者: 周剑冬
//创建日期: 2009/8/24
//修 改 者: 
//修改日期: 
//备    注: 
extern unsigned char con_disp(unsigned char xaddr, unsigned char yaddr, const char *buf);

//函 数 名: draw_horizontal_line
//描    述: 从y行x列开始，显示width像素宽,1像素高的横线
//全局变量: 无
//输入参数: 
//			x:以像素为单位的列的位置.
//			y:以像素为单位的行的位置.
//			width:以像素为单位的水平线的宽度.
//输出参数: 无
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/8/25
//修 改 者: 
//修改日期: 
//备    注: 
extern void draw_horizontal_line(int x, int y, int width);


//函 数 名: draw_vertical_line
//描    述: 从y行x列开始，显示height像素高，1像素宽的竖线
//全局变量: 无
//输入参数: 
//			x:以像素为单位的列的位置.
//			y:以像素为单位的行的位置.
//			height:以像素为单位的垂直线的高度
//输出参数: 无
//返 回 值: 无
//作    者: 周剑冬
//创建日期: 2009/8/25
//修 改 者: 吴 志 坚
//修改日期: 
//备    注: 
extern void draw_vertical_line(int x, int y, int height);


//函 数 名: con_draw_vertical_line
//描    述: 与draw_vertical_line不同的是，draw_vertical_line用黑点画线,该函数是用白点画线.
//全局变量: 无
//			x:以像素为单位的列的位置.
//			y:以像素为单位的行的位置.
//			height:以像素为单位的垂直线的高度
//输出参数: 无
//返 回 值: 无
//作    者: 周剑冬
//创建日期: 2009/8/25
//修 改 者: 吴志坚
//修改日期: 
//备    注: 
extern void con_draw_vertical_line(int x, int y, int height);


//函 数 名: _disp_blank
//描    述: 从x行,y列开始画一个长度为len,高度为2的空白矩形
//全局变量: LCDWidth, LCDHeight
//输入参数: 
//			x:行位置(8个像素为一行)
//			y:列位置(8个像素为一列)
//			len:矩形宽度(以8个像素为单位)			
//输出参数: 
//返 回 值: 
//作    者: 周剑冬
//创建日期: 2009/8/24
//修 改 者: 吴志坚
//修改日期: 
//备    注: 矩形的高度为2x8个像素
extern void _disp_blank(unsigned char x, unsigned char y, unsigned char len);



//函 数 名: disp_blank
//描    述: 从x行,y列开始画一个长度为len,高度为2的空白矩形
//全局变量: LCDWidth, LCDHeight
//输入参数: 
//			x:行位置(以垂直方向上的16个像素为一行)
//			y:列位置(以水平方向上的8个像素为一列)
//			len:矩形宽度(以8个像素为单位)			
//输出参数: 
//返 回 值: 
//作    者: 周剑冬
//创建日期: 2009/8/24
//修 改 者: 吴志坚
//修改日期: 
//备    注: 矩形的高度为2x8个像素
extern void disp_blank(unsigned char x, unsigned char y, unsigned char len);



//函 数 名: _con_disp
//描    述: 在xaddr行, yaddr列的位置反相显示字符串
//全局变量: LCDHeight,LCDWidth
//输入参数: 
//			xaddr:行位置,以8个像素点为单位,即在垂直方向上8个像素为一行。
//			yaddr:列位置,以8个像素点为单位,即在水平方向上8个像素为一列?//			buf:要显示的字符串.
//输出参数: 
//返 回 值: 
//作    者: 周剑冬
//创建日期: 2009/8/24
//修 改 者: 
//修改日期: 
//备    注: 
extern unsigned char _con_disp(unsigned char xaddr, unsigned char yaddr, const char *buf);



//函 数 名: _lcd_disp
//描    述: 在xaddr行, yaddr列的位置显示字符串
//全局变量: LCDHeight,LCDWidth
//输入参数: 
//			xaddr:行位置,以8个像素点为单位,即在垂直方向上8个像素为一行。
//			yaddr:列位置,以8个像素点为单位,即在水平方向上8个像素为一列。
//			buf:要显示的字符串.
//输出参数: 
//返 回 值: 
//作    者: 周剑冬
//创建日期: 2009/8/24
//修 改 者: 
//修改日期: 
//备    注: 
extern unsigned char _lcd_disp(unsigned char xaddr, unsigned char yaddr, const char *buf);



//函 数 名: LCDFillRect
//描    述: 用color指定的颜色填充一个矩形方块.以屏幕左上角为坐标原点,水平向右为X轴正向,
//			垂直向下为Y轴正向。矩形左上角坐标为(x0*8, y0*8),矩形宽度为w*8像素, 高度为h*8像素
//全局变量: 无
//输入参数: x0, y0, w, h, color
//输出参数: 无
//返 回 值: 无
//作    者: 周剑冬
//创建日期: 
//修 改 者: zjwu
//修改日期: 2009/8/21
//备    注: 
extern void LCDFillRect(int x0, int y0, int w, int h, int color);



extern void LCDPutImage(int x0, int y0, int w, int h, const char *buf);

extern void LCDPutImageRev(int x0, int y0, int w, int h, const char *buf);


//函 数 名: clear_rows
//描    述: 清除从start_row字符行(包括start_row行)起到end_row字符行(不包括end_row行)止的所有行
//全局变量: LCDHeight
//输入参数: 
//			start_row:起始行
//			end_row:结束行
//输出参数: 
//返 回 值: 
//作    者: 吴 志 坚
//创建日期: 2009/8/24
//修 改 者: 
//修改日期: 
//备    注: 垂直方向上,8个像素为一行
extern void clear_rows(int start_row, int end_row);

//extern void fmt_ctrl_str(const char *str_in, unsigned char expect_len, unsigned char *ok_len, unsigned char fill_right_blank, char *str_out);




//函 数 名: putpixel
//描    述: 以屏幕左上角为原点，水平向右为x轴正方向,垂直向下为y轴正方向的这样坐标系中的
//			显示像素点的函数.
//全局变量: fbmem:lcd缓冲区映射地址. fb_w:以像素为单位的屏幕宽度. fb_h:以像素为单位的屏幕高度.
//输入参数: 
//			x:X轴坐标. 
//			y:Y轴坐标.
//			c:0-表示白点。1-表示黑点。
//输出参数: 无
//返 回 值: 无
//作    者: 周剑冬
//创建日期: 
//修 改 者: 吴 志 坚
//修改日期: 2009/8/21
//备    注: 注释部分由zjw添加
extern void putpixel(int x, int y, int c);



//函 数 名: lcd_refresh
//描    述: 屏幕刷新
//全局变量: g_fbfd,显示设备文件句柄  
//输入参数: 无
//输出参数: 无
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/8/20
//修 改 者: 
//修改日期: 
//备    注: 等同于lcd_update函数
extern void lcd_refresh(void);


//清除整个屏幕
extern void clear_lcd(void);



//函 数 名: GetLcdHeight
//描    述: 得到屏幕高度
//全局变量: LCDWidth
//输入参数: 无
//输出参数: 无
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/8/20
//修 改 者: 
//修改日期: 
//备    注: 这个宽度是指屏幕纵向像素个数/8后的值
extern unsigned short GetLcdHeight(void);


//函 数 名: GetLcdWidth
//描    述: 得到屏幕宽度
//全局变量: LCDWidth
//输入参数: 无
//输出参数: 无
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/8/20
//修 改 者: 
//修改日期: 
//备    注: 这个宽度是指屏幕横向像素个数/8后的值
extern unsigned short GetLcdWidth(void);


//函 数 名: lcd_back_light_on
//描    述: 打开背景灯
//全局变量: g_fbfd,显示设备文件句柄  
//输入参数: 无
//输出参数: 无
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/8/20
//修 改 者: 
//修改日期: 
//备    注: 
extern void lcd_back_light_on(void);

//函 数 名: lcd_back_light_off
//描    述: 关闭背景灯
//全局变量: g_fbfd,显示设备文件句柄  
//输入参数: 无
//输出参数: 无
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/8/20
//修 改 者: 
//修改日期: 
//备    注: 
extern void lcd_back_light_off(void);


//函 数 名: SetLcdBKLightStatus
//描    述: 设置lcd背景灯的当前状态为开或者关
//全局变量: lcd_back_light_status
//输入参数: light_flag>0表示当前背景灯为开，=0为关。
//输出参数: 无
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/8/20
//修 改 者: 
//修改日期: 
//备    注: 
extern void SetLcdBKLightStatus(unsigned char light_flag);


//函 数 名: GetlcdBkLightStatus
//描    述: 取当前背景灯的状态。
//全局变量: lcd_back_light_status
//输入参数: 无
//输出参数: 无
//返 回 值: 返回当前背景灯的状态，>0表示灯亮，=0表示灯息
//作    者: 吴 志 坚
//创建日期: 2009/8/20
//修 改 者: 
//修改日期: 
//备    注: 
extern unsigned char GetlcdBkLightStatus(void);


//函 数 名: DispIconSign
//描    述: 显示图标栏的信号强度图标
//全局变量: g_fbfd,显示设备文件句柄 
//输入参数: sign_value:信号强度值,取值0~5共6挡,0表示信号最弱,5表示信号最强		
//输出参数: 
//返 回 值: 
//作    者: 吴 志 坚
//创建日期: 2009/8/20
//修 改 者: 
//修改日期: 
//备    注: 
extern void DispIconSign( int sign_value );


//函 数 名: DispIconUp
//描    述: 显示图标栏向上箭头
//全局变量: g_fbfd,显示设备文件句柄
//输入参数: switch_flag>0:	显示箭头
//			switch_flag=0:	不显示箭头
//输出参数: 无
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/8/20
//修 改 者: 
//修改日期: 
//备    注: 
extern void DispIconUp(char switch_flag );


//函 数 名: DispIconDown
//描    述: 显示图标栏向下箭头
//全局变量: g_fbfd,显示设备文件句柄
//输入参数: switch_flag>0:	显示箭头
//			switch_flag=0:	不显示箭头
//输出参数: 无
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/8/20
//修 改 者: 
//修改日期: 
//备    注: 
extern void DispIconDown(char switch_flag );


//函 数 名: DispIconBattary
//描    述: 显示电池图标
//全局变量: g_fbfd:显示设备文件句柄
//输入参数: BatID,其取值如下:
//			ICON_BAT(0X01):	显示电池图标的外框
//			ICON_BAT1(0X02):显示电池图标的第一格(从右往左数)
//			ICON_BAT2(0X04):显示电池图标的第二格(从右往左数)
//			ICON_BAT3(0X08):显示电池图标的第三格(从右往左数)
//			ICON_BAT4(0X10):显示电池图标的第四格(从右往左数)
//			0:				不显示电池图标
//输出参数: 无
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/8/20
//修 改 者: 
//修改日期: 
//备    注: 
extern void DispIconBattary( unsigned char BatID );


//函 数 名: DispIconPrinter
//描    述: 显示图标栏的打印机
//全局变量: g_fbfd,显示设备文件句柄
//输入参数: switch_flag>0:	显示
//			switch_flag=0:	不显
//输出参数: 无
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/8/20
//修 改 者: 
//修改日期: 
//备    注: 
extern void DispIconPrinter( char switch_flag );


//函 数 名: get_fb_handle
//描    述: 取显示设备文件句柄
//全局变量: g_fbfd
//输入参数: 无
//输出参数: 无
//返 回 值: 显示设备文件句柄
//作    者: 吴 志 坚
//创建日期: 2009/8/20
//修 改 者: 
//修改日期: 
//备    注: 
int get_fb_handle(void);



//函 数 名: get_fb_mem
//描    述: 取LCD缓存的映射地址
//全局变量: fbmem
//输入参数: 无
//输出参数: 无
//返 回 值: unsgined char型的指针
//作    者: 吴 志 坚
//创建日期: 2009/8/20
//修 改 者: 
//修改日期: 
//备    注: 
unsigned char *get_fb_mem(void);


//函 数 名:	show_bm
//功    能:	显示位图
//输入参数: 
//			start_x:	行起始位置(以像素点为单位)
//			start_y:	列起始为止(以像素点为单位)
//			bmbuf:		描述位图点阵的数组(从左到右,从上到下)
//			bmbuf_size:	数组大小
//			bm_width:	位图宽度(以像素为单位)
extern void show_bm(int start_x, int start_y, unsigned char *bmbuf, int bmbuf_size, int bm_width );


//函 数 名: _message_box
//描    述: 显示字符串
//全局变量: LCDWidth, LCDHeight
//输入参数: msg:指向要显示字符串的指针
//输出参数: 无
//返 回 值: 如果是按回车键,则返回1,否则返回0
//作    者: 周剑冬
//创建日期: 2009/8/24
//修 改 者: 吴志坚
//修改日期: 
//备    注:
//			1.显示字符串前整个屏幕先被清空.
//			2.要退出这个显示界面必须按确认键或者取消键.
//			3.要显示的字符串可以加下面的控制字符:
//			将带控制字符的字符串输出到str_out中
//			控制字符如下：\n, \t, \b, 意义分别如下：
//			默认靠左对齐（后补空格）
//			\n:回车换行，不考虑兼容其他形式
//			\t: 本来是跳格，在此转义用作居中控制，表示其后的字符串按out_len居中（前后补空格）
//      	（前提是其后不能直接是控制字符，否则忽略）
//			\b: 本来是退格，在此转义用作靠右对齐，表示其后的字符串按out_len靠右（前补空格）
//      	（前提是其后不能直接是控制字符，否则忽略）
//			添加参数，表示后方是否补空格。
//			举例：\n\t表示先换一行，然后将\t后的字符串居中
//			控制字符和字符串的位置关系：控制字符在前，字符串在后
//			\n可单独使用\t和\b不能单独使用，必须后跟字符串，否则将被忽略
extern unsigned char _message_box(char *msg);


//参见_message_box函数,如其区别如下:
//输入参数disp_time指明消息要显示的时间(以秒为单位),显示时间达到这个值后自动会会
//退出显示界面,且函数的返回值是0.
extern unsigned char _message_box_in_time(char *msg, long disp_time);

//函 数 名: MessageBox
//描    述: 显示消息(每行最多显示MAX_MSG_LENGTH个字符,最多能显示MAX_MSG_LINES行)
//全局变量: 无
//输入参数: 
//			msg:指向要显示的字符串的指针(也可以带控制字符,含义同_message_box函数).
//			msg_type:消息类型,其取值如下:
//			1.MSG_OKCANCEL:如果disp_time=0,则必须按回车键或者取消键才能退出显示界面,回车键返回1,取消键返回0.
//			2.MSG_ANYKEY按任意键都返回0.
//			3.MSG_ANYKEY_TIME:按任意键返回0,如果不按键,则到disp_time指定的时间后立即返回0(前提是disp_time>0).
//			4.MSG_OKCANCEL_TIME:按回车键返回1,取消键返回0, 或者到disp_time指定的时间后返回0(前提是disp_time>0).
//			5.MSG_TIME:改消息显示时间达到disp_time指定的时间后返回0.
//			disp_time:消息显示的时间.disp_time=0表示无限长.
//输出参数: 无
//返 回 值: 1或者0
//作    者: 吴 志 坚
//创建日期: 2009/8/24
//修 改 者: 
//修改日期: 
//备    注: 
extern char MessageBox(const char *msg, unsigned char msg_type, unsigned char disp_time );

#endif


