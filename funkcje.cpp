#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>

#include "funkcje.h"

using namespace std;

void allPermutations(int* tab, int arraySize)
{
    int loopIter = 0;
    do
        {
            for (int i = 1; i <= arraySize; i++)
                cout << tab[i-1] << " ";
            cout << endl;
            loopIter++;
        } while (next_permutation(tab, tab + arraySize));
    
    cout << "Ilosc wykonanych permutacji "  << endl;
    cout << loopIter << endl;
}

void randomPermutations(int* tab, int perCount, int arraySize)
{
    for (int i = 0; i < perCount; i++)
    {
        randPermutation(tab, arraySize);
        nextPermutation(tab, arraySize);       
        prevPermutation(tab, arraySize);

        iloscInwersji(tab, arraySize);
        
        cout << endl;
    }
     cout << "Ilosc wykonanych permutacji " << perCount << endl;
}

void randPermutation(int* tab, int arraySize)
{
    cout << "Losowa Permutacja" << endl;
    random_shuffle(tab, tab+arraySize);
    drawPermutation(tab, arraySize);
}

void nextPermutation(int* tab, int arraySize)
{
    cout << "Kolejna Permutacja" << endl;
    next_permutation(tab, tab + arraySize);
    drawPermutation(tab, arraySize);
}

void prevPermutation(int* tab, int arraySize)
{
    cout << "Poprzednia Permutacja" << endl;
    prev_permutation(tab, tab + arraySize);
    prev_permutation(tab, tab + arraySize);
    drawPermutation(tab, arraySize);
}

void drawPermutation(int* tab, int arraySize)
{
    for (int i = 1; i <= arraySize; i++)
        cout << tab[i-1] << " ";
    cout << endl;
}

void iloscInwersji(int* tab, int arraySize)
{
    int inwersje = 0;

    for (int i = 0; i < arraySize - 1; i++)
        for (int j = i + 1; j < arraySize; j++)
            if (tab[i] > tab[j])
                inwersje++;
    cout << "Ilosc inwersji: " << inwersje << endl;
}

void fillArray(int* tab, int arraySize)
{
    for (int i = 1; i <= arraySize; i++)
        tab[i-1] = i;
}