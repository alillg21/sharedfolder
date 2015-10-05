/********************************************************************
�ļ��� : sdkDisp.h
��  �� : public�������LCD�йصĲ���
��  Ȩ : ���ǿ���
��  �� : DJ Chen
�޸ļ�¼:
    ����              �޸���  �޸�����
    2014-02-18 14:35  DJ Chen  ����
********************************************************************/
#ifndef PUBLIC_SDKDISP_H_
#define PUBLIC_SDKDISP_H_

#ifdef __cplusplus
    extern "C" {
#endif

#define SDK_DISP_MAXLEN       50
#define SDK_DISP_MAXLINE       32

#define SDK_DISP_LINE   12

#define SDK_DISP_KEYINIT              0
#define SDK_DISP_KEYUP                1
#define SDK_DISP_KEYDOWN              2



typedef struct
{
    u8 szDispData[SDK_DISP_MAXLINE][SDK_DISP_MAXLEN];//������ʾ
    u8 szDispIndex[SDK_DISP_MAXLINE];           //����
    u8 szCurDispAttr[SDK_DISP_MAXLINE];      //��ǰ����ʾ����
    u8 ucStartLine;        //��ʼ��ʾ����
    u8 ucTotalDispLine;    //�ܹ��ܹ���ʾ������
    u8 ucTotalDispNum;     //�ܹ���Ҫ��ʾ������
    u8 ucCurDispLine;      //��ǰ��ʾ������
    u8 ucEndDispLine;      //��ʾ�Ľ�������

}T_SDK_MULT_DISP;


s32 sdkDispMsg(u8 ucStartRow, const u8 *pszStr);
s32 sdkDispMulLine(u8 ucStartRow, const u8 *pszStr);
s32 sdkDispDynamicList(const u8 *pszTitle, const u8 *pszDispData, u32 uiOvertimer);
s32 sdkDispMsgDlg(const u8 *pszStr, u32 uiOvertimer);

#ifdef __cplusplus
    }
#endif

#endif

