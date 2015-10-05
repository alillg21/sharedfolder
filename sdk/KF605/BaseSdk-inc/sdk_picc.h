/*******************************************************************************
* File Name          : sdk_picc.h
* Author             : guohonglv
* Date First Issued  : 2012��11��5��20:28:13
* Description        : ��ȡM���߼���ͷ�ļ�
* Notes              : ��ͷ�ļ��Ĺ�������ɶ�M����ϵ�в�����
                       ��ע�⣬Ϊ��ͳһ���÷ǽӶ����������÷ǽӶ������ĺ����ӿڡ����ڲ���M���ĺ�������������ķ���ֵ
                       ������ָ���Ƿ��Ѿ��ɹ����͵�KF311������KF311�Ѿ��ɹ����������ݵ���λ����
                       ��ˣ���������ֵΪsuccess���������������Ѿ��·���
                       �����·����Ƿ�ִ�гɹ������ж� pRespCode ���״̬�롣
                       ��������ֵ��������KF311��KF900/KF605��--------ͨѶ״̬��
                       �������һ������pRespCode�������Ǹò�����-----ִ��״̬��

                       ��ˣ����ʹ��KF311��Ϊ��������Ҫ�ж϶�������KF900/KF605֮���ͨѶ�Ƿ����������жϺ�������ֵ��
                       ���ָ���Ѿ������·��ˣ����û������õĶ�����ִ�е������������ж� pRespCode��

Attention            : ��ע�����к������ڵȴ��������ݹ����У������ڼ��û��İ�����
                       ��������ʱ���ڡ��û�����ȡ���������������˳������� 0xfc
********************************************************************************/

#ifndef SDK_PICC_H
#define SDK_PICC_H

#define KF311_MSG_LEN_BU      1024
#define KF311_MSG_WAIT_TIME   3000

#define MIFRE_DEBUG
#define PICC_PARA  ST_PICC_PARA//��������ǰ����һ��

// ���������붨��
#define RET_RF_OK                  0x00    // �����ɹ�
#define RET_RF_ERR_PARAM           0x01    // 0x09 ��������
#define RET_RF_ERR_NO_OPEN         0x02    // 0x08 ��Ƶ��ģ��δ����

#define RET_RF_ERR_NOT_ACT         0x13    // 0x0B ��Ƭδ���� // added by liuxl 20070925
#define RET_RF_ERR_MULTI_CARD      0x14    // �࿨��ͻ
#define RET_RF_ERR_TIMEOUT         0x15    // ��ʱ����Ӧ
#define RET_RF_ERR_PROTOCOL        0x16    // Э�����

#define RET_RF_ERR_TRANSMIT        0x17    // ͨ�Ŵ������
#define RET_RF_ERR_AUTH            0x18    // ��֤ʧ��
#define RET_RF_ERR_NO_AUTH         0x19    // ����δ��֤
#define RET_RF_ERR_VAL             0x1A    // ��ֵ�����ݸ�ʽ����
#define RET_RF_ERR_CARD_EXIST      0x1B    // ��Ƭ���ڸ�Ӧ����
#define RET_RF_ERR_STATUS          0x1C    // ��Ƭδ����Э��̬ʱ����APDU����,���ѽ���Э��̬ʱ����M1����// added by liuxl 20070925

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
    unsigned int     Le;              //�������ݳ���
    unsigned char    inf[200];     //�������ݴ��ָ��
    unsigned short SW;        //��������״̬��
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
                    0xff   ����/�������ݴ���
                    other  ����� <pos_picc_bu.h>
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
                    0xff   ����/�������ݴ���
                    other  ����� <pos_picc_bu.h>
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
                    0xfc    �û���ȡ����ȡ��Ѱ��
                    0xff    ����/�������ݴ���
                    others  Exceptional error

ע��            :  ��ע��ú������ڵȴ��������ݹ����У������ڼ��û��İ�����
                   ��������ʱ���ڡ��û�����ȡ���������������˳������� 0xfc
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
                    0xff   ����/�������ݴ���
                    other  ����� <pos_picc_bu.h>
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
                    0xff   ����/�������ݴ���
                    other  ����� <pos_picc_bu.h>
**************************************************************************************/
unsigned char sdk_PiccRemove(unsigned char mode, unsigned char cid, unsigned char *pRespCode);


/**************************************************************************************
Function    :   void sdk_PiccClose(, unsigned char *pRespCode)
Description :   This function power off contactless IC card module.
Input           :   None
Output    :   pRespCode: status from KF311 (the return value of function if success)
Return Value    :   0      Success
                    0xff   ����/�������ݴ���
                    other  ����� <pos_picc_bu.h>
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
                        pRespCode: ��ʾ�������Ƿ��Ѿ���ȷִ��
Return Value    :   0      Success
                    0xff   ����/�������ݴ���
                    other  ����� <pos_picc_bu.h>
**************************************************************************************/
unsigned char sdk_PiccCmdexchange(unsigned int uiSendLen, unsigned char* paucInData, unsigned int* puiRecLen, unsigned char* paucOutData, unsigned char *pRespCode);


/**************************************************************************************
Function     :  unsigned char sdk_PiccFelicaCmdExchange(unsigned char* pucInData, unsigned int uiSendLen, unsigned char* pucOutData,unsigned int* puiRecLen, unsigned int TimeOutN )
Description :  It exchanges APDU data with PICC; terminal sends data to PICC and receives response from PICC.
Input         :  uiSendLen  :  The length of command that user wants to send.
                    paucInData : The command is going to be sent.
                    TimeOutN: ��ʱʱ��
Output       :   puiRecLen  : The length of data that user wants to receive.
                    paucOutData : The pointer that is to save the data from PICC.
                        
Return Value    :   0      Success
                        0xff   ����/�������ݴ���
                        other  ����� <pos_picc_bu.h>
Notice         : for szt
**************************************************************************************/
unsigned char sdk_PiccFelicaCmdExchange(unsigned char* pucInData, unsigned int uiSendLen, unsigned char* pucOutData, unsigned int* puiRecLen, unsigned int TimeOutN );


/**************************************************************************************
Function    :   unsigned char sdk_PiccAPDU(unsigned int cid, unsigned char *pucInDatasend, unsigned int len, APDU_RES *pStuApduResp)
Description :   This function make card in the HALT state by specific mode, or even detected the card whether removed from inductive field.
Input         :   cid:logic channel number of card,value is 0 to 14.
                     pucInDatasend :  ���������
                     len  : ��������ݳ���
Output       :   pStuApduResp : �������ݽṹ
Return Value    :   0      Success
                        0xff   ����/�������ݴ���
                        other  ����� <pos_picc_bu.h>
Notice         : for szt
**************************************************************************************/
unsigned char sdk_PiccAPDU(unsigned int cid, unsigned char *pucInDatasend, unsigned int len, APDU_RES *pStuApduResp);


/************************************************************************************* 
 *������:sdk_M1Authority( unsigned char ucType,unsigned char ucBlkNo,
                               unsigned char *pucPwd,unsigned char *pucSerialNo, unsigned char *pRespCode);
 *����:     Mifare������������֤
 * ������
 *      ucType      : �������������( 'A'��'B' )
 *      ucBlkNo     : ����֤���( ���ݿ�Ƭ��ͬȡֵ��Χ��ͬ )
 *      pucPwd      : ����֤��������������( 6�ֽ� )
 *      pucSerialNo : ����֤�����к�( 4�ֽ� )
  *    pRespCode    : 0��ʾ��֤�ɹ������������
 * ���أ�
 *      0: �����Ѿ�ִ��
 *      ������ʧ��
 *************************************************************************************/
unsigned char sdk_M1Authority( unsigned char ucType, unsigned char ucBlkNo,
                               unsigned char *pucPwd, unsigned char *pucSerialNo, unsigned char *pRespCode);


/*************************************************************************************
 * ������:unsigned char sdk_M1ReadBlock( unsigned char ucBlkNo,unsigned char *pucBlkValue, unsigned char *pRespCode );                               
 * ����:   ���Ѿ�����Mifare������������֤�Ŀ�����
 * ������
 * ucBlkNo     : ָ���������( ���ݿ�Ƭ��ͬȡֵ��Χ��ͬ )
 * pucBlkValue : �����ݻ�����( 16�ֽ� )
 * pRespCode   : 0-��ʾ��ȡ�ɹ������������
 * ���أ�
 *      0: �����Ѿ�ִ��
 *      ������ʧ��
 *************************************************************************************/
unsigned char sdk_M1ReadBlock( unsigned char ucBlkNo, unsigned char *pucBlkValue, unsigned char *pRespCode );


/**************************************************************************************
 *������:unsigned char sdk_M1WriteBlock( unsigned char ucBlkNo, unsigned char *pucBlkValue, unsigned char *pRespCode);                              
 *����: д���ݵ��Ѿ�����Mifare������������֤�Ŀ�
 * ������
 *      ucBlkNo     : ָ����д���( ���ݿ�Ƭ��ͬȡֵ��Χ��ͬ )
 *      pucBlkValue : д���ݻ�����( 16�ֽ� )
 *      pRespCode   : 0-д��ɹ�
 * ���أ�
 *      0: �����Ѿ�ִ��
 *      ������ʧ��
 **************************************************************************************/
unsigned char sdk_M1WriteBlock( unsigned char ucBlkNo, unsigned char *pucBlkValue, unsigned char *pRespCode);


/****************************************************************************************
 *������:unsigned char sdk_M1Operate( unsigned char  ucType, unsigned char  ucBlkNo,
                    unsigned char *pucValue,unsigned char  ucUpdateBlkNo,unsigned char *pRespCode);
 *����:  Mifare����ֵ����ֵ����������
 * ������
 *      ucType        : ��������
 *                        ����ȡֵ��
 *                           '+' : ��ֵ���ֵ
 *                           '-' : ��ֵ���ֵ
 *                           '>' : ���ݿ����ݵ�ͬ������������
 *      ucBlkNo       : ���������( ���ݿ�Ƭ��ͬȡֵ��Χ��ͬ )
 *      pucValue      : ������ֵ( 4�ֽ� )
 *      ucUpdateBlkNo : Ŀ���
   *    pRespCode     : 0-�����ɹ�
 * ���أ�
 *      0,�����ɹ�
 *      ������ʧ��
 ****************************************************************************************/
unsigned char sdk_M1Operate( unsigned char  ucType, unsigned char  ucBlkNo,
                             unsigned char *pucValue, unsigned char  ucUpdateBlkNo, unsigned char *pRespCode);


/***************************************************************************************
 * ������:void sdk_PiccLibVersion(unsigned char buf[]);
 * ����: ��ȡ��ǰ���ļ��İ汾��
 * ������
 * buf     : �����������ȡ�汾��-ע�����6��char�ĳ���
 * ���أ�
 *      ��
 ***************************************************************************************/
void sdk_PiccLibVersion(unsigned char buf[]);

#endif

