#ifndef _SDK_VERSION_
#define _SDK_VERSION_

#ifdef __cplusplus
extern "C" {
#endif

void sdk_GetLibkfsdkVersion(char *sVer );

//函 数 名:
//功    能: 获取机器(硬件)序列号SN (终端背面的条码编号)
//输入参数:
//输出参数: pcTerminalSN - 终端硬件序列号
//返 回 值:
//      0:表示读取成功
//      其他:失败
//备    注: 1.支持手工输入，SN最小输入长度10个字节，最大长度16个字节
//          2.支持条码扫描仪录入，默认波特率9600，串口COM2
//          3.机器序列号保存文件名"/app/pos.sn"，应用层只允许录入一次
//          4.保存成功后，再次调用本函数时从该文件中读取
int sdk_GetTerminalSN(char *pcTerminalSN);

//函 数 名: sdk_GetGoSleepDelayTime
//描    述: 获取进入低功耗的时间
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值:
//          TMC_OPEN_FILE_FAILURE   :打开终端硬件配置文件失败
//          TMC_READ_FILE_FAILURE   :读取终端硬件配置文件失败
//          其他值              :当前配置文件中进入低功耗的时间
//作    者: 刘奇玲
//创建日期: 2013/1/16
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

