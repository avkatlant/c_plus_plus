// Stack | Адаптеры контейнеров | Библиотека стандартных шаблонов (stl) | Уроки
// | C++ #11
// https://youtu.be/wFTvBHEnp1A

#include <deque>
#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// stack - адаптер контейнеров
// Принцип LIFO (LAST INPUT FIRST OUTPUT)
// Может быть основан на vector, list, deque.

int main() {
  stack<int> st;
  st.push(2);
  st.push(3);
  st.emplace(6);
  st.emplace(2);
  // push - сначала создает копию объекта, потом переносит эту копию в
  // коллекцию.
  // emplace - создает объект уже в коллекции, без копирования и
  // перемещения. Работает быстрее push.

  while (!st.empty()) {
    cout << st.top() << endl;
    st.pop();
  }

  cout << endl;

  stack<int, deque<int> > st2;
  st2.push(1);
  st2.push(2);
  st2.push(3);
  st2.emplace(9);
  deque<int> myDeque;
  while (!st2.empty()) {
    myDeque.push_back(st2.top());
    st2.pop();
  }
  for (const auto item : myDeque) {
    cout << item << endl;
  }

  return 0;
}

/*

*/
