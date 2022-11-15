#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    // Zmienne
    int loopIter = 0;
    int arraySize = atoi(argv[1]);
    int perCount = atoi(argv[2]);

    // Dynamiczne alkowanie tablicy
    int *tab = new int[arraySize];

    // Sprawdzenie danych wejsciowych
    if (perCount > 10000)
    {
        cout << "Za duzo permutacji zostalo podanych" << endl;
        return 0;
    }


    // Wypelnianaie tablicy do pierwszego parametru
    for (int i = 1; i <= arraySize; i++)
        tab[i-1] = i;

    // Petla permutujaca tablice
    do
    {
        for (int i = 1; i <= arraySize; i++)
            cout << tab[i-1] << " ";
        cout << endl;

        loopIter++;
        if (loopIter == perCount)
            break;

    } while (next_permutation(tab, tab + arraySize));

    delete[] tab;
  return 0;
}
