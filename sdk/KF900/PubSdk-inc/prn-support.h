/***********************************************************************************************************
 *
 * @FILENAME		: prn-support.h
 *
 * @AUTHOR  		: zjwu
 *
 * @DATE	  		: 2009-9-2
 *
 * @DESCRIPTION		: ��ӡAPIͷ�ļ�
 *
 * @COPYRIGHT		: 2009-2012 ShenZhen KAIFA Technology Co.,Ltd.
 *
 .
 ***********************************************************************************************************/
#ifndef PRN_SUPPORT_H
#define PRN_SUPPORT_H


//	Font Mode
#define PRN_MODE_NORMAL   0	// normal height, normal width
#define PRN_MODE_DBWIDTH  1	// normal height, double width
#define PRN_MODE_DBHEIGHT 2	// double height, normal width
#define PRN_MODE_DBBOTH   3	// double height, double width


#define PRN_FONT12	0	//ʹ��12x12�����ӡ
#define PRN_FONT16	1	//ʹ��16x16�����ӡ
#define PRN_FONT24	2	//ʹ��24x24�����ӡ


#define DEFAULT_DARKNESS	7							//Ĭ�ϴ�ӡɫ��
#define DEFAULT_FONTTYPE	PRN_FONT12		//Ĭ�ϴ�ӡ����
#define DEFAULT_LINESPACE	4							//Ĭ���м��Ϊ4����

#define MAX_DARKNESS	15								//���ɫ��ֵ
#define MIN_DARKNESS	1									//��Сɫ��ֵ



#define PRN_FAILURE					-1
#define PRN_OUT_OF_PAPER 			-2
#define PRN_ABORT_TEMP   			-3


//�� �� ��: PRN_OpenDevice
//��    ��: �򿪴�ӡ���豸
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ: �ɹ�����0, ʧ�ܷ���-1
//��    ��: �� ־ ��
//��������: 2009/9/02
//�� �� ��: 
//�޸�����: 
//��    ע: 
int PRN_OpenDevice(void);

//�� �� ��: PRN_InitFont12
//��    ��: ��ʼ��12����Ĵ�ӡ�ֿ�.�ú�����12����Ĵ�ӡ�ֿ�ĵ�ַ������ӡ��.
//ȫ�ֱ���: ��
//�������: 
//			cn_addr:12����ĺ��ֿ�ĵ�ַ
//			en_addr:12�����ASC�ֿ�ĵ�ַ
//�������: ��
//�� �� ֵ: ��
//��    ��: �� ־ ��
//��������: 2009/9/02
//�� �� ��: 
//�޸�����: 
//��    ע: 
void PRN_InitFont12(void *cn_addr, void *en_addr );

//�� �� ��: PRN_InitFont16
//��    ��: ��ʼ��16����Ĵ�ӡ�ֿ�.�ú�����16����Ĵ�ӡ�ֿ�ĵ�ַ������ӡ��.
//ȫ�ֱ���: ��
//�������: 
//			cn_addr:16����ĺ��ֿ�ĵ�ַ
//			en_addr:16�����ASC�ֿ�ĵ�ַ
//�������: ��
//�� �� ֵ: ��
//��    ��: �� ־ ��
//��������: 2009/9/02
//�� �� ��: 
//�޸�����: 
//��    ע: 
void PRN_InitFont16(void *cn_addr, void *en_addr );

//�� �� ��: PRN_InitFont24
//��    ��: ��ʼ��24����Ĵ�ӡ�ֿ�.�ú�����24����Ĵ�ӡ�ֿ�ĵ�ַ������ӡ��.
//ȫ�ֱ���: ��
//�������: 
//			cn_addr:24����ĺ��ֿ�ĵ�ַ
//			en_addr:24�����ASC�ֿ�ĵ�ַ
//�������: ��
//�� �� ֵ: ��
//��    ��: �� ־ ��
//��������: 2009/9/02
//�� �� ��: 
//�޸�����: 
//��    ע: 
void PRN_InitFont24(void *cn_addr, void *en_addr );

//�� �� ��: PRN_DeviceInit
//��    ��: ��ʼ����ӡ�豸, �������3������
//			1.�򿪴�ӡ���豸
//			2.����Ĭ������ΪĬ��ֵDEFAULT_FONTTYPE
//			3.���ô�ӡɫ��ΪĬ��ֵDEFAULT_DARKNESS
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ: ʧ�ܾ�����-1, �ɹ�����0
//��    ��: �� ־ ��
//��������: 2009/9/02
//�� �� ��: 
//�޸�����: 
//��    ע: 
int PRN_DeviceInit( void );


//�� �� ��: PRN_CloseDevice
//��    ��: �رմ�ӡ���豸
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ: �ɹ�����0��ʧ�ܷ���-1
//��    ��: �� ־ ��
//��������: 2009/9/02
//�� �� ��: 
//�޸�����: 
//��    ע: 
int PRN_CloseDevice(void);


//�� �� ��: PRN_PaperForward
//��    ��: ��ǰ��dot_lineָ�����е�ֽ
//ȫ�ֱ���: ��
//�������: dot_line:��ֽ������
//�������: ��
//�� �� ֵ: �ɹ�����0, ʧ�ܷ���-1
//��    ��: �� ־ ��
//��������: 2009/9/02
//�� �� ��: 
//�޸�����: 
//��    ע: 
int PRN_PaperForward(unsigned short dot_lines);


//�� �� ��: PRN_PaperFallback
//��    ��: �����ֽ, ��ֽ����Ϊdot_line����
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ: �ɹ�����0,ʧ�ܷ���-1
//��    ��: �� ־ ��
//��������: 2009/9/02
//�� �� ��: 
//�޸�����: 
//��    ע: �ú�����������ӡ��������Ч
int PRN_PaperFallback(unsigned short dot_lines);



//�� �� ��: PRN_SetDarkness
//��    ��: ���ô�ӡɫ��
//ȫ�ֱ���: ��
//�������: index:ɫ��ֵ,��Χ��MIN_DARKNESS��MAX_DARKNESS
//�������: ��
//�� �� ֵ: �ɹ�����0,ʧ�ܷ���-1
//��    ��: �� ־ ��
//��������: 2009/9/02
//�� �� ��: 
//�޸�����: 
//��    ע: 
int PRN_SetDarkness( unsigned char  index );


//�� �� ��: PRN_SetFontMode
//��    ��: ���ô�ӡ����ģʽ
//ȫ�ֱ���: ��
//�������: mode:����ģʽ, ����������ֵ֮һ
//			PRN_MODE_NORMAL		:��׼��ӡ
//			PRN_MODE_DBWIDTH	:�����ӡ
//			PRN_MODE_DBHEIGHT	:���ߴ�ӡ
//			PRN_MODE_DBBOTH		:�����ߴ�ӡ	
//�������: ��
//�� �� ֵ: ��
//��    ��: �� ־ ��
//��������: 2009/9/02
//�� �� ��: 
//�޸�����: 
//��    ע: ���������, Ĭ����PRN_MODE_NORMALģʽ
void PRN_SetFontMode(int mode );


//�� �� ��: PRN_SetFontType
//��    ��: ���ô�ӡ�����С(Ŀǰ֧��:12x12, 16x16, 24x24)
//ȫ�ֱ���: ��
//�������: font_type:����������ֵ֮һ
//			PRN_FONT12
//			PRN_FONT16
//			PRN_FONT24
//�������: ��
//�� �� ֵ: ��
//��    ��: �� ־ ��
//��������: 2009/9/02
//�� �� ��: 
//�޸�����: 
//��    ע: 
void PRN_SetFontType( int font_type );



//�� �� ��: PRN_GetDeviceStatus
//��    ��: ��ѯ��ӡ����ǰ״̬
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ: 
//			PRN_OUT_OF_PAPER:	ȱֽ
//			PRN_ABORT_TEMP:		�¶ȹ���
//			0:					��ӡ������
//��    ��: �� ־ ��
//��������: 2009/9/02
//�� �� ��: 
//�޸�����: 
//��    ע: 
int PRN_GetDeviceStatus(void);


//�� �� ��: PRN_SetLineSpace
//��    ��: �����м��
//ȫ�ֱ���: ��
//�������: dot_lines:�����ַ�֮��ĵ�����
//�������: ��
//�� �� ֵ: ��
//��    ��: �� ־ ��
//��������: 2009/9/02
//�� �� ��: 
//�޸�����: 
//��    ע: 
void PRN_SetLineSpace(unsigned short dot_lines);


//�� �� ��: PRN_WriteData2Printer
//��    ��: ���øú�����������ӡ����ӡ�����е�����.
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ: 
//			PRN_FAILURE(-1)			:��ӡʧ��
//			PRN_OUT_OF_PAPER(-2)	:ȱֽ	
//			PRN_ABORT_TEMP(-3)		:�¶ȹ���
//			����ֵ:					:�ɹ���ӡ�����ݳ���	
//��    ��: �� ־ ��
//��������: 2009/9/02
//�� �� ��: 
//�޸�����: 
//��    ע: 
//			���ܴ�ӡ�Ƿ�ɹ�,��ӡ�����е����ݾ��ᱻ���.
int PRN_WriteData2Printer(void);




//�� �� ��: PRN_FillData 
//��    ��: ����ӡ�������������
//�������: 
//			Data	:ָ��Ҫ��ӡ�����ݵ�ָ��
//			DataLen	:���ݳ���
//�� �� ֵ:
//			PRN_FAILURE(-1)			:��ӡʧ��
//			PRN_OUT_OF_PAPER(-2)	:ȱֽ	
//			PRN_ABORT_TEMP(-3)		:�¶ȹ���
//			0						:�ɹ�
//˵    ��: �������������ִ�ӡ�����������Զ���ӡ		
int PRN_FillData( unsigned char *Data, unsigned short DataLen );





//�� �� ��: PRN_PrnBlankDotLines
//��    ��: ����ӡ���������հ׵���
//ȫ�ֱ���: ��
//�������: dot_lines:Ҫ��ӡ�ĵ�����
//�������: ��
//�� �� ֵ: 
//			PRN_FAILURE(-1)			:��ӡʧ��
//			PRN_OUT_OF_PAPER(-2)	:ȱֽ	
//			PRN_ABORT_TEMP(-3)		:�¶ȹ���
//			0						:�ɹ�
//��    ��: �� ־ ��
//��������: 2009/9/02
//�� �� ��: 
//�޸�����: 
//��    ע: 1.�������������ִ�ӡ�����������Զ���ӡ,֮�������������		
//			2.����ӡ���̳���,���ж������̲����ط�0ֵ
int PRN_PrnBlankDotLines( unsigned short dot_lines );



//�� �� ��: PRN_Print
//��    ��: ��strָ�����ַ��������ӡ������
//ȫ�ֱ���: ��
//�������: str:Ҫ��ӡ���ַ���
//�������: ��
//�� �� ֵ: 
//			PRN_FAILURE(-1)			:��ӡʧ��
//			PRN_OUT_OF_PAPER(-2)	:ȱֽ	
//			PRN_ABORT_TEMP(-3)		:�¶ȹ���
//			0						:�ɹ�
//��    ��: �� ־ ��
//��������: 2009/9/02
//�� �� ��: 
//�޸�����: 
//��    ע: 
int PRN_Print( unsigned char *str );






//�� �� ��: PRN_Image
//��    ��: ʵʱ��ӡλͼ(2λ��ɫ)
//ȫ�ֱ���: ��
//�������: 
//			image_data		:λͼ����
//			image_width		:λͼ���(������Ϊ��λ)
//			image_width		:λͼ�߶�(������Ϊ��λ)
//�������: ��
//�� �� ֵ: 
//			PRN_FAILURE(-1)			:��ӡʧ��
//			PRN_OUT_OF_PAPER(-2)	:ȱֽ	
//			PRN_ABORT_TEMP(-3)		:�¶ȹ���
//			-4						:�����ڴ�ʧ��
//			0						:�ɹ�
//��    ��: �� ־ ��
//��������: 2009/9/02
//�� �� ��: 
//�޸�����: 
//��    ע: 1.λͼ���������8�ı���
//			2.λͼ�����Ǻڰ���ɫ,λͼ���ݱ�����bitλ��ʾһ������.
int PRN_Image(unsigned char *image_data, unsigned short image_width, unsigned short image_height );


#endif				/* PRN_SUPPORT_H */
