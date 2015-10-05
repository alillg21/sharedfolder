#ifndef __LABELED_EDIT_H__
#define __LABELED_EDIT_H__

#include "chnpyime.h"

#define EDIT_FORMAT 0
#define EDIT_PASSWD 1
#define EDIT_NORMAL 2

#define FORMAT_HEX  0
#define FORMAT_DEC  1
#define FORMAT_INT  2

#define INVALID_KEYCODE	0xFF	//定义一个无效的keycode码(zjwu 2008-07-24)

#define MAX_LB_EDIT_TEXT_LEN    200	//现需要输入200字节的付款人名称 jdzhou 2007-6-12
#define MAX_LB_TEXT_LEN	50

typedef struct {
	unsigned char label_pos;	//Where is the label? Left or above?
	unsigned char label_updated;	//we can update the label ONLY ONCE by this flag, Its hard to be realized.
	unsigned char label[MAX_LB_TEXT_LEN];	//label of the labeled_edit control
	unsigned char rev_len;	//width of reverse disp area, not more than 10
	unsigned char edit_left;	//left side of edit relative to the beginning of labeled_edit, not less than 10
	unsigned char text[MAX_LB_EDIT_TEXT_LEN + 1];
	unsigned char width;	//max input len, less than 40
	unsigned char pos;	//position of the cursor?
	unsigned char x;
	unsigned char y;
	unsigned char type;	//edit type
	unsigned char format_type;	//if use format edit
	unsigned char (*on_edit) (void *this);
	unsigned char (*onchange) (void *this);	//sth to be handled when edit changed
	unsigned char (*pre_change) (void *this, unsigned char keycode);	//modify by zjwu 2008-07-01,edit接收输入前允许对输入
	//的keycode进行处理,返回处理后的keycode
	unsigned char need_sync;	//有onchange事件，是否需要进行同步刷新? 1为需要 2006-6-13 13:31
	unsigned char sync_obj_num;	//当有onchange事件需要对其他控件进行刷新时，需要刷新的其他控件总数 2006-6-12 11:06
	unsigned char *sync_obj;	//需要刷新的其他控件序号 2006-6-12 11:06
	unsigned char ime_enabled;	//need activate IME, it may be conbined with "type"
	unsigned char ime_status;	//default ime status, such as Chinese/Digit etc.
	unsigned char ime_bar_line;	//start line that the IME bar lies
	unsigned char selected;	//文本被选中, 新键入内容取代原内容而不是追加 1:selected 其他:未被选中
	//void (*on_focused)(void *this); //deal with sth. when focused if needed
	void *object;
} labeled_edit_t;

extern void labeled_edit_show(labeled_edit_t * edit, void *owner, unsigned char enabled);
extern void labeled_edit_setfocus(labeled_edit_t * edit, void *owner);
extern unsigned char labeled_edit_key_event(labeled_edit_t * edit, void *owner, unsigned char keycode);
extern void labeled_edit_init(labeled_edit_t * edit);

extern unsigned char g_edt_changed;	//控件内容被改变 2006-6-13 13:22

#endif				/*  __LABELED_EDIT_H__  */
