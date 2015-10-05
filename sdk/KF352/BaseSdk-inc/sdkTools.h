/********************************************************************
�ļ��� : sdkTools.h
��  �� : Tools����ģ��
��  Ȩ : ���ǿ���
��  �� : ¬ԣ��
�޸ļ�¼:
    ����              �޸���  �޸�����
    2013-12-30 16:19  ¬ԣ��  ����
********************************************************************/
#ifndef BASE_SDKTOOLS_H_
#define BASE_SDKTOOLS_H_

#ifdef __cplusplus
    extern "C" {
#endif

typedef enum
{
    SDK_FILE_OK =0,                 //�ļ������ɹ�
    SDK_FILE_EOF,                   //������ʱ�����ļ�β
    SDK_FILE_SEEK_ERROR,            //д�ļ���λԽ��
    SDK_FILE_ERROR,                 //�ļ��򿪻򴴽�ʧ��
    SDK_FILE_CRCERR,                //�ļ�У���
} E_SDK_FILE_RETURN;

#pragma pack(1)

// 1.λͼ�ļ�ͷ: �����й����ļ����͡��ļ���С�����λ�õ���Ϣ, ����14�ֽ�
typedef struct //t_tag_bit_map_file_header
{   /* bmfh */
    u16 bfType;          //˵���ļ�������. ��ֵ������0x4D42��Ҳ�����ַ�'BM'��
    unsigned long bfSize;           //˵���ļ��Ĵ�С�����ֽ�Ϊ��λ
    u16 bfReserved1;     //��������������Ϊ0
    u16 bfReserved2;     //��������������Ϊ0
    unsigned long bfOffBits;        //˵�����ļ�ͷ��ʼ��ʵ�ʵ�ͼ������֮����ֽڵ�ƫ������
} T_SDK_BIT_MAP_FILE_HEADER;

// 2.λͼ��Ϣͷ:
//BITMAPINFOHEADER�ṹ: ������λͼ�ļ��Ĵ�С��ѹ�����ͺ���ɫ��ʽ, ����40�ֽ�
typedef struct //t_tag_bit_map_info_header
{   /* bmih */
    unsigned long biSize;           //˵��BITMAPINFOHEADER�ṹ����Ҫ��������28h - Windows 3.1x, 95, NT, ��
    long biWidth;                   //˵��ͼ��Ŀ�ȣ�������Ϊ��λ
    long biHeight;                  //˵��ͼ��ĸ߶ȣ�������Ϊ��λ��
    s16 biPlanes;                 //ΪĿ���豸˵��λ��������ֵ�����Ǳ���Ϊ1
    s16 biBitCount;               //˵��������/���أ���ֵΪ1��4��8��16��24����32����ʾ��ɫ��ȡ�
                                    //����1����ɫ����4��16ɫ����8��256ɫ����16��64Kɫ���߲�ɫ����24��16Mɫ�����ɫ����32��4096Mɫ����ǿ�����ɫ��
    unsigned long biCompression;    //˵��ͼ������ѹ�������͡���ֵ����������ֵ֮һ��BI_RGB,BI_RLE8,BI_RLE4,BI_BITFIELDS
    unsigned long biSizeImage;      //˵��ͼ��Ĵ�С�����ֽ�Ϊ��λ������������4�ı���
    long biXPelsPerMeter;           //˵��ˮƽ�ֱ��ʣ�������/�ױ�ʾ
    long biYPelsPerMeter;           //˵����ֱ�ֱ��ʣ�������/�ױ�ʾ
    unsigned long biClrUsed;        //˵��λͼʵ��ʹ�õĲ�ɫ���е���ɫ����������Ϊ0�Ļ�����˵��ʹ�����е�ɫ���
    unsigned long biClrImportant;   //˵����ͼ����ʾ����ҪӰ�����ɫ��������Ŀ�������0����ʾ����Ҫ��
} T_SDK_SDK_BIT_MAP_FILE_HEADER;

// 3.��ɫ��: ��ɫ�������Ԫ����λͼ�����е���ɫ����ͬ�����ص���ɫ��RGBQUAD�ṹ�����塣
typedef struct //t_tag_rgb_quad
{   /* rgbq */
    u8 rgbBlue;          //ָ����ɫǿ��
    u8 rgbGreen;         //ָ����ɫǿ��
    u8 rgbRed;           //ָ����ɫǿ��
    u8 rgbReserved;      //����������Ϊ0
} T_SDK_RGB_QUAD;

// λͼ��Ϣ��BITMAPINFO�ṹ�����壬����λͼ��Ϣͷ(bitmap-information header)�Ͳ�ɫ��(color table)���
typedef struct //t_tag_bit_map_info
{   /* bmi */
    T_SDK_SDK_BIT_MAP_FILE_HEADER bmiHeader;     //˵��BITMAPINFOHEADER�ṹ�����а������й�λͼ�ĳߴ缰λ��ʽ����Ϣ
    T_SDK_RGB_QUAD bmiColors[1];           //˵����ɫ��RGBQUAD�ṹ�����У����а�������ͼ�����ʵRGBֵ
} T_SDK_BIT_MAP_INFO;

// 4.λͼ����: �����ڲ�ɫ��֮�����ͼ�������ֽ����С�

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

