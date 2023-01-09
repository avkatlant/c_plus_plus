// Поиск максимального элемента | max_element c++ | Библиотека стандартных
// шаблонов (stl) C++ #17
// https://youtu.be/Ubj_c8Ho2JU

// Поиск минимального элемента | min_element c++ | Библиотека стандартных
// шаблонов (stl) C++ #18
// https://youtu.be/H91B_tglBaQ

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<int> v = {10, 1, -33, 11, 13, 58};
  auto result = max_element(v.begin(), v.end());
  cout << *result << endl;

  list<int> lst = {4, 7, 77, -3, 44, 74};
  auto result2 = max_element(lst.begin(), lst.end());
  cout << *result2 << endl;

  const int SIZE = 6;
  int arr[SIZE] = {10, 1, -55, 11, 13, 88};
  auto result3 = max_element(arr, arr + SIZE);
  cout << *result3 << endl;

  cout << endl;

  auto result4 = min_element(v.begin(), v.end());
  cout << *result4 << endl;

  auto result5 = min_element(lst.begin(), lst.end());
  cout << *result5 << endl;

  auto result6 = min_element(arr, arr + SIZE);
  cout << *result6 << endl;

  cout << endl;

  auto result7 = minmax_element(arr, arr + SIZE);
  cout << "min: " << *result7.first << " max: " << *result7.second << endl;

  return 0;
}

/*

*/
