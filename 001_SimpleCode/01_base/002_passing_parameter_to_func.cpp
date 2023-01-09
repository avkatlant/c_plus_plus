// передача параметра в функцию

#include <iostream>

// по значению
void Foo(int a) {
  // внутри ф-ции создается новая переменная, того типа который параметр,
  // данные переменной копируются в новую переменную,
  // и мы работаем с локальной переменной
  a = 1;
}

// по ссылке
void Foo2(int &a) { a = 2; }

// по указателю
void Foo3(int *a) {
  // чтоб поменять значение переменной "a",
  // нужно разыменовать указатель "*a"
  *a = 3;
}

int main() {
  int value = 5;
  std::cout << "value = " << value << std::endl;  // value = 5

  Foo(value);
  std::cout << "Foo(value) = " << value << std::endl;  // Foo(value) = 5

  Foo2(value);
  std::cout << "Foo2(value) = " << value << std::endl;  // Foo2(value) = 2

  Foo3(&value);  // необходимо передать адрес ячейки
  std::cout << "Foo3(value) = " << value << std::endl;  // Foo3(value) = 3

  return 0;
}
