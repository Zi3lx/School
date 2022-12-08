#pragma once
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

/*
Output specification:
[n permutations, each separated by newline]

For each permutation - properties separated by newline:
- next
- previous
- inversions
- is even? (0 - false, 1 - true)

*/
using namespace std;

vector<int> generateInitialSet(size_t size);
void printPermutation(vector<int> const &input);
void printPermutationWithParameters(vector<int> const &input);
void printNextPermutation(vector<int> input);
void printPreviousPermutation(vector<int> input);
int numberOfInversions(vector<int> const &input);
bool isEven(int x);
void printNumberOfInversions(vector<int> const &input);
void printAllPermutations(vector<int> input);
void printNRandomPermutations(vector<int> input, int n);

void printTwoLineNotation(vector<int> const &input);
void printSquare(vector<int> const &input);
