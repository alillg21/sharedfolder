/*-----------------+----------------------+------------------------
                   |    编码转换相关      |
-------------------+----------------------+-----------------------*/
#ifndef _UNICODE_TO_GBK_H_
#define _UNICODE_TO_GBK_H_

extern unsigned short g_unicode_to_gbk_buf[];

extern unsigned short g_gbk_to_unicode_buf[];

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

    /*-----------------+-------------------------+------------------------
                       |    endian = 1 大端      |
                       |    endian = 0 小端      |
    -------------------+-------------------------+-----------------------*/
    int gbk_to_unicode(unsigned char *gbk_buf, unsigned short *unicode_buf, int max_unicode_buf_size, int endian);
    int unicode_to_gbk(unsigned short *unicode_buf, unsigned char *gbk_buf, int max_gbk_buf_size, int endian);
    int unicode_to_utf8(unsigned short *unicode_buf, unsigned char *utf8_buf, int max_utf8_buf_size, int endian);
    int utf8_to_unicode(unsigned char *utf8_buf, unsigned short *unicode_buf, int max_unicode_buf_size, int endian);

//int dprintf(char *format, ... );
//int dprintf(wchar_t *pwcStr, int nLen);

#ifdef __cplusplus
}
#endif

#endif
