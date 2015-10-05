#ifndef SUPPORT_HD_H
#define SUPPORT_HD_H


//函 数 名:HD_Init
//功    能:初始化handset与底座的通讯
//输入参数:nType=0, 使用串口, nType=2使用红外
//输出参数:无
//返 回 值:0-成功, -1失败
int HD_Init(int nType );



//该函数功能同HD_Init,为兼容之前的版本而存在,建议不要使用
int hd_serial_init(void);


#endif

