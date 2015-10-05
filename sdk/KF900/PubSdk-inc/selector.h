/*
 * Author: Jiandong Zhou(jiandongzhou@yahoo.com)
 * Date  : 2005-07-14
 */
#ifndef __SELECTOR_H__
#define __SELECTOR_H__

typedef struct {
	unsigned char label_pos;	//position of label, relative to the selector
	const char *label;		//ptr to a string
	unsigned char label_width;	//max label len
	const char **item;		//pointer to an array of string
	unsigned char item_num;		//number of items
	unsigned char item_index;	//current item index
	unsigned char x;		//x coordinate
	unsigned char y;		//y coordinate
	unsigned char width;		//maximum bytes of all the items
	unsigned char (*on_select) (void *owner);	//deal with sth if needed
	void *object;			//the owner object of this selecter
} selector_t;

//
//如果label存在：
//如果label在selector上方，则selector从(x, y+2)开始，label从(x, y)开始
//如果label在selector左方，则selector从(x+label_width, y)开始，label从(x, y)开始
//如果label在selector右方，则selector从(x, y)开始，label从(x+width, y)开始
//
extern void selector_show(selector_t *selector, void *owner);
extern void selector_setfocus(selector_t *selector, void *owner);
extern unsigned char selector_key_event(selector_t *selector, void *owner, unsigned char keycode);
extern void selector_init(selector_t *selector);

#endif
