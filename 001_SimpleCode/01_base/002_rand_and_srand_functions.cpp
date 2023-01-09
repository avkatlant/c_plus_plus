// переменные, указатели, ссылки

// #include <ctime>
#include <iostream>

using namespace std;

int main() {
  // srand(25);
  srand(time(NULL));  // чтоб rand генерировал разные числа

  int a = rand();
  cout << a << endl;

  // Генерируем от 0 до 10
  int b = rand() % 10;
  cout << b << endl;

  // Генерируем от 5 до 15
  int c = rand() % 10 + 5;
  cout << c << endl;

  return 0;
}
