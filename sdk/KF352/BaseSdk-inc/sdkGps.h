/********************************************************************
�ļ��� : sdkGps.h
��  �� : GPS
��  Ȩ : ���ǿ���
��  �� : ¬ԣ��
�޸ļ�¼: 
    ����              �޸���  �޸�����
    2014-03-11 15:53  ¬ԣ��  ����
********************************************************************/
#ifndef BASE_SDKGPS_H_
#define BASE_SDKGPS_H_

#ifdef __cplusplus
    extern "C" {
#endif

//GPSλ����Ϣ��Դ
#define SDK_GPS_DEV         0   //ʹ��GPS���Ƕ�λ
#define SDK_GPS_WIRELESS    1   //ʹ���������綨λ

// GPS������Ϣ
typedef struct
{
    s32 view_num;       /* �ɼ������� */
    s32 used_num;       /* ʹ�������� */
    s32 db[32];        /* ��������� -2��ʼ̬��-1׷��̬��0-99�����*/
}SDK_GPS_SATELLITE;

// GPS��λ��Ϣ
typedef struct
{
    u32 cnts;               /* ����Ѷ��ѭ������ */
    double latitude;        /* γ��             */
    double longitude;       /* ����             */
    double speed;           /* �����ٶ�         */
    double direction;       /* ��λ�Ƕ�         */
    double altitude;        /* ���θ߶�         */

    s32 lati_deg;           /* γ��-��          */
    s32 lati_cen;           /* γ��-��          */
    s32 lati_sec;           /* γ��-��          */
    s32 long_deg;           /* ����-��          */
    s32 long_cen;           /* ����-��          */
    s32 long_sec;           /* ����-��          */
    s8  n_s;                /* �ϱ�             */
    s8  e_w;                /* ����             */

    s8 UTC[16];             /* ����ʱ������ ASC�� "YYYYMMDDhhmmss" */
    s8 BTC[16];             /* ����ʱ������ ASC�� "YYYYMMDDhhmmss" */
    SDK_GPS_SATELLITE SAT;  /* ���ǲ���         */
}SDK_GPS_LOCATION;


s32 sdkGPSOpen(u8 pucProvider);
s32 sdkGPSClose(void);
s32 sdkGPSGetLocation(SDK_GPS_LOCATION *pucLocation);
s32 sdkGPSSleep(int nMode);

#ifdef __cplusplus
    }
#endif

#endif


