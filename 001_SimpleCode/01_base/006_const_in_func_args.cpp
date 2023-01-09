#include <iostream>

void FillArray(int* const arr, const int size) {
  // const - параметры становятся константами
  // int* const arr - указатель не получится поменять
  // const int size - значение переменной не получится изменить
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % 10;
  }
}

void ShowArray(const int* const arr, const int size) {
  // const int* const arr - присвоить значения в массив не получится
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << "\t";
  }
}

int main() { return 0; }
