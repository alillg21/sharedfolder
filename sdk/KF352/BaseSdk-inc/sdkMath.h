/********************************************************************
�ļ��� : sdkMath.h
��  �� : ����CRC16,CRC32,LRC,DES,MAC,MD5,sha-1,sha-256,RSA
��  Ȩ : ���ǿ���
��  �� : ¬ԣ��
�޸ļ�¼:
    ����              �޸���  �޸�����
    2013-12-24 14:59  ¬ԣ��  ����
********************************************************************/
#ifndef BASE_SDKMATH_H_
#define BASE_SDKMATH_H_

#ifdef __cplusplus
    extern "C" {
#endif

typedef enum
{
   ENCRYPT, //0: DES����
   DECRYPT, //1: DES����
} E_SDK_ENCRYPT_TYPE;

typedef enum
{
   ENCODE, //0: Base64����
   DECODE, //1: Base64����
} E_SDK_BASE64_TYPE;

typedef enum
{
    MAC1=0x00,
    MAC2,
    MAC3,//e90 ������׼�㷨
    MAC4,//e99
}E_SDK_MAC_TYPE;

/* RSA public and private key. */
#define MIN_RSA_MODULUS_BITS    508
#define MAX_RSA_MODULUS_BITS    2048
#define MAX_RSA_MODULUS_LEN     ((MAX_RSA_MODULUS_BITS + 7) / 8)
#define MAX_RSA_PRIME_BITS      ((MAX_RSA_MODULUS_BITS + 1) / 2)
#define MAX_RSA_PRIME_LEN       ((MAX_RSA_PRIME_BITS + 7) / 8)

typedef struct
{
    u32 bits;               /* length in bits of modulus */
    u8  modulus[MAX_RSA_MODULUS_LEN];   /* modulus */
    //u8  exponent[4];           /* public exponent */
    u8  exponent[MAX_RSA_MODULUS_LEN];           /* public exponent */
    u16  usCRC;                /*CRC value*/
} T_SDK_RSA_PUBLIC_KEY;

typedef struct
{
    u32 bits;                    /* length in bits of modulus */
    u8  modulus[MAX_RSA_MODULUS_LEN];           /* modulus */
    u8  publicExponent[MAX_RSA_MODULUS_LEN];     /* public exponent */
    u8  exponent[MAX_RSA_MODULUS_LEN];  /* private exponent */
    u8  prime[2][MAX_RSA_PRIME_LEN];    /* prime factors */
    u8  primeExponent[2][MAX_RSA_PRIME_LEN];/*exponents for CRT*/
    u8  coefficient[MAX_RSA_PRIME_LEN];  /* CRT coefficient */
    u16 usCRC;                        /*CRC value*/
} T_SDK_RSA_PRIVATE_KEY;

u16 sdkMathCRC16(u8* phexIn, u32 uiInLen, u16 unPreCrcValue);
u32 sdkMathCRC32(u8* phexIn, u32 uiInLen, u32 unPreCrcValue);
u8 sdkMathLRC(u8* phexIn, u32 uiInLen);
s32 sdkMathDes(u8* phexDataIn, u8* phexDataOut, const u8* phexKey,
                                u8 ucKeyLen, E_SDK_ENCRYPT_TYPE eEncrypt);
s32 sdkMathMac(u8* phexData, u32 uiLen, u8  *pheDestData, const u8* phexKey,
                                u8 ucKeyLen, E_SDK_MAC_TYPE eType);
s32 sdkMathMD5(const u8 *phexSrc, u32 uiLen, u8 *phexDest);
s32 sdkMathSHA1(const u8* phexSrc, u32 uiLen, u8* phexDest);
s32 sdkMathSHA256(const u8* phexSrc, s32 uiLen, u8* phexDest);
s32 sdkMathRSAPubKeyEncrypt(u8* const phexOut, u32* uiOutLen, u8* phexIn,
                                    u32 uiInLen, T_SDK_RSA_PUBLIC_KEY * ptPubKey);
s32 sdkMathRSAPubKeyDecrypt(u8* const phexOut, u32* uiOutLen, u8* phexIn,
                                    u32 uiInLen, T_SDK_RSA_PUBLIC_KEY * ptPubKey);
s32 sdkMathRSAPrivateEncrypt(u8* const phexOut, u32* uiOutLen, u8* phexIn,
                                    u32 uiInLen, T_SDK_RSA_PRIVATE_KEY * ptPrivateKey);

s32 sdkMathRSAPrivateDecrypt(u8* const phexOut, u32* uiOutLen, u8* phexIn,
                                    u32 uiInLen, T_SDK_RSA_PRIVATE_KEY * ptPrivateKey);

s32 sdkMathBase64(u8 *phexOut, s32 *uiOutLen, const u8 *phexIn, s32 uiInLen, E_SDK_BASE64_TYPE ucMode);

#ifdef __cplusplus
    }
#endif

#endif

