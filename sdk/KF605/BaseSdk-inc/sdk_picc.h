/*******************************************************************************
* File Name          : sdk_picc.h
* Author             : guohonglv
* Date First Issued  : 2012年11月5日20:28:13
* Description        : 读取M卡逻辑的头文件
* Notes              : 该头文件的功能是完成对M卡的系列操作。
                       请注意，为了统一内置非接读卡器和外置非接读卡器的函数接口。对于操作M卡的函数，函数本身的返回值
                       表明该指令是否已经成功发送到KF311，并且KF311已经成功返回了数据到上位机。
                       因此，函数返回值为success，仅仅表明命令已经下发。
                       命令下发后，是否执行成功，请判断 pRespCode 这个状态码。
                       函数返回值表明的是KF311与KF900/KF605的--------通讯状态，
                       函数最后一个参数pRespCode表明的是该操作的-----执行状态。

                       因此，如果使用KF311作为读卡器，要判断读卡器与KF900/KF605之间的通讯是否正常，请判断函数返回值。
                       如果指令已经正常下发了，内置或者外置的读卡器执行得怎样，都请判断 pRespCode。

Attention            : 请注意所有函数会在等待接收数据过程中，捕获期间用户的按键，
                       如果在这段时间内。用户按下取消键，函数马上退出，返回 0xfc
********************************************************************************/

#ifndef SDK_PICC_H
#define SDK_PICC_H

#define KF311_MSG_LEN_BU      1024
#define KF311_MSG_WAIT_TIME   3000

#define MIFRE_DEBUG
#define PICC_PARA  ST_PICC_PARA//保持与以前命名一致

// 函数返回码定义
#define RET_RF_OK                  0x00    // 操作成功
#define RET_RF_ERR_PARAM           0x01    // 0x09 参数错误
#define RET_RF_ERR_NO_OPEN         0x02    // 0x08 射频卡模块未开启

#define RET_RF_ERR_NOT_ACT         0x13    // 0x0B 卡片未激活 // added by liuxl 20070925
#define RET_RF_ERR_MULTI_CARD      0x14    // 多卡冲突
#define RET_RF_ERR_TIMEOUT         0x15    // 超时无响应
#define RET_RF_ERR_PROTOCOL        0x16    // 协议错误

#define RET_RF_ERR_TRANSMIT        0x17    // 通信传输错误
#define RET_RF_ERR_AUTH            0x18    // 验证失败
#define RET_RF_ERR_NO_AUTH         0x19    // 扇区未认证
#define RET_RF_ERR_VAL             0x1A    // 数值块数据格式有误
#define RET_RF_ERR_CARD_EXIST      0x1B    // 卡片仍在感应区内
#define RET_RF_ERR_STATUS          0x1C    // 卡片未进入协议态时调用APDU命令,或已进入协议态时调用M1命令// added by liuxl 20070925

#define PICC_TYPE_A  0x81
#define PICC_TYPE_B  0x82
#define PICC_TYPE_F  0x84
#define PICC_TYPE_M 0x88

typedef struct
{
    unsigned char  drv_ver[5];  //e.g. "1.01A", read only
    unsigned char drv_date[12]; //e.g. "2006.08.25",read only

    unsigned char a_conduct_w;  //Type A conduct write enable: 1--enable,else disable
    unsigned char a_conduct_val;//Type A output conduct value,0~63

    unsigned char b_modulate_w;  //Type B modulate index write enable,1--enable,else disable
    unsigned char b_modulate_val;//Type B modulate index value

    unsigned char card_buffer_w;//added in V1.00C,20061204
    unsigned short card_buffer_val;//max_frame_size of PICC

    unsigned char wait_retry_limit_w;//added in V1.00F,20071212
    unsigned short wait_retry_limit_val;//max retry count for WTX block requests,default 3

    // 20080617
    unsigned char card_type_check_w; //
    unsigned char card_type_check_val; //

    unsigned char card_RxThreshold_w;   // card RxThreshold
    unsigned char card_RxThreshold_val;

    unsigned char f_modulate_w;
    unsigned char f_modulate_val;  //FeliCa card modulate

    unsigned char reserved[20];  //

} ST_PICC_PARA;

typedef struct
{
    unsigned char        Command[ 4 ]; // CLA INS  P1 P2
    unsigned short       Lc;           // P3
    unsigned char        DataIn[512];
    unsigned short       Le;
} APDU_SEND;

typedef struct
{
    unsigned short       LenOut;    // length of dataout
    unsigned char        DataOut[512];
    unsigned char        SWA;
    unsigned char        SWB;
} APDU_RESP;

//0909
typedef struct
{
    unsigned int     Le;              //接收数据长度
    unsigned char    inf[200];     //接收数据存放指针
    unsigned short SW;        //接收数据状态字
} APDU_RES;

extern int sdk_Picc_InOut;

/**************************************************************************************
Function    :   void sdk_PiccSetMode(int picc_InOut)
Description :   This function set PICC is in or out
Parameters  :   picc_InOut: 1 out
                            0 inner
Return Value    :   none
**************************************************************************************/
void sdk_PiccSetMode(int picc_InOut);


/**************************************************************************************
Function    :   void sdk_PiccGetMode()
Description :   This function set PICC is in or out
Parameters  :   none
Return Value    :   picc_InOut: 1 out
                                0 inner
**************************************************************************************/
int sdk_PiccGetMode();


/**************************************************************************************
Function    :   unsigned char sdk_PiccOpen(unsigned char *pRespCode)
Description :   This function powers on and resets PICC module, then checks initiative state of PICC module whether is normal after reseting.
Parameters  :   pRespCode: 1~4   Error; 1 and 2 means timeout, 3 and 4 means initiative state error.
Return Value    :   0      Success
                    0xff   发送/接收数据错误
                    other  请参阅 <pos_picc_bu.h>
**************************************************************************************/
unsigned char sdk_PiccOpen(unsigned char *pRespCode);
//unsigned char sdk_PiccOpen(void);


/**************************************************************************************
Function    :   unsigned char sdk_PiccSetup (unsigned char mode, PICC_PARA *picc_para, unsigned char *pRespCode)
Description :   This function writes specific parameters or reads current parameters.
Input           :   mode : appoint to the mode of parameter setup, 'r' or 'R' means read, 'w' or 'W' means write.
                    picc_para : the structural pointer to set parameter.
Output    :   pRespCode: 1      Parameter Error
                         2      PICC module isn't opened
                        others Exceptional error
Return Value    :   0      Success
                    0xff   发送/接收数据错误
                    other  请参阅 <pos_picc_bu.h>
**************************************************************************************/
unsigned char sdk_PiccSetup (unsigned char mode, PICC_PARA *picc_para, unsigned char *pRespCode);


/**************************************************************************************
Function    :   unsigned char sdk_PiccDetect(unsigned char Mode, unsigned char *CardType, unsigned char *SerialInfo, unsigned char *CID, unsigned char *Other, unsigned char *pRespCode)
Description :   This function detects RF card by specific mode,if successful, then select it and make it enable.
Input           :   Mode : appoint to the mode of detecting PICC card.
                        0x81|0x82|0x88|0x84 detect 'A' , 'B' ,'C','M'card;
                        0x81-only detect 'A' card one time;
                        0x82-only detect 'B' card one time;
                        0x88-only detect 'M1' card one time;
                        0x84-only detect 'C' card one time;
                        others-keep reserved.
Output          :   CardType : the pointer to identify card's type. Type:'A','B','M'=M1 card.
                        SerialInfo : point to buffer's first address which access card's serial number.
                        CID : logic channel number of card,value is 0 to 14.
                        Other : access detailed error code, response information etc.
                        pRespCode:  1      Parameter Error (invalid mode parameter)
                                    2      PICC module isn't opened
                                    3      not detect any card (no specific type of card in the inductive field)
                                    4      too many cards in the inductive field (communication conflict)
                                    6      protocol error
                                    others Exceptional error
Return Value    :   0       Success
                    0xfc    用户按取消键取消寻卡
                    0xff    发送/接收数据错误
                    others  Exceptional error

注意            :  请注意该函数会在等待接收数据过程中，捕获期间用户的按键，
                   如果在这段时间内。用户按下取消键，函数马上退出，返回 0xfc
**************************************************************************************/
unsigned char sdk_PiccDetect(unsigned char Mode, unsigned char *CardType, unsigned char *SerialInfo, unsigned char *CID, unsigned char *Other, unsigned char *pRespCode);
//unsigned char sdk_PiccDetect(unsigned char Mode,unsigned char *CardType,unsigned char *SerialInfo,unsigned char *CID,unsigned char *Other);


/**************************************************************************************
Function    :   unsigned char sdk_PiccIsocommand(unsigned char cid,APDU_SEND *ApduSend,APDU_RESP *ApduRecv, unsigned char *pRespCode)
Description :   This function sends data of Type APDU to PICC and receive response from PICC in specifc channel.
Input         :   cid : logic channel number of card, value is 0 to 14.
                        ApduSend : the pointer to identify APDU_SEND.
Output       :       ApduRecv : the pointer to identify APDU_RESP.
                        pRespCode: 0      Success
                        1      Parameter Error
                        2      PICC module isn't opened
                        3      not make any card awake
                        4      transfers error
                        6      protocol error
                        others communication error
Return Value    :   0      Success
                    0xff   发送/接收数据错误
                    other  请参阅 <pos_picc_bu.h>
**************************************************************************************/
unsigned char sdk_PiccIsocommand(unsigned char cid, APDU_SEND *ApduSend, APDU_RESP *ApduRecv, unsigned char *pRespCode);


/**************************************************************************************
Function    :   unsigned char sdk_PiccRemove(unsigned char mode,unsigned char cid, unsigned char *pRespCode)
Description :   This function make card in the HALT state by specific mode, or even detected the card whether removed from inductive field.
Input           :   cid : logic channel number of card,value is 0 to 14.
                        mode : operation mode. 'h' or 'H' means halt, not detect  the card whether remove magnetic field.'r' or 'R' means remove, execute whole flow about removing card.
Output    :   pRespCode: 0      Success
                        1      Parameter Error
                        2      PICC module isn't opened
                        3      not make any card awake
                        4      transfers error
                        5      protocol error
                        6      not remove card
                        others exceptional error
Return Value    :   0      Success
                    0xff   发送/接收数据错误
                    other  请参阅 <pos_picc_bu.h>
**************************************************************************************/
unsigned char sdk_PiccRemove(unsigned char mode, unsigned char cid, unsigned char *pRespCode);


/**************************************************************************************
Function    :   void sdk_PiccClose(, unsigned char *pRespCode)
Description :   This function power off contactless IC card module.
Input           :   None
Output    :   pRespCode: status from KF311 (the return value of function if success)
Return Value    :   0      Success
                    0xff   发送/接收数据错误
                    other  请参阅 <pos_picc_bu.h>
Remarks         :
**************************************************************************************/
unsigned char sdk_PiccClose(unsigned char *pRespCode);
//unsigned char sdk_PiccClose(void);


/**************************************************************************************
Function    :   unsigned char sdk_PiccCmdexchange(unsigned int uiSendLen, unsigned char* paucInData, unsigned int* puiRecLen, unsigned char* paucOutData, unsigned char *pRespCode)
Description :   It exchanges APDU data with PICC; terminal sends data to PICC and receives response from PICC.
Input           :   uiSendLen  :  The length of command that user wants to send.
                        paucInData : The command is going to be sent.
Output          :       puiRecLen  : The length of data that user wants to receive.
                        paucOutData : The pointer that is to save the data from PICC.
                        pRespCode: 表示该命令是否已经正确执行
Return Value    :   0      Success
                    0xff   发送/接收数据错误
                    other  请参阅 <pos_picc_bu.h>
**************************************************************************************/
unsigned char sdk_PiccCmdexchange(unsigned int uiSendLen, unsigned char* paucInData, unsigned int* puiRecLen, unsigned char* paucOutData, unsigned char *pRespCode);


/**************************************************************************************
Function     :  unsigned char sdk_PiccFelicaCmdExchange(unsigned char* pucInData, unsigned int uiSendLen, unsigned char* pucOutData,unsigned int* puiRecLen, unsigned int TimeOutN )
Description :  It exchanges APDU data with PICC; terminal sends data to PICC and receives response from PICC.
Input         :  uiSendLen  :  The length of command that user wants to send.
                    paucInData : The command is going to be sent.
                    TimeOutN: 超时时间
Output       :   puiRecLen  : The length of data that user wants to receive.
                    paucOutData : The pointer that is to save the data from PICC.
                        
Return Value    :   0      Success
                        0xff   发送/接收数据错误
                        other  请参阅 <pos_picc_bu.h>
Notice         : for szt
**************************************************************************************/
unsigned char sdk_PiccFelicaCmdExchange(unsigned char* pucInData, unsigned int uiSendLen, unsigned char* pucOutData, unsigned int* puiRecLen, unsigned int TimeOutN );


/**************************************************************************************
Function    :   unsigned char sdk_PiccAPDU(unsigned int cid, unsigned char *pucInDatasend, unsigned int len, APDU_RES *pStuApduResp)
Description :   This function make card in the HALT state by specific mode, or even detected the card whether removed from inductive field.
Input         :   cid:logic channel number of card,value is 0 to 14.
                     pucInDatasend :  输入的数据
                     len  : 输入的数据长度
Output       :   pStuApduResp : 返回数据结构
Return Value    :   0      Success
                        0xff   发送/接收数据错误
                        other  请参阅 <pos_picc_bu.h>
Notice         : for szt
**************************************************************************************/
unsigned char sdk_PiccAPDU(unsigned int cid, unsigned char *pucInDatasend, unsigned int len, APDU_RES *pStuApduResp);


/************************************************************************************* 
 *函数名:sdk_M1Authority( unsigned char ucType,unsigned char ucBlkNo,
                               unsigned char *pucPwd,unsigned char *pucSerialNo, unsigned char *pRespCode);
 *功能:     Mifare卡扇区密码认证
 * 参数：
 *      ucType      : 扇区密码组类别( 'A'或'B' )
 *      ucBlkNo     : 待认证块号( 根据卡片不同取值范围不同 )
 *      pucPwd      : 待认证块所在扇区密码( 6字节 )
 *      pucSerialNo : 待认证卡序列号( 4字节 )
  *    pRespCode    : 0表示认证成功，输出参数。
 * 返回：
 *      0: 命令已经执行
 *      其他，失败
 *************************************************************************************/
unsigned char sdk_M1Authority( unsigned char ucType, unsigned char ucBlkNo,
                               unsigned char *pucPwd, unsigned char *pucSerialNo, unsigned char *pRespCode);


/*************************************************************************************
 * 函数名:unsigned char sdk_M1ReadBlock( unsigned char ucBlkNo,unsigned char *pucBlkValue, unsigned char *pRespCode );                               
 * 功能:   读已经经过Mifare卡扇区密码认证的块数据
 * 参数：
 * ucBlkNo     : 指定待读块号( 根据卡片不同取值范围不同 )
 * pucBlkValue : 读数据缓冲区( 16字节 )
 * pRespCode   : 0-表示读取成功，输出参数。
 * 返回：
 *      0: 命令已经执行
 *      其他，失败
 *************************************************************************************/
unsigned char sdk_M1ReadBlock( unsigned char ucBlkNo, unsigned char *pucBlkValue, unsigned char *pRespCode );


/**************************************************************************************
 *函数名:unsigned char sdk_M1WriteBlock( unsigned char ucBlkNo, unsigned char *pucBlkValue, unsigned char *pRespCode);                              
 *功能: 写数据到已经经过Mifare卡扇区密码认证的块
 * 参数：
 *      ucBlkNo     : 指定待写块号( 根据卡片不同取值范围不同 )
 *      pucBlkValue : 写数据缓冲区( 16字节 )
 *      pRespCode   : 0-写入成功
 * 返回：
 *      0: 命令已经执行
 *      其他，失败
 **************************************************************************************/
unsigned char sdk_M1WriteBlock( unsigned char ucBlkNo, unsigned char *pucBlkValue, unsigned char *pRespCode);


/****************************************************************************************
 *函数名:unsigned char sdk_M1Operate( unsigned char  ucType, unsigned char  ucBlkNo,
                    unsigned char *pucValue,unsigned char  ucUpdateBlkNo,unsigned char *pRespCode);
 *功能:  Mifare卡充值、减值、备份命令
 * 参数：
 *      ucType        : 操作类型
 *                        可以取值：
 *                           '+' : 对值块充值
 *                           '-' : 对值块减值
 *                           '>' : 备份块数据到同扇区的其他块
 *      ucBlkNo       : 待操作块号( 根据卡片不同取值范围不同 )
 *      pucValue      : 待操作值( 4字节 )
 *      ucUpdateBlkNo : 目标块
   *    pRespCode     : 0-操作成功
 * 返回：
 *      0,操作成功
 *      其他，失败
 ****************************************************************************************/
unsigned char sdk_M1Operate( unsigned char  ucType, unsigned char  ucBlkNo,
                             unsigned char *pucValue, unsigned char  ucUpdateBlkNo, unsigned char *pRespCode);


/***************************************************************************************
 * 函数名:void sdk_PiccLibVersion(unsigned char buf[]);
 * 功能: 获取当前库文件的版本号
 * 参数：
 * buf     : 输出参数，获取版本号-注意输出6个char的长度
 * 返回：
 *      无
 ***************************************************************************************/
void sdk_PiccLibVersion(unsigned char buf[]);

#endif

