/********************************************************************
文件名 : sdkGps.h
描  述 : GPS
版  权 : 长城开发
作  者 : 卢裕燕
修改记录: 
    日期              修改人  修改内容
    2014-03-11 15:53  卢裕燕  创建
********************************************************************/
#ifndef BASE_SDKGPS_H_
#define BASE_SDKGPS_H_

#ifdef __cplusplus
    extern "C" {
#endif

//GPS位置信息来源
#define SDK_GPS_DEV         0   //使用GPS卫星定位
#define SDK_GPS_WIRELESS    1   //使用无线网络定位

// GPS卫星信息
typedef struct
{
    s32 view_num;       /* 可见卫星数 */
    s32 used_num;       /* 使用卫星数 */
    s32 db[32];        /* 卫星信噪比 -2初始态，-1追踪态，0-99信噪比*/
}SDK_GPS_SATELLITE;

// GPS定位信息
typedef struct
{
    u32 cnts;               /* 接收讯号循环计数 */
    double latitude;        /* 纬度             */
    double longitude;       /* 经度             */
    double speed;           /* 地面速度         */
    double direction;       /* 方位角度         */
    double altitude;        /* 海拔高度         */

    s32 lati_deg;           /* 纬度-度          */
    s32 lati_cen;           /* 纬度-分          */
    s32 lati_sec;           /* 纬度-秒          */
    s32 long_deg;           /* 经度-度          */
    s32 long_cen;           /* 经度-分          */
    s32 long_sec;           /* 经度-秒          */
    s8  n_s;                /* 南北             */
    s8  e_w;                /* 东西             */

    s8 UTC[16];             /* 世界时间日期 ASC码 "YYYYMMDDhhmmss" */
    s8 BTC[16];             /* 北京时间日期 ASC码 "YYYYMMDDhhmmss" */
    SDK_GPS_SATELLITE SAT;  /* 卫星参数         */
}SDK_GPS_LOCATION;


s32 sdkGPSOpen(u8 pucProvider);
s32 sdkGPSClose(void);
s32 sdkGPSGetLocation(SDK_GPS_LOCATION *pucLocation);
s32 sdkGPSSleep(int nMode);

#ifdef __cplusplus
    }
#endif

#endif


