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

#define FETCH_HZNUM                     5       /* ����ÿ����ȡ���ֵ���Ŀ */

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
#define MAX_BH_BUFFER           600     /* �����������󻺳�,�����ɲ鵽100���� */

#define BX_INDEX_TOTAL          0x02EB
//#define BXCODETBL_OFFSET      0x0000

#define BX_MAX_REFER_VAL        5

#define BXCODE_REC_SIZE         4

typedef struct {
        unsigned char sTailCode[2];     /* �ʻ��������λ��ת����BCD */
        unsigned char sHz[2];
} __attribute__((packed)) T_BXCODE_REC;

typedef struct {
        unsigned long nCurPosi;
        unsigned short nRamainNum;
} __attribute__((packed)) T_BXTRACK_ITEM;

typedef struct {
        unsigned char sInpCode[7];      /* �����5�룬���в���'*' */
        unsigned short bNum;    /* �����к��ֵ���Ŀ */
        unsigned short bPoint;  /* ����sHzBuffer�ĵ�ǰλ�� */
        unsigned char sHzBuffer[MAX_BH_BUFFER + 20];    /* ��Ų�ѯ����Ļ��� */
        unsigned char bItemTotal;       /* ��С�����¼��ݵ������ */
        T_BXTRACK_ITEM stTrackItem[8];
        union {
                struct {        /* no wildcard  */
                        unsigned short nTotal;  /* ���������ĺ������� */
                        unsigned long nCurPosi; /* FLASH�ĵ�ǰλ�� */
                        unsigned short nReadedNum;
                } __attribute__((packed)) tNo;
                struct {        /*  wildcard   */
                        unsigned char fFindEnd; /* ��ѯ������־  */
                        unsigned char bWildNum; /* '*'����Ŀ,��ͷȥβ����4�� */
                        unsigned char sBitNo[5];        /* '*'������λ�� */
                        unsigned char sCh[5];   /* ���'*'���õ����� */
                        unsigned long nCurPosi; /* FLASH�ĵ�ǰλ�� */
                        unsigned short nRemainNum;      /* FLASH�ĵ�ǰλ��ʣ�µĺ����� */
                        unsigned short nTotal;  /* ���������ĺ������� */
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
#define MAX_PY_BUFFER           2000    /* ƴ���������󻺳�,�����ɲ鵽600���� */

#define MAX_PY_NUM                      14

#define PY_INDEX_TOTAL          0x1E1   // 885
//#define PYCODETBL_OFFSET      0x25d00

#define PYCODE_REC_SIZE         3
#define PYBASE_INFO_SIZE        6

typedef struct {
        unsigned char sInpCode[1];      /* �����������λ��ת����BCD[�Ҷ���] */
        unsigned char sHz[2];
} __attribute__((packed)) T_PYCODE_REC;

typedef struct {
        unsigned char sInpCode[8];      /* �����ƽ���룬���в���'*' */
        unsigned short bHzNum;  /* �����к��ֵ���Ŀ */
        unsigned short bPoint;  /* ����sHzBuffer�ĵ�ǰλ�� */
        unsigned char sHzBuffer[MAX_PY_BUFFER + 4];     /* ��Ų�ѯ����Ļ��� */

        unsigned char bPYNum;   /* ƴ��������� */
        unsigned short nTotal[MAX_PY_NUM];      /* ���������ĺ������� */
        unsigned long nCurPosi[MAX_PY_NUM];     /* FLASH�ĵ�ǰλ�� */
} __attribute__((packed)) T_FINDPYLOG;

typedef struct {
        unsigned char sKey[3];  /* �������� */
        unsigned char sPYTotal[1];      /* ƴ������ */
        unsigned char sOffset[2];       /* �ڲ�����Ϣ�е�ƫ�� */
} __attribute__((packed)) T_PYBASE_INFO;        /* ������Ϣ */

typedef struct {
        unsigned char bPYTotal; /* ƴ����ϵ����� */
        unsigned char fHintInput[MAX_PY_NUM];   /* �Ƿ���ʾ���� */
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
        unsigned short bNum;    /* �����к��ֵ���Ŀ */
        unsigned short bPoint;  /* ����sHzBuffer�ĵ�ǰλ�� */
        unsigned char sHzBuffer[256];   /* ��Ų�ѯ����Ļ��� */
        unsigned short nTotal;  /* ���������ĺ������� */
        unsigned long nCurPosi; /* FLASH�ĵ�ǰλ�� */
} __attribute__((packed)) T_FINDLXLOG;

/* ADD OKI START */
#endif                          /* FINDCODE_H */
/* ADD OKI END */
