#ifndef __WINDOW_H__
#define __WINDOW_H__
#include <stdio.h>
#include <string.h>
#include "object.h"


#define WIN_SELL            0x00	//˰�����۴���
#define WIN_MENU            0x01	//˰�ز˵�����
#define WIN_OTHER           0x02	//˰����������
//======================    ======================
#define EFT_WIN_SELL        0x80	//�������۴���
#define EFT_WIN_MENU        0x81	//���в˵�����
#define EFT_WIN_OTHER       0x82	//������������

#define NO_IDLE_REFRESH     0x00	//����� loop_idle �¼�����Ҫ��ĳ�ؼ�������ʾˢ�� 2006-6-13 11:56
#define IDLE_REFRESH_AUTO   0x01	//����� loop_idle �¼���Ҫ��ĳ�ؼ�����ʵʱ��ʾˢ�� 2006-6-13 11:56
#define IDLE_REFRESH_PRESS  0x02	//�Ѷ��� loop_idle �¼���Ҫ��ÿ�ΰ�����Ҫ��ĳ�ؼ�����ˢ�� 2006-6-13 11:57

typedef struct {
	unsigned char exec_limit;	//�ô��ڵ�ִ��Ȩ������ 0������ 0��3λ�ֱ����տ�Ա�����ܡ������ά����Ա
	unsigned char type;	//��������
	unsigned char wait_tip;	//������ڽ��������Ҫ�ϳ�ʱ���׼�������齫�ñ�־��Ϊ1
	unsigned char showhint;	//��ʾ��ʾ��־
	unsigned char *hint;	//�����ڵ���ʾ��Ϣ
	unsigned char *tips;	//������ʾ��Ϣ
	unsigned char x;	//������
	unsigned char y;	//������
	unsigned char w;	//���
	unsigned char h;	//�߶�
	unsigned char border_style;	//�Ƿ񻭱߿�
	unsigned char init_flag;
	unsigned char need_pretreatment;	//Ԥ�����־ 1:ִ��show_post 2:ִ��loop_pre 3:���߾�ִ��
	object_t **sub_objs;	//�˴��ڵĿؼ�����
	unsigned char objs_num;	//�˴��ڰ����Ŀؼ���
	unsigned char tab_num;	//�ɾ۽��Ŀؼ���������С�ڵ���objs_num 2006-5-31
	unsigned char cur_tabstop;	//��ǰͣ�ڵڼ����ɾ۽��Ŀؼ��ϣ�����С��tab_num����0��ʼ���� 2006-5-31
	unsigned char *tab_order;	//�ؼ��۽�˳�� 2006-5-31
	unsigned char exist_invisible_ctrl;	//�ô�����ڲ��ɼ��ؼ������LCD��Ӧ���죬��ȥ��������
	//==������������� start== jdzhou 2006-12-26
	unsigned char cur_obj;	//��ǰ�ؼ�����
	unsigned char refocus;	//�Ƿ����¾۽�         1:���¾۽�          ����:�����ϴν���
	unsigned char refocus_type;	//���¾۽�ʱ��ʼֵ���� 1:����init_obj��ֵ  ����:�Զ�����
	unsigned char init_obj;	//���¾۽�ʱָ���۽��ؼ������������ر�Ҫ�󣬲�Ҫ���Ĵ�ֵ
	//==������������� end  == jdzhou 2006-12-26
	unsigned char fixed_prev_win;	//prev_win���ɸ��ı�־��1���̶������򣺿ɸ��ģ�
	unsigned char idle_refresh;	//1:�Զ�ˢ��; 2:����ˢ�� �ж���loop_idle��Ա������������Ҫ��idle_refresh�����ĸ��Ľ�����ʾˢ�� 2006-6-9
	unsigned char idle_refresh_sn;	//idle_refresh����Ϊ��Ҫˢ��ʱ��ָ����Ҫˢ�µĿؼ���� 2006-6-12 11:06

	unsigned char para;	//�ڵ��øô��ڵĵط�,�����ô��ڵĲ��� //modify by zjwu 2008-05-20

	void *prev_win;		//ǰһ���ڣ����ڷ���
	void (*init) (void *this);	//Attach the objs to a window, look at the demo
	void (*update) (void *this);	//Change the objs attr such as enabled ATTR
	void (*show_post) (void *this);
	//Message loop routines
	void (*loop_pre) (void *this);
	void (*loop_idle) (void *this, unsigned char keycode);	//�������������޼�ֵʱΪ�����������ʾ��������
	void (*loop) (void *this, unsigned char keycode);
	void (*loop_post) (void *this);
	void (*close_query) (void *this);	//���ڹر�֮ǰ����ѯ�ʻ���
	//up/down/hang/pick/complete/F1/cancel/lock/print�Լ�1..9��Щ�����ر���
	void (*special_key) (void *this, unsigned char keycode);
} window_t;



//�� �� ��: window_run
//��    ��: ����һ������
//ȫ�ֱ���: ��
//�������: window:ָ��һ�����ڽṹ���ָ��
//�������: ��
//�� �� ֵ: ��			
//��    ��: �ܽ���
//��������: 
//�� �� ��: ��־��
//�޸�����: 2009/8/26
//��    ע: 
void window_run(window_t * window);

//�� �� ��: show_spec_window
//��    ��: �ú�������ʹ�ò�����ʾһ������,��Ҫ��window_run�������ʹ��,
//			����:�ȵ���show_spec_window(win_a), Ȼ�����window_run(win_b), ��ʱ
//			��������ʾwin_b, ֻ����ʾwin_a
//ȫ�ֱ���: ��
//�������: window:ָ��һ�����ڽṹ���ָ��
//�������: ��
//�� �� ֵ: ��			
//��    ��: �ܽ���
//��������: 
//�� �� ��: ��־��
//�޸�����: 2009/8/26
//��    ע: 
void show_spec_window(window_t * ap_win);

//����ڴ��ڶ���ʱû�и�init_flag����ʼֵ0, ��ô����show�ô���֮
//ǰ�ȵ��øú���, Ȼ������show
void app_add_window(window_t * win);


//��������ָ���Ĵ���
void window_run_now(window_t * window);

#endif				/*  __WINDOW_H__  */
