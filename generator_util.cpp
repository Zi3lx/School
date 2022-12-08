#include "generator_util.h"

using namespace std;

/*
Output specification:
[n permutations, each separated by newline]

For each permutation - properties separated by newline:
- next
- previous
- inversions
- is even? (0 - false, 1 - true)

*/

vector<int> generateInitialSet(size_t size) {
  vector<int> initialSet(size);
  for (int i = 0; i < size; i++)
    initialSet[i] = i + 1;
  return initialSet;
}

void printPermutation(vector<int> const &input) {
  for (int i = 0; i < input.size(); i++)
    cout << input[i] << " ";
  cout << endl;
}
void printPermutationWithParameters(vector<int> const &input) {
  cout << "PERMUTATION: ";
  printPermutation(input);
  cout << "TWO_LINE: ";
  printTwoLineNotation(input);
  cout << "NEXT: ";
  printNextPermutation(input);
  cout << "PREV: ";
  printPreviousPermutation(input);
  cout << "SQUARE: ";
  printSquare(input);
  cout << "INVERSIONS: ";
  int inversions = numberOfInversions(input);
  cout << inversions << endl;
  cout << "IS_EVEN: ";
  cout << isEven(inversions) << endl;
}

void printNextPermutation(vector<int> input) {
  next_permutation(input.begin(), input.end());
  printPermutation(input);
}

void printPreviousPermutation(vector<int> input) {
  prev_permutation(input.begin(), input.end());
  printPermutation(input);
}
int numberOfInversions(vector<int> const &input) {
  int inw = 0;
  for (int i = 0; i < input.size(); i++)
    for (int j = i + 1; j < input.size(); j++)
      if (input[i] > input[j])
        inw++;

  return inw;
}

bool isEven(int x) {
  if (x % 2 == 0)
    return 1;
  else
    return 0;
}

void printNumberOfInversions(vector<int> const &input) {
  cout << numberOfInversions(input) << endl;
}

void printAllPermutations(vector<int> input) {
  // vector<int> initial=input;
  do {
    printPermutationWithParameters(input);
  } while (next_permutation(input.begin(), input.end()));
}

// for printNRandomPermutations, avoids repetitions (it actually doesn't)
std::default_random_engine
    rng(std::chrono::system_clock::now().time_since_epoch().count());

void printNRandomPermutations(vector<int> input, int n) {
  for (int i = 0; i < n; i++) {
    vector<int> temp = input;
    shuffle(temp.begin(), temp.end(), rng);
    printPermutationWithParameters(temp);
  }
}

void printTwoLineNotation(vector<int> const &input) {
  for (int i = 1; i <= input.size(); i++)
    if (i == input.size())
      cout << i << " \\\\ ";
    else
      cout << i << " & ";
  for (int i = 0; i < input.size(); i++)
    if (i == input.size())
      cout << input[i] << endl;
    else
      cout << input[i] << " & ";
  cout << endl;
}

void printSquare(vector<int> const &input) {
  for (int i = 0; i < input.size(); i++) {
    int index = input[i] - 1;
    cout << input[index] << " ";
  }
  cout << endl;
}
