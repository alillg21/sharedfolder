/***********************************************************************************************************
 *
 * @FILENAME		: des-support.h
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
#ifndef _DES_SUPPORT_H_
#define _DES_SUPPORT_H_

#define DECRYPT_MODE	0		//解密模式
#define ENCRYPT_MODE	1		//加密模式


//函 数 名: DES_Encrypt
//描    述:	根据参数type,用keybuf加密或者解密indatabuf,结果存放到参数outdatabuf中.
//全局变量: 无
//输入参数: 
//			indatabuf: unsigned char 型字符串指针, 指明需要被加密或者解密的数据, 长度为8byte
//			keybuf	 : unsigned char 型字符串指针, 加密或者解密时用到的key, 长度为8个字节.
//			mode	 : 0-解密, 1-加密
//输出参数: outdatabuf:unsigned char 型字符串指针, 加密或者解密的结果,长度为8byte
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 
void DES_Encrypt(unsigned char *indatabuf, unsigned char *keybuf, unsigned char *outdatabuf, char mode);

#endif





