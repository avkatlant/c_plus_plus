// queue | priority queue | Адаптеры контейнеров | Библиотека стандартных
// шаблонов (stl) | C++ #12
// https://youtu.be/U4mV_MVCLuU

#include <iostream>
#include <queue>
#include <string>

using namespace std;

// queue - адаптер контейнеров
// Принцип FIFO (FIRST INPUT FIRST OUTPUT)

int main() {
  queue<int> q;
  q.push(56);
  q.push(5);
  q.push(1);
  q.push(98);

  // смотрим но неизвлекаем
  cout << q.front() << endl << endl;

  while (!q.empty()) {
    cout << q.size() << " - " << q.front() << endl;
    q.pop();  // извлекаем
  }

  cout << endl;

  priority_queue<int> pq;
  pq.push(76);
  pq.push(4);
  pq.push(8);
  pq.push(3);

  while (!pq.empty()) {
    cout << pq.size() << " - " << pq.top() << endl;
    pq.pop();  // извлекаем
  }

  return 0;
}

/*

*/
