// Что такое интерфейс в ООП. Интерфейс c++ пример. Изучение С++ для начинающих.
// Урок 113
// https://youtu.be/3rUgmjfwS_o

#include <string.h>

#include <iostream>

using namespace std;

// В интерфейсе все методы виртуальные
class IBicycle {
 public:
  virtual void TwistTheWheel() = 0;
  virtual void Ride() = 0;
};

class SimpleBicycle : public IBicycle {
 public:
  void TwistTheWheel() override {
    cout << "class SimpleBicycle - TwistTheWheel()" << endl;
  }
  void Ride() override { cout << "class SimpleBicycle - Ride()" << endl; }
};

class SportBicycle : public IBicycle {
 public:
  void TwistTheWheel() override {
    cout << "class SportBicycle - TwistTheWheel()" << endl;
  }
  void Ride() override { cout << "class SportBicycle - Ride()" << endl; }
};

class Human {
 public:
  void RideOn(IBicycle &bicycle) {
    cout << "I'm turning the steering wheel" << endl;
    bicycle.TwistTheWheel();
    cout << "Let's go!" << endl;
    bicycle.Ride();
  }
};

int main() {
  SimpleBicycle smb;
  SportBicycle spb;
  Human h;
  h.RideOn(smb);
  cout << endl;
  h.RideOn(spb);

  return 0;
}
