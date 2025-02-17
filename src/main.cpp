
#include <iostream>
#include <termios.h> // For configuring terminal I/O behaviour (raw mode)
#include <unistd.h> // For low-level read() function
#include "sound.h" // Include the sound playback header

// Function to enable raw input mode
void enableRawMode() {
	struct termios tty; 
	tcgetattr(STDIN_FILENO, &tty);
	struct termios raw = tty;
	raw.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}

// Function to restore to normal mode
void disableRawMode() {
	struct termios tty;
	tcgetattr(STDIN_FILENO, &tty);
	tty.c_lflag |= (ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}



int main() {
	std::cout << "Press any key to play a sound. Press 'q' to quit.\n";


	// Enable raw mode to capture keystrokes instantly
	enableRawMode();

	char ch;
	
	// Loop where keystrokes are read
	while(true) {
		read(STDIN_FILENO, &ch, 1); // Reads a single character from standard input
		if(ch == 'q') break; // Exits if 'q' is pressed

		playSound(); // Plays a sound for each keystroke
	}
	
	// Restore terminal settings to normal mode
	disableRawMode();

	return 0;
}

