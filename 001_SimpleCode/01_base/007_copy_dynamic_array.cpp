// Копирование динамического массива

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
}

int main() {
  int size = 10;
  int* firstArray = new int[size];
  int* secondArray = new int[size];

  FillArray(firstArray, size);
  FillArray(secondArray, size);

  ShowArray(firstArray, size);
  std::cout << std::endl;
  ShowArray(secondArray, size);

  std::cout << std::endl << "***********************" << std::endl;

  delete[] firstArray;

  firstArray = new int[size];
  for (int i = 0; i < size; i++) {
    firstArray[i] = secondArray[i];
  }

  std::cout << firstArray << "\t";
  ShowArray(firstArray, size);
  std::cout << std::endl;
  std::cout << secondArray << "\t";
  ShowArray(secondArray, size);

  delete[] firstArray;
  delete[] secondArray;
  return 0;
}

// 7  9  3  8  0  2  4  8  3  9
// 0  5  2  2  7  3  7  9  0  2
// ***********************
// 0x7ffe25d05820  0  5  2  2  7  3  7  9  0  2
// 0x7ffe25d05850  0  5  2  2  7  3  7  9  0  2
