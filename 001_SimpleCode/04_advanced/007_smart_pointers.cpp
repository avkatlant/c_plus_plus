// Умные указатели. Smart pointers. Изучение С++ для начинающих. Урок 130
// https://youtu.be/ixsTu-ULh0Q

#include <string.h>

#include <iostream>

using namespace std;

template <typename T>
class SmartPointer {
 public:
  SmartPointer(T *ptr) {
    this->ptr = ptr;
    cout << "Constructor was called" << endl;
  }

  ~SmartPointer() {
    delete ptr;
    cout << "Destructor was called" << endl;
  }

  T &operator*() { return *ptr; }

 private:
  T *ptr;
};

int main() {
  int *ptr = new int(5);
  cout << *ptr << endl;
  delete ptr;

  cout << endl;

  SmartPointer<int> pointer = new int(10);
  cout << *pointer << endl;
  *pointer = 2423443;
  cout << *pointer << endl;

  return 0;
}

/*
5

Constructor was called
10
2423443
Destructor was called
*/
