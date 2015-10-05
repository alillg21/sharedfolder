#ifndef _SDK_QRBARCODE_H_
#define _SDK_QRBARCODE_H_

#ifdef __cplusplus
extern "C" {
#endif

/*!
* @brief To print QR lib version.
*
* @param version : the texts to output QR lib version
* @param len : the width of QR lib version
* No return value
*/
void GetQR_Version(char version[], int *len);

/*API_PrintQRCode
* @brief To print QR code bitmap with different texts.
*
* @param strInput : the texts to output QR code bitmap
*
* @return -1 ,encode error. or else the height pf the bmp.
*/
int API_PrintQRCode(const char * strInput, int bitmapx, int bitmapy,int centeralign);

/*!
* @brief To print QR code bitmap with different texts.
*
* @param strInput : the texts to output QR code bitmap
* @param bitmapx : the width of QR code output bitmap
* @param bitmapy : the height of QR code output bitmap
* @param multiple : the multiple to output QR code bitmap
* @return -1 ,encode error. or else the height pf the bmp.
* @return -2 ,multiple error.
*/
int sdk_GenerateQRCode(const char * strInput, unsigned char display[], int *bitmapx, int *bitmapy,int multiple);

/*sdk_PrintQRCode
* @brief To print QR code bitmap with different texts.
*
* @param strInput : the texts to output QR code bitmap
* @param multiple : the multiple to output QR code bitmap,it is value is 2 or 4 or 8
*
* @return -1 ,encode error. or else the height pf the bmp.
* @return -2 ,multiple error.
*/
int sdk_PrintQRCode(const char * strInput, int multiple);

#ifdef __cplusplus
}
#endif

#endif

