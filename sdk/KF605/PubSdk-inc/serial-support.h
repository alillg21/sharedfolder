/***********************************************************************************************************
 *
 * @FILENAME		: serial-support.h
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
#ifndef _SERIAL_SUPPORT_H_
#define _SERIAL_SUPPORT_H_




//下列宏定义可以引用,但是请勿修改
#define COM0	0
#define COM1	1
#define COM2	2
#define COM3	3
#define COM4	4
#define COM5	5
#define COM6	6

#define MAX_COM_NO	COM6

#define PARA_SPEED_ERR 				-2
#define PARA_PORT_NO_ERR 			-3
#define OPEN_SERIAL_PORT_ERR		-1
//-----------------------END------------------------------



//函 数 名: SCOM_Open
//描    述: 以Speed指定的速度打开ComNo指定的串口号
//全局变量: 无
//输入参数: 
//			ComNo:	串口号, 其定义的范围为serila-support.h文件中定义的COM0~MAX_COM_NO, 超出范围将返回PARA_PORT_NO_ERR
//			Speed:	整形值, 必须是下列数值之一:
//					230400, 115200, 57600, 38400, 19200, 9600, 4800, 2400, 1800, 1200, 600, 300, 200
//					Speed不是上述之一是返回PARA_SPEED_ERR错误	
//			Vtime:	读串口数据超时时间, 以0.1秒为单位.
//输出参数: 无
//返 回 值: 
//			PARA_PORT_NO_ERR:输入参数中, 串口号超出范围时返回.
//			PARA_SPEED_ERR:	 输入参数中, 速度参数错误时返回.  
//			OPEN_SERIAL_PORT_ERR:打开串口失败
//			0:打开指定的串口成功.
//作    者: 吴 志 坚
//创建日期: 2009/9/01
//修 改 者: 
//修改日期: 
//备    注: 该函数以非标准输入模式打开串口.属性设置如下:
//			N81, 无流控
//			忽略奇偶校验
//			Raw 模式输出
//			无阻塞
int SCOM_Open(unsigned int ComNo, unsigned int Speed, unsigned int Vtime);


//函 数 名: SCOM_Read
//描    述: 读串口数据,将从指定的串口中读出rdlen长度的数据到buffer中,实际读取到的数据以返回值为准.
//全局变量: 无
//输入参数: 
//			ComNo:串口号, 必须是serila-support.h文件中指定的串口号之一
//			rdlen:期望读取的数据长度
//输出参数: buffer
//返 回 值: 如果成功,将返回实际读取到的数据长度,如果失败,返回-1
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 
int SCOM_Read( unsigned int ComNo, void *buffer, unsigned int rdlen );


//函 数 名: SCOM_Write
//描    述: 向ComNo指定的串口写入buffer中的数据, 写入的数据长度为wrlen
//全局变量: 无
//输入参数: 
//			ComNo:串口号,必须是serila-support.h文件中定义的值
//			buffer要写入的数据
//			要写入的数据长度
//输出参数: 无
//返 回 值: 如果成功,返回实际写入的数据长度.失败返回-1
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 
int SCOM_Write( unsigned int ComNo, void *buffer, unsigned int wrlen );



//函 数 名: SCOM_Close
//描    述: 关闭ComNo指定的串口
//全局变量: 无
//输入参数: ComNo:串口号,必须是serila-support.h文件中定义的串口(COM0~MAX_COM_NO)之一
//输出参数: 无
//返 回 值: 关闭成分返回0, 失败返回-1
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 
int SCOM_Close( unsigned int ComNo );


//函 数 名: SCOM_Clear
//描    述: 清除串口缓冲
//全局变量: 无
//输入参数: ComNo:串口号,必须是serila-support.h文件中定义的值
//输出参数: 无
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 
void SCOM_Clear(unsigned int ComNo );

#endif





