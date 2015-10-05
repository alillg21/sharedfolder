////////////////////////////////////////////////////////
//�ļ���          : ChnPyIme.h
//�汾            : 2.0.0
//Ŀ�ļ���Ҫ����  : ChnPyIme.c�Ľӿ��ļ�
//����            : �ܽ���(jiandongzhou@yahoo.com)
//��������        : 2002-08-01 00:00
//�޸���          : �ܽ���(jiandongzhou@yahoo.com)
//�޸�����        : 2004-3-19 9:25
//�޸�˵��        : ����
////////////////////////////////////////////////////////

/*===================================================
����    : �ܽ���(jiandongzhou@yahoo.com)
��д����: 2002��5��
����    : ƴ�����뷨
�޸���  : �ܽ���(jiandongzhou@yahoo.com)
�޸�����: 2004��3��
δ��������ɣ�����ɢ����
===================================================*/

#include "my_define.h"
#include "kbd_define.h"
#include "keymap.h"

//����״̬����
#define IME_STATUS_PY       0	//ƴ����������
#define IME_STATUS_BH       1	//�ʻ���������
#define IME_STATUS_ENG_CAP  2	//����Ӣ�Ĵ�д״̬
#define IME_STATUS_ENG_LOW  3	//����Ӣ��Сд״̬
#define IME_STATUS_DIGITS   4	//��������״̬
#define IME_STATUS_SYMBOL   5	//�������״̬
#define IME_STATUS_QW       6	//������λ״̬
#define IME_STATUS_PDA      7	//����PDA״̬ 2006-6-20

//���뷨���м�����
#define IME_RUN_LEVEL0      0	//���뷨����״̬0: ����ļ�δ��
#define IME_RUN_LEVEL1      1	//���뷨����״̬1: ����ļ��Ѵ�
#define IME_RUN_LEVEL2      2	//���뷨����״̬2: ���δ��ʼ���ɹ�
#define IME_RUN_LEVEL3      3	//���뷨����״̬3: ����ѳ�ʼ���ɹ�

//���̶���
#define IME_UP          KEY_UP		        //�ϼ�
#define IME_DOWN        KEY_DOWN	        //�¼�
#define IME_LEFT        KEY_LEFT	        //���
#define IME_RIGHT       KEY_RIGHT	        //�Ҽ�

#define IME_PgUp        KEY_PGUP	        //��ҳ��
#define IME_PgDn        KEY_PGDN	        //��ҳ��
#define IME_SUBTOTAL    0x72
#define IME_SHIFT_REV   0x7F	//���á�˰Ŀ����

#define IME_ENTER       KEY_ENTER
#define IME_VOID        KEY_ESC
#define IME_KEY_CLEAR   KEY_CLEAR

#define IME_TOTAL       0x5D
#define IME_SHIFT       KEY_TAB	//0x52

#define IME_BACKSPACE   KEY_BACK
#define IME_DOT         '.'	//���뷨ȷ�ϣ�С����
#define IME_SPACE       '0'	//�ո�0



//�� �� ��: IME_InitMaBiao
//��    ��: ��ʼ�����뷨���
//ȫ�ֱ���: ��
//�������: sImeTableFile������ļ�����·��
//�������: ��
//�� �� ֵ: �ɹ�����0, ʧ�ܷ���1
//��    ��: �ܽ���
//��������: 2005/8/26
//�� �� ��: ��־��
//�޸�����:  
//��    ע: 
extern unsigned char IME_InitMaBiao(char *sImeTableFile);



//�� �� ��: IME_InitPYIndexTbl
//��    ��: ��ʼ��ƴ�����뷨
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ: �ɹ�����0, ʧ�ܷ���1
//��    ��: �ܽ���
//��������: 2005/8/26
//�� �� ��: ��־��
//�޸�����: 
//��    ע: ֻ�������뷨����ļ��򿪵�����¸ú����Ż�������.
extern unsigned char IME_InitPYIndexTbl(void);




//================================================
// �� �� ��: GetString
// ��������: �������ġ���ĸ�����֡�������š�
//           �ո�С���� �Ļ���ַ���
// ȫ�ֱ���: ��
// �������:
//   Max_length: �������������ֽ���
//   row, col: ΪĿ����ʾ����ʼ��������
// �������:
//   rslt_str: �洢����Ļ���ַ���,Ӧ��������
//      (Max_length + 1)���ֽڵĿռ�
// �� �� ֵ: ��ֵ(��ȡ��,�ϼ�,ȷ�ϵ�)
// ��    ��: �ܽ���
// ��������: 2002-06-XX
// �� �� ��: �ܽ���
// �޸�����: 2004-3-18 15:51
//================================================
extern uchar GetString(uchar Max_length, uchar * chinese_string, uchar row, uchar col);

extern uchar GetStringSub(uchar ime_status, uchar Max_length, uchar * rslt_str, uchar row, uchar col);
//�� �� ��: input_use_method
//��    ��: ʹ��ƴ�����뷨������ĸ���ַ������֡��ͺ���
//ȫ�ֱ���: ��
//�������: ��
//�������: ������ַ���
//�� �� ֵ: �ַ�������
//��    ��: �� ־ ��
//��������: 2010/4/14
//�� �� ��: 
//�޸�����: 
//��    ע: ʹ�øú���ǰ,�����ȵ���IME_InitMaBiao������ļ���Ȼ��
//			����IME_InitPYIndexTbl��ʼ��ƴ�����뷨��
extern unsigned short input_use_method(unsigned char *inpt_str );
