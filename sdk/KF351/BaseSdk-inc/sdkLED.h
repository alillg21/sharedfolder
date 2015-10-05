/********************************************************************
文件名 : sdkLED.h
描  述 : LED数码管模块接口
版  权 : 长城开发
作  者 : 卢裕燕
修改记录:
    日期              修改人  修改内容
    2014-06-30 15:36  卢裕燕  创建
********************************************************************/
#ifndef BASE_SDKLED_H_
#define BASE_SDKLED_H_

#ifdef __cplusplus
    extern "C" {
#endif

//LED数码管显示字符
#define SDK_LED_DIGIT_0     0x3F    //'0'
#define SDK_LED_DIGIT_1     0x06    //'1'
#define SDK_LED_DIGIT_2     0x5B    //'2'
#define SDK_LED_DIGIT_3     0x4F    //'3'
#define SDK_LED_DIGIT_4     0x66    //'4'
#define SDK_LED_DIGIT_5     0x6D    //'5'
#define SDK_LED_DIGIT_6     0x7D    //'6'
#define SDK_LED_DIGIT_7     0x07    //'7'
#define SDK_LED_DIGIT_8     0x7F    //'8'
#define SDK_LED_DIGIT_9     0x6F    //'9'

#define SDK_LED_DIGIT_A     0x77    //'A'
#define SDK_LED_DIGIT_B     0x7C    //'b'
#define SDK_LED_DIGIT_C     0x39    //'C'
#define SDK_LED_DIGIT_D     0x5E    //'d'
#define SDK_LED_DIGIT_E     0x79    //'E'
#define SDK_LED_DIGIT_F     0x71    //'F'
#define SDK_LED_DIGIT_EQUAL     0x48    //'='
#define SDK_LED_DIGIT_MINUS     0x40    //'-'
#define SDK_LED_DIGIT_RADIX     0x80    //'.'


s32 sdkLedArrayOpen(void);
void sdkLedArrayClose(void);
s32 sdkLedArrayGetDigit(void);
s32 sdkLedArrayOn(u8 *pucLedData);
s32 sdkLedArrayDisplay(u8 *pucDispString, u8 ucAlignment);
void sdkLedArrayClear(void);


#ifdef __cplusplus
    }
#endif

#endif

