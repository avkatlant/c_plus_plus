#include <iostream>

// Массив находится в непрерывной области памяти, все его ячейки идут подряд.

int main() {
  // Статичный массив
  int arr_static[4];    // Заполнен мусором;
  int arr_static[4]{};  // Заполнен нулями.
  int arr_static[4]{1, 3, 4, 5};
  int arr_static[]{1, 3, 4, 5};

  // Динамический массив
  int size = 10;
  int *arr = new int[size];

  for (int i = 0; i < size; i++) {
    arr[i] = rand() % 10;
  }

  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << "\t";
    std::cout << arr + i << std::endl;
  }

  delete[] arr;  // Очищаем данные динамического массива.

  return 0;
}
