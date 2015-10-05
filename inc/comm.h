/** 
 * @file     comm.h
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
#ifndef COMM_H_
#define COMM_H_

extern void DemoSetCommModel(T_SDK_COMM_COMMPARAM *pstcommpara);
extern s32 DemoCommModeSelect(void);
extern s32 DemoCommFunSimulateTest(const T_SDK_COMM_COMMPARAM *pstcommpara);
extern void DemoCommSettingDetails(s32 commtype,T_SDK_COMM_COMMPARAM *pstcommpara);
extern void DemoEnterCommModule(void);

#endif





