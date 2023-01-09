// Перегрузка оператора сложения.

#include <iostream>

using namespace std;

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

  Point operator+(const Point &other) {
    Point temp;
    temp.x = this->x + other.x;
    temp.y = this->y + other.y;

    return temp;
  }

  void Print() {
    cout << this->x << endl;
    cout << this->y << endl;
  }
};

int main() {
  Point a(5, 1);
  Point b(5, 1);

  Point c = a + b;
  c.Print();

  return 0;
}
