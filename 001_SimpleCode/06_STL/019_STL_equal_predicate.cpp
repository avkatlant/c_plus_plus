// std equal predicate | Библиотека стандартных шаблонов (stl) C++ #21
// https://youtu.be/A5QHIZDXdMA

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

class Point {
 public:
  int x, y;

  Point(int x, int y) {
    this->x = x;
    this->y = y;
  }
};

int main() {
  vector<Point> arr1 = {
      Point(1, 3),
      Point(4, 5),
      Point(5, 7),
  };

  vector<Point> arr2 = {
      Point(1, 3),
      Point(4, 5),
      Point(5, 7),
  };

  bool res1 = equal(begin(arr1), end(arr1), begin(arr2), end(arr2),
                    [](const Point &p1, const Point &p2) {
                      return p1.x == p2.x && p1.y == p2.y;
                    });
  cout << res1 << endl;

  return 0;
}

/*

*/
