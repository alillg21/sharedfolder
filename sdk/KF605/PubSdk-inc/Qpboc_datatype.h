#ifndef Qpboc_datatype_h
#define Qpboc_datatype_h
#include "Struct_pack.h"
//#include "sdk_common.h"

/*typedef unsigned short  ushort;
typedef unsigned char    uchar;
typedef unsigned int      uint;
*/

#define uchar unsigned char
#define ushort unsigned short
//#define uint unsigned int
//#define NULL  (void*)0

//�������ṹ��
typedef struct
{
    uchar  bLen;
    uchar  PAN[10];
    uchar  PANSeqNum;
} STRUCT_PACK T_TERMEXCEPTIONFILE;

/*typedef struct
{
    unsigned long   ulReferCurrCon;           // �ο����Ҵ���ͽ��״����ת��ϵ��
    unsigned int    usMchLocLen;            // �̻����Ƽ�λ��������ĳ���
    uchar   aucMchNameLoc[257];     // �̻����Ƽ�λ��(1-256 �ֽ�)
    uchar   aucMerchCatCode[2];     // �̻�������'9F15'(2�ֽ�)
    uchar   aucMerchantID[15];      // �̻���ʶ(15�ֽ�)9F16
    uchar AcquierId[6];                 //�յ��б�־   // download app
              uchar   aucTmID[8];               // �ն˱�ʶ(�ն˺�)9F1C
    uchar   ucTmType;               // �ն�����9F35
    uchar   ucTransType;            // Goods,Services, Cash,CashBack  10/10/18
    uchar   aucTmCap[3];            // �ն�����9F33
              uchar   aucTmCapAd[5];            // �ն˸�������
              uchar   aucTmCntrCode [2];      // �ն˹��Ҵ��� 9F1A
    uchar   aucTmTransCur[2];       // �ն˽��׻��Ҵ���'5F2A'(2�ֽ�)
    uchar   ucTmTransCurExp;        // �ն˽��׻���ָ��'5F36'(1�ֽ�)
    uchar   aucTmRefCurCode[2];     // �ն˽��ײο����Ҵ���'9F3C'(2�ֽ�)
    uchar   ucTmRefCurExp;          // �ն˽��ײο�����ָ��'9F3D'(1�ֽ�)
    uchar   aucRFU[3];
}STRUCT_PACK  Contactless_ReaderParam;
*/

/*typedef struct CLSS_PREPROC_INTER_FLAG_INFO
{
    uchar aucAID[17];
    uchar ucAidLen;

    // payWave
    uchar   ucZeroAmtFlg;               // 0-���׽��!=0; 1-���׽��=0
    uchar   ucStatusCheckFlg;           // �������Ƿ�֧��״̬���
              uchar   aucReaderTTQ[5];      // �ն˽������ܣ�����VISA/PBOC�У�tag =9F66
    uchar   ucCLAppNotAllowed;          // 1-��AID���ܽ��зǽӴ�����

    // common
    uchar ucTermFLmtExceed;
    uchar ucRdCLTxnLmtExceed;
    uchar ucRdCVMLmtExceed;
    uchar ucRdCLFLmtExceed;

    uchar ucTermFLmtFlg;
    uchar aucTermFLmt[4];

    uchar aucRFU[2];
}STRUCT_PACK Clss_PreProcInterInfo;

typedef struct CLSS_TRANSPARAM
{
    unsigned long  ulAmntAuth;     // ��Ȩ���(ulong)
    unsigned long  ulAmntOther;    // �������(ulong)
    unsigned long  ulTransNo;      // �������м�����(4 BYTE)
    uchar  ucTransType;      // �������� not  '9C' !!! (GOODS CASH)
    uchar  aucTransDate[4];  // �������� YYMMDD
    uchar  aucTransTime[4];  // ����ʱ�� HHMMSS
} STRUCT_PACK Clss_TransParam;
*/
typedef struct EMVTRANS_STRU
{
    unsigned char   bPanSeqNoOk;        // ADVT case 43
    unsigned char   ucPanSeqNo;         // App. PAN sequence number
    unsigned char   sAppCrypto[8];      // app. cryptogram
    unsigned char   sAuthRspCode[2];
    unsigned char   sTVR[5];
    unsigned char   szAID[32+1];
    unsigned char   szAppLable[16+1];
    unsigned char   szAppName[16+1]; //09/12/30 9f12
    unsigned char   sTSI[2];
    unsigned char   sATC[2];
    unsigned char   ucFallBack;         /*ԭ�����Ƿ�FALLBACK  0:����  1:��*/
    unsigned char   ucSwipeFlag;    // swipe flag

    unsigned char   bCryData;      //Cryptogram Information Data(9f27)

    unsigned char  PanLen;
    unsigned char  sAmount[13];
    unsigned char  AmountOtherNum[6];//9f03 50Amount Other
    unsigned char  TerminalCountry[2];//9f1a 70Terminal Country Code
    unsigned char  TranCurrency[2];  //5f2a 9Transaction Currency Code
    unsigned char  TranDate[3];      //9a
    unsigned char  TransType;        /* 9cTransaction type */
    unsigned char  UnpredictNum[4];  //9f37 90Unpredictable Number
    unsigned char  AIP[2];           //82 23Application Interchange Profile
    unsigned char  IssuerAppData[32];//9f10 61Issuer Application Data (IAD)
    unsigned char  Ec_Balance[6];        //9f5d Available Offline Spending Amount
    unsigned char  VLPIssuAuthorCode[6]; //9F74 EC Issuer Authorization Code
} STRUCT_PACK EMVTRANS_STRU;

typedef struct
{
    unsigned short  nTag;
    uchar bOption;
} STRUCT_PACK T_EMVTAG;

#define TRACK2_MAX_LEN  37
#define TRACK3_MAX_LEN  104
#define CARD_NUMBER_LEN   19
#define DATETIME_LEN       7
#define SECRET_LEN           8
#define CARD_SERIES_NO_LEN  10
//�ֻ�оƬ�Ĵŵ���Ϣ

/*typedef struct
{
    char card_series_no[CARD_SERIES_NO_LEN+1];
    char card_number[CARD_NUMBER_LEN+1];
    char track_data2[TRACK2_MAX_LEN+1];
    char track_data3[TRACK3_MAX_LEN+1];
    char secret[SECRET_LEN+1];
    char date_time[DATETIME_LEN+1];
}STRUCT_PACK MSD_CUP_INFO;
*/

#endif

