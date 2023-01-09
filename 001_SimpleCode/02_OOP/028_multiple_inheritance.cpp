// Множественное наследование c++ пример. ООП. Изучение С++ с нуля для
// начинающих. Урок 109
// https://youtu.be/QEuR9GIdrZY

// Порядок вызова конструкторов при множественном наследовании. ООП. С++
// начинающих. Урок 110
// https://youtu.be/0LnCYMZqWwE

// Порядок вызова деструкторов при множественном наследовании. ООП. С++
// начинающих. Урок 111
// https://youtu.be/WBt2Gsfz6WA

// С++ множественное наследование одинаковые методы. ООП. Изучение С++ для
// начинающих. Урок 112
// https://youtu.be/2a2aC_5SGFE

#include <string.h>

#include <iostream>

using namespace std;

class Car {
 public:
  Car() { cout << "Constructor Car" << endl; }

  ~Car() { cout << "Destructor Car" << endl; }

  string str1 = "Field car class.";

  void Drive() { cout << "I'm drive!" << endl; }

  void Use() { cout << "class Car - I'm Use!" << endl; }
};

class Airplane {
 public:
  Airplane() { cout << "Constructor Airplane" << endl; }

  ~Airplane() { cout << "Destructor Airplane" << endl; }

  string str2 = "Field airplane class.";

  void Fly() { cout << "I'm fly!" << endl; }

  void Use() { cout << "class Airplane - I'm Use!" << endl; }
};

class FlyingCar : public Car, public Airplane {
 public:
  FlyingCar() { cout << "Constructor FlyingCar" << endl; }

  ~FlyingCar() { cout << "Destructor FlyingCar" << endl; }
};

int main() {
  // Car c;
  // c.Drive();

  // Airplane a;
  // a.Fly();

  // cout << endl;

  FlyingCar fc;
  fc.Drive();
  fc.Fly();

  // Указатель на базовый класс может хранить ссылку на любой класс наследника
  // Car *ptrC = &fc;
  // Airplane *ptrA = &fc;

  cout << endl;

  // Указываем явно из какого родительского класса на нужно взять унаследованный
  // метод Use
  ((Car)fc).Use();
  ((Airplane)fc).Use();

  cout << endl;

  return 0;
}
