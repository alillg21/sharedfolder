/**
 * @file     lcd.h
 * @brief    SDK(software development kit) sample code
 * @details  head files
 * @author   song
 * @date     2014/04/22
 * @version  V001
 * @par Copyright (c):
 *           KAIFA SHENZHEN CHINA
 * @par History:
 *   version: V001
 */
#ifndef LCD_H_
#define LCD_H_

enum BATTERY_STAUS
{
    E_EXTERNAL_SUPPLY = -3, //power supply error,or no battery on this POS
    E_POWER_FULL,           //has power supply,meanwhile,battery is full status
    E_POWER_ONGOING,        //power supply is on going,icon should flush always.
    E_POWER_ALARM,          //power alarm status,icon still should flash,
    E_POWER_LITTLE,         //little power,POS indicates operator should care it
    E_POWER_1,              //battery level 1
    E_POWER_2,              //battery level 2
    E_POWER_3,              //battery level 3
    E_POWER_4,              //battery level 4

};




extern void DemoEnterLcdModule(void);
extern void DemoPixelsInfoDisplay(void);
extern void DemoDrawFrame(void);
extern void DemoPhotoDisplay(void);
extern void DemoProgrssBarDisplay(void);
extern void DemoIconDisplay(void);

#endif





