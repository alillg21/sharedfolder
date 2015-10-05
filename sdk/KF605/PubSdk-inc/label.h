#ifndef __LABEL_H__
#define __LABEL_H__

typedef struct {
	unsigned char text[41];
	unsigned char x;
	unsigned char y;
	void *object;
} label_t;

extern void label_show(label_t * label, void *owner);
extern void label_setfocus(label_t * label, void *owner);
extern unsigned char label_key_event(label_t * label, void *owner, unsigned char keycode);
extern void label_init(label_t * label);

#endif				/*  __LABEL_H__  */
