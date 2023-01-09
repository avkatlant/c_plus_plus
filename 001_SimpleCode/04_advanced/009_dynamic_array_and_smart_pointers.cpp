// Динамический массив и умные указатели. Изучение С++ для начинающих. Урок 132
// https://youtu.be/edGrIXZJEAA

#include <string.h>

#include <iostream>
#include <memory>

using namespace std;

int main() {
  int SIZE = 5;
  int *arr = new int[SIZE]{1, 6, 44, 9, 8};

  // shared_ptr<int[]> ptr(arr);
  shared_ptr<int> ptr(new int[SIZE]{1, 6, 44, 9, 8});

  for (int i = 0; i < SIZE; i++) {
    cout << ptr.get()[i] << endl;
  }
}

/*
1
6
44
9
8
*/
