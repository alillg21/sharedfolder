/***********************************************************************************************************
 *
 * @FILENAME		: modem-support.h
 *
 * @AUTHOR  		: zjwu
 *
 * @DATE	  		: 2010-4-8
 *
 * @DESCRIPTION		: 
 *
 * @COPYRIGHT		: 2009-2012 ShenZhen KAIFA Technology Co.,Ltd.
 *
 ***********************************************************************************************************/
#ifndef _MODEM_SUPPORT_H_
#define _MODEM_SUPPORT_H_

#define MDM_STATUS_NOTINIT_POWEROFF_ON		0x00 //modem断电后上电//zsp add
#define MDM_STATUS_NOT_INIT				0x11		//modem未初始化
#define MDM_STATUS_IDLE						0x12		//modem空闲
#define MDM_STATUS_DIALING				0x13		//modem拨号中
#define MDM_STATUS_ON_LINE				0x16		//modem在线连接状态
#define MDM_STATUS_ON_HOOKING			0x17		//modem正在挂机
#define MDM_STATUS_INVALID				0x18		//modem失效状态


#define MDM_MSG_OPE_SUCCESS				0x00		//modem操作成功
#define	MDM_MSG_TIMEOUT						0x01		//modem操作超时
#define MDM_MSG_DIAL_NUM_IS_EMPTY	0x02		//拨号号码为空
#define MDM_MSG_NO_LINE						0x03		//未检测到电话线
#define MDM_MSG_LINE_BE_USING			0x04		//线路使用中
#define MDM_MSG_PARALLEL_OFFHOOK	0x05		//并机摘机
#define MDM_MSG_REVERSAL					0x06		//远端挂机
#define MDM_MSG_NO_DIALTONE				0x07		//没有检测到拨号音
#define	MDM_MSG_BUSYTONE					0x08		//忙音
#define MDM_MSG_NO_ANSWERTONE			0x09		//无应答音
#define	MDM_MSG_LOST_CARRIER			0x0A		//载波丢失
#define MDM_MSG_DIAL_FAIL					0x0B		//一般拨号出错
#define	MDM_MSG_RX_READY					0x10		//modem可读
#define MDM_MSG_TX_READY					0x20		//modme可写
#define MDM_MSG_RTX_READY					0x30		//modem可读写
#define MDM_MSG_COMM_ERR					0x40		//通讯数据出错
#define MDM_HD_ERR								0xEE		//hd通讯错
#define MDM_CANNOT_DEAL_THIS_CMD	0xDD		//modem不能处理该指令
#define MDM_TRANSFER_TIMEOUT			0xFE		//modem通讯超时
#define MDM_OPERATOR_FAILURE			-1			//操作modem失败	


//函 数 名: MDM_Open
//描    述: 打开modem设备
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 
//			0			:成功
//			0xEE		:hd通讯出错
//			-1			:打开modem失败
//作    者: 吴 志 坚
//创建日期: 2010/4/08
//修 改 者: 吴志坚
//修改日期: 
//备    注: 
int MDM_OpenDevice(void);


//函 数 名: MDM_Nor_Dial
//描    述: 实现modem同步拨号,指非预拨号模式
//全局变量: 无
//输入参数: 
//			tel_no	: 电话号码(以0结尾的字符串)
//输出参数: 无
//返 回 值: 
//			0x01 	发送缓冲区已被占用。
//			0x02 	旁置电话机占用。
//			0x03 	并线电话占用或无拨号音。
//			0x04   	载波已丢失
//			0x05   	无应答音
//			0x06 	拨号失败（其他原因）。
//			0x07 	未设电话号码。
//			0x08：	接收缓冲区非空
//			0x09：	发送缓冲区已被占用和接收缓冲区非空
//			0x0a：	正在拨号中
//			0x0b：	已挂机/空闲
//			0x0d：	被叫电话忙
//			0x13:	modem拨号连接成功
//			0xfd: 	CLEAR键按下(Modem将终止拨号操作)。
//			
//			其他值	保留（不对外公开）。
//作    者: 吴 志 坚
//创建日期: 2010/4/08
//修 改 者: 
//修改日期: 
//备    注: 
int MDM_Nor_Dial(char *tel_no );


//函 数 名: MDM_Pre_Dial
//描    述: 预拨号函数,执行该函数会立即返回,最终拨号的结果需要通过MDM_GetModemStatus取得.
//全局变量: 无
//输入参数: tel_no:	电话号码
//输出参数: 无
//返 回 值: 
//			0x00	//Modem操作完成
//			0xEE	//HD通讯出错
//			0xDD	//modem无法响应该请求
//			0xF9	//建立modem线程失败
//			-1		//操作modem失败
//作    者: 吴 志 坚
//创建日期: 2010/4/27
//修 改 者: 
//修改日期: 
//备    注: 
int MDM_Pre_Dial( char *tel_no );


//函 数 名: MDM_GetModemStatus
//描    述: 取当前modem状态
//全局变量: 无
//输入参数: 无
//输出参数: modem_info,其含义如下:
//			0x00 	//操作成功
//			0x01	//超时
//			0x02 	//未设电话号码。
//			0x03	//电话线路未连接好
//			0x04	//电话线路被占用
//			0x05	//并线电话终端摘机中
//			0x06	//远端挂机断开
//			0x07 	//并线电话占用或无拨号音
//			0x08	//被叫电话忙
//		   	0x09   	//无应答音
//			0x0A	//载波已丢失
//			0x0B 	//拨号失败（其他原因）。
//	
//			0x10	//接收缓冲区非空,等待host读操作,读准备好
//			0x20 	//发送缓冲区已空,等待host写操作,写准备好
//			0x30	//发送缓冲区已空和接收缓冲区非空, 读写准备好
//			0x40	//通讯中数据传输出错
//返    回：	
//			0x11		modem未初始化
//			0x12		modem空闲状态
//			0x13		modem拨号中
//			0x16		modem在线
//			0x17		modem挂机中
//			0x18		modem失效
//			0xEE		hd通讯出错
//			-1			操作modem失败
//作    者: 吴 志 坚
//创建日期: 2010/4/10
//修 改 者: 
//修改日期: 
//备    注: 
int MDM_GetModemStatus(int *modem_info );



//函 数 名: MDM_Read
//描    述: 接收modem返回数据
//全局变量: 无
//输入参数: timeout	:通讯超时时间(sec)
//输出参数: 
//			data:存放接收数据buf的指针
//			length:存放接收到的数据长度的指针
//返 回 值: 
//			0x00										//成功
//			MDM_MSG_LOST_CARRIER			0x0A		//载波丢失
//			MDM_MSG_COMM_ERR			0x40		//通讯出错
//			MDM_TRANSFER_TIMEOUT			0xFE		//通讯超时
//			MDM_OPERATOR_FAILURE			-1			//操作modem失败
//作    者: 吴 志 坚
//创建日期: 2010/4/10
//修 改 者: 
//修改日期: 
//备    注: 该函数为阻塞函数
int MDM_Read(unsigned char * data, int *length, int timeout );



//函 数 名: MDM_Write
//描    述:	通过modem发送数据
//全局变量: 无
//输入参数: 
//			data	:存放要发送数据buf的指针
//			length	:要发送的数据的长度
//输出参数: 
//返 回 值: 
//			0x00										//成功
//			MDM_MSG_LOST_CARRIER			0x0A		//载波丢失
//			MDM_MSG_COMM_ERR				0x40		//通讯出错
//			MDM_HD_ERR					0xEE		//hd通讯出错
//			MDM_OPERATOR_FAILURE			-1			//操作modem失败
//作    者: 吴 志 坚
//创建日期: 2010/4/10
//修 改 者: 
//修改日期: 
//备    注: 
int MDM_Write(unsigned char *data, int length );



//函 数 名: MDM_Hook
//描    述: 取消modem拨号
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 
//			0x00	:成功接收到modem挂机指令
//			-1		:操作modem失败
//作    者: 吴 志 坚
//创建日期: 2010/4/10
//修 改 者: 
//修改日期: 
//备    注: 挂机结果需要通过MDM_GetModemStatus函数来查询
int MDM_Hook(void);


//函 数 名: MDM_CloseDevice
//描    述: 关闭modem设备
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 
//			 0		:成功
//			-1		:关闭modem失败	
//作    者: 吴 志 坚
//创建日期: 2010/4/10
//修 改 者: 
//修改日期: 
//备    注: 
int MDM_CloseDevice(void);



//函 数 名: MDM_Reset
//描    述: modem复位
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 			0		-复位成功
//				-1		-复位失败
//作    者: 吴 志 坚
//创建日期: 2010/5/27
//修 改 者: 
//修改日期: 
//备    注: 
int MDM_Reset(void);


#endif




