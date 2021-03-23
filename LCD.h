void LCD_Main(void);
void LCD_Write_Command(unsigned char Value);
void LCD_Send_String(unsigned char *s, int SLEN);
void LCD_Write_data(unsigned char value);
void LCD_Transfer(unsigned char  *ptr);


extern void LCD_Main(void);
extern void LCD_Write_Command(unsigned char Value);
extern void LCD_Send_String(unsigned char *s, int SLEN);
extern void LCD_Write_data(unsigned char value);
extern void LCD_Transfer(unsigned char  *ptr);