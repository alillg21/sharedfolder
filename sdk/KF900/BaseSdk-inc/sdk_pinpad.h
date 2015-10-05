/*!@file
********************************************************************************
Module: Common
file name: sdk_pinpad.h

function: system file
Author: CRD by Qiling Liu
version: 1.0.0
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
modify :
date              version          by           fixed
2010/02/23    1.0.0             Liu           create
*******************************************************************************/
#ifndef _sdk_PINPAD_H_
#define _sdk_PINPAD_H_

#ifdef __cplusplus
extern "C" {
#endif

//�����������:
// 1.������̿��Դ��36��master key, 36��Pin key, 36��Mac key, 14��work key.ÿ����Կ���Դ�ŵ�����ֽ���Ϊ24
//  ÿ����Կ�ĳ���ֻ����8byte����16byte����24byte,��������������.���������ú�����Կ,KeyIdֵ����0��ʼ����,��master key,
//  pin key,mac key��id�ķ�ΧΪ0~35, work key��id����0~13,�����к�����,���id�ų���������Χ������.
// 2.ʹ���������ǰҪ��sdk_PinpadInit,Ȼ�����sdk_PinpadUnlock����������̲�������ʹ��,Ϊ�˰�ȫ���,�ڲ�ʹ��pinpad�ڼ�,
//  �������sdk_PinpadLock����pinpad.


//�� �� ��: sdk_PinpadInit
//��     ��: ��ʼ��Pinpad
//�������: ��
//�������: ��
//�� �� ֵ: �ɹ�����0,ʧ�ܷ���-1
    int sdk_PinpadInit(void);

//�� �� ��: sdk_PinpadLock
//��    ��: ����Pinpad
//�������: ��
//�������: ��
//�� �� ֵ: �ɹ�����0,ʧ�ܷ���-1
    int sdk_PinpadLock(void);

//�� �� ��: sdk_PinpadUnlock
//��    ��: ����Pinpad
//�������: ��
//�������: ��
//�� �� ֵ: �ɹ�����0,ʧ�ܷ���-1
    int sdk_PinpadUnlock(void);

//nTipX:��ʾ����ʾ���к�
//nTipY:��ʾ����ʾ���к�
//mode:0x80,��ʾPIN�����ʽ,1Ϊ������.0Ϊ����
//0x78,��ʾPIN�������
//0x07��ʾ��ʾ����ʾ��ʽ.0-"�����������";1-"ENTERN PIN";2-"�����������ENTER PIN";
// 3-"����������";4-"�������ѻ�����"
    void sdk_PinpadInputTip( unsigned char nTipX, unsigned char nTipY, unsigned char nMode );

//�� �� ��: sdk_PinpadSaveMasterKey
//��    ��: ������Կ
//�������:
//                      nKeyId          : ����Կ���(0<=nKeyId<MAX_MASTER_KEY_NUM)
//                      nKeyLen         : ����Կ����(8λ,16λ����24λ)
//                      pKeyData        : ����Կ����
//                      nMode           : 0-ֱ��д��, 1-��ԭλ�õ�����Կ����д��
//�������: ��
//�� �� ֵ:
//                      0  :�ɹ�
//                      -1 :��Կ�����Ƿ�
//                      -2 :��Կ���ȷǷ�
//                      -3 :���������������
//                      -4 :����ģʽ�Ƿ�
    int sdk_PinpadSaveMasterKey( unsigned char nKeyId,unsigned char nKeyLen,
                                 unsigned char *pKeyData,unsigned char nMode);

//�� �� ��: sdk_PinpadSavePinKey
//��    ��: ��pin��Կ
//�������:
//                      nKeyId          : pin��Կ���
//                      nKeyLen         : pin��Կ����
//                      pKeyData        : pin��Կ����
//                      nMasterKeyId    : ����Կ����
//                      nMode           : 0-ֱ��д��, 1-����mkey_idָ��������Կ���ܺ�д��, 2-���ܺ�д��
//�������: ��
//�� �� ֵ:
//                      0  :�ɹ�
//                      -1 :��Կ�����Ƿ�
//                      -2 :��Կ���ȷǷ�
//                      -3 :���������������
//                      -4 :����ģʽ�Ƿ�
//                      -5 :����Կ���ȴ�
    int sdk_PinpadSavePinKey( unsigned char nKeyId,unsigned char nKeyLen,unsigned char *pKeyData,
                              unsigned char nMasterKeyId,unsigned char nMode);

//�� �� ��: sdk_PinpadSaveMacKey
//��    ��: ��mac��Կ
//�������:
//                      nKeyId          : mac��Կ���
//                      nKeyLen         : mac��Կ����
//                      pKeyData        : mac��Կ����
//                      nMasterKeyId    : ����Կ����
//                      nMode           : 0-ֱ��д��, 1-����mkey_idָ��������Կ���ܺ�д��, 2-���ܺ�д��
//�������: ��
//�� �� ֵ:
//                      0  :�ɹ�
//                      -1 :��Կ�����Ƿ�
//                      -2 :��Կ���ȷǷ�
//                      -3 :���������������
//                      -4 :����ģʽ�Ƿ�
//                      -5 :����Կ���ȴ�
    int sdk_PinpadSaveMacKey(unsigned char nKeyId,unsigned char nKeyLen,
                             unsigned char *pKeyData,unsigned char nMasterKeyId,unsigned char nMode);

//�� �� ��: sdk_PinpadSaveWorkKey
//��    ��: ��work��Կ
//�������:
//                      nKeyId          : work��Կ���
//                      nKeyLen         : work��Կ����
//                      pKeyData        : work��Կ����
//                      nMasterKeyId    : ����Կ����
//                      nMode           : 0-ֱ��д��, 1-����mkey_idָ��������Կ���ܺ�д��, 2-���ܺ�д��
//�������: ��
//�� �� ֵ:
//                      0  :�ɹ�
//                      -1 :��Կ�����Ƿ�
//                      -2 :��Կ���ȷǷ�
//                      -3 :���������������
//                      -4 :����ģʽ�Ƿ�
//                      -5 :����Կ���ȴ�
    int sdk_PinpadSaveWorkKey( unsigned char nKeyId,unsigned char nKeyLen,unsigned char *pKeyData,
                               unsigned char nMasterKeyId,unsigned char nMode);

//�� �� ��: sdk_PinpadDerivePinKey
//��    ��: ��ɢpin key
//�������:
//                      nMasterKeyId    : ��ɢpin keyʱ�����ӽ��ܵ�����Կ���
//                      nSourcePinKeyId : Դpin key���
//                      nDestPinKeyId   : Ŀ��pin key���
//                      nMode           : 0x01-��������Կ���м���, 0x02-��������Կ���н���
//�������: ��
//�� �� ֵ:
//                      0  :�ɹ�
//                      -1 :��Կ�����Ƿ�
//                      -2 :��Կ���ȷǷ�
//                      -3 :���������������
//                      -4 :����ģʽ�Ƿ�
//                      -5 :����Կ���ȴ�
    int sdk_PinpadDerivePinKey(unsigned char nMasterKeyId,unsigned char nSourcePinKeyId,
                               unsigned char nDestPinKeyId,unsigned char nMode);

//�� �� ��: sdk_PinpadDeriveMacKey
//��    ��: ��ɢmac key
//�������:
//                      nMasterKeyId    : ��ɢmac keyʱ�����ӽ��ܵ�����Կ���
//                      nSourceMacKeyId : Դmac key���
//                      nDestMacKeyId   : Ŀ��mac key���
//                      nMode           : 0x01-��������Կ���м���, 0x02-��������Կ���н���
//�������: ��
//�� �� ֵ:
//                      0  :�ɹ�
//                      -1 :��Կ�����Ƿ�
//                      -2 :��Կ���ȷǷ�
//                      -3 :���������������
//                      -4 :����ģʽ�Ƿ�
//                      -5 :����Կ���ȴ�
    int sdk_PinpadDeriveMacKey(unsigned char nMasterKeyId,unsigned char nSourceMacKeyId,
                               unsigned char nDestMacKeyId,unsigned char nMode);

//�� �� ��: sdk_PinpadDeriveWorkKey
//��    ��: ��ɢwork key
//�������:
//                      nMasterKeyId      : ��ɢwork keyʱ�����ӽ��ܵ�����Կ���
//                      nSourceWorkKeyId  : Դwork key���
//                      nDestWorkKeyId    : Ŀ��work key���
//                      nMode             : 0x01-��������Կ���м���, 0x02-��������Կ���н���
//�������: ��
//�� �� ֵ:
//                      0  :�ɹ�
//                      -1 :��Կ�����Ƿ�
//                      -2 :��Կ���ȷǷ�
//                      -3 :���������������
//                      -4 :����ģʽ�Ƿ�
//                      -5 :����Կ���ȴ�
    int sdk_PinpadDeriveWorkKey( unsigned char nMasterKeyId,unsigned char nSourceWorkKeyId,
                                 unsigned char nDestWorkKeyId,unsigned char nMode);

//�� �� ��: sdk_PinpadGetInputPin
//��    ��: ��ȡ�û��������������
//�������:
//                      nKeyId                  : ָ������PIN��ר����Կ��Ż�WK������Կ��, ������λB8��1�������WK������Կ,������λB8��0�������PINר����Կ
//                      nMinLen                 : ָʾ������������С����
//                      nMaxLen                 : ָʾ������������󳤶�
//                      szCardNo                : ����(������"\0"��β)
//               char *pcMoney:    ���ѵĽ��������������Ҫʹ��
//                      nMode                   : ����ģʽ nMode=0: X9.8 , nMode=1: X3.92
//                      nTimeout                : �ȴ��û����������ʱ�䣬��λ���룩,������ʱ�佫��ʱ
//�������:             pPinBlock               : ���ؼ��ܺ��PIN Block
//�� �� ֵ:             0       :�ɹ�
//                      -1      :��Կ�����Ƿ�
//                      -3      :���������������
//                      0x10   :�û�ȡ����������
//                      0x11   :�ȴ��������볬ʱ
//                      0x12   :�û���ȷ�ϼ��Թ���������
//ע        ��:                szCardNo���㷨Ϊ:��card no�ĵ����ڶ�λ��ʼ�����ȡ12λ,Ȼ���ڽ�ȡ��12λ����ǰ����4��0,��Ϊ����pinpad��16λ����,szCardNo����������"\0"��β
    int sdk_PinpadGetInputPin( unsigned char nKeyId,unsigned char nMinLen,unsigned char nMaxLen,char *szCardNo,char *pcMoney,
                               unsigned char nMode,unsigned short nTimeout,unsigned char *pPinBlock);

//�� �� ��: sdk_PinpadGetMac
//��    ��: ����mac key��������
//�������:
//                      nKeyId           : ָ��MAC��Կ��Ż�WK������Կ��ţ�
//                                        ������λB8��1�������WK������Կ
//                                        ������λB8��0�������MACר����Կ
//                      *pMacData       : ��Ҫ���ܵ�MAC������������
//                      nMacDataLen     : MAC�������ݳ���
//                      *pResult        : ����MAC���ļ��ܽ����8�ֽڣ�
//                      nMode           : д��ģʽ
//                                              01H��            MAC�㷨1
//                                              02H��            MAC�㷨2
//                                              03H:    MAC�㷨3(�й������㷨)
//�� �� ֵ��
//                      0  :�ɹ�
//                      -1 :��Կ�����Ƿ�
//                      -3 :���������������
//                      -4 :����ģʽ�Ƿ�
    int sdk_PinpadGetMac(  unsigned char nKeyId,unsigned char *pMacData,unsigned int  nMacDataLen,unsigned char *pResult,unsigned char nMode );

//�� �� ��: sdk_PinpadEncryptData
//��    ��: des���ܼ�����
//�������:
//                      nKeyId     : B8=1, ��work key, B8=0, ��mac key
//                      pInput     : Ҫ���ܻ��߽��ܵ����ݣ�8�ֽڣ�
//                      pOutput    : ���������8�ֽڣ�
//                      nMode      : 0x01-����, 0x2-����
//�������: ��
//�� �� ֵ��
//                      0  :�ɹ�
//                      -1 :��Կ�����Ƿ�
//                      -3 :���������������
//                      -4 :����ģʽ�Ƿ�
    int sdk_PinpadEncryptData( int nKeyId,unsigned char *pInput,unsigned char *pOutput,unsigned char nMode );

//�� �� ��: sdk_PinpadEncryptData_Ext
//��    ��: des���ܼ��������� ���ݳ���Ϊ8�ı���
//�������:
//                      nKeyId     : B8=1, ��work key, B8=0, ��mac key
//                      pInput     : Ҫ���ܻ��߽��ܵ�����
//                      len: Ҫ�������ݵĳ���
//                      pOutput    : �����
//                      nMode      : 0x01-����, 0x2-����
//�������: ��
//�� �� ֵ��
//                      0  :�ɹ�
//                      -1 :��Կ�����Ƿ�
//               -2 :��������
//                      -3 :���������������
//                      -4 :����ģʽ�Ƿ�
    int sdk_PinpadEncryptData_Ext( int nKeyId,unsigned char *pInput,int len,unsigned char *pOutput,unsigned char nMode);

//�������:VerBuf:�����汾��(16�ֽ�)
    void sdk_GetPPVer(char *VerBuf);

//�ж��Ƿ��������������
//0-���ǣ�1-��
    int sdk_IsOutLayPinpad();

//��ʾ��
    int sdk_PPDispBalance(unsigned char x,unsigned char y, unsigned char* balance,unsigned char lenth);

//��ʾ��
    int sdk_PPDispAmount(unsigned char x,unsigned char y, unsigned char* amount,unsigned char lenth);

    int sdk_PPDispIDLE();

    int sdk_PPGetCpuSn(char *CpuSnBuf);

//����������������̻��������������
//0-����,1 -����
    void sdk_SetPinpadMode(int mode);

//��������������̵Ĵ���������ʾͼ�ꡣ
//disp_buf����488���ֽڵĵ�����Ϣ
    int sdk_PPLoadLog(unsigned char *disp_buf);

//���û��ҷ���
//CurrencyCode:3���ֽڵ��ַ�(��ASII��)
    int sdk_PPSetCurrencyCode(unsigned char *CurrencyCode);

#ifdef __cplusplus
}
#endif

#endif

