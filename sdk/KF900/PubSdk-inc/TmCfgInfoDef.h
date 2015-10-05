/***********************************************************************************************************
 *
 * @FILENAME		: TmCfgInfoDef.h
 *
 * @AUTHOR  		: zjwu
 *
 * @DATE	  		: 2009-8-26
 *
 * @DESCRIPTION		: 
 *
 * @COPYRIGHT		: 2009-2012 ShenZhen KAIFA Technology Co.,Ltd.
 *
 ***********************************************************************************************************/

#ifndef _FACTORYDEF_H_
#define _FACTORYDEF_H_

//�벻Ҫ�޸�����Ķ���
#define HARD_DEVICE_SERIAL_0				0x00000001 			//����0
#define HARD_DEVICE_SERIAL_1				0x00000002			//����1
#define HARD_DEVICE_SERIAL_2				0x00000004			//����2
#define HARD_DEVICE_SERIAL_3				0x00000008			//����3
#define HARD_DEVICE_NETWORK_MOUDLE			0x00000010			//����
#define HARD_DEVICE_GPRS_MODULE				0x00000020			//gprsģ��
#define HARD_DEVICE_CDMA_MODULE				0x00000040			//CDMAģ��
#define HARD_DEVICE_MODEM_MOUDLE			0x00000080			//����modem
#define HARD_DEVICE_PRINTER					0x00000100			//��ӡ��

#define TMC_OPEN_FILE_FAILURE	-1		//���ն�Ӳ�������ļ�ʧ��
#define TMC_READ_FILE_FAILURE	-2		//��ȡ�ն�Ӳ�������ļ�ʧ��
#define TMC_WRITE_FILE_FAILURE	-3		//д�ն�Ӳ�������ļ�ʧ��
#define TMC_CREAT_FILE_FAILURE	-4		//�����ն�Ӳ��������Ϣ�ļ�ʧ��

#define KEYBEEP_ON	1
#define KEYBEEP_OFF	0

#define MAX_DELAY_TIME	999


#define DEFAULT_LCDBACKLIGHT_DELAY_TIME		60					//Ĭ��lcd��������ʱ�ر�ʱ��

#define MOUDLE_EXIST		1
#define MOUDLE_NOT_EXIST	0

//�� �� ��: TMC_IfExistGprsMoudle
//��    ��: �ж��ն�Ӳ���Ƿ���GPRSͨѶģ��
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ: 
//			TMC_OPEN_FILE_FAILURE	:���ն�Ӳ�������ļ�ʧ��
//			TMC_READ_FILE_FAILURE	:��ȡ�ն�Ӳ�������ļ�ʧ��			
//			MOUDLE_EXIST			:ģ�����
// 			MOUDLE_NOT_EXIST		:ģ�鲻����
//��    ��: �� ־ ��
//��������: 2009/8/26
//�� �� ��: 
//�޸�����: 
//��    ע: 
int TMC_IfExistGprsMoudle(void);


//�� �� ��: TMC_IfExistCdmaMoudle
//��    ��: �ж��ն�Ӳ���Ƿ���CDMAͨѶģ��
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ: 
//			TMC_OPEN_FILE_FAILURE	:���ն�Ӳ�������ļ�ʧ��
//			TMC_READ_FILE_FAILURE	:��ȡ�ն�Ӳ�������ļ�ʧ��			
//			MOUDLE_EXIST			:ģ�����
// 			MOUDLE_NOT_EXIST		:ģ�鲻����
//��    ��: �� ־ ��
//��������: 2009/8/26
//�� �� ��: 
//�޸�����: 
//��    ע: 
int TMC_IfExistCdmaMoudle(void);



//�� �� ��: TMC_IfExistModemMoudle
//��    ��: �ж��ն�Ӳ���Ƿ���MODEMͨѶģ��
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ: 
//			TMC_OPEN_FILE_FAILURE	:���ն�Ӳ�������ļ�ʧ��
//			TMC_READ_FILE_FAILURE	:��ȡ�ն�Ӳ�������ļ�ʧ��			
//			MOUDLE_EXIST			:ģ�����
// 			MOUDLE_NOT_EXIST		:ģ�鲻����
//��    ��: �� ־ ��
//��������: 2009/8/26
//�� �� ��: 
//�޸�����: 
//��    ע: 
int TMC_IfExistModemMoudle(void);



//�� �� ��: TMC_IfExistNetWorkMoudle
//��    ��: �ж��ն�Ӳ���Ƿ�������
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ: 
//			TMC_OPEN_FILE_FAILURE	:���ն�Ӳ�������ļ�ʧ��
//			TMC_READ_FILE_FAILURE	:��ȡ�ն�Ӳ�������ļ�ʧ��			
//			MOUDLE_EXIST			:ģ�����
// 			MOUDLE_NOT_EXIST		:ģ�鲻����
//��    ��: �� ־ ��
//��������: 2009/8/26
//�� �� ��: 
//�޸�����: 
//��    ע: 
int TMC_IfExistNetWorkMoudle(void);


//�� �� ��: TMC_IfExistBatteryMoudle
//��    ��: �ж��ն�Ӳ���Ƿ��е��
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ: 
//			TMC_OPEN_FILE_FAILURE	:���ն�Ӳ�������ļ�ʧ��
//			TMC_READ_FILE_FAILURE	:��ȡ�ն�Ӳ�������ļ�ʧ��			
//			MOUDLE_EXIST			:ģ�����
// 			MOUDLE_NOT_EXIST		:ģ�鲻����
//��������: 2012/6/26
//�� �� ��: 
//�޸�����: 
//��    ע: 
int TMC_IfExistBatteryMoudle(void);


//�� �� ��: GetLcdBackLightDelayTime
//��    ��: ��ȡLcd������ʱʱ��
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ: 
//			TMC_OPEN_FILE_FAILURE	:���ն�Ӳ�������ļ�ʧ��
//			TMC_READ_FILE_FAILURE	:��ȡ�ն�Ӳ�������ļ�ʧ��			
//			����ֵ					:��ǰ�����ļ���lcd������ʱʱ��					
//��    ��: �� ־ ��
//��������: 2009/8/26
//�� �� ��: 
//�޸�����: 
//��    ע: 
int GetLcdBackLightDelayTime(void);


//�� �� ��: SetLcdBackLightDelayTime
//��    ��: ��ȡLcd������ʱʱ��
//ȫ�ֱ���: ��
//�������: time:������ʱʱ��(����Ϊ��λ)
//�������: ��
//�� �� ֵ: 
//			TMC_OPEN_FILE_FAILURE	:���ն�Ӳ�������ļ�ʧ��
//			TMC_READ_FILE_FAILURE	:��ȡ�ն�Ӳ�������ļ�ʧ��			
//			TMC_WRITE_FILE_FAILURE	:д�����ļ�ʧ��		
//			0						:�ɹ�			
//��    ��: �� ־ ��
//��������: 2009/8/26
//�� �� ��: 
//�޸�����: 
//��    ע: 
//int SetLcdBackLightDelayTime(int time);




#endif





