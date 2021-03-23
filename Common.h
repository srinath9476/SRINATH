
union WORD1_DEF
{
    struct {
        char    b0:1;
        char    b1:1;
        char    b2:1;
        char    b3:1;
        char    b4:1;
        char    b5:1;
        char    b6:1;
        char    b7:1;
        char    b8:1;
        char    b9:1;
        char    b10:1;
        char    b11:1;
        char    b12:1;
        char    b13:1;
        char    b14:1;
        char    b15:1;
    } bit;
    struct {
        unsigned char   low;                            /* low  8 bit */
        unsigned char   high;                           /* high 8 bit */
    } byte;
    unsigned short  word;
};


union BYTE1_DEF
{
    struct {
        char    b0:1;
        char    b1:1;
        char    b2:1;
        char    b3:1;
        char    b4:1;
        char    b5:1;
        char    b6:1;
        char    b7:1;
    } bit;
	unsigned short  value;
};

/******************************************************************************
Macro Defines
******************************************************************************/
/* Define base clock frequencies	*/
#define	f1_CLK_SPEED	32000000
#define	fc_CLK_SPEED	32768

#define BAUD_RATE	19200

//#define LED_PORT		p7
//#define LED_PORT_DIR	pd7

/* General macros	*/
#define LED_ON			0
#define LED_OFF			1
#define LEDS_ON			0x00
#define LEDS_OFF		0x0F
#define SET_BIT_HIGH	1
#define SET_BIT_LOW		0
#define SET_BYTE_HIGH	0xFF
#define SET_BYTE_LOW	0x00
#define TRUE			1
#define FALSE			0

#define IODirection		p1_6
#define Latch			p1_7

///|********************Changed************************//

#define DataAddress		p0
#define DataAddrDir		pd0

//#define INDataAddress		p0
//#define INDataAddrDir		pd0

#define OUTDataAddress	p2
#define OUTDataAddrDir	pd2

//#define SevAdd p9
//#define SevDir pd9

#define ModuleAddress	p10
#define ModuleAddDir	pd10

///********************Changed***********************|//


/* Port bit to toggle for flashing the LEDs */
#define LED_BIT			0x0F

/* Interrupt control (i.e. Enable / Disable) */
#define ENABLE_IRQ   	{_asm(" FSET I");}
#define DISABLE_IRQ		{_asm(" FCLR I");}

/* 1 cycle delay	*/
#define	NOP()			{_asm("nop");}


/* Port pins having LEDs connected	*/
#define LED2			p3_3
#define LED3			p3_4
#define LED4			p3_7
#define LED5			p4_0
#define LED6			p3_5

#define LED7			p3_6
#define LED8			p4_1
#define LED9			p4_2
#define LED10			p4_3
#define LED11			p4_4

#define LED2_DIR		pd3_3
#define LED3_DIR		pd3_4
#define LED4_DIR		pd3_7
#define LED5_DIR		pd4_0
#define LED6_DIR		pd3_5

#define LED7_DIR		pd3_6
#define LED8_DIR		pd4_1
#define LED9_DIR		pd4_2
#define LED10_DIR		pd4_3
#define LED11_DIR		pd4_4

//|***************Changed ***************************//

#define MAX485_EN 				p5_6
#define PC_LDU_CAL 			p8_2
#define DIRECT_LDU_CAL      p8_3

#define MAX485_EN_DIR         pd5_6
#define PC_LDU_CAL_DIR	   pd8_2
#define DIRECT_LDU_CAL_DIR pd8_3

#define KEY1     p5_1
#define KEY1DIR  pd5_1

#define KEY2	 p5_2
#define KEY2DIR  pd5_2

#define KEY3     p5_3
#define KEY3DIR  pd5_3

#define KEY4	 p5_4
#define KEY4DIR  pd5_4
/*
#define KEY1     p5_1
#define KEY1DIR  pd5_1

#define KEY2	 p5_1
#define KEY2	 p5_1
*/

/*
#define KEY1    p5_1
#define KEY1DIR  pd5_1
*/
/*
#define KEY2Decoder	 p5_2
#define KEY3Decoder	 p5_3

#define KEY1DecodeDIR  pd5_1
#define KEY2DecodeDIR  pd5_2
#define KEY3DecodeDIR  pd5_3
*/

#define KEYDecoder     p4				// P4 is used to select directly to 138
#define KEY1DecodeDIR  pd4

// need to comment 

#define Portr   0x07
/*
#define KEYDecoder     p5				// p5 is used to select segment through Keypad Connection
										// just for checki
#define KEY1DecodeDIR  pd5
*/

/***Changed For I2C SDA and SCL  *********************/

#define SCLK				p4_6
#define SCL					p4_6
#define DIR_SCLK_OP			pd4_6=1

#define SDA					p4_7
#define SDA1				p4_7


#define DIR_SDA			pd4_7

#define SDA_HI				SDA=1
#define SDA_LO				SDA=0

#define SCL_HI				SCL=1
#define SCL_LO				SCL=0

#define MSDELAY				5000
#define BYTESWRITTEN		26




/*******Changed For RTC communication data Processing**************/

/*void ReadRTC(void);
void WriteRTC(void);

void ReadDateNTime(void);
*/

//void delay_ms1(unsigned int ms_count);
//void IsrTimer1(void);
/*
unsigned char TimeString[8];
unsigned char DateString[10];
*/
/*
unsigned char RTC_ARR[9];
unsigned long MSTimer1;
*/
/*
unsigned char RTC_ARR[9];
#define RTC_ID 				0xD0

#define SECONDS 			RTC_ARR[0]
#define MINUTES				RTC_ARR[1]
#define DAY					RTC_ARR[2]
#define HOURS				RTC_ARR[3]
#define DATE				RTC_ARR[4]
#define MONTH				RTC_ARR[5]
#define YEAR				RTC_ARR[6]
#define PREV_SECONDS		RTC_ARR[7]
//#define HOURS				RTC_ARR[8]

#define EEPM_ID_WRITE			0xA0
#define EEPM_ID_READ			0XA1

**/

//***************Changed **************************|//

// Load a value into Baud Rate Generator.  Example is for 9600.
// See section 19.3.1 of datasheet. // in New data sheet 23.3.2.2 Bit rate block it is
//  U1BRG = (Fcy / (16 * BaudRate)) - 1
//  U1BRG = (36850000 / (16 * 9600)) - 1
//  U1BRG = 238.908854 //Round to 239
	
#define Baud1200  	0X0185
#define Baud2400	0X00C2
#define Baud4800	0X0060
#define Baud9600	128 //0X002F
/*20MHz used, (20Mhz/(19200*16))-1=64*/
#define Baud19200 	64
#define Baud38400 	32
#define Baud57600	0X0007
#define Baud115200	10
#define Baud230400	6


#define	RTU_ID	1
#define DIMS_DEF	1 * 2
#define DIMS_Pseudo 0 * 2
#define DOMS_DEF	1 * 2
#define DOMS_Pseudo 0 * 2
#define SLOTS		11 * 2
#define MaxWagons	120
#define ZERODELAY	3000		// 3 second delay for zeroing
//#define THRESHOLD	500			// 5000 KGS
//changed//
#define THRESHOLD	50			// 5000 KGS
#define STOREVAL	10			// 100 kgs

#define bit0	0x01
#define bit1	0x02
#define bit2	0x04
#define bit3	0x08
#define bit4	0x10		  
#define bit5	0x20
#define bit6	0x40
#define bit7	0x80

#define MESWSTAR		2
#define MESWSTOP		3
#define MESWABOR		4
#define MESUNVEH		18

#define ZERODELAY		3000		// 3 second delay for zeroing

#ifdef _MAIN_

void delay(unsigned long duration);
unsigned int GetInt(unsigned char LSB, unsigned char MSB);
unsigned long int GetLInt(unsigned char LSB, unsigned char MIB, unsigned char MSB);
unsigned char GetLSB(unsigned int Integer);
unsigned char GetMSB(unsigned int Integer);
unsigned char LGetLSB(unsigned long int Number);
unsigned char LGetMID(unsigned long int Number);
unsigned char LGetMSB(unsigned long int Number);

void CalcCheckSum(unsigned int Bytes);

void IOInit();
void SetIODefault();
void ReadInputs();
void read_inputs();
void set_tire();
void LatchData();
void read_in_data();
void SendZeroToWS(void);
void ProcessNonWeigh(void);
void CalcSpeed(void);
void CalcArmSpeed(unsigned int *TmrCounter,unsigned int *TxSpeed);
void CalcArm1Speed(void);
void CalcArm2Speed(void);
void Parameters(void);
void Parameters1(void);
void Parameters2(void);
void Parameters3(void);
void Parameters4(void);
void Parameters5(void);

const unsigned int CRCTable[256] = {
	0x00000,0x01189,0x02312,0x0329B,0x04624,0x057AD,0x06536,0x074BF,
  	0x08C48,0x09DC1,0x0AF5A,0x0BED3,0x0CA6C,0x0DBE5,0x0E97E,0x0F8F7,
  	0x01081,0x0108,0x03393,0x0221A,0x056A5,0x0472C,0x075B7,0x0643E,
  	0x09CC9,0x08D40,0x0BFDB,0x0AE52,0x0DAED,0x0CB64,0x0F9FF,0x0E876,
 	0x02102,0x0308B,0x0210,0x01399,0x06726,0x076AF,0x04434,0x055BD,
  	0x0AD4A,0x0BCC3,0x08E58,0x09FD1,0x0EB6E,0x0FAE7,0x0C87C,0x0D9F5,
  	0x03183,0x0200A,0x01291,0x0318,0x077A7,0x0662E,0x054B5,0x0453C,
  	0x0BDCB,0x0AC42,0x09ED9,0x08F50,0x0FBEF,0x0EA66,0x0D8FD,0x0C974,
 	0x04204,0x0538D,0x06116,0x0709F,0x0420,0x015A9,0x02732,0x036BB,
  	0x0CE4C,0x0DFC5,0x0ED5E,0x0FCD7,0x08868,0x099E1,0x0AB7A,0x0BAF3,
  	0x05285,0x0430C,0x07197,0x0601E,0x014A1,0x0528,0x037B3,0x0263A,
  	0x0DECD,0x0CF44,0x0FDDF,0x0EC56,0x098E9,0x08960,0x0BBFB,0x0AA72,
  	0x06306,0x0728F,0x04014,0x0519D,0x02522,0x034AB,0x0630,0x017B9,
  	0x0EF4E,0x0FEC7,0x0CC5C,0x0DDD5,0x0A96A,0x0B8E3,0x08A78,0x09BF1,
  	0x07387,0x0620E,0x05095,0x0411C,0x035A3,0x0242A,0x016B1,0x0738,
  	0x0FFCF,0x0EE46,0x0DCDD,0x0CD54,0x0B9EB,0x0A862,0x09AF9,0x08B70,
  	0x08408,0x09581,0x0A71A,0x0B693,0x0C22C,0x0D3A5,0x0E13E,0x0F0B7,
  	0x0840,0x019C9,0x02B52,0x03ADB,0x04E64,0x05FED,0x06D76,0x07CFF,
  	0x09489,0x08500,0x0B79B,0x0A612,0x0D2AD,0x0C324,0x0F1BF,0x0E036,
  	0x018C1,0x0948,0x03BD3,0x02A5A,0x05EE5,0x04F6C,0x07DF7,0x06C7E,
  	0x0A50A,0x0B483,0x08618,0x09791,0x0E32E,0x0F2A7,0x0C03C,0x0D1B5,
  	0x02942,0x038CB,0x0A50,0x01BD9,0x06F66,0x07EEF,0x04C74,0x05DFD,
  	0x0B58B,0x0A402,0x09699,0x08710,0x0F3AF,0x0E226,0x0D0BD,0x0C134,
  	0x039C3,0x0284A,0x01AD1,0x00B58,0x07FE7,0x06E6E,0x05CF5,0x04D7C,
  	0x0C60C,0x0D785,0x0E51E,0x0F497,0x08028,0x091A1,0x0A33A,0x0B2B3,
  	0x04A44,0x05BCD,0x06956,0x078DF,0x0C60,0x01DE9,0x02F72,0x03EFB,
  	0x0D68D,0x0C704,0x0F59F,0x0E416,0x090A9,0x08120,0x0B3BB,0x0A232,
  	0x05AC5,0x04B4C,0x079D7,0x0685E,0x01CE1,0x00D68,0x03FF3,0x02E7A,
  	0x0E70E,0x0F687,0x0C41C,0x0D595,0x0A12A,0x0B0A3,0x08238,0x093B1,
  	0x06B46,0x07ACF,0x04854,0x059DD,0x02D62,0x03CEB,0x00E70,0x01FF9,
  	0x0F78F,0x0E606,0x0D49D,0x0C514,0x0B1AB,0x0A022,0x092B9,0x08330,
  	0x07BC7,0x06A4E,0x058D5,0x0495C,0x03DE3,0x02C6A,0x01EF1,0x00F78
};

const unsigned char Version[20] = "TrackWeigh V6.1";
const unsigned char ReleaseDate[20] = "8th January 2020";

void InitWeighing(void);
void EndOfWeighing(void);
void FindInputsSetUnSet(void);
void SENDSTOP(void);
void SEN2STOP(void);
void STOPIT(void);
void STOPSR(unsigned char EndSwitch);
void STSWSTAT(unsigned int SwitchPosition, unsigned char Stimuli);
unsigned char PairNo(void);
void STSWSETS(unsigned char PairPosition,unsigned char Stimuli);
unsigned int TDIRECT(unsigned char Direction, unsigned char OorE) ;
void STSWSEQ(unsigned char PairPosition,unsigned char Stimuli);
void UNWEIGH(unsigned char PairPosition);
unsigned char IsItLoco_A(void);
void ForCount(unsigned char SwitchPair);
void WEIGHTST(void);
void BackCount(unsigned char SwitchPair);
void FORWEIGH(unsigned char SwitchPair);
unsigned char GetWeigh(unsigned char SwitchPair);
unsigned char ISITLOCO();
unsigned char GetWeigh_A(unsigned char SwitchPair);
void STWBSTAT(unsigned char WeighSwitchType);
void STSWWEIG(unsigned char WeighSwitchType);
void ONTOWB(void);
void OFFWB(void);
void WHICHAX(void);
void WHICHNEX(void);
void WEIGHING(void);
void SetForWeighing(void);
void BACKAX(void);
void ABOR(void);
void WHICHIS(void);
void REENTER(void);
void REWEIGH(void);
void WHICHWAG(void);
void CLEARTYP(void);
void AXELI (void);
void PAIR1(void);
void PAIR2(void);
void VORL4AX(void);
void V4AX(void);
void V2AX(void);
void L3AX(void);
void LORV2AX(void);
void L2AX(void);
void VERROR(void);
void CheckEndWeigh(void);
unsigned char Front(void);
unsigned char WEIGHTSW(unsigned char SwitchPair);
void IDENT(unsigned char SwitchPair);
void VEHREC(unsigned char WeighSwitchType);

unsigned int SWWEIGH;		//WEIGHT SWITCHES STATE
unsigned int WBSTATE;		//STATE OF WEIGHBRIDGE SPEED TABLE
unsigned char FWEIGHT;		//SET WHEN A 'START WEIGH' IS SENT,UNSET WHEN 'STOP WEIGH' IS SENT
unsigned long LTempBuffer;		// temp buffer to store long value

union WORD1_DEF	Var1;
union WORD1_DEF	Var2;
union WORD1_DEF	Var3;
union WORD1_DEF	Var4;
union WORD1_DEF	Var5;
union BYTE1_DEF Var6;

unsigned char SwitchNumber,PairNumber,Direction,MessageNumber;
// Message numbers
// 1 - Ready					2 - Direction In				3 	- Direction Out
// 4 - Train Forward			5 - Stop Weiging				6 	- Train Reversal
// 7 - Weighing					8 - Unknown Vehicle				9 	- 2 Axle Wagon
//10 - 4 Axle Wagon	  	  		11 - Loco						12	- New Vehicle
//13 - End of Weighing 	  		14 - Checking WS Inteface		15  - Abort Weighing
//16 - Idle Mode

unsigned int Counter,Counter1,StartPos;
unsigned char WeighSwitch;
signed int WAxleWeight[MaxWagons][4];				// Axle Weight - wagon wise
unsigned int CurrentWAxle,PrevWAxle;
unsigned int NextAxles[2];
unsigned int SpeedAvgCount;

unsigned int SwitchCount[8];
unsigned int SWSTATE[8],SWSETS[8];

//SEQUENCE OF PAIRS OF SWITCHES PRESSED -0=NONE,1=ODD ONLY,2=EVEN ONLY
//;3=1 THEN 2,4=	2 THEN 1
unsigned int SWSEQ[8];

//COUNT OF ON AXLES PER FORWARD KEY PAIR
//ONWARD IS ADDED,BACKWARD IS SUBTRACTED FOR SWSEQ=3 OR 4 OR VICE VERSA
unsigned int AXCOUNT[8],AXBACK[8],AXFOR[8];

//INITALLY = 0.SET TO THE AXLE COUNT WHEN WEIGHING	IS STARTED.
//CLEARED WHEN AN 'END WEIGH' MESSAGE IS SENT.
//NOT CHANGED WHEN AN 'ABORT WEIGH' MESSAGE IS SENT.
unsigned int PRWEIGH;

//INITALLY 0,SET 1 FOR 4 AXLE WAGON,2 FOR 2AXLE WAGON, 0xff FOR LOCO
unsigned char FVEHTYPE;

unsigned int VEHRCS;		//VEHICAL RECOGNITION STATE,AVI DITTO
unsigned int SPEEDAX;		//AXLE FOR WHICH SPEED IS BEING MEASURED
unsigned int LAXONWB;		//LAST AXLE THAT CAME ONTO THE WEIGHBRIDGE.USED BY STOP WEIGH MESSAGE
unsigned int ActualAxleWeighed;	// The axles count of logically weighed axles
unsigned int LastAxleWeid;
unsigned int AxleQueried;
unsigned char FillChar;

unsigned char LOCOCOUN;		// number of axles to be eliminated
unsigned char PAIR1COU,PAIR2COU;
unsigned char WAGONS;		//COUNT OF NUMBER OF WAGONS
unsigned char CurrentWagon,PrevWagon;
unsigned long TCOUNT;		//TIME COUNT.ADDS ONE EVERY 'TIME'MMSECS
unsigned int Speed,OSLimit,A1Speed,A2Speed;			//Speed of the Current Axle
unsigned int WSpeed;		// speed of wagon from weighing system
unsigned int AccuSpeed;
unsigned int ZoneSpeed;
unsigned char TempRef;
unsigned char BlinkSpeed;

unsigned int Resolution;
signed long int WeightToStore;
signed long int PrevWtToStore,TempWtToStore;
unsigned char AverageCount;
unsigned char MsgToD,DPos;
unsigned int SampleWt[10];
unsigned int SAvgCount;
signed long int Weight[MaxWagons];				// Wagon Weight
//signed long int Bogie1Weight[MaxWagons];			// 1st Bogie Weight
//signed long int Bogie2Weight[MaxWagons];			// 2nd Bogie Weight
char WagonType[MaxWagons];			// Wagon Type
unsigned int WagonSpeed[MaxWagons];		// Speed of a wagon in binary with 1 decimals places x 10
unsigned int WagonA2Speed[MaxWagons];	// Speed of a wagon in binary with 1 decimals places x 10 - based ib start weigh pair
unsigned int ZeroTimer;
unsigned int SpeedF1Timer,SpeedF2Timer;
unsigned int SpeedTimer;
unsigned int WeighZone;
//unsigned int WaitCounter;

unsigned int OldValue,NewValue;
unsigned char OorE;
unsigned int FrstPara,SecPara,ThrdPara,SwitchSeq;

unsigned char actin[64];
unsigned char in[64],org_buf[64],dup_buf[64],PrevIn[64],setin[64],rstin[64];
unsigned char out[64],setout[64],rstout[64],currout[64];
unsigned char Changed,DataOut,DataIn;
unsigned char DIMS,DOMS;
unsigned int ModuleNumber;
unsigned int TempInt1,TempInt2,NewCSum;
signed long int TempBuf;

unsigned char flag,tire;
unsigned char InCounter,OutCounter;
unsigned char tire_add[8],in_add[64],out_add[64],OTimerRun[(DOMS_DEF+DOMS_Pseudo)*8],ONextStatus[(DOMS_DEF+DOMS_Pseudo)*8],StartAddress;
int DefaultOTime,OTimer[(DOMS_DEF+DOMS_Pseudo)*8],Counter2;
unsigned char ITimerRun[(DIMS_DEF+DIMS_Pseudo)*8],INextStatus[(DIMS_DEF+DIMS_Pseudo)*8];
unsigned int ITimer[(DIMS_DEF+DIMS_Pseudo)*8],OForced,IForced;
unsigned int TCounter;
unsigned int TimerCounter, OutputTimer,ADCounter,ADWaitTimer ;
unsigned int InPointer,OutPointer,TempPointer;
unsigned int ChannelNumber ;

unsigned int NoOfBytes,PCFailCount;
unsigned char CharRTable[4][100+2];
unsigned int BytesToSend[4],BytesSent[4];
unsigned char PackReceived[200],PackToSend[4][300],OutSelect[2];
unsigned char CSum,CByte;
unsigned int MSCounter;
unsigned int RemoteSTimer;
unsigned char CharRcvd,CStep,RTUAddress,CharIn[4],CharOut[4],CharRcvd14;
unsigned char RTUQuery, Digits, RefPos, ByteCntr;
unsigned int PackLength,PackCounter,CRCValue;
unsigned char RTUID;
unsigned char LSBByte,MSBByte,PowerOnStatus, Command ;
unsigned char WSCSum,CSumRcvd;
unsigned char WSCSum0;
unsigned short rcv_data;            /* Reception data */
unsigned char Index,ChannelBit,RelayMode;
unsigned char *xdataPtr;

unsigned int BytesExpectd;
unsigned int ExpPower;
signed int PeakValue;
signed int ActualWt;
signed int CurrentWeight,CurrentWeight0;
signed int ZeroWeight,ZeroWeight0;
signed int CurrAxleWeight;
unsigned char  fail_count;

signed int PrevWt;
unsigned int WtArray[500];
unsigned long int AccuWt;
unsigned int ArrayCnt,AccuCount,PeakWt,PeakPos,HalfPeak;
unsigned long int SampleAccu[4];
unsigned int SampleAvg[4];
unsigned int SampleUL[4],SampleLL[4],SamplesCount[4];

unsigned char CharCount,CharCount0,WBNO;
unsigned char ADFailCount[2],ADTimes[2];
unsigned char ADString[100];
unsigned char ADString0[50];
unsigned char ADBuf[10];
unsigned char BlockStr[2];
unsigned int BlockNo;
unsigned char SCharCount;
unsigned char I40Status[4];
signed int WeightToUpdate,WeightToUpdate1,WeightFromSCADA,WtToConv;
signed int DataToUpdate;
unsigned char WeightCount[2];
signed long int ADValue[2],ADAverage,ADAverage2;
unsigned int TempCounter;

unsigned int Samples[100];
unsigned int SampleCount,PrevWeight;
unsigned int DiffWeight,AxleCount;
unsigned int AxleWtCount,IgnoredWtCount,MissedWtCount;
unsigned long AccuWeight;
unsigned long TempWeight;

unsigned int AxleWeight[MaxWagons*4+30];			// axle weight
unsigned int AxleSpeed[MaxWagons*4+30];				// speed of axle

char AxleType[MaxWagons*4+30];						// Wagon Type of each axle weighed
char LastWagonTye;

signed int AxleWtRcvd;

unsigned int AxlesWeighed,PrevWeighed;
unsigned char Digit_U, Digit_T, Digit_H;

unsigned int InSpeed[10], OutSpeed[10];
unsigned long InFactor[10], OutFactor[10];
unsigned long CurrentFactor;
unsigned long InWtSpeed[10], OutWtSpeed[10];
unsigned long InWtFactor[5][10];
unsigned long OutWtFactor[5][10];
unsigned char WtRange;
unsigned char NetString[10];

unsigned char PackRcvd[5];
unsigned char RCharCount;
unsigned int ReqAxleCount;
unsigned char Digit_U, Digit_T, Digit_H, Digit_Th, Digit_TTh;

/***changed1******/

unsigned char charRTable1[1][100];
int chi=0,RcvdNumber=0,RcvdNumber1[3]=0,Int=0;
unsigned char CharRcvd1;

unsigned int CounterIS1=0,TaCOuntRes=0,INT1=0;

/***changed2******/

signed int TemporaryWeight;



///////////////////////////


void CalcAverage(void);
void CalcAverage32(void);
void AverInAver32(void);
void RegularSamples(void);
void CorrectWeight(void);
void CorrectWtNSpeed(void);

#else

extern void delay(unsigned long duration);
extern unsigned int GetInt(unsigned char LSB, unsigned char MSB);
extern unsigned long int GetLInt(unsigned char LSB, unsigned char MIB, unsigned char MSB);
extern unsigned char GetLSB(unsigned int Integer);
extern unsigned char GetMSB(unsigned int Integer);
extern unsigned char LGetLSB(unsigned long int Number);
extern unsigned char LGetMID(unsigned long int Number);
extern unsigned char LGetMSB(unsigned long int Number);
extern void CalcCheckSum(unsigned int Bytes);

extern void IOInit();
extern void SetIODefault();
extern void ReadInputs();
extern void read_inputs();
extern void set_tire();
extern void LatchData();
extern void read_in_data();
extern void FormRemotePack(void);
extern void IncludeWeight(void);
extern void IncludeWeight1(void);
extern void CheckNIncludeByte(void);
extern void CheckNIncludeByte1(void);
extern void SendZeroToWS(void);
extern void ProcessNonWeigh(void);
extern void CalcSpeed(void);
extern void CalcArmSpeed(unsigned int *TmrCounter,unsigned int *TxSpeed);
extern void CalcArm1Speed(void);
extern void CalcArm2Speed(void);
extern void Parameters(void);
extern void Parameters1(void);
extern void Parameters2(void);
extern void Parameters3(void);
extern void Parameters4(void);
extern void Parameters5(void);

extern void InitWeighing(void);
extern void EndOfWeighing(void);
extern void FindInputsSetUnSet(void);
extern void SENDSTOP(void);
extern void SEN2STOP(void);
extern void STOPIT(void);
extern void STOPSR(unsigned char EndSwitch);
extern void STSWSTAT(unsigned int SwitchPosition, unsigned char Stimuli);
extern unsigned char PairNo(void);
extern void STSWSETS(unsigned char PairPosition,unsigned char Stimuli);
extern unsigned int TDIRECT(unsigned char Direction, unsigned char OorE) ;
extern void STSWSEQ(unsigned char PairPosition,unsigned char Stimuli);
extern void UNWEIGH(unsigned char PairPosition);
extern unsigned char IsItLoco_A(void);
extern unsigned char GetWeigh_A(unsigned char SwitchPair);
extern void ForCount(unsigned char SwitchPair);
extern void WEIGHTST(void);
extern void BackCount(unsigned char SwitchPair);
extern void FORWEIGH(unsigned char SwitchPair);
extern unsigned char GetWeigh(unsigned char SwitchPair);
extern unsigned char ISITLOCO();
extern void STWBSTAT(unsigned char WeighSwitchType);
extern void STSWWEIG(unsigned char WeighSwitchType);
extern void ONTOWB(void);
extern void OFFWB(void);
extern void WHICHAX(void);
extern void WHICHNEX(void);
extern void WEIGHING(void);
extern void SetForWeighing(void);
extern void BACKAX(void);
extern void ABOR(void);
extern void WHICHIS(void);
extern void REENTER(void);
extern void REWEIGH(void);
extern void WHICHWAG(void);
extern void CLEARTYP(void);
extern void AXELI (void);
extern void PAIR1(void);
extern void PAIR2(void);
extern void VORL4AX(void);
extern void V4AX(void);
extern void V2AX(void);
extern void L3AX(void);
extern void LORV2AX(void);
extern void L2AX(void);
extern void VERROR(void);
extern void CheckEndWeigh(void);
extern unsigned char Front(void);
extern unsigned char WEIGHTSW(unsigned char SwitchPair);
extern void IDENT(unsigned char SwitchPair);
extern void VEHREC(unsigned char WeighSwitchType);

extern unsigned int SWWEIGH;		//WEIGHT SWITCHES STATE
extern unsigned int WBSTATE;		//STATE OF WEIGHBRIDGE SPEED TABLE
extern unsigned char FWEIGHT;		//SET WHEN A 'START WEIGH' IS SENT,UNSET WHEN 'STOP WEIGH' IS SENT
extern unsigned long LTempBuffer;	// temp buffer to store long value

extern union WORD1_DEF	Var1;
extern union WORD1_DEF	Var2;
extern union WORD1_DEF	Var3;
extern union WORD1_DEF	Var4;
extern union WORD1_DEF	Var5;
extern union BYTE1_DEF  Var6;

extern unsigned char SwitchNumber,PairNumber,Direction,MessageNumber;
extern unsigned int Counter,Counter1,StartPos;
extern unsigned char WeighSwitch;
extern signed int WAxleWeight[MaxWagons][4];				// Axle Weight - wagon wise
extern unsigned int CurrentWAxle,PrevWAxle;
extern unsigned int NextAxles[2];
extern unsigned int SpeedAvgCount;

extern unsigned int SwitchCount[8];
extern unsigned int SWSTATE[8],SWSETS[8];

//SEQUENCE OF PAIRS OF SWITCHES PRESSED -0=NONE,1=ODD ONLY,2=EVEN ONLY
//;3=1 THEN 2,4=	2 THEN 1
extern unsigned int SWSEQ[8];

//COUNT OF ON AXLES PER FORWARD KEY PAIR
//ONWARD IS ADDED,BACKWARD IS SUBTRACTED FOR SWSEQ=3 OR 4 OR VICE VERSA
extern unsigned int AXCOUNT[8],AXBACK[8],AXFOR[8];

//INITALLY = 0.SET TO THE AXLE COUNT WHEN WEIGHING	IS STARTED.
//CLEARED WHEN AN 'END WEIGH' MESSAGE IS SENT.
//NOT CHANGED WHEN AN 'ABORT WEIGH' MESSAGE IS SENT.
extern unsigned int PRWEIGH;

//INITALLY 0,SET 1 FOR 4 AXLE WAGON,2 FOR 2AXLE WAGON, 0xff FOR LOCO
extern unsigned char FVEHTYPE;

extern unsigned int VEHRCS;			//VEHICAL RECOGNITION STATE,AVI DITTO
extern unsigned int SPEEDAX;		//AXLE FOR WHICH SPEED IS BEING MEASURED
extern unsigned int LAXONWB;		//LAST AXLE THAT CAME ONTO THE WEIGHBRIDGE.USED BY STOP WEIGH MESSAGE
extern unsigned int ActualAxleWeighed;	// The axles count of logically weighed axles
extern unsigned int LastAxleWeid;
extern unsigned int AxleQueried;
extern unsigned char FillChar;
extern unsigned char LOCOCOUN;		// number of axles to be eliminated
extern unsigned char PAIR1COU,PAIR2COU;
extern unsigned char WAGONS;		//COUNT OF NUMBER OF WAGONS
extern unsigned char CurrentWagon,PrevWagon;
extern unsigned long TCOUNT;		//TIME COUNT.ADDS ONE EVERY 'TIME'MMSECS
extern unsigned int Speed,OSLimit,A1Speed,A2Speed;			//Speed of the Current Axle
extern unsigned int WSpeed;			// speed of wagon from weighing system
extern unsigned int AccuSpeed;
extern unsigned int ZoneSpeed;
extern unsigned char TempRef;
extern unsigned char BlinkSpeed;

extern unsigned int Resolution;
extern signed long int WeightToStore;
extern signed long int PrevWtToStore,TempWtToStore;
extern unsigned char AverageCount;
extern unsigned char MsgToD,DPos;
extern unsigned int SampleWt[10];
extern unsigned int SAvgCount;
extern signed long int Weight[MaxWagons];				// Wagon Weight
//extern signed long int Bogie1Weight[MaxWagons];			// 1st Bogie Weight
//extern signed long int Bogie2Weight[MaxWagons];			// 2nd Bogie Weight
extern char WagonType[MaxWagons];			// Wagon Type
extern unsigned int WagonSpeed[MaxWagons];		// Speed of a wagon in binary with 1 decimals places x 10
extern unsigned int WagonA2Speed[MaxWagons];	// Speed of a wagon in binary with 1 decimals places x 10 - based ib start weigh pair
extern unsigned int ZeroTimer;
extern unsigned int SpeedF1Timer,SpeedF2Timer;
extern unsigned int SpeedTimer;
extern unsigned int WeighZone;
//extern unsigned int WaitCounter;
extern unsigned int OldValue,NewValue;
extern unsigned char OorE;
extern unsigned int FrstPara,SecPara,ThrdPara,SwitchSeq;

extern unsigned char actin[64];
extern unsigned char in[64],org_buf[64],dup_buf[64],PrevIn[64],setin[64],rstin[64];
extern unsigned char out[64],setout[64],rstout[64],currout[64];
extern unsigned char Changed,DataOut,DataIn;
extern unsigned char DIMS,DOMS;
extern unsigned int ModuleNumber;
extern unsigned int TempInt1,TempInt2,NewCSum;
extern signed long int TempBuf;

extern unsigned char flag,tire;
extern unsigned char InCounter,OutCounter;
extern unsigned char tire_add[8],in_add[64],out_add[64],OTimerRun[(DOMS_DEF+DOMS_Pseudo)*8],ONextStatus[(DOMS_DEF+DOMS_Pseudo)*8],StartAddress;
extern int DefaultOTime,OTimer[(DOMS_DEF+DOMS_Pseudo)*8],Counter2;
extern unsigned char ITimerRun[(DIMS_DEF+DIMS_Pseudo)*8],INextStatus[(DIMS_DEF+DIMS_Pseudo)*8];
extern unsigned int ITimer[(DIMS_DEF+DIMS_Pseudo)*8],OForced,IForced;
extern unsigned int TCounter;
extern unsigned int TimerCounter, OutputTimer,ADCounter,ADWaitTimer ;
extern unsigned int InPointer,OutPointer,TempPointer;
extern unsigned int ChannelNumber ;

extern unsigned int NoOfBytes,PCFailCount;
extern unsigned char CharRTable[4][100+2];
extern unsigned int BytesToSend[4],BytesSent[4];
extern unsigned char PackReceived[200],PackToSend[4][300],OutSelect[2];
extern unsigned char CSum,CByte;
extern unsigned int MSCounter;
extern unsigned int RemoteSTimer;
extern unsigned char CharRcvd,CStep,RTUAddress,CharIn[4],CharOut[4];
extern unsigned char RTUQuery, Digits, RefPos, ByteCntr;
extern unsigned int PackLength,PackCounter,CRCValue;
extern unsigned char RTUID;
extern unsigned char LSBByte,MSBByte,PowerOnStatus, Command ;
extern unsigned char WSCSum,CSumRcvd;
extern unsigned char WSCSum0;
extern unsigned short rcv_data;            /* Reception data */
extern unsigned char Index,ChannelBit,RelayMode;
extern unsigned char *xdataPtr;

extern unsigned int BytesExpectd;
extern unsigned int ExpPower;
extern signed int PeakValue;
extern signed int ActualWt;
extern signed int CurrentWeight,CurrentWeight0;
extern signed int ZeroWeight,ZeroWeight0;
extern signed int CurrAxleWeight;
extern unsigned char  fail_count;

extern signed int PrevWt;
extern unsigned int WtArray[500];
extern unsigned long int AccuWt;
extern unsigned int ArrayCnt,AccuCount,PeakWt,PeakPos,HalfPeak;
extern unsigned long int SampleAccu[4];
extern unsigned int SampleAvg[4];
extern unsigned int SampleUL[4],SampleLL[4],SamplesCount[4];

extern unsigned char CharCount,CharCount0,WBNO;
extern unsigned char ADFailCount[2],ADTimes[2];
extern unsigned char ADString[100];
extern unsigned char ADString0[50];
extern unsigned char ADBuf[10];
extern unsigned char BlockStr[2];
extern unsigned int BlockNo;
extern unsigned char SCharCount;
extern unsigned char I40Status[4];
extern signed int WeightToUpdate,WeightToUpdate1,WeightFromSCADA,WtToConv;
extern signed int DataToUpdate;
extern unsigned char WeightCount[2];
extern signed long int ADValue[2],ADAverage,ADAverage2;
extern unsigned int TempCounter;

extern unsigned int Samples[100];
extern unsigned int SampleCount,PrevWeight;
extern unsigned int DiffWeight,AxleCount;
extern unsigned int AxleWtCount,IgnoredWtCount,MissedWtCount;
extern unsigned long AccuWeight;
extern unsigned long TempWeight;

extern unsigned int AxleWeight[MaxWagons*4+30];				// axle weight
extern unsigned int AxleSpeed[MaxWagons*4+30];				// speed of axle

extern char AxleType[MaxWagons*4+30];						// Wagon Type of each axle weighed
extern char LastWagonTye;

extern signed int AxleWtRcvd;

extern unsigned int AxlesWeighed,PrevWeighed;
extern unsigned char Digit_U, Digit_T, Digit_H;

extern unsigned int InSpeed[10], OutSpeed[10];
extern unsigned long InFactor[10], OutFactor[10];
extern unsigned long CurrentFactor;
extern unsigned long InWtSpeed[10], OutWtSpeed[10];
extern unsigned long InWtFactor[5][10];
extern unsigned long OutWtFactor[5][10];
extern unsigned char WtRange;
extern unsigned char NetString[10];

extern unsigned char PackRcvd[5];
extern unsigned char RCharCount;
extern unsigned int ReqAxleCount;
extern unsigned char Digit_U, Digit_T, Digit_H, Digit_Th,Digit_TTh;



/***changed1******/

extern unsigned char charRTable1[1][100];
extern int chi,RcvdNumber,RcvdNumber1,Int;

/***changed2******/
extern signed int TemporaryWeight;
extern unsigned int CounterIS1,TaCOuntRes,INT1;


/******Changed 3 for RTC and EEPROM*/
/*
extern void ReadRTC(void);
extern void WriteRTC(void);

extern void ReadDateNTime(void);
*/
//extern void delay_ms1(unsigned int ms_count);
//extern void IsrTimer1(void);
/*
extern unsigned char TimeString[8];
extern unsigned char DateString[10];
*/
/*
extern unsigned char RTC_ARR[9];
extern unsigned long MSTimer1;
*/




///////////////////////////

extern void CalcAverage(void);
extern void CalcAverage32(void);
extern void AverInAver32(void);
extern void RegularSamples(void);
extern void CorrectWeight(void);
extern void CorrectWtNSpeed(void);

#endif

#define		Toggle				Var1.bit.b0				
#define		AllFF		  		Var1.bit.b1
#define		FirstTime	  		Var1.bit.b2
#define		OneSecond	  		Var1.bit.b3
#define 	AcquireZero			Var1.bit.b4
#define 	DLE1Received		Var1.bit.b5
#define 	ChecksumNext		Var1.bit.b6
#define 	DLE0Received		Var1.bit.b7
#define		Stx0Received		Var1.bit.b8
#define 	ChecksumNext0		Var1.bit.b9
#define 	ReplyAvailable		Var1.bit.b10
#define		SendData			Var1.bit.b11
#define		PassOk				Var1.bit.b12
#define		SendData1			Var1.bit.b13
#define		AllZeros			Var1.bit.b14
#define		AnyChange			Var1.bit.b15

#define		NoAlarmCheck		Var2.bit.b0				
#define		DLEReceived  		Var2.bit.b1
#define		StxReceived	  		Var2.bit.b2
#define		BroadCast	  		Var2.bit.b3
#define 	PackOk				Var2.bit.b4
#define 	CheckSumError		Var2.bit.b5
#define 	ResetFrameNumber	Var2.bit.b6
#define 	PCFail				Var2.bit.b7
#define		SendOutputs			Var2.bit.b8
#define 	SendQueryAD			Var2.bit.b9
#define 	OutputSelected		Var2.bit.b10
#define		Stx1Received		Var2.bit.b11
#define		ADOk				Var2.bit.b12
#define		ADFailStatus		Var2.bit.b13
#define		Positive			Var2.bit.b14
#define		OneByOneSet			Var2.bit.b15

#define		AlarmTestingDone	Var3.bit.b0				
#define		HoldStatus  		Var3.bit.b1
#define		StartFlowCheck 		Var3.bit.b2
#define		NoFlow		  		Var3.bit.b3
#define 	AlarmBlink			Var3.bit.b4
#define 	ToggleOff			Var3.bit.b5
#define 	ADOk0				Var3.bit.b6
#define 	ADFailStatus0		Var3.bit.b7
#define		SendQueryAD0		Var3.bit.b8
#define 	Positive0			Var3.bit.b9
#define 	ValueIsLess			Var3.bit.b10
#define		ZeroSent			Var3.bit.b11
#define		SetWLMode			Var3.bit.b12
#define		WLModeSent			Var3.bit.b13
#define 	WaitForCR			Var3.bit.b14
#define 	LeadZero			Var3.bit.b15
//#define		ResetWLMode			Var3.bit.b14
//#define		ResetModeSent		Var3.bit.b15


#define 	ErrorInState		Var4.bit.b0
#define		DisplayAxCount		Var4.bit.b1
//#define		StartSample			Var4.bit.b2
#define		EndWeigh			Var4.bit.b4
#define		DiagMode			Var4.bit.b5
#define     SendToRemote		Var4.bit.b6
#define 	ProcessTrack		Var4.bit.b7
#define		StoreWeight			Var4.bit.b8
#define 	WaitForInput		Var4.bit.b9
#define 	EntireWagon			Var4.bit.b10
#define 	SetSpeed			Var4.bit.b11
//#define 	BlinkSpeed			Var4.bit.b12
#define		SendMessage			Var4.bit.b13
#define		StartSpdTmr			Var4.bit.b14
#define		PowerNext			Var4.bit.b15

#define		ResetWS				Var5.bit.b0
#define		ResetSent			Var5.bit.b1
#define		WaitForWeight		Var5.bit.b2
#define		ResetSlNo			Var5.bit.b3
#define		SlNoResetSent		Var5.bit.b4
#define		NoSamplesError		Var5.bit.b5
#define		IgnoreWeight		Var5.bit.b6
#define		SF1Initiated		Var5.bit.b7
#define		SF2Initiated		Var5.bit.b8
#define		EnqAxleWt			Var5.bit.b11
#define		NextAxleSet			Var5.bit.b12
#define		SecondAxleSet		Var5.bit.b13
#define		StartSampling		Var5.bit.b14
#define		SetContinous		Var5.bit.b15

#define		InSpeedBased		Var6.bit.b0
#define		InWtNSpeed			Var6.bit.b1
#define		OutSpeedBased		Var6.bit.b2
#define		OutWtNSpeed			Var6.bit.b3
#define		DisplayWeight		Var6.bit.b4
#define		SysInWLMode			Var6.bit.b5

//#define		SendToRemote1		Var6.bit.b5


#define	OnSystemReadyRelay		(out[0] |= bit0)
#define	OffSystemReadyRelay		(out[0] &= ~(bit0))

#define	OnOverSpeedRelay		(out[0] |= bit1)
#define	OffOverSpeedRelay		(out[0] &= ~(bit1))
#define	BlinkSpeedRelay			(out[0] ^= bit1)

#define	OnAlarm					(out[0] |= bit2)
#define	OffAlarm				(out[0] &= ~(bit2))
/*
#define	OnOverSpeedAlarm		(out[0] |= bit2)
#define	OffOverSpeedAlarm		(out[0] &= ~(bit2))

#define	OnOtherAlarm			(out[0] |= bit3)
#define	OffOtherAlarm			(out[0] &= ~(bit3))
*/
#define	OnSystemReadyLP			(out[1] |= bit0)
#define	OffSystemReadyLP		(out[1] &= ~(bit0))

#define	OnOverSpeedLP			(out[1] |= bit1)
#define	OffOverSpeedLP			(out[1] &= ~(bit1))
#define	BlinkSpeedLP			(out[1] ^= bit1)

#define	OnAdvanceOSLP			(out[1] |= bit2)
#define	OffAdvanceOSLP			(out[1] &= ~(bit2))
#define	BlinkAdvanceOSLP		(out[1] ^= bit2)

#define	OnUnknownLP				(out[1] |= bit3)
#define	OffUnknownLP			(out[1] &= ~(bit3))

//#define	OnADFailLP				(out[1] |= bit4)
//#define	OffADFailLP				(out[1] &= ~(bit4))

#define	OnWSystemFailLP			(out[1] |= bit4)
#define	OffWSystemFailLP		(out[1] &= ~(bit4))
