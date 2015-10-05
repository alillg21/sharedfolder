#ifndef _LCD_H_
#define _LCD_H_

#define GUI_WIN_HEIGHT 	8
#define GUI_WIN_WIDTH  	16
#define GUI_LINE0		0
#define GUI_LINE1		2
#define GUI_LINE2		4
#define GUI_LINE3		6


#define MSG_OK				0x01		//����ʾ"ȷ��",  ����1
#define MSG_OKCANCEL 		0x03		//��ʾ"ȷ��  ȡ��", ȷ�Ϸ���1, ȡ������0
#define MSG_ANYKEY			0x7			//��ʾ"�����������",      ����1
#define MSG_OKCANCEL_TIME	0x8			//��ʾ"xx����Զ�����",    ����1
#define MSG_ANYKEY_TIME		0x9			//��ʾ"xx����Զ�����",    ����1
#define MSG_TIME			0x10

#define ICON_PHONE1		0x01		//�绰ͼ��ĵ�һ��(����������,��ͬ)
#define ICON_PHONE2		0x02		//�绰ͼ��ĵڶ���
#define ICON_PHONE3     0x04		//�绰ͼ��ĵ�����

#define ICON_BAT		0x01		//���ͼ�����
#define ICON_BAT1		0x02		//���ͼ����������һ��
#define ICON_BAT2		0x04		//���ͼ���������ڶ���
#define ICON_BAT3		0x08		//���ͼ��������������
#define ICON_BAT4		0x10		//���ͼ�����������ĸ�

#define LCD_ALWAYS_ON	1
#define LCD_ALWAYS_OFF	0


//�� �� ��: lcd_disp
//��    ��: ��xaddr��, yaddr�е�λ����ʾ�ַ���
//ȫ�ֱ���: LCDHeight,LCDWidth
//�������: 
//			xaddr:��λ��,��16�����ص�Ϊ��λ(���ڴ�ֱ������16������Ϊ1��)��
//			yaddr:��λ��,��8�����ص�Ϊ��λ(����ˮƽ������8������Ϊ1��).
//			buf:Ҫ��ʾ���ַ���.
//�������: 
//�� �� ֵ: 
//��    ��: �ܽ���
//��������: 2009/8/24
//�� �� ��: 
//�޸�����: 
//��    ע: 
extern unsigned char lcd_disp(unsigned char xaddr, unsigned char yaddr, const char *buf);


//�� �� ��: con_disp
//��    ��: ��xaddr��, yaddr�е�λ�÷�����ʾ�ַ���
//ȫ�ֱ���: LCDHeight,LCDWidth
//�������: 
//			xaddr:��λ��,��16�����ص�Ϊ��λ(���ڴ�ֱ������16������Ϊ1��)��
//			yaddr:��λ��,��8�����ص�Ϊ��λ(����ˮƽ������8������Ϊ1��).
//			buf:Ҫ��ʾ���ַ���.
//�������: 
//�� �� ֵ: 
//��    ��: �ܽ���
//��������: 2009/8/24
//�� �� ��: 
//�޸�����: 
//��    ע: 
extern unsigned char con_disp(unsigned char xaddr, unsigned char yaddr, const char *buf);

//�� �� ��: draw_horizontal_line
//��    ��: ��y��x�п�ʼ����ʾwidth���ؿ�,1���ظߵĺ���
//ȫ�ֱ���: ��
//�������: 
//			x:������Ϊ��λ���е�λ��.
//			y:������Ϊ��λ���е�λ��.
//			width:������Ϊ��λ��ˮƽ�ߵĿ��.
//�������: ��
//�� �� ֵ: ��
//��    ��: �� ־ ��
//��������: 2009/8/25
//�� �� ��: 
//�޸�����: 
//��    ע: 
extern void draw_horizontal_line(int x, int y, int width);


//�� �� ��: draw_vertical_line
//��    ��: ��y��x�п�ʼ����ʾheight���ظߣ�1���ؿ������
//ȫ�ֱ���: ��
//�������: 
//			x:������Ϊ��λ���е�λ��.
//			y:������Ϊ��λ���е�λ��.
//			height:������Ϊ��λ�Ĵ�ֱ�ߵĸ߶�
//�������: ��
//�� �� ֵ: ��
//��    ��: �ܽ���
//��������: 2009/8/25
//�� �� ��: �� ־ ��
//�޸�����: 
//��    ע: 
extern void draw_vertical_line(int x, int y, int height);


//�� �� ��: con_draw_vertical_line
//��    ��: ��draw_vertical_line��ͬ���ǣ�draw_vertical_line�úڵ㻭��,�ú������ð׵㻭��.
//ȫ�ֱ���: ��
//			x:������Ϊ��λ���е�λ��.
//			y:������Ϊ��λ���е�λ��.
//			height:������Ϊ��λ�Ĵ�ֱ�ߵĸ߶�
//�������: ��
//�� �� ֵ: ��
//��    ��: �ܽ���
//��������: 2009/8/25
//�� �� ��: ��־��
//�޸�����: 
//��    ע: 
extern void con_draw_vertical_line(int x, int y, int height);


//�� �� ��: _disp_blank
//��    ��: ��x��,y�п�ʼ��һ������Ϊlen,�߶�Ϊ2�Ŀհ׾���
//ȫ�ֱ���: LCDWidth, LCDHeight
//�������: 
//			x:��λ��(8������Ϊһ��)
//			y:��λ��(8������Ϊһ��)
//			len:���ο��(��8������Ϊ��λ)			
//�������: 
//�� �� ֵ: 
//��    ��: �ܽ���
//��������: 2009/8/24
//�� �� ��: ��־��
//�޸�����: 
//��    ע: ���εĸ߶�Ϊ2x8������
extern void _disp_blank(unsigned char x, unsigned char y, unsigned char len);



//�� �� ��: disp_blank
//��    ��: ��x��,y�п�ʼ��һ������Ϊlen,�߶�Ϊ2�Ŀհ׾���
//ȫ�ֱ���: LCDWidth, LCDHeight
//�������: 
//			x:��λ��(�Դ�ֱ�����ϵ�16������Ϊһ��)
//			y:��λ��(��ˮƽ�����ϵ�8������Ϊһ��)
//			len:���ο��(��8������Ϊ��λ)			
//�������: 
//�� �� ֵ: 
//��    ��: �ܽ���
//��������: 2009/8/24
//�� �� ��: ��־��
//�޸�����: 
//��    ע: ���εĸ߶�Ϊ2x8������
extern void disp_blank(unsigned char x, unsigned char y, unsigned char len);



//�� �� ��: _con_disp
//��    ��: ��xaddr��, yaddr�е�λ�÷�����ʾ�ַ���
//ȫ�ֱ���: LCDHeight,LCDWidth
//�������: 
//			xaddr:��λ��,��8�����ص�Ϊ��λ,���ڴ�ֱ������8������Ϊһ�С�
//			yaddr:��λ��,��8�����ص�Ϊ��λ,����ˮƽ������8������Ϊһ��?//			buf:Ҫ��ʾ���ַ���.
//�������: 
//�� �� ֵ: 
//��    ��: �ܽ���
//��������: 2009/8/24
//�� �� ��: 
//�޸�����: 
//��    ע: 
extern unsigned char _con_disp(unsigned char xaddr, unsigned char yaddr, const char *buf);



//�� �� ��: _lcd_disp
//��    ��: ��xaddr��, yaddr�е�λ����ʾ�ַ���
//ȫ�ֱ���: LCDHeight,LCDWidth
//�������: 
//			xaddr:��λ��,��8�����ص�Ϊ��λ,���ڴ�ֱ������8������Ϊһ�С�
//			yaddr:��λ��,��8�����ص�Ϊ��λ,����ˮƽ������8������Ϊһ�С�
//			buf:Ҫ��ʾ���ַ���.
//�������: 
//�� �� ֵ: 
//��    ��: �ܽ���
//��������: 2009/8/24
//�� �� ��: 
//�޸�����: 
//��    ע: 
extern unsigned char _lcd_disp(unsigned char xaddr, unsigned char yaddr, const char *buf);



//�� �� ��: LCDFillRect
//��    ��: ��colorָ������ɫ���һ�����η���.����Ļ���Ͻ�Ϊ����ԭ��,ˮƽ����ΪX������,
//			��ֱ����ΪY�����򡣾������Ͻ�����Ϊ(x0*8, y0*8),���ο��Ϊw*8����, �߶�Ϊh*8����
//ȫ�ֱ���: ��
//�������: x0, y0, w, h, color
//�������: ��
//�� �� ֵ: ��
//��    ��: �ܽ���
//��������: 
//�� �� ��: zjwu
//�޸�����: 2009/8/21
//��    ע: 
extern void LCDFillRect(int x0, int y0, int w, int h, int color);



extern void LCDPutImage(int x0, int y0, int w, int h, const char *buf);

extern void LCDPutImageRev(int x0, int y0, int w, int h, const char *buf);


//�� �� ��: clear_rows
//��    ��: �����start_row�ַ���(����start_row��)��end_row�ַ���(������end_row��)ֹ��������
//ȫ�ֱ���: LCDHeight
//�������: 
//			start_row:��ʼ��
//			end_row:������
//�������: 
//�� �� ֵ: 
//��    ��: �� ־ ��
//��������: 2009/8/24
//�� �� ��: 
//�޸�����: 
//��    ע: ��ֱ������,8������Ϊһ��
extern void clear_rows(int start_row, int end_row);

//extern void fmt_ctrl_str(const char *str_in, unsigned char expect_len, unsigned char *ok_len, unsigned char fill_right_blank, char *str_out);




//�� �� ��: putpixel
//��    ��: ����Ļ���Ͻ�Ϊԭ�㣬ˮƽ����Ϊx��������,��ֱ����Ϊy�����������������ϵ�е�
//			��ʾ���ص�ĺ���.
//ȫ�ֱ���: fbmem:lcd������ӳ���ַ. fb_w:������Ϊ��λ����Ļ���. fb_h:������Ϊ��λ����Ļ�߶�.
//�������: 
//			x:X������. 
//			y:Y������.
//			c:0-��ʾ�׵㡣1-��ʾ�ڵ㡣
//�������: ��
//�� �� ֵ: ��
//��    ��: �ܽ���
//��������: 
//�� �� ��: �� ־ ��
//�޸�����: 2009/8/21
//��    ע: ע�Ͳ�����zjw���
extern void putpixel(int x, int y, int c);



//�� �� ��: lcd_refresh
//��    ��: ��Ļˢ��
//ȫ�ֱ���: g_fbfd,��ʾ�豸�ļ����  
//�������: ��
//�������: ��
//�� �� ֵ: ��
//��    ��: �� ־ ��
//��������: 2009/8/20
//�� �� ��: 
//�޸�����: 
//��    ע: ��ͬ��lcd_update����
extern void lcd_refresh(void);


//���������Ļ
extern void clear_lcd(void);



//�� �� ��: GetLcdHeight
//��    ��: �õ���Ļ�߶�
//ȫ�ֱ���: LCDWidth
//�������: ��
//�������: ��
//�� �� ֵ: ��
//��    ��: �� ־ ��
//��������: 2009/8/20
//�� �� ��: 
//�޸�����: 
//��    ע: ��������ָ��Ļ�������ظ���/8���ֵ
extern unsigned short GetLcdHeight(void);


//�� �� ��: GetLcdWidth
//��    ��: �õ���Ļ���
//ȫ�ֱ���: LCDWidth
//�������: ��
//�������: ��
//�� �� ֵ: ��
//��    ��: �� ־ ��
//��������: 2009/8/20
//�� �� ��: 
//�޸�����: 
//��    ע: ��������ָ��Ļ�������ظ���/8���ֵ
extern unsigned short GetLcdWidth(void);


//�� �� ��: lcd_back_light_on
//��    ��: �򿪱�����
//ȫ�ֱ���: g_fbfd,��ʾ�豸�ļ����  
//�������: ��
//�������: ��
//�� �� ֵ: ��
//��    ��: �� ־ ��
//��������: 2009/8/20
//�� �� ��: 
//�޸�����: 
//��    ע: 
extern void lcd_back_light_on(void);

//�� �� ��: lcd_back_light_off
//��    ��: �رձ�����
//ȫ�ֱ���: g_fbfd,��ʾ�豸�ļ����  
//�������: ��
//�������: ��
//�� �� ֵ: ��
//��    ��: �� ־ ��
//��������: 2009/8/20
//�� �� ��: 
//�޸�����: 
//��    ע: 
extern void lcd_back_light_off(void);


//�� �� ��: SetLcdBKLightStatus
//��    ��: ����lcd�����Ƶĵ�ǰ״̬Ϊ�����߹�
//ȫ�ֱ���: lcd_back_light_status
//�������: light_flag>0��ʾ��ǰ������Ϊ����=0Ϊ�ء�
//�������: ��
//�� �� ֵ: ��
//��    ��: �� ־ ��
//��������: 2009/8/20
//�� �� ��: 
//�޸�����: 
//��    ע: 
extern void SetLcdBKLightStatus(unsigned char light_flag);


//�� �� ��: GetlcdBkLightStatus
//��    ��: ȡ��ǰ�����Ƶ�״̬��
//ȫ�ֱ���: lcd_back_light_status
//�������: ��
//�������: ��
//�� �� ֵ: ���ص�ǰ�����Ƶ�״̬��>0��ʾ������=0��ʾ��Ϣ
//��    ��: �� ־ ��
//��������: 2009/8/20
//�� �� ��: 
//�޸�����: 
//��    ע: 
extern unsigned char GetlcdBkLightStatus(void);


//�� �� ��: DispIconSign
//��    ��: ��ʾͼ�������ź�ǿ��ͼ��
//ȫ�ֱ���: g_fbfd,��ʾ�豸�ļ���� 
//�������: sign_value:�ź�ǿ��ֵ,ȡֵ0~5��6��,0��ʾ�ź�����,5��ʾ�ź���ǿ		
//�������: 
//�� �� ֵ: 
//��    ��: �� ־ ��
//��������: 2009/8/20
//�� �� ��: 
//�޸�����: 
//��    ע: 
extern void DispIconSign( int sign_value );


//�� �� ��: DispIconUp
//��    ��: ��ʾͼ�������ϼ�ͷ
//ȫ�ֱ���: g_fbfd,��ʾ�豸�ļ����
//�������: switch_flag>0:	��ʾ��ͷ
//			switch_flag=0:	����ʾ��ͷ
//�������: ��
//�� �� ֵ: ��
//��    ��: �� ־ ��
//��������: 2009/8/20
//�� �� ��: 
//�޸�����: 
//��    ע: 
extern void DispIconUp(char switch_flag );


//�� �� ��: DispIconDown
//��    ��: ��ʾͼ�������¼�ͷ
//ȫ�ֱ���: g_fbfd,��ʾ�豸�ļ����
//�������: switch_flag>0:	��ʾ��ͷ
//			switch_flag=0:	����ʾ��ͷ
//�������: ��
//�� �� ֵ: ��
//��    ��: �� ־ ��
//��������: 2009/8/20
//�� �� ��: 
//�޸�����: 
//��    ע: 
extern void DispIconDown(char switch_flag );


//�� �� ��: DispIconBattary
//��    ��: ��ʾ���ͼ��
//ȫ�ֱ���: g_fbfd:��ʾ�豸�ļ����
//�������: BatID,��ȡֵ����:
//			ICON_BAT(0X01):	��ʾ���ͼ������
//			ICON_BAT1(0X02):��ʾ���ͼ��ĵ�һ��(����������)
//			ICON_BAT2(0X04):��ʾ���ͼ��ĵڶ���(����������)
//			ICON_BAT3(0X08):��ʾ���ͼ��ĵ�����(����������)
//			ICON_BAT4(0X10):��ʾ���ͼ��ĵ��ĸ�(����������)
//			0:				����ʾ���ͼ��
//�������: ��
//�� �� ֵ: ��
//��    ��: �� ־ ��
//��������: 2009/8/20
//�� �� ��: 
//�޸�����: 
//��    ע: 
extern void DispIconBattary( unsigned char BatID );


//�� �� ��: DispIconPrinter
//��    ��: ��ʾͼ�����Ĵ�ӡ��
//ȫ�ֱ���: g_fbfd,��ʾ�豸�ļ����
//�������: switch_flag>0:	��ʾ
//			switch_flag=0:	����
//�������: ��
//�� �� ֵ: ��
//��    ��: �� ־ ��
//��������: 2009/8/20
//�� �� ��: 
//�޸�����: 
//��    ע: 
extern void DispIconPrinter( char switch_flag );


//�� �� ��: get_fb_handle
//��    ��: ȡ��ʾ�豸�ļ����
//ȫ�ֱ���: g_fbfd
//�������: ��
//�������: ��
//�� �� ֵ: ��ʾ�豸�ļ����
//��    ��: �� ־ ��
//��������: 2009/8/20
//�� �� ��: 
//�޸�����: 
//��    ע: 
int get_fb_handle(void);



//�� �� ��: get_fb_mem
//��    ��: ȡLCD�����ӳ���ַ
//ȫ�ֱ���: fbmem
//�������: ��
//�������: ��
//�� �� ֵ: unsgined char�͵�ָ��
//��    ��: �� ־ ��
//��������: 2009/8/20
//�� �� ��: 
//�޸�����: 
//��    ע: 
unsigned char *get_fb_mem(void);


//�� �� ��:	show_bm
//��    ��:	��ʾλͼ
//�������: 
//			start_x:	����ʼλ��(�����ص�Ϊ��λ)
//			start_y:	����ʼΪֹ(�����ص�Ϊ��λ)
//			bmbuf:		����λͼ���������(������,���ϵ���)
//			bmbuf_size:	�����С
//			bm_width:	λͼ���(������Ϊ��λ)
extern void show_bm(int start_x, int start_y, unsigned char *bmbuf, int bmbuf_size, int bm_width );


//�� �� ��: _message_box
//��    ��: ��ʾ�ַ���
//ȫ�ֱ���: LCDWidth, LCDHeight
//�������: msg:ָ��Ҫ��ʾ�ַ�����ָ��
//�������: ��
//�� �� ֵ: ����ǰ��س���,�򷵻�1,���򷵻�0
//��    ��: �ܽ���
//��������: 2009/8/24
//�� �� ��: ��־��
//�޸�����: 
//��    ע:
//			1.��ʾ�ַ���ǰ������Ļ�ȱ����.
//			2.Ҫ�˳������ʾ������밴ȷ�ϼ�����ȡ����.
//			3.Ҫ��ʾ���ַ������Լ�����Ŀ����ַ�:
//			���������ַ����ַ��������str_out��
//			�����ַ����£�\n, \t, \b, ����ֱ����£�
//			Ĭ�Ͽ�����루�󲹿ո�
//			\n:�س����У������Ǽ���������ʽ
//			\t: �����������ڴ�ת���������п��ƣ���ʾ�����ַ�����out_len���У�ǰ�󲹿ո�
//      	��ǰ���������ֱ���ǿ����ַ���������ԣ�
//			\b: �������˸��ڴ�ת���������Ҷ��룬��ʾ�����ַ�����out_len���ң�ǰ���ո�
//      	��ǰ���������ֱ���ǿ����ַ���������ԣ�
//			��Ӳ�������ʾ���Ƿ񲹿ո�
//			������\n\t��ʾ�Ȼ�һ�У�Ȼ��\t����ַ�������
//			�����ַ����ַ�����λ�ù�ϵ�������ַ���ǰ���ַ����ں�
//			\n�ɵ���ʹ��\t��\b���ܵ���ʹ�ã��������ַ��������򽫱�����
extern unsigned char _message_box(char *msg);


//�μ�_message_box����,������������:
//�������disp_timeָ����ϢҪ��ʾ��ʱ��(����Ϊ��λ),��ʾʱ��ﵽ���ֵ���Զ����
//�˳���ʾ����,�Һ����ķ���ֵ��0.
extern unsigned char _message_box_in_time(char *msg, long disp_time);

//�� �� ��: MessageBox
//��    ��: ��ʾ��Ϣ(ÿ�������ʾMAX_MSG_LENGTH���ַ�,�������ʾMAX_MSG_LINES��)
//ȫ�ֱ���: ��
//�������: 
//			msg:ָ��Ҫ��ʾ���ַ�����ָ��(Ҳ���Դ������ַ�,����ͬ_message_box����).
//			msg_type:��Ϣ����,��ȡֵ����:
//			1.MSG_OKCANCEL:���disp_time=0,����밴�س�������ȡ���������˳���ʾ����,�س�������1,ȡ��������0.
//			2.MSG_ANYKEY�������������0.
//			3.MSG_ANYKEY_TIME:�����������0,���������,��disp_timeָ����ʱ�����������0(ǰ����disp_time>0).
//			4.MSG_OKCANCEL_TIME:���س�������1,ȡ��������0, ���ߵ�disp_timeָ����ʱ��󷵻�0(ǰ����disp_time>0).
//			5.MSG_TIME:����Ϣ��ʾʱ��ﵽdisp_timeָ����ʱ��󷵻�0.
//			disp_time:��Ϣ��ʾ��ʱ��.disp_time=0��ʾ���޳�.
//�������: ��
//�� �� ֵ: 1����0
//��    ��: �� ־ ��
//��������: 2009/8/24
//�� �� ��: 
//�޸�����: 
//��    ע: 
extern char MessageBox(const char *msg, unsigned char msg_type, unsigned char disp_time );

#endif


