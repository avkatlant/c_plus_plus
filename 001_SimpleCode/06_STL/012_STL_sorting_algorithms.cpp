// STL Алгоритмы сортировки | Бинарный предикат | Лямбда функции | C++ STL Уроки
// | #13
// https://youtu.be/A3Y0KihfjLY

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

// Унарный предикат
bool GreaterThanZero(int a) { return a > 9; }

// бинарный предикат
bool MyPred(int a, int b) { return a > b; }

int main() {
  vector<int> v = {54, 35, 45, 6, 56, 3, 5, 6, 4};

  sort(v.begin(), v.end());
  for (auto el : v) {
    cout << el << "  ";
  }

  cout << endl;

  sort(v.begin(), v.end(), MyPred);
  for (auto el : v) {
    cout << el << "  ";
  }

  cout << endl;

  sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
  for (auto el : v) {
    cout << el << "  ";
  }

  cout << endl;

  const int SIZE = 11;
  int arr[SIZE] = {6, 3, 8, 2, 43, 7, 36, 7, 34, 53, 4};
  sort(arr, arr + SIZE);
  for (auto el : arr) {
    cout << el << "  ";
  }

  cout << endl << endl;

  vector<Person> people{
      Person("Vasia", 181), Person("Nadia", 32), Person("Misha", 5),
      Person("Alex", 522),  Person("Oleg", 67),  Person("Vera", 25),
      Person("Serega", 63),
  };

  sort(people.begin(), people.end(),
       [](const Person &p1, const Person &p2) { return p1.Name < p2.Name; });

  for (auto el : people) {
    cout << el.Name << " - " << el.Score << endl;
  }

  return 0;
}

/*

*/
