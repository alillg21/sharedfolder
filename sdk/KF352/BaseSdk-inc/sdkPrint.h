/********************************************************************
�ļ��� : sdkPrint.h
��  �� : �ʹ�ӡ����صĺ���
��  Ȩ : ���ǿ���
��  �� : DJ Chen
�޸ļ�¼: 
    ����              �޸���  �޸�����
    2014-01-07 13:19  DJ Chen  ����
********************************************************************/
#ifndef BASE_SDKPRINT_H_
#define BASE_SDKPRINT_H_
#include "sdkTypeDef.h"


#ifdef __cplusplus
    extern "C" {
#endif

//  Font Mode
#define PRN_MODE_NORMAL   0x00 // normal height, normal width ����
#define PRN_MODE_DBWIDTH  0x01 // normal height, double width ����
#define PRN_MODE_DBHEIGHT 0x02 // double height, normal width ����
#define PRN_MODE_DBBOTH   0x03 // double height, double width ������

#define PRN_MODE_LEFT            0x01  //����
#define PRN_MODE_MIDDLE          0x02  //����
#define PRN_MODE_RIGHT           0x03  //����

//��ӡ��״ֵ̬
#define SDK_PRN_STATUS_OK 0
#define SDK_PRN_STATUS_PAPEROUT (SDK_USER_DEFINE-1)   //��ӡ��ȱֽ
#define SDK_PRN_STATUS_TOOHEAT  (SDK_USER_DEFINE-2)   //�¶ȹ���
#define SDK_PRN_STATUS_FAULT    (SDK_USER_DEFINE-3)   //��ӡ���豸����

//��������
#define SDK_PRN_CODE39  0x00
#define SDK_PRN_CODE128 0x01
#define SDK_PRN_EAN13   0x02


//����ַ��Ľṹ
typedef struct{
    s8 *pcInfo;         //Ҫ��ӡ���ַ���
    u8 ucFont;          //���� ͬLCD��ʾ������
    u8 ucInterval;      //�ּ�� ��λ:pixel ��δʵ��
    u8 ucAtt;           //������ =0�׵׺��� =FONT_CONTRAST�ڵװ���
    u8 ucBold;          //�Ӵ�
    u8 ucItalic;        //б��
    u8 ucUnderline;     //�»���
}T_PRN_INFOATT;

s32 sdkPrnOpen(void);
s32 sdkPrnClose(void);

s32 sdkPrnSetGray(u8 ucGray);
s32 sdkPrnSetSpeed(u8 ucSpeed);
s32 sdkPrnSetFont(s8 *pFontName, s8 *pFontCharacter, u32 Size);
void sdkPrnSetRowGap(u32 uiRowGap);

s32 sdkPrnFillBuffer(u8  *pszBuf, u8 ucAlign, u32 uiFontZoom, u32 uiOffset);
s32 sdkPrnLogo(u8 *pBMPBuf, u32 uiOffset);
s32 sdkPrnBarcode (u8 *pBarcode, u8 ucBarcodeType,u32 uiPrintMode, u32 uiOffset);
s32 sdkPrnQRCode(const s8 *pszInput, s32 iMultiple, u32 uiOffset);
s32 sdkPrnStart(void);

s32 sdkPrnGetCurLine(void);
s32 sdkPrnDotStep(u8 ucDir,u32 uiDotLine);
s32 sdkPrnPaperForward(u32 uiPIXNum);
s32 sdkPrnStatus(void);

#ifdef __cplusplus
    }
#endif

#endif

