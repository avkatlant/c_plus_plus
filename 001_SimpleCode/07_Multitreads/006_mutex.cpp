// Что такое mutex | Cинхронизация потоков | Многопоточное программирование |
// C++ #6
// https://youtu.be/FaF2dADZ-Y0

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

// mutex - некий сигнал что ресурс занят, и пока один поток работает с ресурсом,
// остальные потоки не могут получить к этому ресурсу доступ.
// Cинхронизация потоков, защита разделения данных.
mutex mtx;

void Print(char ch) {
  this_thread::sleep_for(chrono::milliseconds(2000));
  mtx.lock();

  for (int i = 0; i < 5; ++i) {
    for (int i = 0; i < 10; i++) {
      cout << ch;
      this_thread::sleep_for(chrono::milliseconds(20));
    }
    cout << endl;
  }
  cout << endl;

  mtx.unlock();
  this_thread::sleep_for(chrono::milliseconds(2000));
}

int main() {
  SimpleTimer timer;

  thread t1(Print, '*');
  thread t2(Print, '#');
  thread t3(Print, '@');

  t1.join();
  t2.join();
  t3.join();

  return 0;
}
