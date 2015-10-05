#include "Global.h"


BOOL PerformTransmitAPDU(u8 cmd1[], unsigned long size)
{    
	T_SDK_CARD_PARAM tCardParam;
	u8	uc[255];
	u32	uiLen = 0;
	u32	ret=0;

	memset(&tCardParam, 0x00, sizeof(tCardParam));
	memset(pbRecvBuffer, 0x00, sizeof(pbRecvBuffer));
	
	tCardParam.eCardType 	= ICC_CARDTYPE_CPU;
	tCardParam.ucCardMode	= SDK_CARD_INSERT;
	tCardParam.ucSlotNo		= 0x00;
	ret = sdkCardPowerUp(&tCardParam);
	if(ret!=SDK_OK)
		return FALSE;

	ret = sdkCardReset(&tCardParam, uc, &uiLen);
	if(ret!=SDK_OK)
		return FALSE;

	ret = sdkCardGetStatus(&tCardParam);
	if(ret !=SDK_OK)
		return FALSE;

	
	u32 dwRecvLength = sizeof(pbRecvBuffer); 
	ret = sdkCardSendData(&tCardParam, cmd1, size, pbRecvBuffer, &dwRecvLength);
	if(ret != SDK_OK)
		return FALSE;

	ret = sdkCardPowerDown(&tCardParam);
	if(ret != SDK_OK)
		return FALSE;
	  
	return TRUE;
}

BOOL initialize()
{
	u8 cmd1[] = { 0x80, 0x20, 0x07, 0x00, 0x08, 0x41, 0x43, 0x4F, 0x53, 0x54, 0x45, 0x53, 0x54 };
	
	if(!PerformTransmitAPDU(cmd1, sizeof(cmd1)))       
		return FALSE;   

	return TRUE;
}

BOOL selectFile(u8 HiAddr, u8 LoAddr)   
{
	// Select file Hi address & Low address    
	u8 Data[7];   

	Data[0] = 0x80;       
	Data[1] = 0xA4;           
	Data[2] = 0x00;             
	Data[3] = 0x00;             
	Data[4] = 0x02;             
	Data[5] = HiAddr;          
	Data[6] = LoAddr;          

	if(PerformTransmitAPDU(Data, sizeof(Data)))        
		return TRUE;   
	else        
		return FALSE;
}

BOOL readRecord(u8 RecNo, u8 dataLen)
{
	// Read data from card    
	u8 Data[5];    

	Data[0] = 0x80;      	     
	Data[1] = 0xB2;      	     
	Data[2] = RecNo;        	    
	Data[3] = 0x00;         	    
	Data[4] = dataLen;         

	if(PerformTransmitAPDU(Data, sizeof(Data)))        
		return TRUE;    
	else        
		return FALSE;
}

BOOL writeRecord(s32 caseType, u8 RecNo, u8 maxLen, u8 DataLen, u8 * ApduIn)
{
	u32 	i;    
	u8 	Data[5 + maxLen];    

	if (caseType == 1)    // If card data is to be erased before writing new data. Re-initialize card values to $00    
	{        
		Data[0] = 0x80;         	       
		Data[1] = 0xD2;         	     
		Data[2] = RecNo;                
		Data[3] = 0x00;        	        
		Data[4] = maxLen;	       

		for (i = 0; i < maxLen; i++)            
			Data[i+5] = ApduIn[i];        

		if(PerformTransmitAPDU(Data, sizeof(Data)))           
			return TRUE;        
		else            
			return FALSE;    
	}   

	//Write data to card    
	Data[0] = 0x80;            
	Data[1] = 0xD2;             
	Data[2] = RecNo;          
	Data[3] = 0x00;             
	Data[4] = DataLen;      

	for (i = 0; i < maxLen; i++)    
	{        
		if(sizeof(ApduIn) > i )        
		{            
			Data[i + 5] = ApduIn[i];        
		}       
		else        
		{            
			Data[i + 5] = 0x20;       
		}    
	}  

	if(PerformTransmitAPDU(Data, sizeof(Data)))       
		return TRUE;    
	else        
		return FALSE;
}

































void ReadCard(void) {

}

void WriteCard(void) {
	
}

void StatusCard(void) {

}

void PowerOnCard(void) {

}

void PowerResetCard(void) {

}

void SendAPDUCard(void) {


}


