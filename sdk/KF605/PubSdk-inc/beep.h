/*
 * Author: Seeger Chin
 *  Owner: ARCA Technology Corporation.
 *   Date: 2003.08.12
 *
 * =================== W  A  R  N  I  N  G ===========================
 *
 *     This demo ONLY show how to operate the Arca GT2000 SCC (Smart Card Controller)
 *     in user space.
 *
 *     The source code is NOT complete.  It only handles the simplest cases.
 *     For example, it only supports the protocol 0, and does not handle all
 *     the failure cases.
 *
 *     So, for safety, we recommend that USER writes the program based on the
 *     published GB and ISO standards, and DO NOT use this demo application
 *     directly.
 *
 * ================== W  A  R  N  I  N  G ============================
 */


#ifndef  BEEP_H
#define  BEEP_H


extern void beep_on(int, int);
extern int beep_init();
extern int close_beep();

//设置频率,声音大小,持续时间
extern void Sdk_BeepSet(int vol, int fre, unsigned short time);

//发声
extern void Sdk_BeepVoice(int vol, int fre, unsigned short  time);

extern void beep(int mode);

extern void Sdk_BeepAccept(void);


extern void Sdk_BeepWarn(void);


#endif
