#include "utils.h"
#include <iostream>
#include <limits>

#ifdef _WIN32
#include <cstdlib>
#endif

std::string Utils::toLetterGrade(double score) {
    if (score >= 90.0) return "A";
    if (score >= 80.0) return "B";
    if (score >= 70.0) return "C";
    if (score >= 60.0) return "D";
    return "F";
}

double Utils::toGPA(double score) {
    if (score >= 93.0) return 4.0;
    if (score >= 90.0) return 3.7;
    if (score >= 87.0) return 3.3;
    if (score >= 83.0) return 3.0;
    if (score >= 80.0) return 2.7;
    if (score >= 77.0) return 2.3;
    if (score >= 73.0) return 2.0;
    if (score >= 70.0) return 1.7;
    if (score >= 67.0) return 1.3;
    if (score >= 63.0) return 1.0;
    if (score >= 60.0) return 0.7;
    return 0.0;
}

void Utils::clearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void Utils::pause() {
    std::cout << "\nНажмите Enter для продолжения...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int Utils::readInt() {
    int value;
    std::cin >> value;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return -1;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return value;
}
