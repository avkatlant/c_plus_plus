// STL unique | Удалить повторяющиеся элементы | Библиотека стандартных шаблонов
// (stl) C++ #23
// https://youtu.be/f_Faa9bljjA

#include <string.h>

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

// unique - оставляет только уникальные элементы.

// unique_copy - оставляет только уникальные элементы и копирует их в новый
// контейнер.

int main() {
  int arr[] = {1, 2, 2, 2, 5, 4, 4, 6};

  auto it = unique(begin(arr), end(arr));
  // unique - сортирует элементы таким образом, что повторы
  // переносится в конец.
  // it - итератор указывает на границу
  for_each(begin(arr), it, [](int a) { cout << a << "  "; });  // 1  2  5  4  6

  cout << endl << endl;

  vector<int> v = {1, 2, 2, 2, 5, 4, 4, 6};

  auto it2 = unique(begin(v), end(v));
  v.erase(it2, v.end());  // Удаляем повторяющиеся элементы
  for (auto el : v) {
    cout << el << "  ";
  }

  cout << endl << endl;

  list<int> v2;
  unique_copy(begin(v), end(v), back_inserter(v2));
  for (auto el : v2) {
    cout << el << "  ";
  }

  return 0;
}

/*

*/
