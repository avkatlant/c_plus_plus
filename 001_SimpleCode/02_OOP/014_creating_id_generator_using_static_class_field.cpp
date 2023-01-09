// id generator. Генератор уникальных идентификаторов с использованием static
// переменной Начинающим #93
// https://youtu.be/t05dMR4yB9s

#include <string.h>

#include <iostream>

using namespace std;

class Apple {
 private:
  int weight;
  string color;
  int id;

 public:
  static int Count;

  Apple(int weight, string color) {
    this->weight = weight;
    this->color = color;
    Count++;
    id = Count;
  }

  int GetId() { return id; }
};

int Apple::Count = 0;

int main() {
  Apple apple(150, "RED");
  Apple apple2(150, "Green");
  Apple apple3(150, "Yellow");

  cout << apple.GetId() << endl;
  cout << apple2.GetId() << endl;
  cout << apple3.GetId() << endl;

  return 0;
}
