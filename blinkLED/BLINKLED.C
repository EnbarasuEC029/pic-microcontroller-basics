#include <pic.h>
#define _XTAL_FREQ 20000000

void main(void)
{
    TRISD0 = 0; // Set RD0 as output

    while(1)
    {
        RD0 = 1;           // Turn LED ON
        for(int i=0;i<1000;i++); // Wait 1 second
        RD0 = 0;           // Turn LED OFF
        for(int i=0;i<1000;i++); // Wait 1 second
    }
}
