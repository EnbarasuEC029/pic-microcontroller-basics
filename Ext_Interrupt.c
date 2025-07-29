#include<pic.h>
#define _XTAL_FREQ 20000000

void interrupt name(){
	if(INTF==1)
	{
		RC0=~RC0;
		INTF=0;
		}
	}

void main()
{
	GIE=1;
	PEIE=1;
	INTE=1;
	INTEDG =1;
	TRISC=0X00;
	
	while(1){
		
		RC1=1;
		for(int i=0;i<10000;i++);
		RC1=0;
		for(int i=0;i<10000;i++);
	}	
}
