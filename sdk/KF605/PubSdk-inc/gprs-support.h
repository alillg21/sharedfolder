#ifndef _GPRS_SUPPORT_H_ 
#define _GPRS_SUPPORT_H_

#define GPRS_CONN_ID1		1		//socket connect ID
#define GPRS_CONN_ID2		2
#define GPRS_CONN_ID3		3
#define GPRS_CONN_ID4		4
#define GPRS_CONN_ID5		5
#define GPRS_MAX_CONN_ID	5		//最大socket connect数目


#define GRPS_PDP_CID1		1		//上下文ID
#define GRPS_PDP_CID2		2		//上下文ID
#define GRPS_PDP_CID3		3		//上下文ID
#define GRPS_PDP_CID4		4		//上下文ID
#define GRPS_PDP_CID5		5		//上下文ID
#define GRPS_MAX_PDP_CID	5		//最大上下文ID



#define GPRS_CR	0x0D
#define GPRS_LF	0x0A
#define GPRS_CRLF "\x0D\x0A"
#define GPRS_SUCCESS				0
#define GPRS_RS_TIMEOUT 			0xFF	//接收设备返回数据超时
#define GPRS_WRITE_ERR				0xFE	//写串口出错
#define GPRS_READ_ERR				0xFD	//读串口出错
#define GPRS_PARA_ERR				0xFC	//输入的参数错误
#define GPRS_EXECUTE_ERR			0xFB	//执行命令失败
#define GPRS_PARSERES_ERR			0xFA  	//解析应答错误
#define GPRS_DISCONNECT_ERR 		0xF9	//失去连接
#define GPRS_OPEN_SERIALPORT_ERR	0xF8	//打开GPRS串口出错

#define GPRS_DEFAULT_TIMEOUT 		        2000*1000		//2sec
#define GPRS_SH_TIMEOUT 		        4000*1000		//3sec
#define CMEE_TIMEOUT 				5000*1000		//5 sec
#define CGDCONT_TIMEPUT 			20000*1000		//20 sec
#define CSQ_TIMEOUT					5000*1000		//5 sec
#define CREG_TIMEOUT				5000*1000		//5 sec
#define CGATT_TIMEOUT				180000*1000		//180 sec
#define GPRS_ACTIVE_TIMEOUT			10000*1000		//10 sec
#define GPRS_SOCKET_CONNECT_TIMEOUT	1000*1000*140	//16sec
#define GPRS_SGACT_TIMEOUT	150000*1000		//150 sec

#define GET_SQ_TIME 40				//40sec
#define WAIT_REG_GRPS_TIME 40		//40sec


//GPRS指令长度不能超过该值
#define GPRS_MAX_CMD_LEN	999

//返回的gprs应答的最大长度
#define GPRS_MAX_RS_LEN	 	199

#define GPRS_BUFSIZE 1500	//gprs buf大小(发送数据时,数据长度不能超过该值)
#define RECV_TIME 1000*500 	//usec(这个时间是指接收的前一个字符与后一个字符的间隔时间)
#define CMD_SEND_MODE  1   //命令态传输模式
#define HYA_SEND_MODE  0	//透明传输模式


#define CUR_PDP_CID	GRPS_PDP_CID1  	//当前使用的PDP上下文ID
#define CUR_CONN_ID	GPRS_CONN_ID1	//当前使用的SOCKET CONNECT ID
#define GPRS_TCP	0


typedef struct _CGREG_STATUS_STRUCT_
{
	unsigned short mode;	//creg mode
	unsigned short state;	//状态
	unsigned char lac[50];		//Local Area Code for the currently registered on cell
	unsigned char ci[50];		//Cell Id for the currently registered on cell
}struct_cgreg_status;


//函 数 名:GprsOpenCom
//功    能:关闭与GPRS模块通讯的串口
//输入参数:无
//输出参数:无
//返 回 值:	
void GPRS_CloseSCOM(void);


//函 数 名:GPRS_OpenSCOM
//功    能:打开与gprs模块通讯的串口
//输入参数:无
//输出参数:无
//返 回 值:	
//			0:							打开串口成功
//			GPRS_OPEN_SERIALPORT_ERR:  	打开串口失败
unsigned short GPRS_OpenSCOM(void);


//函 数 名:	GPRS_Activate
//功    能:	deactivates/activates the GPRS context,
//输入参数:	mode
//			mode=1:activate gprs context
//			mode=0:deactivate gprs context
//输出参数:	respone:	设备返回的应答
//返 回 值:
//			GPRS_SUCCESS:		执行成功
//			GPRS_RS_TIMEOUT:	接收应答超时
//			GPRS_WRITE_ERR:		写串口出错
//			GPRS_EXECUTE_ERR:	处理失败,原因参见response
//			GPRS_PARA_ERR:		参数错误
unsigned short GPRS_Activate( unsigned short mode, char *respone );
unsigned short GPRS_Activate_V1(unsigned short connId, unsigned short mode, char *userid, char *userpwd,char *respone );

//函 数 名:	GPRS_ChangeToCommand
//功    能:	moves back to command mode
//输入参数:	none
//输出参数:	respone:	设备返回的应答
//返 回 值:
//			GPRS_SUCCESS:	执行成功
//			GPRS_RS_TIMEOUT:接收应答超时
//			GPRS_WRITE_ERR:	写串口出错
//			GPRS_EXECUTE_ERR:	处理失败,原因参见response
unsigned short GPRS_ChangeToCommand( char *respone );


//函 数 名:	GPRS_ChangeToCmd_NoWaitRes
//功    能:	moves back to command mode
//输入参数:	none
//输出参数:	none
//返 回 值:
//			GPRS_SUCCESS:	执行成功
//说    明:	该函数不会等待+++切换指令后的返回值
unsigned short GPRS_ChangeToCmd_NoWaitRes( void );


//函 数 名:GPRS_ATTest
//功    能: 发送指令AT,测试是否能与模块正常通讯
//输入参数: 无
//输出参数:	respone:	设备返回的应答
//返 回 值:	
//			GPRS_SUCCESS:	命令发送成功
//			GPRS_RS_TIMEOUT:接收应答超时
//			GPRS_WRITE_ERR:	写串口出错
unsigned short GPRS_ATTest(  char *respone );


//函 数 名:	GPRS_CmdEcho
//功    能:	使用该命令，可设置TA 在命令状态下是否回显从TE 接收到的字符
//输入参数:	val
//			1:回显方式开启, 0:回显方式关闭
//输出参数:	respone:	设备返回的应答
//返 回 值:
//			GPRS_SUCCESS:		设置userid成功
//			GPRS_RS_TIMEOUT:	接收应答超时
//			GPRS_WRITE_ERR:		写串口出错
//			GPRS_EXECUTE_ERR:	处理失败,原因参见response
unsigned short GPRS_CmdEcho( unsigned short val, char *respone );

//函 数 名:	GPRS_CloseSocket
//功    能:	resumes socket connection which has been suspended by the escape sequence.
//输入参数:	connId:		socket connection identifier, 1..6
//输出参数:	respone:	设备返回的应答
//返 回 值:
//			GPRS_SUCCESS:	执行成功
//			GPRS_RS_TIMEOUT:接收应答超时
//			GPRS_WRITE_ERR:	写串口出错
//			GPRS_EXECUTE_ERR:	处理失败,原因参见response
unsigned short GPRS_CloseSocket( unsigned short connId, char *respone );

//函 数 名:	GPRS_GetActivationStatus
//功    能:	get current status of the GPRS context
//输入参数:	none
//输出参数:	respone:	设备返回的应答
//			gprs_status:
//			0 - GPRS context deactivated
//			1 - GPRS context activated
//			2 - GPRS context activation pending
//返 回 值:
//			GPRS_SUCCESS:	执行成功
//			GPRS_RS_TIMEOUT:接收应答超时
//			GPRS_WRITE_ERR:	写串口出错
//			GPRS_EXECUTE_ERR:	处理失败,原因参见response
//			GPRS_PARSERES_ERR:	解析应答错误
unsigned short GPRS_GetActivationStatus( char *respone, unsigned short *status );

unsigned short GPRS_GetActivationStatus_V1( char *respone, unsigned short *status );
//函 数 名:	GPRS_GetErrorMode
//功    能:	enables/disables the report of result code:
//输入参数:	无
//输出参数:	respone:	设备返回的应答
//			mode:
//					0 - disable +CME ERROR:<err> reports, use only ERROR report.   
//					1 - enable +CME ERROR:<err> reports, with <err> in numeric format
//					2 - enable +CME ERROR: <err> reports, with <err> in verbose format
//返 回 值:
//			GPRS_SUCCESS:	执行成功
//			GPRS_RS_TIMEOUT:接收应答超时
//			GPRS_WRITE_ERR:	写串口出错
//			GPRS_EXECUTE_ERR:	处理失败,原因参见response
//			GPRS_PARSERES_ERR:	解析应答错误
unsigned short GPRS_GetErrorMode( char *respone, unsigned short *mode );

//函 数 名:	GPRS_GetSQ
//功    能:	Get Signal Quality
//输入参数:	none
//输出参数:	respone:	设备返回的应答
//			rssi:		信号强度
//			ber:	    误码率
//返 回 值:
//			GPRS_SUCCESS:	查询成功
//			GPRS_RS_TIMEOUT:接收应答超时
//			GPRS_WRITE_ERR:	写串口出错
//			GPRS_EXECUTE_ERR:	处理失败,原因参见response
unsigned short GPRS_GetSQ( char *respone, unsigned short *rssi, unsigned short *ber );

//函 数 名:	GPRS_NetRegReport
//功    能:	查询GPRS网络注册状态
//输入参数:	none
//输出参数:	respone:	设备返回的应答
//			cgreg_st:	成功时状态值
//返 回 值:
//			GPRS_SUCCESS:		查询成功
//			GPRS_RS_TIMEOUT:	接收应答超时
//			GPRS_WRITE_ERR:		写串口出错
//			GPRS_EXECUTE_ERR:	处理失败,原因参见response
//			GPRS_PARSERES_ERR:	解析应答错误
unsigned short GPRS_NetRegReport( char *respone, struct_cgreg_status *cgreg_st );

unsigned short GPRS_RecvData_V1(int socket_fd, unsigned char *data, unsigned short *rev_len, unsigned short timeout );
//函 数 名:	GPRS_RevcData
//功    能:	接收设备从指定的SOCKET通道返回的数据
//输入参数:	timeout:	接收超时时间
//输出参数:	respone:	设备返回的应答
//			data:		接收到的数据
//			rev_len:	接收到的数据长度
//返 回 值:
//			GPRS_SUCCESS:		查询成功
//			GPRS_RS_TIMEOUT:	接收应答超时
unsigned short GPRS_RecvData( unsigned char *data, unsigned short *rev_len, unsigned short timeout );

//函 数 名:GPRS_SendAtCmd
//功    能:发送命令给GPRS模块
//输入参数:
//			cmd:要发送给模块的命令(带<CR><LF>的字符串)
//			timeout:该命令的响应超时时间
//输出参数:	response:模块返回的应答
//返 回 值:	
//			GPRS_SUCCESS:	命令发送成功
//			GPRS_RS_TIMEOUT:接收应答超时
//			GPRS_WRITE_ERR:	写串口出错
//补充说明:该函数正确使用的前提是打开命令回显模式,即ATE=1;
unsigned short GPRS_SendAtCmd( char *cmd, char *respone, long timeout );

unsigned short GPRS_SendData_V1V2( int socket_fd, unsigned char *data, unsigned short data_len ,char version,char *respone );
unsigned short GPRS_SendData_V1( int socket_fd, unsigned char *data, unsigned short data_len ,char *respone );
unsigned short GPRS_SendData_V2( int socket_fd, unsigned char *data, unsigned short data_len ,char *respone );
//函 数 名:GPRS_SendData
//功    能:发送数据(必须在socket连接以后才能调用该函数)
//输入参数:
//			data:要发送的数据
//			data_len:要发送的数据的长度
//			timeout:该命令的响应超时时间
//返 回 值:	
//			GPRS_SUCCESS:	命令发送成功
//			GPRS_WRITE_ERR:	写串口出错
//			GPRS_PARA_ERR:	输入参数出错
unsigned short GPRS_SendData( unsigned char *data, unsigned short data_len );

//函 数 名:	GPRS_SetAttach
//功    能:	sets GPRS Attach Or Detach
//输入参数:	state
//			state=1:attach the terminal to gprs service
//			state=0:detach the terminal from gprs service
//输出参数:	respone:	设备返回的应答
//返 回 值:
//			GPRS_SUCCESS:	执行成功
//			GPRS_RS_TIMEOUT:接收应答超时
//			GPRS_WRITE_ERR:	写串口出错
//			GPRS_EXECUTE_ERR:	处理失败,原因参见response
//			GPRS_PARA_ERR:		参数错误
unsigned short GPRS_SetAttach( unsigned short state, char *respone );


//函 数 名:	GPRS_GetAttachStatus
//功    能:	取gprs附着状态
//输入参数:	none
//输出参数:	respone:	设备返回的应答
//			status:		附着状态, 0-未附着,1-已附着
//返 回 值:
//			GPRS_SUCCESS:	查询成功
//			GPRS_RS_TIMEOUT:接收应答超时
//			GPRS_WRITE_ERR:	写串口出错
//			GPRS_EXECUTE_ERR:	处理失败,原因参见response
unsigned short GPRS_GetAttachStatus( unsigned short *status, char *respone );


//函 数 名:	GPRS_SetErrorMode
//功    能:	enables/disables the report of result code:
//输入参数:	mode
//			0 - disable +CME ERROR:<err> reports, use only ERROR report.   
//			1 - enable +CME ERROR:<err> reports, with <err> in numeric format
//			2 - enable +CME ERROR: <err> reports, with <err> in verbose format
//输出参数:	respone:	设备返回的应答
//返 回 值:
//			GPRS_SUCCESS:	执行成功
//			GPRS_RS_TIMEOUT:接收应答超时
//			GPRS_WRITE_ERR:	写串口出错
//			GPRS_EXECUTE_ERR:	处理失败,原因参见response
//			GPRS_PARA_ERR:		参数错误
unsigned short GPRS_SetErrorMode( unsigned short mode, char *respone );


//函 数 名:	GPRS_SetNetRegReportMode
//功    能:	设置GPRS网络注册模式
//输入参数:	mode
//			0 - disable network registration unsolicited result code (factory default)
//			1 - enable network registration unsolicited result code
//			2 - enable network registration unsolicited result code with network Cell
//				identification data
//输出参数:	respone:	设备返回的应答
//返 回 值:
//			GPRS_SUCCESS:		查询成功
//			GPRS_RS_TIMEOUT:	接收应答超时
//			GPRS_WRITE_ERR:		写串口出错
//			GPRS_EXECUTE_ERR:	处理失败,原因参见response
//			GPRS_PARA_ERR:		参数错
unsigned short GPRS_SetNetRegReportMode( unsigned short mode, char *respone );

//函 数 名:GPRS_SetPDPContext
//功    能:设置PDP context
//输入参数:
//			cid:		numeric parameter which specifies a particular PDP context definition
//			pdp_type:	(Packet Data Protocol type) a string parameter which specifies the type of packet data protocol
//						"IP" - Internet Protocol
//						"PPP" - Point to Point Protocol
//			apn:		(Access Point Name) a string parameter which is a logical name that is used to select the GGSN 
//						or the external packet data network. 
//			pdp_addr:	a string parameter that identifies the terminal in the address space applicable to the PDP.
//			d_comp:		numeric parameter that controls PDP data compression
//						0 - off (default if value is omitted)
//						1 - on
//			h_comp:		numeric parameter that controls PDP header compression
//						0 - off (default if value is omitted)
//						1 - on
//输出参数:	response:	GPRS设备返回的应答
//返 回 值:
//			GPRS_SUCCESS:	设置PDP上下文成功
//			GPRS_RS_TIMEOUT:接收应答超时
//			GPRS_WRITE_ERR:	写串口出错
//			1:				设置PDP上下文失败,失败原因参见response
//			2:				参数错 			
unsigned short GPRS_SetPDPContext(unsigned short cid, char *pdp_type, char *apn, char	*pdp_addr, unsigned short d_comp, unsigned short h_comp, char *response );

//函 数 名:	GPRS_SetUserID
//功    能:	sets the user identification string to be used during the
//			authentication step
//输入参数:	userid
//输出参数:	respone:	设备返回的应答
//返 回 值:
//			GPRS_SUCCESS:	设置userid成功
//			GPRS_RS_TIMEOUT:接收应答超时
//			GPRS_WRITE_ERR:	写串口出错
//			GPRS_EXECUTE_ERR:	处理失败,原因参见response
unsigned short GPRS_SetUserID( char *userid, char *respone );



//函 数 名:	GPRS_SetUserPWD
//功    能:	sets the user password string to be used during the
//			authentication step.
//输入参数:	userpwd
//输出参数:	respone:	设备返回的应答
//返 回 值:
//			GPRS_SUCCESS:	设置userid成功
//			GPRS_RS_TIMEOUT:接收应答超时
//			GPRS_WRITE_ERR:	写串口出错
//			GPRS_EXECUTE_ERR:	处理失败,原因参见response
unsigned short GPRS_SetUserPWD( char *userpwd, char *respone );


//函 数 名:	GPRS_SkipEsc
//功    能:	enables/disables skipping the escape sequence +++ while
//			transmitting during a data connection.
//输入参数:	flag=0:doesn’t skip the escape sequence; its transmission is enabled (factory default).
//			flag=1:skips the escape sequence; its transmission is not enabled.
//输出参数:	respone:	设备返回的应答
//返 回 值:
//			GPRS_SUCCESS:	执行成功
//			GPRS_RS_TIMEOUT:接收应答超时
//			GPRS_WRITE_ERR:	写串口出错
//			GPRS_EXECUTE_ERR:	处理失败,原因参见response
//注	意:	in case of an FTP connection, the escape sequence is not
//			transmitted, regardless of the command setting.
unsigned short GPRS_SkipEsc( unsigned short flag, char *respone );


//函 数 名:	GPRS_SocketConfig
//功    能:	opens a remote connection via socket.
//输入参数:	
//			connId:		socket connection identifier, 1..6
//			cid:		PDP context identifier 1..5 - numeric parameter which specifies a particular PDP context definition
//			pktSz:		packet size to be used by the TCP/UDP/IP stack for data sending.
//						0 - automatically chosen by the device.
//						1..1500 - packet size in bytes.
//			maxTo:		exchange timeout (or socket inactivity timeout); if there’s no
//						data exchange within this timeout period the connection is closed.
//						0 - no timeout
//						n - timeout value in seconds (default 90 s.)
//			connTo:		connection timeout; if we can’t establish a connection to the
//						remote within this timeout period, an error is raised.
//						0 - no timeout
//						n - timeout value in hundreds of milliseconds (default 600)	
//			txTo:		data sending timeout; after this period data are sent also if they’re
//						less than max packet size.
//						0 - no timeout
//						n - timeout value in hundreds of milliseconds (default 50)
//输出参数:	respone:	设备返回的应答
//返 回 值:
//			GPRS_SUCCESS:	执行成功
//			GPRS_RS_TIMEOUT:接收应答超时
//			GPRS_WRITE_ERR:	写串口出错
//			GPRS_EXECUTE_ERR:	处理失败,原因参见response
//			GPRS_PARA_ERR:		参数错误
//Note: 	these values are automatically saved in NVM.
unsigned short GPRS_SocketConfig( unsigned short connId, unsigned short cid, unsigned short pktSz, 
								unsigned short maxTo, unsigned short connTo, unsigned short txTo, char *respone );
unsigned short GPRS_SocketConfigExt( unsigned short connId, unsigned short srMode, unsigned short recvDataMode, 
								unsigned short keepalive, unsigned short ListenAutoRsp, unsigned short sendDataMode, char *respone );			
								
unsigned short GPRS_SocketDial_V1( unsigned short connId, unsigned short txProt, unsigned short rPort, 
								char *IPaddr, unsigned short lingerT, unsigned short lPort,unsigned char mode,char *respone );
//函 数 名:	GPRS_SocketDial
//功    能:	opens a remote connection via socket.
//输入参数:	
//			connId:		socket connection identifier, 1..6
//			txProt:		transmission protocol, 0 - TCP, 1 - UDP
//			rPort:		remote host port to contact, 0~65535
//			IPaddr:		address of the remote host, string type.
//						This parameter can be either:
//						- any valid IP address in the format: “xxx.xxx.xxx.xxx”
//						- any host name to be solved with a DNS query
//			lingerT:	linger time	
//						0 - immediate closure after remote closure
//						255 - local host closes only after an escape sequence (+++)
//			lPort:		UDP connections local port, 0..65535
//输出参数:	respone:	设备返回的应答
//返 回 值:
//			GPRS_SUCCESS:	执行成功
//			GPRS_RS_TIMEOUT:接收应答超时
//			GPRS_WRITE_ERR:	写串口出错
//			GPRS_EXECUTE_ERR:	处理失败,原因参见response
//			GPRS_PARA_ERR:		参数错误
unsigned short GPRS_SocketDial( unsigned short connId, unsigned short txProt, unsigned short rPort, 
								char *IPaddr, unsigned short lingerT, unsigned short lPort, char *respone )	;							
	
//函 数 名:	GPRS_PingHost
//功    能:	send Ping echo request messages and to receive the correspongding echo reply.
//输入参数:	IPaddr: address of the remote host,string type.
//          retryNum: the number if Ping Echo Request to send;
//          len: the length of Ping Echo request message;
//          timeout: the timeout
//          ttl: time to live
//输出参数:	respone:	设备返回的应答
//返 回 值:
//			GPRS_SUCCESS:	执行成功
//			GPRS_RS_TIMEOUT:接收应答超时
//			GPRS_WRITE_ERR:	写串口出错
//			GPRS_EXECUTE_ERR:	处理失败,原因参见response
unsigned short GPRS_PingHost( char *IPaddr,unsigned char retryNum,int len,int timeout, unsigned char ttl, char *respone );
								
								//函 数 名:	GPRS_SocketRestore
//功    能:	resumes socket connection which has been suspended by the escape sequence.
//输入参数:	connId:		socket connection identifier, 1..6
//输出参数:	respone:	设备返回的应答
//返 回 值:
//			GPRS_SUCCESS:	执行成功
//			GPRS_RS_TIMEOUT:接收应答超时
//			GPRS_WRITE_ERR:	写串口出错
//			GPRS_EXECUTE_ERR:	处理失败,原因参见response
unsigned short GPRS_SocketRestore( unsigned short connId, char *respone );


//函 数 名:GPRS_DeviceInit
//输入参数:无
//输出参数:无
//返 回 值:
// GPRS_RS_TIMEOUT 				//接收设备返回数据超时
// GPRS_WRITE_ERR				//写串口出错
// GPRS_READ_ERR				//读串口出错
// GPRS_PARA_ERR				//输入的参数错误
// GPRS_EXECUTE_ERR				//执行命令失败
// GPRS_PARSERES_ERR			//解析应答错误
// GPRS_DISCONNECT_ERR 			//失去连接
// GPRS_OPEN_SERIALPORT_ERR		//打开GPRS串口出错						
unsigned short GPRS_DeviceInit(void);

					
//函 数 名:	GPRS_CPIN
//功    能:	查询SIM卡插入情况
//输入参数:	无
//输出参数:	respone:	设备返回的应答
//返 回 值:
//			GPRS_SUCCESS:		查询成功
//			GPRS_RS_TIMEOUT:	接收应答超时
//			GPRS_WRITE_ERR:		写串口出错
//			GPRS_EXECUTE_ERR:	处理失败,原因参见response
unsigned short GPRS_InqCPIN( char *respone );

//函 数 名:        GPRS_GetGMR
//功    能:       使用该命令查询模块版本号
//输入参数: 无
//输出参数: respone:        设备返回的应答(包含厂家信息)
//返 回 值:
//                      GPRS_SUCCESS:           查询成功
//                      GPRS_RS_TIMEOUT:        接收应答超时
//                      GPRS_WRITE_ERR:         写串口出错
//                      GPRS_EXECUTE_ERR:       处理失败,原因参见response
unsigned short GPRS_GetGMR( char *respone );

//函 数 名:	GPRS_SelectFLO
//功    能:	设置是否使用流控
//输入参数:	type
//			0:flow control None
//      1:flow control Software(XON_XOFF)
//      2.flow control Hardware(CTS-RTS)-(factory default)
//输出参数:	respone:	设备返回的应答
//返 回 值:
//			GPRS_SUCCESS:		设置成功
//			GPRS_RS_TIMEOUT:	接收应答超时
//			GPRS_WRITE_ERR:		写串口出错
//			GPRS_EXECUTE_ERR:	处理失败,原因参见response
unsigned short GPRS_SelectFLO( unsigned short type, char *respone );

//函 数 名:	GPRS_SetCPUMode
//功    能:	设置是否使用流控
//输入参数:	mode
//			0: normal CPU clock
//      1: fast CPU clock
//      2. fast CPU clock,during GPRS TX/RX only
//输出参数:	respone:	设备返回的应答
//返 回 值:
//			GPRS_SUCCESS:		设置成功
//			GPRS_RS_TIMEOUT:	接收应答超时
//			GPRS_WRITE_ERR:		写串口出错
//			GPRS_EXECUTE_ERR:	处理失败,原因参见response
unsigned short GPRS_SetCPUMode( unsigned short mode, char *respone );
//函 数 名:	GPRS_GetGMI
//功    能:	使用该命令查询厂家名称
//输入参数:	无
//输出参数:	respone:	设备返回的应答(包含厂家信息)
//返 回 值:
//			GPRS_SUCCESS:		查询成功
//			GPRS_RS_TIMEOUT:	接收应答超时
//			GPRS_WRITE_ERR:		写串口出错
//			GPRS_EXECUTE_ERR:	处理失败,原因参见response
unsigned short GPRS_GetGMI( char *respone );




#endif


