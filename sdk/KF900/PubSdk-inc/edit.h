#ifndef __EDIT_H__
#define __EDIT_H__

#define EDIT_FORMAT 0
#define EDIT_PASSWD 1
#define EDIT_NORMAL 2

#define FORMAT_HEX  0
#define FORMAT_DEC  1

typedef struct {
	unsigned char text[41];
	unsigned char width;	/* the max number of the input text */
	unsigned char pos;
	unsigned char x;
	unsigned char y;
	unsigned char type;
	unsigned char format_type;	/* if use format edit */
	unsigned char (*on_edit) (void *this);
	void *object;
	unsigned char imgbuf[40 * 16 + 2];
} edit_t;

extern void edit_show(edit_t * edit, void *owner, unsigned char enabled);
extern void edit_setfocus(edit_t * edit, void *owner);
extern unsigned char edit_key_event(edit_t * edit, void *owner, unsigned char keycode);
extern void edit_init(edit_t * edit);

#endif				/*  __EDIT_H__  */
