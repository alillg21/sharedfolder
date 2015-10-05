/* Serial module functions
********************************************************************************
1. Implement the initial functions.
----by Wu Zhijian  12/22/2010

*******************************************************************************/
#ifndef _SERIAL_SUPPORT_H_
#define _SERIAL_SUPPORT_H_

//Please DO NOT modify the following definations.
#define COM0    0
#define COM1    1
#define COM2    2

#ifdef __cplusplus
extern "C" {
#endif

/* sdk_SerialOpen
********************************************************************************
Description : initializes and opens the specific serial port at a certain speed.
Input Param :
                 nPortId: An integer to identify the port number. KAIFA POS supports 3 serial ports at most:
                             0 - Serial port 1.
                             1 - Serial port 2.
                             2 - Serial port 3.
                 nSpeed : An integer to identify the baud rate. KAIFA POS supports the following rates (in BPS):
                          [230400, 115200, 57600, 38400, 19200, 9600, 4800, 2400, 1800, 1200, 600, 300, 200]
Output Param: none
Return      :
                 0: Success
        -1: fails to open the serial port.
        -2: invalid parameters.
        -3: the nSpeed parameter is not correct.
Remarks     :   1. The default timeout is 150 ms.
                2. This function opens the serial port with BN1 mode, and the attribute settings is 8N1 (
                data bit is 8; parity check is none; stop bit is 1); RAW mode to output;
                no flow control; no blocking.
                3. The first port (nPortId = 0, or "/dev/ttys0") is used by internal GPRS module.
                User should not use this port unless user wants to send AT CMD to the GPRS module.
                4. In debug mode, the second port (nPortId = 1, or "/dev/ttyS1") is used to debug and can not be used.
                In this situation, only the third port (nPortId = 2, or "/dev/ttyS2") can be used to communicate with
                other serial devices.
*******************************************************************************/
int sdk_SerialOpen(unsigned short nPortId, unsigned int nSpeed);

/* sdk_SerialClose
********************************************************************************
Description : tries to close the specific serial port.
Input Param :
                nPortId: An integer to identify the port number.
Output Param: none
Return      :
                 0: Success
        -1: fails to close the certain port.
        -2: invalid port number.
Remarks     : The port number should be 0~2
*******************************************************************************/
int sdk_SerialClose( unsigned short nPortId );

/* sdk_SerialClear
********************************************************************************
Description : clears all the data in the specific serial port.
Input Param :
                nPortId: An integer to identify the port number.
Output Param: none
Return      :
                 0: Success
        -1: fails to clear the data.
        -2: invalid port number.
Remarks     : none
*******************************************************************************/
int sdk_SerialClear(unsigned short nPortId );

/* sdk_SerialSend
********************************************************************************
Description : sends a certain length of data to the specific serial port.
Input Param :
                nPortId    : An integer to identify the port number.
                pInBuffer  : The data that is going to be sent.
                nExpSendLen: The length of data that user wants to send.
Output Param: none
Return      :
                 0: Success
        -1: fails to send data.
        -2: invalid parameters.
        -3: the certain port is not opened.
Remarks     :   1. If the data can not completely be sent once, it will send the
                 rest data more times until the data is completely sent.
                2. It will return the data that sends successfully.
*******************************************************************************/
int sdk_SerialSend ( unsigned short nPortId, void *pInBuffer, unsigned int nExpSendLen );

/* sdk_SerialRecv
********************************************************************************
Description : receives and saves a certain length of data from a specific serial port.
Input Param :
               nPortId    :An integer to identify the port number.
               nExpReadLen:The length of data that user wants to read.
Output Param:
               pOutBuffer: The pointer that is to save the data read from the serial.
Return      :
                 0: Success
        -1: fails to read the data.
        -2: invalid parameters.
        -3: the certain port is not opened.
Remarks     :   This function will return immediately. It will return the data that reads,
                otherwise it will return 0 (Success but no data) or the error code.
*******************************************************************************/
int sdk_SerialRecv( unsigned short nPortId, void *pOutBuffer, unsigned int nExpReadLen );

#ifdef __cplusplus
}
#endif

#endif

