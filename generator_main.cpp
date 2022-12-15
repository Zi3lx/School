#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <vector>

#include "generator_util.h"

using namespace std;

int main(int argc, char* argv[])
{
    // Variables
    int arraySize = atoi(argv[1]);
    int perCount = atoi(argv[2]);
		vector<int> input=generateInitialSet(arraySize);
    srand(time(NULL));
    // Permutations
    if (*argv[2] == 'A')
        printAllPermutations(input);
    else 
        printNRandomPermutations(input, perCount);
    return 0;
}
