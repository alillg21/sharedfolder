/*!@file
********************************************************************************
Module: Common
file name: sdk_common.h

function: system file
Author: CRD by Zumiao Yu
version: 1.0.0
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
modify :
date              version          by           fixed
2010/02/23    1.0.0             Yu            create
*******************************************************************************/
#ifndef _SDK_COMMON_H_
#define _SDK_COMMON_H_

#define OK          0   //�ɹ�
#define FAIL        -1  //ʧ��
#define OVERTIME    -2  //��ʱ

#undef uchar
#define uchar unsigned char
#undef ulong
#define ulong unsigned long
#undef uint 
#define uint unsigned int
#undef ushort
#define ushort unsigned short

#define CLOSED -1   //�豸�ѹر�

#ifdef __cplusplus
extern "C" {
#endif

void sdk_OddBCDADD(uchar* pbDest, uchar* pbSrc, uchar cLen);
ulong sdk_OddBCD2LONG(uchar* pbSrc, uchar cLen);
void sdk_OddBCD2BCD(uchar* pbDest, uchar* pbSrc, ushort cLen);

void sdk_BCD2OddBCD(uchar* pbDest, uchar* pbSrc, ushort cLen);
void sdk_BCD2STR(char* pcDestStr, uchar* pcSrcBcd, ushort nLen);
ulong sdk_BCD2LONG(uchar* pcBcd, uchar cLen);
//
void sdk_LONG4BYTE(uchar* psDest, ulong nNum);
void sdk_LONG2BCD(uchar* pcDestBcd, ulong nSrcNum, uchar cLimitDestLen, uchar cType);
ulong sdk_BYTE2LONG(uchar* pcData, uchar cLen);
ulong sdk_STR2LONG(char* psStr);
ushort sdk_STR2BCD(uchar* pcDestBcd, char* pcSrcStr, ushort cBcdLen, uchar cLeftRight);

ushort sdk_Partion_Strbuf(char *pcDest, char *pcSrc, ushort nLen);
void sdk_Format_Str_Money(char *pcDest, char *pcSrc);

void sdk_DesEncrypt(uchar cType, uchar* psDesData, uchar* psKey);
void sdk_3DesEncrypt(uchar cType, uchar* psDesData, uchar* psKey);
ulong sdk_Crc32(ulong crc, uchar *buf, ulong len);

extern void sdk_BcdToAsc(unsigned char *asc, unsigned char *bcd, unsigned char asc_len);

extern void sdk_AscToBcd(unsigned char *bcd, unsigned char *asc, unsigned char asc_len);

//Description: convert the source buffer data to base64 format.
//Return:
//  >0 - successful, return the real length of encoded data
//      (refer to dest_len, limit by dest_len).
//  -1 - failed
int sdk_Base64Encode(char *dest_buf, int dest_len, char *src_buf, int src_len);

//Description: convert the data in base64 format to normal char format.
//Return:
//  >0 - successful, return the real length of decoded data
//      (refer to dest_len, limit by dest_len).
//  -1 - failed
int sdk_Base64Decode(char *dest_buf, int dest_len, char *src_buf, int src_len);

/********************************************************************************
Function    : sdk_UnicodeConvert
Description : convert ASC format into Unicode that in BASE64 format
Parameter   : pcSrc_Asc : source character string that need to been convert
Return      : point to string that in BASE64 format - success
--------------------------------------------------------------------------------
Notes  : 1.convert source character string(pcSrc_Asc) into Unicode,then convert into BASE64 format
         2.eg: temp_buf = sdk_UnicodeConvert("�й���� 123ABC#^");
--------------------------------------------------------------------------------
Author  : LYN
*******************************************************************************/
char* sdk_UnicodeConvert(char *pcSrc_Asc);

/********************************************************************************
Function    : sdk_UnicodeCat
Description : combine Unicode string��consult strcat.
        The function appends the [src] string to the [dest] string,
        overwriting the null byte ('\0') at the end of [dest], and then adds a terminating null byte.
        The strings may not overlap, and the [dest] string must have enough space for the result.
Parameter   : pcSrc_Base64 : source character string��BASE64 format(get it from GetStr)
              pcAppend_Asc : string need to been superadd(such as strcat),ASC format
              pcDest_Base64: output result,in BASE64 format
Return      : 0     - success
              other - fail
--------------------------------------------------------------------------------
Notes : 1.combine source character string(pcSrc_Base64) and superaddition string(pcAppend_Asc)
        2.when source string(pcSrc_Base64)is NULL,convert pcStr_Append into Unicode and output in Base64 format
        3.output combined string that Unicode format,and output in BASE64 format
        4.eg: sdk_UnicodeCat(GetStr(eREC_MerchantID), "123456789012345", merchant_id);
--------------------------------------------------------------------------------
Author  : KAIFA
*******************************************************************************/
int sdk_UnicodeCat(char *pcSrc_Base64, char *pcAppend_Asc, char *pcDest_Base64);

//Set Unicode characters set
//PARAM:
//  cIsUnicodeFlag: 0-Not Unicode; 1-Is Unicode
void sdk_SetUnicodeChar(int cIsUnicodeFlag);

//Get Unicode characters set
//RETURN:
//  0-Not Unicode; 1-Is Unicode
int sdk_GetUnicodeFlag(void);

/*
sdk_BYTE2LONG
sdk_LONG2BYTE
sdk_STR2LONG
sdk_BCD2LONG
*/

// 1.bitmap head:include :file type��size��save position and so on ,it is size is 14 bytes
typedef struct tagBITMAPFILEHEADER
{
    /* bmfh */
    unsigned short bfType;      //˵���ļ�������. ��ֵ������0x4D42��Ҳ�����ַ�'BM'��
    unsigned long bfSize;       //˵���ļ��Ĵ�С�����ֽ�Ϊ��λ
    unsigned short bfReserved1; //��������������Ϊ0
    unsigned short bfReserved2; //��������������Ϊ0
    unsigned long bfOffBits;    //˵�����ļ�ͷ��ʼ��ʵ�ʵ�ͼ������֮����ֽڵ�ƫ������
//}__attribute__((packed)) BITMAPFILEHEADER;
} __attribute__((packed)) BITMAPFILEHEADER;

// 2.λͼ��Ϣͷ:
//BITMAPINFOHEADER�ṹ: ������λͼ�ļ��Ĵ�С��ѹ�����ͺ���ɫ��ʽ, ����40�ֽ�
typedef struct tagBITMAPINFOHEADER
{
    /* bmih */
    unsigned long biSize;   //˵��BITMAPINFOHEADER�ṹ����Ҫ��������28h - Windows 3.1x, 95, NT, ��
    long biWidth;       //˵��ͼ��Ŀ�ȣ�������Ϊ��λ
    long biHeight;      //˵��ͼ��ĸ߶ȣ�������Ϊ��λ��
    short biPlanes;     //ΪĿ���豸˵��λ��������ֵ�����Ǳ���Ϊ1
    short biBitCount;   //˵��������/���أ���ֵΪ1��4��8��16��24����32����ʾ��ɫ��ȡ�
    //����1����ɫ����4��16ɫ����8��256ɫ����16��64Kɫ���߲�ɫ����24��16Mɫ�����ɫ����32��4096Mɫ����ǿ�����ɫ��
    unsigned long biCompression;    //˵��ͼ������ѹ�������͡���ֵ����������ֵ֮һ��BI_RGB,BI_RLE8,BI_RLE4,BI_BITFIELDS
    unsigned long biSizeImage;  //˵��ͼ��Ĵ�С�����ֽ�Ϊ��λ������������4�ı���
    long biXPelsPerMeter;   //˵��ˮƽ�ֱ��ʣ�������/�ױ�ʾ
    long biYPelsPerMeter;   //˵����ֱ�ֱ��ʣ�������/�ױ�ʾ
    unsigned long biClrUsed;        //˵��λͼʵ��ʹ�õĲ�ɫ���е���ɫ����������Ϊ0�Ļ�����˵��ʹ�����е�ɫ���
    unsigned long biClrImportant;   //˵����ͼ����ʾ����ҪӰ�����ɫ��������Ŀ�������0����ʾ����Ҫ��
} __attribute__((packed)) BITMAPINFOHEADER;

// 3.��ɫ��: ��ɫ�������Ԫ����λͼ�����е���ɫ����ͬ�����ص���ɫ��RGBQUAD�ṹ�����塣
typedef struct tagRGBQUAD
{
    /* rgbq */
    unsigned char rgbBlue;      //ָ����ɫǿ��
    unsigned char rgbGreen;     //ָ����ɫǿ��
    unsigned char rgbRed;       //ָ����ɫǿ��
    unsigned char rgbReserved;  //����������Ϊ0
} __attribute__((packed)) RGBQUAD;

// λͼ��Ϣ��BITMAPINFO�ṹ�����壬����λͼ��Ϣͷ(bitmap-information header)�Ͳ�ɫ��(color table)���
typedef struct tagBITMAPINFO
{
    /* bmi */
    BITMAPINFOHEADER bmiHeader;     //˵��BITMAPINFOHEADER�ṹ�����а������й�λͼ�ĳߴ缰λ��ʽ����Ϣ
    RGBQUAD bmiColors[1];       //˵����ɫ��RGBQUAD�ṹ�����У����а�������ͼ�����ʵRGBֵ
} __attribute__((packed)) BITMAPINFO;

// 4.λͼ����: �����ڲ�ɫ��֮�����ͼ�������ֽ����С�

/*****************************************
*Description��
*      save bitmap data to BMP file
*Parameter��
*      char *bmpName-file name and path
*      unsigned char *imgBuf-bitmap data need to be save
*      int width-bitmap data width base on pels
*      int  height-bitmap data height base on pels
*      int biBitCount-pels size
*      RGBQUAD *pColorTable-pointer point color table
*return��
*      0:fail��1:success
*Notes��give bitmap message that data��width��height��pointer color table and pels size and so on,
*      and write it into appoint file
==========================================
    //For Example:
    RGBQUAD t_ColorTable[256];
    RGBQUAD *ptColorTable[256];
    //init color table
    memset(t_ColorTable, 0, sizeof(t_ColorTable));
    memset(ptColorTable, 0, sizeof(ptColorTable));
    for(i=0; i<sizeof(t_ColorTable)/sizeof(t_ColorTable[0]); i++)
    {
        ptColorTable[i] = &t_ColorTable[i];
    }
******************************************/
int sdk_SaveBmp(char *bmpName, unsigned char *imgBuf, int width,
                int height, int biBitCount, RGBQUAD **pColorTable);

/****************************************
*Description��
*      rad bitmap data fron BMP
*Parameter��
*      char *bmpName -file name and path
*return��
*      0:fail��1:success
*Notes��give file name and path,read map's data��width��height��color table and pels size and save them in output parameter
==========================================
    //For Example:
    RGBQUAD t_ColorTable[256];
    RGBQUAD *ptColorTable[256];
    //init color table
    memset(t_ColorTable, 0, sizeof(t_ColorTable));
    memset(ptColorTable, 0, sizeof(ptColorTable));
    for(i=0; i<sizeof(t_ColorTable)/sizeof(t_ColorTable[0]); i++)
    {
        ptColorTable[i] = &t_ColorTable[i];
    }
****************************************/
int sdk_ReadBmp(char *bmpName, unsigned char *pcBitmapBuf, int *pwWidth,
                int *pwHeight, int *pwBitCount, RGBQUAD **ppColorTable);

/****************************************
*Description��
*      CaptureLCD() - get LCD lattice data
*Parameter��
*      char *pcSaveDir - screen picture file save path,when it NULL or it is 0 default it save directory is "/var/pictures/"
*Return ��
*      0 :success��other:fail
*Notes��save screen lattice as BMP,save in directory according pcSaveDir and file name self-build
       according date,memory directory can save 1024 sheet BMP at most
****************************************/
int sdk_CaptureLCD(char *pcSaveDir);

/****************************************
*Description��
*      PrintBarCode() - print barcode
*Parameter��
*      pcBarcode     - the value need to been print
*      byBarcodeType - the type of barcode��0-Code 39; 1-Code 128; 2-EAN 13
*      byPrintMode   - 0-Normal, 1-Double Width, 2-Double Height,3-Both Double Width and Height
*Return��
*       0:success��other:fail
*      -1:fail��data length error or value not follow rule.
       when byBarcodeType is 0,when byPrintMode is 1 or 3 the data length between 1-13,
          when byPrintMode is 0 or 2 the data length between 1-26
          when byBarcodeType is 1,when byPrintMode is 1 or 3 the data length between 1-24,
          when byPrintMode is 0 or 2 the data length between 1-26
       when byBarcodeType is 2,the data length must 13,and the data must follow EAN13 rule .
       such as 6901424333948 or 4897028377766 and so on.goods'bar code follow EAN13
*      -2:fail��parameter error
       when byBarcodeType is 2,the data not follow EAN13 rule,the checkcode is wrong!
*      other: print error
*Notes:

****************************************/
int sdk_PrintBarCode(unsigned char *pcBarcode, int byBarcodeType,int byPrintMode);

/****************************************
*Description��
*      sdk_GenerateBarCode()-Generate barcode
*Parameter��
*      pcBarcode      - the value need to been print
*      Bitmap_Barcode - Bitmap need to been print
*      byBarcodeType  - the type of barcode��0-Code 39; 1-Code 128; 2-EAN 13
*      byPrintMode    - 0-Normal, 1-Double Width, 2-Double Height,3-Both Double Width and Height
*      width  -  width of Bitmap
*      height -  height of Bitmap
*Return��
*       0:success��other:fail
*      -1:fail��data length error or value not follow rule.
       when byBarcodeType is 0,when byPrintMode is 1 or 3 the data length between 1-13,
          when byPrintMode is 0 or 2 the data length between 1-26
          when byBarcodeType is 1,when byPrintMode is 1 or 3 the data length between 1-24,
          when byPrintMode is 0 or 2 the data length between 1-26
       when byBarcodeType is 2,the data length must 13,and the data must follow EAN13 rule .
       such as 6901424333948 or 4897028377766 and so on.goods'bar code follow EAN13
*      -2:fail��parameter error
       when byBarcodeType is 2,the data not follow EAN13 rule,the checkcode is wrong!
*      other: print error
*Notes:

****************************************/
int sdk_GenerateBarCode(unsigned char *pcBarcode, unsigned char *Bitmap_Barcode, int byBarcodeType, int byPrintMode, int *width, int *height);

void GetQR_Version(char version[], int *len);

/*
* @brief To print QR code bitmap with different texts.
*
* @param strInput : the texts to output QR code bitmap
* @param bitmapx : the width of QR code output bitmap
* @param bitmapy : the height of QR code output bitmap
* @param centerAligned : true for center aligned, or else not center aligned \n
*     if ture,the parameters of xpos and ypos are neglected \n
*     Using in MPOS terminal input, input 1 for true, others for false
* @return -1 ,encode error. or else the height pf the bmp.
*/
int API_PrintQRCode(const char *strInput, int bitmapx, int bitmapy,int centeralign);

/*!
* @brief To print QR code bitmap with different texts.
*
* @param strInput : the texts to output QR code bitmap
* @param QRCode  : the QR code bitmap
* @param bitmapx : the width of QR code output bitmap
* @param bitmapy : the height of QR code output bitmap
* @param multiple : the multiple to output QR code bitmap,it is value is only 2 or 3 or 4 or 8
* @return -1 ,encode error. or else the height pf the bmp.
* @return -2 ,multiple error.
*/
int sdk_GenerateQRCode(const char *strInput, unsigned char *QRCode, int *bitmapx, int *bitmapy,int multiple);

/*sdk_PrintQRCode
* @brief To print QR code bitmap with different texts.
*
* @param strInput : the texts to output QR code bitmap
* @param multiple : the multiple to output QR code bitmap,it is value is only 2 or 3 or 4 or 8
*
* @return -1 ,encode error. or else the height pf the bmp.
* @return -2 ,multiple error.
*/
int sdk_PrintQRCode(const char *strInput, int multiple);

/********************************************************************************
*Description��
*      sdk_PrintPdf417Code() -  print barcode
*Parameter��
*      strInput     - the value need to been print
*Return��
*       0:success
*       other:print fail
--------------------------------------------------------------------------------
Author: creat by Chunhua Peng (2013/8/19)
********************************************************************************/
int sdk_PrintPdf417Code(unsigned char *strInput);

/********************************************************************************
*Description��
*      sdk_PrintPdf417Code() -  generate barcode
*Parameter��
*      strInput     - the value need to been print
*      Bit_Result   - Bitmap need to been print
*      wide  -  width of Bitmap
*      high -  height of Bitmap
*Return��
*       0:success��other:fail
--------------------------------------------------------------------------------
Author: creat by Chunhua Peng (2013/8/19)
********************************************************************************/
int sdk_GeneratePdf417Code(unsigned char *strInput, unsigned char *Bit_Result, int *wide, int *high);

#ifdef __cplusplus
}
#endif

#endif

