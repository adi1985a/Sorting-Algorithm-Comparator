# Sorting Algorithm Comparator

## Description
A C++ console application that compares the performance of Bubble Sort and Quicksort algorithms. Generates random arrays, measures execution time, and saves results to a file. Features a colorful interface and error handling. Created by Adrian Lesniak.

## Features
- Generate random arrays for sorting
- Compare Bubble Sort and Quicksort execution times
- Save results to `sort_results.txt`
- Colorful console interface
- Error logging for invalid inputs

## Requirements
- C++ compiler (e.g., g++)
- Header file: `sort_utils.h` (not provided)
- Windows OS (uses `windows.h` for console functions)

## Installation
1. Clone the repository:
   ```bash
   git clone <repository-url>
   ```
2. Ensure `sort_utils.h` is in the project directory.
3. Compile the program:
   ```bash
   g++ main.cpp -o sorting_comparator
   ```

## Usage
1. Run the program:
   ```bash
   ./sorting_comparator
   ```
2. Enter the array size (1 to 1,000,000) or 0 to exit.
3. The program will:
   - Generate a random array
   - Sort using Bubble Sort and Quicksort
   - Display execution times
   - Save results to `sort_results.txt`

## Notes
- Requires `sort_utils.h` for functions like `clearScreen()`, `setColor()`, `drawLine()`, `waitForKeyPress()`, and `logError()`.
- Results are appended to `sort_results.txt` with timestamps.
- Array size is limited to 1,000,000 to prevent excessive memory usage.

## Author
Adrian Lesniak

## License
MIT License