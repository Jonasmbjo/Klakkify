
#include "sound.h"
#include <cstdlib> // For system() function to play sound
#include <iostream>

// Function to play a sound
void playSound() {
	// Use system() to play 
	
	int result = system("paplay src/sound1.wav &");
	if (result !=0) {
		std::cerr << "Error: Failed to play sound!!!\n";
	} else {
		std::cout << "Should play a sound";
	}
}
