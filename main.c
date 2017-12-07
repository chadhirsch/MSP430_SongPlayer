#include <msp430.h>

#include "main.h"

#ifndef TIMERA0_VECTOR
#define TIMERA0_VECTOR TIMER0_A0_VECTOR
#endif // TIMER0_A0_VECTOR  

#ifndef TIMERA1_VECTOR
#define TIMERA1_VECTOR TIMER0_A1_VECTOR
#endif // TIMER0_A1_VECTOR 

// Uncomment the song you wish to play. When I tried to do both I ran into memory size limitations on the MSP.

 //#include "songs/great_fairy_fountain.c" 
 #include "songs/lost_woods.c" 

void init() {
    
    WDTCTL = WDTPW | WDTHOLD;	// Stop the watchdog. 

    // Set the system clock to 1 MHz.
    DCOCTL = CALDCO_1MHZ;
    BCSCTL1 = CALBC1_1MHZ;

    // Initialize LEDs (output) and button (input).
    LED_DIRECTORY |= RED;
    LED_DIRECTORY|= GREEN;
    
    P1OUT = 0;
    BUTTON_DIRECTORY &= ~BUTTON;
    P1REN |= BUTTON;                               
    P1OUT |= BUTTON; 

    SPEAKER_DIRECTORY |= SPEAKER; // Initialize speaker (output).
    
    // Initialize the timer. 
    TACTL |= TASSEL_2 | ID_0 | MC_2 | TAIE;
    TACCTL0 |= CCIE;
    TACCTL1 |= CCIE;

    
    WRITE_SR(GIE); // Enable interrupts globally.
}

void __attribute__((interrupt (TIMERA0_VECTOR))) frequency_wave() {
    // Push the timer forward by one note cycle.
    TACCR0 += current_note;

    // Output to the speaker if sound is enabled.
    if (sound_enabled) {
        SPEAKER_OUTPUT ^= SPEAKER;
    }
}




/* NOTE TO SELF: TAIV will give you a value indicating which one of the possible interrupt sources is causing the current interrupt. It also has a desired side effect of clearing that interrupt flag. */

//check TAIV for compare/capture interrupt
void __attribute__((interrupt (TIMERA1_VECTOR))) ms_gone_by() {
    switch (TAIV) {
        case 2: // CCR1
            TACCR1 += 1000; // 1 ms
            ms_elapsed++;
            break;
    }
}

int main() {
    // Initialize the system.
    init();

    while (1) {
        // Green LED off. Red LED on. 
        LED_OUTPUT |= RED;
        LED_OUTPUT &= ~GREEN;
        
        // Wait for button press.
        while (BUTTON_IN & BUTTON);
        
        //Green LED on. Red LED off. 
        LED_OUTPUT &= ~RED;
        LED_OUTPUT |= GREEN;
        
        //These functions are found/done in the selected song file.
        create_song();
        song_play();
	song_play();
    }
    
    return 0;
}
