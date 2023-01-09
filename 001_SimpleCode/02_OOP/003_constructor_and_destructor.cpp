#include <iostream>

using namespace std;

class Point {
 private:
  int z;
  int x;
  int y;
  int v_size;
  int *data;

 public:
  Point() {
    z = 1;
    x = 0;
    y = 0;
    data = new int[6];
    cout << "Object: " << z << " The constructor is called." << endl;
  }

  Point(int valueX, int valueY) {
    z = 2;
    x = valueX;
    y = valueY;
    cout << "Object: " << z << " The constructor is called." << endl;
  }

  Point(int size) {
    z = 3;
    v_size = size;
    data = new int[size];
    for (int i = 0; i < size; i++) {
      data[i] = i;
    }
    cout << "Object: " << z << " The constructor is called." << endl;
  }

  ~Point() {
    delete[] data;
    data = nullptr;
    cout << "Object: " << z << " The destructor is called." << endl;
  }

  void Print() {
    cout << "x = " << x << "\n"
         << "y = " << y << endl;
  }

  void PrintData() {
    for (int i = 0; i < v_size; i++) {
      cout << data[i] << endl;
    }
  }
};

int main() {
  Point a;
  a.Print();

  Point b(4, 14);
  b.Print();

  Point c(6);
  c.PrintData();

  return 0;
}

// Object: 1 The constructor is called.
// x = 0
// y = 0
// Object: 2 The constructor is called.
// x = 4
// y = 14
// Object: 3 The constructor is called.
// 0
// 1
// 2
// 3
// 4
// 5
// Object: 3 The destructor is called.
// Object: 2 The destructor is called.
// Object: 1 The destructor is called.
