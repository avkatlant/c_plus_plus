// Изменить размер массива. Удалить. Добавить элемент в массив.
// Увеличение массива
// https://youtu.be/fzNksn5wPTg

#include <iostream>

void FillArray(int* const arr, const int size) {
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % 10;
  }
}

void ShowArray(const int* const arr, const int size) {
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << "  ";
  }
  std::cout << std::endl;
}

void push_back(int*& arr, int& size, const int value) {
  // int*& arr - адрес указателя, который указывает на динамический массив

  int* newArray = new int[size + 1];
  for (int i = 0; i < size; i++) {
    newArray[i] = arr[i];
  }
  newArray[size] = value;
  size++;
  delete[] arr;
  arr = newArray;
}

void pop_back(int*& arr, int& size) {
  size--;
  int* newArray = new int[size];
  for (int i = 0; i < size; i++) {
    newArray[i] = arr[i];
  }
  delete[] arr;
  arr = newArray;
}

int main() {
  int size = 5;
  int* arr = new int[size];

  FillArray(arr, size);
  ShowArray(arr, size);

  push_back(arr, size, 111);
  ShowArray(arr, size);

  pop_back(arr, size);
  pop_back(arr, size);
  ShowArray(arr, size);

  delete[] arr;
  return 0;
}
