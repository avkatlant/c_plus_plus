// Ключевое слово auto | Изучение С++ для начинающих. Урок 136
// https://youtu.be/o-U0PAFVKdk

#include <string.h>

#include <iostream>
#include <vector>

using namespace std;

int main() {
  // Когда мы указываем auto, то компилятор сам догадается какой тип переменной
  // использовать.
  auto a = 5;
  auto b = "Hello";
  auto c = 4.6;
  auto d = true;

  // auto e;  // так не получится,
  // необходимо сразу присвоить какое-нибудь значение

  // vector<int>::iterator it = myVector.begin();
  // auto it = myVector.begin();

  return 0;
}

/*

*/
