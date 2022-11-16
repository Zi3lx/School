#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>

using namespace std;

void allPermutations(int*, int);
void randomPermutations(int*, int, int);

int main(int argc, char* argv[])
{
    for (int i  = 0; i < atoi(argv[1]); i++)
    {
        // Variables
        int loopIter = 0;
        int arraySize = atoi(argv[2 + (2 * i)]);
        int perCount = atoi(argv[3 + (2 * i)]);

        int *tab = new int[arraySize];


        // Checking input
        if (perCount > 10000)
        {
            cout << "Za duzo permutacji zostalo podanych" << endl;
            return 0;
        }

        // Filling an array
        srand(time(NULL));
        for (int i = 1; i <= arraySize; i++)
            tab[i-1] = i;


        // Permutations
        if ((*argv[3 + (2 * i)]) == 'A')
            allPermutations(tab, arraySize);
        else 
            randomPermutations(tab, perCount, arraySize);


        delete[] tab;
    }
  return 0;
}

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
        random_shuffle(tab, tab+arraySize);
        for (int i = 1; i <= arraySize; i++)
            cout << tab[i-1] << " ";
        cout << endl;
    }
}
