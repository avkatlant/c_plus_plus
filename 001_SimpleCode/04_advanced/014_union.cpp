// Union | Использование в С++ | Изучение С++ для начинающих. Урок 141
// https://youtu.be/6IsGVvNbyOo

#include <iostream>
using namespace std;

// Под объект Union выделяется столько байт, сколько места в памяти
// может занимать наибольший объект в этом Union.
// Память которая не заполняются данными, заполняются нулями.

union MyUnion {
  short int a;
  int b;
  float c;
};

int main() {
  MyUnion u;

  u.a = 5;
  // после записи в переменную "a", в переменных "b" и "c" хранится мусор.

  u.b = 40000;
  // после записи в переменную "b", в переменных "a" и "c" хранится мусор.

  u.c = 43.54;
  // после записи в переменную "c", в переменных "a" и "b" хранится мусор.

  return 0;
}
