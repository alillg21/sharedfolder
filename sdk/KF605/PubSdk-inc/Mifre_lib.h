#ifndef MIFRE_LIB_H
#define MIFRE_LIB_H

#include "Qpboc_datatype.h"
//#include "sdk_common.h"

typedef struct
{
    uchar  drv_ver[5];  //e.g. "1.01A", read only
    uchar drv_date[12]; //e.g. "2006.08.25",read only

    uchar a_conduct_w;  //Type A conduct write enable: 1--enable,else disable
    uchar a_conduct_val;//Type A output conduct value,0~63


    uchar b_modulate_w;  //Type B modulate index write enable,1--enable,else disable
    uchar b_modulate_val;//Type B modulate index value

    uchar card_buffer_w;//added in V1.00C,20061204
    ushort card_buffer_val;//max_frame_size of PICC

    uchar wait_retry_limit_w;//added in V1.00F,20071212
    ushort wait_retry_limit_val;//max retry count for WTX block requests,default 3

    // 20080617
    uchar card_type_check_w; //
    uchar card_type_check_val; //

    uchar card_RxThreshold_w;   // card RxThreshold
    uchar card_RxThreshold_val;


    uchar f_modulate_w;
    uchar f_modulate_val;  //FeliCa card modulate

    uchar reserved[20];  //
} ST_PICC_PARA;

#define PICC_PARA  ST_PICC_PARA//保持与以前命名一致

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

//以下为函数声明
extern int ret_conver(unsigned char funNo,unsigned char ret);

extern unsigned char picc_open(void);
extern unsigned char picc_m1authority(unsigned char Type,unsigned char BlkNo,
                                      unsigned char *Pwd,unsigned char *SerialNo);
extern unsigned char picc_m1operate(unsigned char Type, unsigned char BlkNo,
                                    unsigned char *Value, unsigned char UpdateBlkNo);
extern unsigned char picc_m1readblock(unsigned char BlkNo,unsigned char *BlkValue);
extern unsigned char picc_m1writeblock(unsigned char BlkNo,unsigned char *BlkValue);
extern unsigned char picc_detect(unsigned char ucMode,unsigned char *CardType,
                                 unsigned char *SerialInfo,unsigned char *CID,unsigned char *Other);
extern unsigned char picc_isocommand(unsigned char cid,APDU_SEND *ApduSend,APDU_RESP *ApduRecv);
extern unsigned char picc_setup(unsigned char ucMode, PICC_PARA *picc_para);
extern unsigned char picc_remove(unsigned char mode, unsigned char cid);
extern void picc_close(void);
extern unsigned char picc_cmdexchange(unsigned int uiSendLen, unsigned char* paucInData,
                                      unsigned int* puiRecLen, unsigned char* paucOutData);
extern unsigned char picc_initfelica(unsigned char ucRate,unsigned char ucPol);

extern unsigned char picc_POLLEMV_Step(uchar* pucType);
extern void picc_OpenCarrier_step(void);
extern void picc_CloseCarrier_Step(void);
extern void picc_ResetCarrier_Step(void);
extern unsigned char picc_RemoveEMV_step(uchar cid, ushort ul100Ms);
#endif

