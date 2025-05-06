#include <pic.h>

void main() {
    unsigned int seg[11] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7C,0x07,0x7F,0x6F}, i, j;
    TRISD = 0x00;  // Set PORTD as output

    while(1) {
        for(i = 0; i <= 9; i++) {
            PORTD = seg[i];
            for(j = 0; j < 10000; j++); // Simple delay loop
        }
    }
}
