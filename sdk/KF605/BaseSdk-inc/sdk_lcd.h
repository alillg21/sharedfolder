/* LCD module functions
********************************************************************************
1. Implement the initial functions.
----by Lu Yongning/Yu Zumiao  03/22/2010

2. Add new functions (Backlight, display row, draw point etc)
----by Luo cheng  11/18/2010
*******************************************************************************/


#ifndef _SDK_LCD_H_
#define _SDK_LCD_H_

//#include "sdk_font.h"
#include "sdk_common.h"

#define LCD_FILENAME        "/dev/fb0"

#define ICON_PHONE1         0x01        //the first phone icon(from topside)
#define ICON_PHONE2         0x02        //the second phone icon(from topside)
#define ICON_PHONE3     0x03        //the third phone icon(from topside)

/*
#define ICON_BAT        0x01        //the outside boarder of battery icon/
#define ICON_BAT1       0x02        //the first block of battery icon from right to left.
#define ICON_BAT2       0x04        //the second block of battery icon from right to left.
#define ICON_BAT3       0x08        //the third block of battery icon from right to left.
#define ICON_BAT4       0x10        //the fourth (last) block of battery icon
*/
#define LINE1   0
#define LINE2   1
#define LINE3   2
#define LINE4   3
#define LINE5   4
#define LINE6   5
#define LINE7   6
#define LINE8   7

#define ICON_PHONE      11  //phone icon
#define ICON_SIGNAL     12  //wireless signal icon
#define ICON_PRINTER    13  //printer icon
#define ICON_ICCARD     14  //IC card icon
#define ICON_LOCK           15  //lock icon
#define ICON_SPEAKER    16  //speaker icon
#define ICON_UP             17  //up icon
#define ICON_DOWN           18  //down icon
#define ICON_BATTERY    19  //battery icon


#ifdef __cplusplus
extern "C" {
#endif

/* sdk_LcdInit
********************************************************************************
Description : initializes the LCD device
Input Param : none
Output Param: none
Return      :
                 0: Success
        -1: the LCD module is not detected.
        -2: fails to get the display parameter.
        -3: fails to set backlight.
Remarks     :   This function should be invoked in the function of main () and
                needn't be invoked for a second time (If user initializes again,
                this API will return the handle initialized successfully).
*******************************************************************************/
int sdk_LcdInit(void);

/* sdk_LcdClose
********************************************************************************
Description : closes the LCD device
Input Param : none
Output Param: none
Return      : none
Remarks     : The application may not invoke it because the LCD will close automatically after exiting.
*******************************************************************************/
void sdk_LcdClose(void);

/* LcdSetContrast
********************************************************************************
Description :  NOT AVAILABLE NOW.
Input Param : value:1-50
Output Param:
Return      :
Remarks     :
*******************************************************************************/
int sdk_SetLcdContrast(uchar value);

/* sdk_LcdSetBackLightStatus
********************************************************************************
Description : controls LCD backlight.
Input Param :
                mode :An integer to indicate the backlight settings:
                      0 - The backlight is on all the time
                      1 - The backlight is off all the time
                      2 - The backlight will be on for a period of time, which is decided by the parameter timer.
                times:An integer to identify how long the LCD will be on before being off (in seconds).
                      Its value is from 1 to 999.
Output Param: none
Return      :
                 0: Success
        -1: the LCD module is not initialized.
        -2: fails to open the backlight.
        -3: Invalid parameter
Remarks     :   In mode 2, the backlight will turn on whenever there is keyboard/magnetic card/ICC card event.
*******************************************************************************/
int sdk_LcdSetBackLightStatus(int mode, int times);

/* sdk_LcdGetBackLightStatus
********************************************************************************
Description : gets the status of the LCD backlight.
Input Param : none
Output Param: none
Return      :
      0 - The backlight is on all the time
      1 - The backlight is off all the time
      2 - The backlight will be on for a period of time.
*******************************************************************************/
int sdk_LcdGetBackLightStatus(void);

/* sdk_LcdBackLightOn
********************************************************************************
Description : turns on LCD backlight immediately.
Input Param : none
Output Param: none
Return      :
                 0: Success
        -1: the LCD module is not initialized.
        -2: fails to open the backlight.
Remarks     : The backlight will not be off until invoking the close function.
*******************************************************************************/
int sdk_LcdBackLightOn(void);

/* sdk_LcdBackLightOff
********************************************************************************
Description : turns off LCD backlight immediately.
Input Param : none
Output Param: none
Return      :
                 0: Success
        -1: the LCD module is not initialized.
        -2: fails to open the backlight.
Remarks     : The backlight will keep off if user doesn't invoke the open function.
*******************************************************************************/
int sdk_LcdBackLightOff(void);

/* sdk_LcdBackLightIsOpen
********************************************************************************
Description : checks the backlight of the LCD is on or off.
Input Param : none
Output Param: none
Return      :
      0 - The backlight is off.
      1 - The backlight is on.
*******************************************************************************/
int sdk_LcdBackLightIsOpen(void);

/* sdk_LcdSetIcon
********************************************************************************
Description : controls whether to light the specific built-in icon (like GPRS signal).
Input Param :
                icon_no:An integer to identified the built-in icon:
                        ICON_PHONE - Telephone signal icon
                        ICON_SIGNAL - Wireless icon
                        ICON_PRINTER - Printer icon
                        ICON_ICCARD - ICCard icon
                        ICON_LOCK - Lock icon
                        ICON_SPEAKER - Loudhailer icon
                        ICON_UP - Up icon
                        ICON_DOWN - Down icon
                        ICON_BATTERY - Battery icon

                action:An integer to decide whether to light the icon:
                       0 - Turns off the icon
                       1 - Turns on the icon
                       2 - Shows "hang up" (only used for telephone)

Output Param: none
Return      :
                 0: Success
        -1: the LCD module is not initialized.
        -2: fails to set up the icon.
Remarks     :   If the parameter is out of range, the icon status will not change.
                It is suggested that application program uses signal intensity icon only.
*******************************************************************************/
int sdk_LcdSetIcon(int icon_no, int action);

/* sdk_LcdSetFont
********************************************************************************
Description :  sets the font in the screen.
Input Param :
             font_type: It supports four fonts, two for English language and the other two for Chinese.
                        This parameter's default value is 0x0.
                        0x0 - Shows 6*12 ASCII characters, only used for English words.
                        0x1 - Shows 8*16 ASCII characters, only used for English words.
                        0x2 - Shows 12*24 ASCII characters, only used for English words.
                        0x3 - Shows 24*48 ASCII characters, only used for English words.
                        0x4 - Shows 48*96 ASCII characters, only used for English words.
                        0x5 - Shows 12*12 CHNFONT characters, only used for Chinese words.
                        0x6 - Shows 16*16 CHNFONT characters, only used for Chinese words.
                        0x7 - Shows 24*24 CHNFONT characters, only used for Chinese words.
                        0x8 - Shows 12*24 CHNFONT characters, only used for Chinese words.
                        0x9 - Shows 16*32 CHNFONT characters, only used for Chinese words.
                        0xA - Shows 24*48 CHNFONT characters, only used for Chinese words.
                        0xB - Shows 6*8 CHNFONT characters, only used for Chinese words.

Output Param: none
Return      : none
Remarks     :   The macro is defined in font.h
                It shows 6*8 ASCII English characters as default.
                It is suggested to check and set proper font before programming.
*******************************************************************************/
void sdk_LcdSetFont(uchar cFontType);

/* sdk_LcdGetSize
********************************************************************************
Description : gets the size of the screen.
Input Param : none
Output Param:
                width: An output parameter, to which the function will return and write the width of the screen.
                height:An output parameter, to which the function will return and write the height of the screen.
Return      : none
Remarks     : none
*******************************************************************************/
void sdk_LcdGetSize(int *width, int *height);

/* sdk_LcdGetWidth
********************************************************************************
Description : gets the width of the screen.
Input Param : none
Output Param:
Return      : width of the screen.
Remarks     : none
*******************************************************************************/
int sdk_LcdGetWidth(void);

/* sdk_LcdGetHeight
********************************************************************************
Description : gets the height of the screen.
Input Param : none
Output Param:
Return      : height of the screen.
Remarks     : none
*******************************************************************************/
int sdk_LcdGetHeight(void);

/* sdk_LcdGetFontWidth
********************************************************************************
Description : gets the width of the current font.
Input Param : none
Output Param:
Return      : height of the current font.
Remarks     : none
*******************************************************************************/
int sdk_LcdGetFontWidth(void);

/* sdk_LcdGetHeight
********************************************************************************
Description : gets the height of the current font.
Input Param : none
Output Param:
Return      : height of the current font.
Remarks     : none
*******************************************************************************/
int sdk_LcdGetFontHeight(void);

/* sdk_LcdBrush
********************************************************************************
Description : reads the pixel lattice from the specified memory area and shows it on the display.
Input Param : none
Output Param: none
Return      :
                 0: Success
        -1: the LCD module is not initialized.
        -2: fails to clear the display.
Remarks     :   This function is usually used with "sdk_ScrDrawPoint".
*******************************************************************************/
int sdk_LcdBrush(void);

/* sdk_ScrClear
********************************************************************************
Description : clears all contents on the LCD screen.
Input Param : none
Output Param: none
Return      :
                 0: Success
        -1: the LCD module is not initialized.
        -2: fails to clear the display.
Remarks     :   It will take effect immediately.
*******************************************************************************/
int sdk_ScrClear(void);

/* sdk_ScrClearRow
********************************************************************************
Description : clears all contents between the start row and the end row on the LCD screen.
Input Param : 
                StartRow: the row to start clear.
                EndRow: the row to end clear.
Output Param: none
Return      :
                 0: Success
        -1: the LCD module is not initialized.
        -2: fails to clear the display.
        -3: invalid parameters.
Remarks     :   It will take effect immediately.
*******************************************************************************/
int sdk_ScrClearRow(uchar StartRow, uchar EndRow);

/* sdk_ScrDispDo
********************************************************************************
Description : displays a string in the given location(x,y).
Input Param :
        x - the special column(pixel)
                -1: center alignment
                -2: right alignment
        y - the start row(pixel)
        pcString - the string need to display
        cType - 0:normal display; 1:reverse display
Output Param: none
Return      :
                 0: Success
        -1: the LCD module is not initialized.
        -2: fails to display.
        -3: invalid parameters.
        -4: fails to fill string.
Remarks     : If the string is too long to display in the given location, the string beyond the location will be terminated.
--------------------------------------------------------------------------------
*******************************************************************************/
int sdk_ScrDispRowDo(int x, int y, char *pcString, char cType);

/* sdk_ScrDispRow
********************************************************************************
Description : displays a string in the given location.
Input Param :
               pcString:The pointer to the data buffer of the string.
               Row     :An integer to identify the row (0 ~ MaxRow)
               Col     :An integer to identify the column (0 ~ MaxColumn -1)
                        Special [Col]: -1: center alignment
                                       -2: right alignment
Output Param: none
Return      :
                 0: Success
        -1: the LCD module is not initialized.
        -2: fails to display.
        -3: invalid parameters.
        -4: fails to fill string.
Remarks     :  It will return directly with nothing changed if any parameter is out of range.
               If the string is too long to display in the given location, the string beyond the location will be terminated.
               Notice that the max row will be different under different fonts settings.
*******************************************************************************/
int sdk_ScrDispRow(char* pcString, int Row, int Col);

/* sdk_ScrDispMultRow
********************************************************************************
Description : displays a string start from the given location,
                   if the string is too long to display in one line, it will be terminated and be displayed in multi-lines.
Input Param :
               pcString:The pointer to the data buffer of the string.
               Row     :An integer to identify the row (0 ~ MaxRow)
               Col     :An integer to identify the column (0 ~ MaxColumn -1)
                        Special [Col]: -1: center alignment
                                       -2: right alignment
Output Param: none
Return      :
                 0: Success
        -1: the LCD module is not initialized.
        -2: fails to display.
        -3: invalid parameters.
        -4: fails to fill string.
*******************************************************************************/
int sdk_ScrDispMultRow(char *pcDispInfo, int Row, int Col);

/* sdk_ScrDispRowReverse
********************************************************************************
Description : displays a string with color reversed in the given location,
              which means the background is black while the words are white.
Input Param :
               pcString:The pointer to the data buffer of the string.
               Row     :An integer to identify the row (0 ~ MaxRow -1)
               Col     :An integer to identify the column (0 ~ MaxColumn -1)
Output Param: none
Return      :
                 0: Success
        -1: the LCD module is not initialized.
        -2: fails to display.
        -3: invalid parameters.
        -4: fails to fill string.
Remarks     :  It will return directly with nothing changed if any parameter is out of range.
               If the string is too big to display in the given location, the string beyond the location will be cut.
               Notice that the max row will be different under different fonts settings.
*******************************************************************************/
int sdk_ScrDispRowReverse(char* pcString, int Row, int Col);

/* sdk_ScrPoint
********************************************************************************
Description : draws a point of a given location in the specified memory area.
              It doesn't show on the display until user invokes the "sdk_LcdBrush" function.
Input Param :
                 x     :An integer to identify the abscissa (The most left is 0 pixels while the most right is 127 pixels).
                 y     :An integer to identify the ordinate (The most top is 0 pixels while the most bottom is 63 pixels).
                 action:An integer to decide to draw or erase the point:
                        0 - Erases the given point
                        1 - Draw the point
Output Param: none
Return      :
                 0: Success
        -1: invalid parameters.
Remarks     :   It will return directly with nothing changed if any parameter is out of range.
*******************************************************************************/
int sdk_ScrPoint(int x, int y, int action);

/* sdk_ScrDrawHorizontalLine
********************************************************************************
Description : draws a horizontal line with the given location.
Input Param :
                 x    :An integer to identify the abscissa (The most left is 0 pixels while the most right is 127 pixels).
                 y    :An integer to identify the ordinate (The most top is 0 pixels while the most bottom is 63 pixels).
                 width:An integer of pixels to identify the length of the line.
Output Param: none
Return      :
                 0: Success
        -1: the LCD module is not initialized.
        -2: fails to clear the display.
        -3: invalid parameters.
Remarks     : none
*******************************************************************************/
int sdk_ScrDrawHorizontalLine(int x, int y, int width);

/* sdk_ScrDrawVerticalLine
********************************************************************************
Description : draws a vertical line with the given location.
Input Param :
                 x     :An integer to identify the abscissa (The most left is 0 pixels while the most right is 127 pixels).
                 y     :An integer to identify the ordinate (The most top is 0 pixels while the most bottom is 63 pixels).
                 height:An integer of pixels to identify the height of the line.
Output Param: none
Return      :
                 0: Success
        -1: the LCD module is not initialized.
        -2: fails to clear the display.
        -3: invalid parameters.
Remarks     : none
*******************************************************************************/
int sdk_ScrDrawVerticalLine(int x, int y, int height);

/* sdk_ScrDrawRectangle
********************************************************************************
Description : draws a certain size of rectangle in the given location.
Input Param :
                 x     :An integer to identify the abscissa (The most left is 0 pixels while the most right is 127 pixels).
                 y     :An integer to identify the ordinate (The most top is 0 pixels while the most bottom is 63 pixels).
                 width :An integer of pixels to identify the width of the rectangle.
                 height:An integer of pixels to identify the height of the rectangle.
Output Param: none
Return      :
                 0: Success
        -1: the LCD module is not initialized.
        -2: fails to clear the display.
        -3: invalid parameters.
Remarks     : none
*******************************************************************************/
int sdk_ScrDrawRectangle(int x, int y, int width, int height);

/* sdk_ScrCursor
********************************************************************************
Description : creates or erases a cursor at a specific location, which is decided by the coordinate.
Input Param :
                 x   :An integer to identify the abscissa (The most left is 0 pixels while the most right is 127 pixels).
                 y   :An integer to identify the ordinate (The most top is 0 pixels while the most bottom is 63 pixels).
                 mode:It decides to create or erase a cursor:
                        1 - Create a cursor
                        0 - Erases a cursor
Output Param: none
Return      :
                 0: Success
        -1: the LCD module is not initialized.
        -2: fails to display.
        -3:  invalid parameters.
Remarks     :   It will return directly with nothing changed if any parameter is out of range.
*******************************************************************************/
int sdk_ScrCursor(int x, int y,int mode);

/* sdk_ScrDispLogo
********************************************************************************
Description : displays a bitmap picture in the given area of the screen.
Input Param :
                 x   :An integer to identify the abscissa (The most left is 0 pixels while the most right is 127 pixels).
                 y   :An integer to identify the ordinate (The most top is 0 pixels while the most bottom is 63 pixels).
                 pcLogoBitmap:The pointer to the data buffer of the bitmap picture.
                 nLogoWidth:  An integer to identify the width (in pixels) of the bitmap picture.
                 nLogoHeight: An integer to identify the height (in pixels) of the bitmap picture.
Output Param: none
Return      :
                 0: Success
        -1: the LCD module is not initialized.
        -2: fails to display.
        -3: invalid parameters.
        -4: fails to read the memory area of picture.
Remarks     : It will return directly with nothing changed if any parameter is out of range.
          If the bitmap is too big to display in the given area, the bitmap beyond the area will be cut.
*******************************************************************************/
int sdk_ScrDispLogo(int x, int y, uchar* pcLogoBitmap, int nLogoWidth, int nLogoHeight);

/* sdk_ScrDispPage
********************************************************************************
Description : displays the contents with several lines.
              It always shows the contents from the very start column.
Input Param :
                pcDispInfo:The pointer to the data buffer of the string.
                StartRow  :The start row to show the contents.
                EndRow    :The end row to show the contents.
Output Param: none
Return      :
                 0: Success
        -1: the LCD module is not initialized.
        -2: fails to display.
        -3: invalid parameters.
        -4: fails to fill string.
Remarks     : none
*******************************************************************************/
int sdk_ScrDispPage(char *pcDispInfo, uchar StartRow, uchar EndRow);

#ifdef __cplusplus
}
#endif

#endif

