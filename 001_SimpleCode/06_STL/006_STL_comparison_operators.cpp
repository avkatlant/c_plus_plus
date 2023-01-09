// Контейнеры STL и операторы сравнения. | Библиотека стандартных шаблонов (stl)
// | Уроки | C++ | #7
// https://youtu.be/K_1qCfGW5Fo

#include <array>
#include <iostream>

using namespace std;

int main() {
  array<int, 4> arr = {5435, 554, 765, 3};
  array<int, 4> arr2 = {5435, 554, 765, 1};

  bool result = (arr > arr2);

  cout << result << endl;

  return 0;
}

/*

*/
