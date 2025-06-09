#include <iostream>
#include <time.h>
#include <windows.h>
#include "sort_utils.h"

/*
Jakie mamy algorytmy sortowania?
-przez scalanie (mergesort)
-sortowanie Shella
-przez wstawianie
-przez selekcje (wybor)
-przez kopcowanie (heapsort)



Od czego zalezy efektywnosc algorytmu?

Czas i poamiec potrzebne do zrealizowania
algorytmow sa wyrazone w funkcji rozmiaru danych wejsciowych (ozn. n).

Zlozonosc czasowa - to zaleznosc miedzy rozmiarem i porzadkiem danych
wejsciowych algorytmu, a jego czasem wykonania.

Zlozonosc pamieciowa - to zaleznosc pomiedzy rozmiarem i porzadkiem danych
wejsciowych algorytmu, a jego zapotrzebowaniem na pamiec
niezbedna do realizacji tegoz algorytmu



*/


using namespace std;

int ile;
clock_t start,stop;
double czas;

void sortowanie_babelkowe(int *tab, int n)
{
    setColor(YELLOW);
    std::cout << "Bubble sort: sorting..." << std::endl;
    setColor(WHITE);
    for(int i=1; i<n; i++)
    {
        for(int j=n-1; j>=1; j--)
        {
            // Usunięto wyświetlanie w każdej iteracji
            if(tab[j]<tab[j-1])
            {
                int bufor;
                bufor=tab[j-1];
                tab[j-1]=tab[j];
                tab[j]=bufor;
            }
        }
    }
    setColor(YELLOW);
    std::cout << "Bubble sort: finished sorting." << std::endl;
    setColor(WHITE);
}

void quicksort(int *tablica, int lewy, int prawy)
{
    // Usunięto wyświetlanie w każdej iteracji
    if (lewy >= prawy) return;
    int v=tablica[(lewy+prawy)/2];
    int i=lewy, j=prawy, x;
    do
    {
        while(tablica[i]<v) i++;
        while(tablica[j]>v) j--;
        if(i<=j)
        {
            x=tablica[i];
            tablica[i]=tablica[j];
            tablica[j]=x;
            i++;
            j--;
        }
    }
    while(i<=j);
    if(j>lewy) quicksort(tablica,lewy, j);
    if(i<prawy) quicksort(tablica, i, prawy);
}

// ...existing code...
void drawHeader() {
    clearScreen();
    setColor(CYAN);
    drawLine('=');
    std::cout << "\n\t\tSorting Algorithm Comparison\n";
    std::cout << "\t\tCreated by Adrian Lesniak\n";
    drawLine('=');
    setColor(WHITE);
    std::cout << "\nThis program compares the execution time of Quicksort and Bubble sort algorithms.\n";
    std::cout << "Options available:\n";
    std::cout << "- Generate random numbers for sorting\n";
    std::cout << "- View sorting process and execution time\n";
    std::cout << "- Save results to file\n\n";
}

void saveResults(const std::string& filename, double bubbleTime, double quickTime, int size) {
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << "Test results [" << std::time(nullptr) << "]:\n";
        file << "Array size: " << size << "\n";
        file << "Bubble sort time: " << bubbleTime << "s\n";
        file << "Quick sort time: " << quickTime << "s\n\n";
        file.close();
    }
}

int main() {
    SetConsoleTitle("Sorting Algorithm Comparison");

    while (true) {
        drawHeader();

        try {
            setColor(YELLOW);
            std::cout << "Enter array size (0 to exit): ";
            setColor(WHITE);
            std::cin >> ile;

            if (ile <= 0) break;
            if (ile > 1000000) {
                throw std::runtime_error("Array size too large!");
            }

            system("cls");

            //dynamiczna alokacja tablicy
            int *tablica = new int[ile];
            int *tablica2 = new int[ile];

            //inicjowanie generatora
            srand(time(NULL));

            //wczytywanie losowych liczb do tablicy
            for (int i = 0; i < ile; i++) {
                tablica[i] = rand() % 100000 + 1;
            }

            //przepisanie tablicy do tablicy2
            for (int i = 0; i < ile; i++) {
                tablica2[i] = tablica[i];
            }

            setColor(GREEN);
            std::cout << "\n--- Bubble Sort ---\n";
            setColor(WHITE);

            cout << "Sorting " << ile << " elements using Bubble Sort. Please wait!" << endl;
            start = clock();
            sortowanie_babelkowe(tablica, ile);
            stop = clock();
            double bubbleTime = (double)(stop - start) / CLOCKS_PER_SEC;
            cout << "\nBubble Sort completed in: " << bubbleTime << " s" << endl;

            setColor(GREEN);
            std::cout << "\n--- Quick Sort ---\n";
            setColor(WHITE);

            cout << "Sorting " << ile << " elements using Quick Sort. Please wait!" << endl;
            start = clock();
            quicksort(tablica2, 0, ile - 1);
            stop = clock();
            double quickTime = (double)(stop - start) / CLOCKS_PER_SEC;
            cout << "\nQuick Sort completed in: " << quickTime << " s" << endl;

            saveResults("sort_results.txt", bubbleTime, quickTime, ile);

            setColor(MAGENTA);
            std::cout << "\nResults have been saved to sort_results.txt\n";
            setColor(WHITE);
        }
        catch (const std::exception& e) {
            setColor(RED);
            std::cout << "\nError: " << e.what() << std::endl;
            setColor(WHITE);
            logError(e.what());
        }

        std::cout << "\nPress any key to continue...";
        waitForKeyPress();
    }

    return 0;
}
