// Наследование в ООП пример. Что такое наследование. Для чего нужно
// наследование классов. ООП. C++ #98
// https://youtu.be/O7ruEWCa7zc

#include <string.h>

#include <iostream>

using namespace std;

class Human {
 private:
  string name = "Ivan";

 public:
  string GetName() { return name; }

  void SetName(string name) { this->name = name; }
};

class Student : public Human {
 public:
  string group;

  void Learn() { cout << "I am learn." << endl; }
};

class ExtramuralStudent : public Student {
 public:
  void Learn() { cout << "I am learn Extramural." << endl; }
};

class Professor : public Human {
 public:
  string subject;
};

int main() {
  Student st;
  st.Learn();
  st.SetName("John");
  cout << st.GetName() << endl;

  ExtramuralStudent est;
  est.Learn();
  est.SetName("Sandy");
  cout << est.GetName() << endl;

  return 0;
}
