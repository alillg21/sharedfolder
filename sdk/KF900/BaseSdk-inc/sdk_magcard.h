/* Magnetic module functions
********************************************************************************
1. Implement the initial functions.
----by Yu Zumiao/Luo Cheng  03/22/2010

*******************************************************************************/
#ifndef _sdk_MAGCARD_H_
#define _sdk_MAGCARD_H_

#ifdef __cplusplus
extern "C" {
#endif

/* sdk_MagcardOpen
********************************************************************************
Description : results in the magnetic device is connected to service.
Input Param : none
Output Param: none
Return      :
                 0: Success
        -1: the magnetic device can not be opened.
Remarks     :   Once this function is invoked, it will keep checking card swiping and reading magnetic data all the time,
                until user closes the magnetic device with Sdk_MagClose API.
*******************************************************************************/
int sdk_MagcardOpen(void);

/* sdk_MagcardClose
********************************************************************************
Description : closes the magnetic service.
Input Param : none
Output Param: none
Return      : none
Remarks     : It is suggested to close the magnetic device when not using it.
*******************************************************************************/
void sdk_MagcardClose(void);

/* sdk_MagcardClearTrack
********************************************************************************
Description : clears all the track data in the buffer.
Input Param : none
Output Param: none
Return      : none
Remarks     : It is suggested to call this function when user wants to swipe card.
*******************************************************************************/
void sdk_MagcardClearTrack(void);

/* sdk_MagcardSwipeCheck
********************************************************************************
Description : checks whether there is any swiping card event.
Input Param : none
Output Param: none
Return      :
                 0: There is no card swiped.
        -1: There is a card swiped.
Remarks     : none
*******************************************************************************/
int sdk_MagcardSwipeCheck(void);

/* sdk_MagcardRead
********************************************************************************
Description : reads the three tracks data of the card and puts the data into the corresponding parameters.
Input Param : none
Output Param:
                cType: The pointer that is to identify which track data is included
                       *cType&0x01>0:has track 1 data, or no track 1 data
                       *cType&0x02>0: has track 2 data, or no track 2 data
                       *cType&0x04>0: has track 3 data, or no track 3 data
                track1:The pointer that is to save the data of track1 (data length is 79 bytes).
                       Set it as NULL if user doesn't want this track data.
                track2:The pointer that is to save the data of track2 (data length is 40 bytes).
                       Set it as NULL if user doesn't want this track data.
                track3:The pointer that is to save the data of track3 (data length is 107 bytes).
                       Set it as NULL if user doesn't want this track data.
Return      :
                 bit0==0: Error to read card
                 bit0==1: Success
                 bit1==0: Track 1 data checkout fails
                 bit1==1: Success to read track 1 data
                 bit2==0: Track 2 data checkout fails
                 bit2==1: Success to read track 2 data
                 bit3==0: Track 3 data checkout fails
                 bit3==1: Success to read track 3 data
Remarks     :   If success, it will return the original data (including the start and end char, track data etc),
                            user needs to deal with different data field (PAN, Exp, Data…)
                The track data is defined as ISO7812.
*******************************************************************************/
int sdk_MagcardRead(unsigned char *cType, unsigned char *track1, unsigned char *track2, unsigned char *track3);

/* sdk_MagcardCheck
********************************************************************************
Description : 检查卡号数据是否正确,如果正确则输出卡号
Input Param : none
              cType:卡磁道类型(取值从右到左第一位表示第一磁道，第二位表示第二磁道，第三位表示第三磁道)
              track1:一磁道数据
              track2:二磁道数据
              track3:三磁道数据
Output Param: card_no
Return      : 成功返回0,失败返回-1(chengluo)
Remarks     : 
             1.只有成功时,card_no才有意义。
             2.未对1磁道数据做出校验。
             3.没有完全严格校对2、3磁道数据
*******************************************************************************/
int sdk_MagcardCheck(unsigned char cType, unsigned char *track1, unsigned char *track2,
                     unsigned char *track3, unsigned char *card_no);

#ifdef __cplusplus
}
#endif

#endif

