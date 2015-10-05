/********************************************************************
�ļ��� : sdkRfCard.h
��  �� : �ǽӿ��ӿ�
��  Ȩ : ���ǿ���
��  �� : ��ΰ��
�޸ļ�¼:
    ����              �޸���  �޸�����
    2013-12-25 14:22  ��ΰ��  ����
********************************************************************/
#ifndef BASE_SDKRFCARD_H_
#define BASE_SDKRFCARD_H_

#ifdef __cplusplus
    extern "C" {
#endif

//�ǽӿ�����
#define RF_TYPE_AB      0x01    //Type A,B��, 13.56M
#define RF_TYPE_M1      0x02    //M1��, 13.56M
#define RF_TYPE_FELICA  0x04    //Type C����δ����iso14443Э��
#define RF_TYPE_N24G    0x08    //2.4G

typedef enum
{
    SDK_RF_EXTERNAL,    //External RF module
    SDK_RF_INTERNAL,    //Internal RF module
}E_SDK_RFTYPE;

s32 sdkRfSetType(E_SDK_RFTYPE ucType);
s32 sdkRfPowerOn(void);
s32 sdkRfPowerDown(void);
//
s32 sdkRfReset(void);
s32 sdkRfSearchCard(u8 ucInCardType, u8 *pucOutCardType, u8 *pucSerialInfo, u8 *pucCID, u8 *pucOther);
s32 sdkRfMoveCard(u8 ucMode, u8 ucCID);
s32 sdkRfSendData(const u8 *phexInBuf, u32 uiInLen, u8 *phexOutBuf, u32 *puiOutLen);
//Mifare M1
s32 sdkMifVerifyKey(u8 ucBlock, u8 ucKeyType, const u8 *pheKey, u32 uiKeyLen, u8 *pucSerialNo);
s32 sdkMifReadBlock(u8 ucBlock, u8 *phexOut, u32 *puiOutLen);
s32 sdkMifWriteBlock(u8 ucBlock, const u8 *phexIn, u32 phexInLen);
s32 sdkMifOprateBlock(u8 ucType, u32 BlockNo, s32 siValue);
s32 sdkMifBackUpBlock(u8 ucBlockSrc, u8 ucBlockDest);

void sdkMifSetFelicaTime(u32 uiTimeVaule);

#ifdef __cplusplus
    }
#endif

#endif

