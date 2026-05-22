#include "szerLib.hpp"

void wait(int ms) {
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void slow_cout(std::string text, int time) {
	int size = text.length();
	for (int i = 0; i < size; i++) {
		std::cout << text[i] << std::flush;
		wait(time);
	}
}

int main() {
	std::string slow;
	std::cin >> slow;

	slow_cout(slow, 20);
	std::cout << '\n';

	std::cout << getCpu();

	return 0;
}
