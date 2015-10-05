/*!@file
********************************************************************************
Module: Common
file name: sdk_key.h

function: system file
Author: CRD by Zumiao Yu
version: 1.0.0
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
modify :
date              version          by           fixed
2010/02/23    1.0.0             Yu            create
*******************************************************************************/
#ifndef _sdk_KEY_H_
#define _sdk_KEY_H_

#define KEYBOARD_FILENAME "/dev/event0"

#define NULL_KEY        0x00

#define KEY_0           '0'
#define KEY_1           '1'
#define KEY_2           '2'
#define KEY_3           '3'
#define KEY_4           '4'
#define KEY_5           '5'
#define KEY_6           '6'
#define KEY_7           '7'
#define KEY_8           '8'
#define KEY_9           '9'

#define KEY_ALPHA       0xb1
#define KEY_FUNC        0x9E
#define KEY_MENU        0x9d

#define KEY_UP          0x94
#define KEY_DOWN        0x95
#define KEY_LEFT        0x96
#define KEY_RIGHT       0x97

#define KEY_ESC         0x81
#define KEY_BACK        0x82
#define KEY_ENTER       0x84

#ifdef __cplusplus
extern "C" {
#endif

/*
name       :sdk_KbInit
desc.        :Open keyboard device,setup RAW mod.
input para :None
return      :   0 : Successful
            -1: Failed
*/
int sdk_KbInit(void);

/*
name       :sdk_KbClose
desc.        :Close the keyboard device.
input para :None
return      :None
*/
void sdk_KbClose(void);

/*
name       :sdk_KbClear
desc.        :Clear the key which haven't been readed in current key buffer.
input para :None
return      : None
*/
void sdk_KbClear(void);

/*
name       :sdk_GetKey
desc.        :Read the key value in key buffer.  while the key value have been read,it must be cleared.
input para :    None
return      :   0:If it's empty.
            >0 Key value.
*/
uchar sdk_GetKey(void);

/*
name       :sdk_GetKey_Value
desc.        :Get the key value before transform (primordial value).
input para :None
return      : Key value
*/
uchar sdk_GetKeyScanCode(void);

/*
name       :sdk_GetKeyPressTime
desc.        :Get the last time from press the keyboard.
input para :None
return      : time value
*/
long sdk_GetKeyPressTime(void);

/*
name       :sdk_SetKeyPressTime
desc.        :Set the time when press the keyboard.
input para :None
return      : time value
*/
void sdk_SetKeyPressTime();

#ifdef __cplusplus
}
#endif

#endif

