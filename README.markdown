# 📊⏱️ Sorting Algorithm Showdown: Bubble vs. Quicksort 🚀
_A C++ console application for comparing the performance (execution time) of Bubble Sort and Quicksort on randomly generated arrays._

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)](https://isocpp.org/)
[![Platform: Windows](https://img.shields.io/badge/Platform-Windows-lightgrey.svg)](https://www.microsoft.com/windows)

## 📋 Table of Contents
1.  [Project Description](#-project-description)
2.  [Key Features](#-key-features)
3.  [Screenshots](#-screenshots)
4.  [System Requirements](#-system-requirements)
5.  [Installation and Running](#️-installation-and-running)
6.  [How to Use](#️-how-to-use)
7.  [Technical Details & Program Logic](#-technical-details--program-logic)
8.  [Contributing](#-contributing)
9.  [Author](#️-author)
10. [License](#-license)

## 📝 Project Description

**Sorting Algorithm Showdown** is an insightful C++ console application designed to practically demonstrate and compare the performance characteristics of two fundamental sorting algorithms: **Bubble Sort** and **Quicksort**. The program generates an array of random numbers of a user-specified size, then meticulously measures and displays the execution time taken by each algorithm to sort an identical copy of this array. Results, including array size and timings for both sorts, are saved to `sort_results.txt` for later analysis. The application features a colorful user interface and robust error handling for invalid inputs, making it an excellent educational tool for understanding algorithmic efficiency.

![Demo GIF](screenshots/1.gif)

## ✨ Key Features

*   🎲 **Random Array Generation**: Creates arrays of random integers with a user-defined size (up to 1,000,000 elements).
*   ⚖️ **Algorithm Comparison**: Directly compares the execution time of:
    *   **Bubble Sort** (a simple, O(n²) complexity algorithm)
    *   **Quicksort** (an efficient, O(n log n) average complexity divide-and-conquer algorithm)
*   ⏱️ **Execution Time Measurement**: Accurately measures the time taken by each sorting algorithm using C++ chrono library or similar high-resolution timers.
*   💾 **Results Logging**: Saves comparison results (array size, Bubble Sort time, Quicksort time, timestamp) to `sort_results.txt`, appending new results for cumulative analysis.
*   🌈 **Colorful Console Interface**: Enhanced user experience with colored text for prompts, results, and status messages, facilitated by `sort_utils.h` (Windows-specific for full effect).
*   ✔️ **Input Validation & Error Handling**: Validates user input for array size and logs any errors encountered (e.g., non-numeric input, size out of range).
*   🔄 **Iterative Testing**: Allows users to run multiple comparisons with different array sizes in a single session.

## 🖼️ Screenshots

_Screenshots showcasing the array size input, the display of sorting times for Bubble Sort and Quicksort, and an example of the `sort_results.txt` file content._

<p align="center">
  <img src="screenshots\1.jpg" width="300"/>
  <img src="screenshots\2.jpg" width="300"/>
  <img src="screenshots\3.jpg" width="300"/>
  <img src="screenshots\4.jpg" width="300"/>
  <img src="screenshots\5.jpg" width="300"/>
  <img src="screenshots\6.jpg" width="300"/>
</p>

## ⚙️ System Requirements

*   **Operating System**: Windows is recommended for full color functionality, as the console manipulation utilities are likely Windows-specific (via `windows.h` abstracted in `sort_utils.h`).
*   **C++ Compiler**: Any modern C++ compiler that supports C++11 or newer (e.g., g++, MinGW, Clang, MSVC).
*   📄 **`sort_utils.h` Header File (User-Provided)**: This project **critically requires** a header file named `sort_utils.h`. **This file is not included in the repository and must be created by the user.** It should define utility functions for console manipulation (colors, screen clearing, etc.) and error logging. See the "Installation and Running" section for more details.

## 🛠️ Installation and Running

1.  **Clone the Repository**:
    ```bash
    git clone <repository-url>
    ```
    (Replace `<repository-url>` with the actual URL of your repository)

2.  **Navigate to the Project Directory**:
    ```bash
    cd <repository-directory>
    ```
    (Replace `<repository-directory>` with the name of the cloned folder)

3.  **Create `sort_utils.h`**:
    Before compiling, you **must** create a file named `sort_utils.h` in the project's root directory. This file should define necessary utility functions. Here's an illustrative example:
    ```cpp
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
    ```
    *Adjust these constants and function declarations to precisely match what your `main.cpp` (and potentially your sorting algorithm implementations) expect. Implement these functions, likely in a `sort_utils.cpp` file.*

4.  **Implement Sorting Algorithms**:
    Ensure that your `main.cpp` (or linked files) contains correct implementations of Bubble Sort and Quicksort.

5.  **Compile the Program**:
    Open a terminal (like Command Prompt or PowerShell) in the project directory.
    **Example using g++ (MinGW):**
    ```bash
    g++ main.cpp sort_utils.cpp -o sorting_comparator.exe -std=c++11 -O2 -static-libgcc -static-libstdc++
    ```
    *(This assumes `sort_utils.cpp` contains implementations for `sort_utils.h`. The `-std=c++11` ensures C++11 features like `<chrono>` are available. `-O2` is an optimization flag which is good for performance comparisons, though be mindful it can sometimes affect very fine-grained timing observations of tiny code snippets differently than unoptimized code).*

6.  **Run the Application**:
    After successful compilation, execute the generated program:
    ```bash
    ./sorting_comparator.exe
    ```
    or simply in CMD:
    ```bash
    sorting_comparator.exe
    ```

## ▶️ How to Use

1.  Launch the application.
2.  You will be prompted to **enter the size of the array** you want to sort. Input a number between 1 and 1,000,000.
3.  Entering `0` at this prompt will typically exit the program.
4.  If a valid size is entered, the program will:
    *   Generate an array of random integers of the specified size.
    *   Create two copies of this array.
    *   Sort one copy using **Bubble Sort** and measure its execution time.
    *   Sort the other copy using **Quicksort** and measure its execution time.
    *   Display the execution times for both algorithms.
5.  The results (array size, Bubble Sort time, Quicksort time, and a timestamp) will be appended to `sort_results.txt`.
6.  You will then be prompted to enter a new array size or exit.

## 💡 Technical Details & Program Logic

*   **Array Generation**: A `std::vector<int>` or dynamic C-style array is filled with random integers. `rand()` or C++11 `<random>` utilities can be used.
*   **Sorting Algorithms**:
    *   **Bubble Sort**: Implemented as the classic O(n²) comparison sort.
    *   **Quicksort**: Implemented using the divide-and-conquer strategy, typically with a recursive approach and a pivot selection strategy.
*   **Time Measurement**: Uses C++ `<chrono>` library (e.g., `std::chrono::high_resolution_clock` or `std::chrono::steady_clock`) to get precise start and end times for each sort operation. The duration is then calculated.
*   **`sort_utils.h`**: This critical user-provided header contains utility functions like `setColor()`, `clearScreen()`, `drawLine()`, `waitForKeyPress()`, and `logError()`. It might also contain `logResults()` specifically for appending to `sort_results.txt`.
*   **File Output**: Results are appended to `sort_results.txt` using `std::ofstream` with `std::ios::app` mode, usually including a timestamp for each entry.
*   **Memory Management**: The program is designed to handle arrays up to 1,000,000 integers. Ensure sufficient memory is available, especially for larger array sizes. Copies of the array are made for each sort to ensure they operate on identical unsorted data.

## 🤝 Contributing

Contributions to the **Sorting Algorithm Showdown** are welcome! If you have ideas for adding more sorting algorithms to compare (e.g., Merge Sort, Insertion Sort, Heap Sort), improving the timing accuracy, enhancing the UI, or adding graphical result plotting:

1.  Fork the repository.
2.  Create a new branch for your feature: `git checkout -b feature/your-sorting-enhancement`
3.  Implement your changes and commit them: `git commit -m "Feature: Add your sorting enhancement"`
4.  Push your changes to your branch: `git push origin feature/your-sorting-enhancement`
5.  Open a Pull Request.

Please ensure your contributions are well-documented and adhere to the project's coding style.

## ✍️ Author

**Adrian Lesniak**
_C++ Developer & Algorithm Enthusiast_

## 📃 License

This project is licensed under the **MIT License**.
The full text of the license is available at: [https://opensource.org/licenses/MIT](https://opensource.org/licenses/MIT)

---
⏳ _Witness the race of algorithms and understand the true cost of sorting!_
