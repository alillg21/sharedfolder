#ifndef _GPRS_SUPPORT_H_ 
#define _GPRS_SUPPORT_H_

#define GPRS_CONN_ID1		1		//socket connect ID
#define GPRS_CONN_ID2		2
#define GPRS_CONN_ID3		3
#define GPRS_CONN_ID4		4
#define GPRS_CONN_ID5		5
#define GPRS_MAX_CONN_ID	5		//���socket connect��Ŀ


#define GRPS_PDP_CID1		1		//������ID
#define GRPS_PDP_CID2		2		//������ID
#define GRPS_PDP_CID3		3		//������ID
#define GRPS_PDP_CID4		4		//������ID
#define GRPS_PDP_CID5		5		//������ID
#define GRPS_MAX_PDP_CID	5		//���������ID



#define GPRS_CR	0x0D
#define GPRS_LF	0x0A
#define GPRS_CRLF "\x0D\x0A"
#define GPRS_SUCCESS				0
#define GPRS_RS_TIMEOUT 			0xFF	//�����豸�������ݳ�ʱ
#define GPRS_WRITE_ERR				0xFE	//д���ڳ���
#define GPRS_READ_ERR				0xFD	//�����ڳ���
#define GPRS_PARA_ERR				0xFC	//����Ĳ�������
#define GPRS_EXECUTE_ERR			0xFB	//ִ������ʧ��
#define GPRS_PARSERES_ERR			0xFA  	//����Ӧ�����
#define GPRS_DISCONNECT_ERR 		0xF9	//ʧȥ����
#define GPRS_OPEN_SERIALPORT_ERR	0xF8	//��GPRS���ڳ���

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


//GPRSָ��Ȳ��ܳ�����ֵ
#define GPRS_MAX_CMD_LEN	999

//���ص�gprsӦ�����󳤶�
#define GPRS_MAX_RS_LEN	 	199

#define GPRS_BUFSIZE 1500	//gprs buf��С(��������ʱ,���ݳ��Ȳ��ܳ�����ֵ)
#define RECV_TIME 1000*500 	//usec(���ʱ����ָ���յ�ǰһ���ַ����һ���ַ��ļ��ʱ��)
#define CMD_SEND_MODE  1   //����̬����ģʽ
#define HYA_SEND_MODE  0	//͸������ģʽ


#define CUR_PDP_CID	GRPS_PDP_CID1  	//��ǰʹ�õ�PDP������ID
#define CUR_CONN_ID	GPRS_CONN_ID1	//��ǰʹ�õ�SOCKET CONNECT ID
#define GPRS_TCP	0


typedef struct _CGREG_STATUS_STRUCT_
{
	unsigned short mode;	//creg mode
	unsigned short state;	//״̬
	unsigned char lac[50];		//Local Area Code for the currently registered on cell
	unsigned char ci[50];		//Cell Id for the currently registered on cell
}struct_cgreg_status;


//�� �� ��:GprsOpenCom
//��    ��:�ر���GPRSģ��ͨѶ�Ĵ���
//�������:��
//�������:��
//�� �� ֵ:	
void GPRS_CloseSCOM(void);


//�� �� ��:GPRS_OpenSCOM
//��    ��:����gprsģ��ͨѶ�Ĵ���
//�������:��
//�������:��
//�� �� ֵ:	
//			0:							�򿪴��ڳɹ�
//			GPRS_OPEN_SERIALPORT_ERR:  	�򿪴���ʧ��
unsigned short GPRS_OpenSCOM(void);


//�� �� ��:	GPRS_Activate
//��    ��:	deactivates/activates the GPRS context,
//�������:	mode
//			mode=1:activate gprs context
//			mode=0:deactivate gprs context
//�������:	respone:	�豸���ص�Ӧ��
//�� �� ֵ:
//			GPRS_SUCCESS:		ִ�гɹ�
//			GPRS_RS_TIMEOUT:	����Ӧ��ʱ
//			GPRS_WRITE_ERR:		д���ڳ���
//			GPRS_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
//			GPRS_PARA_ERR:		��������
unsigned short GPRS_Activate( unsigned short mode, char *respone );
unsigned short GPRS_Activate_V1(unsigned short connId, unsigned short mode, char *userid, char *userpwd,char *respone );

//�� �� ��:	GPRS_ChangeToCommand
//��    ��:	moves back to command mode
//�������:	none
//�������:	respone:	�豸���ص�Ӧ��
//�� �� ֵ:
//			GPRS_SUCCESS:	ִ�гɹ�
//			GPRS_RS_TIMEOUT:����Ӧ��ʱ
//			GPRS_WRITE_ERR:	д���ڳ���
//			GPRS_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
unsigned short GPRS_ChangeToCommand( char *respone );


//�� �� ��:	GPRS_ChangeToCmd_NoWaitRes
//��    ��:	moves back to command mode
//�������:	none
//�������:	none
//�� �� ֵ:
//			GPRS_SUCCESS:	ִ�гɹ�
//˵    ��:	�ú�������ȴ�+++�л�ָ���ķ���ֵ
unsigned short GPRS_ChangeToCmd_NoWaitRes( void );


//�� �� ��:GPRS_ATTest
//��    ��: ����ָ��AT,�����Ƿ�����ģ������ͨѶ
//�������: ��
//�������:	respone:	�豸���ص�Ӧ��
//�� �� ֵ:	
//			GPRS_SUCCESS:	����ͳɹ�
//			GPRS_RS_TIMEOUT:����Ӧ��ʱ
//			GPRS_WRITE_ERR:	д���ڳ���
unsigned short GPRS_ATTest(  char *respone );


//�� �� ��:	GPRS_CmdEcho
//��    ��:	ʹ�ø����������TA ������״̬���Ƿ���Դ�TE ���յ����ַ�
//�������:	val
//			1:���Է�ʽ����, 0:���Է�ʽ�ر�
//�������:	respone:	�豸���ص�Ӧ��
//�� �� ֵ:
//			GPRS_SUCCESS:		����userid�ɹ�
//			GPRS_RS_TIMEOUT:	����Ӧ��ʱ
//			GPRS_WRITE_ERR:		д���ڳ���
//			GPRS_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
unsigned short GPRS_CmdEcho( unsigned short val, char *respone );

//�� �� ��:	GPRS_CloseSocket
//��    ��:	resumes socket connection which has been suspended by the escape sequence.
//�������:	connId:		socket connection identifier, 1..6
//�������:	respone:	�豸���ص�Ӧ��
//�� �� ֵ:
//			GPRS_SUCCESS:	ִ�гɹ�
//			GPRS_RS_TIMEOUT:����Ӧ��ʱ
//			GPRS_WRITE_ERR:	д���ڳ���
//			GPRS_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
unsigned short GPRS_CloseSocket( unsigned short connId, char *respone );

//�� �� ��:	GPRS_GetActivationStatus
//��    ��:	get current status of the GPRS context
//�������:	none
//�������:	respone:	�豸���ص�Ӧ��
//			gprs_status:
//			0 - GPRS context deactivated
//			1 - GPRS context activated
//			2 - GPRS context activation pending
//�� �� ֵ:
//			GPRS_SUCCESS:	ִ�гɹ�
//			GPRS_RS_TIMEOUT:����Ӧ��ʱ
//			GPRS_WRITE_ERR:	д���ڳ���
//			GPRS_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
//			GPRS_PARSERES_ERR:	����Ӧ�����
unsigned short GPRS_GetActivationStatus( char *respone, unsigned short *status );

unsigned short GPRS_GetActivationStatus_V1( char *respone, unsigned short *status );
//�� �� ��:	GPRS_GetErrorMode
//��    ��:	enables/disables the report of result code:
//�������:	��
//�������:	respone:	�豸���ص�Ӧ��
//			mode:
//					0 - disable +CME ERROR:<err> reports, use only ERROR report.   
//					1 - enable +CME ERROR:<err> reports, with <err> in numeric format
//					2 - enable +CME ERROR: <err> reports, with <err> in verbose format
//�� �� ֵ:
//			GPRS_SUCCESS:	ִ�гɹ�
//			GPRS_RS_TIMEOUT:����Ӧ��ʱ
//			GPRS_WRITE_ERR:	д���ڳ���
//			GPRS_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
//			GPRS_PARSERES_ERR:	����Ӧ�����
unsigned short GPRS_GetErrorMode( char *respone, unsigned short *mode );

//�� �� ��:	GPRS_GetSQ
//��    ��:	Get Signal Quality
//�������:	none
//�������:	respone:	�豸���ص�Ӧ��
//			rssi:		�ź�ǿ��
//			ber:	    ������
//�� �� ֵ:
//			GPRS_SUCCESS:	��ѯ�ɹ�
//			GPRS_RS_TIMEOUT:����Ӧ��ʱ
//			GPRS_WRITE_ERR:	д���ڳ���
//			GPRS_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
unsigned short GPRS_GetSQ( char *respone, unsigned short *rssi, unsigned short *ber );

//�� �� ��:	GPRS_NetRegReport
//��    ��:	��ѯGPRS����ע��״̬
//�������:	none
//�������:	respone:	�豸���ص�Ӧ��
//			cgreg_st:	�ɹ�ʱ״ֵ̬
//�� �� ֵ:
//			GPRS_SUCCESS:		��ѯ�ɹ�
//			GPRS_RS_TIMEOUT:	����Ӧ��ʱ
//			GPRS_WRITE_ERR:		д���ڳ���
//			GPRS_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
//			GPRS_PARSERES_ERR:	����Ӧ�����
unsigned short GPRS_NetRegReport( char *respone, struct_cgreg_status *cgreg_st );

unsigned short GPRS_RecvData_V1(int socket_fd, unsigned char *data, unsigned short *rev_len, unsigned short timeout );
//�� �� ��:	GPRS_RevcData
//��    ��:	�����豸��ָ����SOCKETͨ�����ص�����
//�������:	timeout:	���ճ�ʱʱ��
//�������:	respone:	�豸���ص�Ӧ��
//			data:		���յ�������
//			rev_len:	���յ������ݳ���
//�� �� ֵ:
//			GPRS_SUCCESS:		��ѯ�ɹ�
//			GPRS_RS_TIMEOUT:	����Ӧ��ʱ
unsigned short GPRS_RecvData( unsigned char *data, unsigned short *rev_len, unsigned short timeout );

//�� �� ��:GPRS_SendAtCmd
//��    ��:���������GPRSģ��
//�������:
//			cmd:Ҫ���͸�ģ�������(��<CR><LF>���ַ���)
//			timeout:���������Ӧ��ʱʱ��
//�������:	response:ģ�鷵�ص�Ӧ��
//�� �� ֵ:	
//			GPRS_SUCCESS:	����ͳɹ�
//			GPRS_RS_TIMEOUT:����Ӧ��ʱ
//			GPRS_WRITE_ERR:	д���ڳ���
//����˵��:�ú�����ȷʹ�õ�ǰ���Ǵ��������ģʽ,��ATE=1;
unsigned short GPRS_SendAtCmd( char *cmd, char *respone, long timeout );

unsigned short GPRS_SendData_V1V2( int socket_fd, unsigned char *data, unsigned short data_len ,char version,char *respone );
unsigned short GPRS_SendData_V1( int socket_fd, unsigned char *data, unsigned short data_len ,char *respone );
unsigned short GPRS_SendData_V2( int socket_fd, unsigned char *data, unsigned short data_len ,char *respone );
//�� �� ��:GPRS_SendData
//��    ��:��������(������socket�����Ժ���ܵ��øú���)
//�������:
//			data:Ҫ���͵�����
//			data_len:Ҫ���͵����ݵĳ���
//			timeout:���������Ӧ��ʱʱ��
//�� �� ֵ:	
//			GPRS_SUCCESS:	����ͳɹ�
//			GPRS_WRITE_ERR:	д���ڳ���
//			GPRS_PARA_ERR:	�����������
unsigned short GPRS_SendData( unsigned char *data, unsigned short data_len );

//�� �� ��:	GPRS_SetAttach
//��    ��:	sets GPRS Attach Or Detach
//�������:	state
//			state=1:attach the terminal to gprs service
//			state=0:detach the terminal from gprs service
//�������:	respone:	�豸���ص�Ӧ��
//�� �� ֵ:
//			GPRS_SUCCESS:	ִ�гɹ�
//			GPRS_RS_TIMEOUT:����Ӧ��ʱ
//			GPRS_WRITE_ERR:	д���ڳ���
//			GPRS_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
//			GPRS_PARA_ERR:		��������
unsigned short GPRS_SetAttach( unsigned short state, char *respone );


//�� �� ��:	GPRS_GetAttachStatus
//��    ��:	ȡgprs����״̬
//�������:	none
//�������:	respone:	�豸���ص�Ӧ��
//			status:		����״̬, 0-δ����,1-�Ѹ���
//�� �� ֵ:
//			GPRS_SUCCESS:	��ѯ�ɹ�
//			GPRS_RS_TIMEOUT:����Ӧ��ʱ
//			GPRS_WRITE_ERR:	д���ڳ���
//			GPRS_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
unsigned short GPRS_GetAttachStatus( unsigned short *status, char *respone );


//�� �� ��:	GPRS_SetErrorMode
//��    ��:	enables/disables the report of result code:
//�������:	mode
//			0 - disable +CME ERROR:<err> reports, use only ERROR report.   
//			1 - enable +CME ERROR:<err> reports, with <err> in numeric format
//			2 - enable +CME ERROR: <err> reports, with <err> in verbose format
//�������:	respone:	�豸���ص�Ӧ��
//�� �� ֵ:
//			GPRS_SUCCESS:	ִ�гɹ�
//			GPRS_RS_TIMEOUT:����Ӧ��ʱ
//			GPRS_WRITE_ERR:	д���ڳ���
//			GPRS_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
//			GPRS_PARA_ERR:		��������
unsigned short GPRS_SetErrorMode( unsigned short mode, char *respone );


//�� �� ��:	GPRS_SetNetRegReportMode
//��    ��:	����GPRS����ע��ģʽ
//�������:	mode
//			0 - disable network registration unsolicited result code (factory default)
//			1 - enable network registration unsolicited result code
//			2 - enable network registration unsolicited result code with network Cell
//				identification data
//�������:	respone:	�豸���ص�Ӧ��
//�� �� ֵ:
//			GPRS_SUCCESS:		��ѯ�ɹ�
//			GPRS_RS_TIMEOUT:	����Ӧ��ʱ
//			GPRS_WRITE_ERR:		д���ڳ���
//			GPRS_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
//			GPRS_PARA_ERR:		������
unsigned short GPRS_SetNetRegReportMode( unsigned short mode, char *respone );

//�� �� ��:GPRS_SetPDPContext
//��    ��:����PDP context
//�������:
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
//�������:	response:	GPRS�豸���ص�Ӧ��
//�� �� ֵ:
//			GPRS_SUCCESS:	����PDP�����ĳɹ�
//			GPRS_RS_TIMEOUT:����Ӧ��ʱ
//			GPRS_WRITE_ERR:	д���ڳ���
//			1:				����PDP������ʧ��,ʧ��ԭ��μ�response
//			2:				������ 			
unsigned short GPRS_SetPDPContext(unsigned short cid, char *pdp_type, char *apn, char	*pdp_addr, unsigned short d_comp, unsigned short h_comp, char *response );

//�� �� ��:	GPRS_SetUserID
//��    ��:	sets the user identification string to be used during the
//			authentication step
//�������:	userid
//�������:	respone:	�豸���ص�Ӧ��
//�� �� ֵ:
//			GPRS_SUCCESS:	����userid�ɹ�
//			GPRS_RS_TIMEOUT:����Ӧ��ʱ
//			GPRS_WRITE_ERR:	д���ڳ���
//			GPRS_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
unsigned short GPRS_SetUserID( char *userid, char *respone );



//�� �� ��:	GPRS_SetUserPWD
//��    ��:	sets the user password string to be used during the
//			authentication step.
//�������:	userpwd
//�������:	respone:	�豸���ص�Ӧ��
//�� �� ֵ:
//			GPRS_SUCCESS:	����userid�ɹ�
//			GPRS_RS_TIMEOUT:����Ӧ��ʱ
//			GPRS_WRITE_ERR:	д���ڳ���
//			GPRS_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
unsigned short GPRS_SetUserPWD( char *userpwd, char *respone );


//�� �� ��:	GPRS_SkipEsc
//��    ��:	enables/disables skipping the escape sequence +++ while
//			transmitting during a data connection.
//�������:	flag=0:doesn��t skip the escape sequence; its transmission is enabled (factory default).
//			flag=1:skips the escape sequence; its transmission is not enabled.
//�������:	respone:	�豸���ص�Ӧ��
//�� �� ֵ:
//			GPRS_SUCCESS:	ִ�гɹ�
//			GPRS_RS_TIMEOUT:����Ӧ��ʱ
//			GPRS_WRITE_ERR:	д���ڳ���
//			GPRS_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
//ע	��:	in case of an FTP connection, the escape sequence is not
//			transmitted, regardless of the command setting.
unsigned short GPRS_SkipEsc( unsigned short flag, char *respone );


//�� �� ��:	GPRS_SocketConfig
//��    ��:	opens a remote connection via socket.
//�������:	
//			connId:		socket connection identifier, 1..6
//			cid:		PDP context identifier 1..5 - numeric parameter which specifies a particular PDP context definition
//			pktSz:		packet size to be used by the TCP/UDP/IP stack for data sending.
//						0 - automatically chosen by the device.
//						1..1500 - packet size in bytes.
//			maxTo:		exchange timeout (or socket inactivity timeout); if there��s no
//						data exchange within this timeout period the connection is closed.
//						0 - no timeout
//						n - timeout value in seconds (default 90 s.)
//			connTo:		connection timeout; if we can��t establish a connection to the
//						remote within this timeout period, an error is raised.
//						0 - no timeout
//						n - timeout value in hundreds of milliseconds (default 600)	
//			txTo:		data sending timeout; after this period data are sent also if they��re
//						less than max packet size.
//						0 - no timeout
//						n - timeout value in hundreds of milliseconds (default 50)
//�������:	respone:	�豸���ص�Ӧ��
//�� �� ֵ:
//			GPRS_SUCCESS:	ִ�гɹ�
//			GPRS_RS_TIMEOUT:����Ӧ��ʱ
//			GPRS_WRITE_ERR:	д���ڳ���
//			GPRS_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
//			GPRS_PARA_ERR:		��������
//Note: 	these values are automatically saved in NVM.
unsigned short GPRS_SocketConfig( unsigned short connId, unsigned short cid, unsigned short pktSz, 
								unsigned short maxTo, unsigned short connTo, unsigned short txTo, char *respone );
unsigned short GPRS_SocketConfigExt( unsigned short connId, unsigned short srMode, unsigned short recvDataMode, 
								unsigned short keepalive, unsigned short ListenAutoRsp, unsigned short sendDataMode, char *respone );			
								
unsigned short GPRS_SocketDial_V1( unsigned short connId, unsigned short txProt, unsigned short rPort, 
								char *IPaddr, unsigned short lingerT, unsigned short lPort,unsigned char mode,char *respone );
//�� �� ��:	GPRS_SocketDial
//��    ��:	opens a remote connection via socket.
//�������:	
//			connId:		socket connection identifier, 1..6
//			txProt:		transmission protocol, 0 - TCP, 1 - UDP
//			rPort:		remote host port to contact, 0~65535
//			IPaddr:		address of the remote host, string type.
//						This parameter can be either:
//						- any valid IP address in the format: ��xxx.xxx.xxx.xxx��
//						- any host name to be solved with a DNS query
//			lingerT:	linger time	
//						0 - immediate closure after remote closure
//						255 - local host closes only after an escape sequence (+++)
//			lPort:		UDP connections local port, 0..65535
//�������:	respone:	�豸���ص�Ӧ��
//�� �� ֵ:
//			GPRS_SUCCESS:	ִ�гɹ�
//			GPRS_RS_TIMEOUT:����Ӧ��ʱ
//			GPRS_WRITE_ERR:	д���ڳ���
//			GPRS_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
//			GPRS_PARA_ERR:		��������
unsigned short GPRS_SocketDial( unsigned short connId, unsigned short txProt, unsigned short rPort, 
								char *IPaddr, unsigned short lingerT, unsigned short lPort, char *respone )	;							
	
//�� �� ��:	GPRS_PingHost
//��    ��:	send Ping echo request messages and to receive the correspongding echo reply.
//�������:	IPaddr: address of the remote host,string type.
//          retryNum: the number if Ping Echo Request to send;
//          len: the length of Ping Echo request message;
//          timeout: the timeout
//          ttl: time to live
//�������:	respone:	�豸���ص�Ӧ��
//�� �� ֵ:
//			GPRS_SUCCESS:	ִ�гɹ�
//			GPRS_RS_TIMEOUT:����Ӧ��ʱ
//			GPRS_WRITE_ERR:	д���ڳ���
//			GPRS_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
unsigned short GPRS_PingHost( char *IPaddr,unsigned char retryNum,int len,int timeout, unsigned char ttl, char *respone );
								
								//�� �� ��:	GPRS_SocketRestore
//��    ��:	resumes socket connection which has been suspended by the escape sequence.
//�������:	connId:		socket connection identifier, 1..6
//�������:	respone:	�豸���ص�Ӧ��
//�� �� ֵ:
//			GPRS_SUCCESS:	ִ�гɹ�
//			GPRS_RS_TIMEOUT:����Ӧ��ʱ
//			GPRS_WRITE_ERR:	д���ڳ���
//			GPRS_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
unsigned short GPRS_SocketRestore( unsigned short connId, char *respone );


//�� �� ��:GPRS_DeviceInit
//�������:��
//�������:��
//�� �� ֵ:
// GPRS_RS_TIMEOUT 				//�����豸�������ݳ�ʱ
// GPRS_WRITE_ERR				//д���ڳ���
// GPRS_READ_ERR				//�����ڳ���
// GPRS_PARA_ERR				//����Ĳ�������
// GPRS_EXECUTE_ERR				//ִ������ʧ��
// GPRS_PARSERES_ERR			//����Ӧ�����
// GPRS_DISCONNECT_ERR 			//ʧȥ����
// GPRS_OPEN_SERIALPORT_ERR		//��GPRS���ڳ���						
unsigned short GPRS_DeviceInit(void);

					
//�� �� ��:	GPRS_CPIN
//��    ��:	��ѯSIM���������
//�������:	��
//�������:	respone:	�豸���ص�Ӧ��
//�� �� ֵ:
//			GPRS_SUCCESS:		��ѯ�ɹ�
//			GPRS_RS_TIMEOUT:	����Ӧ��ʱ
//			GPRS_WRITE_ERR:		д���ڳ���
//			GPRS_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
unsigned short GPRS_InqCPIN( char *respone );

//�� �� ��:        GPRS_GetGMR
//��    ��:       ʹ�ø������ѯģ��汾��
//�������: ��
//�������: respone:        �豸���ص�Ӧ��(����������Ϣ)
//�� �� ֵ:
//                      GPRS_SUCCESS:           ��ѯ�ɹ�
//                      GPRS_RS_TIMEOUT:        ����Ӧ��ʱ
//                      GPRS_WRITE_ERR:         д���ڳ���
//                      GPRS_EXECUTE_ERR:       ����ʧ��,ԭ��μ�response
unsigned short GPRS_GetGMR( char *respone );

//�� �� ��:	GPRS_SelectFLO
//��    ��:	�����Ƿ�ʹ������
//�������:	type
//			0:flow control None
//      1:flow control Software(XON_XOFF)
//      2.flow control Hardware(CTS-RTS)-(factory default)
//�������:	respone:	�豸���ص�Ӧ��
//�� �� ֵ:
//			GPRS_SUCCESS:		���óɹ�
//			GPRS_RS_TIMEOUT:	����Ӧ��ʱ
//			GPRS_WRITE_ERR:		д���ڳ���
//			GPRS_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
unsigned short GPRS_SelectFLO( unsigned short type, char *respone );

//�� �� ��:	GPRS_SetCPUMode
//��    ��:	�����Ƿ�ʹ������
//�������:	mode
//			0: normal CPU clock
//      1: fast CPU clock
//      2. fast CPU clock,during GPRS TX/RX only
//�������:	respone:	�豸���ص�Ӧ��
//�� �� ֵ:
//			GPRS_SUCCESS:		���óɹ�
//			GPRS_RS_TIMEOUT:	����Ӧ��ʱ
//			GPRS_WRITE_ERR:		д���ڳ���
//			GPRS_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
unsigned short GPRS_SetCPUMode( unsigned short mode, char *respone );
//�� �� ��:	GPRS_GetGMI
//��    ��:	ʹ�ø������ѯ��������
//�������:	��
//�������:	respone:	�豸���ص�Ӧ��(����������Ϣ)
//�� �� ֵ:
//			GPRS_SUCCESS:		��ѯ�ɹ�
//			GPRS_RS_TIMEOUT:	����Ӧ��ʱ
//			GPRS_WRITE_ERR:		д���ڳ���
//			GPRS_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
unsigned short GPRS_GetGMI( char *respone );




#endif


