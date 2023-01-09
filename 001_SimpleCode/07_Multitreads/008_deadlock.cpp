// Deadlock Взаимная блокировка | Многопоточное программирование | C++ #8
// https://youtu.be/KJ1CnT7XY74

#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

class SimpleTimer {
 public:
  SimpleTimer() { start = std::chrono::steady_clock::now(); }
  ~SimpleTimer() {
    end = std::chrono::steady_clock::now();
    std::chrono::duration<float> duration = end - start;
    cout << "duration = " << duration.count() << " s" << endl;
  }

 private:
  std::chrono::time_point<std::chrono::steady_clock> start, end;
};

mutex mtx1;
mutex mtx2;

// deadlock - Взаимная блокировка

// пример как избегать взаимной блокировки

void Print() {
  mtx1.lock();
  this_thread::sleep_for(chrono::milliseconds(1));
  mtx2.lock();

  for (int i = 0; i < 5; ++i) {
    for (int i = 0; i < 10; i++) {
      cout << '*';
      this_thread::sleep_for(chrono::milliseconds(10));
    }
    cout << endl;
  }
  cout << endl;

  mtx1.unlock();
  mtx2.unlock();
}

void Print2() {
  mtx1.lock();
  // this_thread::sleep_for(chrono::milliseconds(1));
  mtx2.lock();

  for (int i = 0; i < 5; ++i) {
    for (int i = 0; i < 10; i++) {
      cout << '#';
      this_thread::sleep_for(chrono::milliseconds(10));
    }
    cout << endl;
  }
  cout << endl;

  mtx1.unlock();
  mtx2.unlock();
}

int main() {
  SimpleTimer timer;

  thread t1(Print);
  thread t2(Print2);

  t1.join();
  t2.join();

  return 0;
}
