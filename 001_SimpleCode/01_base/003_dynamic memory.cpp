#include <iostream>

int main() {
  int *pa = new int;  // Выделение динамической памяти (в Heap).

  *pa = 10;  // разыменовываем указатель.
  std::cout << *pa << std::endl;

  delete pa;  // Очищение данных в динамической памяти.

  pa = nullptr;  // Затираем адрес.

  return 0;
}
