/*!@file
********************************************************************************
Module: Common
file name: sdk_beep.h

function: system file
Author: CRD by Qiling Liu
version: 1.0.0
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
modify :
date              version          by           fixed
2010/02/23    1.0.0             Liu           create
*******************************************************************************/
#ifndef _sdk_BEEP_H_
#define _sdk_BEEP_H_

#ifdef __cplusplus
extern "C" {
#endif

//�� �� ��: sdk_CloseBeep
//��    ��: �򿪷�����
//�������: ��
//�������: ��
//�� �� ֵ: 0 �ɹ�, -1 �򿪷�����ʧ��
//��    ע:
int sdk_OpenBeep(void);

//�� �� ��: sdk_CloseBeep
//��    ��: �رշ�����
//�������: ��
//�������: ��
//�� �� ֵ: 0 �ɹ�, -1 �رշ�����ʧ��
//��    ע:
int sdk_CloseBeep(void);

/*
name       :sdk_Beep
desc.      :Beep with the current frequency during the default period(100 millisecond)
input para :None
return     :0   Success
            -1  Beeper is disabled
*/
int sdk_Beep();

#ifdef __cplusplus
}
#endif

#endif

