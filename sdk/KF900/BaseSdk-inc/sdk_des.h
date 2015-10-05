#ifndef SDK_DES_H_
#define SDK_DES_H_

//函 数 名: void sdk_Des(   unsigned char *pInData, unsigned char *pKeyData,
//                              unsigned char *pOutData, unsigned char nMode )
//
//功    能: 加密或解密函数
//输入参数:
//              pInData         :需要加密的数据, 长度为8个字节
//              pKeyData        :用于加密的key, 长度为8个字节
//              nMode           :0-解密
//                              :1-加密
//输出参数: pOutData        :存放加密结果的buffer,长度为8个字节
//返 回 值: 无
void sdk_Des( unsigned char *pInData, unsigned char *pKeyData,
              unsigned char *pOutData, unsigned char nMode );

#endif /* SDK_DES_H_ */

