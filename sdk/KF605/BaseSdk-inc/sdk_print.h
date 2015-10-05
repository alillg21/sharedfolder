/*!@file
********************************************************************************
Module: Common
file name: sdk_print.h

function: system file
Author: CRD by Zumiao Yu
version: 1.0.0
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
modify :
date              version          by           fixed
2010/02/23    1.0.0             Yu            create
*******************************************************************************/
#ifndef _SDK_PIRNT_H_
#include "sdk_font.h"

#define _SDK_PIRNT_H_
#define PRINT_FILENAME "/dev/lp0"

//  Font Mode
#define PRN_MODE_NORMAL   0 // normal height, normal width
#define PRN_MODE_DBWIDTH  1 // normal height, double width
#define PRN_MODE_DBHEIGHT 2 // double height, normal width
#define PRN_MODE_DBBOTH   3 // double height, double width

#define PRN_FONT12  0   //ʹ��12x12�����ӡ
#define PRN_FONT16  1   //ʹ��16x16�����ӡ
#define PRN_FONT24  2   //ʹ��24x24�����ӡ
#define PRN_FONT2412 3

#define DEFAULT_DARKNESS    7                           //Ĭ�ϴ�ӡɫ��
#define DEFAULT_FONTTYPE    PRN_FONT12      //Ĭ�ϴ�ӡ����
#define DEFAULT_LINESPACE   2                           //Ĭ���м��Ϊ4����

#define MAX_DARKNESS    15                              //���ɫ��ֵ
#define MIN_DARKNESS    1                                   //��Сɫ��ֵ

#define PRN_FAILURE                 -1
#define PRN_OUT_OF_PAPER            -2
#define PRN_ABORT_TEMP              -3
#define  PRINT_MAX_WIDTH 384    //һ�д�ӡ�����(��λ:pixel),�ֽ�=PRINT_MAX_WIDTH/8

//����ַ��Ľṹ
typedef struct
{
    char *pcInfo;       //Ҫ��ӡ���ַ���
    unsigned char cFont;        //���� ͬLCD��ʾ������
    unsigned char cInterval;    //�ּ�� ��λ:pixel ��δʵ��
    unsigned char cAtt;         //������ =0�׵׺��� =FONT_CONTRAST�ڵװ���
} __attribute__((packed)) T_PRN_INFOATT;

#define PRN_FAILURE                 -1  //��ӡʧ��
#define PRN_OUT_OF_PAPER            -2  //ȱֽ
#define PRN_ABORT_TEMP              -3  //�¶ȹ���

#define MAX_DARKNESS    15              //���ɫ��ֵ
#define MIN_DARKNESS    1               //��Сɫ��ֵ

#ifdef __cplusplus
extern "C" {
#endif

//��ӡ��ʼ��
//�� �� ֵ: 0�ɹ�
//          -1  �豸��ʼ��ʧ��
int sdk_PrnOpen(void);

//��ӡ�豸�ر�
//�� �� ֵ: 0�ɹ�
//          -1  �ر��豸ʧ��
int sdk_PrnClose(void);

//���ô�ӡ�Ҷ�
//level : ɫ��ֵ MIN_DARKNESS>= level <=MAX_DARKNESS
//�� �� ֵ: 0�ɹ�
//          -1  ʧ��
//          -2  ��ӡ�豸δ��ʼ��
//          -3  ��������
int sdk_PrnSetGray(unsigned char level);

//���ô�ӡ�ٶ�
//mode : 1-����; 2-����
//�� �� ֵ: 0�ɹ�
//          -1  ʧ��
//          -2  ��ӡ�豸δ��ʼ��
//          -3  ��������
//��ע:
//  Ĭ�ϴ�ӡ�ٶ�Ϊ���ٴ�ӡ
int sdk_PrnSetSpeed(int mode);

/*! @function
********************************************************************************
������: Sdk_FillPrnData
����  : ����ַ����Ĵ�ӡbuffer
����  : ptPrnBoard ��ӡģ��Ľṹ��
        ptPrnStrAtt ��ӡͼ�εĽṹ��
����ֵ:
        0 �ɹ�
        -1 ����
��ע  :
*******************************************************************************/
int sdk_PrnFillStr(T_FONT_BOARD *ptPrnBoard, T_PRN_INFOATT* ptPrnStrAtt);

/*! @function
********************************************************************************
������: Sdk_FillPrnData
����  : ���ͼ�εĴ�ӡbuffer
����  : ptPrnBoard ��ӡģ��Ľṹ��
        ptPrnBitmapAtt ��ӡͼ�εĽṹ��
����ֵ:
        0 �ɹ�
        -1 ����
��ע  :
*******************************************************************************/
int sdk_PrnFillBitmap(T_FONT_BOARD *ptPrnBoard, T_FONT_BOARD *ptPrnBitmapAtt);

//������ӡ����ʼ��ӡ
//DotLine:��ӡbuffer�ĵ�����
//�� �� ֵ: >=0 �ɹ���ӡ�����ݳ���
//          -1  ��ӡʧ��
//          -2  ȱֽ
//          -3  �¶ȹ���
int sdk_PrnStart(unsigned char* pcPrnData, uint DotLine);

//��ȡ��ǰ��ӡ״̬
//�� �� ֵ: 0�ɹ�
//          -1  ��ӡ�豸δ��ʼ��
//          -2  ȱֽ
//          -3  �¶ȹ���
int sdk_PrnGetStatus(void);

//�� �� ��: PRN_PaperForward
//��    ��: ��ǰ��ָ�����е�ֽ
//ȫ�ֱ���: ��
//�������: DotLine:��ֽ������
//�������: ��
//�� �� ֵ: 0�ɹ�, -1ʧ��,-2��ӡ�豸δ��ʼ��
int sdk_PrnPaperFeed(unsigned short DotLine);

//�� �� ��: sdk_PrnFill
//��    ��: ��strָ�����ַ��������ӡ������
//ȫ�ֱ���: ��
//�������: str:Ҫ��ӡ���ַ���
//�������: ��
//�� �� ֵ:
//          PRN_FAILURE(-1)         :��ӡʧ��
//          PRN_OUT_OF_PAPER(-2)    :ȱֽ
//          PRN_ABORT_TEMP(-3)      :�¶ȹ���
//          0                       :�ɹ�
//��    ��: �� ־ ��
//��������: 2009/9/02
//�� �� ��:
//�޸�����:
//��    ע:
int sdk_PrnFill( unsigned char *str );

//�� �� ��: sdk_PrnExecute
//��    ��: ���øú�����������ӡ����ӡ�����е�����.
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ:
//          PRN_FAILURE(-1)         :��ӡʧ��
//          PRN_OUT_OF_PAPER(-2)    :ȱֽ
//          PRN_ABORT_TEMP(-3)      :�¶ȹ���
//          ����ֵ:                 :�ɹ���ӡ�����ݳ���
//��    ��: �� ־ ��
//��������: 2009/9/02
//�� �� ��:
//�޸�����:
//��    ע:
//          ���ܴ�ӡ�Ƿ�ɹ�,��ӡ�����е����ݾ��ᱻ���.
int sdk_PrnExecute(void);

//�� �� ��: sdk_PrnSetFontMode
//��    ��: ���ô�ӡ����ģʽ
//ȫ�ֱ���: ��
//�������: mode:����ģʽ, ����������ֵ֮һ
//          PRN_MODE_NORMAL     :��׼��ӡ
//          PRN_MODE_DBWIDTH    :�����ӡ
//          PRN_MODE_DBHEIGHT   :���ߴ�ӡ
//          PRN_MODE_DBBOTH     :�����ߴ�ӡ
//�������: ��
//�� �� ֵ: ��
//��    ��: �� ־ ��
//��������: 2009/9/02
//�� �� ��:
//�޸�����:
//��    ע: ���������, Ĭ����PRN_MODE_NORMALģʽ
void sdk_PrnSetFontMode(int mode );

/********************************************************************
��������: ��ȡ��ӡ����ģʽ
�������: 
�������: 
�� �� ֵ: ��ӡ����ģʽ
�޸���Ϣ: 2014-05-15  ��ѩ��  ����
********************************************************************/
int sdk_PrnGetFontMode();

//�� �� ��: sdk_PrnSetFontType
//��    ��: ���ô�ӡ�����С(Ŀǰ֧��:12x12, 16x16, 24x24)
//ȫ�ֱ���: ��
//�������: font_type:����������ֵ֮һ
//          PRN_FONT12
//          PRN_FONT16
//          PRN_FONT24
//�������: ��
//�� �� ֵ: ��
//��    ��: �� ־ ��
//��������: 2009/9/02
//�� �� ��:
//�޸�����:
//��    ע:
void sdk_PrnSetFontType( int font_type );

/********************************************************************
��������: ��ȡ��ӡ�����С
�������: 
�������: 
�� �� ֵ: ��ӡ�����С
�޸���Ϣ: 2014-05-15  ��ѩ��  ����
********************************************************************/
int sdk_PrnGetFontType();

//�� �� ��: sdk_PrnBlankDotLines
//��    ��: ����ӡ���������հ׵���
//ȫ�ֱ���: ��
//�������: dot_lines:Ҫ��ӡ�ĵ�����
//�������: ��
//�� �� ֵ:
//          PRN_FAILURE(-1)             :��ӡʧ��
//          PRN_OUT_OF_PAPER(-2)    :ȱֽ
//          PRN_ABORT_TEMP(-3)      :�¶ȹ���
//          0                       :�ɹ�
//��    ��: �� ־ ��
//��������: 2009/9/02
//�� �� ��:
//�޸�����:
//��    ע: 1.�������������ִ�ӡ�����������Զ���ӡ,֮�������������
//          2.����ӡ���̳���,���ж������̲����ط�0ֵ
int sdk_PrnBlankDotLines( unsigned short dot_lines );

#ifdef __cplusplus
}
#endif

#endif

