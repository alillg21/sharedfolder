/********************************************************************
�ļ��� : sdkLCD.h
��  �� : ��LCD��Ļ��صĴ���
��  Ȩ : ���ǿ���
��  �� : DJ Chen
�޸ļ�¼:
    ����              �޸���  �޸�����
    2013-12-26 08:53  DJ Chen  ����
********************************************************************/
#ifndef BASE_SDKLCD_H_
#define BASE_SDKLCD_H_

#ifdef __cplusplus
    extern "C" {
#endif

#define COLOR_SCREEN     1       //��ɫ��
#define BLACK_SCREEN     0       //��ɫ��

//������ Font Name
#define FONT_COURIER_NEW    "CourierNew"
#define FONT_SONG           "����"
#define FONT_KHMER          "Khmer"     //������(֧��Unicode�ַ���)

//�ַ��� Charset
#define FONT_CHARSET_ASCII   "ASCII"    //������ASC���ַ� (0x00~0x7F)
#define FONT_CHARSET_GB18030 "GB18030"  //��������GBK�����ַ���ASC��
#define FONT_CHARSET_UNICODE "UNICODE"  //��������ͳһ�� (����ͨ���ַ���UCS-2�ַ�)

//����߶�
#define SDK_FONT_HIGHT_8    8       //�ߺͿ�Ϊ8x6��Ӣ���ַ�
#define SDK_FONT_HIGHT_12   12      //�����ַ�ʱ�ߺͿ�Ϊ12x12��ASC��ʱ�ߺͿ�Ϊ12x6
#define SDK_FONT_HIGHT_16   16      //�����ַ�ʱ�ߺͿ�Ϊ16x16��ASC��ʱ�ߺͿ�Ϊ16x8
#define SDK_FONT_HIGHT_24   24      //�����ַ�ʱ�ߺͿ�Ϊ24x24��ASC��ʱ�ߺͿ�Ϊ24x12
#define SDK_FONT_HIGHT_32   32      //�����ַ�ʱ�ߺͿ�Ϊ32x32��ASC��ʱ�ߺͿ�Ϊ32x16

//��ʾ����
#define SDK_LCD_LEFT            0x01  //�����
#define SDK_LCD_RIGHT           0x02  //�Ҷ���
#define SDK_LCD_MIDDLE          0x04  //����
#define SDK_LCD_COL             0x08  //����һ��
#define SDK_LCD_REVERSE         0x10  //�ַ�����
#define SDK_LCD_BOX             0x20  //�ӿ�
#define SDK_LCD_OVERLINE        0x40  //���»���
#define SDK_LCD_REVERSELINE     0x80  //���з��� ��������ô��������ַ����Խ�ʧЧ��

#define SDK_LCD_LINE1    0
#define SDK_LCD_LINE2    1
#define SDK_LCD_LINE3    2
#define SDK_LCD_LINE4    3
#define SDK_LCD_LINE5    4
#define SDK_LCD_LINE6    5
#define SDK_LCD_LINE7    6
#define SDK_LCD_LINE8    7
#define SDK_LCD_LINE9    8
#define SDK_LCD_LINE10   9
#define SDK_LCD_LINE11   10
#define SDK_LCD_LINE12   11
//
#define SDK_LCD_LINE13   12
#define SDK_LCD_LINE14   13
#define SDK_LCD_LINE15   14
#define SDK_LCD_LINE16   15
#define SDK_LCD_LINE17   16
#define SDK_LCD_LINE18   17
#define SDK_LCD_LINE19   18
#define SDK_LCD_LINE20   19
//
#define SDK_LCD_LINE21   20
#define SDK_LCD_LINE22   21
#define SDK_LCD_LINE23   22
#define SDK_LCD_LINE24   23
#define SDK_LCD_LINE25   24
#define SDK_LCD_LINE26   25
#define SDK_LCD_LINE27   26
#define SDK_LCD_LINE28   27

//////////////////////////////// IconNo ////////////////////////////////
//LCD��ʾͼ��ID
#define  SDK_ICON_PHONE      1  // phone �绰
#define  SDK_ICON_SIGNAL     2  // wireless signal �ź�
#define  SDK_ICON_PRINTER    3  // printer ��ӡ��
#define  SDK_ICON_ICCARD     4  // smart card IC��
#define  SDK_ICON_LOCK       5  // lock ��
#define  SDK_ICON_BATTERY    6  // Battery���ͼ��
#define  SDK_ICON_EXTPWR     7  // ���ͼ��
#define  SDK_ICON_UP         8  // up ����
#define  SDK_ICON_DOWN       9  // down ����
#define  SDK_ICON_WIFI       10  // WIFIͼ��

//////////////////////////////// Mode ////////////////////////////////
//��ͨͼ���ģʽMode��0:Ϩ��1:������
#define  SDK_CLOSE_ICON    0    // �ر�ͼ��[�������ͼ��]
#define  SDK_OPEN_ICON     1    // ��ʾͼ��[��Դ�ӡ����IC����������ء����ϡ�����]

//����SDK_ICON_PHONE�������绰ժ�����һ�ͼ�꣬Mode��ֵ�������£�
#define  SDK_ICON_OFFHOOK   1   // hook off ժ��
#define  SDK_ICON_ONHOOK    2   // hook on  �һ�

//����SDK_ICON_SIGNAL�������ź�ͼ�꣬Mode��ֵ����Ϊ��[1��6]��6����1��ʾ�ź��������źŸ�ȫ�ף���6��ʾ�ź���ǿ�����5��
#define  SDK_ICON_INITSIGNAL    1   //��ʼ�ź�ǿ�� [��ǿ�ź�ΪINITSIGNAL+5]
#define  SDK_ICON_SIGNAL1       2   //�ź�ͼ���һ��
#define  SDK_ICON_SIGNAL2       3   //�ź�ͼ��ڶ���
#define  SDK_ICON_SIGNAL3       4   //�ź�ͼ�������
#define  SDK_ICON_SIGNAL4       5   //�ź�ͼ����ĸ�
#define  SDK_ICON_SIGNAL5       6   //�ź�ͼ������ (�ź�����)

//����SDK_ICON_BATTERY���������ͼ�꣬��Mode��ֵ����Ϊ��[1��5]��5����1��ʾ��������������򣩣�5��ʾ�����ǿ�����4��
#define  SDK_ICON_INITBATTERY   1   //������ [�����ΪINITBATTERY+4]
#define  SDK_ICON_BAT1          2   //���ͼ���һ��
#define  SDK_ICON_BAT2          3   //���ͼ��ڶ���
#define  SDK_ICON_BAT3          4   //���ͼ�������
#define  SDK_ICON_BAT4          5   //���ͼ����ĸ� (��������)
//////////////////////////////// SetIconEnd ////////////////////////////////

//ͼ��ICON��ȶ���
#define  SDK_ICON_WIDTH     32

//LCD ��������ͼ��ո񲿷֣�ר��ͼ������
#define  SDK_LCD_ENABLE_TOP   1

//LCD ����������ͼ��ո񲿷�
#define  SDK_LCD_DISABLE_TOP   0

//LCD �Զ�ˢ��ͼ��
#define SDK_AUTO_BRUSH_BATTERY  0x01  //�Զ�ˢ�µ��ͼ��
#define SDK_AUTO_BRUSH_SIGNAL   0x02  //�Զ�ˢ���ź�ͼ��

//color, RGB
typedef enum
{
    COLOR_BLACK = 0x00000000,     //��ɫ
    COLOR_BLUE = 0X000000FF,      //��ɫ
    COLOR_GREEN = 0X0000FF00,     //��ɫ
    COLOR_RED = 0X00FF0000,       //��ɫ
    COLOR_WHITE = 0X00FFFFFF,     //��ɫ
}E_SDK_LCD_COLOR;

s32 sdkLcdOpen(void);
s32 sdkLcdClose(void);

s32 sdkLcdSetFont(s8 *pszFontName, s8 *pszFontCharacter, u32 uiSize);
s32 sdkLcdGetFont(s8 *pszFontName, s8 *pszFontCharacter, u32 *puiSize);
s32 sdkLcdFillRow(u32 uiRow, u32 uiCol, const u8 *pszStr, u8 ucAtr);
s32 sdkLcdRowAt(u32 uiRow, u32 uiCol, const u8 *pszStr, u8 ucAtr);
s32 sdkLcdPixel(u32 uiX, u32 uiY, u32 uiColor);
s32 sdkLcdLine(u32 uiStartX, u32 uiEndX, u32 uiStartY, u32 uiEndY, u32 uiColor);
s32 sdkLcdDrawFrame(u32 uiStartX, u32 uiStartY, u32 uiWidth, u32 uiHeight, u32 uiColor);
s32 sdkLcdClearRow(u8 ucRow);
s32 sdkLcdClearRows(u8 ucStartRow, u8 ucEndRow);
s32 sdkLcdClearLine(u8 ucRow, u32 uiStartCol, u32 uiEndCol);
s32 sdkLcdClear(void);
s32 sdkLcdBrushScreen(void);

s32 sdkLcdDispBmp(u32 uiX, u32 uiY, u8 *pBitmap);
s32 sdkLcdDispBmpFile(u32 uiX, u32 uiY, u8 *pFileName);
s32 sdkLcdDispBitmap(u32 uiX, u32 uiY, u8* pcLogoBitmap, u32 uiLogoWidth, u32 uiLogoHeight);
s32 sdkLcdProcessBar(u32 uiStartX, u32 uiStartY, u32 uiWidth, u32 uiHeight, u32 uiCurrentX);
s32 sdkLcdCaptureScreen(void);
s32 sdkLcdRestoreScreen(void);
s32 sdkLcdSaveScreenBMP(s8 *pcFileName);

s32 sdkLcdGetPixel(u32 *pucWidth, u32 *pucHeigh);
s32 sdkLcdGetMaxRow(u8 *pucMaxRow, u8 *pucMaxCharNum);
void sdkLcdSetContrast(u8 ucContrast);
void sdkLcdLight(BOOL bMode);
void sdkLcdSetIcon(u8 ucIconNo, u32 uiMode);
s32 sdkLcdBrushIcon(u8 ucMode);

void sdkLcdSetLineGap(u8 ucDotValue);
void sdkLcdSetFontColor(u32 uiColor);
void sdkLcdSetBgColor(u32 uiColor);
s32 sdkLcdSetTopBlank(u8 ucStatus);
s32 sdkLcdGetScreenType(void);
s32 sdkLcdGetWidth(void);
s32 sdkLcdGetHeigh(void);
u8 sdkLcdGetContrast(void);

#ifdef __cplusplus
    }
#endif

#endif

