/********************************************************************
�ļ��� : SdkVoice.h
��  �� : ����ģ��ӿں���
��  Ȩ : ���ǿ���
��  �� : yaosong
�޸ļ�¼:
    ����              �޸���  �޸�����
    2014-06-03 11:35  yaosong  ����
********************************************************************/
#ifndef BASE_SDKVOICE_H_
#define BASE_SDKVOICE_H_

#ifdef __cplusplus
    extern "C" {
#endif

#define	SDK_VOICE_0						1	// 0
#define	SDK_VOICE_1						2	// 1
#define	SDK_VOICE_2						3	// 2
#define	SDK_VOICE_3						4	// 3
#define	SDK_VOICE_4						5	// 4
#define	SDK_VOICE_5					    6	// 5
#define	SDK_VOICE_6						7	// 6
#define	SDK_VOICE_7						8	// 7
#define	SDK_VOICE_8						9	// 8
#define	SDK_VOICE_9						10  // 9
//
#define	SDK_VOICE_10					11  // ʮ
#define SDK_VOICE_100					12  // ��
#define SDK_VOICE_1000					13  // ǧ
#define SDK_VOICE_10000					14  // ��
#define SDK_VOICE_DIAN					15  // ��
#define SDK_VOICE_FEN					16  // ��
#define SDK_VOICE_JIAO					17  // ��
#define SDK_VOICE_YUAN					18  // Ԫ
//
#define SDK_VOICE_NOW_CONSUME			19  // ��������
#define SDK_VOICE_INVALID_CARD			20  // ��Ч��
#define	SDK_VOICE_INSUFFICIENT_BALANCE	21  // ����
#define	SDK_VOICE_BAD_CONSUME			22  // ����ʧ��
#define SDK_VOICE_PLEASE_CARD			23  // ��ˢ��
#define SDK_VOICE_BALANCE_VALUE         24  // ���Ϊ
//new for KF351
#define SDK_VOICE_PLS_SWIPECARD_AGAIN   25  // ������ˢ��
#define SDK_VOICE_WELCOMDE_USE          26  // ��ӭʹ��
#define SDK_VOICE_QUICK_PASS            27  // ��������
#define SDK_VOICE_OR                    28  // ��
#define SDK_VOICE_SZT                   29  // ����ͨ
//
#define SDK_VOICE_RESERVE1              30  // ����1
#define SDK_VOICE_RESERVE2              31  // ����2
#define SDK_VOICE_RESERVE3              32  // ����3
#define SDK_VOICE_RESERVE4              33  // ����4

//#define SDK_VOICE_NUMS                  33

s32 sdkVoiceOpen(void);
s32 sdkVoiceClose(void);
s32 sdkVoiceSound(u8 ucVoiceID);
s32 sdkVoiceMute(u8 ucMutFlg);
s32 sdkVoiceErase(void);
s32 sdkVoiceWrite(u32 uiAddr,const u8 *pucInBuf,u32 uiLen);
s32 sdkVoiceRead(u32 uiAddr,u8 *pucOutBuf,u32 uiLen);

#ifdef __cplusplus
    }
#endif

#endif

