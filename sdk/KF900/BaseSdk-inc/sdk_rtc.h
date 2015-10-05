//sdk_rtc.h
#ifndef _SDK_RTC_H_
#define _SDK_RTC_H_

#define TIMERNUM    10      //It defines 10 system timer
#define TIMERLCD    9           //The timer that controls backlight

#ifdef __cplusplus
extern "C" {
#endif

//      Function        :       int sdk_RtcSetTime (unsigned char *pDateTime)
//      Description     :       This function sets the system date and time.
//      Parameters      :       pDateTime       The pointer to the string of date and time, and the string format is YYYYMMDDhhmmss, which is decimal with 7 Bytes.
//                      for example: 2012/12/30 12:59:59  ,the parameter value is 0x14 0x0c 0x0c 0x1e 0x0c 0x3b 0x3b
//                                      pDateTime [0] = Higher Byte of year
//                                      pDateTime [1] = Higher Byte of year
//                                      pDateTime [2]= Month
//                                      pDateTime [3]= Day
//                                      pDateTime [4]= Hour
//                                      pDateTime [5]= Minute
//                                      pDateTime [6]= Second
//      Return Value:   0       Success
//                                      -1      Error: Error: Fails to set the RTC.
//                                      -2      Error: invalid parameters.
//                                      -3      Other errors.
int sdk_RtcSetTime (unsigned char *pDateTime);

//      Function                :       int sdk_RtcGetTime (unsigned char *pDateTime)
//      Description             :       This function gets the system date and time.
//      Parameters      :       pDateTime       The pointer to the string of date and time, and the string format is YYYYMMDDhhmmss, which is decimal with 7 Bytes.
//                      for example: 2012/12/30 12:59:59  ,the parameter value is 0x14 0x0c 0x0c 0x1e 0x0c 0x3b 0x3b
//                                              pDateTime [0] = Higher Byte of year
//                                              pDateTime [1] = Higher Byte of year
//                                              pDateTime [2]= Month
//                                              pDateTime [3]= Day
//                                              pDateTime [4]= Hour
//                                              pDateTime [5]= Minute
//                                              pDateTime [6]= Second
//      Return Value    :       0       Success
//                                      :       -1      Error: Fails to get the RTC.
//                                      :       -2      Other errors.
int sdk_RtcGetTime (unsigned char *pDateTime);

//  Function    :   int sdk_RtcTimerSet (int timer_id, unsigned int count)
//  Description :   This function sets up a timer and starts it.
//  Parameters  :
//                  cTimeId:    An integer to identify the timer (It supports 5 timer at most,
//                              the number is 0~4).
//              :   nTimeMs :   The parameter to identify the counting time in millisecond.
//  Return Value:   0   Success
//                  -1  Error: invalid parameters.
//                  -2  Other errors.
//  Remarks None
//int sdk_RtcTimerSet (unsigned char cTimeId, int nTimeMs);

//  Function    :   unsigned int sdk_RtcTimerCheck (int timer_id)
//  Description :   This function checks what the current value is to a specific timer, which also means how much time is left (in millisecond).
//  Parameters  :   timer_id    An integer to identify the timer (0~4)
//  Return Value:   positive number The time that has left.
//                  0   time out
//                  -1  Error: invalid parameters.
//                  -2  Other errors.
//                  >0  The time left
//  Remarks     :   None
//int sdk_RtcTimerCheck (unsigned char cTimeId);

//      Function        :       int sdk_RtcDelay (unsigned short nMsec)
//      Description     :       This function makes the application wait for a period of time.
//      Parameters      :       nMsec   The parameter to identify the waiting time (in millisecond).
//      Return Value:   0       Success
//                                      -1      Error: invalid parameters.
//                                      -2      failure.
//      Remarks         :       None
int sdk_RtcDelay (unsigned short nMsec);

#ifdef __cplusplus
}
#endif

#endif

