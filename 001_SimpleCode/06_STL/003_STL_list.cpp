// LIST | STL C++ | Библиотека стандартных шаблонов (stl) | Уроки | C++ | #3
// https://youtu.be/tYkaWCkAVJI

#include <iostream>
#include <list>
#include <vector>

using namespace std;

// list - реализован на основе двусвязного списка

// Быстро выполняются операции в начале и конце списка,
// операции в середине медленно.

template <typename T>
void PrintList(const list<T> &lst) {
  for (auto i = lst.cbegin(); i != lst.cend(); ++i) {
    cout << *i << "  ";
  }
  cout << endl;
}

int main() {
  // list<int> myList;
  list<int> myList = {54, 23, 76, 4};

  myList.push_back(5);
  myList.push_front(7);
  myList.push_front(30);

  list<int>::iterator it = myList.begin();
  cout << *it << endl;

  cout << endl;

  // Выводим все элементы
  PrintList(myList);

  cout << endl;

  // Сортируем
  myList.sort();
  PrintList(myList);

  cout << endl;

  myList.pop_front();
  myList.pop_back();
  PrintList(myList);

  cout << endl;

  cout << myList.size() << endl;

  cout << endl;

  myList.push_front(99);
  myList.push_back(99);
  myList.push_back(99);
  PrintList(myList);
  myList.unique();  // Удаляет дубликаты, которые идут последовательно.
  PrintList(myList);

  cout << endl;

  myList.reverse();
  PrintList(myList);

  cout << endl;

  // myList.clear(); //  Удаляем все данные
  // PrintList(myList);

  // cout << endl;

  // Добавляем элемент
  auto itInsert = myList.begin();
  myList.insert(itInsert, 111);
  PrintList(myList);

  cout << endl;

  // Добавляем элемент с произвольным индексом
  auto itInsert2 = myList.begin();
  advance(itInsert2, 3);
  myList.insert(itInsert2, 111);
  PrintList(myList);

  itInsert2++;
  myList.erase(itInsert2);  // Стираем элемент
  PrintList(myList);

  myList.remove(99);  // Удаляем конкретный элемент по значению.
  PrintList(myList);

  cout << endl;

  // Заполняем list значениями
  myList.assign(3, 0);  // Заполняем list тремя эл. со значением 0
  PrintList(myList);

  // Копируем все элементы из myList2 в myList
  list<int> myList2 = {345, 65, 332, 76, 2, 74};
  myList.assign(myList2.begin(), myList2.end());
  PrintList(myList);

  return 0;
}

/*

*/
