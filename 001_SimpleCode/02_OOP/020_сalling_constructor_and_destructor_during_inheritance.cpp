// Порядок вызова конструкторов при наследовании. Как вызываются конструкторы.
// ООП C++ Начинающим 100
// https://youtu.be/sNInKQgUZMA
// Порядок вызова деструкторов при наследовании. Деструкторы. ООП C++ Для
// начинающих. Урок 101
// https://youtu.be/S_owqPD5dVk

#include <string.h>

#include <iostream>

using namespace std;

class A {
 public:
  A() { cout << "The class A constructor was called." << endl; }

  ~A() { cout << "The class A destructor was called." << endl; }
};

class B : public A {
 public:
  B() { cout << "The class B constructor was called." << endl; }

  ~B() { cout << "The class B destructor was called." << endl; }
};

class C : public B {
 public:
  C() { cout << "The class C constructor was called." << endl; }

  ~C() { cout << "The class C destructor was called." << endl; }
};

int main() {
  // A a;
  // B b;
  C c;

  return 0;
}

/*
The class A constructor was called.
The class B constructor was called.
The class C constructor was called.
The class C destructor was called.
The class B destructor was called.
The class A destructor was called.
*/
