// Захват контекста лямбдой | Лямбда функции | Лямбда-выражения | Анонимные
// функции | Урок 144
// https://youtu.be/m3WgGSVmNcs

#include <functional>
#include <iostream>
#include <vector>

using namespace std;

class MyClass {
 public:
  int a = 11;

  void Msg() { cout << "msg" << endl; }

  void Lampda() {
    // Захватываем из контекста весь класс
    auto f = [this]() { this->Msg(); };
    f();
  }
};

int main() {
  int a = 55;
  int b = 10;

  auto f1 = [&a, b]() {
    // [=] - захватываем все переменные в контексте по значению, и присваивать
    // новые значения переменным внутри lambda мы уже не можем.
    // [&] - захватываем все переменные в контексте по ссылке
    a = 23424;
    cout << "Lambda - " << a << endl;
    cout << "Lambda - " << b << endl;
  };
  f1();

  cout << endl;

  auto f2 = [=]() mutable {
    // [a, b]() mutable или [=]() mutable - захватываем все переменные в
    // контексте по значению, и присваивать новые значения переменным внутри
    // lambda мы можем.
    a = 23424;
    b = 432;
    cout << "Lambda - " << a << endl;
    cout << "Lambda - " << b << endl;
  };
  f2();

  cout << endl;

  auto f3 = [&a, b]() mutable {
    // переменная "b" поменяет значение только внутри lambda
    a = 23424;
    b = 432;
    cout << "Lambda - " << a << endl;
    cout << "Lambda - " << b << endl;
  };
  f3();

  cout << endl;

  MyClass m;
  m.Lampda();

  cout << endl;

  // Жестко указываем тип возвращаемого значения
  auto f4 = []() -> double { return 1.45; };
  auto result = f4();
  cout << "Lambda 4 - " << result << endl;

  return 0;
}
