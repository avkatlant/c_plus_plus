// Предикаты с++ | Что такое предикат | Изучение С++ для начинающих. Урок 147
// https://youtu.be/041eqc6qJl8

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Предикат - это ф-ция или функтор, которая возвращает булево значение (bool).

bool GreaterThanZero(int a) { return a > 0; }

class Person {
 public:
  Person(string name, double score) {
    this->Name = name;
    this->Score = score;
  }

  int operator()(const Person &p) { return p.Score > 180; }

  string Name;
  double Score;
};

int main() {
  cout << GreaterThanZero(1) << endl;

  vector<int> v = {1, 3, -5, 34, -255, 6};
  int result = count_if(v.begin(), v.end(), GreaterThanZero);
  cout << result << endl;

  cout << endl;

  vector<Person> people = {
      Person("Vasia", 181),  Person("Nadia", 32), Person("Misha", 522),
      Person("Alex", 522),   Person("Oleg", 67),  Person("Vera", 250),
      Person("Serega", 630),
  };
  int res = count_if(people.begin(), people.end(), people.front());
  cout << res << endl;

  return 0;
}
