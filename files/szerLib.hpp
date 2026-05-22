/* * * * * * * * * * * * * *
 * SzerLib++
 * C++ Library with helpful functions
 * by Szerwigi1410
 * * * * * * * * * * * * * */

#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <random>

//-defines---------------------------------------------------------------------
// colors
#define RESET_COLOR "\033[0m"
#define GREEN "\033[32m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

//-functions-------------------------------------------------------------------

// custom color
void color_cout(int x) {
    std::cout << "\033[" << x << "m";
}

// wait
void wait(int ms) {
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

// slow cout
void slow_cout(std::string string, int time_ms) {
	int size = string.length();
	for (int i = 0; i < size; i++) {
		std::cout << string[i] << std::flush;
		wait(time_ms);
	}
}

// spinner
void spinner_wait(int x) {
	for (int i = 0; i < 20; i++) {
        char spin[] = {'|', '/', '-', '\\'};
		std::cout << spin[i % 4] << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(x));
		std::cout << "\b" << std::flush;
	}
}

// random number generator
int random_int (int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

// random float number generator
int random_float (float min, float max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<float> dist(min, max);
    return dist(gen);
}

std::string getCPU() {
    std::ifstream file("/proc/cpuinfo");
    std::string line;

    while (std::getline(file, line)) {
        if (line.find("model name") != std::string::npos) {
            auto pos = line.find(':');
            // if (pos != std::string::npos) {
            //     std::string value = line.substr(pos + 1);
            //     while (!value.empty() && std::isspace((unsigned char)value.front())) {
            //         value.erase(value.begin());
            //     }

            //     if (value.find("Intel") != std::string::npos) {
            //         return "Inetl";
            //     }
            //     else if (value.find("AMD") != std::string::npos) {
            //         return "red team";
            //     }

            //     return value;
            // }
            return line;
        }
    }
    return "Unknown CPU";
}