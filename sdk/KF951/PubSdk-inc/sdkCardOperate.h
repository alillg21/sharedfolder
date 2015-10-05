/********************************************************************
文件名 : sdkPubCardOperate.h
描  述 : 卡类操作
版  权 : 长城开发
作  者 : 陈伟明
修改记录: 
    日期              修改人  修改内容
    2014-02-18 09:45  陈伟明  创建
********************************************************************/
#ifndef PUBLIC_CARDOPERATE_H_
#define PUBLIC_CARDOPERATE_H_

#ifdef __cplusplus
    extern "C" {
#endif

#define SDK_RF_TYPE_AB      0x01    //Type A,B卡
#define SDK_RF_TYPE_M1      0x02    //M1卡
#define SDK_RF_TYPE_FELICA  0x04    //Type C卡，未纳入iso14443协议
#define SDK_RF_TYPE_N24G    0x08    //2.4G

//实际的读卡模式
#define SDK_CARD_MAG     0x01
#define SDK_CARD_NFC     0x02
#define SDK_CARD_INSERT  0x04
#define SDK_CARD_HAND    0x08

typedef enum
{
    ICC_CARDTYPE_MAG,
    ICC_CARDTYPE_CPU,
    ICC_CARDTYPE_AT,
    ICC_CARDTYPE_MIF,
    ICC_CARDTYPE_MEMMORY,
}E_SDK_ICC_CARDTYPE;

typedef struct
{    
    u8 ucSlotNo;                    // 卡座号
    u8 ucCardMode;                  // 实际的读卡模式：非接、接触、磁条卡、手输入
    E_SDK_ICC_CARDTYPE eCardType;   // 卡类型
}T_SDK_CARD_PARAM;                  // 卡参数

typedef enum
{
    SDK_CARD_CARDON=0,
    SDK_CARD_CARDOUT,    
}E_CARD_STATUS;

s32 sdkCardPowerUp(const T_SDK_CARD_PARAM * ptCardParam);
s32 sdkCardPowerDown(const T_SDK_CARD_PARAM * ptCardParam);
s32 sdkCardReset(const T_SDK_CARD_PARAM *ptCardParam, u8 *phexOutBuf, u32 *puiOutLen);
s32 sdkCardSearch(u8 ucInCardType, u8 *pucOutCardType, u8 *pucSerialInfo, u8 *pucCID);
s32 sdkCardRemove (u8 *pucCID);
s32 sdkCardGetStatus(const T_SDK_CARD_PARAM *ptCardParam);
s32 sdkCardSendData(const T_SDK_CARD_PARAM *ptCardParam, const u8 *phexInBuf,  
                    u32 uiInLen, u8 *phexOutBuf, u32 *puiOutLen);


#ifdef __cplusplus
    }
#endif

#endif

