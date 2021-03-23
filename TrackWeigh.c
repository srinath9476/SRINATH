
#define _MAIN_

#include "sfr65.h"
#include "Common.h"
#include "stdlib.h"
#include "string.h"

/***********Changed************************/
#include "LCD.h"

#include "I2C.h"
#include "RTC.h"
#include "EEPROM.h"
/******************************************/


void main(void);
void mcuinit(void);
void mcuinit1(void);
void Com0Init(void);
void Com1Init(void);
void Com2Init(void);
void Com6Init(void);
void Init_Timer1(void);
void PowerOnInit(void);
void Com0Rx(void);
void Com0Tx(void);
void Com1Rx(void);
void Com1Tx(void);
void Com2Rx(void);
void Com2Tx(void); 
void Com6Rx(void);
void Com6Tx(void);
/**************changedb**************************/
/*
void ProcessByte(void);
void ProcessCommands(void);
*/
//void ProcessByte1(void);
//void ProcessCommands1(void);
void ProcessBytesPCUnit(signed int DataToUpdate);
void ProcessBytesFromPCUnit(void);
signed int DataTOPC;

void DisplayErr();
/*******************************************/

unsigned int GetCSum(unsigned int CRCPValue, unsigned char CByte);

void SendByte0(void);
void SendByte1(void);
void SendByte2(void);
void SendByte6(void);

unsigned char GetChannelStatus(unsigned int ChannelNumber);
void SetIChannelStatus(unsigned int ChannelNumber, unsigned char Status);
void SetOChannelStatus(unsigned int ChannelNumber, unsigned char Status, unsigned int Duration);
void OrgIChannelStatus(unsigned int ChannelNumber);
void OrgOChannelStatus(unsigned int ChannelNumber);
void InsertByte();
void StartXmit1(unsigned int Bytes);
void StartXmit2(unsigned int Bytes);
void StartXmit0(unsigned int Bytes);
void StartXmit6(unsigned int Bytes);
void ReplyCommandError();
void ReplyCRCError();
void ReplyIllegalPara();
void QueryAD(void);
void SendInfo();
void FormRemotePack(void);
void IncludeWeight(void);
void CheckNIncludeByte(void);
//void StoreSamples(void);

void EnquireWt(void);
void SendZeroToWS(void);
void SendResetWLToWS(void);
void SendSoftReset(void);
void EnqLastSl(void);
void EnqReqAxle(void);

void FormRemotePack1(void);
void IncludeWeight1(void);
void CheckNIncludeByte1(void);

void QueryFlintech(void);
void ProcessByteFlint(void);
void ProcessFlintech(void);
void CheckWeight(void);
void CalculateSpeed(void);
void CalculateWt(void);
void Avg3_4Peak(void);
void AverInAver(void);
void AverInPeak(void);

void ProcessByteTLUnit(void);
void ProcessTLUnit(void);
void SendWeight(void);

void AckReset(void);
void ResetSteps(void);
void AckResetWS(void);
void AckSetWL(void);
void AckZero(void);
void AckResetSl(void);
void SendAxlesWeighed(void);
void SendAxleWeight(void);
void TransmitAxleWeight(void);
void SendAllAxleWeights(void);
void SendNextAxle(void);

//|************** changed*****************************//
int j;
int DisplayCheck[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf, 0xbf,0x7f,0xc0,0xf9,0xa4,0xb0,0x99, 0x92, 0x82, 0xf8, 0x80, 0x90,0xff}; //18 numbers
int DisplayNumber[]={0xc0,0xf9,0xa4,0xb0,0x99, 0x92, 0x82, 0xf8, 0x80, 0x90,0xBF};//to display "0,1,2,3,4,5,6,7,8,9,-" in Segment
int DisplaySelect[]={0x38,0x30,0x28,0x20,0x18,0x10,0x08,0x00}; // To Select individul Segments [0] is '1's location
																							// [7] is '10M'`s location 
																							
//char CharToNumber[]={'0','1','2','3','4','5','6','7','8','9'};
char CharToNumber[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','X','Y','Z','a','b','c','d','e','f','g','h',' '};																							
//int DisplaySelect[]={0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x0E};
int nodAtA[]={0x71,0x77,0x88,0x87,0x88,0xA1,0xA3,0xAB};	//{!-AtAdon in array elements, but printing in Segment "nodAtA_!"
int PC2EM[]={0x3f,0xbf,0xc6,0xa1,0x88,0xa4,0xc6,0x8c};
int RT2EM[]={0x3f,0xbf,0xc6,0xa1,0x88,0xa4,0x87,0x8f};
int Error[]={0x79,0x0f,0xbf,0x8f,0xa3,0x8f,0x8f,0x86};
int Overloada[]={0x79,0xf7,0xa1,0x88,0xa3,0xc7,0x8f,0xc0};
int Underloada[]={0x79,0xf7,0xa1,0x88,0xa3,0xc7,0x8f,0xc1};
int NUpdate[]={0x2c,0xf7,0x84,0x87,0x88,0xa1,0x8c,0xe3};


int EnterPassword[]={0x79,0x21,0x92,0x8c,0x0f,0x87,0xab,0x86};
int OOPs[]={0x7f,0x7f,0x7f,0x7f,0x12,0x8c,0xa3,0xa3};
int MisMatchedPassword[]={0x21,0x8c,0x87,0x8f,0x46,0x87,0xa3,0xab};
int MatchedPassword[]={0x21,0x8c,0x87,0x8f,0x46,0xBF,0x8d,0xa3};
						
int PWDDisplayNumber[]={0xff,0xc0,0xf9,0xa4,0xb0,0x99, 0x92, 0x82, 0xf8, 0x80, 0x90,0x88,0x83,0x46,0xa1,0x84,0x8e,0xc2,0x8b,0xcf,0xf1,0x8d,0xc7,0xab,0xa3,0x8c,0x18,0x8f,0x12,0x87,0xe3,0xc1,0x09,0x91,0x24,0xBF};					
						//{ ,0,1,2,3,4,5,6,7,8,9 , a, b, c, d, e, f, g, h, i, j, k, l, n, o, p, q, r, s, t, u, v, x, y, z, -}
						//{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35}		
//int SeTDPSWD[10]={23,23,15,27,19,29,1,2};
//int SeTDPSWD[]={2,1,29,19,27,15,23,23};
int SeTDPSWD[]={1,1,1,1,1,1,1,1};
int CheKPSWD[9];



int PWDCount=0,PWDx=0,DJJ=0,KEY1Count=1;
																			
signed int DataToSegment =0;
int ChKX=0;
int Segment=0,SegNumber;
int ixz, DJ=0,ji,iij;

int ADDi[10]={0,0,0,0,0,0,0,0,0,0};

unsigned char ADDataFetch[40][10]={
								  {' ','I','S',0x0d,'\0'},
								  {' ','C','E',0x0d,'\0'},{' ','C','G',0x0d,'\0'},{' ','F','M',0x0d,'\0'},{' ','F','L',0x0d,'\0'},{' ','N','R',0x0d,'\0'},{' ','N','T',0x0d,'\0'},{' ','D','P',0x0d,'\0'},
								  {' ','D','S',0x0d,'\0'},{' ','M','R',0x0d,'\0'},{' ','T','N',0x0d,'\0'},{' ','C','I',0x0d,'\0'},{'C','M','1',0x0d,'\0'},{'C','M','2',0x0d,'\0'},{'C','M','3',0x0d,'\0'},
								  {' ','Z','I',0x0d,'\0'},{' ','Z','R',0x0d,'\0'},{' ','Z','T',0x0d,'\0'},{' ','T','M',0x0d,'\0'},{' ','A','D',0x0d,'\0'},{' ','B','R',0x0d,'\0'},{' ','D','X',0x0d,'\0'},{' ','T','D',0x0d,'\0'},
								  {' ','D','T',0x0d,'\0'},{' ','G','A',0x0d,'\0'},{' ','H','T',0x0d,'\0'},{' ','M','T',0x0d,'\0'},{' ','S','D',0x0d,'\0'},{' ','T','I',0x0d,'\0'},{' ','T','W',0x0d,'\0'},
								  {' ','T','E',0x0d,'\0'},{' ','T','L',0x0d,'\0'},{' ','I','D',0x0d,'\0'},{' ','R','S',0x0d,'\0'},{' ','I','V',0x0d,'\0'},
								  {' ','G','G',0x0d,'\0'},{' ','G','N',0x0d,'\0'},{' ','G','T',0x0d,'\0'}
								 };	//
unsigned char ADDateGNfetRx[40][15],ADDateGNfetRx1[40][15];

						

int CEZ=0,TacT=0,TactZeroCount=0,PVEZeroes=0,Update[100];
char TactCounter[10];

void OnBoardDisplay(signed int DataToUpdate1);
void OnDisplaynodata(void);
void DisplayPC2EM(void);
void DisplayRT2EM(void);
void DisplayErr(void);
void OnDisplayOVD(void);
void OnDisplayUVD(void);
void DisplayTackCntr(void);

void ADDatabaseManagement(void);
void ADDataFetchTransBus(void);
void ADDataFetchRecevBus(void);

void StartXmit22(unsigned int Bytes);

void CalibrationCheck(void);

void PasswordCheck(void);
void EnterPasswordDisplay(void);
void EnterPasswordByKey(void);
void PWD_Checking(void);

void CalibrationCE(void);
void CalibrationCEN(void);
void SendNetValCont(void);
void deviceStatus(void);
void Stable_Check(void);
void CalSel(void);
void CalProcDisp1(void);
void CalProcDisp2(void);
void CalibrationZero(void);

void ExistValue(void);
void FMExistingValue(int inc1);
void CalParaExistingVal(int inc2);
void SerilaCommExistVal(int inc3);
void CheckWeighExistVal(int inc4);
void StandardExistVal(int inc5);

void FlComand(void);
void FLTxRxCheck(void);

//void FilterMotionKEYCommands(void);
//void FilterMotionComCommands(void);
void FilterMotionKEYCommands(int inc6, int inc7,int inc8 );
void FilterMotionComCommands(int inc9, int inc10, int inc11);
void CalParKEYCommands(int inc12, int inc13,int inc14);
void CalParKEYComCommands(int inc15, int inc16,int inc17);

void CrrntADDBMSUpdation(int upda);
void SoftwareReset(void);

void UpdateDisplay(void);

void CalProc(void);
void SaveFunction(void);

int CalPar[40][25] ;													// this variable used for key pressed count number and to ensurer with char to array numbers 
unsigned char CalcPar[40][15],CalcPar1[40][15],CalcPar2[40][15];		// This variables used to assigned chartonumber `s corresponding characters into an array
																		// for reference and send commands to the AD module
														
unsigned char CalcParFrChkg[40][15]; 					// reference for checking whether existing value is changed 

int Caldisp[11][9]={
						{0x2c,0xf7,0x7f,0xc0,0xa4,0xc7,0x88,0x46},//0
						{0x2c,0xab,0x88,0x8c,0x12,0xc7,0x88,0x46},//1
						{0xc7,0x88,0xc1,0x87,0x12,0xcf,0x09,0x84},//2
						{},										  //3
						{0xab,0x87,0xc8,0xc8,0x2f,0x8f,0x87,0x8E},//4
						{0x2c,0x8f,0x88,0x8c,0x83,0xc7,0x88,0x46},//5
						{0xc8,0xc8,0xa3,0x46,0xc7,0x8f,0x84,0x12},//6
						{0xc2,0x84,0xc1,0xc1,0x8d,0x84,0x8b,0x46},//7
						{0xa1,0x8f,0x88,0xa1,0xab,0x88,0x87,0x12},//8
						{0x2c,0xf7,0x84,0xc1,0x88,0x12,0xff,0xff},//9
						{0x2c,0xbf,0xff,0x87,0xcf,0x46,0xf0,0x84},//10 ---> Exit
						
					};
int Caldisp1[40][9]={
						//Filter  Motion Selection
						{0xa1,0xa3,0xc8,0xc8,0xff,0x8f,0x87,0x8E},//0
						{0x7f,0xc7,0x88,0xc1,0xff,0x8f,0x87,0x8E},//1
						{0xc2,0x8f,0xab,0x87,0xc8,0xc8,0xa3,0xab},//2
						{0xcf,0x87,0xab,0x87,0xc8,0xc8,0xa3,0xab},//3
						{0x2c,0xbf,0xff,0x87,0xcf,0x46,0xf0,0x84},//4--Exit
						//Calibration Parameter Displays
						{0x87,0xab,0xcf,0xa3,0x8c,0x46,0x84,0xa1},//5
						{0x8c,0x84,0x87,0x12,0x8c,0x12,0xcf,0xa1},//6
						{0xc2,0xab,0x88,0x8f,0xc7,0xe3,0xc8,0xc8},//7
						{0x84,0xc7,0xa3,0xc1,0x84,0x8f,0x88,0x87},//8
						{0xcf,0xab,0xcf,0xc8,0xc8,0x87,0x84,0x12},//9
					    {0xF9,0x46,0xf0,0x88,0xc8,0xc8,0x87,0x12},//10
						{0xa4,0x46,0xf0,0x88,0xc8,0xc8,0x87,0x12},//11
						{0xb0,0x46,0xf0,0x88,0xc8,0xc8,0x87,0x12},//12
						{0x79,0xc0,0xBF,0xff,0x87,0xcf,0xab,0xcf},//13
						{0x79,0x84,0xc2,0xab,0x88,0x8f,0xbf,0xc0},//14
						{0x79,0x8d,0x46,0x88,0x8f,0x87,0xBF,0xc0},//15
						{0xa1,0xa3,0xc8,0xc8,0x84,0x8f,0x88,0x87},//16
						{0x2c,0xbf,0xff,0x87,0xcf,0x46,0xf0,0x84},//17--Exit
						//Serial Communication Display
						{0x8F,0xa1,0xa1,0x88,0xbf,0xc1,0x84,0xa1},//18
						{0x84,0x87,0x88,0x8f,0xa1,0xe3,0x88,0x83},//19
						{0xa1,0xa3,0xc8,0xc8,0xc7,0x8f,0x84,0x12},//20
						{0x91,0xc7,0x84,0xa1,0xab,0x88,0x8f,0x87},//21
						{0x2c,0xbf,0xff,0x87,0xcf,0x46,0xf0,0x84},//22--Exit
						//CheckWeigh
						{0xc8,0xc8,0xcf,0x87,0x88,0x87,0xc7,0xa1},//23
						{0x84,0xc2,0x8f,0xc1,0x88,0x87,0x84,0xc2},//24
						{0xc8,0xc8,0xcf,0x87,0xa1,0xc7,0xa3,0x8b},//25
						{0xc8,0xc8,0xcf,0x87,0x8f,0x12,0xc8,0xc8},//26
						{0x91,0xc7,0x84,0xa1,0x8f,0x88,0x87,0x12},//27
						{0xc8,0xc8,0xcf,0x87,0x84,0x8f,0x88,0x87},//28
						{0xab,0xcf,0xc1,0xc1,0x84,0x8f,0x88,0x87},//29
						{0x84,0xc2,0xa1,0x84,0xc2,0xcf,0x8f,0x87},//30
						{0xc7,0xc1,0x84,0xc7,0xc2,0xcf,0x8f,0x87},//31
						{0x2c,0xbf,0xff,0x87,0xcf,0x46,0xf0,0x84},//32--Exit
						//Standard
						{0x8f,0xc8,0xc8,0xe3,0xab,0xbf,0xa1,0xcf},//33
						{0xc7,0x8f,0x84,0x12,0xa1,0x88,0x84,0x8f},//34
						{0xc8,0xc8,0xe3,0xab,0xbf,0x8f,0x84,0xc1},//35
						{0x2c,0xbf,0xff,0x87,0xcf,0x46,0xf0,0x84},//36--Exit
					}; 
					
char DisplayStep[8][6]={
						 {'0','0','1',0x0d,'\0'},
						 {'0','0','2',0x0d,'\0'},
						 {'0','0','5',0x0d,'\0'},
						 {'0','1','0',0x0d,'\0'},
						 {'0','2','0',0x0d,'\0'},
						 {'0','5','0',0x0d,'\0'},
						 {'1','0','0',0x0d,'\0'},
						 {'2','0','0',0x0d,'\0'},	 	
					   };
int DisplaySteps[8][4]={
						{0xf9,0xc0,0xc0},//1
						{0xa4,0xc0,0xc0},//2
						{0x92,0xc0,0xc0},//5
						{0xc0,0xf9,0xc0},//10
						{0xc0,0xa4,0xc0},//20
						{0xc0,0x92,0xc0},//50
						{0xc0,0xc0,0xf9},//100
						{0xc0,0xc0,0xa4},//200	
						};

int inc[100];
int error[100];


int izx=0;
void CalibrationCZ(void);
int overload=0,underload=0;
//for zero reducing 
int ze,zn, dataArray[8],dataElement;
int MinusPot,PVeZeroes,Passwardmatched=0,pDS=0;
int PDKeyCount[10],Sel1r2KeyCount=0;
int izxx=0;
int key1Count=1;//SystemZero=0;

signed int DataAddress1=0;

char DiData[3]={0,0,0};
char CEstring[10],STAstring[10];
int StaCount=0,SavingCount=0,ErrSgnl=0;
//|************** changed*****************************//




void main(void)
{

	
	DISABLE_IRQ				/* Disable interrupts before setting interrupt control register */
	
	mcuinit();
	mcuinit1();
 		//Start1:
	//for(ixz=0;ixz<=0xff;ixz++); 
	Init_Timer1();			/* Initilization of Timer 1 */
	Com0Init();				// tracklogic rtu
	Com1Init();				// back port - scada
	Com2Init();				// weighing system port
	Com6Init();				// display board
	PowerOnInit();
	Start1:
	ENABLE_IRQ				/* Enable interrupts */	
		
	WeighZone=250;
	
	 
		 
	ADDatabaseManagement();

	SetContinous=0;
	CalibrationCE();
	delay(100);
	SetContinous=0;
	Stable_Check();
	delay(100);
	//DIR_SDA_OP=1;
	//DIR_SDA_IP=0;
		//LCD_Main();
		/*
		DIR_SCLK_OP;
		DIR_SDA_OP;
		while(1)
		{
			SDA=1;
			SCL_HI;
			delay(200000);
			SDA=0;
			SCL_LO;
			delay(200000);
			}
		*/
	//WriteDateNTime();
		 
		// delay(100);
		 //delay(100);
		 //delay(100);
	 //ReadDateNTime();
	 //delay(100);
		
	//while(1);

	
	while (1)
	{
		 //I2C_Clock();
		
		
		//if(StaCount>10)    																// changed on 19 -Mar 21 
		if(StaCount>15)
		{
			SetContinous=0;
			Stable_Check();
			delay(50);  // Transmission delay from EM100 to RTU is setted to 100ms 
			StaCount=0;
			
		}
		else
		{
			SetContinous=1;
			StaCount++;
			QueryAD();
			ReadInputs();
		}
		
		//	QueryAD();
       	//	ReadInputs();
		
		if (ADFailStatus ||NoSamplesError || BlinkSpeed) 
		{
			 OnAlarm;
			 p2_0=1;
			 p2_1=0;
			 OnDisplaynodata();
			
		}     	
		else 
		{
			 OffAlarm;
			 p2_0=0;
			 p2_1=1;
			// OUTDataAddress=0x02;
			 
		}				        
	//	ProcessByte();
	//	ProcessCommands();
	
	/*********Changed ****************/
	// comport checking -
	
	//ProcessByte1();

	
	/***********/
	
		ProcessByteFlint();
		
		ProcessFlintech();
	 
		ProcessByteTLUnit();
		
		if (OneSecond) 
		{
			if (OForced > 0 ) 
			{
				for(TCounter=0;TCounter<(DOMS+DOMS_Pseudo)*8;TCounter++)
				{
					if (OTimerRun[TCounter]==1)
					{
						OTimer[TCounter]--;
						if (OTimer[TCounter]<=0) 
						{
							OTimerRun[TCounter]=0;
							SetOChannelStatus(TCounter+1, ONextStatus[TCounter],DefaultOTime);
							OForced--;
						}
					}
				}											
			}
			if (IForced > 0 ) 
			{
				for(TCounter=0;TCounter<(DIMS+DIMS_Pseudo)*8;TCounter++) 
				{
					if (ITimerRun[TCounter]==1) 
					{
						ITimer[TCounter]--;
						if (ITimer[TCounter]<=0) 
						{
							ITimerRun[TCounter]=0;
							SetIChannelStatus(TCounter+1, INextStatus[TCounter]);
							IForced--;
						}
					}
				}											
			}	
			PCFailCount++;
			if (PCFailCount >1)
			{ 
			    PCFailCount =0;
				StxReceived = 0;
			}							
     		OneSecond=0; 
			LED2 ^= 1 ;
			
		
			
			if (SetSpeed)
		    {
				if (BlinkSpeed) 
				{
	/*   changed   ****/
					// if direction is not set then advance overspeed
					if (Direction==0) 
					{//changed 
						BlinkAdvanceOSLP;OffOverSpeedLP;
					}
					else 
					{//changed
					 	BlinkSpeedLP;OffAdvanceOSLP;
					}
					//changed  
					BlinkSpeedRelay;
					/*   changed   ****/				
					
					//OnOverSpeedAlarm;

				}
				else 
				{	
					// if direction is not set then advance overspeed
					// off advance overspeed lamp if direction is set
					
					if (Direction==0) 
					{//changed
						OnAdvanceOSLP;OffOverSpeedLP;
					}
					else 
					{//changed	
						OffOverSpeedLP;OffAdvanceOSLP;
					}
					//changed	
					OnOverSpeedRelay;
					//OffOverSpeedAlarm;
				}
			}
			else
			{
				//changed 
				BlinkSpeed=0;
				//changed 	
				OffOverSpeedLP;OffAdvanceOSLP;
				//changed
					OffOverSpeedRelay;
				
				//OffOverSpeedAlarm;
			}
		}
		
		
		if (ReplyAvailable) 
		{
			ReplyAvailable=0;
			StartXmit1(NoOfBytes);
			
			//changed 
		//	StartXmit1(NoOfBytes);
			
		}	
		if (SendToRemote) 
		{
			SendToRemote=0;
			DPos=2;
			if (DisplayAxCount && SysInWLMode) 
			{
				if (AxlesWeighed > 0) 
				{	DataToUpdate=AxlesWeighed;DPos=0;}
				else {DataToUpdate=WeightToUpdate;}
			}
			else 
			{ DataToUpdate=WeightToUpdate;	}
			
			//OnBoardDisplay(DataToUpdate);
			
			FormRemotePack();
		}	
		
//		if (SendToRemote1) {
//			SendToRemote1=0;
//			FormRemotePack1();
//		}																										
		if (OneByOneSet) 
		{
			SendNextAxle();
		}
		
		//for(iij=0;iij<2;iij++)
		{
			OnBoardDisplay(DataToUpdate);
		}
			//PC to EM calibration communication setting  
			

	//}
			
			CalibrationCheck();
			ProcessBytesPCUnit(DataToUpdate);
			ProcessBytesFromPCUnit();
		SendByte0();							// tracklogic rtu
		SendByte1();							// back port scada
		SendByte2();							// weighing system
		SendByte6();							// display board
		
		/*
		if(SignalStable==0)
				{SetContinous=0;
					Stable_Check();
				//SetContinous=1;
				//goto Start1;
				}
				else
				{
					SetContinous=1;	
				}
				*/
				/*
				SetContinous=0;*/
				//Stable_Check();
			//	SetContinous=1;
			//ReadDateNTime();
	 //delay(100);
	if(Update[1]>0)
	{
		p2_7=1;
	}
	else
	{
		p2_7=0;
	}
	//ReadDateNTime();
	 //delay(100);
				
	};
	
}
//|********************Changed*******************************//
void CalibrationCheck(void)
{
	
		if(KEY1==0)
		{
			CalibrationZero();
			/*
			StaCount=0;
			
			while(KEY1==0);
			delay(20000);
			//Stable_Check();
			TemporaryWeight=DataToUpdate;
			if(TemporaryWeight>=450)
			{
				delay(20000);
				p2_3=1;
				for(izx=0;izx<1000;izx++)
				{
					DisplayErr();
				}
				
				for(izx=0;izx<1000;izx++)
				{
					OnBoardDisplay(DataToUpdate);
				}
			//	CharIn[2]=0;
			//	CharOut[2]=0;
				p2_3=0;
				delay(20000);
				return;	
			}	
			else if(TemporaryWeight<450)
			{
				SetContinous=0;
				p2_2=1;
				delay(20000);
				INT1=1;
			    CalibrationCZ();
				for(izx=0;izx<200;izx++);
				///*
				//CharIn[2]=0;
				//CharOut[2]=0;
				//*/
				/*
				DataToUpdate=0xffffffff;
				CurrentWeight=0xffffffff;
				 WeightToUpdate=0xffffffff;
				 //include  //
				 
				 //SetContinous=1;
				 //SendNetValCont();
				 //EnquireWt();
				 delay(20000);
				p2_2=0;
				return ;
			}
			*/	
				
			
		}
		if(KEY3==0)
		{
			SetContinous=0;
			CalibrationCE();
			delay(100);
			while(KEY3==0);
			for(izx=0;izx<5000;izx++){
			DisplayTackCntr();}
			
			//EWriteDateNTime();
			delay(2000);
			ReadDateNTime();
			EReadDateNTime();
	 //delay(100);
			delay(20000);
			//ReadDateNTime();
	 //delay(100);
			delay(2000);
			return; 
		}	
		if(KEY4==0)
		{
			while(KEY1);   // until KEY1 is pressing, system will wait
			
			if(KEY1==0)
			{
			//	Stable_Check();
				PasswordCheck();
				//if(Passwar;dmatched)
				{
					/*
					if
					while(KEY2!=0)
					{
						PC_LDU_CAL=1;
						DIRECT_LDU_CAL=0;
						DisplayPC2EM();
					}*/
				}
				//else
				{
					
				}
			}
			/*
			while(KEY1!=0)
			{
				while(!(KEY2==0))
				{
					PC_LDU_CAL=1;
					DIRECT_LDU_CAL=0;
					DisplayPC2EM();
				}
			}*/
			//start();
			ADDatabaseManagement();
				
		}
		return ;
}
void Stable_Check(void)
{			
	deviceStatus();delay(50);
}
void PasswordCheck(void)
{
	for(pDS=0;pDS<=2000;pDS++)
	{
		EnterPasswordDisplay();
	}
	EnterPasswordByKey();
}
void EnterPasswordDisplay(void)
{
	for(DJ=0;DJ<8;DJ++)
		{
		  	KEYDecoder=DisplaySelect[DJ];
			ModuleAddress=EnterPassword[DJ];
			//ModuleAddress=DisplayNumber[DJ];
			delay(100);
			
		}
}
void ADDatabaseManagement(void)
{
	ADDi[0]=0;ADDi[1]=0;ADDi[2]=0;ADDi[3]=0;ADDi[4]=0;
	CharOut[2]=0;
	for(ADDi[0]=0;ADDi[0]<38;ADDi[0]++)
	{
		u1tbl='\r';
		ADDataFetchTransBus();
		u1tbl='\n';
		delay(1000);
	}
	
	// used to check the database has been changed or not 
	// comment this and use these while in saving check changes happen 
	// this prevents ensure the tac counter not to change unnessecarily
	/*
	if(ADDi[6]==0)
	{
		for(ADDi[2]=0;ADDi[2]<38;ADDi[2]++)
		{
			for(ADDi[4]=0;ADDi[4]<9;ADDi[4]++)
			{
				
				if((ADDateGNfetRx[ADDi[2]][ADDi[4]] =='\r')||(ADDateGNfetRx[ADDi[2]][ADDi[4]] =='\n')||(ADDateGNfetRx[ADDi[2]][ADDi[4]] ==0x0a)||(ADDateGNfetRx[ADDi[2]][ADDi[4]] ==0x0d)) 
				{ADDi[4]=10;
				delay(1000);
				u1tbl='\n';
				u1tbl='\r';}
				else
				{
					u1tbl=ADDateGNfetRx[ADDi[2]][ADDi[4]];
					ADDateGNfetRx1[ADDi[2]][ADDi[4]]=ADDateGNfetRx[ADDi[2]][ADDi[4]];								
					delay(1000);
				}
			
			}
			u1tbl='\n';
			u1tbl='\r';
		}
		ADDi[6]=1;
	}
	
	SavingCount=0;
	for(ADDi[2]=0;ADDi[2]<38;ADDi[2]++)
	{
		for(ADDi[4]=0;ADDi[4]<9;ADDi[4]++)
		{
				
			if((ADDateGNfetRx1[ADDi[2]][ADDi[4]] =='\r')||(ADDateGNfetRx1[ADDi[2]][ADDi[4]] =='\0')||(ADDateGNfetRx1[ADDi[2]][ADDi[4]] ==0x0a)||(ADDateGNfetRx1[ADDi[2]][ADDi[4]] ==0x0d)) 
			{ADDi[4]=10;}
			else
			{
			 if(ADDateGNfetRx1[ADDi[2]][ADDi[4]]==ADDateGNfetRx[ADDi[2]][ADDi[4]]){SavingCount++;}	
			}
		}
		if(SavingCount>=37){p2_7=0;p2_6=1;}else{p2_6=0;p2_7=1;}	
		
	}
	//////////till this Database management checking 
	u1tbl='\n';
		delay(10000);
		u1tbl='\n';
		delay(10000);
		u1tbl=CharToNumber[SavingCount];
		delay(10000);
		u1tbl='\n';
		delay(10000);
		u1tbl='\n';
		delay(10000);
		*/
}

void ADDataFetchTransBus(void)
{
	CharIn[2]=0;
	CharOut[2]=0;
	if(ADDi[1]<38)
	{
		for(ADDi[3]=0;ADDi[3]<4;ADDi[3]++)
		{
			
			//u1tbl=ADDataFetch[ADDi[1]][ADDi[3]];
			u2tbl=ADDataFetch[ADDi[1]][ADDi[3]];
			delay(10000);
			
		}
		ADDi[1]++;
		//delay(20000);
		if(ADDi[2]<38)
		{
			for(ADDi[4]=0;ADDi[4]<12;ADDi[4]++)
			{
			
				if (CharOut[2] >= 100) {CharOut[2]=0;}
				delay(2000);
				CharRcvd=CharRTable[2][CharOut[2]++];
				
				//u1tbl=CharRcvd;
				ADDateGNfetRx[ADDi[2]][ADDi[4]]=CharRcvd;
				
				u1tbl=ADDateGNfetRx[ADDi[2]][ADDi[4]];
											//comment this line while despatching 
				
				if ((CharRcvd =='\r')||(CharRcvd =='\n')||(CharRcvd ==0x0a)||(CharRcvd ==0x0d)) {ADDi[4]=12;}
				
			
			}
			ADDateGNfetRx[ADDi[2]][ADDi[4]]='\0';
			ADDi[2]++;
		
		}
		else
		{
			ADDi[2]=0;
		}
		
	}
	else
	{
		ADDi[1]=0;
	}
	
}
/*
void ADDataFetchRecevBus(void)
{
	
	if(ADDi[2]<26)
	{
		for(ADDi[4]=0;ADDi[4]<10;ADDi[4]++)
		{
			
			
			delay(100);
			CharRcvd=CharRTable[2][CharOut[2]];
			ADDateGNfetRx[ADDi[2]][ADDi[4]]=CharRcvd;
			
		}
		//u1tbl='\n';
		ADDi[2]++;
		
	}
	else
	{
		ADDi[2]=0;
	}
}

*/
void EnterPasswordByKey(void)
{
	/*
	DJJ=8;
	PWDCount=0;
	PWDx=8;
	
	while(KEY1Count!=2)
	{
		if(KEY4==0)
		{
			while(KEY4==0);
			++KEY1Count;
		}
		if(KEY3==0)
		{
			while(KEY3==0);
			if(DJJ<=0){DJJ=8;}else{CheKPSWD[DJJ]=PWDCount;DJJ--;;PWDCount=0;}
		}	
		if(KEY2==0)
		{
			while(KEY2==0);
			if(PWDCount>35){PWDCount=0;}else{PWDCount++;}
		}
		
		KEYDecoder=DisplaySelect[PWDx];
		ModuleAddress=PWDDisplayNumber[PWDCount];
		delay(100);
		for(PWDx=8;PWDx>=DJJ;PWDx--)
		{
			KEYDecoder=DisplaySelect[PWDx];
			ModuleAddress=PWDDisplayNumber[CheKPSWD[PWDx]];
			delay(100);
		}
	}
	*/
	DJJ=7;
	PWDCount=0;
	//PWDx=8;
	CheKPSWD[DJJ]=PWDCount;
	
	while(KEY1Count!=2)
	{
		if(KEY4==0)
		{
			while(KEY4==0);
			++KEY1Count;
		}
		if(KEY3==0)
		{
			while(KEY3==0);
			if(DJJ<=-1){DJJ=7;}else{CheKPSWD[DJJ]=PWDCount;--DJJ;PWDCount=0;}
		}	
		if(KEY2==0)
		{
			while(KEY2==0);
			if(PWDCount>34){PWDCount=0;}else{PWDCount++;}
		}
		if(KEY1==0)
		{
			while(KEY1==0);
			if(PWDCount<0){PWDCount=34;}else{PWDCount--;}
		}
		
		
		KEYDecoder=DisplaySelect[DJJ];
		ModuleAddress=PWDDisplayNumber[PWDCount];
		delay(100);
		for(PWDx=7;PWDx>DJJ;PWDx--)
		{
			KEYDecoder=DisplaySelect[PWDx];
			ModuleAddress=PWDDisplayNumber[CheKPSWD[PWDx]];
			delay(100);
		}
	}
	KEY1Count=1;
   
   /*************************************/
   	
	PWD_Checking(); //-------------------------->966 line
	
	/*************************************/
	
	return ;
}
void PWD_Checking(void)
{
	Passwardmatched=0;
		for(PWDx=0;PWDx<8;PWDx++)
		{
			if(SeTDPSWD[PWDx]!=CheKPSWD[PWDx])
			{
				
				break;
			}
			else 
			{
				++Passwardmatched;
			}
		}
			for(pDS=0;pDS<=2000;pDS++)
			{
				for(DJJ=8;DJJ>=0;DJJ--)
				{
					
				  	KEYDecoder=DisplaySelect[DJJ];
					ModuleAddress=PWDDisplayNumber[CheKPSWD[DJJ]];
					delay(100);
			
				}
			}
		if(Passwardmatched<7)
		{
			for(pDS=0;pDS<=2000;pDS++)
			{
				for(DJ=0;DJ<8;DJ++)
				{
				  	KEYDecoder=DisplaySelect[DJ];
					ModuleAddress=OOPs[DJ];
					delay(100);
			
				}
			}
			for(pDS=0;pDS<=2000;pDS++)
			{
				for(DJ=0;DJ<8;DJ++)
				{
				  	KEYDecoder=DisplaySelect[DJ];
					ModuleAddress=MisMatchedPassword[DJ];
					//ModuleAddress=DisplayNumber[DJ];
					delay(100);
			
				}
			}
		}
		else
		{
			for(pDS=0;pDS<=2000;pDS++)
			{
				for(DJJ=0;DJJ<8;DJJ++)
				{
				  	KEYDecoder=DisplaySelect[DJJ];
					ModuleAddress=MatchedPassword[DJJ];
					//ModuleAddress=DisplayNumber[DJ];
					delay(100);
			
				}
			}
			
			/*************************************----->1039*/
			
			CalSel();
			
			/*************************************/
		}
}
void CalSel(void)
{
	while((KEY1)&&(KEY2));
	if(KEY1==0)
	{
		while(KEY1==0);
		PC_LDU_CAL=0;
		DIRECT_LDU_CAL=1;
		for(iij=0;iij<2000;iij++)
		{
		DisplayRT2EM();}
		
		/*************************************/
		CalProc();
		/*************************************/
	}
	if(KEY2==0)
	{
		
		while((KEY2==0));
		while(KEY1!=0)
		{
				
			PC_LDU_CAL=1;
			DIRECT_LDU_CAL=0;
			DisplayPC2EM();
			
		}
		start();	
	}			
}
void CalProc(void)
{
	inc[1]=0;
	CalPar[0][20]=1;
	//while((KEY4==1)
	inc[3]=0;
	inc[4]=0;
	inc[23]=0;
	inc[7]=0;
	inc[5]=0;
	
	while(CalPar[0][20]==1)
	{
		
		if((inc[1]==2)||(inc[1]==3)){inc[1]=4;continue;}else{
		CalProcDisp1();
		}
		
		if((KEY3==0)&&(inc[1]==0))
		{
			while(KEY3==0);
			CalibrationZero();	
		}
		
		if((KEY3==0)&&(inc[1]==1))
		{
			//while(KEY3==0);
			//CalProcDisp1();
			while(KEY3==0);
			inc[1]=2;
			CalProcDisp1();
			while(KEY3==0);
			while((KEY1==1)&&(KEY2==1)&&(inc[1]==2))
			{
				
				{ExistValue();}
			}
			
			//while((KEY1==0)||(KEY2==0));
			if(KEY2==0){while(KEY2==0);inc[1]=1;}else
			{
				FlComand();	
				if(Update[0]==1)
				{
					FLTxRxCheck();
					if(Update[1]<=37)
					{Update[1]++;}else{Update[1]=1;}
					//return ;//main();
						//ADDatabaseManagement();	
				}		
				else
				{
					if(Update[1]>-1)
					{Update[1]--;}
				}
			}
			inc[1]=1;
		}	
		
		// Filter and motion block settings code 
		if((KEY3==0)&&(inc[1]==4))
		{
			while(KEY3==0);
			inc[2]=0;
			inc[3]=0;
			inc[8]=3;
			inc[12]=0;
			while(inc[3]==0)
			{
				if(inc[2]<=4)
				{
					CalProcDisp2();
				
				}
				if((KEY3==0)&&(inc[2]<=3))
				{
					while(KEY3==0);
					
					
					{
						while((KEY1==1)&&(KEY4==1))
						{
							FMExistingValue(inc[2]);
						}
						if(KEY1==0)
						{
							while(KEY1==0);
							inc[12]=1;
						}
						if(KEY4==0)
						{
							while(KEY4==0);
						}
						
					}
				}
				
				if((inc[12]==1)&&(inc[2]==0))
				{
					inc[12]=0;
					//while(KEY3==1)
					{
						CalPar[3][23]=1;
						CalPar[3][24]=1;
						
						FilterMotionKEYCommands(inc[2]+3,CalPar[3][23],CalPar[3][24]);  // Command array number, number of digits, numbers range allowed eg. 3 array, one digits, range 0&1
						//FilterMotionKEYCommands();        commented on 31-DEC-2020
						if(Update[3]>0)
						{
							FilterMotionComCommands(inc[2]+3,CalPar[3][23],CalPar[3][24]=5);
						}
					}
					inc[2]=0;
					inc[3]=0;
				}
				
				if((inc[12]==1)&&(inc[2]==1))
				{
					inc[12]=0;
					{
						CalPar[4][23]=1;
						CalPar[4][24]=8;
						FilterMotionKEYCommands(inc[2]+3,CalPar[4][23],CalPar[4][24]);
						//FilterMotionKEYCommands();        commented on 31-DEC-2020
						
						if(Update[4]>0)
						{
							FilterMotionComCommands(inc[2]+3,CalPar[4][23],CalPar[4][24]=5);
						}
					}
					inc[2]=1;
					inc[3]=0;
				}
				
				if((inc[12]==1)&&(inc[2]==2))
				{
					inc[12]=0;
					CalPar[5][23]=5;
					CalPar[5][24]=9;
					FilterMotionKEYCommands(inc[2]+3,CalPar[5][23],CalPar[5][24]);
						if(Update[5]>0)
						{
							FilterMotionComCommands(inc[2]+3,CalPar[5][23],CalPar[5][24]=10);
						}
					inc[2]=2;
					inc[3]=0;
				}
				if((inc[12]==1)&&(inc[2]==3))
				{
					inc[12]=0;
					CalPar[6][23]=5;
					CalPar[6][24]=9;
					FilterMotionKEYCommands(inc[2]+3,CalPar[6][23],CalPar[6][24]);
						if(Update[6]>0)
						{
							FilterMotionComCommands(inc[2]+3,CalPar[6][23],CalPar[6][24]=10);
						}
					inc[2]=3;
					inc[3]=0;
				}
				
				if(KEY2==0)
				{ while(KEY2==0);
					if(inc[2]<5){inc[2]++;}else{inc[2]=0;}
				}
				if(KEY1==0)
				{while(KEY1==0);
				 if(inc[2]>0){inc[2]--;}else{inc[2]=4;}
				}
				
				
				
				if((KEY3==0)&&(inc[2]==4))
				{
					while(KEY3==0);
					delay(1000);
					inc[3]=1;
					break;
				}
				else
				{
					inc[3]=0;
				}
				
			}
			
		}
		//Calibration Parameters Display and Settings blocks 
		if((KEY3==0)&&(inc[1]==5))
		{
			while(KEY3==0);
			inc[2]=5;
			inc[4]=0;
			while(inc[4]==0) // Exit 
			{
				if(inc[2]<18)
				{
					CalProcDisp2();	
				}
				if((KEY3==0)&&(inc[2]<17)&&(inc[2]>4))
				{
					while(KEY3==0);
					u1tbl=CharToNumber[inc[2]]; delay(10000);
					while((KEY1==1)&&(KEY4==1))
					{
						CalParaExistingVal(inc[2]+2);
					}
					if((inc[2]+2)==11)
					{
						KEYDecoder=DisplaySelect[6];
						ModuleAddress=0xff;
						delay(500);	
					}
					if(KEY1==0)
					{
						while(KEY1==0);
						inc[27]=1;
					}
					if(KEY4==0)
					{
					
						while(KEY4==0);
					}
					
				}
	//-------------------------------------------------------------------------0 & 1 s alone****************
	
				
				if((inc[27]==1)&&(inc[2]==7))
				{
					inc[27]=0;
					//while(KEY3==1)
					{
						CalPar[9][23]=1;
						CalPar[9][24]=1;
						
						CalParKEYCommands(inc[2]+2,CalPar[9][23],CalPar[9][24]);  // Command array number, number of digits, numbers range allowed eg. 3 array, one digits, range 0&1
						//FilterMotionKEYCommands();        commented on 31-DEC-2020
						if(Update[9]>0)
						{
							CalParKEYComCommands(inc[2]+2,CalPar[9][23],CalPar[9][24]=5);
						}
					}
					inc[2]=7;
					inc[4]=0;
				}
				if((inc[27]==1)&&(inc[2]==8))
				{
					inc[27]=0;
					//while(KEY3==1)
					{
						CalPar[10][23]=1;
						CalPar[10][24]=1;
						
						CalParKEYCommands(inc[2]+2,CalPar[10][23],CalPar[10][24]);  // Command array number, number of digits, numbers range allowed eg. 3 array, one digits, range 0&1
						//FilterMotionKEYCommands();        commented on 31-DEC-2020
						if(Update[10]>0)
						{
							CalParKEYComCommands(inc[2]+2,CalPar[10][23],CalPar[10][24]=5);
						}
					}
					inc[2]=8;
					inc[4]=0;
				}if((inc[27]==1)&&(inc[2]==16))
				{
					inc[27]=0;
					//while(KEY3==1)
					{
						CalPar[18][23]=1;
						CalPar[18][24]=1;
						
						CalParKEYCommands(inc[2]+2,CalPar[18][23],CalPar[18][24]);  // Command array number, number of digits, numbers range allowed eg. 3 array, one digits, range 0&1
						//FilterMotionKEYCommands();        commented on 31-DEC-2020
						if(Update[18]>0)
						{
							CalParKEYComCommands(inc[2]+2,CalPar[18][23],CalPar[18][24]=5);
						}
					}
					inc[2]=16;
					inc[4]=0;
				}
				//***********************************************0 to 5*******************************
				if((inc[27]==1)&&(inc[2]==5))
				{
					inc[27]=0;
					{
						CalPar[7][23]=1;
						CalPar[7][24]=5;
						CalParKEYCommands(inc[2]+2,CalPar[7][23],CalPar[7][24]);// Command array number, number of digits, numbers range allowed eg. 3 array, one digits, range 0&1
						//FilterMotionKEYCommands();        commented on 31-DEC-2020
						
						if(Update[7]>0)
						{
							CalParKEYComCommands(inc[2]+2,CalPar[7][23],CalPar[7][24]=5);
						}
					}
					inc[2]=5;
					inc[4]=0;
				}
				//*****************************Display Step********************************
				if((inc[27]==1)&&(inc[2]==6))
				{
					inc[27]=0;
					{
						CalPar[8][23]=0;
						CalPar[8][24]=7;
						CalParKEYCommands(inc[2]+2,CalPar[8][23],CalPar[8][24]);// Command array number, number of digits, numbers range allowed eg. 3 array,Starting range , ending
						//FilterMotionKEYCommands();        commented on 31-DEC-2020
						
						if(Update[8]>0)
						{
							CalParKEYComCommands(inc[2]+2,CalPar[8][23],CalPar[8][24]=8);
						}
					}
					inc[2]=6;
					inc[4]=0;
				}
				
				//*****************Zero Track----------------------------------------
				
					if((inc[27]==1)&&(inc[2]==15))
				{
					inc[27]=0;
					{
						CalPar[17][23]=3;
						CalPar[17][24]=9;
						CalParKEYCommands(inc[2]+2,CalPar[17][23],CalPar[17][24]);// Command array number, number of digits, numbers range allowed eg. 3 array, one digits, range 0&1
						//FilterMotionKEYCommands();        commented on 31-DEC-2020
						
						if(Update[17]>0)
						{
							CalParKEYComCommands(inc[2]+2,CalPar[17][23],CalPar[17][24]=8);
						}
					}
					inc[2]=15;
					inc[4]=0;
				}
			//---------------------------------------  0 to 99999**********************************
				if((inc[27]==1)&&(inc[2]==9))
				{
					inc[27]=0;
					CalPar[11][23]=5;
					CalPar[11][24]=9;
					u1tbl=CharToNumber[inc[2]]; delay(10000);
					CalParKEYCommands(inc[2]+2,CalPar[11][23],CalPar[11][24]);// Command array number, number of digits, numbers range allowed eg. 3 array, one digits, range 0&1
						if(Update[11]>0)
						{
							CalParKEYComCommands(inc[2]+2,CalPar[11][23],CalPar[11][24]=10);
						}
					inc[2]=9;
					inc[4]=0;
				}
				if((inc[27]==1)&&(inc[2]==10))
				{
					inc[27]=0;
					CalPar[12][23]=5;
					CalPar[12][24]=9;
					u1tbl=CharToNumber[inc[2]]; delay(10000);
					CalParKEYCommands(inc[2]+2,CalPar[12][23],CalPar[12][24]);
						if(Update[12]>0)
						{
							CalParKEYComCommands(inc[2]+2,CalPar[12][23],CalPar[12][24]=10);
						}
					inc[2]=10;
					inc[4]=0;
				}
				if((inc[27]==1)&&(inc[2]==11))
				{
					inc[27]=0;
					CalPar[13][23]=5;
					CalPar[13][24]=9;
					u1tbl=CharToNumber[inc[2]]; delay(10000);
					CalParKEYCommands(inc[2]+2,CalPar[13][23],CalPar[13][24]);
						if(Update[13]>0)
						{
							CalParKEYComCommands(inc[2]+2,CalPar[13][23],CalPar[13][24]=10);
						}
					inc[2]=11;
					inc[4]=0;
				}
				if((inc[27]==1)&&(inc[2]==12))
				{
					inc[27]=0;
					CalPar[14][23]=5;
					CalPar[14][24]=9;
					u1tbl=CharToNumber[inc[2]]; delay(10000);
					CalParKEYCommands(inc[2]+2,CalPar[14][23],CalPar[14][24]);
						if(Update[14]>0)
						{
							CalParKEYComCommands(inc[2]+2,CalPar[14][23],CalPar[14][24]=10);
						}
					inc[2]=12;
					inc[4]=0;
				}
				if((inc[27]==1)&&(inc[2]==13))
				{
					inc[27]=0;
					CalPar[15][23]=5;
					CalPar[15][24]=9;
					u1tbl=CharToNumber[inc[2]]; delay(10000);
					CalParKEYCommands(inc[2]+2,CalPar[15][23],CalPar[15][24]);
						if(Update[15]>0)
						{
							CalParKEYComCommands(inc[2]+2,CalPar[15][23],CalPar[15][24]=10);
						}
					inc[2]=13;
					inc[4]=0;
				}
				if((inc[27]==1)&&(inc[2]==14))
				{
					inc[27]=0;
					CalPar[16][23]=5;
					CalPar[16][24]=9;
					u1tbl=CharToNumber[inc[2]]; delay(10000);
					CalParKEYCommands(inc[2]+2,CalPar[16][23],CalPar[16][24]);
						if(Update[16]>0)
						{
							CalParKEYComCommands(inc[2]+2,CalPar[16][23],CalPar[16][24]=10);
						}
					inc[2]=14;
					inc[4]=0;
				}
				
				
				
				if(KEY2==0)
				{
					while(KEY2==0);
					if(inc[2]<18){++inc[2];}else{inc[2]=5;}
				}
				if(KEY1==0)
				{
					while(KEY1==0);
					if(inc[2]>5){--inc[2];}else{inc[2]=17;}
				}
				if((KEY3==0)&&(inc[2]==17))
				{while(KEY3==0);delay(1000);inc[4]=1;}
				else
				{
					inc[4]=0;
				}
				
			}
		}
		//Serial Communications Block
		if((KEY3==0)&&(inc[1]==6))
		{
			while(KEY3==0);
			inc[2]=18;
			inc[5]=0;
			while(inc[5]==0)
			{
				if(inc[2]<23)
				{
					CalProcDisp2();	
				}
					
				if((KEY3==0)&&(inc[2]<22)&&(inc[2]>17))
				{
					while(KEY3==0);
					while(KEY1==1)
					{
						SerilaCommExistVal(inc[2]+1);
					}
					
				}
				
				if(KEY2==0)
				{
					while(KEY2==0);
					if(inc[2]<23){++inc[2];}else{inc[2]=18;}	u1tbl=CharToNumber[inc[2]]; delay(10000);
				}
				if(KEY1==0)
				{
					while(KEY1==0);
					if(inc[2]>18){--inc[2];}else{inc[2]=22;}  u1tbl=CharToNumber[inc[2]]; delay(10000);
				}
				if((KEY3==0)&&((inc[2]==22)||(inc[2]==23)))
				{while(KEY3==0);delay(1000);inc[5]=1;}
					else
				{
					inc[5]=0;
				}
			}
		}
		//Check Weigh parameters Block
		if((KEY3==0)&&(inc[1]==7))
		{
			while(KEY3==0);
			inc[2]=23;
			inc[23]=0;
			while(inc[23]==0)
			{
				if(inc[2]<33)
				{
					CalProcDisp2();	
				}
				if((KEY3==0)&&(inc[2]<31)&&(inc[2]>22))
				{
					while(KEY3==0);
					while(KEY1==1)
					{
						CheckWeighExistVal(inc[2]);
					}
					
				}
				if(KEY2==0)
				{
					while(KEY2==0);
					if(inc[2]<33){inc[2]++;}else{inc[2]=23;}
				}
				if(KEY1==0)
				{
					while(KEY1==0);
					if(inc[2]>23){inc[2]--;}else{inc[2]=32;}
				}
				if((KEY3==0)&&(inc[2]==32))
				{while(KEY3==0);delay(1000);inc[23]=1;}
			
				else
				{
					inc[23]=0;
				}
			}
		}
		//Standards Display Blocks 
		if((KEY3==0)&&(inc[1]==8))
		{
			while(KEY3==0);
			inc[2]=33;
			inc[7]=0;
			while(inc[7]==0)
			{
				if(inc[2]<37)
				{
					CalProcDisp2();	
				}
				
				if((KEY3==0)&&(inc[2]<35)&&(inc[2]>32))
				{
					while(KEY3==0);
					while(KEY1==1)
					{
						StandardExistVal(inc[2]-1);
					}
					
				}
				if(KEY2==0)
				{
					while(KEY2==0);
					if(inc[2]<37){++inc[2];}else{inc[2]=33;}
				}
				if(KEY1==0)
				{
					while(KEY1==0);
					if(inc[2]>33){--inc[2];}else{inc[2]=36;}
				}
				if((KEY3==0)&&(inc[2]==36))
				{while(KEY3==0);delay(1000);inc[7]=1;break;}
				else
				{
					inc[7]=0;
				}
			}
		}
		//if(((KEY3==0)&&(inc[1]==9))||(CalPar[0][21]==1))
		if((KEY3==0)&&(inc[1]==9))
		{
			while(KEY3==0);
			while((KEY2)&&(KEY1));
			if(KEY1==0)
			{
				while(KEY1==0);
				SaveFunction();
				
				inc[1]=10;
				for(CalPar[39][22]=0;CalPar[39][22]<39;CalPar[39][22]++){
				Update[CalPar[39][22]]=0;}
				
			}
			if(KEY2==0)
			{
				while(KEY2==0);
				Update[0]=0;
				inc[1]=10;
				SoftwareReset();
				 start();
			}
			
				
		}
		
		if((KEY3==0)&&(inc[1]==10))
		{
			while((KEY3==0));
			for(CalPar[39][22]=0;CalPar[39][22]<39;)
			{
					u1tbl=CharToNumber[CalPar[39][22]];
					delay(1000);
					u1tbl=' ';
					delay(1000);
					u1tbl=CharToNumber[Update[CalPar[39][22]]];
					delay(1000);
					u1tbl='\n';
					delay(1000);
					u1tbl='\r';
					delay(1000);
				if(Update[CalPar[39][22]]>0)
				{
					inc[1]=9;
					CalPar[0][21]=1;
					CalPar[39][22]=40;
				}
				else 
				{
					CalPar[0][21]=3;
					CalPar[39][22]++;
					if((CalPar[39][22]>=38)&&(CalPar[0][21]==3))
					{
						CalPar[0][20]=2;
						//start();
						return ;
				 
					}
				}
			}
		}
		
		if(KEY2==0)
		{
			while(KEY2==0);
				
				if((inc[1]==2)||(inc[1]==3)){inc[1]=4;continue;}else{if(inc[1]>=10){inc[1]=0;}else{inc[1]++;}}	
			//inc[1]++;
		}
		if(KEY1==0)
		{
			while(KEY1==0);
				
				if((inc[1]==2)||(inc[1]==3)||(inc[1]==4)){inc[1]=1;continue;}else if(inc[1]>-1){inc[1]--;}else {inc[1]=10;}
			//inc[1]++;
		}
	}
	
}
void CalProcDisp1(void)
{
	while((KEY4==1)&&(KEY3==1)&&(KEY2==1)&&(KEY1==1))
	{
		for(inc[0]=0;inc[0]<8;inc[0]++)
		{
			KEYDecoder=DisplaySelect[inc[0]];
			ModuleAddress=Caldisp[inc[1]][inc[0]];
			delay(100);
		}
	};
}
void CalProcDisp2(void)
{
	while((KEY4==1)&&(KEY3==1)&&(KEY2==1)&&(KEY1==1))
	{
		for(inc[0]=0;inc[0]<8;inc[0]++)
		{
			KEYDecoder=DisplaySelect[inc[0]];
			ModuleAddress=Caldisp1[inc[2]][inc[0]];
			delay(100);
		}
	};
}
void ExistValue(void)
{
	//for(inc[4]=0;inc[4]<200;inc[4]++)
	{
    	inc[5]=0;
		for(inc[2]=7;inc[2]>=2;)
		{
			//u1tbl=CharToNumber[inc[2]];
			//delay(1000);
			//u1tbl=CharToNumber[inc[1]];
			//delay(1000);
			for(inc[3]=0;inc[3]<10;inc[3]++)
			{
				if(CharToNumber[inc[3]]==ADDateGNfetRx[inc[1]][inc[2]])//if(CharToNumber[inc[3]]==ADDateGNfetRx[inc[1]][inc[2]])try out 
				{
					if(inc[5]==6){inc[5]=0;}//else{inc[5]++;}
					KEYDecoder=DisplaySelect[inc[5]++];
				 	ModuleAddress=DisplayNumber[inc[3]];
				 	//u1tbl=CharToNumber[inc[3]];
					delay(1000);
					//inc[2]++;
					inc[2]--;
					inc[3]=10;
					
							
				}	
			}
		}
		//inc[2]=7;
		//inc[3]=0;
	}
	//return ;
}
void FMExistingValue(int inc1)
{
	inc[8]=inc1;
	if((inc[8]==0)||(inc[8]==1))
	{
		inc[9]=6;
	}
	if((inc[8]==2)||(inc[8]==3))
	{
		inc[9]=7;
	}
	inc[5]=0;
	for(inc[10]=inc[9];inc[10]>=2;)
	{
		for(inc[3]=0;inc[3]<10;inc[3]++)
		{
			if(CharToNumber[inc[3]]==ADDateGNfetRx[inc[8]+3][inc[10]])
			{
				if(inc[5]==6){inc[5]=0;}
				KEYDecoder=DisplaySelect[inc[5]++];
				ModuleAddress=DisplayNumber[inc[3]];
				delay(1000);
				inc[10]--;
				inc[3]=10;
			}
		}
	}
	return;
}
void CalParaExistingVal(int inc2)
{
	inc[11]=inc2;
	if((inc[11]==7)||(inc[11]==8)||(inc[11]==9))
	{
		inc[12]=6;
	}
	if((inc[11]==11)||(inc[11]==12)||(inc[11]==13)||(inc[11]==14)||(inc[11]==15)||(inc[11]==16))
	{
		inc[12]=7;
	}
	if((inc[11]==10)||(inc[11]==17)||(inc[11]==18))
	{
		inc[12]=4;
	}
	inc[5]=0;
	if(inc[11]==11)
	{
		KEYDecoder=DisplaySelect[6];
		ModuleAddress=0xbf;
		delay(500);	
	}
	else
	{
		KEYDecoder=DisplaySelect[6];
		ModuleAddress=0xff;
	}
		
	for(inc[13]=inc[12];inc[13]>=2;)
	{
		for(inc[3]=0;inc[3]<10;inc[3]++)
		{
			if(CharToNumber[inc[3]]==ADDateGNfetRx[inc[11]][inc[13]])
			{
				if(inc[5]==6){inc[5]=0;}
				KEYDecoder=DisplaySelect[inc[5]++];
				ModuleAddress=DisplayNumber[inc[3]];
				delay(1000);
				inc[13]--;
				inc[3]=10;
			}
		}
	}
	return;
}
void SerilaCommExistVal(int inc3)
{
	inc[14]=inc3;
	if((inc[14]==20))
	{
		inc[15]=7;
	}
	if(inc[14]==22)
	{
		inc[15]=6;
	}
	if((inc[14]==19)||(inc[14]==21))
	{
		inc[15]=4;
	}
	inc[5]=0;
	for(inc[16]=inc[15];inc[16]>=2;)
	{
		for(inc[3]=0;inc[3]<10;inc[3]++)
		{
			if(CharToNumber[inc[3]]==ADDateGNfetRx[inc[14]][inc[16]])
			{
				if(inc[5]==6){inc[5]=0;}
				KEYDecoder=DisplaySelect[inc[5]++];
				ModuleAddress=DisplayNumber[inc[3]];
				delay(1000);
				inc[16]--;
				inc[3]=10;
			}
		}
	}
	return;
}
void CheckWeighExistVal(int inc4)
{
	inc[17]=inc4;
	
	if((inc[17]==23)||(inc[17]==24)||(inc[17]==25)||(inc[17]==26)||(inc[17]==27)||(inc[17]==28)||(inc[17]==29)||(inc[17]==31))
	{
		inc[18]=6;
	}
	if((inc[17]==30))
	{
		inc[18]=4;
	}
	inc[5]=0;
	for(inc[19]=inc[18];inc[19]>=2;)
	{
		for(inc[3]=0;inc[3]<10;inc[3]++)
		{
			if(CharToNumber[inc[3]]==ADDateGNfetRx[inc[17]][inc[19]])
			{
				if(inc[5]==6){inc[5]=0;}
				KEYDecoder=DisplaySelect[inc[5]++];
				ModuleAddress=DisplayNumber[inc[3]];
				delay(1000);
				inc[19]--;
				inc[3]=10;
			}
		}
	}
	return;
}
void StandardExistVal(int inc5)
{
	inc[20]=inc5;

	//if((inc[20]==20)||(inc[20]==21))
	{
		inc[21]=5;
	}
	inc[5]=0;
	for(inc[22]=inc[21];inc[22]>=2;)
	{
		for(inc[3]=0;inc[3]<10;inc[3]++)
		{
			if(CharToNumber[inc[3]]==ADDateGNfetRx[inc[20]][inc[22]])
			{
				if(inc[5]==6){inc[5]=0;}
				KEYDecoder=DisplaySelect[inc[5]++];
				ModuleAddress=DisplayNumber[inc[3]];
				delay(1000);
				inc[22]--;
				inc[3]=10;
			}
		}
	}
	return;
}
void FlComand(void)
{
	error[3]=0;
	CalPar[0][13]=1;
	CalPar[0][7]=5;
	CalPar[0][9]=0;
	inc[6]=5;
	while(CalPar[0][13]!=2) //Exit/ ok button pressed check condition 
	{
	
			if(KEY2==0)
			{
				while(KEY2==0);
				if(CalPar[0][9]<10)
				{
					CalPar[0][9]++; 
				}
				else
				{
					CalPar[0][9]=0;
				}
				
			}
			if(KEY1==0)
			{
				while(KEY1==0);
				
				if(CalPar[0][9]>0)
				{
					CalPar[0][9]--;
				}
				else
				{
					CalPar[0][9]=9;
				}
				/*
				if(KEY1==0)
				{
					while(KEY1==0);
					return ;
				}	*/
				
				
			}
			if(KEY3==0)
			{
				while(KEY3==0);
				CalcPar[1][inc[6]+1]=CharToNumber[CalPar[0][9]];
				//need to comment this line after cheking
				u1tbl=CalcPar[1][inc[6]+1];
				//
				if(CalPar[0][7]>-1){
				CalPar[0][CalPar[0][7]--]=CalPar[0][9];}else{CalPar[0][7]=5;}
				if(inc[6]>-1)
				{	
					inc[6]--;
				}
				else
				{
					inc[6]=5;
				}
				CalPar[0][9]=0;
			}
			
			if((KEY4==0)&&(CalPar[0][13]==1))
			{
				while(KEY4==0);
				while((KEY1==1)&&(KEY2==1))
				{
					UpdateDisplay();
				}
				if(KEY1==0)
				{
					while(KEY1==0);
					Update[0]=1;
					CalPar[0][13]=2;
					
				}
				if((KEY2==0))
				{
					Update[0]=0;
					CalPar[0][13]=2;
					CharIn[2]=0;
					CharOut[2]=0;
				}
				CalPar[0][13]=2;
				
			}
			KEYDecoder=DisplaySelect[inc[6]];
			ModuleAddress=DisplayNumber[CalPar[0][9]];
			delay(100);
			
		for(CalPar[0][10]=5;CalPar[0][10]>inc[6];CalPar[0][10]--)
		{
			KEYDecoder=DisplaySelect[CalPar[0][10]];
			ModuleAddress=PWDDisplayNumber[CalPar[0][CalPar[0][10]]+1];
			delay(100);
		}
			
	}
	CalPar[0][13]=1;
	p2_7=1;
	CharIn[2]=0;
	CharOut[2]=0;
	
	//return ;
}
void FLTxRxCheck(void)
{
	error[0]=0;
	CharIn[2]=0;
	CharOut[2]=0;
	CalcPar[0][0]=' ';
	CalcPar[0][1]='C';
	CalcPar[0][2]='E';
	CalcPar[0][3]=' ';
	CalcPar[0][4]=ADDateGNfetRx[1][2];
	CalcPar[0][5]=ADDateGNfetRx[1][3];
	CalcPar[0][6]=ADDateGNfetRx[1][4];
	CalcPar[0][7]=ADDateGNfetRx[1][5];
	CalcPar[0][8]=ADDateGNfetRx[1][6];
	CalcPar[0][9]=0x0d;
	for(CalPar[0][15]=0;CalPar[0][15]<10;CalPar[0][15]++)
	{
		u1tbl=CalcPar[0][CalPar[0][15]];
		u2tbl=CalcPar[0][CalPar[0][15]];
		delay(10000);
	}
	
	for(CalPar[0][16]=0;CalPar[0][16]<3;CalPar[0][16]++)
	{
		CharRcvd=CharRTable[2][CharOut[2]];
		if(CharOut[2]>100)
		{
			CharOut[2]=0;CalPar[0][16]=0;
		}
		else
		{
			CharOut[2]++;
		}
		delay(20000);
		if((CharRcvd==0x0d)||(CharRcvd=='\n')||(CharRcvd=='\r'))
		{ 
			u1tbl='\n';
			continue;
		}
		else
		{	
			CalcPar1[2][CalPar[0][16]]=CharRcvd;
		}
		u1tbl=CharRcvd;
		
	}
	for(CalPar[0][16]=0;CalPar[0][16]<3;CalPar[0][16]++)
	{
		delay(20000);
		u1tbl=CalcPar1[2][CalPar[0][16]];
		delay(2000);
		
	}
	if((CalcPar1[2][0]=='O')||(CalcPar1[2][0]=='K')||(CalcPar1[2][1]=='K'))
	{
		p2_7=0;
		CharIn[2]=0;
		CharOut[2]=0;
		CalcPar[2][0]='C';
		CalcPar[2][1]='G';
		CalcPar[2][2]=' ';
		CalcPar[2][3]=CalcPar[1][6];
		CalcPar[2][4]=CalcPar[1][5];
		CalcPar[2][5]=CalcPar[1][4];
		CalcPar[2][6]=CalcPar[1][3];
		CalcPar[2][7]=CalcPar[1][2];
		CalcPar[2][8]=CalcPar[1][1];
		CalcPar[2][9]=0x0d;
		
		for(CalPar[0][15]=0;CalPar[0][15]<10;CalPar[0][15]++)
		{
			u1tbl=CalcPar[2][CalPar[0][15]];
			u2tbl=CalcPar[2][CalPar[0][15]];
			delay(10000);
			//u1tbl=CharToNumber[CalPar[0][15]];
			//delay(10000);
		}
	//Error or ok indicationg functions
	u1tbl='\n';
	 
		for(CalPar[1][16]=0;CalPar[1][16]<3;CalPar[1][16]++)
		{
			CharRcvd=CharRTable[2][CharOut[2]];
			if(CharOut[2]>=100)
			{
				CharOut[2]=0;CalPar[0][16]=0;
			}
			else
			{
				CharOut[2]++;
			}
			delay(20000);
			if((CharRcvd==0x0d)||(CharRcvd=='\n')||(CharRcvd=='\r'))
			{ 
				u1tbl='\n';
				continue;
			}
			else
			{	
				CalcPar1[3][CalPar[1][16]]=CharRcvd;
			}
				u1tbl=CharRcvd;
		
		}
		u1tbl='\n';
		for(CalPar[1][16]=0;CalPar[1][16]<3;CalPar[1][16]++)
		{
			delay(20000);
			u1tbl=CalcPar1[3][CalPar[1][16]];
			delay(2000);
		}
		u1tbl='\n';
		if((CalcPar1[3][0]=='O')||(CalcPar1[3][0]=='K')||(CalcPar1[3][1]=='K')||(CalcPar1[3][1]=='O'))
		{
			p2_6=0;
			CharIn[2]=0;
			CharOut[2]=0;
			CalPar[0][14]=2;                    //used in CrrntADDBMSUpdation(CalPar[inc9][1]); function 
			CrrntADDBMSUpdation(CalPar[0][14]);
		}
		else
		{
			DisplayErr();
			delay(50000);
			p2_6=1;
			delay(50000);
		}
		//CalPar[0][14]=2;
	}
	else
	{
		DisplayErr();
		p2_6=1;
		
	}
	 //CalPar[0][14]=2;	
	 //CrrntADDBMSUpdation(CalPar[0][14]);
	 //CalPar[0][15]=2;
	
}

void FilterMotionKEYCommands(int inc6,int inc7,int inc8)
{
	error[4]=0;
	CalPar[inc6][13]=1;
	CalPar[inc6][7]=4;
	//CalPar[3][7]=5;
	CalPar[inc6][9]=0;
	inc[24]=0;
	inc[25]=4;
	
	if(inc6==3||inc6==4)
	{
		CalcParFrChkg[inc6][6]=ADDateGNfetRx[inc6][6];
	}
	else if(inc6==5||inc6==6)
	{
		for(CalPar[inc6][22]=3;CalPar[inc6][22]<=7;CalPar[inc6][22]++)
		{
			CalcParFrChkg[inc6][CalPar[inc6][22]]=ADDateGNfetRx[inc6][CalPar[inc6][22]];
		}
	}
	while((CalPar[inc6][13]!=2))
	{
		if(KEY2==0)
		{	while(KEY2==0);
			if(CalPar[inc6][9]<=inc8-1)
			{
				CalPar[inc6][9]++;
			}
			else
			{
				CalPar[inc6][9]=0;
			}
		}
		
		
		if(inc6==3||inc6==4)
		{
			if(((KEY3==0)||(KEY4==0))&&(CalPar[inc6][13]==1))
			{
				//CalPar[inc6][9]=0;
				//Update[inc6]=0;
				while((KEY3==0)||(KEY4==0));
				CalcPar[inc6][inc[24]+1]=CharToNumber[CalPar[inc6][9]];
				u1tbl=CalcPar[inc6][inc[24]+1];//needed to be commented 
				{
					if(CalcParFrChkg[inc6][6]!=CharToNumber[CalPar[inc6][9]])
					{
						while((KEY1==1)&&(KEY2==1))
						{
							UpdateDisplay();
						}
						if(KEY1==0)
						{
							while(KEY1==0);
							Update[inc6]++;
							CalPar[inc6][13]=2;
						
						}
						if(KEY2==0)
						{
							while(KEY2==0);
							Update[inc6]=0;
							CalPar[inc6][13]=2;
							CharIn[2]=0;
							CharOut[2]=0;
						}
					
					}
					CalPar[inc6][9]=0;
				}
				CalPar[inc6][13]=2;
			}
			KEYDecoder=DisplaySelect[inc[24]];
			ModuleAddress=DisplayNumber[CalPar[inc6][9]];
			delay(100);
		}
		
		if(inc6==5||inc6==6)
		{
			if(KEY1==0)
			{
				while(KEY1==0);
				
				if(CalPar[inc6][9]>-1)
				{
					CalPar[inc6][9]--;
				}
				else
				{
					CalPar[inc6][9]=9;
				}
			}
			
			if(KEY3==0)
			{
				
				while(KEY3==0);
				CalcPar[inc6][7-inc[25]]=CharToNumber[CalPar[inc6][9]];
				u1tbl=CalcPar[inc6][7-inc[25]];
				if(inc[25]>-1)
				{
					inc[25]--;
				}
				else
				{
					inc[25]=4;
				}
				delay(10000);
				if(CalPar[inc6][7]>-1)
				{
					CalPar[inc6][CalPar[inc6][7]--]=CalPar[inc6][9];
				}
				else
				{
					CalPar[inc6][7]=4;
				}
				
				CalPar[inc6][9]=0;
			}
				
			
			if((KEY4==0)&&(CalPar[inc6][13]==1))
			{
				//Update[inc6]=0;
				while((KEY4==0));
				//CalcPar[inc6][inc[25]+1]=CharToNumber[CalPar[inc6][9]];
				//u1tbl=CalcPar[inc6][inc[24]+1];//needed to be commented 
				for(CalPar[inc6][22]=3;CalPar[inc6][22]<=7;CalPar[inc6][22]++)
				{
					/*
					u1tbl=CalcPar[inc6][CalPar[inc6][22]];
					delay(10000);
					*/
					if(CalcParFrChkg[inc6][CalPar[inc6][22]]!=CalcPar[inc6][CalPar[inc6][22]])
					{
						CalPar[inc6][22]=7;
						while((KEY1==1)&&(KEY2==1))
						{
							UpdateDisplay();
						}
						if(KEY1==0)
						{
							while(KEY1==0);
							Update[inc6]++;
							CalPar[inc6][13]=2;
						
						}
						if(KEY2==0)
						{
							while(KEY2==0);
							Update[inc6]=0;
							CalPar[inc6][13]=2;
							CharIn[2]=0;
							CharOut[2]=0;
						}
					
					}
					
				}
				CalPar[inc6][13]=2;
			}
			
			KEYDecoder=DisplaySelect[inc[25]];
			ModuleAddress=DisplayNumber[CalPar[inc6][9]];
			delay(100);
			for(inc[26]=4;inc[26]>inc[25];inc[26]--)
			{	
				KEYDecoder=DisplaySelect[inc[26]];
				ModuleAddress=PWDDisplayNumber[CalPar[inc6][inc[26]]+1];
				delay(100);	
			}
		}
	}
	CalPar[inc6][13]=1;
	CharIn[2]=0;
	CharOut[2]=0;
	return ;
		
}
void FilterMotionComCommands(int inc9,int inc10,int inc11)
{
	error[0]=0;
	CharIn[2]=0;
	CharOut[2]=0;
	if((inc9==3)||(inc9==4))
	{
			CalcPar2[inc9][0]=' ';
			CalcPar2[inc9][1]=' ';
			CalcPar2[inc9][2]=' ';
			CalcPar2[inc9][3]='F';
			if(inc9==3){CalcPar2[inc9][4]='M';} else if (inc9==4){CalcPar2[inc9][4]='L';}
			CalcPar2[inc9][5]=' ';
			CalcPar2[inc9][6]=CalcPar[inc9][1];
			CalcPar2[inc9][7]=0x0d;
	}
	else if((inc9==5)||(inc9==6))
	{
			CalcPar2[inc9][0]=' ';
			CalcPar2[inc9][1]=' ';
			CalcPar2[inc9][2]=' ';
			CalcPar2[inc9][3]='N';
			if(inc9==5){CalcPar2[inc9][4]='R';} else if (inc9==6){CalcPar2[inc9][4]='T';}
			CalcPar2[inc9][5]=' ';
			CalcPar2[inc9][6]=CalcPar[inc9][3];
			CalcPar2[inc9][7]=CalcPar[inc9][4];
			CalcPar2[inc9][8]=CalcPar[inc9][5];
			CalcPar2[inc9][9]=CalcPar[inc9][6];
			CalcPar2[inc9][10]=CalcPar[inc9][7];
			CalcPar2[inc9][11]=0x0d;
		
	}
	for(CalPar[inc9][15]=0;CalPar[inc9][15]<inc11+3;CalPar[inc9][15]++)
	{
		u2tbl=CalcPar2[inc9][CalPar[inc9][15]];
		u1tbl=CalcPar2[inc9][CalPar[inc9][15]];
		delay(10000);
	}
	for(CalPar[inc9][16]=0;CalPar[inc9][16]<3;CalPar[inc9][16]++)
	{
		CharRcvd=CharRTable[2][CharOut[2]];
		if(CharOut[2]>=100)
		{
			CharOut[2]=0;
			CalPar[inc9][16]=0;
		}
		else
		{
			CharOut[2]++;
		}
		delay(20000);
		if((CharRcvd==0x0d)||(CharRcvd=='\n')||(CharRcvd=='\r')){ 
			u1tbl='\n';
			continue;}
		else
		{
			CalcPar1[inc9][CalPar[inc9][16]]=CharRcvd;
			u1tbl=CharRcvd;
		}
		for(CalPar[inc9][16]=0;CalPar[inc9][16]<3;CalPar[inc9][16]++)
		{
			delay(20000);
			u1tbl=CalcPar1[inc9][CalPar[inc9][16]];
			delay(2000);
		}
		if((CalcPar1[inc9][0]=='O')||(CalcPar1[inc9][0]=='K')||(CalcPar1[inc9][1]=='K'))
		{
			p2_7=0;
			CharIn[2]=0;
			CharOut[2]=0;
			CalPar[inc9][1]=inc9;                       //used in CrrntADDBMSUpdation(CalPar[inc9][1]); function 
			CrrntADDBMSUpdation(CalPar[inc9][1]);
		}
		else
		{
			DisplayErr();
			p2_7=1;
		}
	}	
	
}
void CalParKEYCommands(int inc12, int inc13,int inc14)
{
	error[4]=0;
	CalPar[inc12][13]=1;
	CalPar[inc12][14]=1;
	CalPar[inc12][15]=1;
	CalPar[inc12][7]=4;
	//CalPar[3][7]=5;
	CalPar[inc12][9]=0;
	inc[24]=0;
	inc[25]=4;
	
	
	if(inc12==9||inc12==18||inc12==7)
	{
		CalcParFrChkg[inc12][6]=ADDateGNfetRx[inc12][6];
	}
	else if(inc12==10)
	{
		CalcParFrChkg[inc12][4]=ADDateGNfetRx[inc12][4];
	}
	else if(inc12==11||inc12==12||inc12==13||inc12==14||inc12==15||inc12==16)
	{
		for(CalPar[inc12][22]=3;CalPar[inc12][22]<=7;CalPar[inc12][22]++)
		{
			CalcParFrChkg[inc12][CalPar[inc12][22]]=ADDateGNfetRx[inc12][CalPar[inc12][22]];
		}
	}
	else if(inc12==8)
	{
		for(CalPar[inc12][22]=4;CalPar[inc12][22]<=6;CalPar[inc12][22]++)
		{
			CalcParFrChkg[inc12][CalPar[inc12][22]]=ADDateGNfetRx[inc12][CalPar[inc12][22]];
			u1tbl=ADDateGNfetRx[inc12][CalPar[inc12][22]];
			delay(1000);
		}
		u1tbl=CharToNumber[inc12];
		delay(1000);
		u1tbl=CharToNumber[inc13];
		delay(1000);
		u1tbl=CharToNumber[inc14];
		delay(1000);
		//inc12 is 8 the array
		// inc 13 is starting of array elements
		//inc 14 is ending if an array to select perticular option provided 
		CalPar[inc12][16]=inc13;
		CalPar[inc12][17]=inc14;
		while(CalPar[inc12][15]==1)
		{		
			if(CalPar[inc12][16]<0)
			{
				CalPar[inc12][16]=7;
			}
			if(CalPar[inc12][16]>=8)
			{
				CalPar[inc12][16]=0;	
			}
			if(KEY1==0)
			{
				while(KEY1==0);
				CalPar[inc12][16]--;
			}
			if(KEY2==0)
			{
				CalPar[inc12][16]++;
				while(KEY2==0);
			}
			/*
			if((KEY3==0))
			{
				while(KEY3==0);
			}
			*/
			if((KEY4==0))
			{
				while((KEY4==0));
				for(CalPar[inc12][22]=4,CalPar[inc12][18]=0;CalPar[inc12][22]<=6,CalPar[inc12][18]<3;CalPar[inc12][22]++,CalPar[inc12][18]++)
				{
					CalcPar[inc12][CalPar[inc12][22]]=DisplayStep[CalPar[inc12][16]][CalPar[inc12][18]];
					u1tbl=CalcPar[inc12][CalPar[inc12][22]];
					delay(10000);
				}
				
				
				for(CalPar[inc12][22]=4;CalPar[inc12][22]<=6;CalPar[inc12][22]++)
					{
						/*
						u1tbl=CalcPar[inc12][CalPar[inc12][22]];
						delay(10000);
						*/
						if(CalcParFrChkg[inc12][CalPar[inc12][22]]!=CalcPar[inc12][CalPar[inc12][22]])
						{
							CalPar[inc12][22]=8;
							while((KEY1==1)&&(KEY2==1))
							{
								UpdateDisplay();
							}
							if(KEY1==0)
							{
								while(KEY1==0);
								Update[inc12]++;
								CalPar[inc12][13]=2;
						
							}
							if(KEY2==0)
							{
								while(KEY2==0);
								Update[inc12]=0;
								CalPar[inc12][13]=2;
								CharIn[2]=0;
								CharOut[2]=0;
							}
					
						}
					
					}
					CalPar[inc12][14]=2;
					CalPar[inc12][13]=2;
					CalPar[inc12][7]=4;
				
				
				CalPar[inc12][15]=2;
				CalPar[inc12][14]=2;
				CalPar[inc12][13]=2;
			}
			for(CalPar[inc12][18]=0;CalPar[inc12][18]<3;CalPar[inc12][18]++)
			{
				KEYDecoder=DisplaySelect[CalPar[inc12][18]];
				ModuleAddress=DisplaySteps[CalPar[inc12][16]][CalPar[inc12][18]];
				delay(200);
			}
			delay(100);
			
		};
	}
	else if(inc12==17)
	{
		/*
		u1tbl='\n';
		delay(1000);
		for(CalPar[inc12][22]=2;CalPar[inc12][22]<=4;CalPar[inc12][22]++)
		{
			CalcParFrChkg[inc12][CalPar[inc12][22]]=ADDateGNfetRx[inc12][CalPar[inc12][22]];
			u1tbl=ADDateGNfetRx[inc12][CalPar[inc12][22]];
			delay(1000);
		}
		*/
		
		CalPar[inc12][17]=2;//st digit maximum number allowed
		//CalPar[inc12][18]=5// if 1st digit 2 ,  and 3 rd digit should not be grater than 5
		CalPar[inc12][19]=2;// initial position
		//CalPar[inc12][20]=2;
		while((CalPar[inc12][14]!=2))
		{
			if(KEY2==0)
			{	while(KEY2==0);
				if(CalPar[inc12][19]==2)
				{
					if(CalPar[inc12][9]<=1)
					{
						CalPar[inc12][9]++;
					}
					else
					{
						CalPar[inc12][9]=0;
					}
				}
				else
				{
					if(CalPar[inc12][9]<=inc14-1)
					{
						CalPar[inc12][9]++;
					}
					else
					{
						CalPar[inc12][9]=0;
					}
				}
			}
			//if(inc12==8)
			{
				/*
				if(KEY1==0)
				{
					while(KEY1==0);
				
					if(CalPar[inc12][9]>-1)
					{
						CalPar[inc12][9]--;
					}
					else
					{
						CalPar[inc12][9]=9;
					}
				}
				*/
				if(KEY3==0)
				{
					while(KEY3==0);
					if((CalPar[inc12][19]==2)&&(CalPar[inc12][9]>=2))
					{
						CalPar[inc12][19]=1;
						//CalPar[inc12][20]=CalPar[inc12][9];
						inc14=5;
					}
					else if((CalPar[inc12][19]==2)&&(CalPar[inc12][9]<2))
					{
						CalPar[inc12][19]=1;
						inc14=9;
					}
				
					//while(KEY3==0);
					
					CalcPar[inc12][7-inc[25]]=CharToNumber[CalPar[inc12][9]];
					u1tbl=CalcPar[inc12][7-inc[25]];
					if(inc[25]>=2)
					{
						inc[25]--;
					}
					else
					{
						inc[25]=4;
						CalPar[inc12][19]=2;
					}
					delay(10000);
					if(CalPar[inc12][7]>2)
					{
						CalPar[inc12][CalPar[inc12][7]--]=CalPar[inc12][9];
					}
					else
					{
						CalPar[inc12][7]=4;
					}
				
					CalPar[inc12][9]=0;
				}
				
			
				if((KEY4==0)&&(CalPar[inc12][14]==1))
				{
					//Update[inc6]=0;
					while((KEY4==0));
					//CalcPar[inc6][inc[25]+1]=CharToNumber[CalPar[inc6][9]];
					//u1tbl=CalcPar[inc6][inc[24]+1];//needed to be commented 
					for(CalPar[inc12][22]=3;CalPar[inc12][22]<6;CalPar[inc12][22]++)
					{
						
						/*
						u1tbl=CalcParFrChkg[inc12][CalPar[inc12][22]-1];
						delay(10000);
						u1tbl=CalcPar[inc12][CalPar[inc12][22]];
						delay(10000);
						u1tbl='\t';
						delay(10000);
						*/
						if(CalcParFrChkg[inc12][CalPar[inc12][22]-1]!=CalcPar[inc12][CalPar[inc12][22]])
						{
							CalPar[inc12][22]=8;
							while((KEY1==1)&&(KEY2==1))
							{
								UpdateDisplay();
							}
							if(KEY1==0)
							{
								while(KEY1==0);
								Update[inc12]++;
								CalPar[inc12][13]=2;
						
							}
							if(KEY2==0)
							{
								while(KEY2==0);
								Update[inc12]=0;
								CalPar[inc12][13]=2;
								CharIn[2]=0;
								CharOut[2]=0;
							}
					
						}
					
					}
					CalPar[inc12][14]=2;
					CalPar[inc12][13]=2;
					CalPar[inc12][15]=2;
					CalPar[inc12][7]=4;
				}
			
				
				KEYDecoder=DisplaySelect[inc[25]-2];
				ModuleAddress=DisplayNumber[CalPar[inc12][9]];
				delay(100);
				for(inc[26]=4;inc[26]>inc[25];inc[26]--)
				{	
					KEYDecoder=DisplaySelect[inc[26]-2];
					ModuleAddress=PWDDisplayNumber[CalPar[inc12][inc[26]]+1];
					//ModuleAddress=PWDDisplayNumber[CalPar[inc12][inc[26]]];
					delay(100);	
				}
			
			}
		}
		
	}
	while((CalPar[inc12][13]!=2))
	{
		if(KEY2==0)
		{	while(KEY2==0);
			if(CalPar[inc12][9]<=inc14-1)
			{
				CalPar[inc12][9]++;
			}
			else
			{
				CalPar[inc12][9]=0;
			}
		}
		
	
		
		if(inc12==9||inc12==10||inc12==18||inc12==7)
		{
			if(((KEY3==0)||(KEY4==0))&&(CalPar[inc12][13]==1))
			{
				//CalPar[inc6][9]=0;
				//Update[inc6]=0;
				
				while((KEY3==0)||(KEY4==0));
				if(inc12==10)
				{
					CalcPar[inc12][inc[24]+1]=CharToNumber[CalPar[inc12][9]];
					u1tbl=CalcPar[inc12][inc[24]+1];//needed to be commented 
					//{
						if(CalcParFrChkg[inc12][4]!=CharToNumber[CalPar[inc12][9]])
						{
							while((KEY1==1)&&(KEY2==1))
							{
								UpdateDisplay();
							}
							if(KEY1==0)
							{
								while(KEY1==0);
								Update[inc12]++;
								CalPar[inc12][13]=2;
						
							}
							if(KEY2==0)
							{
								while(KEY2==0);
								Update[inc12]=0;
								CalPar[inc12][13]=2;
								CharIn[2]=0;
								CharOut[2]=0;
							}
					
						}
				}
				else
				{
					CalcPar[inc12][inc[24]+1]=CharToNumber[CalPar[inc12][9]];
					u1tbl=CalcPar[inc12][inc[24]+1];//needed to be commented 
					{
						if(CalcParFrChkg[inc12][6]!=CharToNumber[CalPar[inc12][9]])
						{
							while((KEY1==1)&&(KEY2==1))
							{
								UpdateDisplay();
							}
							if(KEY1==0)
							{
								while(KEY1==0);
								Update[inc12]++;
								CalPar[inc12][13]=2;
						
							}
							if(KEY2==0)
							{
								while(KEY2==0);
								Update[inc12]=0;
								CalPar[inc12][13]=2;
								CharIn[2]=0;
								CharOut[2]=0;
							}
					
						}
						CalPar[inc12][9]=0;
					}
				}
				CalPar[inc12][13]=2;
			}
			KEYDecoder=DisplaySelect[inc[24]];
			ModuleAddress=DisplayNumber[CalPar[inc12][9]];
			delay(100);
		}
		
		if(inc12==11||inc12==12||inc12==13||inc12==14||inc12==15||inc12==16)
		{
			if(KEY1==0)
			{
				while(KEY1==0);
				
				if(CalPar[inc12][9]>-1)
				{
					CalPar[inc12][9]--;
				}
				else
				{
					CalPar[inc12][9]=9;
				}
			}
			
			if(KEY3==0)
			{
				
				while(KEY3==0);
				CalcPar[inc12][7-inc[25]]=CharToNumber[CalPar[inc12][9]];
				u1tbl=CalcPar[inc12][7-inc[25]];
				if(inc[25]>-1)
				{
					inc[25]--;
				}
				else
				{
					inc[25]=4;
				}
				delay(10000);
				if(CalPar[inc12][7]>-1)
				{
					CalPar[inc12][CalPar[inc12][7]--]=CalPar[inc12][9];
				}
				else
				{
					CalPar[inc12][7]=4;
				}
				
				CalPar[inc12][9]=0;
			}
				
			
			if((KEY4==0)&&(CalPar[inc12][13]==1))
			{
				//Update[inc6]=0;
				while((KEY4==0));
				//CalcPar[inc6][inc[25]+1]=CharToNumber[CalPar[inc6][9]];
				//u1tbl=CalcPar[inc6][inc[24]+1];//needed to be commented 
				for(CalPar[inc12][22]=3;CalPar[inc12][22]<=7;CalPar[inc12][22]++)
				{
					/*
					u1tbl=CalcPar[inc12][CalPar[inc12][22]];
					delay(10000);
					*/
					if(CalcParFrChkg[inc12][CalPar[inc12][22]]!=CalcPar[inc12][CalPar[inc12][22]])
					{
						CalPar[inc12][22]=7;
						while((KEY1==1)&&(KEY2==1))
						{
							UpdateDisplay();
						}
						if(KEY1==0)
						{
							while(KEY1==0);
							Update[inc12]++;
							CalPar[inc12][13]=2;
						
						}
						if(KEY2==0)
						{
							while(KEY2==0);
							Update[inc12]=0;
							CalPar[inc12][13]=2;
							CharIn[2]=0;
							CharOut[2]=0;
						}
					
					}
					
				}
				CalPar[inc12][13]=2;
			}
			
			
			KEYDecoder=DisplaySelect[inc[25]];
			ModuleAddress=DisplayNumber[CalPar[inc12][9]];
			delay(100);
			for(inc[26]=4;inc[26]>inc[25];inc[26]--)
			{	
				KEYDecoder=DisplaySelect[inc[26]];
				ModuleAddress=PWDDisplayNumber[CalPar[inc12][inc[26]]+1];
				delay(100);	
			}
		}
	}
	CalPar[inc12][13]=1;
	CharIn[2]=0;
	CharOut[2]=0;
	return ;
		
}

void CalParKEYComCommands(int inc15, int inc16,int inc17)
{
	error[0]=0;
	CharIn[2]=0;
	CharOut[2]=0;
	CalcPar[0][0]=' ';
	CalcPar[0][1]='C';
	CalcPar[0][2]='E';
	CalcPar[0][3]=' ';
	CalcPar[0][4]=ADDateGNfetRx[1][2];
	CalcPar[0][5]=ADDateGNfetRx[1][3];
	CalcPar[0][6]=ADDateGNfetRx[1][4];
	CalcPar[0][7]=ADDateGNfetRx[1][5];
	CalcPar[0][8]=ADDateGNfetRx[1][6];
	CalcPar[0][9]=0x0d;
	for(CalPar[0][15]=0;CalPar[0][15]<10;CalPar[0][15]++)
	{
		u1tbl=CalcPar[0][CalPar[0][15]];
		u2tbl=CalcPar[0][CalPar[0][15]];
		delay(10000);
	}
	
	for(CalPar[0][16]=0;CalPar[0][16]<3;CalPar[0][16]++)
	{
		CharRcvd=CharRTable[2][CharOut[2]];
		if(CharOut[2]>100){CharOut[2]=0;CalPar[0][16]=0;
		}else{CharOut[2]++;}
		delay(20000);
		
		
		
		if((CharRcvd==0x0d)||(CharRcvd=='\n')||(CharRcvd=='\r')){ 
		u1tbl='\n';
		continue;}
		else
		{	CalcPar1[2][CalPar[0][16]]=CharRcvd;}
		u1tbl=CharRcvd;
		
	}
	for(CalPar[0][16]=0;CalPar[0][16]<3;CalPar[0][16]++)
	{
		delay(20000);
		u1tbl=CalcPar1[2][CalPar[0][16]];
		delay(2000);
		
	}
	if((CalcPar1[2][0]=='O')||(CalcPar1[2][0]=='K')||(CalcPar1[2][1]=='K'))
	{
		
		p2_7=0;
		error[0]=0;
		CharIn[2]=0;
		CharOut[2]=0;
		if((inc15==7)||(inc15==9)||(inc15==10)||(inc15==18))
		{
				CalcPar2[inc15][0]=' ';
				CalcPar2[inc15][1]=' ';
				CalcPar2[inc15][2]=' ';
				
				if(inc15==7)
				{
					CalcPar2[inc15][3]='D';
					CalcPar2[inc15][4]='P';
				} 
				else if (inc15==9)
				{
					CalcPar2[inc15][3]='M';
					CalcPar2[inc15][4]='R';
				}
				else if(inc15==10)
				{
					CalcPar2[inc15][3]='T';
					CalcPar2[inc15][4]='N';
				} 
				else if (inc15==18)
				{
					CalcPar2[inc15][3]='T';
					CalcPar2[inc15][4]='M';
				}
				CalcPar2[inc15][5]=' ';
				CalcPar2[inc15][6]=CalcPar[inc15][1];
				CalcPar2[inc15][7]=0x0d;
		}
		else if(inc15==11||inc15==12||inc15==13||inc15==14||inc15==15||inc15==16)
		{
			CalcPar2[inc15][0]=' ';
			CalcPar2[inc15][1]=' ';
			CalcPar2[inc15][2]=' ';
			
			if(inc15==11)
			{
				CalcPar2[inc15][3]='C';
				CalcPar2[inc15][4]='I';
				CalcPar2[inc15][5]=' ';
				CalcPar2[inc15][6]='-';
				
			} 
			else if(inc15==12)
			{
				CalcPar2[inc15][3]='C';
				CalcPar2[inc15][4]='M';
				CalcPar2[inc15][5]='1';
				CalcPar2[inc15][6]=' ';
			}
			else if(inc15==13)
			{
				CalcPar2[inc15][3]='C';
				CalcPar2[inc15][4]='M';
				CalcPar2[inc15][5]='2';
				CalcPar2[inc15][6]=' ';
			}
			else if(inc15==14)
			{
				CalcPar2[inc15][3]='C';
				CalcPar2[inc15][4]='M';
				CalcPar2[inc15][5]='3';
				CalcPar2[inc15][6]=' ';
			}
			else if(inc15==15)
			{
				CalcPar2[inc15][3]='Z';
				CalcPar2[inc15][4]='I';
				CalcPar2[inc15][5]=' ';
				CalcPar2[inc15][6]=' ';
				
			}
			else if(inc15==16)
			{
				CalcPar2[inc15][3]='Z';
				CalcPar2[inc15][4]='R';
				CalcPar2[inc15][5]=' ';
				CalcPar2[inc15][6]=' ';
			}
			
			
			CalcPar2[inc15][7]=CalcPar[inc15][3];
			CalcPar2[inc15][8]=CalcPar[inc15][4];
			CalcPar2[inc15][9]=CalcPar[inc15][5];
			CalcPar2[inc15][10]=CalcPar[inc15][6];
			CalcPar2[inc15][11]=CalcPar[inc15][7];
			CalcPar2[inc15][12]=0x0d;
		
	}
	 else if(inc15==8||inc15==17)
		{
			CalcPar2[inc15][0]=' ';
			CalcPar2[inc15][1]=' ';
			CalcPar2[inc15][2]=' ';
			
			if(inc15==8)
			{
				CalcPar2[inc15][3]='D';
				CalcPar2[inc15][4]='S';
				CalcPar2[inc15][5]=' ';
				
			} 
			else if(inc15==17)
			{
				CalcPar2[inc15][3]='Z';
				CalcPar2[inc15][4]='T';
				CalcPar2[inc15][5]=' ';
			}
			
			
			CalcPar2[inc15][6]=CalcPar[inc15][3];
			CalcPar2[inc15][7]=CalcPar[inc15][4];
			CalcPar2[inc15][8]=CalcPar[inc15][5];
			CalcPar2[inc15][9]=CalcPar[inc15][6];
			CalcPar2[inc15][10]=0x0d;
		
	}
	for(CalPar[inc15][15]=0;CalPar[inc15][15]<inc17+3;CalPar[inc15][15]++)
	{
		u2tbl=CalcPar2[inc15][CalPar[inc15][15]];
		u1tbl=CalcPar2[inc15][CalPar[inc15][15]];
		delay(10000);
	}
	for(CalPar[inc15][16]=0;CalPar[inc15][16]<3;CalPar[inc15][16]++)
	{
		CharRcvd=CharRTable[2][CharOut[2]];
		if(CharOut[2]>=100)
		{
			CharOut[2]=0;
			CalPar[inc15][16]=0;
		}
		else
		{
			CharOut[2]++;
		}
		delay(20000);
		if((CharRcvd==0x0d)||(CharRcvd=='\n')||(CharRcvd=='\r')){ 
			u1tbl='\n';
			continue;}
		else
		{
			CalcPar1[inc15][CalPar[inc15][16]]=CharRcvd;
			u1tbl=CharRcvd;
		}
		for(CalPar[inc15][16]=0;CalPar[inc15][16]<3;CalPar[inc15][16]++)
		{
			delay(20000);
			u1tbl=CalcPar1[inc15][CalPar[inc15][16]];
			delay(2000);
		}
		if((CalcPar1[inc15][0]=='O')||(CalcPar1[inc15][0]=='K')||(CalcPar1[inc15][1]=='K'))
		{
			p2_7=0;
			CharIn[2]=0;
			CharOut[2]=0;
			CalPar[inc15][1]=inc15;                       //used in CrrntADDBMSUpdation(CalPar[inc9][1]); function 
			CrrntADDBMSUpdation(CalPar[inc15][1]);
		}
		else
		{
			DisplayErr();
			p2_7=1;
			//re
		}
	}
	 //CrrntADDBMSUpdation(CalPar[0][14]);
	 //CalPar[0][15]=2;
	//*/
	}
	else
	{
		DisplayErr();
		p2_7=1;
		//return;
	}
	
}
void CrrntADDBMSUpdation(int Upd)
{
	CharIn[2]=0;
	CharOut[2]=0;
	if(Upd<38)
	{
		for(ADDi[3]=0;ADDi[3]<4;ADDi[3]++)
		{
			u2tbl=ADDataFetch[Upd][ADDi[3]];
			u1tbl=ADDataFetch[Upd][ADDi[3]];
			delay(10000);
		}
		for(ADDi[4]=0;ADDi[4]<8;ADDi[4]++)
		{
			if(CharOut[2]>=100)
			{
				CharOut[2]=0;
			}
			delay(2000);
			CharRcvd=CharRTable[2][CharOut[2]++];
			ADDateGNfetRx[Upd][ADDi[4]]=CharRcvd;
			u1tbl=ADDateGNfetRx[Upd][ADDi[4]];
			if((CharRcvd=='\r')||(CharRcvd=='\n')||(CharRcvd==0x0a)||(CharRcvd==0x0d))
			{
				ADDi[4]=12;
			}
			
		}
		
			ADDateGNfetRx[Upd][ADDi[4]]='\0';
	}	
}
void SaveFunction()
{
		error[0]=0;
	CharIn[2]=0;
	CharOut[2]=0;
	CalcPar[0][0]=' ';
	CalcPar[0][1]='C';
	CalcPar[0][2]='E';
	CalcPar[0][3]=' ';
	CalcPar[0][4]=ADDateGNfetRx[1][2];
	CalcPar[0][5]=ADDateGNfetRx[1][3];
	CalcPar[0][6]=ADDateGNfetRx[1][4];
	CalcPar[0][7]=ADDateGNfetRx[1][5];
	CalcPar[0][8]=ADDateGNfetRx[1][6];
	CalcPar[0][9]=0x0d;
	for(CalPar[0][15]=0;CalPar[0][15]<10;CalPar[0][15]++)
	{
		u1tbl=CalcPar[0][CalPar[0][15]];
		u2tbl=CalcPar[0][CalPar[0][15]];
		delay(10000);
	}
	
	for(CalPar[0][16]=0;CalPar[0][16]<3;CalPar[0][16]++)
	{
		CharRcvd=CharRTable[2][CharOut[2]];
		if(CharOut[2]>100)
		{
			CharOut[2]=0;CalPar[0][16]=0;
		}
		else
		{
			CharOut[2]++;
		}
		delay(20000);
		if((CharRcvd==0x0d)||(CharRcvd=='\n')||(CharRcvd=='\r'))
		{ 
			u1tbl='\n';
			continue;
		}
		else
		{	
			CalcPar1[2][CalPar[0][16]]=CharRcvd;
		}
		u1tbl=CharRcvd;
		
	}
	for(CalPar[0][16]=0;CalPar[0][16]<3;CalPar[0][16]++)
	{
		delay(20000);
		u1tbl=CalcPar1[2][CalPar[0][16]];
		delay(2000);
		
	}
	if((CalcPar1[2][0]=='O')||(CalcPar1[2][0]=='K')||(CalcPar1[2][1]=='K'))
	{
				error[0]=0;
				CharIn[2]=0;
				CharOut[2]=0;
				CalcPar[38][0]=' ';
				CalcPar[38][1]=' ';
				CalcPar[38][2]='C';
				CalcPar[38][3]='S';
				CalcPar[38][4]=0x0d;
				for(CalPar[38][15]=0;CalPar[38][15]<5;CalPar[38][15]++)
				{
					u1tbl=CalcPar[38][CalPar[38][15]];
					u2tbl=CalcPar[38][CalPar[38][15]];
					delay(10000);
				}
	
				for(CalPar[38][16]=0;CalPar[38][16]<3;CalPar[38][16]++)
				{
					CharRcvd=CharRTable[2][CharOut[2]];
					if(CharOut[2]>100){CharOut[2]=0;CalPar[38][16]=0;
					}else{CharOut[2]++;}
					delay(20000);
		
		
		
					if((CharRcvd==0x0d)||(CharRcvd=='\n')||(CharRcvd=='\r')){ 
					u1tbl='\n';
					continue;}
					else
					{	CalcPar1[38][CalPar[38][16]]=CharRcvd;}
					u1tbl=CharRcvd;
		
				}
				for(CalPar[38][16]=0;CalPar[38][16]<3;CalPar[38][16]++)
				{
					delay(20000);
					u1tbl=CalcPar1[38][CalPar[38][16]];
					delay(2000);
		
				}
				if((CalcPar1[38][0]=='O')||(CalcPar1[38][0]=='K')||(CalcPar1[38][1]=='K'))
				{
					p2_6=0;
				}
				else
				{
					p2_6=1;
					SaveFunction();
				}
	}
	else
	{
		p2_6=1;
		SaveFunction();
	}
}
	
 
void OnBoardDisplay(signed int DataToUpdate1)
{	
	//return	 ;	
	int ovr=0;
	DataToSegment=DataToUpdate1;
	ChKX=(((DataToSegment%10)==0)&&((DataToSegment/10)==0));
	if(overload)
	{
		//for(ovr=0;ovr<100;ovr++)
		{
			OnDisplayOVD();
		}
		//overload=0;underload=0;
	}
	else if(underload)
	{
		//for(ovr=0;ovr<100;ovr++)
		{
			OnDisplayUVD();
		}
		
	}
	
	//else if((DataToUpdate1>=0)||)
	else if((overload==0)&&(underload==0))
	{ 
		{	
				  								
			if(DataToSegment<0)
			{
				//SegNumber=DataToSegment%10;
				//if((ChKX)&&(Segment>=1))
			
				//else								  	   //  in - , numbers to be executed to perticular Segment
				{	
					DataToSegment*=-1;                     // negative number has problem for representing segment
														   // by modulus and number seperation for negative number numbers get reverse executtion 
														   // eg. instead 0123456789 execution executes 9876543210 i..e instead 0, number 9 gets execution
														   // intead of 8 2 is getting executed, its leads to wrong format 
														   // for this prevention "DataToSegment*=-1;" is done 
					
					for(ze=0;ze<8;ze++)
					{
						dataArray[ze]=DataToSegment%10;
						DataToSegment/=10;
					}
					MinusPot=7;
					for(ze=6;ze>=0;ze--)
					{
						if(dataArray[ze]==0)
						{
							MinusPot--;
						}
						else
						{
							ze=0;
							break;
						}
					}
					MinusPot=MinusPot-1;
					KEYDecoder=DisplaySelect[MinusPot];
					ModuleAddress=DisplayNumber[10];
					delay(60);
					for(ze=MinusPot;ze>0;ze--)
					{
						dataElement=dataArray[ze];
						KEYDecoder=DisplaySelect[ze-1];
						ModuleAddress=DisplayNumber[dataElement];
						delay(100);	
					}
				}
			}
			else									   		//  + number to be Executed to corresponding Segments
			{
				for(zn=0;zn<8;zn++)
					{
						dataArray[zn]=DataToSegment%10;
						DataToSegment/=10;
					}
					PVeZeroes=7;
					for(zn=7;zn>=0;zn--)
					{
						if(dataArray[zn]==0)
						{
							PVeZeroes--;
						}
						else
						{
							zn=0;
							break;
						}
					}
					//PVeZeroes=PVeZeroes-1;
					if(PVeZeroes<1)
					{
						KEYDecoder=DisplaySelect[0];
							ModuleAddress=DisplayNumber[0];	
							delay(100);
					}
					else
					{
						for(zn=PVeZeroes;zn>=0;zn--)
						{
							dataElement=dataArray[zn];
							KEYDecoder=DisplaySelect[zn];
							ModuleAddress=DisplayNumber[dataElement];
							delay(100);	
						}
					}
					
					//ModuleAddress=DisplayNumber[0xff];
					
			}
		//	DataToSegment/=10;
		//	Segment++;
	
		
			if((Segment>=7)||(DataToSegment==0))
			{
				Segment=0;
				ModuleAddress=0xff;
			}
			
		}
		
		if((ChKX)||(DataToSegment==0))
		{
			KEYDecoder=DisplaySelect[7];
			//ModuleAddress=DisplayNumber[0];
			ModuleAddress=0xff;
		}
			
	}
	//else
	{
	//		OnDisplaynodata();
	}
		//overload=0;underload=0;
}
void OnDisplaynodata(void)
{
	for(DJ=0;DJ<8;DJ++)
		{
		  	KEYDecoder=DisplaySelect[DJ];
			ModuleAddress=nodAtA[DJ];
			//ModuleAddress=DisplayNumber[DJ];
			delay(1000);
			
		}
}
void DisplayRT2EM(void)
{
	for(DJ=0;DJ<8;DJ++)
		{
		  	KEYDecoder=DisplaySelect[DJ];
			ModuleAddress=RT2EM[DJ];
			//ModuleAddress=DisplayNumber[DJ];
			delay(1000);
			
		}
	
}
void DisplayPC2EM(void)
{
	for(DJ=0;DJ<8;DJ++)
		{
		  	KEYDecoder=DisplaySelect[DJ];
			ModuleAddress=PC2EM[DJ];
			//ModuleAddress=DisplayNumber[DJ];
			delay(100);
			
		}
	
}
void OnDisplayOVD(void)
{
	for(DJ=0;DJ<8;DJ++)
		{
		  	KEYDecoder=DisplaySelect[DJ];
			ModuleAddress=Overloada[DJ];
			//ModuleAddress=DisplayNumber[DJ];
			delay(100);
			
		}
	//overload=0;
}
void OnDisplayUVD(void)
{
	for(DJ=0;DJ<8;DJ++)
		{
		  	KEYDecoder=DisplaySelect[DJ];
			ModuleAddress=Underloada[DJ];
			//ModuleAddress=DisplayNumber[DJ];
			delay(100);
			
		}
		//underload=0;
}
void UpdateDisplay(void)
{
	for(DJ=0;DJ<8;DJ++)
		{
		  	KEYDecoder=DisplaySelect[DJ];
			ModuleAddress=NUpdate[DJ];
			//ModuleAddress=DisplayNumber[DJ];
			delay(100);
			
		}
}
void DisplayTackCntr(void)
{	TactZeroCount=4;
	
	/*for(CEZ=2;CEZ<=6;CEZ++)
	{
		TactCounter[6-CEZ]=CEstring[CEZ];
	}
	
	for(CEZ=2;CEZ<=6;CEZ++)
	{	if(CEstring[CEZ]=='0'){
		TactZeroCount--;}
		else{CEZ=2;break;}
	}*/
	for(CEZ=2;CEZ<=6;CEZ++)
	{
		TactCounter[6-CEZ]=ADDateGNfetRx[1][CEZ];
	}
	
	for(CEZ=2;CEZ<=6;CEZ++)
	{	if(ADDateGNfetRx[1][CEZ]=='0'){
		TactZeroCount--;}
		else{CEZ=2;break;}
	}
	if(TactZeroCount<1)
	{
		KEYDecoder=DisplaySelect[0];
		ModuleAddress=DisplayNumber[0];
		delay(50);
		return ;
	}
	else
	{
		for(CEZ=TactZeroCount;CEZ>=0;CEZ--)
		{
			for(TacT=0;TacT<10;TacT++)
			{
				if(TactCounter[CEZ]==CharToNumber[TacT])
				{
					KEYDecoder=DisplaySelect[CEZ];
					ModuleAddress=DisplayNumber[TacT];
					delay(10);	
				}
			}
		}
	}
	 return;
}
void CalibrationZero(void)
{
	StaCount=0;
			
			while(KEY1==0);
			delay(20000);
			//Stable_Check();
			TemporaryWeight=DataToUpdate;
			if(TemporaryWeight>=450)
			{
				delay(20000);
				p2_3=1;
				for(izx=0;izx<1000;izx++)
				{
					DisplayErr();
				}
				
				for(izx=0;izx<1000;izx++)
				{
					OnBoardDisplay(DataToUpdate);
				}
			//	CharIn[2]=0;
			//	CharOut[2]=0;
				p2_3=0;
				delay(20000);
				return;	
			}	
			else if(TemporaryWeight<450)
			{
				SetContinous=0;
				p2_2=1;
				delay(20000);
				INT1=1;
			    CalibrationCZ();
				for(izx=0;izx<200;izx++);
				///*
				//CharIn[2]=0;
				//CharOut[2]=0;
				//*/
				/*
				DataToUpdate=0xffffffff;
				CurrentWeight=0xffffffff;
				 WeightToUpdate=0xffffffff;
				 //include  *///
				 
				 //SetContinous=1;
				 //SendNetValCont();
				 //EnquireWt();
				 delay(20000);
				p2_2=0;
				return ;
			}
}

void CalibrationCE(void)
{
	//Counter1=0;
	PackToSend[2][Counter1++] = 'C';
	PackToSend[2][Counter1++] = 'E';
	PackToSend[2][Counter1++] = 0x0d;
	//StartXmit1(Counter1++);
	//	StartXmit22(Counter1);
	return;
}
void CalibrationCEN(void)
{
	//Counter1=0;
	PackToSend[2][Counter1++] = 'C';
	PackToSend[2][Counter1++] = 'E';
	PackToSend[2][Counter1++] = ' ';
	PackToSend[2][Counter1++] = CEstring[2];
	PackToSend[2][Counter1++] = CEstring[3];
	PackToSend[2][Counter1++] = CEstring[4];
	PackToSend[2][Counter1++] = CEstring[5];
	PackToSend[2][Counter1++] = CEstring[6];
	PackToSend[2][Counter1++] = 0x0d;
	//StartXmit1(Counter1++);
	//	StartXmit22(Counter1);
	return;
}
/*
void CalibrationCZ(void)
{
	Counter1=0;
	
	PackToSend[2][Counter1++] = 'C';
	PackToSend[2][Counter1++] = 'Z';
	PackToSend[2][Counter1++] = '\n';
	StartXmit22(Counter1++);
	return;
}
*/
void CalibrationCZ(void)
{
	/*
	//Counter1=12;
	Counter1=0;
	PackToSend[2][Counter1++] = 's';
	PackToSend[2][Counter1++] = 'z';
	PackToSend[2][Counter1++] = 0x0d;
	//StartXmit22(Counter1++);*/
	u2tb= 's';
	delay(1000);
	u2tb= 'z';
	delay(1000);
	u2tb= 0x0d;
	delay(1000);
	//StartXmit2(Counter1);
	Counter1=0;
	return;
}
void SendNetValCont(void)
{
	//Counter1=30;
	Counter1=20;
	PackToSend[2][Counter1++] = 's';
	PackToSend[2][Counter1++] = 'n';
	PackToSend[2][Counter1++] = 0x0d;
	StartXmit22(Counter1);	
	return;
}
void deviceStatus(void)
{
	//if(INT1==1)
	{
	//CounterIS1=20;
	CounterIS1=30;
	//INT1=0;
	}
	//else
	//{CounterIS1=0;}
	PackToSend[2][CounterIS1++] = 'I';
	PackToSend[2][CounterIS1++] = 'S';
	PackToSend[2][CounterIS1++] = 0x0d;
	//StartXmit2(CounterIS1);
	StartXmit22(CounterIS1);
	//CounterIS1=20;
	return;
}
void SoftwareReset(void)
{
	CharIn[2]=0;
	CharOut[2]=0;
	CalcPar[39][0]=' ';
	CalcPar[39][1]='S';
	CalcPar[39][2]='R';
	CalcPar[39][3]=0x0d;
	for(CalPar[39][24]=0;CalPar[39][24]<4;CalPar[39][24]++)
	{
		u2tbl=CalcPar[39][CalPar[39][24]];
		delay(10000);
	}
	for(CalPar[39][23]=0;CalPar[39][23]<4;CalPar[39][23]++)
	{
		
		CharRcvd=CharRTable[2][CharOut[2]];
		if(CharOut[2]>=100)
		{
			CharOut[2]=0;
			CalPar[39][23]=4;
		}
		else
		{
			CharOut[2]++;
		}
		if((CharRcvd==0x0d)||(CharRcvd=='\r')||(CharRcvd=='\n'))
		{
			u1tbl='\n';
			continue;
		}
		else
		{
			CalcPar[39][CalPar[39][23]]=CharRcvd;
			u1tbl=CharRcvd;
		}
		delay(10000);
	
	}
	
	for(CalPar[39][23]=0;CalPar[39][23]<4;CalPar[39][23]++)
	{
		
	}
	if(CalcPar[39][0]=='O'||CalcPar[39][0]=='K'||CalcPar[39][2]=='k')
	{
		p2_7=0;
		CharIn[2]=0;
		CharOut[2]=0;
		
	}
	else
	{
		delay(10000);
		SoftwareReset();
	}	
	return ;
	
}
void DisplayErr(void)
{
		for(DJ=0;DJ<8;DJ++)
		{
		  	KEYDecoder=DisplaySelect[DJ];
			ModuleAddress=Error[DJ];
			//ModuleAddress=DisplayNumber[DJ];
			delay(100);
			
		}
}
/*
void ReadRTC()
{
}
void WriteRTC()
{
}

void ReadDateNTime(void)
{
}
void delay_ms1(unsigned int ms_count)
{
}
void IsrTimer1(void)
{
}

*/
/*********************************************|*/
unsigned int GetInt(unsigned char LSB, unsigned char MSB)
{
	//return ((MSB <<8) | LSB) ;
	TempInt1  = MSB * 256;
	TempInt1 += LSB;
	return (TempInt1) ;
}

unsigned long int GetLInt(unsigned char LSB, unsigned char MIB, unsigned char MSB)
{
	TempBuf= MSB * 65536;	
	// MIB x 256 needed to be stored in integer varialble and then added to the long
	TempInt1=MIB * 256;
	TempBuf = TempBuf+TempInt1+LSB;
	return (TempBuf) ;
	//return ( (MSB <<16) | (MIB <<8) | LSB) ;
}

unsigned char GetLSB(unsigned int Integer)
{
	return (Integer & 0xff);
}

unsigned char GetMSB(unsigned int Integer)
{
	TempInt1 = Integer / 256;
	return (TempInt1 & 0x0ff);
	//return ((Integer >> 8 ) & 0x0ff);
}

unsigned char LGetLSB(unsigned long int Number)
{
	return (Number & 0xff);
}

unsigned char LGetMID(unsigned long int Number)
{
	TempInt1 = Number / 256;
	return (TempInt1 & 0x0ff);
//	return ((Number >> 8) & 0xff);
}

unsigned char LGetMSB(unsigned long int Number)
{
	TempInt1 = Number / 65536;
	return (TempInt1 & 0x0ff);
//	return ((Number >> 16 ) & 0xff);
}

void delay(unsigned long duration)
{
	long i;
	for(i=0;i<duration;i++);	
}

void mcuinit(void)
{
	
    prcr  = 0x01;                /* CM0,CM1,CM2,PLC0,PCLKR,fra0 register protect off 	*/
    cm21  = 0;                   /* System clock select: Main clock 					*/
    cm1   = 0xA0;                /* System clock Divide by 4 							*/
    cm06  = 0;                   /* CM16 and CM17 enabled 								*/
    cm1   = 0x60;                /* System clock Divide by 2 							*/
    cm1   = 0x20;                /* System clock Divide by 1 							*/
    prcr  = 0x00;                /* Protect on 											*/	

	//LED_PORT_DIR=0xFF;
	//LED2=LED3=LED4=LED5=LED6=1;
}
void mcuinit1(void)
{
	unsigned long i,k;
	LED2_DIR=1;LED3_DIR=1;LED4_DIR=1;LED5_DIR=1;LED6_DIR=1;
	LED2=LED3=LED4=LED5=LED6=0;
	
	LED7_DIR=1;LED8_DIR=1;LED9_DIR=1;LED10_DIR=1;LED11_DIR=1;
	LED7=LED8=LED9=LED10=LED11=0;
	
//|******************************************changed**********************//
	DataAddrDir=0x00;
//	SevDir=1;
	//SevAdd=1;
	ModuleAddDir=0xff;
						//Port7AddDir=0xff;
	KEY1DecodeDIR=0x38;
	for(j=0;j<19;j++)
	{
				//	SevenSigAddres=0x01;
				//KEY1DecodeDIR=0x38;
		
		for(i=0;i<1550;i++)
		{
			ModuleAddress=DisplayCheck[j];
			//Port7Address=DisplayCheck[j];
			for(k=0;k<8;k++)
			{
				KEYDecoder=DisplaySelect[k];
			}
		}
	}
	KEY1DIR=1;
	KEY2DIR=1;
	pd2_7=1;
	pd10_6=1;
    
	
	
	/*	for(DJ=0;DJ<8;DJ++)
		{
		  	KEYDecoder=DisplaySelect[DJ];
			ModuleAddress=0xff;
			for(ji=0;ji<200;ji++);
		}*/
	//	KEY1DIR =0;
	
	// Checking for 74LS138
	
	KEY1DIR=0;
	KEY2DIR=0;
	KEY3DIR=0;
	KEY4DIR=0;
	MAX485_EN_DIR=1;
	PC_LDU_CAL_DIR=1;
	DIRECT_LDU_CAL_DIR=1;
	OUTDataAddrDir=0xff;
		
		
	
	DIRECT_LDU_CAL=(Portr&0)>>0;
	PC_LDU_CAL=(Portr&2)>>1;
	MAX485_EN=(Portr&4)>>2;
	
	
	//MAX485_EN=1;
	//PC_LDU_CAL=1;
	//DIRECT_LDU_CAL=1;
	OUTDataAddress=0x00;
	
	for(i=0;i<1550000;i++);
	MAX485_EN=0;
	PC_LDU_CAL=0;
	DIRECT_LDU_CAL=0;
	OUTDataAddress=0xff;
	//Portr210=0x02;
	
	for(i=0;i<1550000;i++);
		MAX485_EN=1;
	PC_LDU_CAL=1;
	DIRECT_LDU_CAL=1;
	OUTDataAddress=0x1f;
	
	for(i=0;i<1550000;i++);
		MAX485_EN=0;
	PC_LDU_CAL=0;
		OUTDataAddress=0x00;
	//DIRECT_LDU_CAL=1;

	/*
	for(i=0;i<1550000;i++);
	//	MAX485_EN=1;
	PC_LDU_CAL=0;
	DIRECT_LDU_CAL=1;
	OUTDataAddress=0x00;
	*/
		
	//******************************************changed**********************|//
	
	pd1_6=1;					// set as output
	pd1_7=1;					// set as output
   //	ModuleAddDir=0xff;		// set as output
	
	Latch=0;
	
	IODirection=0;
	//	SevAdd=0;
}

void Init_Timer1(void) 
{
	
	tckdivc0 = 0x00;			/* Setting timer AB division control register 0 											*/
								/* TCDIV00: Clock select prior to timer AB division bit (0:f1) 								*/
	tacs0 = 0x90;				/* Selecting the count source of Timer A1 													*/
								/* TCS6~TCS4: Timer A1 count source select bit (000:f1TIMAB or f2TIMAB) 					*/
								/* TCS7: Count source option sepecified bit (0: TCK1,TCK0 enabled, TCS4 to TCS6 disabled)	*/
	ta1mr = 0x40;				/* Selecting timer mode and functions														*/
								/* TMOD1,TMOD0: Selection of timer mode														*/
								/* MR0: Pulse output function select bit (0:Pulse is not output)							*/
								/* MR2,MR1: Gate function select bit (00:Gate function not available)						*/
								/* MR3: Must always be "0" in timer mode													*/
								/* TCK1,TCK0: Count source (01:f8TIMAB)														*/
	tapofs = 0x00;				/* Select Timer A waveform output function													*/
								/* POFS1: TA1OUT output polar control bit (0:Output waveform "H" active)					*/
	ta1 = 2500-1;				/* Setting counter value (1msec @20MHz, f8)													*/
	cpsrf = 0x00;				/* Setting clock prescaler reset flag														*/
								/* CPSR: Clock prescaler reset flag (0:No effect)											*/
	tabsr = 0x02;				/* Setting count start flag		*/		
	ta1ic = 0x07;													
	ir_ta1ic=0;	
	return;
}

void IsrTimer(void)
{
	if(++MSCounter>999) {
		MSCounter=0;
		OneSecond=1; //SendQueryAD=1;
		DisplayAxCount ^= 1;
	}
	if (RemoteSTimer++ >= 50) {
		RemoteSTimer=0;	SendToRemote=1;
//		SendToRemote1=1;
	}	
	
	if (ADCounter++ > ADWaitTimer) {
		ADCounter=0;
		SendQueryAD=1;
	}
//	if (++WaitCounter > 60000) {		// seoonds x 1000 - one msec interrupt
//		WaitCounter=60000;				// initalise counter
//	}
	if (StartSpdTmr) {
		TCOUNT++;
		if (TCOUNT > 65000) {TCOUNT = 65000;}
	}
	if (ZeroTimer>0) {ZeroTimer--;}	
	SpeedF1Timer++;SpeedF2Timer++;
	SpeedTimer++;
	ir_ta1ic=0;	
}

void PowerOnInit(void)
{
	Toggle=0;
	StxReceived = 0;CStep=0;PackCounter=0;
	PackLength = 0;	DLEReceived =0;
	SendOutputs=1;
	CheckSumError = 0;
	OutputSelected = 0;
	TimerCounter =0;OneSecond=0;
	ReplyAvailable=0;OutputTimer=0;tire = 0;
	if (PowerOnStatus != 0x55) {
		PowerOnStatus = 0x55;
		InPointer=0;OutPointer=0;TempPointer=0;
	}
	ChannelNumber = 0;
	for(Counter=0;Counter<4;Counter++) {
		CharIn[Counter] = 0; CharOut[Counter]=0;
		BytesToSend[Counter]=0;BytesSent[Counter]=0;
	}
	ResetFrameNumber = 0;
	//FrameNumber =0;	
	CurrentWeight=0xffffffff;
	FirstTime=1;AnyChange=0;
	RTUID = RTU_ID;			
	DIMS  = DIMS_DEF;			/* necessary before calling IOInit */
	DOMS  = DOMS_DEF;
	IOInit();
	SetIODefault();
	MSCounter=0;
	RemoteSTimer=0;SendToRemote=0;//SendToRemote1=0;
	Direction=0;
	ZeroWeight=0;AcquireZero=0;ZeroSent=0;
	ZeroWeight0=0;
	WBNO=0;
	PCFailCount=0;ADCounter=0;
	StartSpdTmr=0;	
	//ProcessTrack=1;		// confirm and remove the statement. set for pc for trackwitch processing
	ZeroTimer=ZERODELAY;		
	//AcquireZero=1;		// read scale weight and take as new zero if withing limits
	Resolution=5;			// default resolution is 50 kgs - last digit zero is ignore
	OSLimit=150;	
	//InitWeighing();
	ADWaitTimer=50;
	SpeedF1Timer=0;SpeedF2Timer=0;
	A1Speed=0;A2Speed=0;
	
	for(Counter=0;Counter < 10; Counter++) {
		InSpeed[Counter]=0;InFactor[Counter]=0;
		OutSpeed[Counter]=0;OutFactor[Counter]=0;
		
		InWtSpeed[Counter]=0;OutWtSpeed[Counter]=0;
		
		for(Counter1=0;Counter1 < 5; Counter1++) {
			InWtFactor[Counter1][Counter]=0;
			OutWtFactor[Counter1][Counter]=0;
		}
	}	
	
	ResetSteps();
	AxlesWeighed=0;WaitForCR=0;
	OneByOneSet=0;SpeedTimer=0;DPos=0;
	SetContinous=1;
}

void Com0Init()								/* COM PORT 0*/
{
    u0c1  = 0x00;                       /* disable Transmission, receive. also clear all*/
                                        /* Reception disabled */
    u0mr = 0x05;                        /* UART mode character bit length is 8 bits */
                                        /* Internal/external clock: Internal clock */
                                        /* Stop bit length: 1 stop bit */
                                        /* Parity disabled */
                                        /* TXD, RXD I/O polarity inverse: Not inverted */

    u0c0 = 0x10;                        /* U1BRG count source: f1SIO */
                                        /* CTS/RTS function disabled */
                                        /* Data output: Pins TXDi/SDAi and SCLi are CMOS output */
                                        /* Bit order: LSB first */

    u0c1 = 0x00;                        /* Data logic: No reverse */
                                        /* Error signal output: Output disabled */

    ucon = 0x00;                        /* Transmission buffer empty */
                                   		/* causes UART1 transmit interrupt */

    u0brg = Baud19200;              	 
	u0smr  = 0x00;                      /* 00h is set the UART1 special mode register */
    u0smr2 = 0x00;                      /* 00h is set the UART1 special mode register 2 */
    u0smr3 = 0x00;                      /* 00h is set the UART1 special mode register 3 */
    u0smr4 = 0x00;                      /* 00h is set the UART1 special mode register 4 */

    s0tic = 0x01;               /* UART1 transmit Interrupt: Level 1 */
    s0ric = 0x02;             	/* UART1 receive Interrupt : Level 2 */
	
    u0c1  = 0x05;                       /* Transmission enabled */
                                        /* Reception enabled */
}	

void Com1Init()								/* COM PORT 1*/
{
    u1c1  = 0x00;                       /* disable Transmission, receive. also clear all*/
                                        /* Reception disabled */
    u1mr = 0x05;                        /* UART mode character bit length is 8 bits */
                                        /* Internal/external clock: Internal clock */
                                        /* Stop bit length: 1 stop bit */
                                        /* Parity disabled */
                                        /* TXD, RXD I/O polarity inverse: Not inverted */

    u1c0 = 0x10;                        /* U1BRG count source: f1SIO */
                                        /* CTS/RTS function disabled */
                                        /* Data output: Pins TXDi/SDAi and SCLi are CMOS output */
                                        /* Bit order: LSB first */

    u1c1 = 0x00;                        /* Data logic: No reverse */
                                        /* Error signal output: Output disabled */

    ucon = 0x00;                        /* Transmission buffer empty */
                                   		/* causes UART1 transmit interrupt */

    u1brg = Baud19200;              	 
	u1smr  = 0x00;                      /* 00h is set the UART1 special mode register */
    u1smr2 = 0x00;                      /* 00h is set the UART1 special mode register 2 */
    u1smr3 = 0x00;                      /* 00h is set the UART1 special mode register 3 */
    u1smr4 = 0x00;                      /* 00h is set the UART1 special mode register 4 */

    s1tic = 0x01;               /* UART1 transmit Interrupt: Level 1 */
    s1ric = 0x02;             	/* UART1 receive Interrupt : Level 2 */
	
    u1c1  = 0x05;                       /* Transmission enabled */
                                        /* Reception enabled */
}	

void Com2Init()							/* COM PORT 2*/
{
    u2c1  = 0x00;                       /* disable Transmission, receive. also clear all*/
                                        /* Reception disabled */
    u2mr = 0x05;                        /* UART mode character bit length is 8 bits */
                                        /* Internal/external clock: Internal clock */
                                        /* Stop bit length: 1 stop bit */
                                        /* Parity disabled */
                                        /* TXD, RXD I/O polarity inverse: Not inverted */

    u2c0 = 0x10;                        /* UiBRG count source: f1SIO */
                                        /* CTS/RTS function disabled */
                                        /* Data output: Pins TXDi/SDAi and SCLi are CMOS output */
                                        /* Bit order: LSB first */

    u2c1 = 0x00;                        /* Data logic: No reverse */
                                        /* Error signal output: Output disabled */
    u2brg = Baud115200;              	 
	u2smr  = 0x00;                      /* 00h is set the UART6 special mode register */
    u2smr2 = 0x00;                      /* 00h is set the UART6 special mode register 2 */
    u2smr3 = 0x00;                      /* 00h is set the UART6 special mode register 3 */
    u2smr4 = 0x00;                      /* 00h is set the UART6 special mode register 4 */

    s2tic = 0x01;               		/* UART2 transmit Interrupt: Level 1 */
    s2ric = 0x02;             			/* UART2 receive Interrupt : Level 2 */
	
    u2c1  = 0x05;                       /* Transmission & Reception enabled */
}	

void Com6Init()							/* COM PORT 6*/
{
    u6c1  = 0x00;                       /* disable Transmission, receive. also clear all*/
                                        /* Reception disabled */
    u6mr = 0x05;                        /* UART mode character bit length is 8 bits */
                                        /* Internal/external clock: Internal clock */
                                        /* Stop bit length: 1 stop bit */
                                        /* Parity disabled */
                                        /* TXD, RXD I/O polarity inverse: Not inverted */

    u6c0 = 0x10;                        /* UiBRG count source: f1SIO */
                                        /* CTS/RTS function disabled */
                                        /* Data output: Pins TXDi/SDAi and SCLi are CMOS output */
                                        /* Bit order: LSB first */

    u6c1 = 0x00;                        /* Data logic: No reverse */
                                        /* Error signal output: Output disabled */
    u6brg = Baud38400;              	 
	u6smr  = 0x00;                      /* 00h is set the UART6 special mode register */
    u6smr2 = 0x00;                      /* 00h is set the UART6 special mode register 2 */
    u6smr3 = 0x00;                      /* 00h is set the UART6 special mode register 3 */
    u6smr4 = 0x00;                      /* 00h is set the UART6 special mode register 4 */

    s6tic = 0x01;               		/* UART6 transmit Interrupt: Level 1 */
    s6ric = 0x02;             			/* UART6 receive Interrupt : Level 2 */
	
    u6c1  = 0x05;                       /* Transmission & Reception enabled */
}	

void Com0Rx(void)
{
	LED5 ^= 1;
    rcv_data = u0rbl;                    /* Read reception data from U1RB register */
    //if((rcv_data & 0x1000) != 0x0000){
    //    /* When an error occurred, please perform error processing */
    //}
    //else{
		CharRTable[0][CharIn[0]++] = rcv_data;
		//CharIn[0]++;
		if (CharIn[0] >= 100) CharIn[0]=0;
		//SecondPort=0;
	//}	
}

void Com1Rx(void)
{
	//LED10 ^= 1;
    rcv_data = u1rbl;                    /* Read reception data from U1RB register */
    //if((rcv_data & 0x1000) != 0x0000){
    //    /* When an error occurred, please perform error processing */
    //}
    //else{
		CharRTable[1][CharIn[1]++] = rcv_data;
		//CharIn[1]++;
		if (CharIn[1] >= 100) CharIn[1]=0;
		//SecondPort=1;
		
		Int=1;
	//}	
}
/*
void Com2Rx(void)
{
    //rcv_data = u2rbl;                    /* Read reception data from U2RB register */
    //if((rcv_data & 0x1000) != 0x0000){
    //    /* When an error occurred, please perform error processing *///
    //}
    //else{
	//	CharRTable[2][CharIn[2]++]=u2rbl;
		//CharIn[2]++;
	//	if (CharIn[2] >= 100) CharIn[2]=0;
	//}	
//}*/

void Com2Rx(void)
{
    //rcv_data = u2rbl;                    /* Read reception data from U2RB register */
    //if((rcv_data & 0x1000) != 0x0000){
    //    /* When an error occurred, please perform error processing */
    //}
    //else{
		CharRTable[2][CharIn[2]++]=u2rbl;
		//CharIn[2]++;
		if (CharIn[2] >= 100) CharIn[2]=0;
		//if (CharRTable[2][CharIn[2]++]=='\r')CharIn[2]=0;
	//}	
}

void Com6Rx(void)
{
    //rcv_data = u6rbl;                    /* Read reception data from U6RB register */
    //if((rcv_data & 0x1000) != 0x0000){
    //    /* When an error occurred, please perform error processing */
    //}
    //else{
		CharRTable[3][CharIn[3]++]=u6rbl;
		//CharIn[3]++;
		if (CharIn[3] >= 100) CharIn[3]=0;
	//}	
}


void Com0Tx(void)
{
}

void Com1Tx(void)
{
}

void Com2Tx(void)
{
}

void Com6Tx(void)
{
}

void SendByte0(void)
{
	if (!ti_u0c1)			// transmitt buffer empty
		return; 
	if (BytesToSend[0]==0) {
		LED6=1;						
		return;
	}
	if (BytesSent[0] >= BytesToSend[0]) {
		BytesToSend[0]=0;
		LED6=1;						
		return;
	}
	LED6 ^= 1 ;						
	u0tbl = PackToSend[0][BytesSent[0]];
	BytesSent[0]++;
}

void SendByte1(void)
{
	
	if (!ti_u1c1) {			// transmitt buffer empty
		return; 
	}
	if (BytesToSend[1]==0) {
		//LED11=1;
		return;
	}
	if (BytesSent[1] >= BytesToSend[1]) {
		//LED11=1;
		return;
	}
	u1tbl = PackToSend[1][BytesSent[1]];
	//LED11 ^= 1;					
	BytesSent[1]++;
}

void SendByte2(void)
{
	if (!ti_u2c1)			// transmitt buffer empty
		return; 
	if (BytesToSend[2]==0) {
		//LED8=1;			// avoid clearing as query is one byte only. MORE THAN 1 BYTE POSSIBLE
		return;
	}
	if (BytesSent[2] >= BytesToSend[2]) {
		BytesToSend[2]=0;
		//LED8=1;			// avoid clearing as query is one byte only. MORE THAN 1 BYTE POSSIBLE
		return;			
	}
	//LED8 ^= 1 ;			// avoid toggle as query is one byte only. MORE THAN 1 BYTE POSSIBLE
	u2tbl = PackToSend[2][BytesSent[2]];
	BytesSent[2]++;
}

void SendByte6(void)
{
	if (!ti_u6c1)			// transmitt buffer empty
		return; 
	if (BytesToSend[3]==0) {
		LED4=1;						
		return;
	}
	if (BytesSent[3] >= BytesToSend[3]) {
		BytesToSend[3]=0;
		LED4=1;						
		return;
	}
	LED4 ^= 1 ;						
	u6tbl = PackToSend[3][BytesSent[3]];
	BytesSent[3]++;
}
/***************changed ***************************/
void ProcessByte(void)
{
	if (CharIn[1] == CharOut[1]) {
		return;
	}
	CharRcvd = CharRTable[1][CharOut[1]++];
	if (CharOut[1] >= 100) {
		CharOut[1]=0;
	}
	
//	u1tbl = CharRcvd;
//	return ;
	
	if ( CharRcvd == 0x7e) {
		if (DLEReceived) {
			DLEReceived = 0;
		}
		else {
			StxReceived = 1;CStep=1;CRCValue=0;
			CRCValue=GetCSum(CRCValue,CharRcvd);
			return;
		}
	}
	if (!StxReceived) {
		return;
	}	
	if ( CharRcvd == 0x10) {
		if (DLEReceived) {
			DLEReceived = 0;
		}
		else	{
			DLEReceived = 1;
			return;
		}		
	}
	CRCValue=GetCSum(CRCValue,CharRcvd);
	switch (CStep) {
	case 1:	// address to be received
		if (CharRcvd == 0xff) {
			BroadCast = 1;
			RTUAddress = RTUID;
		}
		else {
			BroadCast = 0;
			RTUAddress = CharRcvd;
		}
		CStep = 2;
		PackLength = 0;
		break;
	case 2:	// LSB of packet length 
		LSBByte = CharRcvd;
		CStep = 3;
		break;
	case 3:	// MSB of packet length
		MSBByte = CharRcvd;
		PackLength = GetInt(LSBByte,MSBByte) ;
		PackCounter=0;
		CStep = 4;
		break;
	case 4:	// command + data
		PackReceived[PackCounter] = CharRcvd;
		PackCounter++;
		if (PackCounter==PackLength) {
			CStep = 5;
		}
		break;
	case 5:	// LSB of checksum
		CStep = 6;
		break;
	case 6:	// MSB of checksum
		PackOk = 1;
		if (CRCValue ==0) {
			CheckSumError = 0;
		}
		else {
			CheckSumError = 1;
		}		
		StxReceived = 0;
	}
}

unsigned int GetCSum(unsigned int CRCPValue, unsigned char CByte)
{
	Index = ((CRCPValue ^ CByte) & 0x0ff) ;
	NewCSum = ((CRCPValue & 0xff00) >> 8 ) ^ CRCTable[Index];
	return (NewCSum);
}
/**************changed ************/
void ProcessBytesPCUnit(signed int DataToUpdate)
{
	if(Int==0)
	{
	DataTOPC=DataToUpdate;
	/*
	PackToSend[1][6]=(char)((DataTOPC%10)|0x30);
	DataTOPC/=10;
	StartXmit1(1);
	PackToSend[1][6]=(char)((DataTOPC%10)|0x30);
	DataTOPC/=10;
	StartXmit1(1);
	PackToSend[1][6]=(char)((DataTOPC%10)|0x30);
	DataTOPC/=10;
	StartXmit1(1);
	PackToSend[1][6]=(char)((DataTOPC%10)|0x30);
	DataTOPC/=10;
	StartXmit1(1);
	PackToSend[1][6]=(char)((DataTOPC%10)|0x30);
	DataTOPC/=10;
	StartXmit1(1);
	PackToSend[1][6]=(char)((DataTOPC%10)|0x30);
	
	StartXmit1(1);
	*/
	if (DataTOPC< 0) { 
	  WtToConv=0-DataTOPC; NetString[0]='-';
	}
	else {
	 WtToConv=DataTOPC; NetString[0]=' ';
	}                       
	NetString[6] = '0';
	NetString[5]= (char)((WtToConv % 10) | 0x030);
	WtToConv = WtToConv/10;
	NetString[4]= (char)((WtToConv % 10) | 0x030);
	WtToConv = WtToConv/10;
	NetString[3]= (char)((WtToConv % 10) | 0x030);
	WtToConv = WtToConv/10;
	NetString[2]= (char)((WtToConv % 10) | 0x030);
	WtToConv = WtToConv/10;
	NetString[1]= (char)((WtToConv % 10) | 0x030);
	if (NetString[1]=='-') {NetString[1]='-';}

	BytesToSend[1]=0;
	PackToSend[1][BytesToSend[1]++]=0x01 ;
    PackToSend[1][BytesToSend[1]++]=NetString[0];//u1tbl = PackToSend[1][1];
		
    PackToSend[1][BytesToSend[1]++]=NetString[1];//u1tbl = PackToSend[1][2];
    PackToSend[1][BytesToSend[1]++]=NetString[2];//u1tbl = PackToSend[1][3];
    PackToSend[1][BytesToSend[1]++]=NetString[3];//u1tbl = PackToSend[1][4];
    PackToSend[1][BytesToSend[1]++]=NetString[4];//u1tbl = PackToSend[1][5];
    PackToSend[1][BytesToSend[1]++]=NetString[5];//u1tbl = PackToSend[1][6];
    //PackToSend[1][BytesToSend[1]++]=NetString[6];//u1tbl = PackToSend[1][7];
	
	PackToSend[1][BytesToSend[1]++]='\t';//u1tbl = PackToSend[1][8];
	DataAddress1=DataAddress;
	DiData[2]=((char)(DataAddress1%10)| 0x030);
	DataAddress1/=10;
	DiData[1]=((char)(DataAddress1%10)| 0x030);
	DataAddress1/=10;
	DiData[0]=((char)(DataAddress1%10)| 0x030);
	PackToSend[1][BytesToSend[1]++]=DiData[0];
	PackToSend[1][BytesToSend[1]++]=DiData[1];
	PackToSend[1][BytesToSend[1]++]=DiData[2];	
	PackToSend[1][BytesToSend[1]++]=0x0d;//u1tbl = PackToSend[1][8];
	//PackToSend[1][BytesToSend[1]++]=0x0a;

	StartXmit1(BytesToSend[1]);		
	return ;
	}
}

void ProcessBytesFromPCUnit(void)
{
	//for(chi=0;chi<100;chi++)
	{
		//charRTable1[1][chi]=CharRTable[1][CharIn[chi]];
	}
	//CharIn[chi]=0;
	
	if (CharIn[1] == CharOut[1]) {
		return;
	}
	
	if (CharOut[1] >= 100) {
		CharOut[1]=0;
	}
	CharRcvd1 = CharRTable[1][CharOut[1]++];
	
	if((CharRcvd1 =='\n')||(CharRcvd1==0x0a)||(CharRcvd1 ==10)||(CharRcvd1 ==0x0d))
	{
		OUTDataAddress=((RcvdNumber1[0]*100)+RcvdNumber1[1]*10+RcvdNumber1[2]*1);
		//OUTDataAddress=255;
		
		//RcvdNumber1=0;
		Int=0;
		//CharIn[1]=0;
		//CharOut[1]=0;
		
		 
		//CharIn[1]=0;
		//return ;
		chi=0;
		
	}
	else
	{
		//RcvdNumber+=(int)(CharRcvd-0x48);
		//RcvdNumber+=(int)CharRcvd;
		if(chi>=3){chi=0;}
		else{
		RcvdNumber=(int)CharRcvd1-48;
		RcvdNumber1[chi]=RcvdNumber;
		RcvdNumber=0;
		chi++;
		}
		//OUTDataAddress=00;
	}
	
	
	
	
//	if(chi>5){chi=0;}
	//else
	/*
	{charRTable1[1][chi]=CharRTable[1][CharIn[1]];
			chi++;}
	
	if(((charRTable1[1][chi])=='\n')||((charRTable1[1][chi])==0x0a)||((charRTable1[1][chi])==10))
	{
		OUTDataAddress=RcvdNumber;
		//OUTDataAddress=255;
		chi=0;
		RcvdNumber=0;
		Int=0;
		//CharIn[1]=0;
		//return ;
		
	}
	else
	{
		RcvdNumber+=(int)((charRTable1[1][chi])-0x48);
		RcvdNumber*=10;
		OUTDataAddress=00;
	}
	//return ;

	
	/*
	if(charRTable1[1][chi]>0)
	{
		for(;(((charRTable1[1][chi])=='\n')||((charRTable1[1][chi])==0x0d));)
		{
			RcvdNumber+=(int)charRTable1[1][chi];
			RcvdNumber*=10;
			chi++;
		}	
	OUTDataAddress=RcvdNumber;
	Int=0;
	return ;
	}
	*/
	

}
	


void ProcessCommands()
{
	if (!PackOk)
		return;	
	PackOk = 0;CharIn[1] = 0; CharOut[1]=0;

	if (RTUAddress != RTUID) 
		return;		

	if (BroadCast) {
		ResetFrameNumber = 1;
	}
	if (CheckSumError) {
		CheckSumError = 0;
		ReplyCRCError();
		return;
	}

	fail_count=0;PCFail = 0;
	PackToSend[1][0] = 0x7e;
	PackToSend[1][1] = RTUAddress;
	Command = PackReceived[0] ;		// & 0x3f;

	PackToSend[1][4]=Command ;
	ReplyAvailable=1;				// have reply available as yes -default
		
	if (Command == 4) {	// send all output status bytes
		PackToSend[1][2]=1+DOMS+DOMS;
		PackToSend[1][3]=0;
		for (Counter=0;Counter<DOMS;Counter++) {
			PackToSend[1][5+Counter]=currout[Counter];
		}
		for (Counter=0;Counter<DOMS;Counter++) {
			PackToSend[1][5+DOMS+Counter]=out[Counter];
		}		
		CalcCheckSum(5+DOMS+DOMS);
		NoOfBytes = 7 + DOMS+DOMS;
		return;
	}		
	if (Command == 10) {	// send all status bytes
		PackToSend[1][2]=1+DIMS+DIMS;
		PackToSend[1][3]=0;
		for (Counter=0;Counter<DIMS;Counter++) {
			PackToSend[1][5+Counter]=in[Counter];
		}
		for (Counter=0;Counter<DIMS;Counter++) {
			PackToSend[1][5+DIMS+Counter]=actin[Counter];
		}		
		CalcCheckSum(5+DIMS+DIMS);
		NoOfBytes = 7 + DIMS+DIMS;
		return;
	}
/*	if (Command == 11) {	// send one status point
		if (GetInt(PackReceived[1],PackReceived[2])>DIMS*8) {
			ReplyIllegalPara();
			return;
		}
		PackToSend[2]=4;
		PackToSend[3]=0;
		PackToSend[5]=PackReceived[1];
		PackToSend[6]=PackReceived[2];
		PackToSend[7]=GetChannelStatus(GetInt(PackReceived[1],PackReceived[2]));
		CalcCheckSum(8);
		NoOfBytes = 10;
		DiagMode=1;
		return;
	}	
	if (Command == 30) {	// Activate control outputs using default operating time
		// 1 offset as command will be stored in the 0th offset
		for(Counter=1;Counter < PackLength;Counter+=2) {
			// mask 2 msb bits of msb as status of output will be stored
			if (GetInt(PackReceived[Counter],(PackReceived[Counter+1]&0x3f))>DOMS*8) {
				ReplyIllegalPara();
				return;
			}
			ChannelNumber = GetInt(PackReceived[Counter],PackReceived[Counter+1]&0x3f);
			SetOChannelStatus(ChannelNumber,PackReceived[Counter+1]&0xc0,DefaultOTime);
		}
		PackToSend[2]=1;
		PackToSend[3]=0;
		CalcCheckSum(5);
		NoOfBytes = 7;
		return;
	}	*/
	if (Command == 30) {	// Activate control outputs using default operating time
		// 1 offset as command will be stored in the 0th offset
		for(Counter=1;Counter < PackLength;Counter+=2) {
			// mask 2 msb bits of msb as status of output will be stored
			if (GetInt(PackReceived[Counter],(PackReceived[Counter+1]&0x0f))>DOMS*8) {
				ReplyIllegalPara();
				return;
			}
			ChannelNumber = GetInt(PackReceived[Counter],PackReceived[Counter+1]&0x0f);
			SetOChannelStatus(ChannelNumber,PackReceived[Counter+1]&0xf0,DefaultOTime);
		}
		PackToSend[1][2]=1;
		PackToSend[1][3]=0;
		CalcCheckSum(5);
		NoOfBytes = 7;
		return;
	}	
	if (Command == 31) {	// Set or Reset the input status
		for(Counter=1;Counter < PackLength;Counter+=2) {
			// mask 2 msb bits of msb as status of output will be stored
			if (GetInt(PackReceived[Counter],(PackReceived[Counter+1]&0x0f))>DIMS*8) {
				ReplyIllegalPara();
				return;
			}
			ChannelNumber = GetInt(PackReceived[Counter],PackReceived[Counter+1]&0x0f);
			SetIChannelStatus(ChannelNumber,PackReceived[Counter+1]&0xf0);
		}
		PackToSend[1][2]=1;
		PackToSend[1][3]=0;
		CalcCheckSum(5);
		NoOfBytes = 7;
		return;
	}		

	if (Command == 53) {		// Set RTU time clock
//		SetTime(PackReceived[1],PackReceived[2],PackReceived[3]);
		PackToSend[1][2]=1;
		PackToSend[1][3]=0;
		CalcCheckSum(5);
		NoOfBytes = 7;	
		return;
	}		
   	if (Command ==72) {			// Reset the force input status - intialises to power on status
		for (Counter=0; Counter<DIMS; Counter++) {
			in[Counter] =	0x00;
			org_buf[Counter] = 0x00;
			dup_buf[Counter] = 0x00;
			PrevIn[Counter] = 0x00;
			setin[Counter] = 0x0;
			rstin[Counter] = 0xff;
		}   
		PackToSend[1][2]=1;
		PackToSend[1][3]=0;
		CalcCheckSum(5);
		NoOfBytes = 7;			
		return;
   }   
   if (Command ==73) {			// Reset the force output status - intialises to actual status
		for (Counter=0; Counter<DOMS; Counter++) {
			setout[Counter] = 0x0;
			rstout[Counter] = 0xff;
		}
		PackToSend[1][2]=1;
		PackToSend[1][3]=0;
		CalcCheckSum(5);
		NoOfBytes = 7;			
		return;
   }      
	if (Command == 75) {	
   		Parameters();
		PackToSend[1][2]=1;
		PackToSend[1][3]=0;
		CalcCheckSum(5);
		NoOfBytes = 7;			
		return;
	}   

	if (Command == 77) {	// put original status of input
		for(Counter=1;Counter < PackLength;Counter+=2) {
			// mask 2 msb bits of msb as status of output will be stored
			if (GetInt(PackReceived[Counter],(PackReceived[Counter+1]&0x0f))>DIMS*8) {
				ReplyIllegalPara();
				return;
			}
			ChannelNumber = GetInt(PackReceived[Counter],PackReceived[Counter+1]&0x0f);
			OrgIChannelStatus(ChannelNumber);
		}
		PackToSend[1][2]=1;
		PackToSend[1][3]=0;
		CalcCheckSum(5);
		NoOfBytes = 7;
		return;
	}		
	if (Command == 78) {	// put original status of output
		for(Counter=1;Counter < PackLength;Counter+=2) {
			// mask 2 msb bits of msb as status of output will be stored
			if (GetInt(PackReceived[Counter],(PackReceived[Counter+1]&0x0f))>DOMS*8) {
				ReplyIllegalPara();
				return;
			}
			ChannelNumber = GetInt(PackReceived[Counter],PackReceived[Counter+1]&0x0f);
			OrgOChannelStatus(ChannelNumber);
		}
		PackToSend[1][2]=1;
		PackToSend[1][3]=0;
		CalcCheckSum(5);
		NoOfBytes = 7;
		return;
	}		
	if (Command == 80) {	// send the version number from the ROM
		Counter=strlen(Version);		// used at three places so stored in variable
		for(Counter1=0;Counter1<20;Counter1++) {
			if (! Version[Counter1]) {
				break;
			}
			PackToSend[1][5+Counter1]=Version[Counter1];
		}		
		PackToSend[1][2]=1+Counter1;
		PackToSend[1][3]=0;
		CalcCheckSum(5+Counter);	// Counter contains the length of the version string
		NoOfBytes = 7 + Counter;	// Counter contains the length of the version string
		return;
	}		
	if (Command == 81) {	// send the release date from the ROM
		Counter=strlen(ReleaseDate);		// used at three places so stored in variable
		for(Counter1=0;Counter1<20;Counter1++) {
			if (! ReleaseDate[Counter1]) {
				break;
			}
			PackToSend[1][5+Counter1]=ReleaseDate[Counter1];
		}
		PackToSend[1][2]=1+Counter1;		
		PackToSend[1][3]=0;
		CalcCheckSum(5+Counter);	// Counter contains the length of the release date string
		NoOfBytes = 7 + Counter;	// Counter contains the length of the release date string
		return;
	}			
   if (Command ==90) {
	   	DiagMode=0;
	   	SendInfo();
		return;
   }
   if (Command ==91) {
		//EndOfWeighing();
		//InitWeighing();
   }   
   if (Command ==92) {
		//InitWeighing();
   }
	if (Command ==93) {
		//InitWeighing();
		ProcessTrack=1;		// trackswitch inputs will be processed now only
		AcquireZero=1;		// zero the current weight
	}
	if (Command ==94) {
		SendZeroToWS();
	}
	if (Command == 101) {	
   		Parameters1();
		PackToSend[1][2]=1;
		PackToSend[1][3]=0;
		CalcCheckSum(5);
		NoOfBytes = 7;			
		return;
	}   
	if (Command == 102) {	
   		Parameters2();
		PackToSend[1][2]=1;
		PackToSend[1][3]=0;
		CalcCheckSum(5);
		NoOfBytes = 7;			
		return;
	}   
	if (Command == 103) {	
   		Parameters3();
		PackToSend[1][2]=1;
		PackToSend[1][3]=0;
		CalcCheckSum(5);
		NoOfBytes = 7;			
		return;
	}   
	if (Command == 104) {	
   		Parameters4();
		PackToSend[1][2]=1;
		PackToSend[1][3]=0;
		CalcCheckSum(5);
		NoOfBytes = 7;			
		return;
	}   
	if (Command == 105) {	
   		Parameters5();
		PackToSend[1][2]=1;
		PackToSend[1][3]=0;
		CalcCheckSum(5);
		NoOfBytes = 7;			
		return;
	}   
	
	PackToSend[1][2]=1;
	PackToSend[1][3]=0;
	CalcCheckSum(5);
	NoOfBytes = 7;	
	return;	
}

unsigned char GetChannelStatus(unsigned int ChannelNumber)
{
	ChannelNumber = ChannelNumber - 1;
	ModuleNumber = ChannelNumber / 8;
	ChannelBit = 1 << (ChannelNumber  - ModuleNumber * 8 - 1);
	if (in[ModuleNumber] & ChannelBit)
		return (0xff);
	else
		return (0x00);
}		

void SetIChannelStatus(unsigned int ChannelNumber, unsigned char Status)
{
	ChannelNumber = ChannelNumber - 1;
	ModuleNumber = ChannelNumber / 8;
	ChannelBit = 1 << (ChannelNumber  - ModuleNumber * 8 );
	if (ChannelNumber < DIMS * 8) {
		InCounter = ModuleNumber;
	}
	if (Status == 0x10) {
		ITimerRun[ChannelNumber] = 0;
		ITimer[ChannelNumber] = DefaultOTime;
		//in[ModuleNumber] |= ChannelBit;
		setin[ModuleNumber] |= ChannelBit;
		rstin[ModuleNumber] |= ChannelBit;		
		ITimerRun[ChannelNumber] = 1;
//		INextStatus[ChannelNumber] = 0x80;			// set the next status as low

/*
***************changed************************ */
						//	INextStatus[ChannelNumber] = 0x41;			// put back original status
		
		INextStatus[ChannelNumber] = 0x41;;
/* ***************changed*************************	*/


		IForced++;
	}
	else 	if (Status == 0x20){
		ITimerRun[ChannelNumber] = 0;
		ITimer[ChannelNumber] = DefaultOTime;
		//in[ModuleNumber] &= ~ChannelBit;
		rstin[ModuleNumber] &= ~ChannelBit;
		ITimerRun[ChannelNumber] = 1;
//		INextStatus[ChannelNumber] = 0x40;			// set the next status as high
		INextStatus[ChannelNumber] = 0x41;			// put back original status
		IForced++;
	}
	else 	if (Status == 0x40) {
				// Note that channel number will be from offset 0
				//if (ChannelNumber < 80) {
					//in[ModuleNumber] |= ChannelBit;
					setin[ModuleNumber] |= ChannelBit;
					rstin[ModuleNumber] |= ChannelBit;
				//}
				//else {
					//if (ChannelNumber == 82) { // Note that channel number will be from offset 0
					//	SetBatchCyleOn;
					//}
					//else if (ChannelNumber == 83) {	// Note that channel number will be from offset 0
					//	SetBatchCyleOff;
					//}
					//else {
					//	in[ModuleNumber] |= ChannelBit;
					//}
				//}
	}
	else 	if (Status == 0x41) {			 		 // put back original status
			setin[ModuleNumber] &= ~ChannelBit;
			rstin[ModuleNumber] |= ChannelBit;
	}
	else {
			// Note that channel number will be from offset 0
			//if (ChannelNumber < 64) {
				//in[ModuleNumber] &= ~ChannelBit;
				rstin[ModuleNumber] &= ~ChannelBit;
			//}
			//else {
			//	in[ModuleNumber] &= ~ChannelBit;
			//}
	}
	if (ChannelNumber>= DIMS_DEF*8) {	// internal input buffer is set	
		DataOut = in[ModuleNumber];
		DataOut |= setin[ModuleNumber];	
		DataOut &= rstin[ModuleNumber];
		in[ModuleNumber] = DataOut;		
	}
}		

void SetOChannelStatus(unsigned int ChannelNumber, unsigned char Status, unsigned int Duration)
{
	ChannelNumber = ChannelNumber - 1;
	ModuleNumber = ChannelNumber / 8;
	ChannelBit = 1 << (ChannelNumber  - ModuleNumber * 8 );
	OutCounter = ModuleNumber;
	if ((Status == 0x10) && Duration > 0){
		OTimerRun[ChannelNumber] = 0;
		OTimer[ChannelNumber] = Duration;
//		out[ModuleNumber] |= ChannelBit;
		setout[ModuleNumber] |= ChannelBit;
		rstout[ModuleNumber] |= ChannelBit;
		OTimerRun[ChannelNumber] = 1;
//		ONextStatus[ChannelNumber] = 0x80;			// set the next status as low
		ONextStatus[ChannelNumber] = 0x41;			// put back original status
		OForced++;
	}
	else 	if ((Status == 0x20) && Duration > 0){
		OTimerRun[ChannelNumber] = 0;
		OTimer[ChannelNumber] = Duration;
		//out[ModuleNumber] &= ~ChannelBit;
		rstout[ModuleNumber] &= ~ChannelBit;
		OTimerRun[ChannelNumber] = 1;
//		ONextStatus[ChannelNumber] = 0x40;			// set the next status as high
		ONextStatus[ChannelNumber] = 0x41;			// put back original status
		OForced++;
		}
		else if (Status == 0x40) {
				//out[ModuleNumber] |= ChannelBit;
				setout[ModuleNumber] |= ChannelBit;
				rstout[ModuleNumber] |= ChannelBit;
			}
			else 	if (Status == 0x41) {			  // put back original status
				setout[ModuleNumber] &= ~ChannelBit;
				rstout[ModuleNumber] |= ChannelBit;
			}
		  	else if ((Status == 0x80) || Duration == 0) {
				//out[ModuleNumber] &= ~ChannelBit;
				rstout[ModuleNumber] &= ~ChannelBit;
			}
	SendOutputs=1;
	OutputTimer=0;			
}		


void OrgIChannelStatus(unsigned int ChannelNumber)
{
	ChannelNumber = ChannelNumber - 1;
	ModuleNumber = ChannelNumber / 8;
	ChannelBit = 1 << (ChannelNumber  - ModuleNumber * 8 );
	if (ChannelNumber < DIMS * 8) {
		InCounter = ModuleNumber;
	}
	setin[ModuleNumber] &= ~ChannelBit;
	rstin[ModuleNumber] |= ChannelBit;
}		

void OrgOChannelStatus(unsigned int ChannelNumber)
{
	ChannelNumber = ChannelNumber - 1;
	ModuleNumber = ChannelNumber / 8;
	ChannelBit = 1 << (ChannelNumber  - ModuleNumber * 8 );
	setout[ModuleNumber] &= ~ChannelBit;
	rstout[ModuleNumber] |= ChannelBit;
}		

void CalcCheckSum(unsigned int Bytes)
{
	unsigned int Counter,CheckSum;
	CheckSum = 0;
	for(Counter=0;Counter<Bytes;Counter++) {
		CheckSum=GetCSum(CheckSum,PackToSend[1][Counter]);
	}
	PackToSend[1][Bytes] = GetLSB(CheckSum);
	PackToSend[1][Bytes+1] = GetMSB(CheckSum);
}

void InsertByte()
{
	unsigned int TempCounter;
	unsigned char TempBuffer;
	BytesToSend[1]++;
	for (TempCounter=BytesToSend[1]-1;TempCounter>Counter;TempCounter--) {
		TempBuffer=PackToSend[1][TempCounter-1];
		PackToSend[1][TempCounter]=TempBuffer;
	}
		return;
}


void StartXmit1(unsigned int Bytes1)
{
	/*
	if (BroadCast) 
		return;
		
	BytesToSend[1]=Bytes;
	for(Counter=1;Counter<BytesToSend[1];Counter++) {
		if ((PackToSend[1][Counter] == 0x7e)||(PackToSend[1][Counter] == 0x10)) {
			InsertByte();
			PackToSend[1][Counter] = 0x10;
			Counter++;
		}
	}		
	*/
	BytesToSend[1]=Bytes1;	
	//BytesSent[1]=1;
		//for(Counter=1;Counter<BytesToSend[1];Counter++)
		 {
	//if(BytesSent[1]>100){BytesSent[1]=1;}
	if(BytesSent[1]>Bytes1){BytesSent[1]=0;}
	u1tbl = PackToSend[1][BytesSent[1]++];
		}		
				//u1tbl = PackToSend[1][3];

	/*
	u1tbl = PackToSend[1][6];
	u1tbl = PackToSend[1][7];
	u1tbl = PackToSend[1][8];
	u1tbl = PackToSend[1][11];
	u1tbl = PackToSend[1][12];
	*/
	return;
}

void StartXmit2(unsigned int Bytes)
{
	BytesToSend[2]=Bytes;
	BytesSent[2]=1;
	u2tbl= PackToSend[2][0];
	LED8 ^= 1 ;			// toggle as query is one byte only				
	return;
}
void StartXmit22(unsigned int Bytes6)
{
	BytesToSend[2]=Bytes6;
	if(BytesSent[2]>100)
	{
	//BytesSent[2]=1;
	BytesSent[2]=1;
	}
	u2tbl= PackToSend[2][BytesSent[2]++];
	delay(100);
	LED8 ^= 1 ;			// toggle as query is one byte only		
	/*
	BytesToSend[1]=Bytes1;	
	//BytesSent[1]=1;
		//for(Counter=1;Counter<BytesToSend[1];Counter++)
		 {
	//if(BytesSent[1]>100){BytesSent[1]=1;}
	if(BytesSent[1]>Bytes1){BytesSent[1]=0;}
	u1tbl = PackToSend[1][BytesSent[1]++];
		}*/		
	return;
}

void StartXmit0(unsigned int Bytes)
{
	BytesToSend[0]=Bytes;
	BytesSent[0]=1;
	u0tbl= PackToSend[0][0];
	return;
}

void StartXmit6(unsigned int Bytes)
{
	BytesToSend[3]=Bytes;
	BytesSent[3]=1;
	u6tbl= PackToSend[3][0];
	return;
}

void ReplyCommandError()
{
	PackToSend[1][2]=1;
	PackToSend[1][3]=0;
	PackToSend[1][4]=0x3f;		// command error - number 63
	CalcCheckSum(5);
	NoOfBytes = 7;	
	return;
}

void ReplyCRCError()
{
	PackToSend[1][2]=1;
	PackToSend[1][3]=0;
	PackToSend[1][4]=0x3e;		// crc error - number 62
	CalcCheckSum(5);
	NoOfBytes = 7;	
	return;
}

void ReplyIllegalPara()
{
	PackToSend[1][2]=1;
	PackToSend[1][3]=0;
	PackToSend[1][4]=0x3c;		// illegal command parameters - number 60
	CalcCheckSum(5);
	NoOfBytes = 7;	
	return;
}

void QueryAD(void)
{
	QueryFlintech();

/*	if (ADFailCount[0] >= 20) {
		SendQueryAD=1;
		ADFailCount[0]=0;
		ADFailStatus=1;
		ADTimes[0]=0;
		CurrentWeight=0xffffffff;
		Positive=1;						// set positive also 1. to show ws comm failin scada
		LED7 = 1;						// clear led
		if (MessageNumber==14){			// If Power on message then set ready to weigh
			if (ProcessTrack) {MessageNumber=1;}
			else {MessageNumber=16;}
		}
		OnWSystemFailLP;				// on weighing system fail lamp
	}*/
}

void QueryFlintech(void)
{
	if (SendQueryAD) {
		ADTimes[0]++;
		if ((ADTimes[0] >= 1) ) {
			ADFailCount[0]++;
			ADTimes[0]=0;
		}
		SendQueryAD=0;
		if (ResetWS) {
			CharCount=0;BytesExpectd=0;
			SendSoftReset();
			WaitForWeight=0;ResetSent=1;ADWaitTimer=100;
			return;
		}
		if (AcquireZero) {
			CharCount=0;BytesExpectd=0;
			SendZeroToWS();	
			WaitForWeight=0;ZeroSent=1;ADWaitTimer=2000;		// wait for 1 second
			return;
		}
		if (SetContinous) {
			CharCount=0;BytesExpectd=9;
			EnquireWt();ADWaitTimer=50;
			return;
		}
		else {
				LED8=1;			// clear transmitt led
		}
		return;
	}
	if (ADFailCount[0] >= 20) {
		SendQueryAD=1;
		ADFailCount[0]=0;
		ADFailStatus=1;
		ADTimes[0]=0;
		CurrentWeight=0xffffffff;
		Positive=1;						// set positive also 1. to show ws comm failin scada
		LED7 = 1;						// clear led
		if (MessageNumber==14){			// If Power on message then set ready to weigh
			if (ProcessTrack) {MessageNumber=1;}
			else {MessageNumber=16;}
		}
		OnWSystemFailLP;				// on weighing system fail lamp
		SetContinous=1;					// set continous mode
	}
	return;	
}

void SendInfo()
{	
	Var6.value=PackReceived[2];
	Resolution=PackReceived[4] * 256 + PackReceived[3];		// units position of resolution will not be available
	WeightFromSCADA=PackReceived[6] * 256 + PackReceived[5];
	if (!DisplayWeight) {WeightToUpdate=WeightFromSCADA;}	// if recalculated in pc, display this weight

	//command is available in PackToSend[1][4];
	if (Positive) {
		PackToSend[1][5] = '+' ;
	}
	else {
		PackToSend[1][5] = '-' ;
	}
	PackToSend[1][6] = LGetLSB(CurrentWeight);
	PackToSend[1][7] = LGetMID(CurrentWeight);	
	PackToSend[1][8] = LGetMSB(CurrentWeight);	
	PackToSend[1][9]=Direction;
	PackToSend[1][10]=MessageNumber;
	PackToSend[1][11]=WAGONS;
	PackToSend[1][12]=SWWEIGH;
	PackToSend[1][13]=WBSTATE;
	PackToSend[1][14] = GetLSB(LastAxleWeid);
	PackToSend[1][15] = GetMSB(LastAxleWeid);	
	
	PackToSend[1][16] = GetLSB(A1Speed);
	PackToSend[1][17] = GetMSB(A1Speed);	
	PackToSend[1][18] = GetLSB(A2Speed);
	PackToSend[1][19] = GetMSB(A2Speed);	
	PackToSend[1][20] = GetLSB(ZoneSpeed);
	PackToSend[1][21] = GetMSB(ZoneSpeed);	

	PackToSend[1][22] = GetLSB(AXCOUNT[0]);
	PackToSend[1][23] = GetMSB(AXCOUNT[0]);	
	PackToSend[1][24] = GetLSB(AXCOUNT[1]);
	PackToSend[1][25] = GetMSB(AXCOUNT[1]);	
	PackToSend[1][26] = GetLSB(AXCOUNT[2]);
	PackToSend[1][27] = GetMSB(AXCOUNT[2]);	
	PackToSend[1][28] = GetLSB(AXCOUNT[3]);
	PackToSend[1][29] = GetMSB(AXCOUNT[3]);	

	PackToSend[1][30] = GetLSB(AxlesWeighed);
	PackToSend[1][31] = GetMSB(AxlesWeighed);		//AxleWtCount
	PackToSend[1][32] = GetLSB(IgnoredWtCount);
	PackToSend[1][33] = GetMSB(IgnoredWtCount);	

	PackLength=12+2*3+2*4+2*2;
	NoOfBytes=34; // position of the next data in the array
	
	if (WAGONS != 0)  {
		if (PackReceived[1] <= WAGONS) {		
			Counter=PackReceived[1]-1;
			PackToSend[1][NoOfBytes]=PackReceived[1];
			PackLength++;NoOfBytes++;
		
			PackToSend[1][NoOfBytes]=WagonType[Counter];
			PackLength++;NoOfBytes++;
			
			PackToSend[1][NoOfBytes] = LGetLSB(Weight[Counter]);
			PackLength++;NoOfBytes++;
			
			PackToSend[1][NoOfBytes] = LGetMID(Weight[Counter]);
			PackLength++;NoOfBytes++;
			
			PackToSend[1][NoOfBytes] = LGetMSB(Weight[Counter]);
			PackLength++;NoOfBytes++;
	
			PackToSend[1][NoOfBytes] = GetLSB(WAxleWeight[Counter][0]);
			PackLength++;NoOfBytes++;
				
			PackToSend[1][NoOfBytes] = GetMSB(WAxleWeight[Counter][0]);
			PackLength++;NoOfBytes++;

			PackToSend[1][NoOfBytes] = GetLSB(WAxleWeight[Counter][1]);
			PackLength++;NoOfBytes++;
				
			PackToSend[1][NoOfBytes] = GetMSB(WAxleWeight[Counter][1]);
			PackLength++;NoOfBytes++;
			
			PackToSend[1][NoOfBytes] = GetLSB(WAxleWeight[Counter][2]);
			PackLength++;NoOfBytes++;
				
			PackToSend[1][NoOfBytes] = GetMSB(WAxleWeight[Counter][2]);
			PackLength++;NoOfBytes++;
			
			PackToSend[1][NoOfBytes] = GetLSB(WAxleWeight[Counter][3]);
			PackLength++;NoOfBytes++;
				
			PackToSend[1][NoOfBytes] = GetMSB(WAxleWeight[Counter][3]);
			PackLength++;NoOfBytes++;

			PackToSend[1][NoOfBytes]=GetLSB(WagonSpeed[Counter]);
			PackLength++;NoOfBytes++;

			PackToSend[1][NoOfBytes]=GetLSB(WagonA2Speed[Counter]);
			PackLength++;NoOfBytes++;
		}			
	}
	PackToSend[1][2]=GetLSB(PackLength);
	PackToSend[1][3]=GetMSB(PackLength);
	CalcCheckSum(NoOfBytes);
	NoOfBytes =  2+NoOfBytes;
	return;
}

void SendSoftReset(void)
{
	Counter1=0;
	PackToSend[2][Counter1++] = 'S';
	PackToSend[2][Counter1++] = 'R';
	PackToSend[2][Counter1++] = 0x0d;
	StartXmit2(Counter1	);
	return;
}

/*void SendResetWLToWS(void)
{
	// resetting wl mode not available, send wt. cmd sent
	Counter1=0;
	PackToSend[2][Counter1++] = 'G';
	PackToSend[2][Counter1++] = 'N';
	PackToSend[2][Counter1++] = 0x0d;
	StartXmit2(Counter1	);
	return;
}
*/

void SendZeroToWS(void)
{
	Counter1=0;
	PackToSend[2][Counter1++] = 'S';
	PackToSend[2][Counter1++] = 'Z';
	PackToSend[2][Counter1++] = 0x0d;
	StartXmit2(Counter1	);
	return;
}

void EnquireWt(void)
{
	Counter1=0;
	PackToSend[2][Counter1++] = 'S';
	PackToSend[2][Counter1++] = 'N';
	PackToSend[2][Counter1++] = 0x0d;
	StartXmit2(Counter1++	);	
	return;
	
	Counter1=0;
	PackToSend[2][Counter1++] = 'G';
	PackToSend[2][Counter1++] = 'N';
	PackToSend[2][Counter1++] = 0x0d;
	StartXmit2(Counter1	);
	return;
}

void EnqLastSl(void)
{
	PackToSend[2][0] = 'l';
	StartXmit2(0);	
	return;
}

void EnqReqAxle(void)
{
	PackToSend[2][0] = '#';
	//eqnuire the weight of LAXONWB

	Counter1 = ActualAxleWeighed + IgnoredWtCount - MissedWtCount;
	
	Digit_U = Counter1 % 10;
	
	Counter1 = Counter1 / 10;Digit_T = Counter1 % 10;
	
	Counter1 = Counter1 / 10;Digit_H = Counter1 % 10;
	
	Counter1=1;		// same variable used
	if (Digit_H != 0) {
		PackToSend[2][Counter1++] = Digit_H + 0x30;
		PackToSend[2][Counter1++] = Digit_T + 0x30;
	}
	else {
		if (Digit_T != 0) {PackToSend[2][Counter1++] = Digit_T + 0x30;}
	}
	PackToSend[2][Counter1++] = Digit_U + 0x30;
	PackToSend[2][Counter1++] = 0x0d;
	StartXmit2(Counter1	);
	
/*	Counter1=1;	
	PackToSend[2][Counter1++] = '1';
	PackToSend[2][Counter1++] = 0x0d;
	StartXmit2(3);		//Counter1
*/	
	return;
}

void FormRemotePack(void)
{
	BytesToSend[3]=0;
	PackToSend[3][BytesToSend[3]++]=0x02;
	
	IncludeWeight();	/* include the weight to be updated. current or axle / wagon weight */
	CSum=0;
	for (Counter=1;Counter< BytesToSend[3];Counter++) {
		CSum = CSum ^ PackToSend[3][Counter];
	}
	PackToSend[3][BytesToSend[3]++]=0x03;
	PackToSend[3][BytesToSend[3]++]=CSum;
	
	/*changed*/
	/*
		PackToSend[3][BytesToSend[3]++]='2';
		PackToSend[3][BytesToSend[3]++]='4';
		PackToSend[3][BytesToSend[3]++]='0';
		PackToSend[3][BytesToSend[3]++]='2';
		PackToSend[3][BytesToSend[3]++]='2';
		PackToSend[3][BytesToSend[3]++]='1';
		PackToSend[3][BytesToSend[3]++]='0';
		PackToSend[3][BytesToSend[3]++]='5';
		PackToSend[3][BytesToSend[3]++]='0';
		PackToSend[3][BytesToSend[3]++]='4';*/

	StartXmit6(BytesToSend[3]);		// BytesToSend[3] will be again updated by BytesToSend[3] in startxmit6
}
	
void IncludeWeight(void)
{
	if (WeightToUpdate > 0) {
		PackToSend[3][BytesToSend[3]++]=0x31 ;
	}
	else {
		PackToSend[3][BytesToSend[3]++]=0x30 ;
	}

	//CByte = ((WeightToUpdate >> 8 ) & 0xff);
	CByte =  LGetMID(DataToUpdate);
	CheckNIncludeByte();

	//CByte = (WeightToUpdate & 0xff);
	CByte =  LGetLSB(DataToUpdate);
	CheckNIncludeByte();	

	CByte = DPos;
	CheckNIncludeByte();	
		
	CByte = MsgToD;
	CheckNIncludeByte();	
	
	CByte = MessageNumber;
	CheckNIncludeByte();

	CByte = WAGONS;
	CheckNIncludeByte();
	
	return;
}

void CheckNIncludeByte(void)
{
	if (CByte == 0x10) {
		PackToSend[3][BytesToSend[3]++]=0x10;
	}
	if (CByte == 0x0) {
		PackToSend[3][BytesToSend[3]++]=0x10;
	}
	if (CByte == 0x02) {
		PackToSend[3][BytesToSend[3]++]=0x10;
	}
	if (CByte == 0x03) {
		PackToSend[3][BytesToSend[3]++]=0x10;
	}
	if (CByte == 0x0) {
		PackToSend[3][BytesToSend[3]++]=0x30;
	}
	else {
		PackToSend[3][BytesToSend[3]++]=CByte ;
	}
	return;

}	

void FormRemotePack1(void)
{
	if (WeightToUpdate< 0) { 
	  WtToConv=0-WeightToUpdate; NetString[0]='-';
	}
	else {
	 WtToConv=WeightToUpdate; NetString[0]=' ';
	}                       
	NetString[6] = '0';
	NetString[5]= (WtToConv % 10) | 0x030;
	WtToConv = WtToConv/10;
	NetString[4]= (WtToConv % 10) | 0x030;
	WtToConv = WtToConv/10;
	NetString[3]= (WtToConv % 10) | 0x030;
	WtToConv = WtToConv/10;
	NetString[2]= (WtToConv % 10) | 0x030;
	WtToConv = WtToConv/10;
	NetString[1]= (WtToConv % 10) | 0x030;
	if (NetString[0]=='-') {NetString[1]='-';}

	BytesToSend[0]=0;
	PackToSend[0][BytesToSend[0]++]=0x01 ;
    PackToSend[0][BytesToSend[0]++]=NetString[0];
    PackToSend[0][BytesToSend[0]++]=NetString[1];
    PackToSend[0][BytesToSend[0]++]=NetString[2];
    PackToSend[0][BytesToSend[0]++]=NetString[3];
    PackToSend[0][BytesToSend[0]++]=NetString[4];
    PackToSend[0][BytesToSend[0]++]=NetString[5];
    PackToSend[0][BytesToSend[0]++]=NetString[6];
	PackToSend[0][BytesToSend[0]++]=0x0d;

	StartXmit0(BytesToSend[0]);		// BytesToSend[0] will be again updated by BytesToSend[0] in startxmit0
}

void IncludeWeight1(void)
{
	if (Positive) {
		PackToSend[0][BytesToSend[0]++]=0x31 ;
	}
	else {
		PackToSend[0][BytesToSend[0]++]=0x30 ;
	}

	CByte =  LGetMID(ADValue[0]);
	CheckNIncludeByte1();

	CByte =  LGetLSB(ADValue[0]);
	CheckNIncludeByte1();	
	
	CByte = MsgToD;
	CheckNIncludeByte1();	
	
	CByte = MessageNumber;
	CheckNIncludeByte1();

	CByte = WAGONS;
	CheckNIncludeByte1();
	
	return;
}

void CheckNIncludeByte1(void)
{
	if (CByte == 0x10) {
		PackToSend[0][BytesToSend[0]++]=0x10;
	}
	if (CByte == 0x0) {
		PackToSend[0][BytesToSend[0]++]=0x10;
	}
	if (CByte == 0x02) {
		PackToSend[0][BytesToSend[0]++]=0x10;
	}
	if (CByte == 0x03) {
		PackToSend[0][BytesToSend[0]++]=0x10;
	}
	if (CByte == 0x00) {
		PackToSend[0][BytesToSend[0]++]=0x30;
	}
	else {
		PackToSend[0][BytesToSend[0]++]=CByte ;
	}
	return;
}


void ProcessByteFlint(void)
{
	if (CharIn[2] == CharOut[2]) {
		return;
	}
	CharRcvd = CharRTable[2][CharOut[2]++];
	//PackToSend[1][Counter1++] = CharRcvd;
	//StartXmit1(Counter1 );
	if (CharOut[2] > 99) {CharOut[2]=0;}
	if ( CharRcvd == 13) {	
		//if ( CharCount == BytesExpectd) {ADOk=1;return;}	
		if (CharCount>0) {ADOk=1;return;}	// bytes expected not used 
	}	
	ADString[CharCount]=CharRcvd;
	CharCount++;
	//	PackToSend[1][CharCount++] = CharRcvd;
	//StartXmit1(Counter1 );
	if ( CharCount > 99) {CharOut[2]=0;CharCount=0;return;}
	if ((CharRcvd =='\r')||(CharRcvd =='\n')||(CharRcvd ==0x0a)||(CharRcvd ==0x0d)) {CharOut[2]=0;
	CharCount=0;
	//for(ixz=0;ixz<=100;ixz++)ADString[ixz]=0xff;
	return;}
}
/*
void ProcessFlintech(void)
{
	if (ADOk) {
		ADOk = 0;OffWSystemFailLP;		
		if (++WeightCount[0]>= 2) {
			LED7 ^= 1;			// toggle  led
			WeightCount[0]=0;
		}				
		ADFailCount[0]=0;ADFailStatus=0;SendQueryAD=0;
		AllZeros=1;
		if (ResetSent) {
			if (ADString[0]=='O') {		// OK will be received
				ResetWS=0;ResetSent=0;
				ADWaitTimer=1000;	// not much delay required
				ADCounter=0;		// reset timer for safe
				SendQueryAD=0;		// reset for safe
				AckResetWS();		// ack the Track weighing RTU
				SetContinous=1;		// set continous mode
			}			
			return;
		}	
		if (ZeroSent) {
			if (ADString[0]=='O') {
				ZeroSent=0;AcquireZero=0;
				OnSystemReadyLP;OnSystemReadyRelay;
				AckZero();
				SetContinous=1;		// set continous mode
			}			
			return;
		}
		if (SlNoResetSent) {
			if (ADString[0]=='N') {		// send net weight cmd is only sent
				ResetSlNo=0;SlNoResetSent=0;
				AxlesWeighed=0;		// this contains the axle count weighed
				SetContinous=1;		// set continous mode
			}			
			return;
		}
		if (ADString[0]=='N') {		// net weight is received
			SetContinous=0;			// reset continous mode
			CharCount=0;			// reset charcount as weight is received continously

			PowerNext=0;ExpPower=0;
			Counter1=0;Positive=1;	// default as positive number
		
			for (Counter=1;Counter<9;Counter++) {	
				if (ADString[Counter]=='-') {	// first position will only contain -ve sign. no issues if condition is checked always
					Positive=0;				
					continue;
				}			
				if (ADString[Counter]=='.') {	// ignore decimal place
					continue;
				}			
				if (ADString[Counter]=='+') {	// ignore positive sign
					continue;
				}			
				ADBuf[Counter1] = ADString[Counter];
				if (ADBuf[Counter1] != '0') AllZeros=0;
				Counter1++;
			}
			ADBuf[Counter1-1] = 0;	// end of string - ignore one zero
		
			ADValue[0]=atol(ADBuf) ;
			if (!Positive) {
				ADValue[0] = ADValue[0] * -1 ;
			}
		
			CurrentWeight = ADValue[0]; //-ZeroWeight;
			ActualWt = CurrentWeight;
			Positive=0;
			if (CurrentWeight >= 0) {Positive=1;}
		
			if (MessageNumber==14)	{// If Power on message then set ready to weigh
				if (ProcessTrack) {MessageNumber=1;}
				else {MessageNumber=16;}
			}
			if (WaitForWeight) { CheckWeight();return;}
			else {WeightToUpdate=ActualWt;}	//CurrentWeight
		}
	}		
	return ;	
}
*/
void ProcessFlintech(void)
{
	if (ADOk) {
		ADOk = 0;OffWSystemFailLP;		
		if (++WeightCount[0]>= 2) {
			LED7 ^= 1;			// toggle  led
			WeightCount[0]=0;
		}				
		ADFailCount[0]=0;ADFailStatus=0;SendQueryAD=0;
		AllZeros=1;
		if (ResetSent) {
			if (ADString[0]=='O') {		// OK will be received
				ResetWS=0;ResetSent=0;
				ADWaitTimer=1000;	// not much delay required
				ADCounter=0;		// reset timer for safe
				SendQueryAD=0;		// reset for safe
				AckResetWS();		// ack the Track weighing RTU
				SetContinous=1;		// set continous mode
			}			
			return;
		}	
		if (ZeroSent) {
			if (ADString[0]=='O') {
				ZeroSent=0;AcquireZero=0;
				OnSystemReadyLP;OnSystemReadyRelay;
				AckZero();
				SetContinous=1;		// set continous mode
			}			
			return;
		}
		if (SlNoResetSent) {
			if (ADString[0]=='N') {		// send net weight cmd is only sent
				ResetSlNo=0;SlNoResetSent=0;
				AxlesWeighed=0;		// this contains the axle count weighed
				SetContinous=1;		// set continous mode
			}			
			return;
		}
		if(ADString[0]=='S') //TacCounter 
		{  SetContinous=0;
			for (Counter=1;Counter<9;Counter++)
			{	STAstring[Counter]=ADString[Counter];
			}
			
			if(STAstring[1]==':') //Device status
			{
				if(((STAstring[4]=='1')||(STAstring[3]=='1')||(STAstring[2]=='1'))||((STAstring[4]=='3')||(STAstring[3]=='3')||(STAstring[2]=='3')))
				{
					
						p2_4=1;
						p2_5=0;
				}
				else
				{
						p2_4=0;
						p2_5=1;
				}
			}
			if(ADString[1]=='+') //Device step Size
			{
					
			}
			return;
		}
		if(ADString[0]=='E') //TacCounter 
		{
			SetContinous=0;			// reset continous mode
			CharCount=0;
			if(ADString[1]=='+')
			{
				TaCOuntRes=1;
				for (Counter=2;Counter<8;Counter++) {	
					CEstring[Counter]=ADString[Counter];		
				}
				
			}
			else if(ADString[1]=='r')  // Error Indication
			{
				ErrSgnl=1;
				error[0]=1;	
			}
			
			return;
		}
		if(ADString[0]=='O')
		{
			if(ADString[1]=='K')
			{
				ErrSgnl=0;
				error[0]=2;	
			}
		}
		/*
		for (Counter=1;Counter<45;Counter++) {
		if (ADString[Counter]==0x0d){ CharIn[2]=0 ;break;}}*/
		if (ADString[0]=='N') 		// net weight is received
		{
			SetContinous=0;			// reset continous mode
			CharCount=0;			// reset charcount as weight is received continously
			//Counter=0;
			PowerNext=0;ExpPower=0;
			Counter1=0;Positive=1;	// default as positive number
		
			for (Counter=1;Counter<9;Counter++) 
			{	
				if (ADString[Counter]=='-') {	// first position will only contain -ve sign. no issues if condition is checked always
					Positive=0;	
						overload=0;
						underload=0;			
					continue;
				}			
				if (ADString[Counter]=='.') {	// ignore decimal place
					continue;
				}			
				if (ADString[Counter]=='+') {	// ignore positive sign
					overload=0;
				 	underload=0;
					continue;
				}	
					if (ADString[1]=='o') {	// overload
					overload=1;
					//break;
					continue;
				}
				if (ADString[1]=='u') {	// underload
					underload=1;
					continue;
				}
					
				if ((ADString[Counter]=='\r')||(ADString[Counter]=='\n')) {	// 
					Counter=0;
					CharIn[2]=0;
					//return;
				}		
				ADBuf[Counter1] = ADString[Counter];
				if (ADBuf[Counter1] != '0') AllZeros=0;
				Counter1++;
			}
			
			
			for (Counter=1;Counter<50;Counter++) {	
				ADString[Counter]=' ';
			}
			ADBuf[Counter1-1] = 0;	// end of string - ignore one zero
		
			ADValue[0]=atol(ADBuf) ;
			if (!Positive) {
				ADValue[0] = ADValue[0] * -1 ;
			}
		
			CurrentWeight = ADValue[0]; //-ZeroWeight;
			ActualWt = CurrentWeight;
			Positive=0;
			if (CurrentWeight >= 0) {Positive=1;}
		
			if (MessageNumber==14)	{// If Power on message then set ready to weigh
				if (ProcessTrack) {MessageNumber=1;}
				else {MessageNumber=16;}
			}
			if (WaitForWeight) { CheckWeight();return;}
			else {WeightToUpdate=ActualWt;}	//CurrentWeight
		}
	}		
	return ;	
}
void CheckWeight(void)
{
/*signed int PrevWt;
unsigned int WtArray[500];
unsigned long int AccuWt;
unsigned int ArrayCnt,AccuCount,PeakWt,PeakPos;*/
	
	if (StartSampling) {
		if (ActualWt < THRESHOLD) {
			CalculateSpeed();
			
			CurrAxleWeight=PeakWt;
			//Avg3_4Peak();
			//AverInAver();
			//AverInPeak();
			
			AxleWeight[AxlesWeighed]=CurrAxleWeight;
			AxleSpeed[AxlesWeighed]=ZoneSpeed;
			AxlesWeighed++;
			StartSampling=0;DisplayAxCount=1;
			WeightToUpdate=CurrAxleWeight;
			return;
		}
		if (abs(PrevWt-ActualWt) < STOREVAL) { return;}
		PrevWt = ActualWt;AccuWt+=ActualWt;AccuCount++;
		WtArray[ArrayCnt++]=ActualWt;
		if(ActualWt>PeakWt) {PeakWt=ActualWt;PeakPos=ArrayCnt;}	// Arraycnt with offset as 1
		return;
	}
	if (ActualWt > THRESHOLD) {
		StartSampling=1;
		PrevWt = ActualWt;AccuWt=ActualWt;AccuCount=1;
		WtArray[0]=ActualWt;ArrayCnt=1;
		PeakWt=ActualWt;PeakPos=1;SpeedTimer=0;
		return;
	}
}


void CalculateSpeed(void)
{
	ZoneSpeed=0;
	if (SpeedTimer<65000) {	//STATIONARY OR VERY SLOW
		// formula (weighzone in mm x 36) / (10 x time in m.sec)
		ZoneSpeed = WeighZone * 36;
		ZoneSpeed = ZoneSpeed / SpeedTimer;
		ZoneSpeed = ZoneSpeed / 10;
	}		
	return;
}

void AverInPeak(void)
{
	AccuWt=0;AccuCount=0;
	for (Counter=PeakPos-5;Counter<PeakPos+5;Counter++) {
		AccuWt+=WtArray[Counter];AccuCount++;
	}
	CurrAxleWeight = AccuWt/AccuCount;	
	return;	
}

void Avg3_4Peak(void)
{	
	// find 3/4 the of peak value
	// add all weights > 3/4 of peak, average and calculate weight
	HalfPeak = PeakWt/2;AccuWt=0;AccuCount=0;
	HalfPeak += HalfPeak/2;
	for (Counter=0;Counter<ArrayCnt;Counter++) {
		if (WtArray[Counter]>=HalfPeak) {
			AccuWt+=WtArray[Counter];AccuCount++;
		}
	}
	CurrAxleWeight = AccuWt/AccuCount;	
	CurrAxleWeight = CurrAxleWeight + PeakWt;
	CurrAxleWeight = CurrAxleWeight / 2;
/*	CurrAxleWeight = CurrAxleWeight* 10;
	
	LTempBuffer = Resolution / 2;
	LTempBuffer += CurrAxleWeight;
	LTempBuffer = CurrAxleWeight / Resolution ;
	LTempBuffer = CurrAxleWeight * Resolution;
	CurrAxleWeight = LTempBuffer;	
	CurrAxleWeight = CurrAxleWeight/ 10;
*/	
	// rounding to resolution not done as it wiil done after correction
	
	return;
}

void AverInAver(void)
{
	SampleAccu[0]=0;SampleAccu[1]=0;SampleAccu[2]=0;SampleAccu[3]=0;
	
	SampleLL[0]=0;
	SampleUL[0]=ArrayCnt * 3;SampleUL[0]=SampleUL[0]/8;

	SampleLL[1]=ArrayCnt / 4;SampleLL[1]++;
	SampleUL[1]=ArrayCnt * 5;SampleUL[1]=SampleUL[1]/8;

	SampleLL[2]=ArrayCnt * 3;SampleLL[2]=SampleLL[2]/8;SampleLL[2]++;
	SampleUL[2]=ArrayCnt * 7;SampleUL[2]=SampleUL[2]/8;
	
	SampleLL[3]=ArrayCnt * 5;SampleLL[3]=SampleLL[3]/8;SampleLL[3]++;
	SampleUL[3]=ArrayCnt ;

	SamplesCount[0]=0;SamplesCount[1]=0;SamplesCount[2]=0;SamplesCount[3]=0;
	for (Counter=0;Counter<ArrayCnt;Counter++) {
		for (Counter1=0;Counter1<4;Counter1++) {
			if ((Counter>=SampleLL[Counter1]) && (Counter <= SampleUL[Counter1])) {
				SampleAccu[Counter1]+=WtArray[Counter];SamplesCount[Counter1]++;
			}
		}
	}
	AccuWt=0;
	for (Counter1=0;Counter1<4;Counter1++) {
		SampleAvg[Counter1]=SampleAccu[Counter1]/SamplesCount[Counter1];
		AccuWt += SampleAvg[Counter1];
	}
	CurrAxleWeight = AccuWt/4;	
	return;
		
}

void Parameters(void)
{
//unsigned int InSpeed[10], OutSpeed[10];
//unsigned long InFactor[10], OutFactor[10];

	StartPos=1;
	for(Counter=0;Counter < 10; Counter++) {
		InSpeed[Counter]=GetInt(PackReceived[StartPos],PackReceived[StartPos+1]);
		StartPos=StartPos+2;
	}

	for(Counter=0;Counter < 10; Counter++) {
		InFactor[Counter]=GetLInt(PackReceived[StartPos],PackReceived[StartPos+1],PackReceived[StartPos+2]);
		StartPos=StartPos+3;
	}

	for(Counter=0;Counter < 10; Counter++) {
		OutSpeed[Counter]=GetInt(PackReceived[StartPos],PackReceived[StartPos+1]);
		StartPos=StartPos+2;
	}

	for(Counter=0;Counter < 10; Counter++) {
		OutFactor[Counter]=GetLInt(PackReceived[StartPos],PackReceived[StartPos+1],PackReceived[StartPos+2]);
		StartPos=StartPos+3;
	}
	
	return;
}

void Parameters1(void)
{
//unsigned long InWtSpeed[10], OutWtSpeed[10];
//unsigned long InWtFactor[5][10], OutWtFactor[5][10];
	StartPos=1;
	for(Counter=0;Counter < 10; Counter++) {
		InWtSpeed[Counter]=GetInt(PackReceived[StartPos],PackReceived[StartPos+1]);
		StartPos=StartPos+2;
	}
	for(Counter=0;Counter < 10; Counter++) {
		OutWtSpeed[Counter]=GetInt(PackReceived[StartPos],PackReceived[StartPos+1]);
		StartPos=StartPos+2;
	}
	for(Counter=0;Counter < 10; Counter++) {
		InWtFactor[0][Counter]=GetLInt(PackReceived[StartPos],PackReceived[StartPos+1],PackReceived[StartPos+2]);
		StartPos=StartPos+3;
	}
	for(Counter=0;Counter < 10; Counter++) {
		OutWtFactor[0][Counter]=GetLInt(PackReceived[StartPos],PackReceived[StartPos+1],PackReceived[StartPos+2]);
		StartPos=StartPos+3;
	}	
	return;
}

void Parameters2(void)
{
//unsigned long InWtSpeed[10], OutWtSpeed[10];
//unsigned long InWtFactor[5][10], OutWtFactor[5][10];
	StartPos=1;
	for(Counter=0;Counter < 10; Counter++) {
		InWtFactor[1][Counter]=GetLInt(PackReceived[StartPos],PackReceived[StartPos+1],PackReceived[StartPos+2]);
		StartPos=StartPos+3;
	}
	for(Counter=0;Counter < 10; Counter++) {
		OutWtFactor[1][Counter]=GetLInt(PackReceived[StartPos],PackReceived[StartPos+1],PackReceived[StartPos+2]);
		StartPos=StartPos+3;
	}
	return;
}

void Parameters3(void)
{
//unsigned long InWtSpeed[10], OutWtSpeed[10];
//unsigned long InWtFactor[5][10], OutWtFactor[5][10];
	StartPos=1;
	for(Counter=0;Counter < 10; Counter++) {
		InWtFactor[2][Counter]=GetLInt(PackReceived[StartPos],PackReceived[StartPos+1],PackReceived[StartPos+2]);
		StartPos=StartPos+3;
	}
	for(Counter=0;Counter < 10; Counter++) {
		OutWtFactor[2][Counter]=GetLInt(PackReceived[StartPos],PackReceived[StartPos+1],PackReceived[StartPos+2]);
		StartPos=StartPos+3;
	}
	return;
}

void Parameters4(void)
{
//unsigned long InWtSpeed[10], OutWtSpeed[10];
//unsigned long InWtFactor[5][10], OutWtFactor[5][10];
	StartPos=1;
	for(Counter=0;Counter < 10; Counter++) {
		InWtFactor[3][Counter]=GetLInt(PackReceived[StartPos],PackReceived[StartPos+1],PackReceived[StartPos+2]);
		StartPos=StartPos+3;
	}
	for(Counter=0;Counter < 10; Counter++) {
		OutWtFactor[3][Counter]=GetLInt(PackReceived[StartPos],PackReceived[StartPos+1],PackReceived[StartPos+2]);
		StartPos=StartPos+3;
	}
	return;
}

void Parameters5(void)
{
//unsigned long InWtSpeed[10], OutWtSpeed[10];
//unsigned long InWtFactor[5][10], OutWtFactor[5][10];
	StartPos=1;
	for(Counter=0;Counter < 10; Counter++) {
		InWtFactor[4][Counter]=GetLInt(PackReceived[StartPos],PackReceived[StartPos+1],PackReceived[StartPos+2]);
		StartPos=StartPos+3;
	}
	for(Counter=0;Counter < 10; Counter++) {
		OutWtFactor[4][Counter]=GetLInt(PackReceived[StartPos],PackReceived[StartPos+1],PackReceived[StartPos+2]);
		StartPos=StartPos+3;
	}
	return;
}

void ProcessByteTLUnit(void)
{
	if (CharIn[0] == CharOut[0]) {
		return;
	}
	CharRcvd = CharRTable[0][CharOut[0]++];
	if (CharOut[0] >= 100) {CharOut[0]=0;}

	if (CharRcvd == '#') {	// need to wait for CR for this command
		WaitForCR=1;RCharCount=0;
		return;
	}	
	if (WaitForCR) {
		PackRcvd[RCharCount++]=CharRcvd;
		if (RCharCount >=5) {WaitForCR=0;}
		if (CharRcvd==13) {
			WaitForCR=0;CharRcvd='#';	//set as axle weight query and process packet
		}
		else { return;}
	}
	RTUQuery = CharRcvd;
	ProcessTLUnit();

	
	
//	if ( CharRcvd == 13) {	
//		//if ( CharCount == BytesExpectd) {ADOk=1;return;}	
//		if (CharCount>0) {ADOk=1;return;}	// bytes expected not used 
//	}	
//	ADString[CharCount]=CharRcvd;
//	CharCount++;
//	if ( CharCount > 50) {CharCount=0;return;}
	return;
}

void ProcessTLUnit(void)
{
	if (RTUQuery=='?') {SendWeight();return;}
	if (RTUQuery=='x') {
		// 'ms=xxxxx' is received if 'x' is sent when weighing system is not in weigh line mode
		/*if (SysInWLMode) {
		}
		else {
		}*/
		ResetSteps();AckReset();return;
	}
	if (RTUQuery=='S') {ResetWS=1;return;}
	if (RTUQuery=='w') {WaitForWeight=1;SysInWLMode=1;WeightToUpdate=0;AxlesWeighed=0;AckSetWL();return;}
	if (RTUQuery=='z') {AcquireZero=1;return;}
	if (RTUQuery=='o') {AxlesWeighed=0;AckResetSl();return;}
	if (RTUQuery=='l') {SendAxlesWeighed();return;}	
	if (RTUQuery=='#') {FillChar='_';SendAxleWeight();return;}
	if (RTUQuery=='r') {SendAllAxleWeights();return;}
	return;
}

void SendWeight(void)
{
	BytesToSend[0]=0;
	if (ActualWt < 0) { 
	  	WtToConv=0-ActualWt; 
		PackToSend[0][BytesToSend[0]++]='-';
	}
	else {
	 	WtToConv=ActualWt; 
	}                       
	Digits=0;
	if (WtToConv != 0) {
		NetString[6] = (WtToConv % 10) | 0x030;Digits++;
		WtToConv = WtToConv/10;
		if (WtToConv >0) {
			NetString[5]= (WtToConv % 10) | 0x030;Digits++;
			WtToConv = WtToConv/10;
			if (WtToConv >0) {
				NetString[4]= (WtToConv % 10) | 0x030;Digits++;
				WtToConv = WtToConv/10;
				if (WtToConv >0) {
					NetString[3]= (WtToConv % 10) | 0x030;Digits++;
					WtToConv = WtToConv/10;
					if (WtToConv >0) {
						NetString[2]= (WtToConv % 10) | 0x030;Digits++;
						WtToConv = WtToConv/10;
						if (WtToConv >0) {
							NetString[1]= (WtToConv % 10) | 0x030;Digits++;
						}
					}
				}
			}
		}
	}
	if (Digits==0) {
		PackToSend[0][BytesToSend[0]++]='0' ;
		PackToSend[0][BytesToSend[0]++]='.' ;
		PackToSend[0][BytesToSend[0]++]='0' ;
		PackToSend[0][BytesToSend[0]++]='0' ;
		PackToSend[0][BytesToSend[0]++]='0' ;
		PackToSend[0][BytesToSend[0]++]='0' ;
		PackToSend[0][BytesToSend[0]++]='0' ;
		PackToSend[0][BytesToSend[0]++]='0' ;
		PackToSend[0][BytesToSend[0]++]='e' ;
		PackToSend[0][BytesToSend[0]++]='+' ;
		PackToSend[0][BytesToSend[0]++]='0' ;
		PackToSend[0][BytesToSend[0]++]='1' ;
	}
	else {
		RefPos = 6 - (Digits -1);ByteCntr=1;
		PackToSend[0][BytesToSend[0]++]=NetString[RefPos];
		PackToSend[0][BytesToSend[0]++]='.';
		if (Digits > 1) {
			for(ByteCntr=2;ByteCntr<=Digits;ByteCntr++){
				RefPos = 6 - (Digits - ByteCntr);
				PackToSend[0][BytesToSend[0]++]=NetString[RefPos];
			}
		}
		for(RefPos=ByteCntr;RefPos<=7;RefPos++){
			PackToSend[0][BytesToSend[0]++]='0';
		}	
		PackToSend[0][BytesToSend[0]++]='e' ;
		PackToSend[0][BytesToSend[0]++]='+' ;
		PackToSend[0][BytesToSend[0]++]='0' ;
		PackToSend[0][BytesToSend[0]++]=Digits|0x030 ;
		
	}	
	PackToSend[0][BytesToSend[0]++]=0x0d;
	StartXmit0(BytesToSend[0]);		// BytesToSend[0] will be again updated by BytesToSend[0] in startxmit0

	return;
}

void AckReset(void)
{
	BytesToSend[0]=0;
	PackToSend[0][BytesToSend[0]++]='x';
	PackToSend[0][BytesToSend[0]++]=0x0d;
	StartXmit0(BytesToSend[0]);		// BytesToSend[0] will be again updated by BytesToSend[0] in startxmit0
	return;
}

void ResetSteps(void)
{
	SysInWLMode=0;WaitForWeight=0;DisplayAxCount=0;
	return;
}

void AckResetWS(void)
{
	BytesToSend[0]=0;
	PackToSend[0][BytesToSend[0]++]='S';
	PackToSend[0][BytesToSend[0]++]=0x0d;
	StartXmit0(BytesToSend[0]);		// BytesToSend[0] will be again updated by BytesToSend[0] in startxmit0
	return;
}

void AckSetWL(void)
{
	BytesToSend[0]=0;
	PackToSend[0][BytesToSend[0]++]='w';
	PackToSend[0][BytesToSend[0]++]=0x0d;
	StartXmit0(BytesToSend[0]);		// BytesToSend[0] will be again updated by BytesToSend[0] in startxmit0
	return;
}

void AckZero(void)
{
	BytesToSend[0]=0;
	PackToSend[0][BytesToSend[0]++]='z';
	PackToSend[0][BytesToSend[0]++]=0x0d;
	StartXmit0(BytesToSend[0]);		// BytesToSend[0] will be again updated by BytesToSend[0] in startxmit0
	return;
}

void AckResetSl(void)
{
	BytesToSend[0]=0;
	PackToSend[0][BytesToSend[0]++]='o';
	PackToSend[0][BytesToSend[0]++]=0x0d;
	StartXmit0(BytesToSend[0]);		// BytesToSend[0] will be again updated by BytesToSend[0] in startxmit0
	return;

}

void SendAxlesWeighed(void)
{
	BytesToSend[0]=0;
	PackToSend[0][0]='L';BytesToSend[0]++;
	PackToSend[0][1]='=';BytesToSend[0]++;
	
	// serial number - 4 digits
	
	TempCounter=AxlesWeighed; 	
	PackToSend[0][5] = (TempCounter % 10) | 0x030;BytesToSend[0]++;
	
	TempCounter = TempCounter/10;
	PackToSend[0][4] = (TempCounter % 10) | 0x030;BytesToSend[0]++;
	
	TempCounter = TempCounter/10;
	PackToSend[0][3] = (TempCounter % 10) | 0x030;BytesToSend[0]++;
	
	TempCounter = TempCounter/10;
	PackToSend[0][2] = (TempCounter % 10) | 0x030;BytesToSend[0]++;
	
	PackToSend[0][BytesToSend[0]++]=0x0d;
	StartXmit0(BytesToSend[0]);		// BytesToSend[0] will be again updated by BytesToSend[0] in startxmit0

}

void SendAxleWeight(void) 
{
	ReqAxleCount=0;
	if (RCharCount <=1) { return;}

	for (Counter=0;Counter<RCharCount;Counter++) {
		CharRcvd = PackRcvd[Counter];
		if (CharRcvd==13) { break;}
		ReqAxleCount = ReqAxleCount * 10;		
		ReqAxleCount += CharRcvd & 0x0f;
	}

	TransmitAxleWeight();

	return;
}

void TransmitAxleWeight(void)
{
	BytesToSend[0]=0;
	PackToSend[0][BytesToSend[0]++]='#';
	
	Counter1 = ReqAxleCount;
	Digit_U = Counter1 % 10;
	Counter1 = Counter1 / 10;Digit_T = Counter1 % 10;
	Counter1 = Counter1 / 10;Digit_H = Counter1 % 10;
	Counter1 = Counter1 / 10;Digit_Th = Counter1 % 10;
	
	LeadZero=1;
	if (Digit_Th == 0) {PackToSend[0][BytesToSend[0]++] = FillChar;}
	else {PackToSend[0][BytesToSend[0]++] = Digit_Th + 0x30;LeadZero=0;}
	if ((Digit_H == 0) && LeadZero) {PackToSend[0][BytesToSend[0]++] = FillChar;}
	else {PackToSend[0][BytesToSend[0]++] = Digit_H + 0x30;LeadZero=0;}
	if ((Digit_T == 0)&& LeadZero) {PackToSend[0][BytesToSend[0]++] = FillChar;}
	else {PackToSend[0][BytesToSend[0]++] = Digit_T + 0x30;LeadZero=0;}
	PackToSend[0][BytesToSend[0]++] = Digit_U + 0x30;	
	
	for (Counter=0;Counter<7;Counter++) {
		PackToSend[0][BytesToSend[0]++] = FillChar;
	}

	if (ReqAxleCount <= AxlesWeighed) {

		Counter1 = AxleWeight[ReqAxleCount-1];
		Digit_U = Counter1 % 10;
		Counter1 = Counter1 / 10;Digit_T = Counter1 % 10;
		Counter1 = Counter1 / 10;Digit_H = Counter1 % 10;
		Counter1 = Counter1 / 10;Digit_Th = Counter1 % 10;
		Counter1 = Counter1 / 10;Digit_TTh = Counter1 % 10;

		LeadZero=1;
		if (Digit_TTh == 0) {PackToSend[0][BytesToSend[0]++] = FillChar;}
		else {PackToSend[0][BytesToSend[0]++] = Digit_TTh + 0x30;LeadZero=0;}
		if ((Digit_Th == 0) && LeadZero) {PackToSend[0][BytesToSend[0]++] = FillChar;}
		else {PackToSend[0][BytesToSend[0]++] = Digit_Th + 0x30;LeadZero=0;}
		if ((Digit_H == 0)&& LeadZero) {PackToSend[0][BytesToSend[0]++] = FillChar;}
		else {PackToSend[0][BytesToSend[0]++] = Digit_H + 0x30;LeadZero=0;}
		if ((Digit_T == 0)&& LeadZero) {PackToSend[0][BytesToSend[0]++] = FillChar;}
		else {PackToSend[0][BytesToSend[0]++] = Digit_T + 0x30;LeadZero=0;}
		PackToSend[0][BytesToSend[0]++] = Digit_U + 0x30;
		PackToSend[0][BytesToSend[0]++] = '0';	// add one zero. will be deleted by RTU
	}
	else {
		// send -1 if enquired axle count is not in range
		for (Counter=0;Counter<4;Counter++) {
			PackToSend[0][BytesToSend[0]++] = FillChar;
		}
		PackToSend[0][BytesToSend[0]++] = '-';
		PackToSend[0][BytesToSend[0]++] = '1';
	}

	for (Counter=0;Counter<4;Counter++) {
		PackToSend[0][BytesToSend[0]++] = FillChar;
	}

	Counter1 = AxleSpeed[ReqAxleCount-1];		
	Digit_U = Counter1 % 10;
	Counter1 = Counter1 / 10;Digit_T = Counter1 % 10;
	Counter1 = Counter1 / 10;Digit_H = Counter1 % 10;
	LeadZero=1;
	if (Digit_H == 0) {PackToSend[0][BytesToSend[0]++] = FillChar;}
	else {PackToSend[0][BytesToSend[0]++] = Digit_H + 0x30;LeadZero=0;}
	if ((Digit_T == 0)&& LeadZero) {PackToSend[0][BytesToSend[0]++] = FillChar;}
	else {PackToSend[0][BytesToSend[0]++] = Digit_T + 0x30;LeadZero=0;}
	PackToSend[0][BytesToSend[0]++] = Digit_U + 0x30;

	// reset of the pack provided by wim is avoided as it is not used. for safty purposed '_' are sent
	for (Counter=0;Counter<7;Counter++) {
		PackToSend[0][BytesToSend[0]++] = FillChar;
	}

	PackToSend[0][BytesToSend[0]++]=0x0d;
	StartXmit0(BytesToSend[0]);		// BytesToSend[0] will be again updated by BytesToSend[0] in startxmit0
	return;
}

void SendAllAxleWeights(void)
{
	FillChar=' ';
	if (AxlesWeighed==0) {	// if no axles are weighed, send serial number 1 with -1 as weight
		ReqAxleCount=1;
		TransmitAxleWeight();
		return;
	}
	OneByOneSet=1;
	ReqAxleCount=1;
	TransmitAxleWeight();
	return;
}

void SendNextAxle(void)
{
	if (BytesToSend[0]!=0) { return;}
	ReqAxleCount++;
	if (ReqAxleCount>AxlesWeighed) {OneByOneSet=0;return;}
	TransmitAxleWeight();
}

