// Шаблоны классов с++ примеры. Обобщенные классы. Изучение С++ для начинающих.
// Урок 126
// https://youtu.be/SDRMUgJwro0

#include <string.h>

#include <iostream>

using namespace std;

class Point {
 public:
  double x;
  double y;
  double z;

  Point() { x = y = z = 0; }
};

template <typename T>
class MyClass {
 public:
  MyClass(T value) { this->value = value; }

  void DataTypeSize() { cout << sizeof(value) << endl; }

  T Foo() { return value; }

 private:
  T value;
};

template <typename T1, typename T2>
class MyClass2 {
 public:
  MyClass2(T1 value, T2 value2) {
    this->value = value;
    this->value2 = value2;
  }

  void DataTypeSize() {
    cout << "value = " << sizeof(value) << endl;
    cout << "value2 = " << sizeof(value2) << endl;
  }

  T1 Foo() { return value; }

 private:
  T1 value;
  T2 value2;
};

int main() {
  int a = 5;
  MyClass<int> c(a);
  c.DataTypeSize();

  double b = 4.35;
  MyClass<double> f(b);
  f.DataTypeSize();

  Point n;
  MyClass<Point> s(n);
  s.DataTypeSize();

  cout << endl;

  int r = 2;
  Point p;
  MyClass2<int, Point> k(r, p);
  k.DataTypeSize();

  return 0;
}

/*
4
8
24

value = 4
value2 = 24
*/
