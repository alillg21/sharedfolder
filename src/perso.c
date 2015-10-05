#include "Global.h"

int explode(u8 ***arr_ptr, u8 *str, u8 delimiter)
{
	u8 		*src = str, *end, *dst;
	u8 		**arr;
	u32 		size = 1, i;

	while((end = strchr(src, delimiter)) != NULL)
	{
		++size;
		src = end + 1;
	}

	arr = malloc(size * sizeof(char *) + (strlen(str) + 1) * sizeof(char));

	src = str;
	dst = (u8 *) arr + size * sizeof(u8 *);

	for (i = 0; i < size; ++i)
	{
		if ((end = strchr(src, delimiter)) == NULL)
			end = src + strlen(src);
		arr[i] = dst;
		strncpy(dst, src, end - src);
		dst[end - src] = '\0';
		dst += end - src + 1;
		src = end + 1;
	}
	*arr_ptr = arr;

	return size;
}

void DemoPersoCard(u8 *FingerData, u8 *nik, u8 *name)
{
	u8		tempData[2000];
	u8 		**arr;
	s32 		size, i;
	
	memset(tempData, 0x00, sizeof(tempData));
	memset(buffer1, 0x00, sizeof(buffer1));
	memset(buffer2, 0x00, sizeof(buffer2));
	memset(buffer3, 0x00, sizeof(buffer3));
	
	strcpy(tempData,  nik);
	strcat(tempData,"#");
	strcat(tempData,name);
	strcat(tempData,"#");
	strcat(tempData,"100000");
	strcat(tempData,"#");
	strcat(tempData, FingerData);
	
	strcpy(buffer1,nik);
	strcpy(buffer2,name);
	strcpy(buffer3,"100000");
	
	if(!selectFile(0xAA, 0x10))        
		return;    
	
	if(!writeRecord(0x00,0x00,0x15,0x15, (u8*)tempData))
		return;
	
	if(!readRecord(0x00, 0x18))       
		return;
	else
	{
		s32 key = 0;
    		s32 timerid = 0;

		size = explode(&arr, tempData, '#');
	    	timerid = sdkSysGetTimerCount();
		
	    	while (1)
	    	{
	        	sdkLcdClear();
			for (i = 0; i < size; ++i)
	        		sdkLcdFillRow(i, 0, (u8 *) arr[i], M_UCTR);

			sdkLcdBrushScreen();
  	         	if (sdkSysGetTimerEnd(timerid,AUTORET_TIME))
        		{
            			DemoShowWelCome();
            			return;
        		}
        		key = sdkKbGetKey();
        		switch(key)
        		{
				case SDK_KEY_CANCEL:	
					DemoShowWelCome(); break;
		
			}
	    	}
	}
}

void DemoSaldoCard(void)
{
	u8		tempData[2000];
	u8 		**arr;
	s32 		size, i;

	if(!initialize())
		return;
	
	if(!selectFile(0xAA, 0x10))        
		return;    
	
	if(!readRecord(0x00, 0x18))       
		return;
	else
	{
		s32 key = 0;
    		s32 timerid = 0;

		size = explode(&arr, pbRecvBuffer, '#');
	    	timerid = sdkSysGetTimerCount();
		
	    	while (1)
	    	{
	        	sdkLcdClear();
			for (i = 0; i < size; ++i)
	        		sdkLcdFillRow(i, 0, (u8 *) arr[i], M_UCTR);

			sdkLcdBrushScreen();
  	         	if (sdkSysGetTimerEnd(timerid,AUTORET_TIME))
        		{
            			DemoShowWelCome();
            			return;
        		}
        		key = sdkKbGetKey();
        		switch(key)
        		{
				case SDK_KEY_CANCEL:	DemoShowWelCome(); break;
		
			}
	    	}
	}
}

