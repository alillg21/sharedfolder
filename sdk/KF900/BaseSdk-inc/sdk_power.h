#ifndef _SDK_POWER_H_
#define _SDK_POWER_H_

/* battery status
0 - No power in battery.
1 - One quarter of power in battery.
2 - A half of power in battery.
3 - Three quarters of power in battery.
4 - Full power in battery.
0xFF - External AC power is used.
0xFE - External AC power is used, and the battery is being charged up.
*/
#define BAT_VAL0        0
#define BAT_VAL1        1
#define BAT_VAL2        2
#define BAT_VAL3        3
#define BAT_VAL4        4
#define BAT_DC          0xFF
#define BAT_CHARGE      0xFE

#define WAKEUP_BY_ENTER 0x01 //OPT
#define WAKEUP_BY_RS232_CP_EPP 0x06
#define WAKEUP_BY_MDB 0x08
#define WAKEUP_BY_USB 0x10
#define WAKEUP_BY_TM0 0x40

#define MDB_WAKEOUT_UP "0124"
#define MDB_WAKEOUT_DOWN "0125"

#ifdef __cplusplus
extern "C" {
#endif

//  Function    :  int sdk_BatteryStatus (unsigned short *pValue)
//  Description :  This function returns the power status.
//  Parameters  :  pValue
//                 An output parameter, which is used to get the status of the power/battery.
//                 0 每 No power in battery.
//                 1 每 One quarter of power in battery.
//                 2 每 A half of power in battery.
//                 3 每 Three quarters of power in battery.
//                 4 每 Full power in battery.
//                 0xFF 每 External AC power is used.
//                 0xFE 每 External AC power is used, and the battery is being charged up.
//  Return Value:  0       Success
//                 -1      Error
//  Remarks     :  None
int sdk_BatteryStatus (unsigned short *pValue);

//  Function    : int sdk_PowerProtectOpen (void)
//  Description : NOT AVAILABLE NOW
//  Parameters  : N/A
//  Return Value: 0     Success
//                -1    Error
//  Remarks     : N/A
int sdk_PowerProtectOpen(void);

//  Function    : int PowerProtectClose(void)
//  Description : NOT AVAILABLE NOW
//  Parameters  : N/A
//  Return Value: 0     Success
//                -1    Error
//  Remarks     : N/A
int sdk_PowerProtectClose(void);

/* sdk_Sleep
********************************************************************************
Description : Sleep
Input Param : wakeup_mode: Set the wakeup mode, only the device you set in the
               mode will wake the uetb up. must include one of the
               following: WAKEUP_BY_RS232_OPT, WAKEUP_BY_RS232_CR_
               EPP, WAKEUP_BY_MDB, WAKEUP_BY_USB, WAKEUP_BY_TM0.
               you can set as "WAKEUP_BY_MDB || WAKEUP_BY_USB" to
               use more than one device
          sec(s): Only use for rtc wakeup. after sec seconds, the UETB will
                   wake up by the rtc
Output Param: none
Return      :
               0: Wakeup by USB or TM0 (WAKEUP_BY_USB_TM0)
           1: Wakeup by OPT (WAKEUP_BY_RS232_OPT)
           6: Wakeup by EPP_CR (WAKEUP_BY_RS232_CR_EPP)
           8: Wakeup by MDB (WAKEUP_BY_MDB)
          81: Wakeup by OPT, USB or TM0 (WAKEUP_BY_OPT_USB_TM0)
          -1: Can not update the system clock
          -2: Can not set the alarm time
Remarks     : none
*******************************************************************************/
int sdk_Sleep(int wakeup_mode, int sec);

/* sdk_ResetEth
*******************************************************************************
Description: Reset the ethernet after sleep
Input Param : None
Output Param: None
Return      :
               0: Success
               -1: False
*******************************************************************************/
int sdk_ResetEth();

#ifdef __cplusplus
}
#endif

#endif

