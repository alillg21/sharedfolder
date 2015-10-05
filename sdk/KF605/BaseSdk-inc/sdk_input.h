////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
#ifndef _sdk_PINYIN_
#define _sdk_PINYIN_

#include "sdk_common.h"
//#include "FindCode.h"

#define  IME_TABLE_FILE  "/usr/font/PyBxCode.bin"  //���뷨����ļ�

#define TERMINAL_HARDTEST_CONFIG_FILE   "/app/Test/hardtest.cfg"

#define MONEY_FORMAT    0 //���
#define NUMERAL_FORMAT  1 //ʮ����0..9
#define HEX_FORMAT      2 //16����0..9,a..f,A..F
#define ALPHA_FORMAT    3 //�����������ֺ��ַ�
#define ALPHA_HZ_FORMAT 4 //���� ���ֺ��ַ�
#define BINARY_FORMAT   5 //������0,1
#define PASSWORD_FORMAT 6 //������ʾ*��ʮ����0..9

#define INPUT_MAX_LEN 128 //��������ֽ���

extern uchar g_ime_status_line;     //���������뷨״̬�� Ĭ�ϵ�1��
extern uchar g_ime_hz_line;     //���������뷨������ʾ�� Ĭ�ϵ�2��
extern uchar g_ime_disp_num;//���뷨���һ����ʾƴ������ Ĭ��Ϊ3

#ifdef __cplusplus
extern "C" {
#endif

//��ʼ�����뷨 ��ϵͳ��ʼ��ʱ����һ��
//����ֵ:0�ɹ�; -1�����뷨����ļ�ʧ��; -2ƴ�����뷨��ʼ��ʧ��
int sdk_IMEInit(void);

/*
name       :sdk_Input
desc.        :Get inputed mixed string including number, letter, special character blank, decimal, Chinesecharacter.
input para :    Max_len The maximal bytes to input
            Str The string to save, must have (Max_length + 1) bytes spare space
            Row Started coordinate to display
            number_flag allow numeric only when it's value is not 0, otherwise we can input numeric and character
return      :Key value
*/
uchar sdk_Input(uchar row, uchar col, char *str,uchar max_len,int format);

void sdk_ReadMachineType(unsigned char *info_buf);

#ifdef __cplusplus
}
#endif

#endif

