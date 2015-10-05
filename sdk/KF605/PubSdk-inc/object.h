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
#define OBJ_REFRESH     4	//所有控件刷新
#define CUR_OBJ_REFRESH 5	//当前控件刷新

#define POS_LEFT        0
#define POS_ABOVE       1
#define POS_RIGHT       2

typedef struct {
	unsigned char type;	//控件类型
	unsigned char enabled;	//控件是否有效
	unsigned char visible;	//控件是否可见
	unsigned char showhint;	//提示显示标志
	unsigned char *hint;	//本控件的快捷提示
	unsigned char tab_stop;	//本控件是否响应轮流聚焦
	void *owner;		//本控件所属窗口
	union {
		edit_t *edit;	//编辑框
		label_t *label;	//标签
		button_t *button;	//按钮
		labeled_edit_t *labeled_edit;	//带标签的编辑框
		selector_t *selector;	//选择条
		memo_t *memo;
	} obj;
} object_t;

extern void object_show(object_t * object);
extern void object_setfocus(object_t * object);
extern unsigned char object_key_event(object_t * object, unsigned char keycode);
extern void object_create(object_t * obj, void *component, unsigned char type);

#endif				/*  __OBJECT_H__  */
