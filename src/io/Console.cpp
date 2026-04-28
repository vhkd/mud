#include "io/Console.h"

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <thread>

namespace Console {

void clear() {
	std::system("clear");
}

void pause() {
	std::cout << "按回车继续...";
	if (std::cin.peek() == '\n') {
		std::cin.get();
	}
	std::cin.get();
}

void sleepMs(int milliseconds) {
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

}
