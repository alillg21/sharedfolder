#ifndef _SDK_SOCKET_H_
#define _SDK_SOCKET_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Socket module functions
********************************************************************************
1. Implement the initial functions.
----by Luo cheng  12/20/2010
*******************************************************************************/

//-------------------------------------------------------------------
// Desc: check socket file  descriptor status.
// Return:
//      0 - socket file  descriptor status is correct(current socket file  descriptor)
//      -1 - socket file  descriptor status is wrong (maybe had closed by server, need re-connect)
//-------------------------------------------------------------------
int sdk_SocketCheck(void);

//-------------------------------------------------------------------
// Desc: build an asynchronous (non-block) socket connection within a period time
// Param:
//      ip - the ip address
//      port - the port number
//      time_sec - the period timeout (second)
// Return:
//      =0 - successful
//      -1 - error ，and close socket
//      -2 - timeout ，and close socket
//-------------------------------------------------------------------
int sdk_SocketConnect(char *host_ip, int port, int time_sec);

//-------------------------------------------------------------------
// Desc: close socket.
// Param:
//      socket_fd - online socket
// Return:
//      =0 - successfully
//      -1 - socket not available or close socket error
//-------------------------------------------------------------------
int sdk_SocketDisconnect(void);

//-------------------------------------------------------------------
// Desc: read data from a descriptor.
// Param:
//      buf - the buffer to store read data
//      len - the size of the read buffer
//      time_sec - the period timeout (second)
// Return:
//      >0 - read data length  (返回数据长度<len,表示超时读出的数据长度)
//      -1 - socket close
//      -2 - no data
//      -3 - server close connect
//      -4 - other error
//-------------------------------------------------------------------
int sdk_SocketRead(char *buf, int len, int time_sec );

//-------------------------------------------------------------------
// Desc: write data from a descriptor.
// Param:
//      socket_fd - file descriptor or socket descriptor
//      buf - the buffer to store write data
//      len - the size of the write buffer
//      time_sec - the period time to wait (second)
// Return:
//      >0 - write data length
//      -1 - socket not available or write error
//-------------------------------------------------------------------
int sdk_SocketWrite(char *buf, int len);

#ifdef __cplusplus
}
#endif

#endif

