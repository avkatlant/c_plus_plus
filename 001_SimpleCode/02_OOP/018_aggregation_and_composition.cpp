// Что такое агрегация и композиция. Отношения между классами и объектами. ООП.
// C++ Для начинающих #97
// https://youtu.be/N7DzmfLBolM

#include <string.h>

#include <iostream>

using namespace std;

// В агрегация и композиция - один класс используется в другом, но используются
// они по разному.

// class Human и class Cap - реализованна агрегация - классы не зависят друг от
// друга, class Cap можем использовать с другим классом.

// class Human и class Brain - реализованна композиция - жесткая привязка одного
// объекта к другому, class Brain без class Human мы использовать не можем.

class Cap {
 public:
  string GetColor() { return color; }

 private:
  string color = "red";
};

class Model {
 public:
  void InspectModel() {
    cout << "My cap is " << cap.GetColor() << " color." << endl;
  }

 private:
  Cap cap;
};

class Human {
 public:
  void Think() { brain.Think(); }

  void InspectTheCap() {
    cout << "My cap is " << cap.GetColor() << " color." << endl;
  }

 private:
  class Brain {
   public:
    void Think() { cout << "I am soul!" << endl; }
  };

  Brain brain;
  Cap cap;
};

int main() {
  Human human;
  human.Think();
  human.InspectTheCap();

  Model model;
  model.InspectModel();

  return 0;
}
