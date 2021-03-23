
#include "Common.h"
#include "sfr65.h" 
#include "I2C.h"

unsigned long MSTimer1;
void IsrTimer1(void)
{
	if(MSTimer1>0){MSTimer1--;}
}
void delay_ms(unsigned int ms_count)
{
	MSTimer1=ms_count;
	while(MSTimer1!=0)
	{
		IsrTimer1();
		continue;
	}
}


void I2C_Init(void)
{
	DIR_SDA=1;
	DIR_SCLK_OP;
}
void I2C_Start(void)
{
	DIR_SCLK_OP;
	DIR_SDA=1;
	SDA_HI;
	delay_ms(MSDELAY);
	SCL_HI;
	delay_ms(MSDELAY);
	SDA_LO;
	delay_ms(MSDELAY/2);
	SCL_LO;
	delay_ms(MSDELAY/2);
	//return;
}

void I2C_Stop(void)
{
	DIR_SCLK_OP;
	DIR_SDA=1;
	SDA_LO;
	SDA_LO;
	SDA_LO;
	delay_ms(MSDELAY);
	SCL_HI;
	SCL_HI;
	delay_ms(MSDELAY);
	SDA_HI;
	SDA_HI;
	delay_ms(MSDELAY);
	
	//return ;
}

void I2C_Clock(void)
{
	delay_ms(MSDELAY);
	SCL_HI;
	delay_ms(MSDELAY);
	SCL_LO;
	delay_ms(MSDELAY);
	//return;
}

void I2C_Write(unsigned char datt)
{

	unsigned char iXi;
	DIR_SCLK_OP;
	DIR_SDA=1;
	
	for(iXi=0;iXi<8;iXi++)
	{
		
		if(datt&0x80)
		{
			SDA1=1;
		}
		else
		{
			SDA1=0;
		}
		delay_ms(MSDELAY/2);
		SCL_HI;
		delay_ms(MSDELAY);
		SCL_LO;
		delay_ms(MSDELAY/2);
		datt<<=1;
	}
	
	
	return ;
}
unsigned char I2C_Read(void)
{
	unsigned char iXX,datt=0x00;
	DIR_SCLK_OP;
	DIR_SDA=0;
	for(iXX=0;iXX<=7;iXX++)
	{
		datt<<=1;
		datt=(datt|SDA);
		delay_ms(MSDELAY/2);
		SCL_HI;
		delay_ms(MSDELAY);
		SCL_LO;
		delay_ms(MSDELAY/2);
	}
	return datt;
}
void I2C_ACK(void)
{
	unsigned char dat;
	
	
	if(DIR_SDA==0)
	{
	dat=SDA;
	delay_ms(MSDELAY/2);
	SCL_HI;
	delay_ms(MSDELAY);
	SCL_LO;
	delay_ms(MSDELAY/2);
	}
	else if(DIR_SDA==1)
	{
		SDA=0;
		delay(10000);
		SCL_HI;
		delay_ms(MSDELAY);
		SCL_LO;
		delay_ms(MSDELAY);
		
	}
	return;

}

void I2C_NACK(void)
{
	DIR_SDA=1;

	SDA=1;
	delay_ms(MSDELAY/2);
	SCL_HI;
	delay_ms(MSDELAY);
	SCL_LO;
	delay_ms(MSDELAY/2);
	return;
	
}

