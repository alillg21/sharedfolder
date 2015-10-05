#ifndef _CDMA_SUPPORT_H_
#define	_CDMA_SUPPORT_H_

#define ZTC_CDMA_COM	1
#define CDMA_CR	0x0D
#define CDMA_LF	0x0A
#define CDMA_SCR "\x0D"
#define CDMA_CRLF "\x0D\x0A"
#define CDMA_SUCCESS					0
#define CDMA_RS_TIMEOUT 				0xFF	//�����豸���س�ʱ
#define CDMA_WRITE_ERR					0xFE	//д���ڳ���
#define CDMA_READ_ERR					0xFD	//�����ڳ���
#define CDMA_PARA_ERR					0xFC	//����Ĳ�������
#define CDMA_EXECUTE_ERR				0xFB	//ִ������ʧ��
#define CDMA_PARSERES_ERR				0xFA  	//����Ӧ�����
#define CDMA_OPEN_SERIALPORT_ERR		0xF9	//��CDMA���ڳ���

#define CDMA_DEFAULT_TIMEOUT 			4000*1000		//2 sec
#define CDMA_SENDDATA_TIMEOUT			1000*1000*20 	//20sec
#define CDMA_CREG_TIMEOUT  				2000*1000		//2 sec

#define CDMA_CONNECT_TIMEOUT			1000*1000*60 	//60SEC

#define CDMA_PWRON_GET_RS_TIMEOUT_TIME 	10*1000*1000 	//10 SEC


#define CDMA_MAX_SEND_LEN	1024

//���͵�CDMAģ������ָ���(������β�س���)
//�����ͳ��ȳ�����ֵ��ָ�
#define CDMA_MAX_CMD_LEN 999

//cdmaָ��ص�Ӧ�𳤶����ֵ, ��CDMA��API��������Ӧ�������bufferӦ�ô��ڸ�ֵ.
//�����п��ܲ���Խ���Σ��.
#define CDMA_MAX_RS_LEN	199  

#define CDMA_CONN_ID1		1		//socket connect ID
#define CDMA_CONN_ID2		2
#define CDMA_CONN_ID3		3
#define CDMA_MAX_CONN_ID	3		//���socket connect��Ŀ

#define PPP_OPENED		2
#define PPP_OPENING		1
#define PPP_CLOSED		0

#define SK_CONNECTED	2
#define SK_CONNECTING   1
#define SK_CLOSED	    0


//�� �� ��:CDMA_CloseSCOM
//��    ��:�ر���CDMAģ��ͨѶ�Ĵ���
//�������:��
//�������:��
//�� �� ֵ:��
void CDMA_CloseSCOM(void);


//�� �� ��:CDMA_OpenSCOM
//��    ��:����CDMAģ��ͨѶ�Ĵ���
//�������:��
//�������:��
//�� �� ֵ:	
//			0:							�򿪴��ڳɹ�
//			CDMA_OPEN_SERIALPORT_ERR:  	�򿪴���ʧ��
unsigned short CDMA_OpenSCOM(void);



//�� �� ��:CDMA_SendAtCmd
//��    ��:���������CDMAģ��(����)
//�������:
//			cmd:Ҫ���͸�ģ�������(��<CR>���ַ���)
//			timeout:���������Ӧ��ʱʱ��
//�������:	response:ģ�鷵�ص�Ӧ��
//�� �� ֵ:	
//			CDMA_SUCCESS:	����ͳɹ�
//			CDMA_RS_TIMEOUT:����Ӧ��ʱ
//			CDMA_WRITE_ERR:	д���ڳ���
//����˵��:�ú�����ȷʹ�õ�ǰ���Ǵ��������ģʽ,��ATE=1;
unsigned short CDMA_SendAtCmd(char *cmd, char *respone, long timeout );

//�� �� ��:CDMA_SetDialNum
//��    ��:�趨����ҵ�����
//�������:dial_no:����ҵ�����
//�������:respone:�豸���ص�Ӧ��
//�� �� ֵ:
//			CDMA_SUCCESS:		ִ�гɹ�
//			CDMA_RS_TIMEOUT:	����Ӧ��ʱ
//			CDMA_WRITE_ERR:		д���ڳ���
//			CDMA_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
//			CDMA_PARA_ERR:		�����������
unsigned short CDMA_SetDialNum( char *dial_no, char *respone );



//�� �� ��:	CDMA_SetIDPWD
//��    ��:	�趨����ҵ���û���������
//�������:
//			id:		�û���
//			pwd:	�û�����
//�������:	respone:�豸���ص�Ӧ��
//�� �� ֵ:
//			CDMA_SUCCESS:		ִ�гɹ�
//			CDMA_RS_TIMEOUT:	����Ӧ��ʱ
//			CDMA_WRITE_ERR:		д���ڳ���
//			CDMA_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
//			CDMA_PARA_ERR:		�����������
unsigned short CDMA_SetIDPWD( char *id, char *pwd, char *respone );

//�� �� ��:	CDMA_PPPOpen
//��    ��:	��ģ����в�������
//�������:	��
//�������:	respone:�豸���ص�Ӧ��
//�� �� ֵ:
//			CDMA_SUCCESS:		ִ�гɹ�
//			CDMA_RS_TIMEOUT:	����Ӧ��ʱ
//			CDMA_WRITE_ERR:		д���ڳ���
//			CDMA_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
//			CDMA_PARA_ERR:		�����������
unsigned short CDMA_PPPOpen( char *respone );

//�� �� ��:	CDMA_PPPClose
//��    ��:	�Ͽ���������
//�������:	��
//�������:	respone:�豸���ص�Ӧ��
//�� �� ֵ:
//			CDMA_SUCCESS:		ִ�гɹ�
//			CDMA_RS_TIMEOUT:	����Ӧ��ʱ
//			CDMA_WRITE_ERR:		д���ڳ���
//			CDMA_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
//			CDMA_PARA_ERR:		�����������
unsigned short CDMA_PPPClose( char *respone );


//�� �� ��:	CDMA_PPPStatus
//��    ��:	��ѯ��������״̬
//�������:	��
//�������:	respone:�豸���ص�Ӧ��
//			status:	
//					0-ppp closed
//					1-ppp opening
//					2-ppp opened
//�� �� ֵ:
//			CDMA_SUCCESS:		ִ�гɹ�
//			CDMA_RS_TIMEOUT:	����Ӧ��ʱ
//			CDMA_WRITE_ERR:		д���ڳ���
//			CDMA_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
//			CDMA_PARA_ERR:		�����������
unsigned short CDMA_PPPStatus( char *respone, unsigned short *status );

//�� �� ��:	CDMA_Connect
//��    ��:	����TCP ����������TCP ��ʽ��������
//�������:		
//			socket_num:	�������ӵ�socketͨ����,ȡֵ��Χ:0,1,2
//			ipaddr:		���ӵķ�������ַ
//			port:		���ӵķ������˿�
//�������:	respone:	�豸���ص�Ӧ��
//�� �� ֵ:
//			CDMA_SUCCESS:		ִ�гɹ�
//			CDMA_RS_TIMEOUT:	����Ӧ��ʱ
//			CDMA_WRITE_ERR:		д���ڳ���
//			CDMA_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
//			CDMA_PARA_ERR:		�����������
unsigned short CDMA_Connect( unsigned short socket_num, char *ipaddr, unsigned long port, char *respone );

//�� �� ��:	CDMA_IPClose
//��    ��:	�Ͽ���������
//�������:	socket_no:	TCP socketͨ��, ȡֵ��Χ:0,1,2
//�������:	respone:�豸���ص�Ӧ��
//�� �� ֵ:
//			CDMA_SUCCESS:		ִ�гɹ�
//			CDMA_RS_TIMEOUT:	����Ӧ��ʱ
//			CDMA_WRITE_ERR:		д���ڳ���
//			CDMA_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
//			CDMA_PARA_ERR:		�����������
unsigned short CDMA_IPClose( unsigned short socket_no, char *respone );

//�� �� ��:	CDMA_IPStatus
//��    ��:	��ѯTCP SOCKET �Ƿ����ӳɹ�
//�������:	socket_num:	Ҫ��ѯ��socketͨ��
//�������:	respone:�豸���ص�Ӧ��
//			status:	
//					0-���ӹر� 
//					1-��������
//					2-��������
//�� �� ֵ:
//			CDMA_SUCCESS:		ִ�гɹ�
//			CDMA_RS_TIMEOUT:	����Ӧ��ʱ
//			CDMA_WRITE_ERR:		д���ڳ���
//			CDMA_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
//			CDMA_PARA_ERR:		�����������
unsigned short CDMA_IPStatus( unsigned short socket_num, char *respone, unsigned short *status );


//�� �� ��:	CDMA_JoinDormancyTime
//��    ��:	���ý������ߵ�ʱ��
//�������:	time:PPP���ӳɹ����������ģʽ��ʱ��(sec)
//			time=0,�Ӳ���������
//�������:	respone:�豸���ص�Ӧ��
//�� �� ֵ:
//			CDMA_SUCCESS:		ִ�гɹ�
//			CDMA_RS_TIMEOUT:	����Ӧ��ʱ
//			CDMA_WRITE_ERR:		д���ڳ���
//			CDMA_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
//			CDMA_PARA_ERR:		�����������
//˵   ��:
//			��������ģʽ������;����Zdormant����������������ģʽ��CTA����һ��ʱ����
//			������ģʽ����վҲ�п��ƣ��ﵽһ��ʱ�䣬��վ�ͷ�ҵ���ŵ���
//			CTA �����ñ���������PPP ֮ǰ���á�����PPP ֮�������ã�ֻ�жϿ�����PPP ���ӣ�
//			�������Ӻ����Ч
unsigned short CDMA_JoinDormancyTime( unsigned short time, char *respone );


//�� �� ��:	CDMA_TcpSendData
//��    ��:	��TCPͨ���Ϸ�������
//�������:	
//			socket_no:	socketͨ��
//			data_len:	���͵����ݳ���
//			data:		���͵�����
//�������:	respone:	�豸���ص�Ӧ��
//			RSendLen:	ʵ�ʷ��͵ĳ���
//�� �� ֵ:
//			CDMA_SUCCESS:		ִ�гɹ�
//			CDMA_RS_TIMEOUT:	����Ӧ��ʱ
//			CDMA_WRITE_ERR:		д���ڳ���
//			CDMA_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
//			CDMA_PARA_ERR:		�����������
//			CDMA_PARSERES_ERR:  ����Ӧ�����
//��    ע: �ú���ÿ������͵����ݳ�����CDMA_MAX_SEND_LEN
unsigned short CDMA_TcpSendData( unsigned short socket_no, unsigned short data_len, unsigned char *data,unsigned short *RSendLen, char *respone );


//�� �� ��:	CDMA_GetSQ
//��    ��:	Get Signal Quality
//�������:	none
//�������:	respone:	�豸���ص�Ӧ��
//			rssi:		�ź�ǿ��
//			ber:	    ������
//�� �� ֵ:
//			CDMA_SUCCESS:	��ѯ�ɹ�
//			CDMA_RS_TIMEOUT:����Ӧ��ʱ
//			CDMA_WRITE_ERR:	д���ڳ���
//			CDMA_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
unsigned short CDMA_GetSQ( char *respone, unsigned short *rssi );

//�� �� ��:	CDMA_NetRegReport
//��    ��:	��ѯCDMA����ע��״̬
//�������:	none
//�������:	respone:	�豸���ص�Ӧ��
//		rssi:	
//			0: δע��,����ģ�鵱ǰ����Ѱ�µ���Ӫ��
//			1: ��ע�᱾������
//			2��δע��,�ն�������Ѱ��վ
//			4��ע�ᱻ�ܾ�
//			5����ע��,���Ҵ�������״̬
//�� �� ֵ:
//			CDMA_SUCCESS:		��ѯ�ɹ�
//			CDMA_RS_TIMEOUT:	����Ӧ��ʱ
//			CDMA_WRITE_ERR:		д���ڳ���
//			CDMA_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
//			CDMA_PARSERES_ERR:	����Ӧ�����
unsigned short CDMA_NetRegReport( char *respone, unsigned short *status );

//�� �� ��:	CDMA_IPReceive
//��    ��:	�����豸��ָ����SOCKETͨ�����ص�����
//�������:	timeout:���ճ�ʱʱ��
//�������:	respone:	�豸���ص�Ӧ��
//			data:		���յ�������
//			rev_len:	���յ������ݳ���
//�� �� ֵ:
//			CDMA_SUCCESS:		��ѯ�ɹ�
//			CDMA_RS_TIMEOUT:	����Ӧ��ʱ
//			CDMA_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
unsigned short CDMA_IPReceive( unsigned char *data,  unsigned short *rev_len, unsigned short timeout, char *respone );



//	�� �� ��: CDMA_Get_PwrOn_Rs
//	��    ��: ȡCDMAģ����ϵ�Ӧ��
//	ȫ�ֱ���: ��
//	�������: timeout:��usΪ��λ
//	�������: Respone
//	�� �� ֵ: �ɹ�����0, ����-ʧ��
//	��    ��: �� ־ ��
//	��������: 2009/7/25
//	�� �� ��: 
//	�޸�����: 
//	��    ע: ����CDMAģ����ϵ�ʱ����:+ZIND:8 ��+ZIND:1,�õ�������غ���ܽ���ATָ��
unsigned short CDMA_Get_PwrOn_Rs( long timeout, char *Respone );




//	�� �� ��: CDMA_SetPPP_ReDial
//	��    ��: ����PPP�����ز�.
//	ȫ�ֱ���: ��
//	�������: time: 0-���ز�, ����ֵΪ�ز���϶,����Ϊ��λ, timeout:ָ�ʱʱ��
//	�������: respone:ģ�鷵�ص�Ӧ��
//	�� �� ֵ: 0-�ɹ�, ����-ʧ��
//	��    ��: �� ־ ��
//	��������: 2009/7/25
//	�� �� ��: 
//	�޸�����: 
//	��    ע: 
unsigned short CDMA_SetPPP_ReDial( unsigned short time, char *respone );




//	�� �� ��: CDMA_Set_EnableKeepOnLine
//	��    ��: ���û��߹رձ������߹���
//	ȫ�ֱ���: ��
//	�������: YesOrNot:0-�ر�,  1-���� 
//	�������: respone:ģ�鷵�ص�Ӧ��
//	�� �� ֵ: 0-�ɹ�, ����-ʧ��
//	��    ��: �� ־ ��
//	��������: 2009/7/25
//	�� �� ��: 
//	�޸�����: 
//	��    ע: 
unsigned short CDMA_Set_EnableKeepOnLine( unsigned short YesOrNot, char *respone );


//	�� �� ��: CDMA_Set_VKLStatus
//	��    ��: ���ý�������ģʽ
//	ȫ�ֱ���: ��
//	�������: 
//			  mode=0:�����������߹���
//			  mode=1:ʵ����ģʽ
//			  mode=2:Զ����ģʽ	 
//			  mode=3:��ѯ����ģʽ
//			  mode=4:���ý���������ģʽʱ��
//			  ��mode=4ʱ, timeΪ��������ģʽ��ʱ��
//			  time:(0~255)//sec
//	�������: 
//	�� �� ֵ: �ɹ�-0, ����-����
//	��    ��: �� ־ ��
//	��������: 2009/7/25
//	�� �� ��: 
//	�޸�����: 
//	��    ע: 
unsigned short CDMA_Set_VKLStatus( unsigned short mode, unsigned short time, char * respone );


//�� �� ��:CDMA_DeviceInit
//�������:scom:��ģ��ͨѶ�Ĵ��ں�
//�������:��
//�� �� ֵ:
// CDMA_SUCCESS						0
// CDMA_RS_TIMEOUT 					0xFF	//�����豸���س�ʱ
// CDMA_WRITE_ERR					0xFE	//д���ڳ���
// CDMA_READ_ERR					0xFD	//�����ڳ���
// CDMA_PARA_ERR					0xFC	//����Ĳ�������
// CDMA_EXECUTE_ERR					0xFB	//ִ������ʧ��
// CDMA_PARSERES_ERR				0xFA  	//����Ӧ�����
// CDMA_OPEN_SERIALPORT_ERR			0xF9	//��CDMA���ڳ���		
unsigned short CDMA_DeviceInit(void);

/*================================================================================================*
	�� �� ��: CDMA_Inquiry_ZIND
	��    ��: ��ѯģ��ָʾ�������
	ȫ�ֱ���: ��
	�������: ��
	�������: 
	�� �� ֵ: �ɹ�-0, ����-����
	��    ��: �� ־ ��
	��������: 2009/7/25
	�� �� ��: 
	�޸�����: 
	��    ע: 
*================================================================================================*/
unsigned short CDMA_Inquiry_ZIND( int *val, char * respone );


/*================================================================================================*
	�� �� ��: CDMA_Set_ZIND
	��    ��: ��ѯģ��ָʾ�������
	ȫ�ֱ���: ��
	�������: ��
	�������: 
	�� �� ֵ: �ɹ�-0, ����-����
	��    ��: �� ־ ��
	��������: 2009/7/25
	�� �� ��: 
	�޸�����: 
	��    ע: 
*================================================================================================*/
unsigned short CDMA_Set_ZIND( int val, char * respone );


//�� �� ��:CDMA_ATTest
//��    ��: ����ָ��AT,�����Ƿ�����ģ������ͨѶ
//�������: ��
//�������:	respone:	�豸���ص�Ӧ��
//�� �� ֵ:	
//			CDMA_SUCCESS:	����ͳɹ�
//			CDMA_RS_TIMEOUT:����Ӧ��ʱ
//			CDMA_WRITE_ERR:	д���ڳ���
//			CDMA_EXECUTE_ERR:ִ������ʧ��
unsigned short CDMA_ATTest(  char *respone );



//�� �� ��: CDMA_InqCPIN
//��    ��: ����Ƿ���Ҫ���������豸������������
//ȫ�ֱ���: ��
//�������: Respone
//�� �� ֵ: �ɹ�����0, ����-ʧ��
//��    ��: �� ־ ��
//��������: 2009/7/25
//�� �� ��: 
//�޸�����: 
//��    ע: ͨ����������Ƿ������SIM��
unsigned short CDMA_InqCPIN( char *respone );


//�� �� ��:	CDMA_CmdEcho
//��    ��:	ʹ�ø����������TA ������״̬���Ƿ���Դ�TE ���յ����ַ�
//�������:	val
//			1:���Է�ʽ����, 0:���Է�ʽ�ر�
//�������:	respone:	�豸���ص�Ӧ��
//�� �� ֵ:
//			CDMA_SUCCESS:		���óɹ�
//			CDMA_RS_TIMEOUT:	����Ӧ��ʱ
//			CDMA_WRITE_ERR:		д���ڳ���
//			CDMA_EXECUTE_ERR:	����ʧ��,ԭ��μ�response
unsigned short CDMA_CmdEcho( unsigned short val, char *respone );

#endif
