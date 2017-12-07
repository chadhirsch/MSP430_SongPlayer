#include "notes.h"


volatile unsigned int sound_enabled = 0;
volatile unsigned int current_note = A4; 
volatile unsigned int ms_elapsed = 0;
static unsigned int ms_per_tick = 0;

void set_BeatsPerMinute(unsigned int BeatsPerMinute) {
    ms_per_tick = 60000 / (TicksForEachBeat * BeatsPerMinute); //number of ms per tick from the beats per minute.
}

void play(unsigned int note, unsigned int duration_ticks) {
    unsigned int duration_ms = 0;

	duration_ms = duration_ticks * ms_per_tick;     //Find the duration (in ms).
	current_note = note;				//Set the current note.
	sound_enabled = 1; 				//Enable the sound ouput.
	ms_elapsed = 0; 				//Reset the elapsed counter.
	while (ms_elapsed < duration_ms - DEAD_TIME_MS);// Wait for the note duration to expire.
	sound_enabled = 0; 				//Disable sound output. 
	while (ms_elapsed < duration_ms); 		//Wait for the full duration to expire.
}

void rest(unsigned int duration_ticks) {
    unsigned int duration_ms = 0;

	duration_ms = duration_ticks * ms_per_tick; 	//Compute the duration (in ms).
	sound_enabled = 0; 				// No sound.
	ms_elapsed = 0; 				//Reset counter.
	while(ms_elapsed < duration_ms); 		//Wait for the rest duration
}
