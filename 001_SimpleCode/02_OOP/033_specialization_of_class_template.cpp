// Специализация шаблона класса. Изучение С++ для начинающих. Урок 128
// https://youtu.be/_kJJoWDNvxM

#include <string.h>

#include <iostream>

using namespace std;

template <typename T>
class Printer {
 public:
  void Print(T value) { cout << value << endl; }
};

// Создаем специализированный шаблон для типа string
template <>
class Printer<string> {
 public:
  void Print(string value) { cout << "_____ " << value << endl; }
};

int main() {
  Printer<int> i;
  i.Print(4567);

  cout << endl;

  Printer<string> s;
  s.Print("Hello World!");

  return 0;
}

/*
4567

_____ Hello World!
*/
