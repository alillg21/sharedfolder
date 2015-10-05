#include "kbd_define.h"
#include "PosModel.h"

#ifndef __KEYMAP_H__
#define __KEYMAP_H__


//��������������ֽ����ֽ
#ifdef KBD_5				//�ٶ�K5Ϊ��ʽ��ӡ��
#define KEY_FEED 0xFF
#define KEY_ROLLBACK 0xFE
#endif

#define KEY_0	'0'
#define KEY_1	'1'
#define KEY_2	'2'
#define KEY_3	'3'
#define KEY_4	'4'
#define KEY_5	'5'
#define KEY_6	'6'
#define KEY_7	'7'
#define KEY_8	'8'
#define KEY_9	'9'
#define KEY_00			0xFA
#define KEY_PLUS		0xFB
#define KEY_MINUS		0xFC
#define NULL_KEY 		0x00

#define KEY_ESC       0x81
#define KEY_BACK      0x82
#define KEY_ENTER     0x84	

#define KEY_HOME      0x92
#define KEY_END       0x93
#define KEY_UP        0x94
#define KEY_DOWN      0x95

#ifdef POS_KF600
  #define KEY_F1            0xA0
  #define KEY_F2            0xA1
  #define KEY_F3            0xA2
  #define KEY_F4            0xA4

  #define KEY_LEFT        KEY_F1
  #define KEY_RIGHT       KEY_F4
#else
#define KEY_LEFT      0x96
#define KEY_RIGHT     0x97
#endif

#define KEY_PGUP      KEY_MENU
#define KEY_PGDN      KEY_FUNC

#define KEY_CLEAR     0x9a
#define KEY_MENU      0x9d
#define KEY_FUNC      0x9E


#define KEY_TAB     	0xb1			//���뷨/�л���
#define KEY_SHIFT_REV   KEY_SELLER		//�����л�,����[ӪҵԱ��]


//��ϼ�����
#define UNKEY_TAB1		0xD1			//��ϼ�Tab+1
#define UNKEY_TAB2		0xD2			//��ϼ�Tab+2
#define UNKEY_10		0xD3			//��ϼ�1+0
#define UNKEY_ENTER1	0xD4			//��ϼ�ENTER+1




//�� �� ��: Set_bklt_dtime
//��    ��: ���ñ�������ʱ�ر�ʱ��
//ȫ�ֱ���: ��
//�������: time
//			=0��ʾ�����Ƴ���
//			=1��ʾ�����Ƴ���
//			>1��ʾ�޶���ʱ��������ʱ�رյ�ʱ��(����Ϊ��λ)
//�������: ��
//�� �� ֵ: ��
//��    ��: �� ־ ��
//��������: 2009/8/26
//�� �� ��: 
//�޸�����: 
//��    ע: 
void Set_bklt_dtime(unsigned short time);


//�� �� ��: Get_bklt_dtime
//��    ��: ���ص�ǰ��������ʱ�ر������õ�ʱ��ֵ.
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ: 0-��ʾ����������Ϊ����
//			1-��ʾ����������Ϊ����
//			>1-��ʾ�޶���ʱ��ʱ�رյ�ʱ��ֵ(����Ϊ��λ)
//��    ��: �� ־ ��
//��������: 2009/8/26
//�� �� ��: 
//�޸�����: 
//��    ע: 
unsigned short Get_bklt_dtime(void);


//�� �� ��: back_light_contorl
//��    ��: �μ�sigfcn����������
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ: ��
//��    ��: �� ־ ��
//��������: 2009/8/26
//�� �� ��: 
//�޸�����: 
//��    ע: 
void back_light_contorl(void);


//�� �� ��: LcdBackLightInit
//��    ��: �������ļ��ж�ȡ��������ʱ����ֵ.ͬʱ�򿪱�����.
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ: ��
//��    ��: �� ־ ��
//��������: 2009/8/26
//�� �� ��: 
//�޸�����: 
//��    ע: 
void LcdBackLightInit(void);


//�� �� ��: getch
//��    ��: ���ص�ǰ�Ӽ��̶����ļ���.
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ: ��ǰ����.
//��    ��: �� ־ ��
//��������: 2009/8/26
//�� �� ��: 
//�޸�����: 
//��    ע: �ް���ʱ����0, �������0x80(��ʾ�ɿ�����)ʱ����0
unsigned char getch(void);


//�� �� ��: getkey
//��    ��: ���ص�ǰ�Ӽ��̶����ļ�ֵ.
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ: keymap.h����ļ�ֵ.
//��    ��: �� ־ ��
//��������: 2009/8/26
//�� �� ��: 
//�޸�����: 
//��    ע: �ް���ʱ����0
unsigned char getkey(void);


//�� �� ��: press_key
//��    ��: ������ֱ���а���ʱ�ŷ��ؼ�ֵ.
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ: keymap.h����ļ�ֵ.
//��    ��: �� ־ ��
//��������: 2009/8/26
//�� �� ��: 
//�޸�����: 
//��    ע: 
unsigned char press_key(void);


//�� �� ��: key2asc
//��    ��: �����뷭��ɰ���ֵ.
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ: keymap.h����ļ�ֵ
//��    ��: �� ־ ��
//��������: 2009/8/26
//�� �� ��: 
//�޸�����: 
//��    ע: 
unsigned char key2asc(unsigned char keycode);


//�� �� ��: sigfcn
//��    ��: �����ǰlcd��������ʱ���ƿ��ز�������Ϊ����,���øú�����򿪱�����,
//			ͬʱ��¼��ǰʱ��.�ú���ͨ���뺯��back_light_contorl���ʹ��,���а�����
//			��������ʱ���øú����򿪱�����,ͬʱ��¼�򿪱����Ƶ�ʱ��,Ȼ����������whileѭ����
//			����back_light_contorl�������жϵ�ǰ�޶���ʱ���Ƿ�ﵽԤ���趨��ֵ,����ﵽ�趨ֵ
//			��ص�������.
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ: ��
//��    ��: �� ־ ��
//��������: 2009/8/26
//�� �� ��: 
//�޸�����: 
//��    ע: 
void sigfcn(void);


//�� �� ��: back_light_contorl
//��    ��: �μ�sigfcn����������
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ: ��
//��    ��: �� ־ ��
//��������: 2009/8/26
//�� �� ��: 
//�޸�����: 
//��    ע: 
void back_light_contorl(void);


//�� �� ��: get_union_key
//��    ��: ����һ����ϼ�. ��ϼ��ļ�ֵ����(��keymap.h�ļ��ж���):
//			#define UNKEY_TAB1		0xD1			//��ϼ�Tab+1
//			#define UNKEY_TAB2		0xD2			//��ϼ�Tab+2
//			#define UNKEY_10		0xD3			//��ϼ�1+0
//			#define UNKEY_ENTER1	0xD4			//��ϼ�ENTER+1
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ: UNKEY_TAB1, UNKEY_TAB2, UNKEY_10, UNKEY_ENTER1
//��    ��: �� ־ ��
//��������: 2009/8/26
//�� �� ��: 
//�޸�����: 
//��    ע: 
unsigned short get_union_key(void);

#endif
