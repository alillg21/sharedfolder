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

//关于密码键盘:
// 1.密码键盘可以存放36组master key, 36组Pin key, 36组Mac key, 14组work key.每组密钥可以存放的最大字节数为24
//  每组密钥的长度只能是8byte或者16byte或者24byte,不能是其它长度.无论是引用何种密钥,KeyId值均从0开始计数,即master key,
//  pin key,mac key的id的范围为0~35, work key的id号是0~13,在下列函数中,如果id号超出上述范围将报错.
// 2.使用密码键盘前要先sdk_PinpadInit,然后调用sdk_PinpadUnlock解锁密码键盘才能正常使用,为了安全起见,在不使用pinpad期间,
//  建议调用sdk_PinpadLock锁定pinpad.


//函 数 名: sdk_PinpadInit
//功     能: 初始化Pinpad
//输入参数: 无
//输出参数: 无
//返 回 值: 成功返回0,失败返回-1
    int sdk_PinpadInit(void);

//函 数 名: sdk_PinpadLock
//功    能: 锁定Pinpad
//输入参数: 无
//输出参数: 无
//返 回 值: 成功返回0,失败返回-1
    int sdk_PinpadLock(void);

//函 数 名: sdk_PinpadUnlock
//功    能: 解锁Pinpad
//输入参数: 无
//输出参数: 无
//返 回 值: 成功返回0,失败返回-1
    int sdk_PinpadUnlock(void);

//nTipX:提示语显示的行号
//nTipY:提示语显示的列号
//mode:0x80,表示PIN输出方式,1为不加密.0为加密
//0x78,表示PIN输入次数
//0x07表示提示语显示方式.0-"输入个人密码";1-"ENTERN PIN";2-"输入个人密码ENTER PIN";
// 3-"请输入密码";4-"请输入脱机密码"
    void sdk_PinpadInputTip( unsigned char nTipX, unsigned char nTipY, unsigned char nMode );

//函 数 名: sdk_PinpadSaveMasterKey
//功    能: 存主密钥
//输入参数:
//                      nKeyId          : 主密钥序号(0<=nKeyId<MAX_MASTER_KEY_NUM)
//                      nKeyLen         : 主密钥长度(8位,16位或者24位)
//                      pKeyData        : 主密钥数据
//                      nMode           : 0-直接写入, 1-与原位置的主密钥亦或后写入
//输出参数: 无
//返 回 值:
//                      0  :成功
//                      -1 :密钥索引非法
//                      -2 :密钥长度非法
//                      -3 :密码键盘锁定错误
//                      -4 :输入模式非法
    int sdk_PinpadSaveMasterKey( unsigned char nKeyId,unsigned char nKeyLen,
                                 unsigned char *pKeyData,unsigned char nMode);

//函 数 名: sdk_PinpadSavePinKey
//功    能: 存pin密钥
//输入参数:
//                      nKeyId          : pin密钥序号
//                      nKeyLen         : pin密钥长度
//                      pKeyData        : pin密钥数据
//                      nMasterKeyId    : 主密钥索引
//                      nMode           : 0-直接写入, 1-利用mkey_id指定的主密钥加密后写入, 2-解密后写入
//输出参数: 无
//返 回 值:
//                      0  :成功
//                      -1 :密钥索引非法
//                      -2 :密钥长度非法
//                      -3 :密码键盘锁定错误
//                      -4 :输入模式非法
//                      -5 :主密钥长度错
    int sdk_PinpadSavePinKey( unsigned char nKeyId,unsigned char nKeyLen,unsigned char *pKeyData,
                              unsigned char nMasterKeyId,unsigned char nMode);

//函 数 名: sdk_PinpadSaveMacKey
//功    能: 存mac密钥
//输入参数:
//                      nKeyId          : mac密钥序号
//                      nKeyLen         : mac密钥长度
//                      pKeyData        : mac密钥数据
//                      nMasterKeyId    : 主密钥索引
//                      nMode           : 0-直接写入, 1-利用mkey_id指定的主密钥加密后写入, 2-解密后写入
//输出参数: 无
//返 回 值:
//                      0  :成功
//                      -1 :密钥索引非法
//                      -2 :密钥长度非法
//                      -3 :密码键盘锁定错误
//                      -4 :输入模式非法
//                      -5 :主密钥长度错
    int sdk_PinpadSaveMacKey(unsigned char nKeyId,unsigned char nKeyLen,
                             unsigned char *pKeyData,unsigned char nMasterKeyId,unsigned char nMode);

//函 数 名: sdk_PinpadSaveWorkKey
//功    能: 存work密钥
//输入参数:
//                      nKeyId          : work密钥序号
//                      nKeyLen         : work密钥长度
//                      pKeyData        : work密钥数据
//                      nMasterKeyId    : 主密钥索引
//                      nMode           : 0-直接写入, 1-利用mkey_id指定的主密钥加密后写入, 2-解密后写入
//输出参数: 无
//返 回 值:
//                      0  :成功
//                      -1 :密钥索引非法
//                      -2 :密钥长度非法
//                      -3 :密码键盘锁定错误
//                      -4 :输入模式非法
//                      -5 :主密钥长度错
    int sdk_PinpadSaveWorkKey( unsigned char nKeyId,unsigned char nKeyLen,unsigned char *pKeyData,
                               unsigned char nMasterKeyId,unsigned char nMode);

//函 数 名: sdk_PinpadDerivePinKey
//功    能: 发散pin key
//输入参数:
//                      nMasterKeyId    : 发散pin key时用来加解密的主密钥序号
//                      nSourcePinKeyId : 源pin key序号
//                      nDestPinKeyId   : 目标pin key序号
//                      nMode           : 0x01-利用主密钥进行加密, 0x02-利用主密钥进行解密
//输出参数: 无
//返 回 值:
//                      0  :成功
//                      -1 :密钥索引非法
//                      -2 :密钥长度非法
//                      -3 :密码键盘锁定错误
//                      -4 :输入模式非法
//                      -5 :主密钥长度错
    int sdk_PinpadDerivePinKey(unsigned char nMasterKeyId,unsigned char nSourcePinKeyId,
                               unsigned char nDestPinKeyId,unsigned char nMode);

//函 数 名: sdk_PinpadDeriveMacKey
//功    能: 发散mac key
//输入参数:
//                      nMasterKeyId    : 发散mac key时用来加解密的主密钥序号
//                      nSourceMacKeyId : 源mac key序号
//                      nDestMacKeyId   : 目标mac key序号
//                      nMode           : 0x01-利用主密钥进行加密, 0x02-利用主密钥进行解密
//输出参数: 无
//返 回 值:
//                      0  :成功
//                      -1 :密钥索引非法
//                      -2 :密钥长度非法
//                      -3 :密码键盘锁定错误
//                      -4 :输入模式非法
//                      -5 :主密钥长度错
    int sdk_PinpadDeriveMacKey(unsigned char nMasterKeyId,unsigned char nSourceMacKeyId,
                               unsigned char nDestMacKeyId,unsigned char nMode);

//函 数 名: sdk_PinpadDeriveWorkKey
//功    能: 发散work key
//输入参数:
//                      nMasterKeyId      : 发散work key时用来加解密的主密钥序号
//                      nSourceWorkKeyId  : 源work key序号
//                      nDestWorkKeyId    : 目标work key序号
//                      nMode             : 0x01-利用主密钥进行加密, 0x02-利用主密钥进行解密
//输出参数: 无
//返 回 值:
//                      0  :成功
//                      -1 :密钥索引非法
//                      -2 :密钥长度非法
//                      -3 :密码键盘锁定错误
//                      -4 :输入模式非法
//                      -5 :主密钥长度错
    int sdk_PinpadDeriveWorkKey( unsigned char nMasterKeyId,unsigned char nSourceWorkKeyId,
                                 unsigned char nDestWorkKeyId,unsigned char nMode);

//函 数 名: sdk_PinpadGetInputPin
//功    能: 获取用户输入的密码密文
//输入参数:
//                      nKeyId                  : 指定加密PIN的专用密钥序号或WK工作密钥号, 如果最高位B8＝1，则采用WK工作密钥,如果最高位B8＝0，则采用PIN专用密钥
//                      nMinLen                 : 指示输入的密码的最小长度
//                      nMaxLen                 : 指示输入的密码的最大长度
//                      szCardNo                : 卡号(必须以"\0"结尾)
//               char *pcMoney:    消费的金额，外置密码键盘需要使用
//                      nMode                   : 加密模式 nMode=0: X9.8 , nMode=1: X3.92
//                      nTimeout                : 等待用户输入密码的时间，单位（秒）,超过该时间将超时
//输出参数:             pPinBlock               : 返回加密后的PIN Block
//返 回 值:             0       :成功
//                      -1      :密钥索引非法
//                      -3      :密码键盘锁定错误
//                      0x10   :用户取消输入密码
//                      0x11   :等待输入密码超时
//                      0x12   :用户按确认键略过输入密码
//注        意:                szCardNo的算法为:从card no的倒数第二位开始向左截取12位,然后在截取的12位卡号前补充4个0,作为发给pinpad的16位数据,szCardNo参数必须以"\0"结尾
    int sdk_PinpadGetInputPin( unsigned char nKeyId,unsigned char nMinLen,unsigned char nMaxLen,char *szCardNo,char *pcMoney,
                               unsigned char nMode,unsigned short nTimeout,unsigned char *pPinBlock);

//函 数 名: sdk_PinpadGetMac
//功    能: 利用mac key加密数据
//输入参数:
//                      nKeyId           : 指定MAC密钥序号或WK工作密钥序号：
//                                        如果最高位B8＝1，则采用WK工作密钥
//                                        如果最高位B8＝0，则采用MAC专用密钥
//                      *pMacData       : 需要加密的MAC报文数据内容
//                      nMacDataLen     : MAC报文数据长度
//                      *pResult        : 返回MAC报文加密结果（8字节）
//                      nMode           : 写入模式
//                                              01H：            MAC算法1
//                                              02H：            MAC算法2
//                                              03H:    MAC算法3(中国银联算法)
//返 回 值：
//                      0  :成功
//                      -1 :密钥索引非法
//                      -3 :密码键盘锁定错误
//                      -4 :输入模式非法
    int sdk_PinpadGetMac(  unsigned char nKeyId,unsigned char *pMacData,unsigned int  nMacDataLen,unsigned char *pResult,unsigned char nMode );

//函 数 名: sdk_PinpadEncryptData
//功    能: des加密及解密
//输入参数:
//                      nKeyId     : B8=1, 用work key, B8=0, 用mac key
//                      pInput     : 要加密或者解密的数据（8字节）
//                      pOutput    : 结果　　（8字节）
//                      nMode      : 0x01-加密, 0x2-解密
//输出参数: 无
//返 回 值：
//                      0  :成功
//                      -1 :密钥索引非法
//                      -3 :密码键盘锁定错误
//                      -4 :输入模式非法
    int sdk_PinpadEncryptData( int nKeyId,unsigned char *pInput,unsigned char *pOutput,unsigned char nMode );

//函 数 名: sdk_PinpadEncryptData_Ext
//功    能: des加密及解密数据 数据长度为8的倍数
//输入参数:
//                      nKeyId     : B8=1, 用work key, B8=0, 用mac key
//                      pInput     : 要加密或者解密的数据
//                      len: 要加密数据的长度
//                      pOutput    : 结果　
//                      nMode      : 0x01-加密, 0x2-解密
//输出参数: 无
//返 回 值：
//                      0  :成功
//                      -1 :密钥索引非法
//               -2 :参数错误
//                      -3 :密码键盘锁定错误
//                      -4 :输入模式非法
    int sdk_PinpadEncryptData_Ext( int nKeyId,unsigned char *pInput,int len,unsigned char *pOutput,unsigned char nMode);

//输入参数:VerBuf:储存库版本号(16字节)
    void sdk_GetPPVer(char *VerBuf);

//判断是否是外置密码键盘
//0-不是，1-是
    int sdk_IsOutLayPinpad();

//显示余额；
    int sdk_PPDispBalance(unsigned char x,unsigned char y, unsigned char* balance,unsigned char lenth);

//显示金额；
    int sdk_PPDispAmount(unsigned char x,unsigned char y, unsigned char* amount,unsigned char lenth);

    int sdk_PPDispIDLE();

    int sdk_PPGetCpuSn(char *CpuSnBuf);

//设置是内置密码键盘还是外置密码键盘
//0-内置,1 -外置
    void sdk_SetPinpadMode(int mode);

//设置外置密码键盘的待机界面显示图标。
//disp_buf传入488个字节的点阵信息
    int sdk_PPLoadLog(unsigned char *disp_buf);

//设置货币符号
//CurrencyCode:3个字节的字符(限ASII码)
    int sdk_PPSetCurrencyCode(unsigned char *CurrencyCode);

#ifdef __cplusplus
}
#endif

#endif

