#include "sort_utils.h"

void setColor(Color color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, static_cast<WORD>(color));
}

void drawLine(char c, int length) {
    for (int i = 0; i < length; i++) {
        std::cout << c;
    }
    std::cout << std::endl;
}

void clearScreen() {
    system("cls");
}

void waitForKeyPress() {
    std::cout << "\nPress any key to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void logError(const std::string& error) {
    std::ofstream errorLog("errors.log", std::ios::app);
    if (errorLog.is_open()) {
        time_t now = time(nullptr);
        errorLog << "[" << ctime(&now) << "] " << error << std::endl;
        errorLog.close();
    }
}
