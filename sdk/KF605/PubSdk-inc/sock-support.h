//函 数 名: SCK_CreatSocket
//描    述: 创建一个新的stream socket
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 如果失败，返回值小于0,否则创建socket成功
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 
int SCK_CreatSocket(void);



//函 数 名: SCK_ConnectServer
//描    述: 连接服务器
//全局变量: 无
//输入参数: 
//			nSocketFd:	通过SCK_CreatSocket函数创建的socket
//			sServerName:要连接的服务器名(或者形如"192.168.100.1"这样的IP地址)
//			nPort:		远端端口
//			timeout:	连接服务器的超时时间
//输出参数: 无
//返 回 值: 
//						-1:连接服务器失败
//						-2:连接服务器超时
//						0: 连接服务器成功
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 
int SCK_ConnectServer( int nSocketFd, char *sServerName, int nPort, unsigned int timeout );



//函 数 名: SCK_Send
//描    述: 向已经建立连接的socket发送数据
//全局变量: 无
//输入参数: 
//			nSocketFd:	要发送数据的socket
//			Data:		要发送的数据
//			nDataLen:	要发送的数据长度
//输出参数: 无
//返 回 值: 
//			>=0			实际成功发送的数据长度
//			<0			发送数据出错
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 
int SCK_Send( int nSocketFd, char *Data, int nDataLen );





//函 数 名: SCK_Recv
//描    述: 接收nSocketFd指定的链路的数据
//全局变量: 无
//输入参数: 
//			nSocketFd:	指明从哪个socket接收数据
//			timeout:	接收数据超时时间
//			nRecvLen:	期望接收到的数据长度
//输出参数: 
//			Data:		接收到的数据
//返 回 值: 
//						-1:接收数据失败
//						-2:接收数据超时
//					   >=0:实际接收到的数据长度
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 
int SCK_Recv( int nSocketFd, char *Data, int nRecvLen, unsigned int timeout );



//函 数 名: SCK_CloseSocket
//描    述: 关闭一个socket
//全局变量: 无
//输入参数: 
//			nSocketFd:	要关闭的socket
//输出参数: 无
//返 回 值: 无
//作    者: 吴 志 坚
//创建日期: 2009/9/02
//修 改 者: 
//修改日期: 
//备    注: 
void SCK_CloseSocket(int nSocketFd );




