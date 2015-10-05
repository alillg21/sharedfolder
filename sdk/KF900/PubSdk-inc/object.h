#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "edit.h"
#include "label.h"
#include "memo.h"
#include "button.h"
#include "labeled_edit.h"
#include "selector.h"

#define OBJ_EDIT        0
#define OBJ_LABEL       1
#define OBJ_BUTTON      2
#define OBJ_LB_EDT      3
#define OBJ_SELECTOR    4
#define OBJ_MEMO        5

#define OBJ_STAY        0
#define OBJ_GOPRE       1
#define OBJ_GONEXT      2
#define OBJ_QUIT        3
#define OBJ_REFRESH     4	//���пؼ�ˢ��
#define CUR_OBJ_REFRESH 5	//��ǰ�ؼ�ˢ��

#define POS_LEFT        0
#define POS_ABOVE       1
#define POS_RIGHT       2

typedef struct {
	unsigned char type;	//�ؼ�����
	unsigned char enabled;	//�ؼ��Ƿ���Ч
	unsigned char visible;	//�ؼ��Ƿ�ɼ�
	unsigned char showhint;	//��ʾ��ʾ��־
	unsigned char *hint;	//���ؼ��Ŀ����ʾ
	unsigned char tab_stop;	//���ؼ��Ƿ���Ӧ�����۽�
	void *owner;		//���ؼ���������
	union {
		edit_t *edit;	//�༭��
		label_t *label;	//��ǩ
		button_t *button;	//��ť
		labeled_edit_t *labeled_edit;	//����ǩ�ı༭��
		selector_t *selector;	//ѡ����
		memo_t *memo;
	} obj;
} object_t;

extern void object_show(object_t * object);
extern void object_setfocus(object_t * object);
extern unsigned char object_key_event(object_t * object, unsigned char keycode);
extern void object_create(object_t * obj, void *component, unsigned char type);

#endif				/*  __OBJECT_H__  */
