// SET | MULTISET | Ассоциативные контейнеры | Библиотека стандартных шаблонов
// (stl) | Уроки | C++ #9
// https://youtu.be/i02_JDJS3yw

#include <iostream>
#include <set>

using namespace std;

// set и multiset - Основаны на бинарном дереве
// Упорядоченная структура данных.

// set - Хранит только уникальные элементы.
// Не может изменять конкретный элемент, но можем добавлять и удалять элементы.

// multiset - Может хранить несколько одинаковых элементов в коллекции.

int main() {
  set<int> mySet;
  // set<int> mySet = {453, 45, 65, 63, 5};

  mySet.insert(5);  // Первый добавленный элемент становится корнем дерева
  mySet.insert(1);
  mySet.insert(65);
  mySet.insert(6);
  mySet.insert(7);
  mySet.insert(12);
  mySet.insert(-4);
  mySet.insert(-4);
  mySet.insert(-4);

  for (auto el : mySet) {
    cout << el << "  ";
  }

  cout << endl;

  auto it = mySet.find(10);
  // .find(10) -  возвращает итератор на определенный элемент в set,
  // если элемент есть, а если нет то вернет mySet.end()
  cout << (it != mySet.end()) << endl;

  cout << endl;

  // Удаление элемента по значению
  auto result = mySet.erase(7);
  // erase возвращает 1 - если удалось удалить, 0 - если нет.
  for (auto el : mySet) {
    cout << el << "  ";
  }

  cout << endl;
  cout << endl;

  multiset<int> myMultiset = {22, 432, 4, 5, 24, 3, 54, 4};
  for (auto el : myMultiset) {
    cout << el << "  ";
  }

  cout << endl;

  auto it2 = myMultiset.lower_bound(5);
  // Вернет итератор, указывающий на первый элемент равный 4
  for (auto i = it2; i != myMultiset.end(); i++) {
    cout << *i << "  ";
  }
  cout << endl;

  auto it3 = myMultiset.upper_bound(24);
  // Вернет итератор,
  // указывающий на первый элемент после элемента со значением 4
  for (auto i = it3; i != myMultiset.end(); i++) {
    cout << *i << "  ";
  }
  cout << endl;
  cout << endl;

  auto it4 = myMultiset.equal_range(5);
  // .equal_range(1) - вернет диапазон значений от .lower_bound до
  // .upper_bound.
  cout << *it4.first << "  ";
  cout << *it4.second << endl;
  cout << endl;

  return 0;
}

/*

*/
