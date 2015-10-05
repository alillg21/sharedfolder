/*!@file
********************************************************************************
Module: Common
file name: sdk_debuglog.h

function: system file
Author: CRD by Yongning Lu
version: 1.0.0
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
modify :
date              version          by           fixed
2010/02/23    1.0.0             Lu            create
*******************************************************************************/
#ifndef __DEBUG_LOG_H__
#define __DEBUG_LOG_H__

#include "sdk_common.h"

#define LOG_NONE        0
#define LOG_CONSOLE     1
#define LOG_NETWORK     2

#define MAX_LOGFILE_SIZE    (1024*1024)

#ifdef __cplusplus
extern "C" {
#endif

/*! @function
********************************************************************************
PROTOTYPE: sdk_Printf
FUNCTION: Output the debug log that has time and curse information to device
PARAMETER: format  : Formatted string
RETURN: None
--------------------------------------------------------------------------------
 ANNOTATION:
    Format of parameter is the same as print
    Output mode can invoke sdk_SetLogMode set as console output or appointed ip  address output
    The function output debug log and write it into log file
    If output mode is internet interface, debug log will be encrypted before output.
*******************************************************************************/
void sdk_Printf(const char *format, ...);

/*! @function
********************************************************************************
PROTOTYPE: sdk_DebugHex
FUNCTION: Output appointed buffer's content in hexadecimal, and compart with blank
PARAMETER: szSrc       : Pointer which point to the output bufferë
             nSrcBufLen  :The length of output data
RETURN : None
--------------------------------------------------------------------------------
ANNOTATION:
    The function output debug log and write it into log file
    If output mode is internet interface, debug log will be encrypted before output.
*******************************************************************************/
void sdk_DebugHex(uchar *szSrc, int nSrcBufLen);

/*! @function
********************************************************************************
PROTOTYPE: sdk_DebugSetLogMode
FUNCTION: Setup output mode of debug log
PARAMETER: nMode       : 0 - Forbid debug log output£»
                                      1 - output from standard device»
                                      2 - output by internet
RETURN: None
--------------------------------------------------------------------------------
ANNOTATION: System Default Forbid debug log output value is 0
                   When invoke this function, the output interface will change at once, debug log will output to appointed interface when execution sdk_Printf.
*******************************************************************************/
void sdk_DebugSetLogMode(int nMode);

/*! @function
********************************************************************************
PROTOTYPE: sdk_DebugSetLogFile
FUNCTION: Setup debug log file
PARAMETER: pFileName       :File name to save debug log
RETURN : 0-Success
               1-Error
--------------------------------------------------------------------------------
ANNOTATION: The function create log file according appointed file name, if setup success, debug log will encrypted and write to the file.
    Log file could be send to TMS server from terminal to check the terminal unusual condition
    The size of log file is 1kb, it'll clear all and write again when it's full.
þ
*******************************************************************************/
int sdk_DebugSetLogFile(char *pFileName);

/*! @function
********************************************************************************
PROTOTYPE: sdk_DebugSetLogServer
FUNCTION: Set the host ip address and port no of Debug Log
PARAMETER: pszHostIP : Object ip address
              nPort : Object port no
RETURN : None
--------------------------------------------------------------------------------
ANNOTATION: Debug log will send to appointed host port by UDP.
    To security,Debug log must be send as cryptograph,
    Receiving terminal must have a application to receive log file, and decipher it.
*******************************************************************************/
void sdk_DebugSetLogServer(char *pszHostIP, int nPort);


/*! @function
********************************************************************************
º¯ÊýÃû: sdk_DebugSetLogServer
¹¦ÄÜ  : ÉÏ´«ÈÕÖ¾ÎÄ¼þ
²ÎÊý  : pcUploadHostIP  : ÉÏ´«Ö÷»úµÄIPµØÖ·
        pcUploadPath    : ÉÏ´«Ö÷»úµÄÂ·¾¶
        pcUploadDir     £ºÉÏ´«Ö÷»úµÄÄ¿Â¼£¨ÔÚpcUploadPathµÄÂ·¾¶ÏÂµÄ×ÓÄ¿Â¼£©
        pcLogFilePath   £ºÈÕÖ¾ÎÄ¼þµÄÍêÕûÂ·¾¶£¨ÈÕÖ¾ÎÄ¼þËùÔÚµÄÄ¿Â¼+ÈÕÖ¾ÎÄ¼þÃû£©
·µ»ØÖµ: ÎÞ
--------------------------------------------------------------------------------
±¸×¢  : ½«ÒÔFTP·½Ê½ÉÏ´«ÈÕÖ¾ÎÄ¼þ¡£
--------------------------------------------------------------------------------
×÷Õß  : Â¬ÓÀÄþ
*******************************************************************************/
//int sdk_DebugUploadLogFile(char *pcUploadHostIP, char *pcUploadPath, char *pcUploadDir, char *pcLogFilePath);

#ifdef __cplusplus
}
#endif

#endif  //__DEBUG_LOG_H__

