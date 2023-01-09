// Перегрузка инкремента и декремента. Постфиксного и префиксного.

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

  // префиксного форма
  Point& operator++() {
    this->x++;
    this->y++;
    return *this;
  }

  // Постфиксного форма
  // у этой формы самый низкий приоритет
  Point operator++(int value) {
    Point temp(*this);
    this->x++;
    this->y++;
    return temp;
  }

  void Print() {
    cout << this->x << endl;
    cout << this->y << endl;
  }
};

int main() {
  Point a(5, 1);

  ++a;
  a.Print();

  Point b = a++;
  b.Print();

  return 0;
}
