// Что такое null pointer. null c++ что это. nullptr c++ что это. nullptr c++11.
// Урок #54

#include <iostream>

using namespace std;

int main() {
  int *pa = new int(5);

  // Удаляем данные в памяти
  delete pa;

  // Затираем указатель
  pa = 0;
  pa = NULL;  // тоже самое что и pa = 0;
  pa = nullptr;
  // nullptr - это отдельный тип данных.
  // Компилятор ни когда не перепутает с NULL и 0.

  return 0;
}
