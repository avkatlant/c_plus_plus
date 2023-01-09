// accumulate c++ | сумма и произведение элементов массива | Библиотека (stl)
// C++ #19
// https://youtu.be/kxYJkyQuYQU

#include <algorithm>
#include <iostream>
#include <list>
#include <numeric>  // <-
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<int> v = {10, 1, -33, 11, 13, 58};
  list<int> lst = {4, 7, 77, -3, 44, 74};
  const int SIZE = 6;
  int arr[SIZE] = {10, 1, -55, 11, 13, 88};

  auto res = accumulate(v.begin(), v.end(), 0);
  cout << res << endl;
  auto res2 = accumulate(lst.begin(), lst.end(), 0);
  cout << res2 << endl;
  auto res3 = accumulate(arr, arr + SIZE, 0);
  cout << res3 << endl;

  cout << endl;

  // begin()
  // end()

  auto res4 = accumulate(begin(v), end(v), 0);
  cout << res4 << endl;

  // Если мы незнаем количество элементов динамического массива
  int arr2[] = {10, 1, -55, 11, 13, 88};
  auto res5 = accumulate(begin(arr2), end(arr2), 0);
  cout << res5 << endl;

  cout << endl;

  // Изменяем поведение
  auto res6 =
      accumulate(begin(arr2), end(arr2), 1, [](int a, int b) { return a * b; });
  cout << res6 << endl;

  cout << endl;

  string res7 =
      accumulate(next(begin(arr2)), end(arr2), to_string(arr2[0]),
                 [](string a, int b) { return a + " - " + to_string(b); });
  cout << res7 << endl;

  return 0;
}

/*

*/
