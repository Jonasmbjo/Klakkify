
#include "sound.h"
#include <cstdlib> // For system() function to play sound

// Function to play a sound
void playSound() {
	// Use system() to play 

	system("aplay src/sound1.wav &");
}
