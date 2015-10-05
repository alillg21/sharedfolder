/***********************************************************************************************************
 *
 * @FILENAME		: tool-support.h
 *
 * @AUTHOR  		: zjwu
 *
 * @DATE	  		: 2009-9-1
 *
 * @DESCRIPTION		: 
 *
 * @COPYRIGHT		: 2009-2012 ShenZhen KAIFA Technology Co.,Ltd.
 *
 ***********************************************************************************************************/
#ifndef _TOOL_SUPPORT_H_
#define _TOOL_SUPPORT_H_

#define RADIX10		0		//10进制
#define RADIX16		1		//16进制

#define MAX_FMT_AMT_LEN		80	//format_amt函数能够格式化的最大金额数据长度


//函 数 名: BcdToAsc_Ex
//描    述:	将BCD格式数据转换成ASC码格式数据.
//全局变量: 无
//输入参数: 
//			bcd_buf			: 指向BCD格式数据的指针.
//			asc_buf_len	 	: BCD格式数据转换成ASC后的长度.
//输出参数: asc_buf			: 转换后,存放ASC数据的字符串指针.
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 
//			1.由asc_buf_len的长度决定要转换的BCD数据的长度.当该值为偶数时, 
//			  要转换的BCD数据的长度为asc_buf_len/2, 当该值为奇数时,要转换的
//			  BCD数据的长度为(asc_buf_len+1)/2, 转换完成时, 转换完成后ASC字
//			  符串的最左边的第一个字节被抛弃.
//			2.转换成功后asc_buf是一个长度为asc_buf_len的以'\0'结尾的字符串.
//			  请给asc_buf分配足够的空间大小,以免发生溢出.
void BcdToAsc_Ex(unsigned char *bcd_buf, int asc_buf_len, char *asc_buf);


//函 数 名: BcdToAsc
//描    述:	将BCD格式数据转换成ASC码格式数据.同BcdToAsc_Ex的差别见备注
//全局变量: 无
//输入参数: 
//			bcd_buf			: 指向BCD格式数据的指针.
//			asc_buf_len	 	: BCD格式数据转换成ASC后的长度.
//输出参数: asc_buf			: 转换后,存放ASC数据的字符串指针.
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 
//			1.同BcdToAsc_Ex的差别是,当asc_buf_len为奇数时, 转换后的ASC码字符
//			  的最右边一个字符被抛弃.
void BcdToAsc(unsigned char *bcd_buf, int asc_buf_len, char *asc_buf);


//函 数 名: AscToBcd_Ex
//描    述:	将Asc格式数据转换成Bcd格式数据
//全局变量: 无
//输入参数: 
//			asc_buf			: 指向ASC格式数据的指针.
//			asc_buf_len	 	: asc_buf的长度.
//输出参数: bcd_buf			: 转换后,存放BCD数据的指针.
//返 回 值: BCD格式数据的长度
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 
//			1.asc_buf_len为奇数时, asc_buf前补'0'后再压缩.
int AscToBcd_Ex(char *asc_buf, int asc_buf_len, unsigned char *bcd_buf);

//函 数 名: AscToBcd
//描    述:	将Asc格式数据转换成Bcd格式数据
//全局变量: 无
//输入参数: 
//			asc_buf			: 指向ASC格式数据的指针.
//			asc_buf_len	 	: asc_buf的长度.
//输出参数: bcd_buf			: 转换后,存放BCD数据的指针.
//返 回 值: BCD格式数据的长度
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 
//			同AscToBcd_Ex的差别:该函数将asc_buf后补'0'后再压缩.
int AscToBcd(char *asc_buf, int asc_buf_len, unsigned char *bcd_buf);


//函 数 名: itobcd
//描    述:	将一个无符号整数转换成BCD格式的字符串.采取前补'0'的方式.
//			当参数radix=0时,该整数采用10进制表现后再转换,当radix=1
//			时,该整数采用16进制表现后再转换.如val=12345(10进制数)时, 
//			转换后bcd_buf为"\x01\x23\x45", radix=1时, 转换后bcd_buf
//			为:"x30\x39"
//全局变量: 无
//输入参数: 
//			val		: 要转换成BCD格式数据的无符号整数.
//			radix	: 整数的表现形式(0或者1).
//输出参数: bcd_buf			: 转换后,存放BCD数据的指针.
//返 回 值: BCD格式数据的长度
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 如果radix!=0, 并且radix!=1,则默认radix=0
int itobcd(unsigned int val, unsigned char *bcd_buf, int radix);


//函 数 名: format_amt
//描    述:	格式化金额数据,如"0012345"格式化成"123.45".
//			"12"格式化成"0.12".
//全局变量: 无
//输入参数: 
//			o_amt	: 要格式化的原字符串.
//输出参数: d_amt	: 格式化后的输出字符串.
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 
//			1.原金额数据长度不能超过MAX_FMT_AMT_LEN(80)位数字,
//			  即字符串o_amt的长度不能大于MAX_FMT_AMT_LEN(80).
//			2.o_amt必须是以'\0'结尾的字符串,转换后d_amt也是以
//			  '\0'结尾的字符串.o_amt和d_amt可以为同一buf.
//			3.只有d_amt的缓冲区长度比o_amt的缓冲区长度大3时才能
//			  保证任何情况下调用该函数不会发生溢出。
void format_amt(char *o_amt, char *d_amt);

//函 数 名: rev_format_amt
//描    述:	反格式化金额数据,format_amt函数的逆过程.如"123.45"格式化成"12345".
//			"0.12"格式化成"12".
//全局变量: 无
//输入参数: 
//			o_amt	: 要格式化的原字符串.
//输出参数: d_amt	: 格式化后的输出字符串.
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 
//			1.原金额数据长度不能超过MAX_FMT_AMT_LEN(80)位数字,
//			  即字符串o_amt的长度不能大于MAX_FMT_AMT_LEN(80).
//			2.o_amt必须是以'\0'结尾的字符串,转换后d_amt也是以
//			  '\0'结尾的字符串.o_amt和d_amt可以为同一buf.
//			3.只有d_amt的缓冲区长度比o_amt的缓冲区长度小不超过1时才能
//			  保证任何情况下调用该函数不会发生溢出。
void rev_format_amt(char *o_amt, char *d_amt);


//函 数 名: digital_str_add
//描    述:	对两组数字字符串进行加法运算,得出两组数字的"和"字符串
//			如:"98762"+"009213"="107975".
//全局变量: 无
//输入参数: 
//			str1	: 加数字符串之一.
//			str2	: 加数字符串之二.
//输出参数: d_amt	: "和"字符串
//返 回 值: 成功返回0, 分配字符串的缓存失败返回-1
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 
//			1.str1和str2以右对齐的方式相加.
//			2.str1中和str2中含非数字字符时,均被当做字符'0'处理.
//			3.如果字符串为空, 则字符串会被当做"0".
//			4.两个全零的字符串相加时得"0"
char digital_str_add(char *str1, char *str2, char *d_str);


//函 数 名: digital_str_subtract
//描    述:	对两组数字字符串进行减法运算,得出两组数字的"差"字符串
//			如:"98762"-"00009213"="89549".
//全局变量: 无
//输入参数: 
//			str1	: 被减数字符串.
//			str2	: 减数字符串.
//输出参数: d_amt	: "差"字符串
//返 回 值: 成功返回0, 分配字符串的缓存失败返回-1, 被减数小于减数错误返回1
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 
//			1.str1和str2以右对齐的方式相减.
//			2.str1中和str2中含非数字字符时,均被当做字符'0'处理.
//			3.如果字符串为空, 则字符串会被当做"0".
//			4.两个全零的字符串相加时得"0"
char digital_str_subtract(char *minuend, char *subtrahend, char *res_str);








#endif





