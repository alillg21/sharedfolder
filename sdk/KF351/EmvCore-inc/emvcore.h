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

//语言
enum
{
    LOCALE,  //0-中文
    SUPPORT, //1-英文
};

//交易的内核类型
#define KERNAL_CONTACT_EMV_PBOC         0       //接触式EMV/PBOC
#define KERNAL_CONTACTLESS_EMV_PBOC     1       //非接EMV/PBOC
#define KERNAL_QPBOC                    2       //qPBOC

//qpboc持卡人认证方式
#define RD_CVM_NO 					0x00
#define RD_CVM_SIG 					0x10
#define RD_CVM_ONLINE_PIN 		    0x11

//交易结果
#define APPROVE_M                   0x00        //批准
#define DECLINE_M                   0x01        //拒绝
#define ONLINE_M                    0xC8        //联机

//_gtEmvCallback.EmvCbReferProc函数返回码定义
#define REFER_APPROVE               APPROVE_M       //参考返回码(选择批准)
#define REFER_DENIAL                DECLINE_M       //参考返回码(选择拒绝)

//应用选择指示符DF01
#define PART_MATCH                  0
#define FULL_MATCH                  1

#define EMV_OPTIONS(ucOptions,bOffset)   ( ( (*(ucOptions+(bOffset-1)/8 ) ) >> ((bOffset-1)%8) )  &0x01 ) //得到终端交易选项标志，
#define EMV_ENABLE_OPTIONS(ucOptions,bOffset) (	*(ucOptions+(bOffset-1)/8 ) |= 0x01<<((bOffset-1)%8) ) //开启其中一位终端交易选项
#define EMV_DISABLE_OPTIONS(ucOptions,bOffset) (	*(ucOptions+(bOffset-1)/8 ) &= (u8)( (0x7f7f<<((bOffset-1)%8)) >> (7-((bOffset-1)%8)) ) )////禁止其中一位终端交易选项 bOffset从1开始 chengluo 2014.02.27 14:13

//终端交易可选项，如强制联机，上送通知报文等,以下是对应的bit,如11为第二byte第三bit
#define OFFSET_CARDHOLDER_NOT_PERFORM                           1 //现金充值，圈存类设置此位不执行持卡人验证
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
#define OFFSET_OnlineCapture_M                                  35//设置此位GAC返回请求通知,如果联机失败则上送通知报文
#define OFFSET_IssuerReferral_M                                 37
#define OFFSET_Advice_M                                         38
#define OFFSET_Force_Acceptance_M                               39
#define OFFSET_ForceOnline_M                                    40//非消费类(含电子现金消费)交易设置此位强制联机

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
	u8 ucAID[16];		        	//9F06 应用ID
	u8 ucAIDLen;                  	//     应用aid长度
	u8 ucSelectIndicator;     		//DF01 应用选择指示符（ASI）(=0部分匹配,=1完全匹配)
	u8 ucPriority;             		//87   应用优先指示器 1：没有持卡人确认应用不能选择 0：没有持卡人确认应用可以选择
	u8 ucTargetPercentage;     		//DF17 随机百分比
	u8 ucMaxTargetPercentage;  		//DF16 随机最大百分比
	u8 ucTermFloor[4];        		//9F1B 终端最低限额HEX
    u8 ucOnLinePINFlag;            	//DF18 终端联机PIN支持能力
	u32 uiThresholdValue;			//DF15 随机选择阀值
	u8 ucTACDefault[5];        		//DF11 缺省
	u8 ucTACDenial[5];         		//DF13 拒绝
	u8 ucTACOnline[5];         		//DF12 联机
	u32 uiDdolLen;       			//     DDOL长度
	u8 ucDdol[252];            		//DF14 缺省DDOL
	u32 uiTdolLen;       			//     TDOL长度
	u8 ucTdol[252];            		//97   缺省TDOL
	u8 ucTermAVM[2];           		//9F09 应用版本号
	u8 ucRFTxnLmt[6];   			//DF20 非接触读写器交易限额bcd
	u8 ucRFFLmt[6];     			//DF19 非接触读写器脱机最低限额bcd
	u8 ucRFCVMLmt[6];       		//DF21 非接读写器持卡人验证方法CVM所需限制bcd
	u8 ECTranLmt[6];        		//9F7B 电子现金终端交易限额bcd
	u16 unCrc;						//	   crc
}STRUCT_PACK T_EMV_APP_LIST;

//认证中心公钥参数_下载时存储
typedef struct
{
	u8 ucRID[5];               		//9F06 与认证中心公钥索引一起标识认证中心的公钥
	u8 ucIndex;                		//9F22 认证中心公钥索引
	u8 ucHashIndicator;        		//DF06 认证中心公钥哈什算法标识
	u8 ucCAPKIndicator;        		//DF07 认证中心公钥算法标识
	u8 ucModulusLen;
	u8 ucModulus[248];         		//DF02 认证中心公钥模   变长，最大为248
	u8 ucExponentLen;
	u8 ucExponent[3];         		//DF04 认证中心公钥指数  1或3
	u8 ucExpDate[3];           		//DF05 认证中心公钥有效期(bcd yyyymmdd)
	u8 ucCheckSum[20];         		//DF03 认证中心公钥校验值sha1
	u16 unCrc;						//	   crc
}STRUCT_PACK T_EMV_TERM_CAPK;

//证书回收列表_存储_EMV/PBOC L2测试使用
typedef struct
{
	u8 ucRID[5];               		//9F06 与认证中心公钥索引一起标识认证中心的公钥
	u8 ucIndex;                		//9F22 认证中心公钥索引
	u8 ucCertiSerial[3];       		//     证书序列号
	u16 unCrc;						//	   crc
}STRUCT_PACK T_EMV_REVOCATIONLIST;

//终端参数_做交易之前(最好在main()函数)设置一次(不存储)
typedef struct
{
	u8 ucIFD[8+1];                  //9F1e 设备序列号,ASC以0x00结束
	u8 ucMerchantCode[2];           //9F15 商户分类号BCD
	u8 ucMerchantID[15+1];          //9F16 商户号,应用以0x00结束
	u8 ucAcquirerID[6];        		//9F01 收单行BCD
	u8 ucTermID[8+1];               //9F1C 终端标识(终端号),ASC以0x00结束

	u8 ucTermType;				    //9F35 终端类型
	u8 ucTermCapa[3];               //9F33 终端性能
	u8 ucAdducTermCapa[5];          //9F40 终端附加性能

	u8 ucTranRefCurrExp;		    //9F3d 交易参考货币指数
	u8 ucTranRefCurr[2];			//9F3c 参考货币代码

	u8 ucTranCurrExp;			    //5F36 交易货币指数
	u8 ucTerminalCountry[2];        //9F1A 国家代码
	u8 ucTranCurrCode[2];			//5F2A 交易货币代码
	u8 ucMerchantNameLocation[40+1];//9F4E 商户名，ASC码以0x00结束

	u8 ucOptions[10];               //	   终端交易可选项，如强制联机，上送通知报文等

	u8 ucPinpadType;				//	   =0内置密码键盘，=1外置密码键盘
	u8 ucTermSMSupportIndicator;	//     终端是否支持SM算法 =0不支持 =1支持

	u8 ucTermFLmtFlg;    			//	   非接读卡器是否支持终端最低限额检查9F1B (qPBOC一般为1) =0不检查，=1检查
	u8 ucRFTxnLmtFlg;				//	   非接读卡器是否支持交易限额检查DF20(qPBOC一般为1) =0不检查，=1检查
	u8 ucRFFLmtFlg;					//	   非接读卡器是否支持脱机最低限额检查DF19(qPBOC一般为1) =0不检查，=1检查
	u8 ucRFCVMLmtFlg;   			//	   非接读卡器是否支持CVM执行限额检查DF21(qPBOC一般为1) =0不检查，=1检查

	u8 ucRFStatusCheckFlg;    		// 	   非接读卡器是否支持状态检查(qPBOC一般为0) =1若授权金额为1,则9F66要求联机密文
	u8 ucRFZeroAmtNoAllowed;       	//	   非接交易0金额不允许(qPBOC一般为0) =0若授权金额为0,则9F66要求联机密文; =1若授权金为0, 则内部qVSDC不支持标志置位

	u8 ucPrintfDebugInfo;           //     打印串口调试信息 =0不打印 =1打印
}STRUCT_PACK T_EMV_TERM_PARAM;

//交易参数_做交易前(调用应用选择函数)设置(不存储)
typedef struct
{
	u8 ucTransKernalType; 			// 	   本交易走的内核类型(=0接触式EMV/PBOC, =1非接EMV/PBOC,=2qPBOC)
	u8 ucEcTerminalSupportIndicator;//9F7A 电子现金终端支持指示器,用于EMV/PBOC中 =0借贷记 =1电子现金 ,qPBOC不用设置
    u8 ucReaderTTQ[4];      		//9F66 终端交易性能，用于qPBOC中

    u8 ucTransNo[4];      			//9F41 交易流水号 BCD，用于消费交易，余额查询不用设置
	u8 ucTransDate[3];  		    //9A   交易日期 BCD YYMMDD
	u8 ucTransTime[3];  			//9F21 交易时间 BCD HHMMS
    u8 ucAmountAuth[6];     		//9F02 授权金额(交易金额) BCD
    u8 ucAmountOther[6];    		//9F03 其他金额(返现金额) BCD

	u8 ucTransType;                 //9C   交易类型 一般为0x00 ,返现请设置0x14
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

//函数返回错误码定义

//#define ICC_RESET_ERR               -1         //IC卡复位失败
//#define EMV_DENIAL                  -11        //密文类型返回拒绝

//#define EMV_NO_PINPAD               -13        //没有密码键盘或键盘不可用
//#define EMV_NO_PASSWORD             -14        //没有密码或用户忽略了密码输入
//#define EMV_NO_DATA                 -17        //指定的Tag没有数据
//#define NO_TRANS_LOG                -19        //交易日志入口
//#define EMV_RECORD_NOT_EXIST        -20        //日志记录号不存在
//#define LOGITEM_NOTEXIST            -21

#define EMV_PARAM_ERR               -1         //EMV参数错误
#define ICC_CMD_ERR                 -2         //IC卡通讯错误
#define ICC_BLOCK                   -3         //IC卡锁卡
#define ICC_RSP_ERR                 -4         //IC卡响应错误
#define EMV_APP_BLOCK               -5         //应用已锁
#define EMV_NO_APP                  -6         //卡片没有终端支持的应用
#define EMV_USER_CANCEL             -7         //用户取消操作或交易
#define EMV_TIME_OUT                -8         //用户操作超时
#define EMV_DATA_ERR                -9         //卡片数据错误
#define EMV_NOT_ACCEPT              -10        //交易不接受
#define EMV_KEY_EXP                 -12        //认证中心公钥过有效期
#define EMV_DATETIME_ERR            -13        //日期时间错误
#define EMV_FILE_ERR                -14        //读写EMV文件错误
#define EMV_SUM_ERR                 -15        //认证中心公钥校验错误
#define EMV_NOT_FOUND               -16        //读EMV文件没有找到相应的记录

#define EMV_NOT_MATCH               -18        //两数据不匹配(如2磁的卡号与Tag:5A卡号等)
#define EMV_NO_TRANS_LOG            -19        //无交易日志
#define EMV_LOG_ENTRY_NOT_EXIST     -20        //交易日志入口不存在


#define ICC_RSP_6985                -22        //GAC中卡片回送6985, 由应用决定是否fallback
#define EMV_EXCP_FILE               -23        //卡片出现在终端异常文件中
#define EMV_USE_CONTACT  		    -24        //使用其他界面进行交易
#define EMV_CARD_EXPIRED            -25        //卡片过有效期
#define EMV_TERMINATE    		    -26        //交易终止
#define EMV_BALANCE_ERR    		    -27        //得到余额失败


/********************************************************************
函数功能: 交易回调函数_做EMV交易前设置(也可开机初始化时设置一次)
输入参数:
输出参数:
返 回 值: =0 成功
          <0 错误，错误的返回值请使用本头文件错误码定义，如有特殊请参考回调函数说明
修改信息: 2014-09-26  罗成  创建
********************************************************************/
typedef struct
{
    s32 (*EmvCbGetAppListNum)(void);//得到IC卡其他参数(应用列表)总数
    s32 (*EmvCbGetCapkNum)(void);//得到认证中心公钥参数总数
    s32 (*EmvCbGetRevocListNum)(void);//得到公钥回收列表总数

    s32 (*EmvCbLoadAppListByIndex)(u8 ucIndex,T_EMV_APP_LIST *ptAppList);//根据索引号得到IC卡其他参数(应用列表)
    s32 (*EmvCbLoadCapkByIndex)(u8 ucIndex, T_EMV_TERM_CAPK *ptTermCapk);//根据索引号得到认证中心公钥参数
    s32 (*EmvCbLoadCapkByRIDCAPKIndex)(u8 *pucRID,u8 ucCAPKIndex,T_EMV_TERM_CAPK *ptTermCapk);//根据RID和公钥索引得到认证中心公钥参数
    s32 (*EmvCbLoadRevocList)(u8 *pucRID,u8 ucCAPKIndex,u8 *pucCertiSerial);//根据RID和公钥索引得到公钥回收列表

    s32 (*EmvCbExchangeApdu)(const u8 *pucSend,u32 uiSendLen,u8 *pucResp,u32 *puiRespLen);//发送apdu,响应apdu处理
    s32 (*EmvCbGetPreferenceLanguage)(u8 *pucLanguagePrefer,u8 ucLen);//根据 5F2d首选语言pucLanguagePrefer 得到终端设置的语言数组下标（0--中文，1--english）
    s32 (*EmvCbGetRandNumberByNum)(u8 *pucRand,u8 ucLen); //从密码键盘得到指定字节的随机数
    s32 (*EmvCbMenuAppSel)(s32 iTryCnt, s8 *pcAppLabelList[], s32 iAppNum);//显示应用标签列表，要求持卡人选择 >=1选择应用列表的序号(从1开始) <0(EMV_USER_CANCEL,EMV_TIME_OUT等)
    s32 (*EmvCbCardholderConfirm)(s8 *pcAppLabel);//持卡人确认提示，cAppLabel为显示的应用标签，不需要显示为空
    s32 (*EmvCbShowHint)(s8 *pcStr,s32 iClearFlag,s32 iDisplayTime);//显示字符串ucStr;显示iDisplayTime秒（可按任意键）返回,iDisplayTime=0不等待直接返回，iDisplayTime=-1有按键才返回

    /********************************************************************
    函数功能: 输入PIN
    输入参数:   ucTryFlag 输入PIN标志
                bit:8 =0联机pin,     =1脱机pin
                bit:1 =0脱机明文pin, =1脱机密文pin
                bit:4-7 脱机pin重试次数(暂未使用)
                ucRandom:脱机密文pin,从IC卡得到的随机数
    输出参数:   pucOutPIN:得到的pin
    返 回 值:
    修改信息: 2014-09-26  罗成  创建
    ********************************************************************/
    s32 (*EmvCbInputPIN)(u8 ucTryFlag, u8 *pucRandom, u8 *pucOutPIN);//输入PIN

    s32 (*EmvCbCertVerify)(void);//持卡人证件验证 =0成功 <0(EMV_USER_CANCEL,EMV_TIME_OUT等)
    s32 (*EmvCbReferProc)(void); //发卡行返回授权响应码(39域为01或02)显示参考(批准或拒绝)
    s32 (*EmvCbOnlineProc)(u8 *pucRspCode,u8 *pucIAuthData,u32 *puiIAuthDataLen, u8 *pucscript71,u32 *puiScriptLen71,u8 *pucScript72,u32 *puiScriptLen72);//联机发送接收，解析响应的55域数据,RspCode为39域应答码,>0为应用层错误码
    s32 (*EmvCbAdviceProc)(void);//GAC之后, 请求通知
    s32 (*EmvCbUnknowTLVData)(u32 uiTag, u8 *pucdata, u32 *puiLen);
    s32 (*EmvCbSearchExceptionList)(u8 *pucPAN,u32 uiPANLen,u8 ucPANSeq);//查找黑名单，用于异常文件检查
    s32 (*EmvCbGetSumLogByPAN)(u8 *pucPAN,u32 uiPANLen,u32 *puiOutAmount);//得到一张卡片的交易累计金额，用于判断终端最低限额9f1b
    s32 (*EmvCbPrintSignature)(void);//打印签名线
}STRUCT_PACK T_EMV_CALLBACK;

void sdkEMVSetCallBackFunc(T_EMV_CALLBACK *ptEmvCallback);//上层应用设置回调函数到Emv内核(启动时或emv交易开始前设置一次),使内核可以调用

/********************************************************************
函数功能:
输入参数:
输出参数:
返 回 值: =0 成功
          <0 错误，错误的返回值参见本头文件错误码定义，如有特殊请参考具体函数说明
修改信息: 2014-09-26  罗成  创建
********************************************************************/

void sdkEmvKernelVersion(s8 *pcStrVer);//得到EMV内核版本号

s32 sdkEmvVerifyCAPK(T_EMV_TERM_CAPK *ptTermCapk);//认证中心公钥校验

//emv交易
s32 sdkEmvAppSelect(void);//应用选择
s32 sdkEmvAppInit(void);//应用初始化(GPO)
s32 sdkEmvReadAppData(void);//读应用数据
s32 sdkEmvOfflineDataAuth(void);//脱机数据认证
s32 sdkEmvProcessRestrictions(void);//处理限制
s32 sdkEmvCardholderVerification(void);//持卡人验证
s32 sdkEmvTerminalRiskManagement(void);//终端风险管理
s32 sdkEmvTerminalAndCardActionAnalysis(void);//终端行为分析
s32 sdkEmvOnlineProcessing(void);//联机处理
s32 sdkEmvGetTransResult(void);//得到交易结果

//qpboc专用
s32 sdkEmvQGetCVMType(void);//脱机数据认证后交易结果为联机，则通过此函数得到持卡人认证方式
s32 skdEmvQTrans(u8 *pucBalance,u8 *pucTransResult,u8 *pucCVMType);//QPBOC完整交易流程,如交易结果为联机，请根据pucCVMType执行CVM
s32 skdEmvQBalanceQuery(u8 *pucTransDate,u8 *pucBalance);//QPBOC余额查询BCD(6byte)完整流程,入口交易日期(9A   交易日期 BCD YYMMDD)

//emv交易流程
s32 skdEmvTransSimple(u8 OfflineDataAuthFlag);//EMV简易流程，=0走到读应用数据,=1走到脱机数据认证(脱机数据认证失败返回错误)
s32 sdkEmvECBalanceQuery(u8 ucDoubleFlag,u8 *pucBalance1,u8 *pucBalance1code,u8 *pucBalance2,u8 *pucBalance2code);//完整流程，双币电子现金余额BCD(6byte)查询;ucDoubleFlag=2(双币),=1(单币);当为ucDoubleFlag=2时,卡片只有一种币时，会返回错误，但pucBalance1,pucBalance1Code会返回，pucBalance2Code返回"\x00\x00"
/********************************************************************
函数功能: 读取所有交易日志记录(完整流程)
输入参数:
          *pucLogFormat: 交易日志格式(最大255Byte)
          *pucRecord:日志记录(最大255*10Byte)
输出参数:
返 回 值: *pucRecordNum 读出的日志总记录数
修改信息: 2014-10-07  罗成  创建
********************************************************************/
s32 sdkEmvGetTransLog(u8 *pucRecordNum,u8 *pucLogFormat,u8 *pucRecord);

//发送apdu得到数据
s32 sdkEmvGetData(u8 ucP1,u8 ucP2,u8 *pucLen,u8 *pucOutdata,u8 *pucStatus);//发送get data apdu
s32 sdkEmvGetECBalance(u8 *pucBalance);//电子现金余额BCD(6byte)查询 发送get data(9F79) apdu

//得到常用emv数据
s32 sdkEmvGetTVR(u8 *pucTVR);//得到TVR
s32 sdkEmvGetTSI(u8 *pucTSI);//得到TSI
s32 sdkEmvGetTLVData(u32 uiTag,u8 *pcDataOut,u32 *puiDataOutLen);//得到一个tag的数据
s32 sdkEmvSetTLVData(u32 uiTag,u8 *pcDataIn,u32 uiDataInLen);//设置一个tag数据到到emv内核
s32 sdkEmvGetScriptResult(u8 *pucResult, u32 *puiResultLen);//得到脚本处理结果
s32 sdkEmvGetTrack2AndPAN(u8 *pucStrTrack2,u8 *pucStrPAN);//获取二磁道等效数据(ASC),主账号(ASC)
s32 sdkEmvGetPAN(u8 *pucPAN,u32 *puiPANLen,u8 *pucPANSeq);//得到主账号(BCD,奇数后补'F'),主账号序列号(应用主账号序列号没有，直接设置为0),用于QPBOC黑名单
s32 sdkEmvGetGACECBalance(u8 *pucBalance);//得到GAC返回的电子现金余额

u8 *sdkEmvSeparateTLV(u8 *pucTLVData,u32 *puiTag,u32 *puiOutDataLen);//解析tlv数据，得到解析后tlv数据指针，tag，长度
u32 sdkEmvPackageTLV(u32 uiTag,u8 *pucData,u32 uiDataLen,u8 *pucOutTLVData);//根据Tag,Data,DataLen，打包为TLV结构的数据,返回TLV数据总长(暂只处理两(一)字节Tag,忽略长度为0,大于0xFF的TAG)

//让上层应用得到emv内核参数指针,使其可以设置
T_EMV_TERM_PARAM *sdkEmvGetTermParam(void);//得到终端参数指针
T_EMV_TRANS_PARAM *sdkEmvGetTransParam(void);//得到交易参数指针


#endif

