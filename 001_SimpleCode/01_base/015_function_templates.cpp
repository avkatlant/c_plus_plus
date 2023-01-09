// Шаблоны функций. Шаблонные функции c++. template typename. template class.
// Урок #41

#include <iostream>

using namespace std;

template <typename T>
T Sum(T a, T b) {
  return a + b;
}

template <typename T1, typename T2>
T1 Sum(T1 a, T2 b) {
  return a + b;
}

int main() {
  cout << Sum(5, 10) << endl;
  cout << Sum(5.4, 10.9) << endl;

  cout << Sum(5, 10.9) << endl;

  return 0;
}
