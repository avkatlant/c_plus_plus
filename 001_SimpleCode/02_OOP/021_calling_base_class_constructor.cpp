// Вызов конструктора базового класса из конструктора класса-наследника.
// Наследование. ООП C++ 102
// https://youtu.be/3Z_Xj2KfsFU

#include <string.h>

#include <iostream>

using namespace std;

class A {
 public:
  A() {
    cout << "The class A constructor 1 was called." << endl;
    msg = "Empty message";
  }

  A(string msg) {
    cout << "The class A constructor 2 was called." << endl;
    this->msg = msg;
  }

  void PrintMsg() { cout << msg << endl; }

 private:
  string msg;
};

class B : public A {
 public:
  // Компилятор по умолчанию вызывает конструктор по умолчанию
  // B() : A() { cout << "The class B constructor was called." << endl; }

  // Вызываем нужный нам конструктор
  B() : A("New message") {
    cout << "The class B constructor was called." << endl;
  }
};

int main() {
  B b;
  b.PrintMsg();

  return 0;
}

/*
The class A constructor 2 was called.
The class B constructor was called.
New message
*/
