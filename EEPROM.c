#include "Common.h"
#include "sfr65.h"

#include "RTC.h"
#include "I2C.h"
#include "EEPROM.h"
unsigned char EEP_ARR[9];
//unsigned char RTC_ARR[60];
#define EEP_ID 				0xA0
//#define RTC_ID 				0x68

#define ESECONDS 			EEP_ARR[0]
#define EMINUTES			EEP_ARR[1]
#define EHOURS				EEP_ARR[2]
#define EDAY				EEP_ARR[3]
#define EDATE				EEP_ARR[4]
#define EMONTH				EEP_ARR[5]
#define EYEAR				EEP_ARR[6]
#define EPREV_SECONDS		EEP_ARR[7]
//#define HOURS				RTC_ARR[8]

int DisplayChecks[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf, 0xbf,0x7f,0xc0,0xf9,0xa4,0xb0,0x99, 0x92, 0x82, 0xf8, 0x80, 0x90,0xff}; //18 numbers
int DisplayNumbers[]={0xc0,0xf9,0xa4,0xb0,0x99, 0x92, 0x82, 0xf8, 0x80, 0x90,0xBF};//to display "0,1,2,3,4,5,6,7,8,9,-" in Segment
int DisplaySelects[]={0x38,0x30,0x28,0x20,0x18,0x10,0x08,0x00}; // To Select individul Segments [0] is '1's location
																							// [7] is '10M'`s location 


 unsigned char ETimeString1[9];
 unsigned char EDateString1[11];
//extern unsigned char TimeString1[9];
//extern unsigned char DateString1[11];

void EEPRead()
{
	//I2C_Init();
	I2C_Start();               	// Start i2c communication
	
	
   	I2C_Write(EEP_ID);	  	  	// connect to DS1307(write) by sending its ID on I2c Bus
	//DIR_SDA=0;
	//DIR_SDA=1;
	DIR_SDA=0;
	I2C_ACK();
	SCL_LO;
	delay_ms(MSDELAY);
   	//I2C_Write(0); 	
	I2C_Write(0); 
	DIR_SDA=0;	
	I2C_ACK();
	
	I2C_Write(0); 
	DIR_SDA=0;	
	I2C_ACK();
	SCL_LO;
	delay_ms(MSDELAY);
	SCL_HI;
	DIR_SDA=1;	
	SDA=1;
	//I2C_Stop();
	I2C_Start();
	
	
	I2C_Write(0xA1);
	
	//DIR_SDA=0;
	DIR_SDA=0;
	I2C_ACK();
	//SDA=0;
	//delay(5000);
	//SCL_LO;
	//delay_ms(MSDELAY);
	
	//SDA=0;
	//delay(5000);
	//DIR_SDA=0;
	//NoOfBytes=7;
	NoOfBytes=7;
	//NoOfBytes=60;
	Counter1=0;
	while(NoOfBytes!=0)
	{
		EEP_ARR[Counter1++]=I2C_Read();
		
		NoOfBytes--;
		if(NoOfBytes>0){DIR_SDA=1;I2C_ACK();SCL_LO;
	delay_ms(MSDELAY);}
		
	}
	I2C_NACK();

	I2C_Stop();
	return ;
	
}

/**Write RTC**/
void EEPWrite()
{
	I2C_Init();
	
	I2C_Start();
	I2C_Write(EEP_ID);	//RTC address
	//DIR_SDA_IP;
	DIR_SDA=0;
	//DIR_SDA=1;
	I2C_ACK();
	SCL_LO;
	delay_ms(MSDELAY);
	
	I2C_Write(0x00);       // starting word address
	
	DIR_SDA=0;
	//DIR_SDA=1;
	I2C_ACK();
	SCL_LO;
	delay_ms(MSDELAY);
	
	I2C_Write(0x00);  
	
	DIR_SDA=0;
	//DIR_SDA=1;
	I2C_ACK();
	SCL_LO;
	delay_ms(MSDELAY);
	
	NoOfBytes=7;
	//NoOfBytes=8;
	Counter1=0;
	while(NoOfBytes!=0)
	//while(NoOfBytes>0)
	{
		I2C_Write(EEP_ARR[Counter1++]);
		NoOfBytes--;
		//if(NoOfBytes>0)
		{
			//DIR_SDA=1;
			DIR_SDA=0;I2C_ACK();
			SCL_LO;
			delay_ms(MSDELAY);
		}
	}
	//I2C_NACK();
	I2C_Stop();
	

	return;
	
	
}

void EReadDateNTime()
{
	char datec;
	int count;
	char Disp[15];
	EEPRead();
	ETimeString1[7]=(ESECONDS&0x0f)|0x30; 
	ETimeString1[6]=((ESECONDS&0xf0)>>4)|0x30;
	
	Disp[0]=(ESECONDS&0x0f);
	Disp[1]=((ESECONDS&0xf0)>>4);
	
	ETimeString1[5]=':';
	
	ETimeString1[4]=(EMINUTES&0x0f)|0x30;
	ETimeString1[3]=((EMINUTES&0xf0)>>4)|0x30;
	
	Disp[2]=(EMINUTES&0x0f);
	Disp[3]=((EMINUTES&0xf0)>>4);
	
	ETimeString1[2]=':';
	
	ETimeString1[1]=(EHOURS&0x0f)|0x30;
	ETimeString1[0]=((EHOURS&0xf0)>>4)|0x30;
	
	Disp[4]=(EHOURS&0x0f);
	Disp[5]=((EHOURS&0xf0)>>4);
	
	for(datec=0;datec<8;datec++)
	{
		u1tbl=	ETimeString1[datec];
		delay(10000);
	}
	for(count=0;count<=1000;count++)
	{
		for(datec=0;datec<6;datec++)
		{
		  	KEYDecoder=DisplaySelects[datec];
			ModuleAddress=DisplayNumbers[Disp[datec]];
			//ModuleAddress=DisplayNumber[DJ];
			delay(100);
		}	
	}
	u1tbl='\t';
	delay(10000);
	u1tbl='\t';
	delay(10000);
	
	EDateString1[1]=(EDATE&0x0f)|0x30;
	EDateString1[0]=((EDATE&0xf0)>>4)|0x30;
	
	Disp[1]=(EDATE&0x0f);
	Disp[0]=((EDATE&0xf0)>>4);
	
	EDateString1[2]='-';
	
	EDateString1[4]=(EMONTH&0x0f)|0x30;
	EDateString1[3]=((EMONTH&0xf0)>>4)|0x30;
	
	Disp[3]=(EMONTH&0x0f);
	Disp[2]=((EMONTH&0xf0)>>4);
	
	EDateString1[5]='-';
	EDateString1[6]='2';
	EDateString1[7]='0';
	
	EDateString1[9]=(EYEAR&0x0f)|0x30;
	EDateString1[8]=((EYEAR&0xf0)>>4)|0x30;
	
	Disp[5]=(EYEAR&0x0f);
	Disp[4]=((EYEAR&0xf0)>>4);
	
	for(datec=0;datec<10;datec++)
	{
		u1tbl=	EDateString1[datec];
		delay(10000);
	}
	
	for(count=0;count<=3000;count++)
	{
		for(datec=0;datec<6;datec++)
		{
		  	KEYDecoder=DisplaySelects[datec];
			ModuleAddress=DisplayNumbers[Disp[5-datec]];
			//ModuleAddress=DisplayNumber[DJ];
			delay(100);
		}	
	}
	u1tbl='\n';
	delay(10000);
	return;
}

void EWriteDateNTime()
{
	unsigned char aT[15];//={'0','0','0','2','1','9','0','6','1','2','0','3','2','1'};
	/*
	RTC_ARR[0]=(((TimeString1[7]&0x0f)<<4)+(TimeString1[6]&0x0f))//seconds updation
	RTC_ARR[1]=(((TimeString1[4]&0x0f)<<4)+(TimeString1[4]&0x0f))// Minutes
	RTC_ARR[2]=((((TimeString1[3]&0x0f)<<4)+(TimeString1[2]&0x0f))+0x40); //Hours
	RTC_ARR[3]=(((TimeString1[1]&0x0f)<<4)+(TimeString1[0]&0x0f));
	RTC_ARR[4]=(((TimeString1[5]&0x0f)<<4)+(TimeString1[4]&0x0f));
	RTC_ARR[5]=(((TimeString1[5]&0x0f)<<4)+(TimeString1[4]&0x0f));
	*/
	
	//RTC_ARR[0]=(((aT[0]&0x0f)<<4)+(aT[1]&0x0f));//seconds updation
	/*
	EEP_ARR[0]=0x00;//seconds updation
	EEP_ARR[1]=(((aT[2]&0x0f)<<4)+(aT[3]&0x0f));// Minutes
	//RTC_ARR[2]=((((aT[4]&0x0f)<<4)+(aT[5]&0x0f))|0x60); //Hours
	EEP_ARR[2]=((((aT[4]&0x0f)<<4)+(aT[5]&0x0f))); //Hours
	EEP_ARR[3]=(((aT[6]&0x0f)<<4)+(aT[7]&0x0f));//Day
	EEP_ARR[4]=(((aT[8]&0x0f)<<4)+(aT[9]&0x0f));//Date
	EEP_ARR[5]=(((aT[10]&0x0f)<<4)+(aT[11]&0x0f));//Month
	EEP_ARR[6]=(((aT[12]&0x0f)<<4)+(aT[13]&0x0f));//Year
	*/

	EEP_ARR[0]=RTC_ARR[0];//seconds updation
	EEP_ARR[1]=RTC_ARR[1];// Minutes
	EEP_ARR[2]=RTC_ARR[2]; //Hours
	EEP_ARR[3]=RTC_ARR[3];//Day
	EEP_ARR[4]=RTC_ARR[4];//Date
	EEP_ARR[5]=RTC_ARR[5];//Month
	EEP_ARR[6]=RTC_ARR[6];//Year
	EEP_ARR[7]=0x03;
	EEPWrite();
	return;
}