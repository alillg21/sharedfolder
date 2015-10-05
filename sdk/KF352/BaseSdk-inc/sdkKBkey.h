/********************************************************************
�ļ��� : sdkKBkey.h
��  �� : ������صĺ���
��  Ȩ : ���ǿ���
��  �� : DJ Chen
�޸ļ�¼:
    ����              �޸���  �޸�����
    2013-12-24 16:42  DJ Chen  ����
********************************************************************/
#ifndef BASE_SDKKBKEY_H_
#define BASE_SDKKBKEY_H_

#ifdef __cplusplus
    extern "C" {
#endif

#define     SDK_KEY_0           '0'                             //  '0'
#define     SDK_KEY_1           '1'                             //  '1'
#define     SDK_KEY_2           '2'                             //  '2'
#define     SDK_KEY_3           '3'                             //  '3'
#define     SDK_KEY_4           '4'                             //  '4'
#define     SDK_KEY_5           '5'                             //  '5'
#define     SDK_KEY_6           '6'                             //  '6'
#define     SDK_KEY_7           '7'                             //  '7'
#define     SDK_KEY_8           '8'                             //  '8'
#define     SDK_KEY_9           '9'                             //  '9'

#define     SDK_KEY_BACKSPACE   0x08                            //  �˸�
#define     SDK_KEY_CLEAR       0x2E                            //  ȫ�����
#define     SDK_KEY_ALPHA       0x07                            //  ��ĸ
#define     SDK_KEY_UP          0x26                            //  ����
#define     SDK_KEY_DOWN        0x28                            //  ����
#define     SDK_KEY_LEFT        0x12        //  ����
#define     SDK_KEY_RIGHT       0x13        //  ����

#define     SDK_KEY_FN          0x15                            //  ����
#define     SDK_KEY_MENU        0x14                            //  �˵�
#define     SDK_KEY_ENTER       0x0D                            //  ȷ��
#define     SDK_KEY_CANCEL      0x1B                            //  ȡ��
#define     SDK_KEY_PRNUP       0x19                            //  ��ӡ������ֽ
#define     SDK_KEY_INVALID     0xFF                            //  ��Ч����
#define     SDK_KEY_TIMEOUT     0X00                            //  ��ʱ�ް���

s32 sdkKbOpen(void);
s32 sdkKbClose(void);

s32 sdkKbGetKey(void);
s32 sdkKbFlush(void);
s32 sdkKbBeep(u8 ucMode);
s32 sdkKbLight(u8 ucMode);

#ifdef  DJ_debug
void TestKB(void);
#endif

#ifdef __cplusplus
    }
#endif

#endif

