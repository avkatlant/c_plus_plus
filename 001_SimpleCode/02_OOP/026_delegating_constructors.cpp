// Делегирующие конструкторы c++. Вызов конструктора из конструктора. ООП. С++
// Для начинающих. 107
// https://youtu.be/-6Od-amEve8

#include <string.h>

#include <iostream>

using namespace std;

class Human {
 public:
  string Name;
  int Age;
  int Weight;

  Human(string Name) {
    this->Name = Name;
    this->Age = 0;
    this->Weight = 0;
  }

  Human(string Name, int Age) : Human(Name) { this->Age = Age; }

  Human(string Name, int Age, int Weight) : Human(Name) {
    this->Weight = Weight;
  }
};

int main() {
  //

  return 0;
}
