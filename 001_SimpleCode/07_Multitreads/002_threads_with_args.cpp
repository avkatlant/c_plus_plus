// Потоки с параметрами | Многопоточное программирование | Уроки | C++ #2
// https://youtu.be/UEtWLpDOg68

#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

void DoWork(int a, int b, string msg) {
  this_thread::sleep_for(chrono::milliseconds(500));
  cout << msg << endl;
  this_thread::sleep_for(chrono::milliseconds(3000));
  cout << "=========== DoWork STARTED ===========" << endl;
  this_thread::sleep_for(chrono::milliseconds(5000));
  cout << "a + b = " << a + b << endl;
  this_thread::sleep_for(chrono::milliseconds(3000));
  cout << "=========== DoWork STOPPED ===========" << endl;
}

int main() {
  thread th(DoWork, 2, 3, "Our message");

  for (int i = 0; true; i++) {
    cout << "ID thread = " << this_thread::get_id() << "\t - main works- " << i
         << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
  }

  th.join();
  return 0;
}
