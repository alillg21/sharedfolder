/***********************************************************************************************************
 *
 * @FILENAME		: prn-support.h
 *
 * @AUTHOR  		: zjwu
 *
 * @DATE	  		: 2009-9-2
 *
 * @DESCRIPTION		: 打印API头文件
 *
 * @COPYRIGHT		: 2009-2012 ShenZhen KAIFA Technology Co.,Ltd.
 *
 .
 ***********************************************************************************************************/
#ifndef PRN_SUPPORT_H
#define PRN_SUPPORT_H


//	Font Mode
#define PRN_MODE_NORMAL   0	// normal height, normal width
#define PRN_MODE_DBWIDTH  1	// normal height, double width
#define PRN_MODE_DBHEIGHT 2	// double height, normal width
#define PRN_MODE_DBBOTH   3	// double height, double width


#define PRN_FONT12	0	//使用12x12字体打印
#define PRN_FONT16	1	//使用16x16字体打印
#define PRN_FONT24	2	//使用24x24字体打印


#define DEFAULT_DARKNESS	7							//默认打印色深
#define DEFAULT_FONTTYPE	PRN_FONT12		//默认打印字体
#define DEFAULT_LINESPACE	4							//默认行间距为4点行

#define MAX_DARKNESS	15								//最大色深值
#define MIN_DARKNESS	1									//最小色深值



#define PRN_FAILURE					-1
#define PRN_OUT_OF_PAPER 			-2
#define PRN_ABORT_TEMP   			-3


//函 数 名: PRN_OpenDevice
//描    述: 打开打印机设备
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 成功返回0, 失败返回-1
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 
int PRN_OpenDevice(void);

//函 数 名: PRN_InitFont12
//描    述: 初始化12点阵的打印字库.该函数将12点阵的打印字库的地址传给打印库.
//全局变量: 无
//输入参数: 
//			cn_addr:12点阵的汉字库的地址
//			en_addr:12点阵的ASC字库的地址
//输出参数: 无
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 
void PRN_InitFont12(void *cn_addr, void *en_addr );

//函 数 名: PRN_InitFont16
//描    述: 初始化16点阵的打印字库.该函数将16点阵的打印字库的地址传给打印库.
//全局变量: 无
//输入参数: 
//			cn_addr:16点阵的汉字库的地址
//			en_addr:16点阵的ASC字库的地址
//输出参数: 无
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 
void PRN_InitFont16(void *cn_addr, void *en_addr );

//函 数 名: PRN_InitFont24
//描    述: 初始化24点阵的打印字库.该函数将24点阵的打印字库的地址传给打印库.
//全局变量: 无
//输入参数: 
//			cn_addr:24点阵的汉字库的地址
//			en_addr:24点阵的ASC字库的地址
//输出参数: 无
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 
void PRN_InitFont24(void *cn_addr, void *en_addr );

//函 数 名: PRN_DeviceInit
//描    述: 初始化打印设备, 完成下列3个动作
//			1.打开打印机设备
//			2.设置默认字体为默认值DEFAULT_FONTTYPE
//			3.设置打印色深为默认值DEFAULT_DARKNESS
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 失败均返回-1, 成功返回0
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 
int PRN_DeviceInit( void );


//函 数 名: PRN_CloseDevice
//描    述: 关闭打印机设备
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 成功返回0，失败返回-1
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 
int PRN_CloseDevice(void);


//函 数 名: PRN_PaperForward
//描    述: 向前走dot_line指定点行的纸
//全局变量: 无
//输入参数: dot_line:走纸点行数
//输出参数: 无
//返 回 值: 成功返回0, 失败返回-1
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 
int PRN_PaperForward(unsigned short dot_lines);


//函 数 名: PRN_PaperFallback
//描    述: 向后退纸, 退纸长度为dot_line点行
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 成功返回0,失败返回-1
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 该函数对热敏打印机机型无效
int PRN_PaperFallback(unsigned short dot_lines);



//函 数 名: PRN_SetDarkness
//描    述: 设置打印色深
//全局变量: 无
//输入参数: index:色深值,范围从MIN_DARKNESS到MAX_DARKNESS
//输出参数: 无
//返 回 值: 成功返回0,失败返回-1
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 
int PRN_SetDarkness( unsigned char  index );


//函 数 名: PRN_SetFontMode
//描    述: 设置打印字体模式
//全局变量: 无
//输入参数: mode:字体模式, 可以是下列值之一
//			PRN_MODE_NORMAL		:标准打印
//			PRN_MODE_DBWIDTH	:倍宽打印
//			PRN_MODE_DBHEIGHT	:倍高打印
//			PRN_MODE_DBBOTH		:倍宽倍高打印	
//输出参数: 无
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 如果不设置, 默认是PRN_MODE_NORMAL模式
void PRN_SetFontMode(int mode );


//函 数 名: PRN_SetFontType
//描    述: 设置打印字体大小(目前支持:12x12, 16x16, 24x24)
//全局变量: 无
//输入参数: font_type:必须是下列值之一
//			PRN_FONT12
//			PRN_FONT16
//			PRN_FONT24
//输出参数: 无
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 
void PRN_SetFontType( int font_type );



//函 数 名: PRN_GetDeviceStatus
//描    述: 查询打印机当前状态
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 
//			PRN_OUT_OF_PAPER:	缺纸
//			PRN_ABORT_TEMP:		温度过高
//			0:					打印机正常
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 
int PRN_GetDeviceStatus(void);


//函 数 名: PRN_SetLineSpace
//描    述: 设置行间距
//全局变量: 无
//输入参数: dot_lines:两行字符之间的点行数
//输出参数: 无
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 
void PRN_SetLineSpace(unsigned short dot_lines);


//函 数 名: PRN_WriteData2Printer
//描    述: 调用该函数将启动打印机打印缓存中的数据.
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 
//			PRN_FAILURE(-1)			:打印失败
//			PRN_OUT_OF_PAPER(-2)	:缺纸	
//			PRN_ABORT_TEMP(-3)		:温度过高
//			其它值:					:成功打印的数据长度	
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 
//			不管打印是否成功,打印缓存中的数据均会被清空.
int PRN_WriteData2Printer(void);




//函 数 名: PRN_FillData 
//功    能: 往打印缓存中填充数据
//输入参数: 
//			Data	:指向要打印的数据的指针
//			DataLen	:数据长度
//返 回 值:
//			PRN_FAILURE(-1)			:打印失败
//			PRN_OUT_OF_PAPER(-2)	:缺纸	
//			PRN_ABORT_TEMP(-3)		:温度过高
//			0						:成功
//说    明: 填充过程中若发现打印缓冲区满将自动打印		
int PRN_FillData( unsigned char *Data, unsigned short DataLen );





//函 数 名: PRN_PrnBlankDotLines
//描    述: 往打印缓存中填充空白点行
//全局变量: 无
//输入参数: dot_lines:要打印的点行数
//输出参数: 无
//返 回 值: 
//			PRN_FAILURE(-1)			:打印失败
//			PRN_OUT_OF_PAPER(-2)	:缺纸	
//			PRN_ABORT_TEMP(-3)		:温度过高
//			0						:成功
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 1.填充过程中若发现打印缓冲区满将自动打印,之后会继续填充数据		
//			2.若打印过程出错,将中断填充过程并返回非0值
int PRN_PrnBlankDotLines( unsigned short dot_lines );



//函 数 名: PRN_Print
//描    述: 将str指定的字符串填入打印缓冲区
//全局变量: 无
//输入参数: str:要打印的字符串
//输出参数: 无
//返 回 值: 
//			PRN_FAILURE(-1)			:打印失败
//			PRN_OUT_OF_PAPER(-2)	:缺纸	
//			PRN_ABORT_TEMP(-3)		:温度过高
//			0						:成功
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 
int PRN_Print( unsigned char *str );






//函 数 名: PRN_Image
//描    述: 实时打印位图(2位数色)
//全局变量: 无
//输入参数: 
//			image_data		:位图数据
//			image_width		:位图宽度(以像素为单位)
//			image_width		:位图高度(以像素为单位)
//输出参数: 无
//返 回 值: 
//			PRN_FAILURE(-1)			:打印失败
//			PRN_OUT_OF_PAPER(-2)	:缺纸	
//			PRN_ABORT_TEMP(-3)		:温度过高
//			-4						:分配内存失败
//			0						:成功
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 1.位图长宽必须是8的倍数
//			2.位图必须是黑白两色,位图数据必须是bit位表示一个像素.
int PRN_Image(unsigned char *image_data, unsigned short image_width, unsigned short image_height );


#endif				/* PRN_SUPPORT_H */
