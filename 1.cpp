#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>

#include "funkcje.h"

using namespace std;

int main(int argc, char* argv[])
{
    // Variables
    int loopIter = 0;
    int arraySize = atoi(argv[1]);
    int perCount = atoi(argv[2]);

    int *tab = new int[arraySize];

    srand(time(NULL));

    // Checking input
    if ((*argv[2] == 'A' && arraySize > 9))
    {
        cout << "Blad " << endl;
        return 0;
    }

    // Filling an array
    fillArray(tab, arraySize);

    // Permutations
    if (*argv[2] == 'A')
        allPermutations(tab, arraySize);
    else 
        randomPermutations(tab, perCount, arraySize);

    delete[] tab;

    return 0;
}
