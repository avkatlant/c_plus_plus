// Многопоточность | Потоки | thread | Многопоточное программирование | Уроки |
// C++ #1
// https://youtu.be/NawpxG81RRk

#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

void DoWork() {
  for (int i = 0; i < 10; i++) {
    cout << "ID thread = " << this_thread::get_id() << "\t - DoWork - " << i
         << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
  }
}

int main() {
  // this_thread::sleep_for() - метод который приостанавливает работу текущего
  // потока на определенный период времени.
  // this_thread::sleep_for(chrono::milliseconds(1000));

  // this_thread::get_id() - идентификатор текущего потока.
  // cout << this_thread::get_id() << endl;

  thread th(DoWork);  // объект потока принимает указатель
  thread th2(DoWork);

  // th.detach()
  // разрываем связь между объектом th и тем потоком,
  // который мы начали выполнять.
  // Вызовет неопределенное поведение, если ф-ция main завершит
  // работу (закроет все потоки), а ф-ция DoWork еще работает.
  // DoWork оборвет свою работу.

  for (int i = 0; i < 10; i++) {
    cout << "ID thread = " << this_thread::get_id() << "\t - main - " << i
         << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
  }

  // Место где дожидаемся выполнения той задачи,
  // которую поставили в отдельном потоке.
  th.join();
  th2.join();
  // Когда программа доходит до метода join, то основной поток блокируется и
  // ждет выполнения другого потока.

  return 0;
}
