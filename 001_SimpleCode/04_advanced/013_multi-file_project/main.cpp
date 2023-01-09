// Многофайловый проект | Изучение С++ для начинающих. Урок 139
// https://youtu.be/pAxEfF2yVlM

// Многофайловый проект | Защита от повторного включения | Изучение С++ для
// начинающих. Урок 140
// https://youtu.be/ZwaE-JM7smI

#include <iostream>

#include "MyClass.h"
#include "Sum.h"

int main() {
  int result = Sum(2, 3);
  std::cout << result << std::endl;

  myNamespace::MyClass m;
  m.PrintMessage("Hello World");

  return 0;
}
