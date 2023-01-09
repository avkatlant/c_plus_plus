// Виртуальный деструктор класса C++. Что это такое. Наследование. Полиморфизм.
// Для начинающих 105
// https://youtu.be/JypBB4J0XrY

#include <string.h>

#include <iostream>

using namespace std;

class A {
 public:
  A() { cout << "class A - Dynamic memory is allocated." << endl; }

  virtual ~A() {
    cout << "class A - Dynamic memory has been released." << endl;
  }
};

class B : public A {
 public:
  B() { cout << "class B - Dynamic memory is allocated." << endl; }

  ~B() override {
    cout << "class B - Dynamic memory has been released." << endl;
  }
};

int main() {
  B *bptr = new B;
  delete bptr;

  cout << endl;

  // Виртуальный деструктор нужен для корректного освобождения ресурсов классов
  // наследников, в случае если мы будем использовать указатель базового класса
  // для хранения ссылок на классы наследники.
  A *aptr = new B;
  delete aptr;

  return 0;
}
