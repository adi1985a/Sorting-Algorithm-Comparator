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
    for(int i=1; i<n; i++)
    {
        for(int j=n-1; j>=1; j--)
        {
            if(tab[j]<tab[j-1])
            {
                int bufor;
                bufor=tab[j-1];
                tab[j-1]=tab[j];
                tab[j]=bufor;
            }
        }
    }
}

void quicksort(int *tablica, int lewy, int prawy)
{
    int v=tablica[(lewy+prawy)/2];
    int i,j,x;
    i=lewy;
    j=prawy;
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

            system ("cls");

            //dynamiczna alokacja tablicy
            int *tablica;
            tablica=new int [ile];

            int *tablica2;
            tablica2=new int [ile];

            //inicjowanie generatora
            srand(time(NULL));

            //wczytywanie losowych liczb do tablicy
            for(int i=0; i<ile; i++)
            {
                tablica[i] = rand()%100000+1;
            }

            //przepisanie tablicy do tablicy2
            for(int i=0; i<ile; i++)
            {
                tablica2[i]=tablica[i];
            }

            setColor(GREEN);
            std::cout << "\nStarting sorting process...\n";
            setColor(WHITE);

            cout<<"\nBubblesort in the process now. Please wait!"<<endl;
            start = clock();
            sortowanie_babelkowe(tablica,ile);
            stop = clock();
            czas = (double)(stop-start) / CLOCKS_PER_SEC;
            cout<<endl<<"\nBubblesort time: "<<czas<<" s"<<endl;

            cout<<endl<<"\nQuicksort in the process now. Please wait!"<<endl;
            start = clock();
            quicksort(tablica2, 0, ile-1);
            stop = clock();
            czas = (double)(stop-start) / CLOCKS_PER_SEC;
            cout<<endl<<"\nQuicksort time: "<<czas<<" s"<<endl;

            saveResults("sort_results.txt", czas, czas, ile);
            
            setColor(MAGENTA);
            std::cout << "\nResults have been saved to sort_results.txt\n";
            setColor(WHITE);
            
            std::cout << "\nPress any key to continue...";
            waitForKeyPress();
        }
        catch (const std::exception& e) {
            setColor(RED);
            std::cout << "\nError: " << e.what() << std::endl;
            setColor(WHITE);
            logError(e.what());
            waitForKeyPress();
        }
    }

    return 0;
}
