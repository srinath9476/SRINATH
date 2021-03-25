/*

#include "Common.h"
#include "sfr65.h"

#include "RTC.h"
#include "I2C.h"
unsigned char RTC_ARR[9];
//unsigned char RTC_ARR[60];
#define RTC_ID 				0xD0
//#define RTC_ID 				0x68

#define SECONDS 			RTC_ARR[0]
#define MINUTES				RTC_ARR[1]
#define HOURS				RTC_ARR[2]
#define DAY					RTC_ARR[3]
#define DATE				RTC_ARR[4]
#define MONTH				RTC_ARR[5]
#define YEAR				RTC_ARR[6]
#define PREV_SECONDS		RTC_ARR[7]
//#define HOURS				RTC_ARR[8]

#define EEPM_ID_WRITE			0xA0
#define EEPM_ID_READ			0XA1

 unsigned char TimeString1[9];
 unsigned char DateString1[11];
//extern unsigned char TimeString1[9];
//extern unsigned char DateString1[11];

void ReadRTC()
{
	I2C_Init();
	I2C_Start();               	// Start i2c communication
   	I2C_Write(RTC_ID);	  	  	// connect to DS1307(write) by sending its ID on I2c Bus
	DIR_SDA=0;
	I2C_ACK();
   	I2C_Write(0); 	
	I2C_ACK();
	
	I2C_Start();
	I2C_Write(RTC_ID|0x01);
	DIR_SDA=0;
	I2C_ACK();
	DIR_SDA=1;
	NoOfBytes=7;
	//NoOfBytes=60;
	Counter1=0;
	while(NoOfBytes!=0)
	{
		RTC_ARR[Counter1++]=I2C_Read();
		
		NoOfBytes--;
		if(NoOfBytes>0){DIR_SDA=1;I2C_ACK();}
		
	}
	I2C_NACK();

	I2C_Stop();
	return ;
	
}

    
void WriteRTC()
{
	
	I2C_Init();
	I2C_Start();
	I2C_Write(RTC_ID);	//RTC address
	//DIR_SDA_IP;
	DIR_SDA=0;
	
	I2C_ACK();
	I2C_Write(0);       // starting word address
	
	
	DIR_SDA=0;
	I2C_ACK();
	NoOfBytes=7;
	//NoOfBytes=8;
	Counter1=0;
	while(NoOfBytes!=0)
	//while(NoOfBytes>0)
	{
		I2C_Write(RTC_ARR[Counter1++]);
		NoOfBytes--;
		if(NoOfBytes>0){DIR_SDA=0;I2C_ACK();}
	}
	I2C_Stop();
	
	
	
	//delay_ms(10);
	return;
	
	
}

void ReadDateNTime()
{
	char datec;
	ReadRTC();
	TimeString1[7]=(SECONDS&0x0f)|0x30;
	TimeString1[6]=((SECONDS&0xf0)>>4)|0x30;
	TimeString1[5]=':';
	
	TimeString1[4]=(MINUTES&0x0f)|0x30;
	TimeString1[3]=((MINUTES&0xf0)>>4)|0x30;
	TimeString1[2]=':';
	
	TimeString1[1]=(HOURS&0x0f)|0x30;
	TimeString1[0]=((HOURS&0xf0)>>4)|0x30;
	for(datec=0;datec<8;datec++)
	{
		u1tbl=	TimeString1[datec];
		delay(10000);
	}
	u1tbl='\t';
	delay(10000);
	u1tbl='\t';
	delay(10000);
	
	DateString1[1]=(DATE&0x0f)|0x30;
	DateString1[0]=((DATE&0xf0)>>4)|0x30;
	
	DateString1[2]='-';
	
	DateString1[4]=(MONTH&0x0f)|0x30;
	DateString1[3]=((MONTH&0xf0)>>4)|0x30;
	
	DateString1[5]='-';
	DateString1[6]='2';
	DateString1[7]='0';
	
	DateString1[9]=(YEAR&0x0f)|0x30;
	DateString1[8]=((YEAR&0xf0)>>4)|0x30;
	
	for(datec=0;datec<10;datec++)
	{
		u1tbl=	DateString1[datec];
		delay(10000);
	}
	
	
	u1tbl='\n';
	delay(10000);
	return;
}

void WriteDateNTime()
{
	unsigned char aT[]={'0','4','2','6','1','1','0','3','1','1','0','3','2','1'};
	int datec;

	RTC_ARR[0]=(((aT[0]&0x0f)<<4)+(aT[1]&0x0f));//seconds updation
	RTC_ARR[1]=(((aT[2]&0x0f)<<4)+(aT[3]&0x0f));// Minutes
	//RTC_ARR[2]=((((aT[4]&0x0f)<<4)+(aT[5]&0x0f))|0x60); //Hours
	RTC_ARR[2]=((((aT[4]&0x0f)<<4)+(aT[5]&0x0f))); //Hours
	RTC_ARR[3]=(((aT[6]&0x0f)<<4)+(aT[7]&0x0f));//Day
	RTC_ARR[4]=(((aT[8]&0x0f)<<4)+(aT[9]&0x0f));//Date
	RTC_ARR[5]=(((aT[10]&0x0f)<<4)+(aT[11]&0x0f));//Month
	RTC_ARR[6]=(((aT[12]&0x0f)<<4)+(aT[13]&0x0f));//Year
	RTC_ARR[7]=0x03;
	
		for(datec=0;datec<=7;datec++)
	{
		u1tbl=	RTC_ARR[datec]+0x23;
		
		delay(10000);
		u1tbl='\t';
		
	}
	WriteRTC();
	u1tbl='\n';
	return;
}
*/
#include "Common.h"
#include "sfr65.h"

#include "RTC.h"
#include "I2C.h"
unsigned char RTC_ARR[9];
//unsigned char RTC_ARR[60];
#define RTC_ID 				0xD0
//#define RTC_ID 				0x68

#define SECONDS 			RTC_ARR[0]
#define MINUTES				RTC_ARR[1]
#define HOURS				RTC_ARR[2]
#define DAY					RTC_ARR[3]
#define DATE				RTC_ARR[4]
#define MONTH				RTC_ARR[5]
#define YEAR				RTC_ARR[6]
#define PREV_SECONDS		RTC_ARR[7]
//#define HOURS				RTC_ARR[8]



 unsigned char TimeString1[9];
 unsigned char DateString1[11];
//extern unsigned char TimeString1[9];
//extern unsigned char DateString1[11];

void ReadRTC()
{
	//I2C_Init();
	I2C_Start();               	// Start i2c communication
	
   	I2C_Write(RTC_ID);	  	  	// connect to DS1307(write) by sending its ID on I2c Bus
	//DIR_SDA=0;
	DIR_SDA=1;
	
	I2C_ACK();
   	//I2C_Write(0); 	
	I2C_Write(0); 	
	I2C_ACK();
	
	I2C_Stop();
	I2C_Start();
	
	I2C_Write(RTC_ID|0x01);
	
	//DIR_SDA=0;
	DIR_SDA=1;
	I2C_ACK();
	
	DIR_SDA=1;
	NoOfBytes=7;
	//NoOfBytes=60;
	Counter1=0;
	while(NoOfBytes!=0)
	{
		RTC_ARR[Counter1++]=I2C_Read();
		
		NoOfBytes--;
		if(NoOfBytes>0){DIR_SDA=1;I2C_ACK();}
		
	}
	I2C_NACK();

	I2C_Stop();
	return ;
	
}

/**Write RTC**/
void WriteRTC()
{
	
	
	I2C_Init();
	
	I2C_Start();
	I2C_Write(RTC_ID);	//RTC address
	//I2C_Write(0xa0);
	//I2C_Clock();
	DIR_SDA=1;
	
	I2C_ACK();
	
	//I2C_Write(0x07);
	I2C_Write(0x09);
	DIR_SDA=1;
	
	I2C_ACK();
	//I2C_Clock();
	//I2C_Write(0x00);
		I2C_Write(0x00);
	DIR_SDA=1;
	
	I2C_ACK();
	//I2C_Clock();
	I2C_Stop();
	
	I2C_Start();
	I2C_Write(RTC_ID);	//RTC address
	//DIR_SDA_IP;
	
	//DIR_SDA=0;
	DIR_SDA=1;
	
	I2C_ACK();
	I2C_Write(0x00);       // starting word address
	

	//DIR_SDA=0;
	DIR_SDA=1;
	I2C_ACK();
	//NoOfBytes=7;
	NoOfBytes=8;
	Counter1=0;
	while(NoOfBytes!=0)
	//while(NoOfBytes>0)
	{
		I2C_Write(RTC_ARR[Counter1++]);
		NoOfBytes--;
		if(NoOfBytes>1){DIR_SDA=0;DIR_SDA=1;I2C_ACK();}
	}
	//I2C_NACK();
	I2C_Stop();
	
	
	/*To Ch Enable*/
	/*
	I2C_Start();
	I2C_Write(RTC_ID);	//RTC address
	//DIR_SDA_IP;
	DIR_SDA=0;
	
	I2C_ACK();
	I2C_Write(0);       // starting word address
	
	DIR_SDA=0;
	I2C_ACK();
	I2C_Write(RTC_ARR[0]&0b01111111);
	DIR_SDA=0;
	I2C_ACK();
	I2C_Stop();
	*/
	//delay_ms(10);
	//I2C_Init();
	
	I2C_Start();
	I2C_Write(RTC_ID);	//RTC address
	//I2C_Clock();
	DIR_SDA=1;
	
	I2C_ACK();
	
	I2C_Write(0x09);
	DIR_SDA=1;
	
	I2C_ACK();
	//I2C_Clock();
	I2C_Write(0x93);
	DIR_SDA=1;
	
	I2C_ACK();
	//I2C_Clock();
	I2C_Stop();
	return;
	
	
}

void ReadDateNTime()
{
	char datec;
	ReadRTC();
	TimeString1[7]=(SECONDS&0x0f)|0x30;
	TimeString1[6]=((SECONDS&0xf0)>>4)|0x30;
	TimeString1[5]=':';
	
	TimeString1[4]=(MINUTES&0x0f)|0x30;
	TimeString1[3]=((MINUTES&0xf0)>>4)|0x30;
	TimeString1[2]=':';
	
	TimeString1[1]=(HOURS&0x0f)|0x30;
	TimeString1[0]=((HOURS&0xf0)>>4)|0x30;
	for(datec=0;datec<8;datec++)
	{
		u1tbl=	TimeString1[datec];
		delay(10000);
	}
	u1tbl='\t';
	delay(10000);
	u1tbl='\t';
	delay(10000);
	
	DateString1[1]=(DATE&0x0f)|0x30;
	DateString1[0]=((DATE&0xf0)>>4)|0x30;
	
	DateString1[2]='-';
	
	DateString1[4]=(MONTH&0x0f)|0x30;
	DateString1[3]=((MONTH&0xf0)>>4)|0x30;
	
	DateString1[5]='-';
	DateString1[6]='2';
	DateString1[7]='0';
	
	DateString1[9]=(YEAR&0x0f)|0x30;
	DateString1[8]=((YEAR&0xf0)>>4)|0x30;
	
	for(datec=0;datec<10;datec++)
	{
		u1tbl=	DateString1[datec];
		delay(10000);
	}
	/*
	u1tbl='\n';
	
		for(datec=10;datec<60;datec++)
	{
		u1tbl=	RTC_ARR[datec];
		delay(10000);
		u1tbl='\t';
	}
	*/
	
	u1tbl='\n';
	delay(10000);
	return;
}

void WriteDateNTime()
{
	unsigned char aT[]={'0','0','2','4','1','8','0','5','2','4','0','3','2','1'};
	int datec;
	/*
	RTC_ARR[0]=(((TimeString1[7]&0x0f)<<4)+(TimeString1[6]&0x0f))//seconds updation
	RTC_ARR[1]=(((TimeString1[4]&0x0f)<<4)+(TimeString1[4]&0x0f))// Minutes
	RTC_ARR[2]=((((TimeString1[3]&0x0f)<<4)+(TimeString1[2]&0x0f))+0x40); //Hours
	RTC_ARR[3]=(((TimeString1[1]&0x0f)<<4)+(TimeString1[0]&0x0f));
	RTC_ARR[4]=(((TimeString1[5]&0x0f)<<4)+(TimeString1[4]&0x0f));
	RTC_ARR[5]=(((TimeString1[5]&0x0f)<<4)+(TimeString1[4]&0x0f));
	*/
	//RTC_ARR[0]=(((aT[0]&0x0f)<<4)+(aT[1]&0x0f));//seconds updation
	RTC_ARR[0]=0x00;//seconds updation
	RTC_ARR[1]=(((aT[2]&0x0f)<<4)+(aT[3]&0x0f));// Minutes
	//RTC_ARR[2]=((((aT[4]&0x0f)<<4)+(aT[5]&0x0f))|0x60); //Hours
	RTC_ARR[2]=((((aT[4]&0x0f)<<4)+(aT[5]&0x0f))); //Hours
	RTC_ARR[3]=(((aT[6]&0x0f)<<4)+(aT[7]&0x0f));//Day
	RTC_ARR[4]=(((aT[8]&0x0f)<<4)+(aT[9]&0x0f));//Date
	RTC_ARR[5]=(((aT[10]&0x0f)<<4)+(aT[11]&0x0f));//Month
	RTC_ARR[6]=(((aT[12]&0x0f)<<4)+(aT[13]&0x0f));//Year
	RTC_ARR[7]=0x03;
	
		for(datec=0;datec<=7;datec++)
	{
		u1tbl=	RTC_ARR[datec]+0x23;
		
		delay(10000);
		u1tbl='\t';
		
	}
	WriteRTC();
	u1tbl='\n';
	return;
}