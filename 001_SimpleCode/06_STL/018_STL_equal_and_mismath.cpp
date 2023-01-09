// STL equal и mismatch | Сравнение массивов | Библиотека стандартных шаблонов
// (stl) C++ #20
// https://youtu.be/mJ2GYvk0Btg

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

int main() {
  // //
  // equal - проверяет на равенство две последовательности.
  // //

  int arr1[] = {10, 1, -55, 11, 13, 88};
  int arr2[] = {10, 1, -55, 11, 13, 88};

  bool res1 = equal(begin(arr1), end(arr1), begin(arr2));
  // Если arr2 будет иметь ещё один элемент, то все ровно будет true
  cout << res1 << endl;

  cout << endl;

  int arr3[] = {10, 1, -55, 11, 13, 88};
  int arr4[] = {10, 1, -55, 11, 13, 88, 67};

  bool res2 = equal(begin(arr3), end(arr3), begin(arr4), end(arr4));
  cout << res2 << endl;

  cout << endl;

  // можно сравнивать коллекции
  int arr5[] = {10, 1, -55, 11, 13, 88};
  vector<int> v1 = {10, 1, -55, 11, 13, 88};
  bool res3 = equal(begin(arr5), end(arr5), begin(v1), end(v1));
  cout << res3 << endl;

  cout << endl;

  // //
  // mismatch - проверяет на равенство две последовательности,
  // и если есть несоответствие, то вернет пару итераторов указывающие на эти
  // элементы.
  // //

  vector<int> v2 = {10, 1, -55, 11, 13, 88};
  vector<int> v3 = {10, 2, -55, 11, 13, 88};
  auto it1 = mismatch(begin(v2), end(v2), begin(v3), end(v3));
  cout << *it1.first << endl;
  cout << *it1.second << endl;

  return 0;
}

/*

*/
