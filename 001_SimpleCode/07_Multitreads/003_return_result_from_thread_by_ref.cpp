// Возврат результата из потока по ссылке | Многопоточное программирование |
// Уроки | C++ #3
// https://youtu.be/fTs2TteQkB4

#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

void DoWork(int &a) {
  this_thread::sleep_for(chrono::milliseconds(3000));
  cout << "ID thread = " << this_thread::get_id()
       << " =========== DoWork STARTED ===========" << endl;
  this_thread::sleep_for(chrono::milliseconds(5000));

  a *= 2;

  cout << "ID thread = " << this_thread::get_id()
       << "=========== DoWork STOPPED ===========" << endl;
}

int main() {
  int q = 5;
  thread th(DoWork, std::ref(q));

  for (int i = 0; i < 10; i++) {
    cout << "ID thread = " << this_thread::get_id() << "\t - main works- " << i
         << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
  }

  th.join();
  cout << q << endl;

  return 0;
}
