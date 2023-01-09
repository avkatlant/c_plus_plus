// Виртуальное наследование c++. Ромбовидное наследование c++. Изучение С++ для
// начинающих. Урок 114
// https://youtu.be/oqpx7L5ipbw

#include <string.h>

#include <iostream>

using namespace std;

class Character {
 public:
  int HP;

  Character() { cout << "class Character - constructor was called." << endl; }
};

class Orc : public virtual Character {
 public:
  Orc() { cout << "class Orc - constructor was called." << endl; }
};

class Warrior : public virtual Character {
 public:
  Warrior() { cout << "class Warrior - constructor was called." << endl; }
};

class OrcWarrior : public Orc, public Warrior {
 public:
  OrcWarrior() { cout << "class OrcWarrior - constructor was called." << endl; }
};

int main() {
  OrcWarrior ow;

  return 0;
}

/*
class Character - constructor was called.
class Orc - constructor was called.
class Warrior - constructor was called.
class OrcWarrior - constructor was called.
*/
