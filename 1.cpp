#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>

#include "funkcje.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        cout << "Za malo argumenow podaj przynajmniej 3" << endl;
        return 0;
    }

    for (int i  = 0; i < atoi(argv[1]); i++)
    {
        // Variables
        int loopIter = 0;
        int arraySize = atoi(argv[2 + (2 * i)]);
        int perCount = atoi(argv[3 + (2 * i)]);

        int *tab = new int[arraySize];

        // Checking input
        if ((*argv[3 + (2 * i)] == 'A' && arraySize > 9))
        {
            cout << "Blad " << endl;
            return 0;
        }

        // Filling an array
        fillArray(tab, arraySize);

        // Permutations
        if (*argv[3 + (2 * i)] == 'A')
            allPermutations(tab, arraySize);
        else 
            randomPermutations(tab, perCount, arraySize);

        delete[] tab;
    }

  return 0;
}
