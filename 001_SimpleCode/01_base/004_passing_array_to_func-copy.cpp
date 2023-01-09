// Передача массива в функцию. Как передать массив в функцию. C++ для
// начинающих. Урок #35.

#include <iostream>

using namespace std;

void FillArray(int arr[], const int size) {
  // int arr[] - передается указатель на массив

  for (int i = 0; i < size; i++) {
    arr[i] = rand() % 10;
  }
}

void PrintArray(int arr[], const int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << "  ";
  }
  cout << endl;
}

int main() {
  const int SIZE = 10;
  int arr[SIZE];

  FillArray(arr, SIZE);
  PrintArray(arr, SIZE);

  return 0;
}
