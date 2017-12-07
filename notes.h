#ifndef NOTES_H_
#define NOTES_H_

// The number of milliseconds to kill the note before the duration expires.
#define DEAD_TIME_MS 20

// This is how many ticks we subdivide the beat into. 
// 4 ticks per beat gives us 16th note resolution. 
#define TicksForEachBeat 4

// Note definitions calculated with (1,000,000 Hz / note frequency / 2).
// With help from google to get not freq for the Zelda Songs.

#define SILENCE_MS 20
#define D7 212
#define Db6 450
#define G6 318
#define E5 757
#define Eb3 3213
#define D4 1702
#define Ab4 1203
#define A5 567
#define Db8 112
#define Gb7 168
#define E6 378
#define G5 637
#define Db5 901
#define F4 1431
#define Bb4 1072
#define Bb7 133
#define B6 252
#define Ab3 2407
#define Gb3 2702
#define Db3 3607
#define A6 283
#define Eb8 99
#define Eb7 200
#define B5 505
#define Eb6 401
#define Gb5 675
#define Ab7 150
#define D8 105
#define D3 3404
#define Bb3 2144
#define A3 2272
#define Db4 1803
#define C4 1910
#define E3 3033
#define B4 1011
#define F3 2863
#define Bb6 267
#define Gb4 1350
#define Eb5 803
#define Gb6 337
#define Eb4 1606
#define Db7 224
#define F7 178
#define C8 118
#define G3 2550
#define C3 3821
#define B7 126
#define A7 141
#define G4 1275
#define C6 477
#define Bb5 535
#define G7 158
#define B3 2024
#define Ab6 300
#define E4 1516
#define A4 1135
#define C5 955
#define D6 425
#define C7 238
#define D5 850
#define E7 189
#define F6 357
#define F5 715
#define Ab5 601

extern volatile unsigned int sound_enabled;  //Turns the sound output on or off.

extern volatile unsigned int current_note;   //Keeps track of the current note we are playing.

extern volatile unsigned int ms_elapsed;     //Keeps track of the number of ms gone by.

void set_BeatsPerMinute(unsigned int BeatsPerMinute); 	     //Sets the tempo in BPM

void play(unsigned int note, unsigned int duration_ticks); //Plays the passed note for the given duration.

void rest(unsigned int duration_ticks);       //Rests for the given duration.
	
#endif 					      //  NOTES_H_
