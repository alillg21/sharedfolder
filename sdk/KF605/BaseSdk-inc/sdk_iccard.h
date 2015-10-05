/*!@file
********************************************************************************
Module: Common
file name: sdk_iccard.h

function: system file
Author: CRD by Zumiao Yu
version: 1.0.0
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
modify :
date              version          by           fixed
2010/02/23    1.0.0             Yu            create
*******************************************************************************/
#ifndef _SDK_ICCARD_H_
#define _SDK_ICCARD_H_

#define ICCARD_DEVICE "/dev/sc"

#define MAX_CARD_NUM    4

#define VCC_3V                  0
#define VCC_1_8V                1
#define VCC_5V                  2

#define SC_WAIT_STATE_CHANGE    1234
#define SC_STATUS               1235
#define SC_RESET                1236
#define SC_GETATR               1237
#define SC_CLOSE                1238
//set icc baudrate
#define SC_SET_RATE                                  1241

typedef enum                    SC_STATE_E
{
    SC_STATE_FREE=0,        // 0 Device not acquired
    SC_STATE_IDLE,          // 1 Device not started
    SC_STATE_NOT_PRESENT,   // 2 Card not inserted
    SC_STATE_PRESENT,       // 3 Card inserted, not powerd
    SC_STATE_READY,         // 4 Ready for command
    SC_STATE_ERROR,         // 5 Card Error reset or remove card
} SC_STATE;


#ifdef __cplusplus
extern "C" {
#endif

/*
name       :sdk_Iccard_Open
desc.        :Electrify to appointed card slot, and reset card, return the responsive content of card
            No command could be done before card initialization successful.
input para :cCardNO Card slot No
return      :0  Success
        -1  card slot No. error
        -2  open device error
*/
int sdk_Iccard_Open(uchar cCardNO);

/*
name       :sdk_Iccard_Close
desc.        :Close appointed IC card module
input para :cCardNO card slot No
return      :0  Success
        -1  card slot No. error
*/
int sdk_Iccard_Close(uchar cCardNO);

/*
name       :sdk_Iccard_CheckExist
desc.        :Check whether there is a card
input para :cCardNO Card slot No
return      :0  Success
        -1  card slot No. error
        -2  not open device file
        -3  other error
*/
int sdk_Iccard_CheckExist(uchar cCardNO);

/*
name       :sdk_Iccard_CheckState
desc.        :Check whether card is ready
input para :cCardNO Card slot No
return      :0  Success
        -1  card slot No. error
        -2  not open device file
        -3  card error
*/
int sdk_Iccard_CheckState(uchar cCardNO);

/*
name       :sdk_Iccard_Reset
desc.        :Reset IC card
input para :cCardNO Card slot No
            pcAtr   Response of SC_GETATR
            pnBackLen   Length of SC_GETATR's response
return      :0  Success
        -1  card slot No. error
        -2  not open device file
        -3  reset IC card error
        -4  IC card is not ready
        -5  get ATR error
*/
int sdk_Iccard_Reset(uchar cCardNO, uchar *pcAtr, int *pnBackLen);

/*
name       :sdk_Iccard_SendCmd
desc.        :Send command
input para :    cCardNO Card slot No
            pcCmdBuf    Command to send
            nCmdLen Length of command
            pcBackBuf   Command to return
            pnBackLen   Length of command
return      :0  Success
        -1  card slot No. error
        -2  not open device file
        -3  send command error
        -4  IC card is not ready
*/
int sdk_Iccard_SendCmd(uchar cCardNO, uchar* pcCmdBuf, int nCmdLen, uchar *pcBackBuf, int* pnBackLen);

/*
name       :sdk_Iccard_SetBaudrate
desc.      :Set ic card baudrate
input para :cCardNO Card slot No
    nBaudrate   Baud rate
return      :0  Success
        -1  card slot No. error
        -2  not open device file
        -3  baud rate error
        -4  other error
note: Reset is expected after baud rate be set.
*/
int sdk_Iccard_SetBaudrate(uchar cCardNO, unsigned long nBaudrate);

#ifdef __cplusplus
}
#endif

#endif

