// Структуры в C++ | struct C++. Разница между структурой и классом. Изучение
// С++ для начинающих.129
// https://youtu.be/EWJqZN7ifI0

#include <string.h>

#include <iostream>

using namespace std;

// По умолчанию все методы и поля класса являются private
class MyClass {
 public:
  int a = 10;
};

class MyClass2 : MyClass {
  // если мы наследуемся без указания модификатора, то все поля public у
  // родителя у наследника станут private
};

// По умолчанию все методы и поля класса являются public
struct MyStruct {
  MyStruct() {
    //
  }
  MyStruct(int a) {
    //
  }
  ~MyStruct() {
    //
  }

  int a = 22;
  void Print() {
    //
  }

 private:
  int b = 33;
};

class MyStruct2 : MyStruct {
  // если мы наследуемся без указания модификатора, то наследование проходит с
  // модификатором public по умолчанию, все поля и методы оставят свои
  // модификаторы доступа.
};

int main() {
  //

  return 0;
}
