/********************************************************************
�ļ��� : sdkPrintExt.h
��  �� : ���ӡ����صĽӿ�
��  Ȩ : ���ǿ���
��  �� : DJ Chen
�޸ļ�¼: 
    ����              �޸���  �޸�����
    2014-02-19 09:02  DJ Chen  ����
********************************************************************/
#ifndef BASE_SDKPRINTEXT_H_
#define BASE_SDKPRINTEXT_H_
    
#ifdef __cplusplus
        extern "C" {
#endif

typedef enum 
{
    SDK_PRINT_LEFTALIGN = 0,       //�����
    SDK_PRINT_RIGHTALIGN = 1,      //�Ҷ���
    SDK_PRINT_MIDDLEALIGN = 2      //���ж���
}E_SDK_PRINT_ALIGNMODE;            //���뷽ʽ

typedef enum 
{
    SDK_FONT_8,
    SDK_FONT_12,
    SDK_FONT_16,
    SDK_FONT_24,
    SDK_FONT_32,
    SDK_FONT_BMP = 13,     //������ӡ��.��ӡ��ɫͼƬ��384����
    SDK_BARCODE_CODE39,     //һά���� Code 39
    SDK_BARCODE_CODE128,    //һά���� Code 128
    SDK_BARCODE_EAN13,      //һά���� EAN 13 
    SDK_BARCODE_QRCode,     //��ά���� QR Code
    SDK_BARCODE_PDF417,     //��ά���� PDF417
}E_SDK_PRINT_FONT;

s32 sdkPrintStr(u8 *pszStr,E_SDK_PRINT_FONT eFont, BOOL bIsBold, E_SDK_PRINT_ALIGNMODE eAlign, u32 uiOffset, u32 uiRowGap);
s32 sdkPrintBitMap(const u8 *pszBmpFile, u32 uiOffset);
s32 sdkPrintSetLastRowGap(u32 uiDoit);
s32 sdkPrintStart(void);

    
#ifdef __cplusplus
        }
#endif
    
#endif



