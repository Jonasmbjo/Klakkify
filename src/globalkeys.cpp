
#include <iostream>
#include <linux/input.h>
#include <fcntl.h>
#include <unistd.h>
#include "sound.h"

int main() {
	const char* device = "/dev/input/event2";
	int fd = open(device, O_RDONLY);
	if (fd < 0) {
		std::cerr << "Error: Cannot open input device";
		return 1;
	}

	std::cout << "Listening for global key presses (Press Ctrl+C to exit)";

	struct input_event ev;
	while (read(fd, &ev, sizeof(struct input_event)) > 0) {
		if (ev.type == EV_KEY && ev.value == 1) { // Key pressed
			playSound();
		}
	}

	close(fd);
	return 0;
}
