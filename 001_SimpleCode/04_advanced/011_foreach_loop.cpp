// Цикл foreach C++ | range-based циклы | Изучение С++ для начинающих. Урок 137
// https://youtu.be/j0_0699UZF4

#include <string.h>

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int arr[] = {5, 4, 36, 7, 6, 43};

  // В переменную var копируются данные по значению.
  for (auto var : arr) {
    cout << var << endl;
  }

  // В переменную var копируются данные по ссылке.
  for (auto &var : arr) {
    cout << var << endl;
  }

  // Запрещаем изменять элемент
  for (const auto &var : arr) {
    cout << var << endl;
  }

  return 0;
}

/*

*/
