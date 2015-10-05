/********************************************************************
�ļ��� : sdkUI.h
��  �� : UI����
��  Ȩ : ���ǿ���
��  �� : ¬ԣ��
�޸ļ�¼: 
    ����              �޸���  �޸�����
    2014-02-18 10:39  ¬ԣ��  ����
********************************************************************/

#ifndef BASE_SDKUI_H_
#define BASE_SDKUI_H_

#ifdef __cplusplus
    extern "C" {
#endif

typedef enum
{
    SDK_UI_MENU_MODE_1,             
    //1.XX
    //2.XX
    //3.XX
    //4.XX

    //5.XX
    //6.XX
    //7.XX
    //8.XX

    SDK_UI_MENU_MODE_2,         
    //1.XX
    //2.XX
    //3.XX
    //4.XX

    //1.XX
    //2.XX
    //3.XX
    //4.XX

    SDK_UI_MENU_MODE_3,     
    //1.XX   2.XX
    //3.XX   4.XX

    SDK_UI_MENU_MODE_4,     
    //1.XX   3.XX
    //2.XX   4.XX
}E_SDK_UI_MENU_MODE;


typedef int (*CallBackFun)(void);

s32 sdkUISetMode(E_SDK_UI_MENU_MODE eMode, const char *pszTitle, 
    u32 nTimeout, CallBackFun pFun);
s32 sdkUIAddItem(const char* pszItem, CallBackFun pFun);
s32 sdkUIAddHideItem(s32 uiKey,CallBackFun pFun);
s32 sdkUIClear(void);
s32 sdkUIShowMenu(void);
s32 sdkUIBrushIcon(u8 ucMode);


#ifdef __cplusplus
    }
#endif

#endif

