// Модификаторы доступа при наследовании. private public protected Спецификаторы
// доступа. ООП. C++ #99
// https://youtu.be/6udKffus77A

#include <string.h>

#include <iostream>

using namespace std;

class A {
 public:
  // Эти поля доступны всем и везде.
  string msgOne = "Message One";

 private:
  // Только class A может работать с этими полями.
  string msgTwo = "Message Two";

 protected:
  // Через объект класса обратиться нельзя, но в наследниках доступ есть.
  string msgThree = "Message Three";
};

class B : public A {
 public:
  void PrintMsg() {
    cout << msgOne << endl;
    cout << msgThree << endl;
  }
};

// Если: class B : private A
// То: в class A public -> private и protected -> private

// Если: class B : protected A
// То: в class A public -> protected

int main() {
  B b;
  b.PrintMsg();

  return 0;
}
