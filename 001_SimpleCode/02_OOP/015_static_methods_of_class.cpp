// Статические методы класса зачем нужны. Модификатор static. Как влияет. ООП.
// Для начинающих. Урок #94
// https://youtu.be/aNilqhdlDXQ

#include <string.h>

#include <iostream>

using namespace std;

class Apple {
 private:
  int weight;
  string color;
  int id;
  static int Count;

 public:
  Apple(int weight, string color) {
    this->weight = weight;
    this->color = color;
    Count++;
    id = Count;
  }

  int GetId() { return id; }

  // Статический метод один на все экземпляры класса!
  static int GetCount() {
    // внутри можем использовать только статические поля
    return Count;
  }

  // Если нам надо менять какое-то свойство экземпляра через статический метод
  static void ChangeColor(Apple &apple, string color) { apple.color = color; }
};

int Apple::Count = 0;

int main() {
  Apple apple(150, "RED");
  Apple apple2(150, "Green");
  Apple apple3(150, "Yellow");

  // Обращаемся к статичному методу класса через экземпляр
  cout << apple.GetCount() << endl;
  cout << apple2.GetCount() << endl;
  cout << apple3.GetCount() << endl;

  // Обращаемся к статичному методу класса
  cout << Apple::GetCount() << endl;

  apple.ChangeColor(apple2, "grey");
  // или
  Apple::ChangeColor(apple2, "grey");

  return 0;
}
