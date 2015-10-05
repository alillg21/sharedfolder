/********************************************************************
文件名 : SdkVoice.h
描  述 : 语音模块接口函数
版  权 : 长城开发
作  者 : yaosong
修改记录:
    日期              修改人  修改内容
    2014-06-03 11:35  yaosong  创建
********************************************************************/
#ifndef BASE_SDKVOICE_H_
#define BASE_SDKVOICE_H_

#ifdef __cplusplus
    extern "C" {
#endif

#define SDK_VOICE_NUMS					25
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
#define	SDK_VOICE_10					11  // 十
#define SDK_VOICE_100					12  // 百
#define SDK_VOICE_1000					13  // 千
#define SDK_VOICE_10000					14  // 万
#define SDK_VOICE_DIAN					15  // 点
#define SDK_VOICE_FEN					16  // 分
#define SDK_VOICE_JIAO					17  // 角
#define SDK_VOICE_YUAN					18  // 元
#define SDK_VOICE_NOW_CONSUME			19  // 本次消费
#define SDK_VOICE_INVALID_CARD			20  // 无效卡
#define	SDK_VOICE_INSUFFICIENT_BALANCE	21  // 余额不足
#define	SDK_VOICE_BAD_CONSUME			22  // 消费失败
#define SDK_VOICE_PLEASE_CARD			23  // 请刷卡
#define SDK_VOICE_BALANCE_VALUE			24  // 余额为
#define SDK_VOICE_BEEP					25  // 滴(830HZ TONE)
#define SDK_VOICE_END                   26


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


