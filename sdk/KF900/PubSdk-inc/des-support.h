/***********************************************************************************************************
 *
 * @FILENAME		: des-support.h
 *
 * @AUTHOR  		: zjwu
 *
 * @DATE	  		: 2009-9-1
 *
 * @DESCRIPTION		: 
 *
 * @COPYRIGHT		: 2009-2012 ShenZhen KAIFA Technology Co.,Ltd.
 *
 ***********************************************************************************************************/
#ifndef _DES_SUPPORT_H_
#define _DES_SUPPORT_H_

#define DECRYPT_MODE	0		//����ģʽ
#define ENCRYPT_MODE	1		//����ģʽ


//�� �� ��: DES_Encrypt
//��    ��:	���ݲ���type,��keybuf���ܻ��߽���indatabuf,�����ŵ�����outdatabuf��.
//ȫ�ֱ���: ��
//�������: 
//			indatabuf: unsigned char ���ַ���ָ��, ָ����Ҫ�����ܻ��߽��ܵ�����, ����Ϊ8byte
//			keybuf	 : unsigned char ���ַ���ָ��, ���ܻ��߽���ʱ�õ���key, ����Ϊ8���ֽ�.
//			mode	 : 0-����, 1-����
//�������: outdatabuf:unsigned char ���ַ���ָ��, ���ܻ��߽��ܵĽ��,����Ϊ8byte
//�� �� ֵ: ��
//��    ��: �� ־ ��
//��������: 2009/9/02
//�� �� ��: 
//�޸�����: 
//��    ע: 
void DES_Encrypt(unsigned char *indatabuf, unsigned char *keybuf, unsigned char *outdatabuf, char mode);

#endif





