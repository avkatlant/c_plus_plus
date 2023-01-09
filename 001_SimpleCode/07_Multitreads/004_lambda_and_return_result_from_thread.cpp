// Лямбда выражения и возврат результата выполнения потока | Многопоточное
// программирование | C++ #4
// https://youtu.be/DFgtADi0Mjo

#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

int Sum(int a, int b) {
  this_thread::sleep_for(chrono::milliseconds(2000));
  cout << "ID thread = " << this_thread::get_id()
       << " =========== DoWork STARTED ===========" << endl;
  this_thread::sleep_for(chrono::milliseconds(5000));

  cout << "ID thread = " << this_thread::get_id()
       << "=========== DoWork STOPPED ===========" << endl;
  return a + b;
}

int main() {
  int result;
  thread th([&result]() { result = Sum(2, 5); });
  // или
  // auto f = [&result]() { result = Sum(2, 5); };
  // thread th(f);

  for (int i = 0; i < 10; i++) {
    cout << "ID thread = " << this_thread::get_id() << "\t - main works- " << i
         << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
  }

  th.join();
  cout << result << endl;

  return 0;
}
