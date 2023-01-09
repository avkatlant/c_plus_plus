// С++ потоки и методы класса | С++ метод класса в потоке | Многопоточное
// программирование | C++ #5
// https://youtu.be/J32wrE_lMS4

#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

class MyClass {
 public:
  void DoWork() {
    this_thread::sleep_for(chrono::milliseconds(900));
    cout << "ID thread = " << this_thread::get_id()
         << " =========== DoWork STARTED ===========" << endl;
    this_thread::sleep_for(chrono::milliseconds(4000));

    cout << "ID thread = " << this_thread::get_id()
         << "=========== DoWork STOPPED ===========" << endl;
  }

  void DoWork2(int a) {
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "ID thread = " << this_thread::get_id()
         << " =========== DoWork 2 STARTED ===========" << endl;
    this_thread::sleep_for(chrono::milliseconds(3000));

    cout << "DoWork2 a = " << a << endl;

    cout << "ID thread = " << this_thread::get_id()
         << "=========== DoWork 2 STOPPED ===========" << endl;
  }

  int Sum(int a, int b) {
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "ID thread = " << this_thread::get_id()
         << " =========== Sum STARTED ===========" << endl;
    this_thread::sleep_for(chrono::milliseconds(6000));

    cout << "ID thread = " << this_thread::get_id()
         << " =========== Sum STOPPED ===========" << endl;
    return a + b;
  }
};

int main() {
  int result;
  MyClass m;

  thread th([&]() { result = m.Sum(2, 5); });

  thread th2(&MyClass::DoWork, m);

  thread th3(&MyClass::DoWork2, m, 5);
  // или
  // thread th([&]() { m.doWork2(5); });

  for (int i = 1; i <= 10; i++) {
    cout << "ID thread = " << this_thread::get_id() << "\t - main works- " << i
         << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
  }

  th.join();
  th2.join();
  th3.join();
  cout << "result = " << result << endl;

  return 0;
}
