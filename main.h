#ifndef MAIN_H_
#define MAIN_H_

#include "notes.h"

// Define led port connections.
#define RED BIT2
#define GREEN BIT5
#define LED_DIRECTORY P1DIR
#define LED_OUTPUT P1OUT

// Define button connections.
#define BUTTON BIT3
#define BUTTON_DIRECTORY P1DIR
#define BUTTON_IN P1IN

// Define speaker connections.
#define SPEAKER BIT7
#define SPEAKER_DIRECTORY P1DIR
#define SPEAKER_OUTPUT P1OUT

//Intialize the necessary elements.
void init();

//CCR0 timer interrupt.
void __attribute__((interrupt (TIMERA0_VECTOR))) frequency_wave();

//TAIV timer interrupt.
void __attribute__((interrupt (TIMERA1_VECTOR))) ms_gone_by();

//Program start point.
int main();

#endif // MAIN_H_
