#ifndef _PWR_SUPPORT_H_
#define _PWR_SUPPORT_H_

#define WM_POWER_ON  				"100"
#define WM_POWER_OFF				"101"
#define WM_POWER_RESET			"102"
#define WM_CHANN_ENABLE  		"103"
#define WM_CHANN_DISABLE  	"104"
	

#define OPEN_PWR_DEV_ERR 	-1
#define CLOSE_PWR_DEV_ERR	-2
#define READ_PWR_DEV_ERR	-3
#define WRITE_PWR_DEV_ERR	-4




//	#define WIFIOFF		105
//	#define WIFION		106
//	#define WIFI_RST  	107
//	#define SELHDMI  	108
//	#define SELBT  		109
//	#define ENBTCMD		110
//	#define DISBTCMD	111
//	#define BT_RST  	112


//status= 0-无电, 1=1/4点量, 2=2/4电量, 3=3/4电量, 4=满电量, 0xFF-外接电源, 0xFE-正在充电
#define BAT_VAL0 	0
#define BAT_VAL1 	1
#define BAT_VAL2 	2
#define BAT_VAL3 	3
#define BAT_VAL4 	4
#define BAT_DC		0xFF
#define BAT_CHARGE 	0xFE


//函 数 名:	PWR_GetHandle
//功    能:	取电源设备句柄,
//输入参数:	无
//输出参数:	无
//返 回 值:
//			-1:表示电源设备文件处于关闭状态
//			>-1:表示电源设备打开后的句柄值
int PWR_GetHandle(void);


//函 数 名:	PWR_CloseDevice
//功    能:	关闭电源设备句柄,
//输入参数:	无
//输出参数:	无
//返 回 值: 
//			0:成功关闭电源设备
//			CLOSE_PWR_DEV_ERR:关闭电源设备失败
int PWR_CloseDevice(void);




//函 数 名:	PWR_OpenDevice
//功    能:	打开电源设备句柄,
//输入参数:	无
//输出参数:	无
//返 回 值: 
//			>=0:成功打开电源设备,返回值为打开设备后返回的句柄
//			OPEN_PWR_DEV_ERR:打开电源设备失败.
int PWR_OpenDevice(void);


//函 数 名: PWR_GetBatteryStatus
//描    述: 取电池状态
//全局变量: 无
//输入参数: 
//输出参数: status= 0-无电, 1=1/4点量, 2=2/4电量, 3=3/4电量, 4=满电量, 0xFF-外接电源, 0xFE-正在充电
//返 回 值: 
//			0-成功
//			OPEN_PWR_DEV_ERR:打开电源设备失败
//			READ_PWR_DEV_ERR:读电源设备失败
//作    者: 吴 志 坚
//创建日期: 2009/7/13
//修 改 者: 
//修改日期: 
//备    注: 
int PWR_GetBatteryStatus(unsigned char *status );


//函 数 名: PWR_WM_PowerOn
//描    述: 无线模块上电
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 
//			0:成功
//			OPEN_PWR_DEV_ERR:打开电源设备失败
//			WRITE_PWR_DEV_ERR:写电源设备失败 
//作    者: 吴 志 坚
//创建日期: 2009/7/06
//修 改 者: 
//修改日期: 
//备    注: 
int PWR_WM_PowerOn(void);


//函 数 名: PWR_WM_PowerOff
//描    述: 无线模块下电
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 
//			0:成功
//			OPEN_PWR_DEV_ERR:打开电源设备失败
//			WRITE_PWR_DEV_ERR:写电源设备失败 
//作    者: 吴 志 坚
//创建日期: 2009/7/06
//修 改 者: 
//修改日期: 
//备    注: 
int PWR_WM_PowerOff(void);



//函 数 名: PWR_WM_PowerReset
//描    述: 无线模块下电
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 
//			0:成功
//			OPEN_PWR_DEV_ERR:打开电源设备失败
//			WRITE_BATTERY_ERR:写电源设备失败 
//作    者: 吴 志 坚
//创建日期: 2009/7/06
//修 改 者: 
//修改日期: 
//备    注: 只有在无线模块Power on状态下, 该函数才会实际其作用
int PWR_WM_PowerReset(void);



//函 数 名: PWR_WM_ChannEnable
//描    述: 启动无线模块通道,只有该函数成功调用后,无线模块才能成功收到AT指令
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 
//			0:成功
//			OPEN_PWR_DEV_ERR:打开电源设备失败
//			WRITE_PWR_DEV_ERR:写电源设备失败 
//作    者: 吴 志 坚
//创建日期: 2009/7/06
//修 改 者: 
//修改日期: 
//备    注: 只有在无线模块Power on状态下, 该函数才会实际其作用
int PWR_WM_ChannEnable(void);



//函 数 名: PWR_WM_ChannDisable
//描    述: 关闭无线模块通道,关闭后,无线模块将收不到AT指令
//全局变量: 无
//输入参数: 无
//输出参数: 无
//返 回 值: 
//			0:成功
//			OPEN_PWR_DEV_ERR:打开电源设备失败
//			WRITE_PWR_DEV_ERR:写电源设备失败 
//作    者: 吴 志 坚
//创建日期: 2009/7/06
//修 改 者: 
//修改日期: 
//备    注:
int PWR_WM_ChannDisable(void);



#endif


