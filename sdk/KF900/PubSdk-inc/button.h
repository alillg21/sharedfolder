#ifndef __BUTTON_H__
#define __BUTTON_H__

typedef struct {
	/*unsigned */char *text;
	unsigned char x;
	unsigned char y;
	unsigned char (*on_button) (void *owner);
	void *object;
} button_t;

extern void button_show(button_t * button, void *owner);
extern void button_setfocus(button_t * button, void *owner);
extern unsigned char button_key_event(button_t * button, void *owner, unsigned char keycode);
extern void button_init(button_t * button);

#endif				/*  __BUTTON_H__  */
