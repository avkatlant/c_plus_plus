// stl copy | stl copy_if | Выборка данных по условию | Библиотека стандартных
// шаблонов (stl) C++ #15 https://youtu.be/s7C8fPpi0BE

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
 public:
  Person(string name, double score) {
    this->Name = name;
    this->Score = score;
  }

  bool operator()(const Person &p) { return p.Score > 180; }

  string Name;
  double Score;
};

int main() {
  vector<Person> people{
      Person("Vasia", 181), Person("Nadia", 32), Person("Misha", 522),
      Person("Alex", 522),  Person("Oleg", 67),  Person("Vera", 25),
      Person("Serega", 63),
  };

  vector<Person> result;

  copy(people.begin(), people.end(), back_inserter(result));
  for (auto el : result) {
    cout << el.Name << " - " << el.Score << endl;
  }

  cout << endl;

  vector<Person> result2;

  copy_if(people.begin(), people.end(), back_inserter(result2),
          [](const Person &b) { return b.Score < 100; });
  for (auto el : result2) {
    cout << el.Name << " - " << el.Score << endl;
  }

  return 0;
}

/*

*/
