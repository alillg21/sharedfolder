/** 
 * @file     other.h
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
#ifndef OTHER_H_
#define OTHER_H_

/*auto ret time defined 60 seconds*/
#define AUTORET_TIME 60000		
/*define function pointer*/
typedef void (*pfun)();


extern void DemoDisplayInfo(const s32 line,const u8 *pinfo,const u8 ucAtr);
extern void DemoWaitKeyToBack(pfun psfun);
extern void DemoEnterUartModule(void);
extern void DemoGetPosSerialNumber(void);
extern void DemoGetLibVersion(void);
extern void DemoEnterOtherModule(void);

#endif





