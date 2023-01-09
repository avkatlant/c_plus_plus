// Лямбда-выражения | Лямбда функции | Анонимные функции | Изучение С++ для
// начинающих. Урок 143
// https://youtu.be/bP5GJN3-zIo

#include <functional>
#include <iostream>
#include <vector>

using namespace std;

void DoWork(vector<int> &vc, function<void(int)> f) {
  for (auto el : vc) {
    f(el);
  }
}

int main() {
  vector<int> vc = {1, 51, 4, 10, 44, 98};

  function<void(int)> f;

  f = [](int a) { cout << "Lambda func was called - " << a << endl; };

  DoWork(vc, f);

  cout << endl;

  DoWork(vc, [](int a) { cout << "Lambda func was called - " << a << endl; });

  cout << endl;

  DoWork(vc, [](int a) {
    if (a % 2 == 0) {
      cout << "lambda - " << a << endl;
    }
  });

  cout << endl;

  int p = 0;
  auto f2 = [&p]() {
    p = 5;
    cout << "Lambda 2 - " << p << endl;
  };
  f2();

  cout << endl;

  auto f3 = []() { return 1.4234; };
  auto q = f3();
  cout << "lambda 3 - " << q << endl;

  return 0;
}
