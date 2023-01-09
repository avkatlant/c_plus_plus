// STL алгоритмы поиска | find | find_if | find_if_not | Библиотека стандартных
// шаблонов (stl) C++ #14
// https://youtu.be/xx_DB4sf92E

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
  vector<int> v = {53, 35, 45, 6, 56, 3, 5, 6, 4};

  // Присутствует ли в коллекции конкретный элемент
  auto it = find(v.begin(), v.end(), 56);
  // std::vector<int>::iterator it - итератор в который завернут указатель,
  // указывающий на число 56.
  if (it == v.end()) {
    cout << "Not found" << endl;
  } else {
    cout << *it << endl;
  }

  cout << endl;

  // find_if - Присутствует ли в коллекции элемент удовлетворяющий условию.
  // find_if_not - инвертированный find_if
  auto it2 = find_if(v.begin(), v.end(), [](int a) { return a % 2 == 0; });
  if (it2 == v.end()) {
    cout << "Not found" << endl;
  } else {
    cout << *it2 << endl;
  }

  cout << endl;

  vector<Person> people{
      Person("Vasia", 181), Person("Nadia", 32), Person("Misha", 5),
      Person("Alex", 522),  Person("Oleg", 67),  Person("Vera", 25),
      Person("Serega", 63),
  };

  auto it3 = find_if(people.begin(), people.end(),
                     [](const Person &b) { return b.Name == "Nadia"; });
  if (it3 == people.end()) {
    cout << "Not found" << endl;
  } else {
    cout << it3->Name << endl;
  }

  return 0;
}

/*

*/
