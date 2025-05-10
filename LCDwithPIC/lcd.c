#include<pic.h>

#define rs RC0
#define rw RC1
#define en RC2



void lcd_cmd(unsigned char cmd)
{
	PORTD=cmd;
	rs=0;
	rw=0;
	en=1;
	for(int i=0;i<5000;i++);
	en=0;
}
void lcd_data(unsigned char data)
{
	PORTD=data;
	rs=1;
	rw=0;
	en=1;
	for(int i=0;i<5000;i++);
	en=0;
}
void lcd_string(const char *str) {
    while(*str) {
        lcd_data(*str++);
    }
}
void lcd_init() {
    

  
    lcd_cmd(0x38); // 8-bit mode, 2 lines, 5x7 font
     lcd_cmd(0x06); // Increment cursor
    lcd_cmd(0x0C); // Display on, cursor off
    lcd_cmd(0x01); // Clear display
   
}


void main(){
	TRISD = 0X00;
	TRISC = 0X00;
	lcd_init();
	while(1){
		lcd_cmd(0x83);
		lcd_string("ENBARASU");
		lcd_cmd(0xC3);
		lcd_string("hello world!");
	}	
}