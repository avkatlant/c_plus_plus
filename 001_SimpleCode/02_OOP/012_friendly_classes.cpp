// Дружественные классы. ООП. friend class.
// https://youtu.be/SiOfT03jSU0

#include <string.h>

#include <iostream>

using namespace std;

class Apple;

class Human {
 public:
  void TakeApple(Apple &apple);

  void EatApple(Apple &apple) {
    cout << apple.weight << " " << apple.color << endl;
  }
};

class Apple {
  friend Human;

 private:
  int weight;
  string color;

 public:
  Apple(int weight, string color) {
    this->weight = weight;
    this->color = color;
  }
};

void Human::TakeApple(Apple &apple) {
  cout << apple.weight << " " << apple.color << endl;
}

int main() {
  Apple apple(150, "Red");
  Human human;
  human.TakeApple(apple);
  return 0;
}
