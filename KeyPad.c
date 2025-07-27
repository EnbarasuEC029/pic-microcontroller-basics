#include<pic.h>

#define rs RC0
#define rw RC1
#define en RC2

#define R1 RB4

#define R2 RB5

#define R3 RB6

#define R4 RB7

#define C1 RB0
#define C2 RB1
#define C3 RB2


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
void keypad(){
	C1=1,C2=0,C3=0;
	if(R1==1){
	lcd_data('1');
	while(R1==1);
	}
	if(R2==1){
	lcd_data('4');
	while(R2==1);
	}
	if(R3==1){
	lcd_data('7');
	while(R3==1);
	}
	if(R4==1){
	lcd_data('*');
	while(R4==1);
	}
	
	C1=0,C2=1,C3=0;
	if(R1==1){
	lcd_data('2');
	while(R1==1);
	}
	if(R2==1){
	lcd_data('5');
	while(R2==1);
	}
	if(R3==1){
	lcd_data('8');
	while(R3==1);
	}
	if(R4==1){
	lcd_data('0');
	while(R4==1);
	}
	
	C1=0,C2=0,C3=1;
	if(R1==1){
	lcd_data('3');
	while(R1==1);
	}
	if(R2==1){
	lcd_data('6');
	while(R2==1);
	}
	if(R3==1){
	lcd_data('9');
	while(R3==1);
	}
	if(R4==1){
	lcd_data('#');
	while(R4==1);
	}
}

void main(){
	TRISD = 0X00;
	TRISC = 0X00;
	TRISB = 0XF0;
	lcd_init();
	lcd_cmd(0X80);
	lcd_string("KEYPAD");
	lcd_cmd(0XC0);
	while(1){
	keypad();
	}	
}
