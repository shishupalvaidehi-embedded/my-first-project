#include<reg51.h>
#define lcd P2
sbit RS=P2^4;
sbit EN=P2^5;

void lcd_start();
void lcd_cmd(unsigned int cmd);
void lcd_data(unsigned char dat);
void delay(unsigned int t);
	void lcd_str(unsigned char word[]);


void lcd_start()
{
	lcd_cmd(0X28);   // 4bit mode
	lcd_cmd(0X01);
	lcd_cmd(0X0F);  // CURSOR BLINKING(BEST OPTION)
	//lcd_cmd(0X0E);  // CURSOR FORWARD
	//lcd_cmd(0X0C);  // NO CURSOR 
	lcd_cmd(0X80);  //first line
}
void lcd_cmd(unsigned int cmd)
	{
		lcd=(cmd>>4);
		RS=0;
		EN=1;
		delay(1);
		EN=0;
		
		lcd=cmd;
		RS=0;
		EN=1;
		delay(1);
		EN=0;
	}
	
	void lcd_data(unsigned char dat)
	{
		lcd=(dat>>4);
		RS=1;
		EN=1;
		delay(1);
		EN=0;
		
		lcd=dat;
		RS=1;
		EN=1;
		delay(1);
		EN=0;
	}
	void delay(unsigned int t)
	{
		unsigned int i,j;
		for(i=0;i<=10*t;i++)
		{
			for(j=0;j<=127;j++);
		}
	}
	void lcd_str(unsigned char word[])
	{
		unsigned int i;
		for(i=0;word[i]!='\0';i++)
		{
			lcd_data(word[i]);
		}
	}