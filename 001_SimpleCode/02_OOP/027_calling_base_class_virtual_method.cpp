// c++ вызов виртуального метода базового класса. ООП. Изучение с++ с нуля. Для
// начинающих. Урок 108
// https://youtu.be/0C7O7gpSxYw

#include <string.h>

#include <iostream>

using namespace std;

class Msg {
 private:
  string msg;

 public:
  Msg(string msg) { this->msg = msg; }

  virtual string GetMsg() { return msg; }
};

class Printer {
 public:
  void Print(Msg *msg) { cout << msg->GetMsg() << endl; }
};

class BraketstMsg : public Msg {
 public:
  BraketstMsg(string msg) : Msg(msg) {}

  // Если не укажем что должен вызываться метод GetMsg базового класса, то
  // GetMsg будет вызываться рекурсивно.
  // ::Msg::GetMsg() - указываем что метод GetMsg базового класса.
  string GetMsg() override { return "[" + ::Msg::GetMsg() + "]"; }
};

int main() {
  BraketstMsg m("Hello");
  Printer p;
  p.Print(&m);

  return 0;
}
