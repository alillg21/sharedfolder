#ifndef _PWR_SUPPORT_H_
#define _PWR_SUPPORT_H_

#define WM_POWER_ON  				"100"
#define WM_POWER_OFF				"101"
#define WM_POWER_RESET			"102"
#define WM_CHANN_ENABLE  		"103"
#define WM_CHANN_DISABLE  	"104"
	

#define OPEN_PWR_DEV_ERR 	-1
#define CLOSE_PWR_DEV_ERR	-2
#define READ_PWR_DEV_ERR	-3
#define WRITE_PWR_DEV_ERR	-4




//	#define WIFIOFF		105
//	#define WIFION		106
//	#define WIFI_RST  	107
//	#define SELHDMI  	108
//	#define SELBT  		109
//	#define ENBTCMD		110
//	#define DISBTCMD	111
//	#define BT_RST  	112


//status= 0-�޵�, 1=1/4����, 2=2/4����, 3=3/4����, 4=������, 0xFF-��ӵ�Դ, 0xFE-���ڳ��
#define BAT_VAL0 	0
#define BAT_VAL1 	1
#define BAT_VAL2 	2
#define BAT_VAL3 	3
#define BAT_VAL4 	4
#define BAT_DC		0xFF
#define BAT_CHARGE 	0xFE


//�� �� ��:	PWR_GetHandle
//��    ��:	ȡ��Դ�豸���,
//�������:	��
//�������:	��
//�� �� ֵ:
//			-1:��ʾ��Դ�豸�ļ����ڹر�״̬
//			>-1:��ʾ��Դ�豸�򿪺�ľ��ֵ
int PWR_GetHandle(void);


//�� �� ��:	PWR_CloseDevice
//��    ��:	�رյ�Դ�豸���,
//�������:	��
//�������:	��
//�� �� ֵ: 
//			0:�ɹ��رյ�Դ�豸
//			CLOSE_PWR_DEV_ERR:�رյ�Դ�豸ʧ��
int PWR_CloseDevice(void);




//�� �� ��:	PWR_OpenDevice
//��    ��:	�򿪵�Դ�豸���,
//�������:	��
//�������:	��
//�� �� ֵ: 
//			>=0:�ɹ��򿪵�Դ�豸,����ֵΪ���豸�󷵻صľ��
//			OPEN_PWR_DEV_ERR:�򿪵�Դ�豸ʧ��.
int PWR_OpenDevice(void);


//�� �� ��: PWR_GetBatteryStatus
//��    ��: ȡ���״̬
//ȫ�ֱ���: ��
//�������: 
//�������: status= 0-�޵�, 1=1/4����, 2=2/4����, 3=3/4����, 4=������, 0xFF-��ӵ�Դ, 0xFE-���ڳ��
//�� �� ֵ: 
//			0-�ɹ�
//			OPEN_PWR_DEV_ERR:�򿪵�Դ�豸ʧ��
//			READ_PWR_DEV_ERR:����Դ�豸ʧ��
//��    ��: �� ־ ��
//��������: 2009/7/13
//�� �� ��: 
//�޸�����: 
//��    ע: 
int PWR_GetBatteryStatus(unsigned char *status );


//�� �� ��: PWR_WM_PowerOn
//��    ��: ����ģ���ϵ�
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ: 
//			0:�ɹ�
//			OPEN_PWR_DEV_ERR:�򿪵�Դ�豸ʧ��
//			WRITE_PWR_DEV_ERR:д��Դ�豸ʧ�� 
//��    ��: �� ־ ��
//��������: 2009/7/06
//�� �� ��: 
//�޸�����: 
//��    ע: 
int PWR_WM_PowerOn(void);


//�� �� ��: PWR_WM_PowerOff
//��    ��: ����ģ���µ�
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ: 
//			0:�ɹ�
//			OPEN_PWR_DEV_ERR:�򿪵�Դ�豸ʧ��
//			WRITE_PWR_DEV_ERR:д��Դ�豸ʧ�� 
//��    ��: �� ־ ��
//��������: 2009/7/06
//�� �� ��: 
//�޸�����: 
//��    ע: 
int PWR_WM_PowerOff(void);



//�� �� ��: PWR_WM_PowerReset
//��    ��: ����ģ���µ�
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ: 
//			0:�ɹ�
//			OPEN_PWR_DEV_ERR:�򿪵�Դ�豸ʧ��
//			WRITE_BATTERY_ERR:д��Դ�豸ʧ�� 
//��    ��: �� ־ ��
//��������: 2009/7/06
//�� �� ��: 
//�޸�����: 
//��    ע: ֻ��������ģ��Power on״̬��, �ú����Ż�ʵ��������
int PWR_WM_PowerReset(void);



//�� �� ��: PWR_WM_ChannEnable
//��    ��: ��������ģ��ͨ��,ֻ�иú����ɹ����ú�,����ģ����ܳɹ��յ�ATָ��
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ: 
//			0:�ɹ�
//			OPEN_PWR_DEV_ERR:�򿪵�Դ�豸ʧ��
//			WRITE_PWR_DEV_ERR:д��Դ�豸ʧ�� 
//��    ��: �� ־ ��
//��������: 2009/7/06
//�� �� ��: 
//�޸�����: 
//��    ע: ֻ��������ģ��Power on״̬��, �ú����Ż�ʵ��������
int PWR_WM_ChannEnable(void);



//�� �� ��: PWR_WM_ChannDisable
//��    ��: �ر�����ģ��ͨ��,�رպ�,����ģ�齫�ղ���ATָ��
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ: 
//			0:�ɹ�
//			OPEN_PWR_DEV_ERR:�򿪵�Դ�豸ʧ��
//			WRITE_PWR_DEV_ERR:д��Դ�豸ʧ�� 
//��    ��: �� ־ ��
//��������: 2009/7/06
//�� �� ��: 
//�޸�����: 
//��    ע:
int PWR_WM_ChannDisable(void);



#endif


