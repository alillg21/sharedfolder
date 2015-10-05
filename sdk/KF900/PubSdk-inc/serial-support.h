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




//���к궨���������,���������޸�
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



//�� �� ��: SCOM_Open
//��    ��: ��Speedָ�����ٶȴ�ComNoָ���Ĵ��ں�
//ȫ�ֱ���: ��
//�������: 
//			ComNo:	���ں�, �䶨��ķ�ΧΪserila-support.h�ļ��ж����COM0~MAX_COM_NO, ������Χ������PARA_PORT_NO_ERR
//			Speed:	����ֵ, ������������ֵ֮һ:
//					230400, 115200, 57600, 38400, 19200, 9600, 4800, 2400, 1800, 1200, 600, 300, 200
//					Speed��������֮һ�Ƿ���PARA_SPEED_ERR����	
//			Vtime:	���������ݳ�ʱʱ��, ��0.1��Ϊ��λ.
//�������: ��
//�� �� ֵ: 
//			PARA_PORT_NO_ERR:���������, ���ںų�����Χʱ����.
//			PARA_SPEED_ERR:	 ���������, �ٶȲ�������ʱ����.  
//			OPEN_SERIAL_PORT_ERR:�򿪴���ʧ��
//			0:��ָ���Ĵ��ڳɹ�.
//��    ��: �� ־ ��
//��������: 2009/9/01
//�� �� ��: 
//�޸�����: 
//��    ע: �ú����ԷǱ�׼����ģʽ�򿪴���.������������:
//			N81, ������
//			������żУ��
//			Raw ģʽ���
//			������
int SCOM_Open(unsigned int ComNo, unsigned int Speed, unsigned int Vtime);


//�� �� ��: SCOM_Read
//��    ��: ����������,����ָ���Ĵ����ж���rdlen���ȵ����ݵ�buffer��,ʵ�ʶ�ȡ���������Է���ֵΪ׼.
//ȫ�ֱ���: ��
//�������: 
//			ComNo:���ں�, ������serila-support.h�ļ���ָ���Ĵ��ں�֮һ
//			rdlen:������ȡ�����ݳ���
//�������: buffer
//�� �� ֵ: ����ɹ�,������ʵ�ʶ�ȡ�������ݳ���,���ʧ��,����-1
//��    ��: �� ־ ��
//��������: 2009/9/02
//�� �� ��: 
//�޸�����: 
//��    ע: 
int SCOM_Read( unsigned int ComNo, void *buffer, unsigned int rdlen );


//�� �� ��: SCOM_Write
//��    ��: ��ComNoָ���Ĵ���д��buffer�е�����, д������ݳ���Ϊwrlen
//ȫ�ֱ���: ��
//�������: 
//			ComNo:���ں�,������serila-support.h�ļ��ж����ֵ
//			bufferҪд�������
//			Ҫд������ݳ���
//�������: ��
//�� �� ֵ: ����ɹ�,����ʵ��д������ݳ���.ʧ�ܷ���-1
//��    ��: �� ־ ��
//��������: 2009/9/02
//�� �� ��: 
//�޸�����: 
//��    ע: 
int SCOM_Write( unsigned int ComNo, void *buffer, unsigned int wrlen );



//�� �� ��: SCOM_Close
//��    ��: �ر�ComNoָ���Ĵ���
//ȫ�ֱ���: ��
//�������: ComNo:���ں�,������serila-support.h�ļ��ж���Ĵ���(COM0~MAX_COM_NO)֮һ
//�������: ��
//�� �� ֵ: �رճɷַ���0, ʧ�ܷ���-1
//��    ��: �� ־ ��
//��������: 2009/9/02
//�� �� ��: 
//�޸�����: 
//��    ע: 
int SCOM_Close( unsigned int ComNo );


//�� �� ��: SCOM_Clear
//��    ��: ������ڻ���
//ȫ�ֱ���: ��
//�������: ComNo:���ں�,������serila-support.h�ļ��ж����ֵ
//�������: ��
//�� �� ֵ: ��
//��    ��: �� ־ ��
//��������: 2009/9/02
//�� �� ��: 
//�޸�����: 
//��    ע: 
void SCOM_Clear(unsigned int ComNo );

#endif





