#include <iostream>

using namespace std;

class Point {
 private:
  int x;
  int y;

 public:
  int GetX() { return x; }
  void SetX(int valueX) { x = valueX; }

  void Print() {
    cout << "x = " << x << "\n"
         << "y = " << y << endl;
  }
};

int main() {
  Point a;
  a.SetX(5);
  a.Print();
  cout << a.GetX() << endl;

  return 0;
}
