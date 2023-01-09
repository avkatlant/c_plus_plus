// Виртуальные методы класса c++. Ключевое слово virtual. Ключевое слово
// override. ООП. C++ 103
// https://youtu.be/YlbFPAugFNA

#include <string.h>

#include <iostream>

using namespace std;

// virtual - позволяет нам реализовать функцию в базовом классе таким образом,
// чтобы в классе наследнике переопределить её поведение, таким образом
// реализовать полиморфизм.

class Gun {
 private:
  /* data */
 public:
  virtual void Shoot() { cout << "BANG!" << endl; }
};

class SubmachineGun : public Gun {
 public:
  void Shoot() override { cout << "BANG! BANG! BANG!" << endl; }
};

class Bazooka : public Gun {
 public:
  void Shoot() override { cout << "BADABUM!" << endl; }
};

class Player {
 public:
  void Shoot(Gun *gun) {
    // Указатель на базовый класс может хранить ссылку на любого своего
    // наследника
    gun->Shoot();
  }
};

int main() {
  Gun gun;
  gun.Shoot();
  Gun *weapon = &gun;
  weapon->Shoot();

  SubmachineGun machineGun;
  Gun *weapon2 = &machineGun;
  weapon2->Shoot();

  cout << endl;

  Bazooka bazooka;

  Player player;
  player.Shoot(&gun);
  player.Shoot(&machineGun);
  player.Shoot(&bazooka);

  return 0;
}
