// lock_guard mutex c++ | Cинхронизация потоков | Многопоточное программирование
// | C++ #7
// https://youtu.be/XDuSaRGeIx4

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

mutex mtx;

void Print(char ch) {
  this_thread::sleep_for(chrono::milliseconds(2000));
  {
    // lock_guard - это класс, задача которого захватить mutex в конструкторе,
    // при создании объекта такого класса, и освободить mutex в destructor, в
    // тот момент когда объект этого класса будет покидать область видимости.
    // lock_guard<mutex> guard(mtx) = mtx.lock() + any code + mtx.unlock()
    lock_guard<mutex> guard(mtx);

    for (int i = 0; i < 5; ++i) {
      for (int i = 0; i < 10; i++) {
        cout << ch;
        this_thread::sleep_for(chrono::milliseconds(20));
      }
      cout << endl;
    }
    cout << endl;
  }
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
