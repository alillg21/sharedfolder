/********************************************************************
�ļ��� : sdkInput.h
��  �� : public������Ͱ��������йصĲ���
��  Ȩ : ���ǿ���
��  �� : DJ Chen
�޸ļ�¼: 
    ����              �޸���  �޸�����
    2014-02-18 10:44  DJ Chen  ����
********************************************************************/
#ifndef BASE_SDKINPUT_H_
#define BASE_SDKINPUT_H_

#ifdef __cplusplus
    extern "C" {
#endif

//��׼����ģʽ
#define SDK_INPUT_NUM     0x00000001        //��������
#define SDK_INPUT_CHAR    0x00000002        //������ĸ
#define SDK_INPUT_SYMBOL  0x00000004        //��������ɼ��ַ�
#define SDK_INPUT_HEX     0x00000008        //����16����
#define SDK_INPUT_HZ      0x00000010        //�������뺺��
#define SDK_INPUT_POINT   0x00000020        //�����С��������(���)
#define SDK_INPUT_PWD     0x00000040        //��������(����Ϊ*)
#define SDK_INPUT_IP      0x00000080        //����IP��ַ
#define SDK_INPUT_LEFT    0x00000100        //�����(Ϊ����Ϊ�Ҷ���)
#define SDK_INPUT_DISP    0x00000200        //����(Ϊ����Ϊ����) 
#define SDK_INPUT_HANDWRITE 0x00000400      //��д

#define SDK_KEY_MASK_0       0x00000001  //'0'
#define SDK_KEY_MASK_1       0x00000002  //'1'
#define SDK_KEY_MASK_2       0x00000004  //'2'
#define SDK_KEY_MASK_3       0x00000008  //'3'
#define SDK_KEY_MASK_4       0x00000010  //'4'
#define SDK_KEY_MASK_5       0x00000020  //'5'
#define SDK_KEY_MASK_6       0x00000040  //'6'
#define SDK_KEY_MASK_7       0x00000080  //'7'
#define SDK_KEY_MASK_8       0x00000100  //'8'
#define SDK_KEY_MASK_9       0x00000200  //'9'
#define SDK_KEY_MASK_ENTER   0x00000400  //ENTER
#define SDK_KEY_MASK_CANCAL  0x00000800  //CANCAL
#define SDK_KEY_MASK_UP      0x00001000  
#define SDK_KEY_MASK_DOWN    0x00002000
#define SDK_KEY_MASK_CLEAR   0x00004000
#define SDK_KEY_MASK_FUN     0x00008000
#define SDK_KEY_MASK_MENU    0x00010000
#define SDK_KEY_MASK_ALPHA   0x00020000
#define SDK_KEY_MASK_BACKSPACE   0x00040000
#define SDK_KEY_MASK_LEFT    0x00080000
#define SDK_KEY_MASK_RIGHT   0x00100000
#define SDK_KEY_MASK_ALL     0x80000000  //���м�ֵ��Ч


s32 sdkKbInput(u32 uiDispRow, u32 uiDispCol, u8 *pszOut, u32 uiMinLen, u32 uiMaxLen, u32 uiMode, u32 uiOvertimer);
s32 sdkKbWaitKey(u32 uiMask, u32 uiOvertimer);


#ifdef __cplusplus
    }
#endif
#endif







