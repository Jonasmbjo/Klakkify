
#include <iostream>
#include <conio.h> // For using _kbhit() and _ghetch()
#include "sound.h"

int main() {
	std::cout << "Press any key to play a sound. Press 'q' to quit.\n";

	while(true) {
		if(_kbhit()) { // Checks if a key is pressed
			char ch = _getch(); // Get the keystrokes
			
			if (ch == 'q') break; // Exits if 'q' is pressed

			playSound(); // Play a sound for each keystroke
		}
	}

	return 0;
}

