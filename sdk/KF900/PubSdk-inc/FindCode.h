/* ADD OKI START */
#ifndef FINDCODE_H
#define FINDCODE_H
/* ADD OKI END */


#define MAX_KEYTABLE            8

#define RESULT_OK                       0x01
#define RESULT_CANCEL           0x02
#define RESULT_END                      0x03
#define RESULT_CONTINUE         0x04

#define BLACK                           0
#define RED                                     1
#define BLUE                            2

#define NORMAL_DISP                     0
#define REVERSE_DISP            0x80

#define BX_INPUT                        1
#define PY_INPUT                        2

#define CHK_PY_FLAG                     0x80

#define TRUE                            1
#define FALSE                           0
#define INDEX_OFFSET            2

#define FETCH_HZNUM                     5       /* 定义每次提取汉字的数目 */

#define NEXT_PAGE                       0
#define PREV_PAGE                       1

#define INDEX_REC_SIZE          7

typedef struct {
        unsigned char sKey[2];
        unsigned char sRecNum[2];
        unsigned char sAddr[3];
} __attribute__((packed)) T_INDEX_REC;

// Define BX
#define BX_MAINKEY_LEN          4
#define MAX_BH_BUFFER           600     /* 笔形输入的最大缓冲,即最大可查到100个字 */

#define BX_INDEX_TOTAL          0x02EB
//#define BXCODETBL_OFFSET      0x0000

#define BX_MAX_REFER_VAL        5

#define BXCODE_REC_SIZE         4

typedef struct {
        unsigned char sTailCode[2];     /* 笔画输入后三位，转换成BCD */
        unsigned char sHz[2];
} __attribute__((packed)) T_BXCODE_REC;

typedef struct {
        unsigned long nCurPosi;
        unsigned short nRamainNum;
} __attribute__((packed)) T_BXTRACK_ITEM;

typedef struct {
        unsigned char sInpCode[7];      /* 输入的5码，其中不带'*' */
        unsigned short bNum;    /* 缓冲中汉字的数目 */
        unsigned short bPoint;  /* 缓冲sHzBuffer的当前位置 */
        unsigned char sHzBuffer[MAX_BH_BUFFER + 20];    /* 存放查询结果的缓冲 */
        unsigned char bItemTotal;       /* 大小码向下兼容的组合数 */
        T_BXTRACK_ITEM stTrackItem[8];
        union {
                struct {        /* no wildcard  */
                        unsigned short nTotal;  /* 符合条件的汉字总数 */
                        unsigned long nCurPosi; /* FLASH的当前位置 */
                        unsigned short nReadedNum;
                } __attribute__((packed)) tNo;
                struct {        /*  wildcard   */
                        unsigned char fFindEnd; /* 查询结束标志  */
                        unsigned char bWildNum; /* '*'的数目,刨头去尾至多4个 */
                        unsigned char sBitNo[5];        /* '*'所处的位置 */
                        unsigned char sCh[5];   /* 替代'*'所用的数字 */
                        unsigned long nCurPosi; /* FLASH的当前位置 */
                        unsigned short nRemainNum;      /* FLASH的当前位置剩下的汉字数 */
                        unsigned short nTotal;  /* 符合条件的汉字总数 */
                        unsigned short nReadedNum;
                } __attribute__((packed)) tYs;
        } un;
} __attribute__((packed)) T_FINDBXLOG;

// Define PY
#define DAN_PIN                         1
#define SHUANG_PIN                      2

#define IS_SHENGMU                      1
#define IS_YUNMU                        2

#define USE_ZEYIN                       0x01
#define NOT_MISTINESS_PY        0x02

#define PY_MAINKEY_LEN          4
#define MAX_PY_BUFFER           2000    /* 拼音输入的最大缓冲,即最大可查到600个字 */

#define MAX_PY_NUM                      14

#define PY_INDEX_TOTAL          0x1E1   // 885
//#define PYCODETBL_OFFSET      0x25d00

#define PYCODE_REC_SIZE         3
#define PYBASE_INFO_SIZE        6

typedef struct {
        unsigned char sInpCode[1];      /* 笔形输入后两位，转换成BCD[右对齐] */
        unsigned char sHz[2];
} __attribute__((packed)) T_PYCODE_REC;

typedef struct {
        unsigned char sInpCode[8];      /* 输入的平音码，其中不带'*' */
        unsigned short bHzNum;  /* 缓冲中汉字的数目 */
        unsigned short bPoint;  /* 缓冲sHzBuffer的当前位置 */
        unsigned char sHzBuffer[MAX_PY_BUFFER + 4];     /* 存放查询结果的缓冲 */

        unsigned char bPYNum;   /* 拼音的组合数 */
        unsigned short nTotal[MAX_PY_NUM];      /* 符合条件的汉字总数 */
        unsigned long nCurPosi[MAX_PY_NUM];     /* FLASH的当前位置 */
} __attribute__((packed)) T_FINDPYLOG;

typedef struct {
        unsigned char sKey[3];  /* 基本编码 */
        unsigned char sPYTotal[1];      /* 拼音总数 */
        unsigned char sOffset[2];       /* 在补码信息中的偏移 */
} __attribute__((packed)) T_PYBASE_INFO;        /* 基本信息 */

typedef struct {
        unsigned char bPYTotal; /* 拼音组合的总数 */
        unsigned char fHintInput[MAX_PY_NUM];   /* 是否提示输入 */
        unsigned char ssPYCode[MAX_PY_NUM][5];
        unsigned char sPYBhBcd[MAX_PY_NUM];
        unsigned char ssPinYun[MAX_PY_NUM][10];
} __attribute__((packed)) T_PYINPUTCODE;

typedef struct {
        unsigned short snField[2];
} __attribute__((packed)) T_FIELD;

typedef struct {
        unsigned char sPYCode[1];
        unsigned char sIndexNo[1];
} __attribute__((packed)) T_CODEINDEXTBL;


// Define LX
#define LX_INDEX_TOTAL          3144
#define LX_INDEXTBL_LEN         LX_INDEX_TOTAL*5
//#define LXCODETBL_OFFSET      0x37c00

#define LX_INDEX_REC_SIZE               5

typedef struct {
        unsigned char sKey[2];
        unsigned char sRecNum[1];
        unsigned char sAddr[2];
} __attribute__((packed)) T_LX_INDEX_REC;

typedef struct {
        unsigned short bNum;    /* 缓冲中汉字的数目 */
        unsigned short bPoint;  /* 缓冲sHzBuffer的当前位置 */
        unsigned char sHzBuffer[256];   /* 存放查询结果的缓冲 */
        unsigned short nTotal;  /* 符合条件的汉字总数 */
        unsigned long nCurPosi; /* FLASH的当前位置 */
} __attribute__((packed)) T_FINDLXLOG;

/* ADD OKI START */
#endif                          /* FINDCODE_H */
/* ADD OKI END */
