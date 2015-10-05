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

#define MDM_STATUS_NOTINIT_POWEROFF_ON		0x00 //modem�ϵ���ϵ�//zsp add
#define MDM_STATUS_NOT_INIT				0x11		//modemδ��ʼ��
#define MDM_STATUS_IDLE						0x12		//modem����
#define MDM_STATUS_DIALING				0x13		//modem������
#define MDM_STATUS_ON_LINE				0x16		//modem��������״̬
#define MDM_STATUS_ON_HOOKING			0x17		//modem���ڹһ�
#define MDM_STATUS_INVALID				0x18		//modemʧЧ״̬


#define MDM_MSG_OPE_SUCCESS				0x00		//modem�����ɹ�
#define	MDM_MSG_TIMEOUT						0x01		//modem������ʱ
#define MDM_MSG_DIAL_NUM_IS_EMPTY	0x02		//���ź���Ϊ��
#define MDM_MSG_NO_LINE						0x03		//δ��⵽�绰��
#define MDM_MSG_LINE_BE_USING			0x04		//��·ʹ����
#define MDM_MSG_PARALLEL_OFFHOOK	0x05		//����ժ��
#define MDM_MSG_REVERSAL					0x06		//Զ�˹һ�
#define MDM_MSG_NO_DIALTONE				0x07		//û�м�⵽������
#define	MDM_MSG_BUSYTONE					0x08		//æ��
#define MDM_MSG_NO_ANSWERTONE			0x09		//��Ӧ����
#define	MDM_MSG_LOST_CARRIER			0x0A		//�ز���ʧ
#define MDM_MSG_DIAL_FAIL					0x0B		//һ�㲦�ų���
#define	MDM_MSG_RX_READY					0x10		//modem�ɶ�
#define MDM_MSG_TX_READY					0x20		//modme��д
#define MDM_MSG_RTX_READY					0x30		//modem�ɶ�д
#define MDM_MSG_COMM_ERR					0x40		//ͨѶ���ݳ���
#define MDM_HD_ERR								0xEE		//hdͨѶ��
#define MDM_CANNOT_DEAL_THIS_CMD	0xDD		//modem���ܴ����ָ��
#define MDM_TRANSFER_TIMEOUT			0xFE		//modemͨѶ��ʱ
#define MDM_OPERATOR_FAILURE			-1			//����modemʧ��	


//�� �� ��: MDM_Open
//��    ��: ��modem�豸
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ: 
//			0			:�ɹ�
//			0xEE		:hdͨѶ����
//			-1			:��modemʧ��
//��    ��: �� ־ ��
//��������: 2010/4/08
//�� �� ��: ��־��
//�޸�����: 
//��    ע: 
int MDM_OpenDevice(void);


//�� �� ��: MDM_Nor_Dial
//��    ��: ʵ��modemͬ������,ָ��Ԥ����ģʽ
//ȫ�ֱ���: ��
//�������: 
//			tel_no	: �绰����(��0��β���ַ���)
//�������: ��
//�� �� ֵ: 
//			0x01 	���ͻ������ѱ�ռ�á�
//			0x02 	���õ绰��ռ�á�
//			0x03 	���ߵ绰ռ�û��޲�������
//			0x04   	�ز��Ѷ�ʧ
//			0x05   	��Ӧ����
//			0x06 	����ʧ�ܣ�����ԭ�򣩡�
//			0x07 	δ��绰���롣
//			0x08��	���ջ������ǿ�
//			0x09��	���ͻ������ѱ�ռ�úͽ��ջ������ǿ�
//			0x0a��	���ڲ�����
//			0x0b��	�ѹһ�/����
//			0x0d��	���е绰æ
//			0x13:	modem�������ӳɹ�
//			0xfd: 	CLEAR������(Modem����ֹ���Ų���)��
//			
//			����ֵ	�����������⹫������
//��    ��: �� ־ ��
//��������: 2010/4/08
//�� �� ��: 
//�޸�����: 
//��    ע: 
int MDM_Nor_Dial(char *tel_no );


//�� �� ��: MDM_Pre_Dial
//��    ��: Ԥ���ź���,ִ�иú�������������,���ղ��ŵĽ����Ҫͨ��MDM_GetModemStatusȡ��.
//ȫ�ֱ���: ��
//�������: tel_no:	�绰����
//�������: ��
//�� �� ֵ: 
//			0x00	//Modem�������
//			0xEE	//HDͨѶ����
//			0xDD	//modem�޷���Ӧ������
//			0xF9	//����modem�߳�ʧ��
//			-1		//����modemʧ��
//��    ��: �� ־ ��
//��������: 2010/4/27
//�� �� ��: 
//�޸�����: 
//��    ע: 
int MDM_Pre_Dial( char *tel_no );


//�� �� ��: MDM_GetModemStatus
//��    ��: ȡ��ǰmodem״̬
//ȫ�ֱ���: ��
//�������: ��
//�������: modem_info,�京������:
//			0x00 	//�����ɹ�
//			0x01	//��ʱ
//			0x02 	//δ��绰���롣
//			0x03	//�绰��·δ���Ӻ�
//			0x04	//�绰��·��ռ��
//			0x05	//���ߵ绰�ն�ժ����
//			0x06	//Զ�˹һ��Ͽ�
//			0x07 	//���ߵ绰ռ�û��޲�����
//			0x08	//���е绰æ
//		   	0x09   	//��Ӧ����
//			0x0A	//�ز��Ѷ�ʧ
//			0x0B 	//����ʧ�ܣ�����ԭ�򣩡�
//	
//			0x10	//���ջ������ǿ�,�ȴ�host������,��׼����
//			0x20 	//���ͻ������ѿ�,�ȴ�hostд����,д׼����
//			0x30	//���ͻ������ѿպͽ��ջ������ǿ�, ��д׼����
//			0x40	//ͨѶ�����ݴ������
//��    �أ�	
//			0x11		modemδ��ʼ��
//			0x12		modem����״̬
//			0x13		modem������
//			0x16		modem����
//			0x17		modem�һ���
//			0x18		modemʧЧ
//			0xEE		hdͨѶ����
//			-1			����modemʧ��
//��    ��: �� ־ ��
//��������: 2010/4/10
//�� �� ��: 
//�޸�����: 
//��    ע: 
int MDM_GetModemStatus(int *modem_info );



//�� �� ��: MDM_Read
//��    ��: ����modem��������
//ȫ�ֱ���: ��
//�������: timeout	:ͨѶ��ʱʱ��(sec)
//�������: 
//			data:��Ž�������buf��ָ��
//			length:��Ž��յ������ݳ��ȵ�ָ��
//�� �� ֵ: 
//			0x00										//�ɹ�
//			MDM_MSG_LOST_CARRIER			0x0A		//�ز���ʧ
//			MDM_MSG_COMM_ERR			0x40		//ͨѶ����
//			MDM_TRANSFER_TIMEOUT			0xFE		//ͨѶ��ʱ
//			MDM_OPERATOR_FAILURE			-1			//����modemʧ��
//��    ��: �� ־ ��
//��������: 2010/4/10
//�� �� ��: 
//�޸�����: 
//��    ע: �ú���Ϊ��������
int MDM_Read(unsigned char * data, int *length, int timeout );



//�� �� ��: MDM_Write
//��    ��:	ͨ��modem��������
//ȫ�ֱ���: ��
//�������: 
//			data	:���Ҫ��������buf��ָ��
//			length	:Ҫ���͵����ݵĳ���
//�������: 
//�� �� ֵ: 
//			0x00										//�ɹ�
//			MDM_MSG_LOST_CARRIER			0x0A		//�ز���ʧ
//			MDM_MSG_COMM_ERR				0x40		//ͨѶ����
//			MDM_HD_ERR					0xEE		//hdͨѶ����
//			MDM_OPERATOR_FAILURE			-1			//����modemʧ��
//��    ��: �� ־ ��
//��������: 2010/4/10
//�� �� ��: 
//�޸�����: 
//��    ע: 
int MDM_Write(unsigned char *data, int length );



//�� �� ��: MDM_Hook
//��    ��: ȡ��modem����
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ: 
//			0x00	:�ɹ����յ�modem�һ�ָ��
//			-1		:����modemʧ��
//��    ��: �� ־ ��
//��������: 2010/4/10
//�� �� ��: 
//�޸�����: 
//��    ע: �һ������Ҫͨ��MDM_GetModemStatus��������ѯ
int MDM_Hook(void);


//�� �� ��: MDM_CloseDevice
//��    ��: �ر�modem�豸
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ: 
//			 0		:�ɹ�
//			-1		:�ر�modemʧ��	
//��    ��: �� ־ ��
//��������: 2010/4/10
//�� �� ��: 
//�޸�����: 
//��    ע: 
int MDM_CloseDevice(void);



//�� �� ��: MDM_Reset
//��    ��: modem��λ
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ: 			0		-��λ�ɹ�
//				-1		-��λʧ��
//��    ��: �� ־ ��
//��������: 2010/5/27
//�� �� ��: 
//�޸�����: 
//��    ע: 
int MDM_Reset(void);


#endif




