#include<stdio.h>
#include<stdlib.h>
#include "LCD.h"
#include "Common.h"
#include "sfr65.h"

unsigned char  DataLines;
int DlY;

/*
	These are the Pins used for LCD operation @present
	
	KEY1		--			R/w      always		0		
	KEY2		--			Sig		 always     0  to power back light on 
	
	p10_0		--			EN			
	p10_1		--			RS			
	KEY3		--			D4			
	KEY4		--			D5			
	p10_2		--			D6
	p10_3		--			D7
	
	need to alterate these pins  based on Design 
*/

char LCD_DispStrings[4][21]={{"      SRINATH V     "},				
							 {" EMBDEDDED SOFTWARE "},
							 {" ENGINEER, B.E.,M.E."},
							 {"Research&Development"}};
							 
	
	

void DELAY_Time(int CI)
{
	for(DlY=0;DlY<=CI*10000;DlY++);
}

void LCD_Main(void)
{
	pd5_1=1;
	pd5_2=1;
	pd5_3=1;
	pd5_4=1;
	pd10=0xFF;				//Port1 and 2nd making it Output		
	LCD_Transfer(0x00);		//port1  making Zero
	
	//port2  making Zero
	KEY1=0;   
	KEY2=0;
	p10_0=0;   //EN
	p10_1=0;   //RS
	
	// POWER On LCD and LCD to Write the data
	//KEY1=0;  
	//KEY2=1;
	
	LCD_Write_Command(0x02);
	LCD_Write_Command(0x28);
	LCD_Write_Command(0x0C);
	LCD_Write_Command(0x01);
	LCD_Write_Command(0x06);
	
	/*LCD_Write_Command(0x80);
	LCD_Send_String("      SRINATH V     ",20);
	LCD_Write_Command(0xC0);
	LCD_Send_String(" EMBDEDDED SOFTWARE ",20);
	LCD_Write_Command(0x94);
	LCD_Send_String(" ENGINEER, B.E.,M.E.",20);
	LCD_Write_Command(0xD4);
	LCD_Send_String("Research&Development",20);
	*/
	LCD_Write_Command(0x80);
	
	LCD_Send_String(&LCD_DispStrings[0][0],20);
	LCD_Write_Command(0xC0);
	LCD_Send_String(&LCD_DispStrings[1][0],20);
	LCD_Write_Command(0x94);
	LCD_Send_String(&LCD_DispStrings[2][0],20);
	LCD_Write_Command(0xD4);
	LCD_Send_String(&LCD_DispStrings[3][0],20);
}
void LCD_Write_Command(unsigned char Value)
{
	/*
	KEY4=0;						// RS=0
	
	DataLines&=0x00;
	LCD_Transfer(DataLines);
	DataLines|=(Value&0xF0);
	LCD_Transfer(DataLines);
	KEY3=1;						// EN=1
	DELAY_Time(1);
	KEY3=0;
	
	DataLines&=0x00;
	LCD_Transfer(DataLines);
	DataLines|=((Value<<4)&0xF0);
	LCD_Transfer(DataLines);
	KEY3=1;						// EN=1
	DELAY_Time(1);
	KEY3=0;
	*/
	p10_1=0;						// RS=0
	
	DataLines&=0x00;
	LCD_Transfer(&DataLines);
	DataLines|=((Value>>4)&0x0F);
	LCD_Transfer(&DataLines);
	p10_0=1;						// EN=1
	DELAY_Time(1);
	p10_0=0;
	
	DataLines&=0x00;
	LCD_Transfer(&DataLines);
	DataLines|=((Value)&0x0F);
	LCD_Transfer(&DataLines);
	p10_0=1;						// EN=1
	DELAY_Time(1);
	p10_0=0;
							
}
void LCD_Send_String(unsigned char *s, int SLEN)
{
	while(SLEN>0)
	{
		LCD_Write_data(*s++);
		SLEN--;
	}
}
void LCD_Write_data(unsigned char Value)
{
	p10_1=1;   //RS=1
	/*
	DataLines&=0x00;
	LCD_Transfer(DataLines);
	//DataLines|=(Value&0xF0);
		DataLines|=(Value&0xF0);
	LCD_Transfer(DataLines);
	KEY3=1;						// EN=1
	DELAY_Time(1);
	KEY3=0;
	
	DataLines&=0x00;
	LCD_Transfer(DataLines);
	DataLines|=((Value<<4)&0xF0);
	LCD_Transfer(DataLines);
	KEY3=1;						// EN=1
	DELAY_Time(1);
	KEY3=0;
	*/
		DataLines&=0x00;
	LCD_Transfer(&DataLines);
	DataLines|=((Value>>4)&0x0F);
	LCD_Transfer(&DataLines);
	p10_0=1;						// EN=1
	DELAY_Time(1);
	p10_0=0;
	
	DataLines&=0x00;
	LCD_Transfer(&DataLines);
	DataLines|=((Value)&0x0F);
	LCD_Transfer(&DataLines);
	p10_0=1;						// EN=1
	DELAY_Time(1);
	p10_0=0;
	
	
}
void LCD_Transfer(unsigned char *ptr)
{
	KEY3=(((*ptr)&1)>>0);
	KEY4=(((*ptr)&2)>>1);
	p10_2=(((*ptr)&4)>>2);
	p10_3=(((*ptr)&8)>>3);
	
	
}


