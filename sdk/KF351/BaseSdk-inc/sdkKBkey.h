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
#define     SDK_KEY_CLEAR       0x2E                            //  ���
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

//�ȴ���������
#define SDK_GETKEY_OK         0x01        //�ȴ�����-ȷ�ϼ�(SDK_KEY_ENTER)
#define SDK_GETKEY_CANCEL     0x02        //�ȴ�����-ȡ����(SDK_KEY_CANCEL)
#define SDK_GETKEY_OKCANCEL   0x03        //�ȴ�����-ȷ�Ϻ�ȡ����(SDK_KEY_ENTER|SDK_KEY_CANCEL)
#define SDK_GETKEY_BACK       0x04        //�ȴ�����-�˸��(SDK_KEY_BACKSPACE)
#define SDK_GETKEY_ALPHA      0x08        //�ȴ�����-��ĸ��(SDK_KEY_ALPHA)
#define SDK_GETKEY_FUNC       0x10        //�ȴ�����-���ܼ�(SDK_KEY_FN)
#define SDK_GETKEY_MENU       0x20        //�ȴ�����-�˵���(SDK_KEY_MENU)
#define SDK_GETKEY_UP         0x40        //�ȴ�����-���ϼ�(SDK_KEY_UP)
#define SDK_GETKEY_DOWN       0x80        //�ȴ�����-���¼�(SDK_KEY_DOWN)
#define SDK_GETKEY_ANYKEY     0xFF        //�ȴ�����-�����

//����ģʽ
#define SDK_INPUT_MODE_REV      0x00000001      //��ʾģʽ:����������ʾ; 1��ʾ����,0��ʾ����
#define SDK_INPUT_MODE_DEC      0x00000002      //�Ƿ���С����; 1��ʾ��С����,0��ʾ��С����
#define SDK_INPUT_MODE_LEFT     0x00000004      //���뷽ʽ; 1��ʾ�����,0��ʾ�Ҷ���
#define SDK_INPUT_MODE_PWD      0x00000008      //����ģʽ; 1��ʾ���뷽ʽ,0��ʾ�����뷽ʽ
#define SDK_INPUT_MODE_ALPHA    0x00000010      //�������ַ�;   1��ʾ�����ַ�,0��ʾ�������ַ�
#define SDK_INPUT_MODE_NUM      0x00000020      //����������;   1��ʾ��������,0��ʾ����������
#define SDK_INPUT_MODE_BOLD     0x00000040      //��С����; 1��ʾ������,0��ʾС����
#define SDK_INPUT_MODE_PRE      0x00000080      //Ԥ��������Ч; 1��ʾ��ʾԤ������,0��ʾ����ʾԤ������
#define SDK_INPUT_MODE_NEWLINE  0x00000100      //�Ƿ�������; 1��ʾ������������뻻����ʾ,0��ʾ������

//���̱����ģʽ
#define SDK_KBLT_OFF_TEMP    0x00    //����ʡ��ģʽ���رձ��⣬�а�����ˢ�����忨�Ȳ���ʱֻ����LCD���⣩
#define SDK_KBLT_ON_TIMER    0x01    //���ⶨʱģʽ���򿪱��⣬���붨ʱģʽ���ް�����ʱʱ�رձ��⣩
#define SDK_KBLT_OFF_MODE    0x02    //���ⳣ�أ���ʹ�а�����ˢ�����忨�Ȳ���ʱ��������
#define SDK_KBLT_ON_MODE     0x03    //���ⳣ��

//���̰�����ģʽ
#define SDK_KBBEEP_ON    0x01       //���̰�������
#define SDK_KBBEEP_OFF   0x00       //���̰������ر�

s32 sdkKbOpen(void);
s32 sdkKbClose(void);
s32 sdkKbFlush(void);
//
s32 sdkKbGetKey(void);
s32 sdkKbGetKeyMs(u8 ucMsgType, s32 iTimeOutMs);
s32 sdkKbGetString(u8 ucRowNo, u8 ucColNo, u8 *pStrBuf, s32 MinLen, s32 MaxLen, u32 Mode, s32 TimeOutMs);
//
s32 sdkKbBeep(u8 ucMode);
s32 sdkKbLight(u8 ucMode);
void sdkKbSetLightTime(u32 uiLightTime);
u32 sdkKbGetLightTime(void);
u8 sdkKbGetLightMode(void);
u8 sdkKbGetBeepFlag(void);

#ifdef __cplusplus
    }
#endif

#endif

