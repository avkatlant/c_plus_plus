// Отсортировать массив в случайном порядке | random_shuffle | STL C++ #24
// https://youtu.be/o9LykzwXAJI

#include <string.h>

#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>  // <-
#include <vector>

using namespace std;

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6};

  std::random_device rd;
  std::mt19937 g(rd());

  shuffle(begin(arr), end(arr), g);

  for (auto el : arr) {
    cout << el << "  ";
  }

  return 0;
}

/*

*/
