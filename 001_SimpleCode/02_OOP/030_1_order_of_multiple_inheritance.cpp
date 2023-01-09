// Виртуальное наследование c++. Ромбовидное наследование c++. Изучение С++ для
// начинающих. Урок 114
// https://youtu.be/oqpx7L5ipbw

#include <string.h>

#include <iostream>

using namespace std;

class Component {
 public:
  string companyName;

  Component(string companyName) {
    cout << "class Component - constructor was called." << endl;
    this->companyName = companyName;
  }
};

class GPU : public Component {
 public:
  GPU(string companyName) : Component(companyName) {
    cout << "class GPU - constructor was called." << endl;
  }
};

class Memory : public Component {
 public:
  Memory(string companyName) : Component(companyName) {
    cout << "class Memory - constructor was called." << endl;
  }
};

class GraphicCard : public GPU, public Memory {
 public:
  GraphicCard(string GPUCompanyName, string MemoryCompanyName)
      : GPU(GPUCompanyName), Memory(MemoryCompanyName) {
    cout << "class GraphicCard - constructor was called." << endl;
  }
};

int main() {
  GraphicCard gc("AMD", "Samsung");

  return 0;
}

/*
class Component - constructor was called.
class GPU - constructor was called.
class Component - constructor was called.
class Memory - constructor was called.
class GraphicCard - constructor was called.
*/
