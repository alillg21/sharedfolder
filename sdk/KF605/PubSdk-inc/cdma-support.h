#ifndef _CDMA_SUPPORT_H_
#define	_CDMA_SUPPORT_H_

#define ZTC_CDMA_COM	1
#define CDMA_CR	0x0D
#define CDMA_LF	0x0A
#define CDMA_SCR "\x0D"
#define CDMA_CRLF "\x0D\x0A"
#define CDMA_SUCCESS					0
#define CDMA_RS_TIMEOUT 				0xFF	//接收设备返回超时
#define CDMA_WRITE_ERR					0xFE	//写串口出错
#define CDMA_READ_ERR					0xFD	//读串口出错
#define CDMA_PARA_ERR					0xFC	//输入的参数错误
#define CDMA_EXECUTE_ERR				0xFB	//执行命令失败
#define CDMA_PARSERES_ERR				0xFA  	//解析应答错误
#define CDMA_OPEN_SERIALPORT_ERR		0xF9	//打开CDMA串口出错

#define CDMA_DEFAULT_TIMEOUT 			4000*1000		//2 sec
#define CDMA_SENDDATA_TIMEOUT			1000*1000*20 	//20sec
#define CDMA_CREG_TIMEOUT  				2000*1000		//2 sec

#define CDMA_CONNECT_TIMEOUT			1000*1000*60 	//60SEC

#define CDMA_PWRON_GET_RS_TIMEOUT_TIME 	10*1000*1000 	//10 SEC


#define CDMA_MAX_SEND_LEN	1024

//发送的CDMA模块的最大指令长度(包括结尾回车符)
//请勿发送长度超过该值的指令。
#define CDMA_MAX_CMD_LEN 999

//cdma指令返回的应答长度最大值, 给CDMA的API函数传递应答参数的buffer应该大于该值.
//否则有可能产生越界的危险.
#define CDMA_MAX_RS_LEN	199  

#define CDMA_CONN_ID1		1		//socket connect ID
#define CDMA_CONN_ID2		2
#define CDMA_CONN_ID3		3
#define CDMA_MAX_CONN_ID	3		//最大socket connect数目

#define PPP_OPENED		2
#define PPP_OPENING		1
#define PPP_CLOSED		0

#define SK_CONNECTED	2
#define SK_CONNECTING   1
#define SK_CLOSED	    0


//函 数 名:CDMA_CloseSCOM
//功    能:关闭与CDMA模块通讯的串口
//输入参数:无
//输出参数:无
//返 回 值:无
void CDMA_CloseSCOM(void);


//函 数 名:CDMA_OpenSCOM
//功    能:打开与CDMA模块通讯的串口
//输入参数:无
//输出参数:无
//返 回 值:	
//			0:							打开串口成功
//			CDMA_OPEN_SERIALPORT_ERR:  	打开串口失败
unsigned short CDMA_OpenSCOM(void);



//函 数 名:CDMA_SendAtCmd
//功    能:发送命令给CDMA模块(中兴)
//输入参数:
//			cmd:要发送给模块的命令(带<CR>的字符串)
//			timeout:该命令的响应超时时间
//输出参数:	response:模块返回的应答
//返 回 值:	
//			CDMA_SUCCESS:	命令发送成功
//			CDMA_RS_TIMEOUT:接收应答超时
//			CDMA_WRITE_ERR:	写串口出错
//补充说明:该函数正确使用的前提是打开命令回显模式,即ATE=1;
unsigned short CDMA_SendAtCmd(char *cmd, char *respone, long timeout );

//函 数 名:CDMA_SetDialNum
//功    能:设定数据业务号码
//输入参数:dial_no:数据业务号码
//输出参数:respone:设备返回的应答
//返 回 值:
//			CDMA_SUCCESS:		执行成功
//			CDMA_RS_TIMEOUT:	接收应答超时
//			CDMA_WRITE_ERR:		写串口出错
//			CDMA_EXECUTE_ERR:	处理失败,原因参见response
//			CDMA_PARA_ERR:		输入参数错误
unsigned short CDMA_SetDialNum( char *dial_no, char *respone );



//函 数 名:	CDMA_SetIDPWD
//功    能:	设定数据业务用户名及密码
//输入参数:
//			id:		用户名
//			pwd:	用户密码
//输出参数:	respone:设备返回的应答
//返 回 值:
//			CDMA_SUCCESS:		执行成功
//			CDMA_RS_TIMEOUT:	接收应答超时
//			CDMA_WRITE_ERR:		写串口出错
//			CDMA_EXECUTE_ERR:	处理失败,原因参见response
//			CDMA_PARA_ERR:		输入参数错误
unsigned short CDMA_SetIDPWD( char *id, char *pwd, char *respone );

//函 数 名:	CDMA_PPPOpen
//功    能:	对模块进行拨号连接
//输入参数:	无
//输出参数:	respone:设备返回的应答
//返 回 值:
//			CDMA_SUCCESS:		执行成功
//			CDMA_RS_TIMEOUT:	接收应答超时
//			CDMA_WRITE_ERR:		写串口出错
//			CDMA_EXECUTE_ERR:	处理失败,原因参见response
//			CDMA_PARA_ERR:		输入参数错误
unsigned short CDMA_PPPOpen( char *respone );

//函 数 名:	CDMA_PPPClose
//功    能:	断开拨号连接
//输入参数:	无
//输出参数:	respone:设备返回的应答
//返 回 值:
//			CDMA_SUCCESS:		执行成功
//			CDMA_RS_TIMEOUT:	接收应答超时
//			CDMA_WRITE_ERR:		写串口出错
//			CDMA_EXECUTE_ERR:	处理失败,原因参见response
//			CDMA_PARA_ERR:		输入参数错误
unsigned short CDMA_PPPClose( char *respone );


//函 数 名:	CDMA_PPPStatus
//功    能:	查询拨号连接状态
//输入参数:	无
//输出参数:	respone:设备返回的应答
//			status:	
//					0-ppp closed
//					1-ppp opening
//					2-ppp opened
//返 回 值:
//			CDMA_SUCCESS:		执行成功
//			CDMA_RS_TIMEOUT:	接收应答超时
//			CDMA_WRITE_ERR:		写串口出错
//			CDMA_EXECUTE_ERR:	处理失败,原因参见response
//			CDMA_PARA_ERR:		输入参数错误
unsigned short CDMA_PPPStatus( char *respone, unsigned short *status );

//函 数 名:	CDMA_Connect
//功    能:	建立TCP 连接用于以TCP 方式发送数据
//输入参数:		
//			socket_num:	进行连接的socket通道号,取值范围:0,1,2
//			ipaddr:		连接的服务器地址
//			port:		连接的服务器端口
//输出参数:	respone:	设备返回的应答
//返 回 值:
//			CDMA_SUCCESS:		执行成功
//			CDMA_RS_TIMEOUT:	接收应答超时
//			CDMA_WRITE_ERR:		写串口出错
//			CDMA_EXECUTE_ERR:	处理失败,原因参见response
//			CDMA_PARA_ERR:		输入参数错误
unsigned short CDMA_Connect( unsigned short socket_num, char *ipaddr, unsigned long port, char *respone );

//函 数 名:	CDMA_IPClose
//功    能:	断开拨号连接
//输入参数:	socket_no:	TCP socket通道, 取值范围:0,1,2
//输出参数:	respone:设备返回的应答
//返 回 值:
//			CDMA_SUCCESS:		执行成功
//			CDMA_RS_TIMEOUT:	接收应答超时
//			CDMA_WRITE_ERR:		写串口出错
//			CDMA_EXECUTE_ERR:	处理失败,原因参见response
//			CDMA_PARA_ERR:		输入参数错误
unsigned short CDMA_IPClose( unsigned short socket_no, char *respone );

//函 数 名:	CDMA_IPStatus
//功    能:	查询TCP SOCKET 是否连接成功
//输入参数:	socket_num:	要查询的socket通道
//输出参数:	respone:设备返回的应答
//			status:	
//					0-连接关闭 
//					1-正在连接
//					2-建立连接
//返 回 值:
//			CDMA_SUCCESS:		执行成功
//			CDMA_RS_TIMEOUT:	接收应答超时
//			CDMA_WRITE_ERR:		写串口出错
//			CDMA_EXECUTE_ERR:	处理失败,原因参见response
//			CDMA_PARA_ERR:		输入参数错误
unsigned short CDMA_IPStatus( unsigned short socket_num, char *respone, unsigned short *status );


//函 数 名:	CDMA_JoinDormancyTime
//功    能:	设置进入休眠的时间
//输入参数:	time:PPP连接成功后进入休眠模式的时间(sec)
//			time=0,从不进入休眠
//输出参数:	respone:设备返回的应答
//返 回 值:
//			CDMA_SUCCESS:		执行成功
//			CDMA_RS_TIMEOUT:	接收应答超时
//			CDMA_WRITE_ERR:		写串口出错
//			CDMA_EXECUTE_ERR:	处理失败,原因参见response
//			CDMA_PARA_ERR:		输入参数错误
//说   明:
//			进入休眠模式有三种途径。Zdormant可以立即进入休眠模式。CTA设置一定时间后进
//			入休眠模式。基站也有控制，达到一定时间，基站释放业务信道。
//			CTA 的设置必须在连接PPP 之前设置。连接PPP 之后再设置，只有断开本次PPP 连接，
//			重新连接后才有效
unsigned short CDMA_JoinDormancyTime( unsigned short time, char *respone );


//函 数 名:	CDMA_TcpSendData
//功    能:	在TCP通道上发送数据
//输入参数:	
//			socket_no:	socket通道
//			data_len:	发送的数据长度
//			data:		发送的数据
//输出参数:	respone:	设备返回的应答
//			RSendLen:	实际发送的长度
//返 回 值:
//			CDMA_SUCCESS:		执行成功
//			CDMA_RS_TIMEOUT:	接收应答超时
//			CDMA_WRITE_ERR:		写串口出错
//			CDMA_EXECUTE_ERR:	处理失败,原因参见response
//			CDMA_PARA_ERR:		输入参数错误
//			CDMA_PARSERES_ERR:  解析应答错误
//备    注: 该函数每次最大发送的数据长度是CDMA_MAX_SEND_LEN
unsigned short CDMA_TcpSendData( unsigned short socket_no, unsigned short data_len, unsigned char *data,unsigned short *RSendLen, char *respone );


//函 数 名:	CDMA_GetSQ
//功    能:	Get Signal Quality
//输入参数:	none
//输出参数:	respone:	设备返回的应答
//			rssi:		信号强度
//			ber:	    误码率
//返 回 值:
//			CDMA_SUCCESS:	查询成功
//			CDMA_RS_TIMEOUT:接收应答超时
//			CDMA_WRITE_ERR:	写串口出错
//			CDMA_EXECUTE_ERR:	处理失败,原因参见response
unsigned short CDMA_GetSQ( char *respone, unsigned short *rssi );

//函 数 名:	CDMA_NetRegReport
//功    能:	查询CDMA网络注册状态
//输入参数:	none
//输出参数:	respone:	设备返回的应答
//		rssi:	
//			0: 未注册,并且模块当前不搜寻新的运营商
//			1: 已注册本地网络
//			2：未注册,终端正在搜寻基站
//			4：注册被拒绝
//			5：已注册,并且处于漫游状态
//返 回 值:
//			CDMA_SUCCESS:		查询成功
//			CDMA_RS_TIMEOUT:	接收应答超时
//			CDMA_WRITE_ERR:		写串口出错
//			CDMA_EXECUTE_ERR:	处理失败,原因参见response
//			CDMA_PARSERES_ERR:	解析应答错误
unsigned short CDMA_NetRegReport( char *respone, unsigned short *status );

//函 数 名:	CDMA_IPReceive
//功    能:	接收设备从指定的SOCKET通道返回的数据
//输入参数:	timeout:接收超时时间
//输出参数:	respone:	设备返回的应答
//			data:		接收到的数据
//			rev_len:	接收到的数据长度
//返 回 值:
//			CDMA_SUCCESS:		查询成功
//			CDMA_RS_TIMEOUT:	接收应答超时
//			CDMA_EXECUTE_ERR:	处理失败,原因参见response
unsigned short CDMA_IPReceive( unsigned char *data,  unsigned short *rev_len, unsigned short timeout, char *respone );



//	函 数 名: CDMA_Get_PwrOn_Rs
//	描    述: 取CDMA模块的上电应答
//	全局变量: 无
//	输入参数: timeout:以us为单位
//	输出参数: Respone
//	返 回 值: 成功返回0, 其它-失败
//	作    者: 吴 志 坚
//	创建日期: 2009/7/25
//	修 改 者: 
//	修改日期: 
//	备    注: 中兴CDMA模块刚上电时返回:+ZIND:8 和+ZIND:1,得到这个返回后才能接收AT指令
unsigned short CDMA_Get_PwrOn_Rs( long timeout, char *Respone );




//	函 数 名: CDMA_SetPPP_ReDial
//	描    述: 设置PPP断线重拨.
//	全局变量: 无
//	输入参数: time: 0-不重拨, 其它值为重拨间隙,以秒为单位, timeout:指令超时时间
//	输出参数: respone:模块返回的应答
//	返 回 值: 0-成功, 其它-失败
//	作    者: 吴 志 坚
//	创建日期: 2009/7/25
//	修 改 者: 
//	修改日期: 
//	备    注: 
unsigned short CDMA_SetPPP_ReDial( unsigned short time, char *respone );




//	函 数 名: CDMA_Set_EnableKeepOnLine
//	描    述: 启用或者关闭保持在线功能
//	全局变量: 无
//	输入参数: YesOrNot:0-关闭,  1-启用 
//	输出参数: respone:模块返回的应答
//	返 回 值: 0-成功, 其它-失败
//	作    者: 吴 志 坚
//	创建日期: 2009/7/25
//	修 改 者: 
//	修改日期: 
//	备    注: 
unsigned short CDMA_Set_EnableKeepOnLine( unsigned short YesOrNot, char *respone );


//	函 数 名: CDMA_Set_VKLStatus
//	描    述: 设置进入虚拟模式
//	全局变量: 无
//	输入参数: 
//			  mode=0:启动虚拟在线功能
//			  mode=1:实在线模式
//			  mode=2:远在线模式	 
//			  mode=3:查询在线模式
//			  mode=4:设置进入虚在线模式时间
//			  当mode=4时, time为进入虚拟模式的时间
//			  time:(0~255)//sec
//	输出参数: 
//	返 回 值: 成功-0, 其它-错误
//	作    者: 吴 志 坚
//	创建日期: 2009/7/25
//	修 改 者: 
//	修改日期: 
//	备    注: 
unsigned short CDMA_Set_VKLStatus( unsigned short mode, unsigned short time, char * respone );


//函 数 名:CDMA_DeviceInit
//输入参数:scom:与模块通讯的串口号
//输出参数:无
//返 回 值:
// CDMA_SUCCESS						0
// CDMA_RS_TIMEOUT 					0xFF	//接收设备返回超时
// CDMA_WRITE_ERR					0xFE	//写串口出错
// CDMA_READ_ERR					0xFD	//读串口出错
// CDMA_PARA_ERR					0xFC	//输入的参数错误
// CDMA_EXECUTE_ERR					0xFB	//执行命令失败
// CDMA_PARSERES_ERR				0xFA  	//解析应答错误
// CDMA_OPEN_SERIALPORT_ERR			0xF9	//打开CDMA串口出错		
unsigned short CDMA_DeviceInit(void);

/*================================================================================================*
	函 数 名: CDMA_Inquiry_ZIND
	描    述: 查询模块指示设置情况
	全局变量: 无
	输入参数: 无
	输出参数: 
	返 回 值: 成功-0, 其它-错误
	作    者: 吴 志 坚
	创建日期: 2009/7/25
	修 改 者: 
	修改日期: 
	备    注: 
*================================================================================================*/
unsigned short CDMA_Inquiry_ZIND( int *val, char * respone );


/*================================================================================================*
	函 数 名: CDMA_Set_ZIND
	描    述: 查询模块指示设置情况
	全局变量: 无
	输入参数: 无
	输出参数: 
	返 回 值: 成功-0, 其它-错误
	作    者: 吴 志 坚
	创建日期: 2009/7/25
	修 改 者: 
	修改日期: 
	备    注: 
*================================================================================================*/
unsigned short CDMA_Set_ZIND( int val, char * respone );


//函 数 名:CDMA_ATTest
//功    能: 发送指令AT,测试是否能与模块正常通讯
//输入参数: 无
//输出参数:	respone:	设备返回的应答
//返 回 值:	
//			CDMA_SUCCESS:	命令发送成功
//			CDMA_RS_TIMEOUT:接收应答超时
//			CDMA_WRITE_ERR:	写串口出错
//			CDMA_EXECUTE_ERR:执行命令失败
unsigned short CDMA_ATTest(  char *respone );



//函 数 名: CDMA_InqCPIN
//描    述: 检查是否需要输入密码设备才能正常是有
//全局变量: 无
//输出参数: Respone
//返 回 值: 成功返回0, 其它-失败
//作    者: 吴 志 坚
//创建日期: 2009/7/25
//修 改 者: 
//修改日期: 
//备    注: 通常用来检查是否插入了SIM卡
unsigned short CDMA_InqCPIN( char *respone );


//函 数 名:	CDMA_CmdEcho
//功    能:	使用该命令，可设置TA 在命令状态下是否回显从TE 接收到的字符
//输入参数:	val
//			1:回显方式开启, 0:回显方式关闭
//输出参数:	respone:	设备返回的应答
//返 回 值:
//			CDMA_SUCCESS:		设置成功
//			CDMA_RS_TIMEOUT:	接收应答超时
//			CDMA_WRITE_ERR:		写串口出错
//			CDMA_EXECUTE_ERR:	处理失败,原因参见response
unsigned short CDMA_CmdEcho( unsigned short val, char *respone );

#endif
