// Перегрузка функций c++ пример.Что такое перегрузка функций. Как перегрузить
// функцию. Урок #40

#include <iostream>

using namespace std;

int Sum(int a, int b) { return a + b; }

int Sum(int a, int b, int c) { return a + b + c; }

double Sum(double a, double b) { return a + b; }

int main() {
  cout << Sum(4, 6) << endl;
  cout << Sum(4, 6, 4) << endl;
  cout << Sum(6.3, 2.9) << endl;

  return 0;
}
