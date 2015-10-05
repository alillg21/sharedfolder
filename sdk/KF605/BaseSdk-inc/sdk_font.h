/*!@file
********************************************************************************
Module: Common
file name: sdk_font.h

function: system file
Author: CRD by Zumiao Yu
version: 1.0.0
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
modify :
date              version          by           fixed
2010/02/23    1.0.0             Yu            create
*******************************************************************************/
#ifndef _sdk_FONT_H_
#define _sdk_FONT_H_

#include "sdk_common.h"

#define FILE_ASC6X8 "/usr/font/ASC6X8"
#define FILE_ASC12 "/usr/font/ASC12"
#define FILE_HZK12 "/usr/font/HZK12"
#define FILE_ASC16 "/usr/font/asc16"
#define FILE_HZK16 "/usr/font/HZK16"
#define FILE_ASC24 "/usr/font/ASC24"
#define FILE_HZK24 "/usr/font/HZK24"

//Unicode char
#if 1 //phoenix 20140411 11:26
#define FILE_UC_ASC6X8  "/usr/font/UNICODE_ASC6x8"
#define FILE_UC_ASC12   "/usr/font/UNICODE_ASC6x12"
#define FILE_UC_ASC24X12   "/usr/font/UNICODE_ASC24x12"
#define FILE_UC_ASC16   "/usr/font/UNICODE_ASC8x16"
#define FILE_UC_ASC24   "/usr/font/UNICODE_ASC12x24"
#else
#define FILE_UC_ASC6X8  "/usr/font/UNICODE_ASC6x8"
#define FILE_UC_ASC12   "/usr/font/UNICODE_ASC12x12" //phoenix
#define FILE_UC_ASC16   "/usr/font/UNICODE_ASC16x16" //phoenix
#define FILE_UC_ASC24   "/usr/font/UNICODE_ASC12x24"
#endif

//������Ѿ�����ʾ���Կ�һһ��Ӧ
//this define is homologous to display_attribute lib.
#define FONT_NUM        13

#define FONT_ENG6X12        0x00
#define FONT_ENG8X16    0x01
#define FONT_ENG12X24   0x02
//#define FONT_ENG24X48 0x03
//#define FONT_ENG48X96 0x04
#define FONT_CHN32X32   0x03        //chengluo  double width,double height
#define FONT_CHN48X48   0x04        //chengluo double width,double height

#define FONT_CHN12X12   0x05        //default font type
#define FONT_CHN16X16   0x06
#define FONT_CHN24X24   0x07

#define FONT_CHN12X24   0x08        //double height
#define FONT_CHN16X32   0x09
#define FONT_CHN24X48   0x0A

#define FONT_ENG6X8     0x0B

#define FONT_SINHALA24X12 0x0C
//�������//attribute of filling
#define FONT_CONTRAST   0x80    //�Ƿ���//whether display black_back and write font.
#define THREE_COMPINED_SINHALA 23
#define COMPINED_SINHALA_CHAR 3
typedef struct
{
    uchar cWide;
    uchar cHigh;
} __attribute__((packed)) T_FONT_FRAME;


typedef struct
{
    uchar cMultCharNum; //���ᳬ��10����ά���ϵ����
    uchar szIdex[10];   //�ڴ����Unicode�е�index
    uchar szCharlen[10];//������ռ���ֽڳ���
    uchar szCharIdex[10];//�ڶ�ά����е�index
}T_MULT_CHAR_INFO;

//demo struct
typedef struct
{
    uchar *pMemory; //��ʾ���ӡ���ڴ�����ָ��
    int nRecWide;   //��ʾ���ӡ������(����)�Ŀ� ��λ:Pixel
    int nRecHigh;   //��ʾ���ӡ������(����)�ĸ� ��λ:Pixel

    int nXStart;    //��ʾ���ӡ������(����)����ʼ����(x) ��λ:Pixel
    int nXEnd;      //��ʾ���ӡ������(����)�Ľ�������(x) ��λ:Pixel
    int nYStart;    //��ʾ���ӡ������(����)����ʼ������(y) ��λ:Pixel
    int nYEnd;      //��ʾ���ӡ������(����)�Ľ�������(y) ��λ:Pixel
} __attribute__((packed)) T_FONT_BOARD;


typedef struct _SINHALA_RECORD
{
    unsigned char ulastflag;    //ɮ٤��ǰһ�ַ��Ƿ��׼����ַ���0����1����
    int ncoladdr;               //ǰһ����ַ����ļ�λ��
} SINHALA_RECORD;


#ifdef __cplusplus
extern "C" {
#endif

//int sdk_FontCheckIsGB2312(uchar *src);
//int sdk_FontCheckIsGB18030(uchar *str);
    int sdk_FontCheckIsGB(unsigned char *str);
//int sdk_FontQueryBitmap(uchar *pucSrc, uchar *pcDest, char cFont);
    int sdk_Calc24x12FontCount(const char *pstr);
int sdk_CalcEnCharCount(const char *pstr);
    int sdk_FontFillBit(T_FONT_BOARD *ptFrameBoard, T_FONT_BOARD *ptInfoBoard);
    int sdk_FontFillStr(uchar cFont, uchar cFillAtt, char* pcString, T_FONT_BOARD *PFontBoard);
int Sdk_FindSinhalaCharNode(unsigned int *pCharlen,const char *pstr,unsigned char *puwcode);
    unsigned char PrivateCheckSinhalaChar(unsigned char *pstrout,const char *pcImage,unsigned char ucAttr);
    extern uchar sdk_LcdGetCurFont(void);
#ifdef __cplusplus
}
#endif

#endif

