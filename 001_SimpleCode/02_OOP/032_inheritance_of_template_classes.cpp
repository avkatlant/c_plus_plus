// Наследование шаблонных классов. Изучение С++ для начинающих. Урок 127
// https://youtu.be/n6GMKC40gC0

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
class TypeSize {
 public:
  TypeSize(T value) { this->value = value; }

  void DataTypeSize() { cout << sizeof(value) << endl; }

  T Foo() { return value; }

 protected:
  T value;
};

template <typename T1>
class TypeInfo : public TypeSize<T1> {
 public:
  TypeInfo(T1 value) : TypeSize<T1>(value) {}

  void ShowTypeName() {
    cout << "Type name: " << typeid(this->value).name() << endl;
    ;
  }
};

int main() {
  double a = 2;
  TypeInfo<double> c(a);
  c.DataTypeSize();
  c.ShowTypeName();

  cout << endl;

  int b = 2;
  TypeInfo<int> w(b);
  w.DataTypeSize();
  w.ShowTypeName();

  cout << endl;

  Point p;
  TypeInfo<Point> n(p);
  n.DataTypeSize();
  n.ShowTypeName();

  return 0;
}

/*
8
Type name: d

4
Type name: i

24
Type name: 5Point
*/
