#pragma once
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <ctime>
#include <limits>

enum Color { 
    BLUE = 9,
    GREEN = 10,
    CYAN = 11,
    RED = 12,
    MAGENTA = 13,
    YELLOW = 14,
    WHITE = 15
};

void setColor(Color color);
void drawLine(char c = '-', int length = 50);
void clearScreen();
void waitForKeyPress();
void logError(const std::string& error);
