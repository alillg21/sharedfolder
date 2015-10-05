/********************************************************************
文件名 : sdkTools.h
描  述 : Tools工具模块
版  权 : 长城开发
作  者 : 卢裕燕
修改记录:
    日期              修改人  修改内容
    2013-12-30 16:19  卢裕燕  创建
********************************************************************/
#ifndef BASE_SDKTOOLS_H_
#define BASE_SDKTOOLS_H_

#ifdef __cplusplus
    extern "C" {
#endif

typedef enum
{
    SDK_FILE_OK =0,                 //文件操作成功
    SDK_FILE_EOF,                   //读操作时碰到文件尾
    SDK_FILE_SEEK_ERROR,            //写文件定位越界
    SDK_FILE_ERROR,                 //文件打开或创建失败
    SDK_FILE_CRCERR,                //文件校验错
} E_SDK_FILE_RETURN;

#pragma pack(1)

// 1.位图文件头: 包含有关于文件类型、文件大小、存放位置等信息, 长度14字节
typedef struct //t_tag_bit_map_file_header
{   /* bmfh */
    u16 bfType;          //说明文件的类型. 该值必需是0x4D42，也就是字符'BM'。
    unsigned long bfSize;           //说明文件的大小，用字节为单位
    u16 bfReserved1;     //保留，必须设置为0
    u16 bfReserved2;     //保留，必须设置为0
    unsigned long bfOffBits;        //说明从文件头开始到实际的图象数据之间的字节的偏移量。
} T_SDK_BIT_MAP_FILE_HEADER;

// 2.位图信息头:
//BITMAPINFOHEADER结构: 包含有位图文件的大小、压缩类型和颜色格式, 长度40字节
typedef struct //t_tag_bit_map_info_header
{   /* bmih */
    unsigned long biSize;           //说明BITMAPINFOHEADER结构所需要的字数。28h - Windows 3.1x, 95, NT, …
    long biWidth;                   //说明图象的宽度，以象素为单位
    long biHeight;                  //说明图象的高度，以象素为单位。
    s16 biPlanes;                 //为目标设备说明位面数，其值将总是被设为1
    s16 biBitCount;               //说明比特数/象素，其值为1、4、8、16、24、或32。表示颜色深度。
                                    //其中1（单色），4（16色），8（256色），16（64K色，高彩色），24（16M色，真彩色），32（4096M色，增强型真彩色）
    unsigned long biCompression;    //说明图象数据压缩的类型。其值可以是下述值之一：BI_RGB,BI_RLE8,BI_RLE4,BI_BITFIELDS
    unsigned long biSizeImage;      //说明图象的大小，以字节为单位。该数必须是4的倍数
    long biXPelsPerMeter;           //说明水平分辨率，用象素/米表示
    long biYPelsPerMeter;           //说明垂直分辨率，用象素/米表示
    unsigned long biClrUsed;        //说明位图实际使用的彩色表中的颜色索引数（设为0的话，则说明使用所有调色板项）
    unsigned long biClrImportant;   //说明对图象显示有重要影响的颜色索引的数目，如果是0，表示都重要。
} T_SDK_SDK_BIT_MAP_FILE_HEADER;

// 3.彩色表: 彩色表包含的元素与位图所具有的颜色数相同，象素的颜色用RGBQUAD结构来定义。
typedef struct //t_tag_rgb_quad
{   /* rgbq */
    u8 rgbBlue;          //指定蓝色强度
    u8 rgbGreen;         //指定绿色强度
    u8 rgbRed;           //指定红色强度
    u8 rgbReserved;      //保留，设置为0
} T_SDK_RGB_QUAD;

// 位图信息用BITMAPINFO结构来定义，它由位图信息头(bitmap-information header)和彩色表(color table)组成
typedef struct //t_tag_bit_map_info
{   /* bmi */
    T_SDK_SDK_BIT_MAP_FILE_HEADER bmiHeader;     //说明BITMAPINFOHEADER结构，其中包含了有关位图的尺寸及位格式等信息
    T_SDK_RGB_QUAD bmiColors[1];           //说明彩色表RGBQUAD结构的阵列，其中包含索引图像的真实RGB值
} T_SDK_BIT_MAP_INFO;

// 4.位图数据: 紧跟在彩色表之后的是图象数据字节阵列。

#pragma pack()

s32 sdkFileRead(u8 *pszFile, u8 *phexOut, u32 uiStart, u32 *puiLen);
s32 sdkFileWrite(u8 *pszFile, u8 *phexIn, u32 uiLen);
s32 sdkFileAppend(u8 *pszFile, u8 *phexIn, u32 uiLen);
s32 sdkFileInsert(u8 *pszFile, u8 *phexIn, u32 uiStart, u32 uiLen);
s32 sdkFileDel(u8 *pszFile);
s32 sdkFileGetSize(u8 *pszFile);
s32 sdkFileAccess(u8 *pszFile);
s32 sdkFileRename(u8 *pszFileName, u8 *pszFileNewName);
s32 sdkFileSysFreeSpace(u32 *puiSize);
//
s32 sdkAscToBcd(const u8* phexSrc, u32 uiLen, u8* phexDest);
s32 sdkAscToBcdR(const u8* phexSrc, u32 uiLen, u8* phexDest);
s32 sdkBcdToAsc(const u8* phexSrc, u32 uiLen, u8* phexDest);
s32 sdkBcdToU8 (u8 *punDest, const u8 *pbcSrc, u32 uiSrclen);
s32 sdkU8ToBcd(const u8  ucSrc,u32 uiDestLen, u8 *pbcDest);
s32 sdkBcdToU16(u16 *punDest, const u8 *pbcSrc, u32 uiSrclen);
s32 sdkU16ToBcd(u16 const unSrc, s32 uiDestlen, u8 *pbcDest);
s32 sdkBcdToU32(u32 *puiDest, const u8 *pbcSrc, u32 uiSrclen);
s32 sdkU32ToBcd(u32 const uiSrc, s32 uiDestlen, u8 *pbcDest);
s32 sdkHexToU16(u16 *punDest, const u8 * phexSrc, u32 uiSrclen);
s32 sdkU16ToHex(const u16 phexSrc,u32 uiLen, u8* phexDest);
s32 sdkHexToU32(u32 *puiDest, const u8 *pbcSrc, u32 uiSrclen);
s32 sdkU32ToHex(u32 const uiSrc, s32 uiDestlen, u8 * phexDest);
s32 sdkU8ToAsc(const u8 ucSrc,u32 uiDestLen, u8 *pasDest);
s32 sdkU16ToAsc(const u16 ucSrc,u32 uiDestLen, u8 *pasDest);
s32 sdkU32ToAsc(const u32 ucSrc,u32 uiDestLen, u8 *pasDest);
s32 sdkAscToDouble(const u8* phexSrc, u32 uiLen, double* phexDest);
BOOL sdkIsAscii(const u8* phexSrc);
s32 sdkFormatAmt(const u8* phexSrc, u8* phexDest);
s32 sdkRevFormatAmt(const u8* phexSrc, u8* phexDest);
s32 sdkRemoveSpace(const u8* phexSrc, u8* phexDest);
s32 sdkCutStr(const u8* phexSrc,u32 uiLen, u8* phexDest);
s32 sdkGetCarNO(const u8* pAscSrc, u8* pAscDest, u32* uiLen);
s32 sdkCardNOVerify(const u8* phexSrc);
s32 sdkBcdAdd(const u8* pbcSrc, u8* pbcDest, u32 uiLen);
s32 sdkBcdSub(const u8* pbcSrc, u8* pbcDest, u32 uiLen);
s32 sdkGetRand(void);
s32 sdkSaveBmp(s8 *pcBmpName, u8 *pucImgBuf, s32 iWidth, s32 iHeight, s32 iBitCount, T_SDK_RGB_QUAD **pptColorTable);
s32 sdkReadBmpFile(s8 *pcBmpName, u8 *pucImgBuf, s32 *piWidth, s32 *piHeight, s32 *piBitCount, T_SDK_RGB_QUAD **pptColorTable);
s32 sdkReadBmpData(s8 *pcBmpData, u8 *pucBitmapBuf, s32 *piWidth, s32 *piHeight, s32 *piBitCount, T_SDK_RGB_QUAD **pptColorTable);

#ifdef __cplusplus
    }
#endif

#endif

