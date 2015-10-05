/***********************************************************************************************************
 *
 * @FILENAME		: mag-support.h
 *
 * @AUTHOR  		: zjwu
 *
 * @DATE	  		: 2009-8-18
 *
 * @DESCRIPTION		: 
 *
 * @COPYRIGHT		: 2009-2012 ShenZhen KAIFA Technology Co.,Ltd.
 *
 ***********************************************************************************************************/


//	函 数 名: MAG_OpenDevice
//	描    述: 打开磁条卡设备
//	全局变量: 无
//	输入参数: 无
//	输出参数: 无
//	返 回 值: 成功返回0, 失败返回-1
//	作    者: 吴 志 坚
//	创建日期: 2009/8/18
//	修 改 者: 
//	修改日期: 
//	备    注: 
int MAG_OpenDevice(void);


//	函 数 名: MAG_ClearTrack
//	描    述: 清除磁道数据
//	全局变量: 无
//	输入参数: 无
//	输出参数: 无
//	返 回 值: 无
//	作    者: 吴 志 坚
//	创建日期: 2009/8/18
//	修 改 者: 
//	修改日期: 
//	备    注: 
void MAG_ClearTrack(void);



//	函 数 名: MAG_CloseDevice
//	描    述: 关闭磁条卡设备
//	全局变量: 无
//	输入参数: 无
//	输出参数: 无
//	返 回 值: 无
//	作    者: 吴 志 坚
//	创建日期: 2009/8/18
//	修 改 者: 
//	修改日期: 
//	备    注: 
void MAG_CloseDevice(void);



//	函 数 名: MAG_SwipeCheck
//	描    述: 检查是否已经刷卡
//	全局变量: 无
//	输入参数: 无
//	输出参数: 无
//	返 回 值: 0-未刷卡, 1-已刷卡, -1-出错
//	作    者: 吴 志 坚
//	创建日期: 2009/8/18
//	修 改 者: 
//	修改日期: 
//	备    注:                                                                                                                                                                                                                                       
int MAG_SwipeCheck( void );


/*================================================================================================*
	函 数 名: MAG_Read
	描    述: 读磁道数据
	全局变量: 无
	输入参数: 无
	输出参数:	
				*cType&0x01>0:有1磁道数据,否则无1磁道数据
				*cType&0x02>0:有2磁道数据,否则无
				*cType&0x04>0:有3磁道数据,否则无
				(*cType取值从右到左第一位表示第一磁道，第二位表示第二磁道，第三位表示第三磁道)
				track1:读到的1磁道数据(只有在*cType&_TR1>0)该值才有意义
				track2:读到的2磁道数据(只有在*cType&_TR2>0)该值才有意义
				track3:读到的3磁道数据(只有在*cType&_TR3>0)该值才有意义
				
	返 回 值:	
				0-读磁卡数据成功
				1-选择磁道出错(读数据时先要选择哪个磁道)
				2-校验磁道起始标志失败
				3-校验磁道结尾标志失败
				4-一磁道数据长度不在_TRACK1_MIN_LEN~_TRACK1_MAX_LEN（包括边界值）之内
				5-二磁道数据长度不在_TRACK2_MIN_LEN~_TRACK2_MAX_LEN（包括边界值）之内
				6-三磁道数据长度不在_TRACK3_MIN_LEN~_TRACK3_MAX_LEN（包括边界值）之内
				7-读磁道数据失败
				
	作    者: 吴 志 坚
	创建日期: 2009/8/18
	修 改 者: 
	修改日期: 
	备    注: 1.该函数没有判断track1和track3的最小数据长度
			  2.输出参数track1的大小必须>=77
			  			track2的大小必须>=38
			  			track3的大小必须>=105
			  3.有一种极端情况是读数据成功(返回0),但是*cType=0.目前驱动层
			  	能够拦截这种情况.
			  4.每个磁道的长度范围定义如下
			  	#define _TRACK1_MAX_LEN 	76
				#define	_TRACK1_MIN_LEN		25	
				#define _TRACK2_MAX_LEN 	37
				#define _TRACK2_MIN_LEN		24 
				#define _TRACK3_MAX_LEN		104
				#define _TRACK3_MIN_LEN		66	
*================================================================================================*/
unsigned short MAG_Read(unsigned char *cType, unsigned char *track1, unsigned char *track2, unsigned char *track3);

//
//	函 数 名: MAG_DataCheck
//	描    述: 检查卡号数据是否正确,如果正确则输出卡号
//	全局变量: 无
//	输入参数: 
//			  cType:卡磁道类型
//			  track1:一磁道数据
//			  track2:二磁道数据
//			  track3:三磁道数据
//	输出参数: card_no
//	返 回 值: 成功返回0,失败返回1
//	作    者: 吴 志 坚
//	创建日期: 2009/8/18
//	修 改 者: 
//	修改日期: 
//	备    注: 
//			 1.只有成功时,card_no才有意义。
//			 2.未对1磁道数据做出校验。
//			 3.没有完全严格校对2、3磁道数据
unsigned short MAG_DataCheck(	unsigned char cType, unsigned char *track1, unsigned char *track2, 
								unsigned char *track3, unsigned char *card_no );



