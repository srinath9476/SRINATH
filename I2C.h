

void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
unsigned char I2C_Read(void);
//unsigned char I2C_Read(char ack);
void I2C_Write(unsigned char datt);
void I2C_ACK(void);
void I2C_NACK(void);
void delay_ms(unsigned int ms_count);

extern void I2C_Init(void);
extern void I2C_Start(void);
extern void I2C_Stop(void);
//extern unsigned char I2C_Read(char ack);
extern unsigned char I2C_Read(void);
extern void I2C_Write(unsigned char datt);
extern void I2C_ACK(void);
extern void I2C_NACK(void);
extern void delay_ms(unsigned int ms_count);
