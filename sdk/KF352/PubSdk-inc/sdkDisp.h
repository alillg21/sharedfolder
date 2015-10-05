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

s32 sdkDispMulLine(u8 ucStartRow, const u8 *pszStr);
s32 sdkDispDynamicList(const u8 *pszTitle, const u8 *pszDispData, u32 uiOvertimer);
s32 sdkDispMsgDlg(const u8 *pszStr, u32 uiOvertimer);

#ifdef __cplusplus
    }
#endif

#endif

