// Перегрузка оператора равенства == и не равно !=. Перегрузка логических
// операторов сравнения

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

  bool operator==(const Point& other) {
    return this->x == other.x && this->y == other.y;
  }

  bool operator!=(const Point& other) {
    return !(this->x == other.x && this->y == other.y);
  }
};

int main() {
  Point a(5, 1);
  Point b(5, 1);

  bool result1 = a == b;
  cout << result1 << endl;

  bool result2 = a != b;
  cout << result2 << endl;

  return 0;
}
