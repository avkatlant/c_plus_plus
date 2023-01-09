// std::function | Полиморфная обёртка функции | Изучение С++ для начинающих.
// Урок 142
// https://youtu.be/Bm2jmUxkUVw

#include <functional>
#include <iostream>
#include <vector>

using namespace std;

// Объект класса std::function может хранить, копировать любой вызываемый
// объект.

void Ex1() { cout << "Ex1 was called" << endl; }
void Ex2() { cout << "Ex2 was called" << endl; }
int Sum(int a, int b) { return a + b; }

void Foo(int a) {
  if (a > 10 && a < 40) {
    cout << "Foo - " << a << endl;
  }
}

void Bar(int a) {
  if (a % 2 == 0) {
    cout << "Bar - " << a << endl;
  }
}

void DoWork(vector<int> &vc, function<void(int)> f) {
  for (auto el : vc) {
    f(el);
  }
}

// Передаем различное количество функций
void DoWork2(vector<int> &vc, vector<function<void(int)>> funcVector) {
  for (auto el : vc) {
    for (auto &fel : funcVector) {
      fel(el);
    }
  }
}

int main() {
  function<void()> f;
  f = Ex1;
  f();
  f = Ex2;
  f();

  function<int(int, int)> f2;
  f2 = Sum;
  cout << f2(2, 4) << endl;

  cout << endl;

  vector<int> vc = {1, 51, 4, 10, 44, 98, 8, 12, 22, 29, 49};
  DoWork(vc, Foo);
  cout << endl;
  DoWork(vc, Bar);

  cout << endl;
  cout << endl;

  vector<function<void(int)>> fVector;
  fVector.emplace_back(Foo);
  fVector.emplace_back(Bar);
  DoWork2(vc, fVector);

  return 0;
}
