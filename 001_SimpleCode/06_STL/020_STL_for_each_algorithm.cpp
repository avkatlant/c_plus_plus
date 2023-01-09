// Алгоритм for_each c++ | Библиотека стандартных шаблонов (stl) C++ #22
// https://youtu.be/zXVSvhr9LgI

#include <string.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void Foo(int a) { cout << a << endl; }

int main() {
  int arr[] = {5, 4, 36, 7, 6, 43};

  for_each(begin(arr), end(arr), Foo);

  cout << endl;

  for_each(begin(arr), end(arr), [](int a) { cout << a << endl; });

  cout << endl;

  // меняем элементы массива
  for_each(begin(arr), end(arr), [](int &a) {
    a++;
    cout << a << endl;
  });

  return 0;
}

/*

*/
