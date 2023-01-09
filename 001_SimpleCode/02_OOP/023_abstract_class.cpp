// Абстрактный класс с++ пример. Чисто виртуальная функция. virtual. override.
// Полиморфизм ООП C++ 104
// https://youtu.be/y2tqQf2mdeA

#include <string.h>

#include <iostream>

using namespace std;

// Абстрактный класс
class Weapon {
 public:
  virtual void Shoot() = 0;
  // = 0 - сообщаем компилятору что это функция только виртуальная и
  // класс в котором она становится абстрактным.
  // Компилятор на даст создать экземпляр этого класса.

  void Foo() { cout << "Foo" << endl; }
};

class Gun : public Weapon {
 private:
  /* data */
 public:
  virtual void Shoot() override { cout << "BANG!" << endl; }
};

class SubmachineGun : public Gun {
 public:
  void Shoot() override { cout << "BANG! BANG! BANG!" << endl; }
};

class Bazooka : public Weapon {
 public:
  void Shoot() override { cout << "BADABUM!" << endl; }
};

class Knife : public Weapon {
 public:
  void Shoot() override { cout << "VJUH!" << endl; }
};

class Player {
 public:
  void Shoot(Weapon *weapon) {
    // Указатель на базовый класс может хранить ссылку на любого своего
    // наследника
    weapon->Shoot();
  }
};

int main() {
  Gun gun;
  SubmachineGun machineGun;
  Bazooka bazooka;
  Knife knife;

  Player player;
  player.Shoot(&gun);
  player.Shoot(&machineGun);
  player.Shoot(&bazooka);
  player.Shoot(&knife);

  gun.Foo();
  machineGun.Foo();
  bazooka.Foo();
  knife.Foo();

  return 0;
}
