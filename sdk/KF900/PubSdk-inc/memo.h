#ifndef __MEMO_H__
#define __MEMO_H__

typedef struct {
	unsigned char *text;	//��̬�ı�
	unsigned char x;	//������
	unsigned char y;	//������
	unsigned char w;	//��ȣ������Զ�����
	unsigned char max_lines;	//���������������ض�
	void *object;		//
} memo_t;

extern void memo_show(memo_t * memo, void *owner);
extern unsigned char memo_key_event(memo_t * memo, void *owner, unsigned char keycode);
extern void memo_init(memo_t * memo);

#endif				/*  __MEMO_H__  */
