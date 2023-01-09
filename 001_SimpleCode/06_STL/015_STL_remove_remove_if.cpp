// stl remove | stl remove_if | stl удаление элемента по условию | Библиотека
// (stl) #16
// https://youtu.be/LLA3PiBmaQU

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
 public:
  Person(string name, double score, int age) {
    this->Name = name;
    this->Score = score;
    this->Age = age;
  }

  bool operator()(const Person &p) { return p.Score > 180; }

  string Name;
  double Score;
  int Age;
};

int main() {
  vector<int> v = {53, 35, 45, 6, 56, 35, 5, 6, 4};

  auto it = remove(v.begin(), v.end(), 35);
  // remove на самом деле не удаляет элементы со значением 35,
  // а переносит их в конец вектора: {53, 45, 6, 56, 5, 6, 4, 35, 35};
  // it - итератор указывающий на первый перенесенный в конец элемент со
  // значением 35.
  v.erase(it, v.end());  // реально удаляем все элементы со значением 35.
  for (auto el : v) {
    cout << el << endl;
  }

  cout << endl;

  vector<Person> people{
      Person("Vasia", 181, 23), Person("Nadia", 32, 54),
      Person("Misha", 522, 18), Person("Alex", 522, 21),
      Person("Oleg", 67, 32),   Person("Vera", 25, 26),
      Person("Serega", 63, 22),
  };

  auto it2 = remove_if(people.begin(), people.end(),
                       [](const Person &p) { return p.Score < 100; });
  people.erase(it2, people.end());
  for (auto el : people) {
    cout << el.Name << " - " << el.Score << " - " << el.Age << endl;
  }

  cout << endl;

  string str = "Текст с несколькими   пробелами.";
  cout << str << endl;
  str.erase(remove(str.begin(), str.end(), ' '), str.end());
  cout << str << endl;

  return 0;
}

/*

*/
