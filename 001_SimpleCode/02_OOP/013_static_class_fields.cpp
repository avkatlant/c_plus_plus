// static что это. Статические поля класса. Инициализация. Ключевое слово
// static. C++ #92
// https://youtu.be/Mlc9vyFdHE8

#include <string.h>

#include <iostream>

using namespace std;

class Apple {
 private:
  int weight;
  string color;

 public:
  // Статическая переменная одна на все экземпляры класса!
  static int Count;

  Apple(int weight, string color) {
    this->weight = weight;
    this->color = color;
    Count++;
  }
};

// Инициализируем статическую переменную вне класса!
int Apple::Count = 0;

int main() {
  Apple apple(150, "RED");
  Apple apple2(150, "Green");
  Apple apple3(150, "Yellow");

  cout << apple.Count << endl;
  cout << apple2.Count << endl;
  cout << apple3.Count << endl;

  // Обращение к статическим полям класса
  cout << Apple::Count << endl;

  return 0;
}
