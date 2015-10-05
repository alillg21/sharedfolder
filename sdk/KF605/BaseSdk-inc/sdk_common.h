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

#define OK          0   //成功
#define FAIL        -1  //失败
#define OVERTIME    -2  //超时

#undef uchar
#define uchar unsigned char
#undef ulong
#define ulong unsigned long
#undef uint 
#define uint unsigned int
#undef ushort
#define ushort unsigned short

#define CLOSED -1   //设备已关闭

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
         2.eg: temp_buf = sdk_UnicodeConvert("中国你好 123ABC#^");
--------------------------------------------------------------------------------
Author  : LYN
*******************************************************************************/
char* sdk_UnicodeConvert(char *pcSrc_Asc);

/********************************************************************************
Function    : sdk_UnicodeCat
Description : combine Unicode string，consult strcat.
        The function appends the [src] string to the [dest] string,
        overwriting the null byte ('\0') at the end of [dest], and then adds a terminating null byte.
        The strings may not overlap, and the [dest] string must have enough space for the result.
Parameter   : pcSrc_Base64 : source character string，BASE64 format(get it from GetStr)
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

// 1.bitmap head:include :file type、size、save position and so on ,it is size is 14 bytes
typedef struct tagBITMAPFILEHEADER
{
    /* bmfh */
    unsigned short bfType;      //说明文件的类型. 该值必需是0x4D42，也就是字符'BM'。
    unsigned long bfSize;       //说明文件的大小，用字节为单位
    unsigned short bfReserved1; //保留，必须设置为0
    unsigned short bfReserved2; //保留，必须设置为0
    unsigned long bfOffBits;    //说明从文件头开始到实际的图象数据之间的字节的偏移量。
//}__attribute__((packed)) BITMAPFILEHEADER;
} __attribute__((packed)) BITMAPFILEHEADER;

// 2.位图信息头:
//BITMAPINFOHEADER结构: 包含有位图文件的大小、压缩类型和颜色格式, 长度40字节
typedef struct tagBITMAPINFOHEADER
{
    /* bmih */
    unsigned long biSize;   //说明BITMAPINFOHEADER结构所需要的字数。28h - Windows 3.1x, 95, NT, …
    long biWidth;       //说明图象的宽度，以象素为单位
    long biHeight;      //说明图象的高度，以象素为单位。
    short biPlanes;     //为目标设备说明位面数，其值将总是被设为1
    short biBitCount;   //说明比特数/象素，其值为1、4、8、16、24、或32。表示颜色深度。
    //其中1（单色），4（16色），8（256色），16（64K色，高彩色），24（16M色，真彩色），32（4096M色，增强型真彩色）
    unsigned long biCompression;    //说明图象数据压缩的类型。其值可以是下述值之一：BI_RGB,BI_RLE8,BI_RLE4,BI_BITFIELDS
    unsigned long biSizeImage;  //说明图象的大小，以字节为单位。该数必须是4的倍数
    long biXPelsPerMeter;   //说明水平分辨率，用象素/米表示
    long biYPelsPerMeter;   //说明垂直分辨率，用象素/米表示
    unsigned long biClrUsed;        //说明位图实际使用的彩色表中的颜色索引数（设为0的话，则说明使用所有调色板项）
    unsigned long biClrImportant;   //说明对图象显示有重要影响的颜色索引的数目，如果是0，表示都重要。
} __attribute__((packed)) BITMAPINFOHEADER;

// 3.彩色表: 彩色表包含的元素与位图所具有的颜色数相同，象素的颜色用RGBQUAD结构来定义。
typedef struct tagRGBQUAD
{
    /* rgbq */
    unsigned char rgbBlue;      //指定蓝色强度
    unsigned char rgbGreen;     //指定绿色强度
    unsigned char rgbRed;       //指定红色强度
    unsigned char rgbReserved;  //保留，设置为0
} __attribute__((packed)) RGBQUAD;

// 位图信息用BITMAPINFO结构来定义，它由位图信息头(bitmap-information header)和彩色表(color table)组成
typedef struct tagBITMAPINFO
{
    /* bmi */
    BITMAPINFOHEADER bmiHeader;     //说明BITMAPINFOHEADER结构，其中包含了有关位图的尺寸及位格式等信息
    RGBQUAD bmiColors[1];       //说明彩色表RGBQUAD结构的阵列，其中包含索引图像的真实RGB值
} __attribute__((packed)) BITMAPINFO;

// 4.位图数据: 紧跟在彩色表之后的是图象数据字节阵列。

/*****************************************
*Description：
*      save bitmap data to BMP file
*Parameter：
*      char *bmpName-file name and path
*      unsigned char *imgBuf-bitmap data need to be save
*      int width-bitmap data width base on pels
*      int  height-bitmap data height base on pels
*      int biBitCount-pels size
*      RGBQUAD *pColorTable-pointer point color table
*return：
*      0:fail，1:success
*Notes：give bitmap message that data、width、height、pointer color table and pels size and so on,
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
*Description：
*      rad bitmap data fron BMP
*Parameter：
*      char *bmpName -file name and path
*return：
*      0:fail，1:success
*Notes：give file name and path,read map's data、width、height、color table and pels size and save them in output parameter
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
*Description：
*      CaptureLCD() - get LCD lattice data
*Parameter：
*      char *pcSaveDir - screen picture file save path,when it NULL or it is 0 default it save directory is "/var/pictures/"
*Return ：
*      0 :success，other:fail
*Notes：save screen lattice as BMP,save in directory according pcSaveDir and file name self-build
       according date,memory directory can save 1024 sheet BMP at most
****************************************/
int sdk_CaptureLCD(char *pcSaveDir);

/****************************************
*Description：
*      PrintBarCode() - print barcode
*Parameter：
*      pcBarcode     - the value need to been print
*      byBarcodeType - the type of barcode，0-Code 39; 1-Code 128; 2-EAN 13
*      byPrintMode   - 0-Normal, 1-Double Width, 2-Double Height,3-Both Double Width and Height
*Return：
*       0:success，other:fail
*      -1:fail，data length error or value not follow rule.
       when byBarcodeType is 0,when byPrintMode is 1 or 3 the data length between 1-13,
          when byPrintMode is 0 or 2 the data length between 1-26
          when byBarcodeType is 1,when byPrintMode is 1 or 3 the data length between 1-24,
          when byPrintMode is 0 or 2 the data length between 1-26
       when byBarcodeType is 2,the data length must 13,and the data must follow EAN13 rule .
       such as 6901424333948 or 4897028377766 and so on.goods'bar code follow EAN13
*      -2:fail，parameter error
       when byBarcodeType is 2,the data not follow EAN13 rule,the checkcode is wrong!
*      other: print error
*Notes:

****************************************/
int sdk_PrintBarCode(unsigned char *pcBarcode, int byBarcodeType,int byPrintMode);

/****************************************
*Description：
*      sdk_GenerateBarCode()-Generate barcode
*Parameter：
*      pcBarcode      - the value need to been print
*      Bitmap_Barcode - Bitmap need to been print
*      byBarcodeType  - the type of barcode，0-Code 39; 1-Code 128; 2-EAN 13
*      byPrintMode    - 0-Normal, 1-Double Width, 2-Double Height,3-Both Double Width and Height
*      width  -  width of Bitmap
*      height -  height of Bitmap
*Return：
*       0:success，other:fail
*      -1:fail，data length error or value not follow rule.
       when byBarcodeType is 0,when byPrintMode is 1 or 3 the data length between 1-13,
          when byPrintMode is 0 or 2 the data length between 1-26
          when byBarcodeType is 1,when byPrintMode is 1 or 3 the data length between 1-24,
          when byPrintMode is 0 or 2 the data length between 1-26
       when byBarcodeType is 2,the data length must 13,and the data must follow EAN13 rule .
       such as 6901424333948 or 4897028377766 and so on.goods'bar code follow EAN13
*      -2:fail，parameter error
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
*Description：
*      sdk_PrintPdf417Code() -  print barcode
*Parameter：
*      strInput     - the value need to been print
*Return：
*       0:success
*       other:print fail
--------------------------------------------------------------------------------
Author: creat by Chunhua Peng (2013/8/19)
********************************************************************************/
int sdk_PrintPdf417Code(unsigned char *strInput);

/********************************************************************************
*Description：
*      sdk_PrintPdf417Code() -  generate barcode
*Parameter：
*      strInput     - the value need to been print
*      Bit_Result   - Bitmap need to been print
*      wide  -  width of Bitmap
*      high -  height of Bitmap
*Return：
*       0:success，other:fail
--------------------------------------------------------------------------------
Author: creat by Chunhua Peng (2013/8/19)
********************************************************************************/
int sdk_GeneratePdf417Code(unsigned char *strInput, unsigned char *Bit_Result, int *wide, int *high);

#ifdef __cplusplus
}
#endif

#endif

