// Чисто виртуальный деструктор c++. Наследование. Полиморфизм. virtual.
// override. Для начинающих 106
// https://youtu.be/jyaxGwOHFJ4

#include <string.h>

#include <iostream>

using namespace std;

// Абстрактный класс
class A {
 public:
  A() { cout << "class A - Dynamic memory is allocated." << endl; }

  // Чисто виртуальный деструктор
  virtual ~A() = 0;
};

// Выносим определение деструктора в не класса
A::~A() { cout << "class A - Dynamic memory has been released." << endl; }

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

  // ССылка на классы наследники
  A *aptr = new B;
  delete aptr;

  return 0;
}
