#ifndef __MEMO_H__
#define __MEMO_H__

typedef struct {
	unsigned char *text;	//静态文本
	unsigned char x;	//横坐标
	unsigned char y;	//纵坐标
	unsigned char w;	//宽度，用于自动换行
	unsigned char max_lines;	//最大行数，超出则截断
	void *object;		//
} memo_t;

extern void memo_show(memo_t * memo, void *owner);
extern unsigned char memo_key_event(memo_t * memo, void *owner, unsigned char keycode);
extern void memo_init(memo_t * memo);

#endif				/*  __MEMO_H__  */
