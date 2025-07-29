#include<pic.h>
#define _XTAL_FREQ 20000000
void timer0_init() {
    OPTION = 0x04; // Prescaler 1:64, assign to Timer0
    TMR0 = 6;          // Preload value for ~1ms delay
}

// Delay function using Timer0 for accurate ms delay
void delay_ms(unsigned int ms) {
    while (ms--) {
        TMR0 = 6;          // Reload preload value
        while (T0IF == 0); // Wait for overflow
        T0IF = 0;          // Clear overflow flag
    }
}

void main() {
    TRISB0 = 0;      // Set RB0 as output
    timer0_init();   // Initialize Timer0

    while(1) {
        RB0 = 1;           // Turn ON LED
        delay_ms(1000);    // 1 second delay
        RB0 = 0;           // Turn OFF LED
        delay_ms(1000);    // 1 second delay
    }
}
