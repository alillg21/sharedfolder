#include "Global.h"

s32 DemoTransaksi(void)
{ 
	if(!GetCardData())
		return 0;
	
	if(!compareFinger())
		return 0;

	return 1;
}

s32 compareFinger()
{
	T_SDK_PT_BIR 	tBir;
	T_SDK_PT_BIR 	*pNewTemplate;
	T_SDK_PT_BIR 	*pFingerTemp;
	s32 				iRet, uiLen;
	
	memset(&tBir, 0, sizeof(T_SDK_PT_BIR));
	pNewTemplate = &tBir;
	iRet = sdkFPEnroll(&pNewTemplate);
	
	pFingerTemp = (T_SDK_PT_BIR*)malloc(0x800);
	uiLen = pNewTemplate->Header.Length;
	memcpy(pFingerTemp, pNewTemplate, uiLen);
	iRet = sdkFPVerify(&pFingerTemp);
	
	return 1;
}

s32 GetCardData()
{
	u8 		**arr;
	s32 		size;

	if(!initialize())
		return 0;
	
	if(!selectFile(0xAA, 0x10))        
		return 0;   
	
	if(!readRecord(0x00, 0x18))       
		return 0;
	else
	{
		size = explode(&arr, pbRecvBuffer, '#');  
		strcpy(nik, arr[0]);
		strcpy(name, arr[1]);
		strcpy(saldo, arr[2]);
		strcpy(FingerData, arr[3]);
		
		return 1;
	}
}

int UpdateCardData()
{
	u8		tempData[2000];

	if(!initialize())
		return 0;
	
	if(!selectFile(0xAA, 0x10))        
		return 0;    
	
	if(!writeRecord(0x00,0x00,0x15,0x15, (u8*)tempData))
		return 0;

	return 1;
}





