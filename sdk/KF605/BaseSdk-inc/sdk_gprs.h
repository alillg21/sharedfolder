/* GPRS module functions
********************************************************************************
1. Implement the initial functions.
----by Wu Zhijian  12/22/2010
2. 2013-12-09 wu xueliang collate it
*******************************************************************************/
#ifndef _SDK_GPRS_H_
#define _SDK_GPRS_H_

#ifdef __cplusplus
extern "C" {
#endif

/* sdk_GetLibGprsVersion
********************************************************************************
Description : get the version of GPRS LIB.
Input Param : none
Output Param: 
                sVer: A pointer to the version of GPRS LIB.
Return      : none
Remarks     :  the format of GPRS LIB is V0.0.1_20131211.

*******************************************************************************/
void sdk_GetLibGprsVersion(char *sVer);

/* sdk_OpenGprsSerialCom
********************************************************************************
Description : opens the serial port that GPRS module uses.
Input Param : none
Output Param: none
Return      :
                 0: Success
          -1: Error
Remarks     :   Please refer to the Serial part for details.
*******************************************************************************/
int sdk_OpenGprsSerialCom(void);

/* sdk_CloseGprsSerialCom
********************************************************************************
Description : closes the serial port that GPRS module uses.
Input Param : none
Output Param: none
Return      :
                 0: Success
        -1: Error
Remarks     :   none
*******************************************************************************/
int sdk_CloseGprsSerialCom(void);

/* sdk_GprsSetCPIN
********************************************************************************
Description : unlock SIM card.
Input Param : pin -original pin(SIM card's PIN)
Output Param: none
Return      :
//      0   SIM card is ready or unlock success.
        -1: no SIM card in the slot.
        -2: waiting PIN to be given.
        -3: waiting PUK to be given.
        -4: other error.
Remarks     : none
*******************************************************************************/
int sdk_GprsSetCPIN(char *pin, ...);

/* sdk_GprsInqCPIN
********************************************************************************
Description : checks the status of SIM card.
Input Param : none
Output Param: none
Return      :
                 0: SIM card is ready.
        -1: no SIM card in the slot.
        -2: waiting PIN to be given.
        -3: waiting PUK to be given.
        -4: other error.
Remarks     : none
*******************************************************************************/
int sdk_GprsInqCPIN(void);

/* sdk_GprsGetSQ
********************************************************************************
Description : gets the signal strength.
Input Param : none
Output Param:
                nRssi: A pointer to the current Received Signal Strength Indication.
                nBer : A pointer to the Baud Error Rate.
Return      :
                 0: Success
        -1: Error
Remarks     : none
*******************************************************************************/
int sdk_GprsGetSQ( unsigned short *nRssi, unsigned short *nBer );

/* sdk_GprsNetRegReport
********************************************************************************
Description : reports whether the GPRS module has been registered in the network.
Input Param : none
Output Param: none
Return      :
                 0: Success to register
        -1: register has not been accomplished.
Remarks     : none
*******************************************************************************/
int sdk_GprsNetRegReport(void);

/* sdk_GprsPing
********************************************************************************
Input Param :   sIPaddr     : address or domain name of the remote host,string type.
                sRetryNum   : the number of Ping Echo Request to send, 1-64 (default 4)
                nLen            : the length of Ping Echo request message, 32-1460 (default 32);
                nTimeout    : the timeout, in 100 ms units, waiting a single Echo Reply
                                                    1-600 (default 50)
                nTTL            : time to live, 1-255sec (default 128)
Output Param:   sRespone,the result of ping return
Return Value :
              0 :   Success
             -1 :   error,execute ping command failure or ping remote host failure(in this case, *sRespone is   meaningless)
Remarks     :
            Once the single Echo Reply message is receive a string like that is displayed:
            #PING: <replyId>,<Ip Address>,<replyTime>,<ttl>
            Where:
            <replyId> - Echo Reply number
            <Ip Address> - IP address of the remote host
            <replyTime> - time, in 100 ms units, required to receive the response
            <ttl> - time to live of the Echo Reply message
            Note: when the Echo Request timeout expires (no reply received on time
                the response will contain <replyTime> set to 600 and <ttl> set to 255
*******************************************************************************/
int sdk_GprsPing(int mode, char *sIPaddr, unsigned char sRetryNum, int nLen, int nTimeout, unsigned char nTTL, char *sRespone);
//int sdk_GprsPing(char *sIPaddr, unsigned char sRetryNum, int nLen, int nTimeout, unsigned char nTTL, char *sRespone);

/* sdk_GprsPowerOn
********************************************************************************
Description : powers on the GPRS module.
Input Param : none
Output Param: none
Return      :
                 0: Success
        -1: Error
Remarks     : none
*******************************************************************************/
int sdk_GprsPowerOn(void);

/* sdk_GprsInit
********************************************************************************
Description : This function initializes the GPRS module, including:
                    1.  Close the command echo
                    2.  Set the ICEE module as +CME ERROR:<err> reports, with <err> in numeric format
                    3.  Check whether the SIM card exists.
                    4.  Set as "Not sending +++ to the remote host".
Input Param : none
Output Param: none
Return      :
                 0: Success
        -1: Error
        -2: no SIM card.
Remarks     : none
*******************************************************************************/
int sdk_GprsInit(void);

/* sdk_GprsConfigForTcp
********************************************************************************
Description : sets up the configuration for TCP connection.
Input Param :
                szAPN           : A pointer to the Access Point Name.max lenth is 30.
                szUserName   : A pointer to the user name to access. max lenth is 30.
                szUserPwd     : A pointer to the password.max lenth is 30.
                nConnectTimeOut : The connection time. If it can not establish a connection to the remote
                                 WAN server with this timeout, an error will occur.
                                     0 - There is no time out.
                                     N - The time out value (in milliseconds).
Output Param: none
Return      :
                 0: Success
        -1: Error
Remarks     :
*******************************************************************************/
int sdk_GprsConfigForTcp(char *szAPN, char *szUserName, char *szUserPwd,
                         unsigned short nConnectTimeOut);

/* sdk_GprsUp
********************************************************************************
Description :   This function attaches the terminal to GPRS service.
Parameters  :   N/A
Return Value:
            0   :   Success
            -1  :   Error: fails to register the GPRS module.
            -2  :   attach the terminal to GPRS service failure
            -3  :   Error: fails to check whether GPRS module has been activated
            -4  :   Error: fails to activate the GPRS module
Remarks     :   None
*******************************************************************************/
int sdk_GprsUp(void);

/* sdk_GprsTcpConnect
********************************************************************************
Description : establishes a connection to the remote WAN host.
Input Param :
                 szRemoteIP : A pointer to the address of the remote host, which can be either of the two:
                                  - any valid IP address in the format "xxx.xxx.xxx.xxx"
                                  - any host name to be solved with a DNS query
                 nRemotePort: The accessing port of the remote host.
Output Param: none
Return      :
               0: Success
        -1: fails to configure the module.
        -2: fails to attach the terminal to GPRS service.
        -3: fails to check whether the GPRS module is activated.
        -4: fails to activate the GPRS module.
        -5: fails to connect the remote host.
Remarks     : none
*******************************************************************************/
int sdk_GprsTcpConnect(char *szRemoteIP, unsigned short nRemotePort);

/*sdk_GprsSendData
********************************************************************************
Description :This function sends data to the socket path
Parameters  :
            pData            :  The pointer to the data that user wants to send.
            nExpSendLen :   The length of the data that user wants to send.
            nTimeOut    :   The timeout to send data (in seconds).
            pRealSendLen :  An output pointer to the length of the data that user sends
                                            successfully.
Return Value:
            0   Success£¬which means ¡°nExpSendLen=* pRealSendLen¡±
            -1  Error, * pRealSendLen is meaningless.
            -2  *pData is NULL; or *pRealSendLen is NULL, * pRealSendLen is meaningless.
            -3  When sending data, * pRealSendLen is the length of the data that user sends successfully in the period of nTimeOut.
            -4  send error, pls excute sdk_GprsDisConnect().
Remarks     :   It can only be invoked after the socket has been established, otherwise error will occur
*******************************************************************************/
int sdk_GprsSendData(unsigned char *pData, unsigned long nDataLen , unsigned long *sent_len, unsigned short TimeOut);

/*sdk_GprsRecvData
********************************************************************************
Description :This function receives the data from the socket.
Parameters  :
            pData   : An output pointer to the data received.
            nExpRecvLen : The length of the data to receive.
                        If user is not sure the length of the data to receive, please set this
                        parameter as 0, then this function will return if timeout. The data
                        actually received is saved in *pData, The length of the data
                        actually received is shown in *pRealRecvLen.
            pRealRecvLen : An output pointer to the length of the data received.
            nTimeOut    :   The timeout (in seconds).
Return Value:
            0   Success£¬£¬which means ¡°nExpRecvLen=* pRealRecvLen¡±
            -1  Error, * pRealRecvLen is meaningless.
            -2  Error, (pData=NULL or pRealRecvLen=NULL)
            -3  Timeout error: * pRealRecvLen is the length of the data actually received.
Remarks         :   None
*******************************************************************************/
int sdk_GprsRecvData(unsigned char *pData, unsigned long nExpRecvLen,
                     unsigned long *pRealRecvLen , unsigned short nTimeOut);

/*sdk_GprsRecvDataExt
********************************************************************************
Description :This function receives the data from the socket.
Parameters  :
            pData   : An output pointer to the data received.
            nExpRecvLen : The length of the data to receive.
                        If user is not sure the length of the data to receive, please set this
                        parameter as 0, then this function will return if timeout. The data
                        actually received is saved in *pData, The length of the data
                        actually received is shown in *pRealRecvLen.
            pRealRecvLen: An output pointer to the length of the data received.
            nTimeOut :  The timeout (in seconds).
Return Value:
            0   Success,which means ¡°nExpRecvLen=* pRealRecvLen¡±
            -1  Error, * pRealRecvLen is meaningless.
            -2  Error, (pData=NULL or pRealRecvLen=NULL)
Remarks     :   None
*******************************************************************************/
//int sdk_GprsRecvDataExt(unsigned char *pData, unsigned long nExpRecvLen,
//                        unsigned long *pRealRecvLen , unsigned short nTimeOut);

/* sdk_GprsTcpDisConnect
********************************************************************************
Description : closes the socket (not the GPRS connection).
Input Param : none
Output Param: none
Return      :
               0: Success
        -1: Error
Remarks     : none
*******************************************************************************/
int sdk_GprsTcpDisConnect(void);

/* sdk_GprsDown
********************************************************************************
Description : closes the GPRS net .
Input Param : none
Output Param: none
Return      :
               0: Success
        -1: Error
Remarks     : none
*******************************************************************************/
int sdk_GprsDown(void);

/* sdk_GprsPowerOff
********************************************************************************
Description : powers off the GPRS module.
Input Param : none
Output Param: none
Return      :
               0: Success
        -1: Error
Remarks     :  After invoking this function, it is suggested to wait for 2 seconds before powering on the GPRS module again.
*******************************************************************************/
int sdk_GprsPowerOff(void);

/*sdk_GprsSetTransmode
********************************************************************************
Description  :This function selects the mode about sending data.
Parameters  :
             mode:  0:transparent; 1:command
Return        :
                 0: Success
          -1: Error
Remarks     :   None
*******************************************************************************/
void sdk_GprsSetTransmode(char mode);

/*sdk_GprsSetModuleType
********************************************************************************
Description :This function selects the type of GPRS module .
Parameters  :
             ModuleType:  0:telit 1:jingwei 2:yiyuan 3:huawei
             PosType:       0:kf900 1:kf605 2:kf323 3:kf439
Return        :
                 0: Success
          -1: Error
Remarks     :   None
*******************************************************************************/
void sdk_GprsSetModuleType(unsigned  short ModuleType, unsigned  short PosType);

/*sdk_GprsSetFunc
********************************************************************************
Description :This function  selects the level of functionality in the ME.
Parameters  :
             state=0: minimum functionality
             state=1:mobile full functionality with power saving disabled (factory default)
             rst=0: do not reset the ME before setting it to <fun> functionality level
                     rst=1 : reset the device. The device is fully functional after the reset.
Return        :
                 0: Success
          -1: Error
Remarks     :   None
*******************************************************************************/
int sdk_GprsSetFunc( unsigned short state, unsigned short rst);

/*sdk_GprsSwitchSIM
********************************************************************************
Description :This function switches the sim card .
Parameters  :
             nIndex=1:analog switch to "SIM1",for KF900G6
             nIndex=2:analog switch to "SIM2",for KF900G6
Return        :
                 0: Success
          -1: Error
Remarks     :   None
*******************************************************************************/
int sdk_GprsSwitchSIM(unsigned char nIndex);

/*sdk_GprsInqPDPAddr
********************************************************************************
Description :This function  shows a list of PDP addresses for the specified context identifiers .
Parameters  :
             mode: a numeric parameter which specifies a particular PDP context
                              definition (see +CGDCONT command). If no <cid> is specified, the
                              addresses for all defined contexts are returned.
Return        :
                 0: Success
          -1: Error
Remarks     :   None
*******************************************************************************/
int sdk_GprsInqPDPAddr(unsigned short mode);

/*  sdk_GprsSetTEChset
********************************************************************************
Description:Set TE Character Set
Input Param:  chset-"GSM","IRA","8859-1","PCCP437","UCS2"
Return        :
                 0: Success
          -1: Error
*******************************************************************************/
int sdk_GprsSetTEChset(char *chset);

/*  sdk_GprsInqTEChset
********************************************************************************
Description:inqury TE Character Set
Output Param:  chset-"GSM","IRA","8859-1","PCCP437","UCS2"
Return        :
                 0: Success
          -1: Error
*******************************************************************************/
int sdk_GprsInqTEChset(char *chset);

/*  sdk_GprsSetSMSCenter
********************************************************************************
Description: Sets the Service Center Address to be used for mobile originated SMS transmissions.
Input Param: saddr -SC phone number in the format defined by <nType>
             nType - 129  national numbering scheme
                   - 145   international numbering scheme (contains the character "+")
Return        :
                 0: Success
          -1: Error
*******************************************************************************/
int sdk_GprsSetSMSCenter(char *saddr, unsigned char nType);

/*  sdk_GprsSetSMSFormat
********************************************************************************
Description:  selects the format of messages used with send, list, read and write commands.
Input Param:
             nType - 0  PDU
                   - 1  Text
Return        :
                 0: Success
          -1: Error
*******************************************************************************/
int sdk_GprsSetSMSFormat(unsigned char nType);

/*  sdk_GprsSetSMSTextPara
********************************************************************************
Description:   select values for additional parameters for storing and sending SMs
               when the text mode is used (+CMGF=1)
Input Param:
             fo  - depending on the command or result code:
                     first octet of 3GPP TS 23.040 SMS-DELIVER, SMS-SUBMIT (default 17),
                     SMS-STATUS-REPORT, or SMS-COMMAND (default 2) in integer format.
             vp  - depending on SMS-SUBMIT <fo> setting
             pid - 3GPP TS 23.040 TP-Protocol-Identifier in integer format.
             dcs - depending on the command or result code:
                   3GPP TS 23.038 SMS Data Coding Scheme (default 0), or Cell
                   Broadcast Data Coding Scheme
Return        :
                 0: Success
          -1: Error
*******************************************************************************/
int sdk_GprsSetSMSTextPara(unsigned char fo, unsigned char vp, unsigned char pid, unsigned char dcs);

/*  sdk_GprsShowSMSTextPara
********************************************************************************
Description:   controls whether detailed header information is shown in text mode (+CMGF=1) result codes.
Input Param:
             nType: - 0  do not show header values
                       - 1  show the values in result codes
Return        :
                 0: Success
          -1: Error
*******************************************************************************/
int sdk_GprsShowSMSTextPara(unsigned char nType);

/*  sdk_GprsIndicateNewSMS
********************************************************************************
Description:  selects the behaviour of the device on how the receiving of
              new messages from the network is indicated to the DTE.
Input Param:
            nType-0-3  unsolicited result codes buffering option
            mt -0-3  result code indication reporting for SMS-DELIVER
            bm- 0,2  broadcast reporting option
            ds- 0,1,2 SMS-STATUS-REPORTs reporting option
            bfr- 0,1 buffered result codes handling method
Return        :
                 0: Success
          -1: Error
*******************************************************************************/
int sdk_GprsIndicateNewSMS(unsigned char nType, unsigned char mt, unsigned char bm,
                           unsigned char ds, unsigned char bfr);

/*  sdk_GprsSendSMSText
********************************************************************************
Description:   sends to the network a message.
Input Param:
            destaddr - - destination address, string type.
            data       - the message data to send
Return        :
                 0: Success
          -1: Error
*******************************************************************************/
int sdk_GprsSendSMSText(char *data, char *destaddr);

/*  sdk_GprsReadIndicateSMS
********************************************************************************
Description:  Get the index of new message
Input Param:
            timeout - time out of response,unit:us
Output Param: nIndex- the index of new mesage
Return        :
                 0: Success
          -1: Error
*******************************************************************************/
int sdk_GprsReadIndicateSMS(unsigned int *nIndex, long timeout);

/*  sdk_GprsReadDirectNewSMS
********************************************************************************
Description:   reads the message to arrive directly, but not save..
Input  Param:timeout-time out of response,unit:us
Output Param:
             sData - message data to read
             sNum - phone number of addresser
             sDate - arrival time of the message to the SC
Return        :
                 0: Success
          -1: Error
*******************************************************************************/
int sdk_GprsReadDirectNewSMS( long timeout, char *sData, char *sNum, char *sDate);

/*  sdk_GprsReadSMS
********************************************************************************
Description:   reports the message with location value <index> from
               <memr> message storage (<memr> is the message storage for read and
               delete SMs as last settings of command +CPMS).
Input  Param:nIndex-the index of message to read
Output Param:
             sData - message data to read
             sState - state of the message
             sNum - phone number of addresser
             sDate - arrival time of the message to the SC
Return        :
                 0: Success
          -1: Error
*******************************************************************************/
int sdk_GprsReadSMS(unsigned int nIndex, char *sData, char *sState, char *sNum, char *sDate);

/*  sdk_GprsSaveSettings
********************************************************************************
Description:  saves settings which have been made by the +CSCA,
              +CSMP and +CSCB commands in local non volatile memory.
Input Param:
             nType : 0 - it saves the settings to NVM (factory default).
                     1..n - SIM profile number; the value of n depends on the SIM and its max is 3
Return        :
                 0: Success
          -1: Error
*******************************************************************************/
int sdk_GprsSaveSettings(unsigned char nType);

/*  sdk_GprsInqStoreSMS
********************************************************************************
Description:   inqury memory storages <memr>, <memw> and <mems> to
               be used for reading, writing, sending and storing SMs.
Input Param:
             nNum - memory room
             nNum[0]- used memory from which messages are read and deleted
             nNum[1]- total memory from which messages are read and deleted
             nNum[2]- used memory from which writing and sending operations are made
             nNum[3]- total memory from which writing and sending operations are made
             nNum[4]- used memory from which received SMs are preferred to be stored
             nNum[5]- total memory from which received SMs are preferred to be stored
Return        :
                 0: Success
          -1: Error
*******************************************************************************/
int sdk_GprsInqStoreSMS(int *nNum);

/*  sdk_GprsSelectStoreSMS
********************************************************************************
Description:  selects memory storages <memr>, <memw> and <mems> to
              be used for reading, writing, sending and storing SMs.
Input Param:
            sMemr: memory from which messages are read and deleted
             "SM" - SIM SMS memory storage
             "ME" - ME internal storage
            sMemw : memory to which writing and sending operations are made
            sMems : memory to which received SMs are preferred to be stored
Return        :
                 0: Success
          -1: Error
*******************************************************************************/
int sdk_GprsSelectStoreSMS(char *sMemr, char *sMemw, char *sMems );

/*  sdk_GprsDeleteSMS
********************************************************************************
Description:  deletes from memory <memr> the message(s).
Input Param:
             nIndex :message index in the selected storage  <memr>  that can have
                     values form 1 to N, where N depends on the available space
             flag : an integer indicating multiple message deletion request.
              0 (or omitted) - delete message specified in <index>
              1  -  delete all read messages from  <memr>  storage, leaving unread
              messages and stored mobile originated messages (whether sent or not)
              untouched
              2  -  delete all read messages from  <memr>  storage and sent mobile
              originated messages, leaving unread messages and unsent mobile
              originated messages untouched
              3  -  delete all  read messages from  <memr>  storage, sent and unsent
              mobile originated messages, leaving unread messages untouched
              4 - delete all messages from <memr> storage.
Return        :
                 0: Success
          -1: Error

*******************************************************************************/
int sdk_GprsDeleteSMS(unsigned int nIndex, unsigned char flag);

/* sdk_GprsInqDNS
********************************************************************************
Description : send a DNS query to solve the host name into an IP address.
Input Param :
                    sHostname:  domain name
Output Param:
                     sIpname: IP address
Return        :
                 0: Success
          -1: Error
*******************************************************************************/
int sdk_GprsInqDNS(char *sHostname, char *sIpname);

/*  sdk_GprsSetDNSIpaddr
********************************************************************************
Description:   manually set primary and secondary DNS servers.
Input Param:
                   cid: context identifier only for telit
                        0 - specifies the GSM context
                        1..5 - numeric parameter which specifies a particular PDP context definition
                   sPridns: manual primary DNS server, string type, in the format
                        "xxx.xxx.xxx.xxx" used for the specified cid;
                   sSecdns:manual secondary DNS server, string type, in the format
                        "xxx.xxx.xxx.xxx" used for the specified cid;
Return :
        0:  Success
        -1:  Failed
*******************************************************************************/
int sdk_GprsSetDNSIpaddr(unsigned char cid, char *sPridns, char *sSecdns);

/* sdk_GprsGetDNSIpaddr
********************************************************************************
Description : send a DNS query to solve the host name into an IP address.
Output Param:
                     cid: context identifier only for telit
                         0 - specifies the GSM context
                         1..5 - numeric parameter which specifies a particular PDP context definition
                     sPridns: manual primary DNS server, string type, in the format
                        "xxx.xxx.xxx.xxx"
                     sSecdns: manual secondary DNS server, string type, in the format
                        "xxx.xxx.xxx.xxx"
Return        :
                 0: Success
          -1: Error
*******************************************************************************/
int sdk_GprsGetDNSIpaddr(unsigned char *cid, char *sPridns, char *sSecdns);

/* sdk_GprsSetDNSIsIporDomain
********************************************************************************
Description : set  module whether use the domain name or an IP address to connet.
Input Param :
                    type:
                           0 - use IP addr to connect
                           1 - use domain name to connect

Return        :
                 0: Success
          -1: Error
*******************************************************************************/
int sdk_GprsSetDNSIsIporDomain(unsigned char type);

/* sdk_GprsGetLocation
********************************************************************************
Description : Get GSM Location.
Input Param :
                    type: - 1 Get location; 2 Get time; 4 Get location and time;
                               5 Get time; 8 Get location
Output Param:
                     longitude
                     latitude
Return        :
                 0: Success
          -1: Error
*******************************************************************************/
int sdk_GprsGetLocation( int type, char *longitude, char *latitude );

/* sdk_GprsSleep
********************************************************************************
Description : set the DTR to OFF to place the module in power saving mode
Input Param : none
Output Param: none
Return      :   none
Remarks     : none
*******************************************************************************/
void sdk_GprsSleep();

/* sdk_GprsWakeup
********************************************************************************
Description : set the DTR to ON(0V) to exit from power saving
Input Param : none
Output Param: none
Return      :   none
Remarks     : none
*******************************************************************************/
void sdk_GprsWakeup();

/* sdk_IsGprsWake
********************************************************************************
Description : inquire the CTS status
Input Param : none
Output Param: none
Return      :
    1 : mobile full funcionality
    0: power saving mode
Remarks     : none
*******************************************************************************/
unsigned short sdk_IsGprsWake();

/* sdk_GprsGetCIMI
********************************************************************************
Description : get the International Mobile Subscriber Identity(IMSI)
Input Param : none
Output Param: 
    imsi: the IMSI value
    mcc: the MCC  value
    mnc: the MNC value
    respone: the error information
Return:
//  0: success
//  -1: fail
Remarks: 
//IMSI - International Mobile Subscriber Identity
//MCC -Mobile Country Code
//MNC - Mobile Network Code
*******************************************************************************/
int sdk_GprsGetCIMI(char *imsi, char *mcc, char *mnc, char *respone);

/* sdk_GprsGetIMEI
********************************************************************************
Description : get the International Mobile Equipment Identity(IMEI)
Input Param : none
Output Param: 
    imei: the IMEI value
Return:
//  0: success
//  -1: fail
Remarks: none
*******************************************************************************/
int sdk_GprsGetIMEI(char *imei);

/* sdk_GprsAct
********************************************************************************
Description : act the mobile occasion
Input Param : none
Output Param: none
Return:
//  0: success
//  -1: fail
Remarks: none
*******************************************************************************/
int sdk_GprsAct();

/* sdk_GprsCUSD
********************************************************************************
Description : allow control of the Unstructed Supplementary Service Data(USSD)
Input Param : 
    sendN: is used to disable/enable the presentation of an unsolicited result code
    sendStr: USSD-string
    sendDcs: GSM3.38 Cell Broadcast Coding Scheme in interger fomat(default is 0)
Output Param: 
    recvN: 
        0 - no further user action required
        1 - further user action required
        2 - USSD terminated by the network
        3 - other local client has responsed
        4 - operation not required
        5 - network timeout
    recvStr: the responsed USSD-string
    recvDcs: the responsed Cell Broadcast Coding Scheme
Return:
//  0: success
//  -1: fail
Remarks: none
*******************************************************************************/
int sdk_GprsCUSD(int sendN, char *sendStr, int sendDcs, int *recvN, char *recvStr, int *recvDcs);

#ifdef __cplusplus
}
#endif
#endif

