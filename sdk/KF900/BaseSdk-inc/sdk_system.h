#ifndef _SDK_VERSION_
#define _SDK_VERSION_

#ifdef __cplusplus
extern "C" {
#endif

void sdk_GetLibkfsdkVersion(char *sVer );

//�� �� ��:
//��    ��: ��ȡ����(Ӳ��)���к�SN (�ն˱����������)
//�������:
//�������: pcTerminalSN - �ն�Ӳ�����к�
//�� �� ֵ:
//      0:��ʾ��ȡ�ɹ�
//      ����:ʧ��
//��    ע: 1.֧���ֹ����룬SN��С���볤��10���ֽڣ���󳤶�16���ֽ�
//          2.֧������ɨ����¼�룬Ĭ�ϲ�����9600������COM2
//          3.�������кű����ļ���"/app/pos.sn"��Ӧ�ò�ֻ����¼��һ��
//          4.����ɹ����ٴε��ñ�����ʱ�Ӹ��ļ��ж�ȡ
int sdk_GetTerminalSN(char *pcTerminalSN);

//�� �� ��: sdk_GetGoSleepDelayTime
//��    ��: ��ȡ����͹��ĵ�ʱ��
//ȫ�ֱ���: ��
//�������: ��
//�������: ��
//�� �� ֵ:
//          TMC_OPEN_FILE_FAILURE   :���ն�Ӳ�������ļ�ʧ��
//          TMC_READ_FILE_FAILURE   :��ȡ�ն�Ӳ�������ļ�ʧ��
//          ����ֵ              :��ǰ�����ļ��н���͹��ĵ�ʱ��
//��    ��: ������
//��������: 2013/1/16
int sdk_GetGoSleepDelayTime(void);

/********************************************************************
Function       :     sdk_Init(void);
Description    :     This function initializes the system .
Input          :     None
Output         :     None
Return Value   :
         0 - Success
         -1 - Failed
*********************************************************************/
int sdk_Init(void);

//  Function    : int sdk_Shutdown(void)
//  Description : This function shuts down the terminal directly.
//  Parameters  : N/A
//  Return Value: 0     Success
//                -1    Error
//  Remarks     : N/A
int sdk_Shutdown(void);

//  Function    : int sdk_Reboot (void)
//  Description : This function reboots the terminal.
//  Parameters  : N/A
//  Return Value: 0     Success
//                -1    Error
//  Remarks     : N/A
int sdk_Reboot (void);

/********************************************************************
Function       :     sdk_SetSDKLanguage
Description    :     This function sets language for the prompt in SDK.
Input          :     cLangIndex
    0 - english
    1 - chinese
Output         :     None
Return Value   :    None
Remarks     : the default displaying language is english.
*********************************************************************/
void sdk_SetSDKLanguage(char cLangIndex);

#ifdef __cplusplus
}
#endif

#endif

