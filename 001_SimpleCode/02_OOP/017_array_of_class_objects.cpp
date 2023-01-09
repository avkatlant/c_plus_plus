// Массив объектов класса. Динамический. Статический. Создание Особенности. ООП
// C++ Для начинающих #96
// https://youtu.be/gNtQ69x1VTM

#include <string.h>

#include <iostream>

using namespace std;

class Pixel {
 public:
  Pixel() { r = g = b = 0; }

  Pixel(int r, int g, int b) {
    this->r = r;
    this->g = g;
    this->b = b;
  }

  string GetInfo() {
    return "Pixel: r = " + to_string(r) + " g = " + to_string(g) +
           " b = " + to_string(b);
  }

 private:
  int r;
  int g;
  int b;
};

int main() {
  const int LENGTH = 5;

  // Статический массив объектов класса

  Pixel arr[LENGTH];
  arr[0] = Pixel(11, 159, 222);
  cout << arr[0].GetInfo() << endl << endl;

  Pixel arr2[LENGTH] = {Pixel(0, 4, 64), Pixel(4, 14, 10), Pixel(111, 4, 24),
                        Pixel(244, 244, 14), Pixel(111, 179, 64)};

  // Динамический массив объектов класса

  Pixel *arr3 = new Pixel[LENGTH];

  arr3[0] = Pixel(4, 14, 10);
  cout << arr3[0].GetInfo() << endl << endl;

  delete[] arr3;

  return 0;
}
