#include <iostream>

void StaticMassive() {
  // Статичный Двумерный массив
  const int ROW = 3;
  const int COL = 4;
  int arr_static_1[ROW][COL];
  int arr_static_2[ROW][COL] = {{2, 4, 6, 7}, {34, 2, 67, 4}, {11, 4, 7, 2}};
  int arr_static_3[][COL] = {{2, 4, 6, 7}, {34, 2, 67, 4}, {11, 4, 7, 2}};

  // Заполнение данными статичного двумерного массива
  int arr_static_4[ROW][COL];
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      arr_static_4[i][j] = rand() % 10;
    }
  }

  // Вывод данных статичного двумерного массива
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      std::cout << arr_static_4[i][j] << "\t";
    }
    std::cout << std::endl;
  }
}

void DynamicMassive() {
  // Динамический Двумерный массив
  int rows = 4;
  int cols = 5;

  // Создаем
  int** arr = new int*[rows];
  for (int i = 0; i < rows; i++) {
    arr[i] = new int[cols];
  }
  // Заполняем
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      arr[i][j] = rand() % 10;
    }
  }
  // Вывод данных
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      std::cout << arr[i][j] << "\t";
    }
    std::cout << std::endl;
  }
  // Очищаем
  for (int i = 0; i < rows; i++) {
    delete[] arr[i];
  }
  delete[] arr;
}

int main() {
  StaticMassive();

  std::cout << std::endl;

  DynamicMassive();

  return 0;
}
