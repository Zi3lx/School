#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>

using namespace std;

void randomPermutations(int* tab, int perCount, int arraySize)
{
    for (int i = 0; i < perCount; i++)
    {
        cout << "Rand" << endl;
        random_shuffle(tab, tab+arraySize);
        drawPermutation(tab, arraySize);

        nextPermutation(tab, arraySize);
        
        prevPermutation(tab, arraySize);
        
        cout << endl;
    }
     cout << "Ilosc wykonanych permutacji " << perCount << endl;
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

    cout << endl;
}

void drawPermutation(int* tab, int arraySize)
{
    for (int i = 1; i <= arraySize; i++)
        cout << tab[i-1] << " ";
    cout << endl;
}