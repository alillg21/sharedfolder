#ifndef Qpboc_fun_h
#define Qpboc_fun_h

#include <time.h>


#define KERNTYPE_PBOC  4	
#define KERNTYPE_DEF   0

#define AC_AAC       0x00
#define AC_TC        0x01
#define AC_ARQC      0x02


#define PART_MATCH  0
#define FULL_MATCH   1

#define LEFT   0xF0
#define MIDDLE 0xF1
#define RIGHT  0xF2

#define QPBOC_OK                     0
#define QPBOC_DATA_ERROR    -9
#define QPBOC_NOT_FOUND      -16
#define QPBOC_FILE_ERR          -23
#define QPBOC_USE_CONTACT -24
#define QPBOC_TRANS_FAIL     0x26
#define QPBOC_NO_APP             -6
#define QPBOC_ICC_BLOCK       -3
#define QPBOC_APP_BLOCK       -5
#define QPBOC_CMD_ERROR      -2
#define QPBOC_RESELECT_APP  -35
#define QPBOC_TRANS_TERMIN  -26
#define QPBOC_USER_CANCLE    -7
#define QPBOC_ICC_RSP_ERR    -4
#define QPBOC_CARD_EXPIRED     -36
#define QPBOC_EXCEPTION       -37 // 卡片在终端异常文件中 

#define TRACK2_MAX_LEN  37
#define TRACK3_MAX_LEN  104
#define CARD_NUMBER_LEN   19
#define DATETIME_LEN       7
#define SECRET_LEN           8
#define CARD_SERIES_NO_LEN  10

typedef struct
{
	char card_series_no[CARD_SERIES_NO_LEN+1];
	char card_number[CARD_NUMBER_LEN+1];
	char track_data2[TRACK2_MAX_LEN+1];
	char track_data3[TRACK3_MAX_LEN+1];
	char secret[SECRET_LEN+1];
	char date_time[DATETIME_LEN+1];
}STRUCT_PACK MSD_CUP_INFO;

extern int Contectless_QpbocInitFile(void);

 //非接参数设置
extern void Contactless_TransParaInit();

//设置TAG值
extern int Contactless_SetTLVData(ushort usTag,uchar * pucDtIn,int nDtLen);

//获取TAG值
extern int Contactless_GetTLVData(ushort usTag,uchar * pucDtIn,int *nDtLen);

//return 0 成功
extern unsigned char Contactless_PiccOpen();

extern void Contactless_PiccClose();

//进入寻卡模式
extern int Check_ContactlessCard(void);

//非接模块寻卡
extern int Contactless_CardDetect(uchar  *pRespCode,int  OutTime);


extern int Contactless_FileSize(char *sName);	

//判断是否为纯电子现金卡，如果是纯电子现金卡，则返回1，否则返回零
extern int Contactless_JudgeECCard(void);

extern void Contactless_AppGetOnlineData(char*online_data_buffer,int *length);


extern void Contactless_AppGetEMVData(EMVTRANS_STRU *data);

//获取打印时候需要的数据
extern void Contactless_GetEMVData(void);

extern void Contactless_GetICOnlineData(uchar flag);

extern void  gettime(struct tm *tDate);

extern int Contactless_NeedSaveDetail(void);

extern void Contactless_SaveDetail(void);

extern void Contactless_GetTrackInfo(char*track2_info,char*track3_info,char*card_number);

extern int Contactless_GetMSDInfor(MSD_CUP_INFO*msd_infor,int *resp_code);

extern int Contactless_Processing(char*amount,int *resp_code);

extern int Contactless_Inquirying(int *resp_code,char*balance_buffer,int *Amountlen);

extern int Contactless_AddExceptionPara(T_TERMEXCEPTIONFILE*exception_para);

extern int Contactless_AddCapkPara(T_EMV_TERM_CAPK *capk);

extern int Contactless_AddAppPara(uchar * buffer,int buffer_len);

extern int Contactless_DelExceptionPara(uchar del_flag ,T_TERMEXCEPTIONFILE*exception_para);

//判断卡号是否为黑名单
extern int Contactless_PanIsException(T_TERMEXCEPTIONFILE*exception);

extern int Contactless_ExceptionCheck(void);

extern void sdk_GetLibqpboc(char *sVer );

extern void Contactless_SetMode(int mode);

extern int Contactless_IsOutLay();

//return 0 :succesful
extern int Contactless_DelAllCapk();

//return 0 :succesful
extern int Contactless_DelAllAidParam();


#endif
