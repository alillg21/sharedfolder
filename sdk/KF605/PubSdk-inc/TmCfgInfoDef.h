/***********************************************************************************************************
 *
 * @FILENAME		: TmCfgInfoDef.h
 *
 * @AUTHOR  		: zjwu
 *
 * @DATE	  		: 2009-8-26
 *
 * @DESCRIPTION		: 
 *
 * @COPYRIGHT		: 2009-2012 ShenZhen KAIFA Technology Co.,Ltd.
 *
 ***********************************************************************************************************/

#ifndef _FACTORYDEF_H_
#define _FACTORYDEF_H_

//请不要修改下面的定义
#define HARD_DEVICE_SERIAL_0				0x00000001 			//串口0
#define HARD_DEVICE_SERIAL_1				0x00000002			//串口1
#define HARD_DEVICE_SERIAL_2				0x00000004			//串口2
#define HARD_DEVICE_SERIAL_3				0x00000008			//串口3
#define HARD_DEVICE_NETWORK_MOUDLE			0x00000010			//网卡
#define HARD_DEVICE_GPRS_MODULE				0x00000020			//gprs模块
#define HARD_DEVICE_CDMA_MODULE				0x00000040			//CDMA模块
#define HARD_DEVICE_MODEM_MOUDLE			0x00000080			//有线modem
#define HARD_DEVICE_PRINTER					0x00000100			//打印机

#define TMC_OPEN_FILE_FAILURE	-1		//打开终端硬件配置文件失败
#define TMC_READ_FILE_FAILURE	-2		//读取终端硬件配置文件失败
#define TMC_WRITE_FILE_FAILURE	-3		//写终端硬件配置文件失败
#define TMC_CREAT_FILE_FAILURE	-4		//创建终端硬件配置信息文件失败

#define KEYBEEP_ON	1
#define KEYBEEP_OFF	0

#define MAX_DELAY_TIME	999


#define DEFAULT_LCDBACKLIGHT_DELAY_TIME		60					//默认lcd背景灯延时关闭时间

#define MOUDLE_EXIST		1
#define MOUDLE_NOT_EXIST	0

//函 数 名: TMC_IfExistGprsMoudle
//描    述: 判断终端硬件是否有GPRS通讯模块
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 
//			TMC_OPEN_FILE_FAILURE	:打开终端硬件配置文件失败
//			TMC_READ_FILE_FAILURE	:读取终端硬件配置文件失败			
//			MOUDLE_EXIST			:模块存在
// 			MOUDLE_NOT_EXIST		:模块不存在
//作    者: 吴 志 坚
//创建日期: 2009/8/26
//修 改 者: 
//修改日期: 
//备    注: 
int TMC_IfExistGprsMoudle(void);


//函 数 名: TMC_IfExistCdmaMoudle
//描    述: 判断终端硬件是否有CDMA通讯模块
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 
//			TMC_OPEN_FILE_FAILURE	:打开终端硬件配置文件失败
//			TMC_READ_FILE_FAILURE	:读取终端硬件配置文件失败			
//			MOUDLE_EXIST			:模块存在
// 			MOUDLE_NOT_EXIST		:模块不存在
//作    者: 吴 志 坚
//创建日期: 2009/8/26
//修 改 者: 
//修改日期: 
//备    注: 
int TMC_IfExistCdmaMoudle(void);



//函 数 名: TMC_IfExistModemMoudle
//描    述: 判断终端硬件是否有MODEM通讯模块
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 
//			TMC_OPEN_FILE_FAILURE	:打开终端硬件配置文件失败
//			TMC_READ_FILE_FAILURE	:读取终端硬件配置文件失败			
//			MOUDLE_EXIST			:模块存在
// 			MOUDLE_NOT_EXIST		:模块不存在
//作    者: 吴 志 坚
//创建日期: 2009/8/26
//修 改 者: 
//修改日期: 
//备    注: 
int TMC_IfExistModemMoudle(void);



//函 数 名: TMC_IfExistNetWorkMoudle
//描    述: 判断终端硬件是否有网卡
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 
//			TMC_OPEN_FILE_FAILURE	:打开终端硬件配置文件失败
//			TMC_READ_FILE_FAILURE	:读取终端硬件配置文件失败			
//			MOUDLE_EXIST			:模块存在
// 			MOUDLE_NOT_EXIST		:模块不存在
//作    者: 吴 志 坚
//创建日期: 2009/8/26
//修 改 者: 
//修改日期: 
//备    注: 
int TMC_IfExistNetWorkMoudle(void);


//函 数 名: TMC_IfExistBatteryMoudle
//描    述: 判断终端硬件是否有电池
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 
//			TMC_OPEN_FILE_FAILURE	:打开终端硬件配置文件失败
//			TMC_READ_FILE_FAILURE	:读取终端硬件配置文件失败			
//			MOUDLE_EXIST			:模块存在
// 			MOUDLE_NOT_EXIST		:模块不存在
//创建日期: 2012/6/26
//修 改 者: 
//修改日期: 
//备    注: 
int TMC_IfExistBatteryMoudle(void);


//函 数 名: GetLcdBackLightDelayTime
//描    述: 获取Lcd背光延时时间
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 
//			TMC_OPEN_FILE_FAILURE	:打开终端硬件配置文件失败
//			TMC_READ_FILE_FAILURE	:读取终端硬件配置文件失败			
//			其他值					:当前配置文件中lcd背光延时时间					
//作    者: 吴 志 坚
//创建日期: 2009/8/26
//修 改 者: 
//修改日期: 
//备    注: 
int GetLcdBackLightDelayTime(void);


//函 数 名: SetLcdBackLightDelayTime
//描    述: 获取Lcd背光延时时间
//全局变量: 无
//输入参数: time:背光延时时间(以秒为单位)
//输出参数: 无
//返 回 值: 
//			TMC_OPEN_FILE_FAILURE	:打开终端硬件配置文件失败
//			TMC_READ_FILE_FAILURE	:读取终端硬件配置文件失败			
//			TMC_WRITE_FILE_FAILURE	:写配置文件失败		
//			0						:成功			
//作    者: 吴 志 坚
//创建日期: 2009/8/26
//修 改 者: 
//修改日期: 
//备    注: 
//int SetLcdBackLightDelayTime(int time);




#endif





