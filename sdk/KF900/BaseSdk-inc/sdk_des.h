#ifndef SDK_DES_H_
#define SDK_DES_H_

//�� �� ��: void sdk_Des(   unsigned char *pInData, unsigned char *pKeyData,
//                              unsigned char *pOutData, unsigned char nMode )
//
//��    ��: ���ܻ���ܺ���
//�������:
//              pInData         :��Ҫ���ܵ�����, ����Ϊ8���ֽ�
//              pKeyData        :���ڼ��ܵ�key, ����Ϊ8���ֽ�
//              nMode           :0-����
//                              :1-����
//�������: pOutData        :��ż��ܽ����buffer,����Ϊ8���ֽ�
//�� �� ֵ: ��
void sdk_Des( unsigned char *pInData, unsigned char *pKeyData,
              unsigned char *pOutData, unsigned char nMode );

#endif /* SDK_DES_H_ */

