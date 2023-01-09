// Дружественные функции и классы пример. Для чего используются. Как
// определяются. Для двух классов
// Дружественный метод класса

#include <iostream>

using namespace std;

class Point;

class Test {
 private:
  int data = 0;

 public:
  void TakePoint(Point &point);

  friend void ChangeX(Point &value, Test &testValue);
};

class Point {
 private:
  int x;
  int y;

 public:
  Point() {
    x = 0;
    y = 0;
  }

  Point(int x, int y) {
    this->x = x;
    this->y = y;
  }

  void Print() {
    cout << this->x << endl;
    cout << this->y << endl;
  }

  // На дружественную ф-цию не распространяется правила private, protected,
  // public полей.
  friend void ChangeX(Point &value, Test &testValue);

  // Дружественный метод класса
  friend void Test::TakePoint(Point &point);
};

void ChangeX(Point &value, Test &testValue) {
  value.x = -1;
  testValue.data = 10;
}

// Дружественный метод класса
void Test::TakePoint(Point &point) { cout << point.x << endl; }

int main() {
  Point a(5, 1);
  a.Print();
  Test b;
  ChangeX(a, b);
  a.Print();

  b.TakePoint(a);

  return 0;
}
