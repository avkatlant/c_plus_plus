// array STL C++ | | Библиотека стандартных шаблонов (stl) | Уроки | C++ | #6
// https://youtu.be/mEJ6Y2N6kmU

#include <array>
#include <iostream>

using namespace std;

// array - реализован на основе статического массива

int main() {
  array<int, 4> arr = {345, 65, 3, 7};

  try {
    // cout << arr[10] << endl; // неопределенное поведение, как и у вектора
    cout << arr.at(10) << endl;  // выбросит исключение

  } catch (const std::exception& e) {
    std::cerr << e.what() << endl;
    ;
  }

  cout << endl;

  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << "  ";
  }
  cout << endl;

  for (auto el : arr) {
    cout << el << "  ";
  }
  cout << endl << endl;

  arr.fill(-1);  // заполняем массив конкретными значениями

  arr.front();  // Доступ к первому элементу массива
  arr.back();  // Доступ к последнему элементу массива

  return 0;
}

/*

*/
