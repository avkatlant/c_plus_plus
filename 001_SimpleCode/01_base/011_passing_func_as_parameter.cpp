// Указатель на функцию в качестве параметра.
// Передача функции в качестве параметра
// https://youtu.be/_6eG9Q40lFM

#include <iostream>

void Foo1() { std::cout << "void Foo 1()" << std::endl; }
void Foo2(int a) { std::cout << "void Foo 2() " << a << std::endl; }

std::string GetDataFromDB() { return "Data from DB"; }
std::string GetDataFromWebServer() { return "Data from WebServer"; }

void ShowInfo(std::string (*foo)()) { std::cout << foo() << std::endl; }

int main() {
  // тип функции(*имя указателя(спецификация параметров));
  void (*fooPointer1)();
  void (*fooPointer2)(int a);

  fooPointer1 = Foo1;
  fooPointer1();
  fooPointer2 = Foo2;
  fooPointer2(5);

  std::cout << std::endl;

  ShowInfo(GetDataFromDB);
  ShowInfo(GetDataFromWebServer);

  return 0;
}

// void Foo 1()
// void Foo 2() 5

// Data from DB
// Data from WebServer
