#ifndef _EMV_CORE_H
#define _EMV_CORE_H

#ifndef STRUCT_PACK
#define STRUCT_PACK __attribute__((packed))
#endif

#ifndef u8
#define u8 unsigned char
#endif

#ifndef u16
#define u16 unsigned short
#endif

#ifndef u32
#define u32 unsigned int
#endif

#ifndef s8
#define s8  char
#endif

#ifndef s16
#define s16  short
#endif

#ifndef s32
#define s32  int
#endif

//����
enum
{
    LOCALE,  //0-����
    SUPPORT, //1-Ӣ��
};

//���׵��ں�����
#define KERNAL_CONTACT_EMV_PBOC         0       //�Ӵ�ʽEMV/PBOC
#define KERNAL_CONTACTLESS_EMV_PBOC     1       //�ǽ�EMV/PBOC
#define KERNAL_QPBOC                    2       //qPBOC

//qpboc�ֿ�����֤��ʽ
#define RD_CVM_NO 					0x00
#define RD_CVM_SIG 					0x10
#define RD_CVM_ONLINE_PIN 		    0x11

//���׽��
#define APPROVE_M                   0x00        //��׼
#define DECLINE_M                   0x01        //�ܾ�
#define ONLINE_M                    0xC8        //����

//_gtEmvCallback.EmvCbReferProc���������붨��
#define REFER_APPROVE               APPROVE_M       //�ο�������(ѡ����׼)
#define REFER_DENIAL                DECLINE_M       //�ο�������(ѡ��ܾ�)

//Ӧ��ѡ��ָʾ��DF01
#define PART_MATCH                  0
#define FULL_MATCH                  1

#define EMV_OPTIONS(ucOptions,bOffset)   ( ( (*(ucOptions+(bOffset-1)/8 ) ) >> ((bOffset-1)%8) )  &0x01 ) //�õ��ն˽���ѡ���־��
#define EMV_ENABLE_OPTIONS(ucOptions,bOffset) (	*(ucOptions+(bOffset-1)/8 ) |= 0x01<<((bOffset-1)%8) ) //��������һλ�ն˽���ѡ��
#define EMV_DISABLE_OPTIONS(ucOptions,bOffset) (	*(ucOptions+(bOffset-1)/8 ) &= (u8)( (0x7f7f<<((bOffset-1)%8)) >> (7-((bOffset-1)%8)) ) )////��ֹ����һλ�ն˽���ѡ�� bOffset��1��ʼ chengluo 2014.02.27 14:13

//�ն˽��׿�ѡ���ǿ������������֪ͨ���ĵ�,�����Ƕ�Ӧ��bit,��11Ϊ�ڶ�byte����bit
#define OFFSET_CARDHOLDER_NOT_PERFORM                           1 //�ֽ��ֵ��Ȧ�������ô�λ��ִ�гֿ�����֤
#define OFFSET_COMMON_CHAR_M                                    3
#define OFFSET_Multi_LANG_M                                     4
#define OFFSET_Partial_AID_M                                    5
#define OFFSET_Prefer_ORDER_M                                   6
#define OFFSET_Cardholder_CONFIRM_M                             7
#define OFFSET_PSE_SELET_M                                      8

#define OFFSET_amount_KNOWN_BEFORE_CVM_M                        11
#define OFFSET_FAILCVM_M                                        12
#define OFFSET_GetDataPINTC_M                                   13
#define OFFSET_PINByPass_M                                      14
#define OFFSET_default_DDOL_M                                   15
#define OFFSET_revocation_ISSUER_PK_M                           16

#define OFFSET_TerminalRisk_BasedOnAip_M                        19
#define OFFSET_Exception_File_M                                 20
#define OFFSET_TransLog_M                                       21
#define OFFSET_Velocity_Check_M                                 22
#define OFFSET_RandomTrans_SELECT_M                             23
#define OFFSET_Floor_LimitCheck_M                               24

#define OFFSET_CDA_requestOrnever_2ndGenerateAC_M               27
#define OFFSET_CDA_requestOrnever_1ndGenerateAC_M               28
#define OFFSET_Detect_CDA_Fail_BeforeTAAnalysis_M               29
#define OFFSET_SkipOrprocTACOrIAC_defaultForUnableToGoOnline_M  30
#define OFFSET_Process_DefaultAC_PriorOrAfter_1ndGenerateAC_M   31
#define OFFSET_Terminal_Action_Codes_M                          32

#define OFFSET_DefaultTDOL_M                                    34
#define OFFSET_OnlineCapture_M                                  35//���ô�λGAC��������֪ͨ,�������ʧ��������֪ͨ����
#define OFFSET_IssuerReferral_M                                 37
#define OFFSET_Advice_M                                         38
#define OFFSET_Force_Acceptance_M                               39
#define OFFSET_ForceOnline_M                                    40//��������(�������ֽ�����)�������ô�λǿ������

#define OFFSET_Internate_Date_Management_M                      42
#define OFFSET_issuer_script_GreaterThan128_M                   43
#define OFFSET_AccountType_Select_M                             44
#define OFFSET_MagstripeReader_First_M                          45
#define OFFSET_ICCAndMagstripe_Reader_Combined_M                46
#define OFFSET_AmountAndPIN_enter_AtTheSame_Keypad_M            47
#define OFFSET_Equipped_With_PINPAD_M                           48

#define OFFSET_Fallback_1stGAC_M                                54
#define OFFSET_Fallback_terminate_M                             55
#define OFFSET_Fallback_notselect_M                             56

typedef struct
{
	u8 ucAID[16];		        	//9F06 Ӧ��ID
	u8 ucAIDLen;                  	//     Ӧ��aid����
	u8 ucSelectIndicator;     		//DF01 Ӧ��ѡ��ָʾ����ASI��(=0����ƥ��,=1��ȫƥ��)
	u8 ucPriority;             		//87   Ӧ������ָʾ�� 1��û�гֿ���ȷ��Ӧ�ò���ѡ�� 0��û�гֿ���ȷ��Ӧ�ÿ���ѡ��
	u8 ucTargetPercentage;     		//DF17 ����ٷֱ�
	u8 ucMaxTargetPercentage;  		//DF16 ������ٷֱ�
	u8 ucTermFloor[4];        		//9F1B �ն�����޶�HEX
    u8 ucOnLinePINFlag;            	//DF18 �ն�����PIN֧������
	u32 uiThresholdValue;			//DF15 ���ѡ��ֵ
	u8 ucTACDefault[5];        		//DF11 ȱʡ
	u8 ucTACDenial[5];         		//DF13 �ܾ�
	u8 ucTACOnline[5];         		//DF12 ����
	u32 uiDdolLen;       			//     DDOL����
	u8 ucDdol[252];            		//DF14 ȱʡDDOL
	u32 uiTdolLen;       			//     TDOL����
	u8 ucTdol[252];            		//97   ȱʡTDOL
	u8 ucTermAVM[2];           		//9F09 Ӧ�ð汾��
	u8 ucRFTxnLmt[6];   			//DF20 �ǽӴ���д�������޶�bcd
	u8 ucRFFLmt[6];     			//DF19 �ǽӴ���д���ѻ�����޶�bcd
	u8 ucRFCVMLmt[6];       		//DF21 �ǽӶ�д���ֿ�����֤����CVM��������bcd
	u8 ECTranLmt[6];        		//9F7B �����ֽ��ն˽����޶�bcd
	u16 unCrc;						//	   crc
}STRUCT_PACK T_EMV_APP_LIST;

//��֤���Ĺ�Կ����_����ʱ�洢
typedef struct
{
	u8 ucRID[5];               		//9F06 ����֤���Ĺ�Կ����һ���ʶ��֤���ĵĹ�Կ
	u8 ucIndex;                		//9F22 ��֤���Ĺ�Կ����
	u8 ucHashIndicator;        		//DF06 ��֤���Ĺ�Կ��ʲ�㷨��ʶ
	u8 ucCAPKIndicator;        		//DF07 ��֤���Ĺ�Կ�㷨��ʶ
	u8 ucModulusLen;
	u8 ucModulus[248];         		//DF02 ��֤���Ĺ�Կģ   �䳤�����Ϊ248
	u8 ucExponentLen;
	u8 ucExponent[3];         		//DF04 ��֤���Ĺ�Կָ��  1��3
	u8 ucExpDate[3];           		//DF05 ��֤���Ĺ�Կ��Ч��(bcd yyyymmdd)
	u8 ucCheckSum[20];         		//DF03 ��֤���Ĺ�ԿУ��ֵsha1
	u16 unCrc;						//	   crc
}STRUCT_PACK T_EMV_TERM_CAPK;

//֤������б�_�洢_EMV/PBOC L2����ʹ��
typedef struct
{
	u8 ucRID[5];               		//9F06 ����֤���Ĺ�Կ����һ���ʶ��֤���ĵĹ�Կ
	u8 ucIndex;                		//9F22 ��֤���Ĺ�Կ����
	u8 ucCertiSerial[3];       		//     ֤�����к�
	u16 unCrc;						//	   crc
}STRUCT_PACK T_EMV_REVOCATIONLIST;

//�ն˲���_������֮ǰ(�����main()����)����һ��(���洢)
typedef struct
{
	u8 ucIFD[8+1];                  //9F1e �豸���к�,ASC��0x00����
	u8 ucMerchantCode[2];           //9F15 �̻������BCD
	u8 ucMerchantID[15+1];          //9F16 �̻���,Ӧ����0x00����
	u8 ucAcquirerID[6];        		//9F01 �յ���BCD
	u8 ucTermID[8+1];               //9F1C �ն˱�ʶ(�ն˺�),ASC��0x00����

	u8 ucTermType;				    //9F35 �ն�����
	u8 ucTermCapa[3];               //9F33 �ն�����
	u8 ucAdducTermCapa[5];          //9F40 �ն˸�������

	u8 ucTranRefCurrExp;		    //9F3d ���ײο�����ָ��
	u8 ucTranRefCurr[2];			//9F3c �ο����Ҵ���

	u8 ucTranCurrExp;			    //5F36 ���׻���ָ��
	u8 ucTerminalCountry[2];        //9F1A ���Ҵ���
	u8 ucTranCurrCode[2];			//5F2A ���׻��Ҵ���
	u8 ucMerchantNameLocation[40+1];//9F4E �̻�����ASC����0x00����

	u8 ucOptions[10];               //	   �ն˽��׿�ѡ���ǿ������������֪ͨ���ĵ�

	u8 ucPinpadType;				//	   =0����������̣�=1�����������
	u8 ucTermSMSupportIndicator;	//     �ն��Ƿ�֧��SM�㷨 =0��֧�� =1֧��

	u8 ucTermFLmtFlg;    			//	   �ǽӶ������Ƿ�֧���ն�����޶���9F1B (qPBOCһ��Ϊ1) =0����飬=1���
	u8 ucRFTxnLmtFlg;				//	   �ǽӶ������Ƿ�֧�ֽ����޶���DF20(qPBOCһ��Ϊ1) =0����飬=1���
	u8 ucRFFLmtFlg;					//	   �ǽӶ������Ƿ�֧���ѻ�����޶���DF19(qPBOCһ��Ϊ1) =0����飬=1���
	u8 ucRFCVMLmtFlg;   			//	   �ǽӶ������Ƿ�֧��CVMִ���޶���DF21(qPBOCһ��Ϊ1) =0����飬=1���

	u8 ucRFStatusCheckFlg;    		// 	   �ǽӶ������Ƿ�֧��״̬���(qPBOCһ��Ϊ0) =1����Ȩ���Ϊ1,��9F66Ҫ����������
	u8 ucRFZeroAmtNoAllowed;       	//	   �ǽӽ���0������(qPBOCһ��Ϊ0) =0����Ȩ���Ϊ0,��9F66Ҫ����������; =1����Ȩ��Ϊ0, ���ڲ�qVSDC��֧�ֱ�־��λ

	u8 ucPrintfDebugInfo;           //     ��ӡ���ڵ�����Ϣ =0����ӡ =1��ӡ
}STRUCT_PACK T_EMV_TERM_PARAM;

//���ײ���_������ǰ(����Ӧ��ѡ����)����(���洢)
typedef struct
{
	u8 ucTransKernalType; 			// 	   �������ߵ��ں�����(=0�Ӵ�ʽEMV/PBOC, =1�ǽ�EMV/PBOC,=2qPBOC)
	u8 ucEcTerminalSupportIndicator;//9F7A �����ֽ��ն�֧��ָʾ��,����EMV/PBOC�� =0����� =1�����ֽ� ,qPBOC��������
    u8 ucReaderTTQ[4];      		//9F66 �ն˽������ܣ�����qPBOC��

    u8 ucTransNo[4];      			//9F41 ������ˮ�� BCD���������ѽ��ף�����ѯ��������
	u8 ucTransDate[3];  		    //9A   �������� BCD YYMMDD
	u8 ucTransTime[3];  			//9F21 ����ʱ�� BCD HHMMS
    u8 ucAmountAuth[6];     		//9F02 ��Ȩ���(���׽��) BCD
    u8 ucAmountOther[6];    		//9F03 �������(���ֽ��) BCD

	u8 ucTransType;                 //9C   �������� һ��Ϊ0x00 ,����������0x14
}STRUCT_PACK T_EMV_TRANS_PARAM;

#ifndef MAX_RSA_MODULUS_LEN
#define MAX_RSA_MODULUS_LEN 248
typedef struct
{
    u16 unBits;                        //length in bits of modulus
    u8 ucModulus[MAX_RSA_MODULUS_LEN]; //modulus
    u8 ucExponent[3];                  //public exponent
}STRUCT_PACK T_RSA_PUBLIC_KEY;
#endif

//�������ش����붨��

//#define ICC_RESET_ERR               -1         //IC����λʧ��
//#define EMV_DENIAL                  -11        //�������ͷ��ؾܾ�

//#define EMV_NO_PINPAD               -13        //û��������̻���̲�����
//#define EMV_NO_PASSWORD             -14        //û��������û���������������
//#define EMV_NO_DATA                 -17        //ָ����Tagû������
//#define NO_TRANS_LOG                -19        //������־���
//#define EMV_RECORD_NOT_EXIST        -20        //��־��¼�Ų�����
//#define LOGITEM_NOTEXIST            -21

#define EMV_PARAM_ERR               -1         //EMV��������
#define ICC_CMD_ERR                 -2         //IC��ͨѶ����
#define ICC_BLOCK                   -3         //IC������
#define ICC_RSP_ERR                 -4         //IC����Ӧ����
#define EMV_APP_BLOCK               -5         //Ӧ������
#define EMV_NO_APP                  -6         //��Ƭû���ն�֧�ֵ�Ӧ��
#define EMV_USER_CANCEL             -7         //�û�ȡ����������
#define EMV_TIME_OUT                -8         //�û�������ʱ
#define EMV_DATA_ERR                -9         //��Ƭ���ݴ���
#define EMV_NOT_ACCEPT              -10        //���ײ�����
#define EMV_KEY_EXP                 -12        //��֤���Ĺ�Կ����Ч��
#define EMV_DATETIME_ERR            -13        //����ʱ�����
#define EMV_FILE_ERR                -14        //��дEMV�ļ�����
#define EMV_SUM_ERR                 -15        //��֤���Ĺ�ԿУ�����
#define EMV_NOT_FOUND               -16        //��EMV�ļ�û���ҵ���Ӧ�ļ�¼

#define EMV_NOT_MATCH               -18        //�����ݲ�ƥ��(��2�ŵĿ�����Tag:5A���ŵ�)
#define EMV_NO_TRANS_LOG            -19        //�޽�����־
#define EMV_LOG_ENTRY_NOT_EXIST     -20        //������־��ڲ�����


#define ICC_RSP_6985                -22        //GAC�п�Ƭ����6985, ��Ӧ�þ����Ƿ�fallback
#define EMV_EXCP_FILE               -23        //��Ƭ�������ն��쳣�ļ���
#define EMV_USE_CONTACT  		    -24        //ʹ������������н���
#define EMV_CARD_EXPIRED            -25        //��Ƭ����Ч��
#define EMV_TERMINATE    		    -26        //������ֹ
#define EMV_BALANCE_ERR    		    -27        //�õ����ʧ��


/********************************************************************
��������: ���׻ص�����_��EMV����ǰ����(Ҳ�ɿ�����ʼ��ʱ����һ��)
�������:
�������:
�� �� ֵ: =0 �ɹ�
          <0 ���󣬴���ķ���ֵ��ʹ�ñ�ͷ�ļ������붨�壬����������ο��ص�����˵��
�޸���Ϣ: 2014-09-26  �޳�  ����
********************************************************************/
typedef struct
{
    s32 (*EmvCbGetAppListNum)(void);//�õ�IC����������(Ӧ���б�)����
    s32 (*EmvCbGetCapkNum)(void);//�õ���֤���Ĺ�Կ��������
    s32 (*EmvCbGetRevocListNum)(void);//�õ���Կ�����б�����

    s32 (*EmvCbLoadAppListByIndex)(u8 ucIndex,T_EMV_APP_LIST *ptAppList);//���������ŵõ�IC����������(Ӧ���б�)
    s32 (*EmvCbLoadCapkByIndex)(u8 ucIndex, T_EMV_TERM_CAPK *ptTermCapk);//���������ŵõ���֤���Ĺ�Կ����
    s32 (*EmvCbLoadCapkByRIDCAPKIndex)(u8 *pucRID,u8 ucCAPKIndex,T_EMV_TERM_CAPK *ptTermCapk);//����RID�͹�Կ�����õ���֤���Ĺ�Կ����
    s32 (*EmvCbLoadRevocList)(u8 *pucRID,u8 ucCAPKIndex,u8 *pucCertiSerial);//����RID�͹�Կ�����õ���Կ�����б�

    s32 (*EmvCbExchangeApdu)(const u8 *pucSend,u32 uiSendLen,u8 *pucResp,u32 *puiRespLen);//����apdu,��Ӧapdu����
    s32 (*EmvCbGetPreferenceLanguage)(u8 *pucLanguagePrefer,u8 ucLen);//���� 5F2d��ѡ����pucLanguagePrefer �õ��ն����õ����������±꣨0--���ģ�1--english��
    s32 (*EmvCbGetRandNumberByNum)(u8 *pucRand,u8 ucLen); //��������̵õ�ָ���ֽڵ������
    s32 (*EmvCbMenuAppSel)(s32 iTryCnt, s8 *pcAppLabelList[], s32 iAppNum);//��ʾӦ�ñ�ǩ�б�Ҫ��ֿ���ѡ�� >=1ѡ��Ӧ���б�����(��1��ʼ) <0(EMV_USER_CANCEL,EMV_TIME_OUT��)
    s32 (*EmvCbCardholderConfirm)(s8 *pcAppLabel);//�ֿ���ȷ����ʾ��cAppLabelΪ��ʾ��Ӧ�ñ�ǩ������Ҫ��ʾΪ��
    s32 (*EmvCbShowHint)(s8 *pcStr,s32 iClearFlag,s32 iDisplayTime);//��ʾ�ַ���ucStr;��ʾiDisplayTime�루�ɰ������������,iDisplayTime=0���ȴ�ֱ�ӷ��أ�iDisplayTime=-1�а����ŷ���

    /********************************************************************
    ��������: ����PIN
    �������:   ucTryFlag ����PIN��־
                bit:8 =0����pin,     =1�ѻ�pin
                bit:1 =0�ѻ�����pin, =1�ѻ�����pin
                bit:4-7 �ѻ�pin���Դ���(��δʹ��)
                ucRandom:�ѻ�����pin,��IC���õ��������
    �������:   pucOutPIN:�õ���pin
    �� �� ֵ:
    �޸���Ϣ: 2014-09-26  �޳�  ����
    ********************************************************************/
    s32 (*EmvCbInputPIN)(u8 ucTryFlag, u8 *pucRandom, u8 *pucOutPIN);//����PIN

    s32 (*EmvCbCertVerify)(void);//�ֿ���֤����֤ =0�ɹ� <0(EMV_USER_CANCEL,EMV_TIME_OUT��)
    s32 (*EmvCbReferProc)(void); //�����з�����Ȩ��Ӧ��(39��Ϊ01��02)��ʾ�ο�(��׼��ܾ�)
    s32 (*EmvCbOnlineProc)(u8 *pucRspCode,u8 *pucIAuthData,u32 *puiIAuthDataLen, u8 *pucscript71,u32 *puiScriptLen71,u8 *pucScript72,u32 *puiScriptLen72);//�������ͽ��գ�������Ӧ��55������,RspCodeΪ39��Ӧ����,>0ΪӦ�ò������
    s32 (*EmvCbAdviceProc)(void);//GAC֮��, ����֪ͨ
    s32 (*EmvCbUnknowTLVData)(u32 uiTag, u8 *pucdata, u32 *puiLen);
    s32 (*EmvCbSearchExceptionList)(u8 *pucPAN,u32 uiPANLen,u8 ucPANSeq);//���Һ������������쳣�ļ����
    s32 (*EmvCbGetSumLogByPAN)(u8 *pucPAN,u32 uiPANLen,u32 *puiOutAmount);//�õ�һ�ſ�Ƭ�Ľ����ۼƽ������ж��ն�����޶�9f1b
    s32 (*EmvCbPrintSignature)(void);//��ӡǩ����
}STRUCT_PACK T_EMV_CALLBACK;

void sdkEMVSetCallBackFunc(T_EMV_CALLBACK *ptEmvCallback);//�ϲ�Ӧ�����ûص�������Emv�ں�(����ʱ��emv���׿�ʼǰ����һ��),ʹ�ں˿��Ե���

/********************************************************************
��������:
�������:
�������:
�� �� ֵ: =0 �ɹ�
          <0 ���󣬴���ķ���ֵ�μ���ͷ�ļ������붨�壬����������ο����庯��˵��
�޸���Ϣ: 2014-09-26  �޳�  ����
********************************************************************/

void sdkEmvKernelVersion(s8 *pcStrVer);//�õ�EMV�ں˰汾��

s32 sdkEmvVerifyCAPK(T_EMV_TERM_CAPK *ptTermCapk);//��֤���Ĺ�ԿУ��

//emv����
s32 sdkEmvAppSelect(void);//Ӧ��ѡ��
s32 sdkEmvAppInit(void);//Ӧ�ó�ʼ��(GPO)
s32 sdkEmvReadAppData(void);//��Ӧ������
s32 sdkEmvOfflineDataAuth(void);//�ѻ�������֤
s32 sdkEmvProcessRestrictions(void);//��������
s32 sdkEmvCardholderVerification(void);//�ֿ�����֤
s32 sdkEmvTerminalRiskManagement(void);//�ն˷��չ���
s32 sdkEmvTerminalAndCardActionAnalysis(void);//�ն���Ϊ����
s32 sdkEmvOnlineProcessing(void);//��������
s32 sdkEmvGetTransResult(void);//�õ����׽��

//qpbocר��
s32 sdkEmvQGetCVMType(void);//�ѻ�������֤���׽��Ϊ��������ͨ���˺����õ��ֿ�����֤��ʽ
s32 skdEmvQTrans(u8 *pucBalance,u8 *pucTransResult,u8 *pucCVMType);//QPBOC������������,�罻�׽��Ϊ�����������pucCVMTypeִ��CVM
s32 skdEmvQBalanceQuery(u8 *pucTransDate,u8 *pucBalance);//QPBOC����ѯBCD(6byte)��������,��ڽ�������(9A   �������� BCD YYMMDD)

//emv��������
s32 skdEmvTransSimple(u8 OfflineDataAuthFlag);//EMV�������̣�=0�ߵ���Ӧ������,=1�ߵ��ѻ�������֤(�ѻ�������֤ʧ�ܷ��ش���)
s32 sdkEmvECBalanceQuery(u8 ucDoubleFlag,u8 *pucBalance1,u8 *pucBalance1code,u8 *pucBalance2,u8 *pucBalance2code);//�������̣�˫�ҵ����ֽ����BCD(6byte)��ѯ;ucDoubleFlag=2(˫��),=1(����);��ΪucDoubleFlag=2ʱ,��Ƭֻ��һ�ֱ�ʱ���᷵�ش��󣬵�pucBalance1,pucBalance1Code�᷵�أ�pucBalance2Code����"\x00\x00"
/********************************************************************
��������: ��ȡ���н�����־��¼(��������)
�������:
          *pucLogFormat: ������־��ʽ(���255Byte)
          *pucRecord:��־��¼(���255*10Byte)
�������:
�� �� ֵ: *pucRecordNum ��������־�ܼ�¼��
�޸���Ϣ: 2014-10-07  �޳�  ����
********************************************************************/
s32 sdkEmvGetTransLog(u8 *pucRecordNum,u8 *pucLogFormat,u8 *pucRecord);

//����apdu�õ�����
s32 sdkEmvGetData(u8 ucP1,u8 ucP2,u8 *pucLen,u8 *pucOutdata,u8 *pucStatus);//����get data apdu
s32 sdkEmvGetECBalance(u8 *pucBalance);//�����ֽ����BCD(6byte)��ѯ ����get data(9F79) apdu

//�õ�����emv����
s32 sdkEmvGetTVR(u8 *pucTVR);//�õ�TVR
s32 sdkEmvGetTSI(u8 *pucTSI);//�õ�TSI
s32 sdkEmvGetTLVData(u32 uiTag,u8 *pcDataOut,u32 *puiDataOutLen);//�õ�һ��tag������
s32 sdkEmvSetTLVData(u32 uiTag,u8 *pcDataIn,u32 uiDataInLen);//����һ��tag���ݵ���emv�ں�
s32 sdkEmvGetScriptResult(u8 *pucResult, u32 *puiResultLen);//�õ��ű�������
s32 sdkEmvGetTrack2AndPAN(u8 *pucStrTrack2,u8 *pucStrPAN);//��ȡ���ŵ���Ч����(ASC),���˺�(ASC)
s32 sdkEmvGetPAN(u8 *pucPAN,u32 *puiPANLen,u8 *pucPANSeq);//�õ����˺�(BCD,������'F'),���˺����к�(Ӧ�����˺����к�û�У�ֱ������Ϊ0),����QPBOC������
s32 sdkEmvGetGACECBalance(u8 *pucBalance);//�õ�GAC���صĵ����ֽ����

u8 *sdkEmvSeparateTLV(u8 *pucTLVData,u32 *puiTag,u32 *puiOutDataLen);//����tlv���ݣ��õ�������tlv����ָ�룬tag������
u32 sdkEmvPackageTLV(u32 uiTag,u8 *pucData,u32 uiDataLen,u8 *pucOutTLVData);//����Tag,Data,DataLen�����ΪTLV�ṹ������,����TLV�����ܳ�(��ֻ������(һ)�ֽ�Tag,���Գ���Ϊ0,����0xFF��TAG)

//���ϲ�Ӧ�õõ�emv�ں˲���ָ��,ʹ���������
T_EMV_TERM_PARAM *sdkEmvGetTermParam(void);//�õ��ն˲���ָ��
T_EMV_TRANS_PARAM *sdkEmvGetTransParam(void);//�õ����ײ���ָ��


#endif

