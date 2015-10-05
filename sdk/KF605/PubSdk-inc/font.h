//font.h
#ifndef _FONT_H_
#define _FONT_H_








//函 数 名: get_gb16font_mem
//描    述: 返回16x16汉字库映射在内存中的地址
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 指向unsigned char型的指针.
//作    者: 吴 志 坚
//创建日期: 2009/8/25
//修 改 者: 
//修改日期: 
//备    注: 由于返回的是指针,请勿改变该指针的值.
unsigned char *get_gb16font_mem(void);

//函 数 名: get_asc16font_mem
//描    述: 返回16x8ASC字库映射在内存中的地址
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 指向unsigned char型的指针.
//作    者: 吴 志 坚
//创建日期: 2009/8/25
//修 改 者: 
//修改日期: 
//备    注: 
unsigned char *get_asc16font_mem(void);



//函 数 名: get_asc12font_mem
//描    述: 返回12x6ASC字库映射在内存中的地址
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 指向unsigned char型的指针.
//作    者: 吴 志 坚
//创建日期: 2009/8/25
//修 改 者: 
//修改日期: 
//备    注: 
unsigned char *get_asc12font_mem(void);


//函 数 名: get_gb12font_mem
//描    述: 返回12x12汉字库映射在内存中的地址
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 指向unsigned char型的指针.
//作    者: 吴 志 坚
//创建日期: 2009/8/25
//修 改 者: 
//修改日期: 
//备    注: 由于返回的是指针,请勿改变该指针的值.
unsigned char *get_gb12font_mem(void);


//函 数 名: get_asc24font_mem
//描    述: 返回24x12ASC字库映射在内存中的地址
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 指向unsigned char型的指针.
//作    者: 吴 志 坚
//创建日期: 2009/8/25
//修 改 者: 
//修改日期: 
//备    注: 
unsigned char *get_asc24font_mem(void);

//函 数 名: get_gb24font_mem
//描    述: 返回24x24汉字库映射在内存中的地址
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 指向unsigned char型的指针.
//作    者: 吴 志 坚
//创建日期: 2009/8/25
//修 改 者: 
//修改日期: 
//备    注: 由于返回的是指针,请勿改变该指针的值.
unsigned char *get_gb24font_mem(void);

//函 数 名: str2image
//描    述: 将str中的字符从16x16的点阵字库中取出点阵信息放入buffer中.
//全局变量: 无
//输入参数: 
//			str:要转换的字符串
//			len:字符串的长度
//输出参数: 
//			buffer:第一个字节为字符串长度, 第二字恒为2,其后字符串str中的每个字符的点阵数据.
//返 回 值: 无
//作    者: 
//创建日期: 2009/8/25
//修 改 者: 吴志坚
//修改日期: 
//备    注: 
//			1.16x16点阵的每个汉字用32个byte表示.16x8的Asc每个字符用16个byte表示.
//			2.对点阵信息在buffer中存放的理解:
//			  假设str[3]='A', 字符'A'在字库中的点阵数据用字节表示为B[0], B[1]...B[15], 
//			  B[0]存放在buffer中的位置为:buffer[2 + 3 + 0x16]
//			  B[1]存放在buffer中的位置为:buffer[2 + 3 + 1x16]
//			  ......
//			  B[15]存放在buffer中的位置为:buffer[2 + 3 + 15x16]
void str2image(unsigned char *str, int len, unsigned char *buffer);


//函 数 名: font_init
//描    述: 初始化字库.
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/8/25
//修 改 者: 
//修改日期: 
//备    注: 
//			1.目前用到的字库有:16x16汉字库, 16x8ASC字库, 12x12汉字库, 12x6Asc字库, 24x24汉字库, 24x12ASC字库
//			2.字库打开后被映射到内存中, 通过下列函数返回字库地址
//				get_gb16font_mem(void)	返回16x16汉字库地址
//				get_asc16font_mem(void)	返回16x8ASC字库地址
//				get_asc12font_mem(void) 返回12X6ASC字库地址
//				get_gb12font_mem(void)	返回12x12汉字库地址
//				get_asc24font_mem(void)	返回24x12ASC字库地址
//				get_gb24font_mem(void)	返回24X24汉字库地址		
//			3.在使用字库前必须先调用该函数
void font_init(void);



//函 数 名: lcdshow_font12x12
//描    述: 显示12x12点阵的字符串
//全局变量: 无
//输入参数: 
//				str:要显示的字符串
//				row_by6:以6个pixel为单位的字符行数,如row_by6=3,实际显示的位置是第18像素行
//				col_by6:以6个pixel为单位的字符列数,如col_by6=3,实际显示的位置是第18像素列
//输出参数: 无
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/8/25
//修 改 者: 
//修改日期: 
//备    注: 
void lcdshow_font12x12(unsigned short row_by6, unsigned short col_by6, unsigned char *str );



//函 数 名: lcdshow_5x8font
//描    述: 显示5x7的asc字符串,字符列之间没有间隙,行之间有一个像素点的间隔.
//全局变量: 无
//输入参数: 
//			  row_pixel:第一个要显示的字符的起点行(以像素为单位)
//			  col_pixel:第一个要显示的字符的起点列(以像素为单位)
//			  str:		要显示的字符串
//	输出参数: 无
//	返 回 值: 无
//	作    者: 吴 志 坚
//	创建日期: 2009/8/05
//	修 改 者: 
//	修改日期: 
//	备    注: 
void lcdshow_5x8font( unsigned short row_pixel, unsigned short col_pixel, char *str );


//函 数 名: lcdshow_6x8font
//描    述: 显示5x7的asc字符串,字符列和行之间均有一个像素的间隔
//全局变量: 无
//输入参数: 
//		  	row_pixel:第一个要显示的字符的起点行(以像素为单位)
//		 	col_pixel:第一个要显示的字符的起点列(以像素为单位)
//		  	str:		要显示的字符串
//输出参数: 无
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/8/05
//修 改 者: 
//修改日期: 
//备    注: 
void lcdshow_6x8font( unsigned short row_pixel, unsigned short col_pixel, char *str );


#endif
