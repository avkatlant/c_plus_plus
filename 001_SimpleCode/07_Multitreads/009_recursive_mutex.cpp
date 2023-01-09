// recursive_mutex C++ | Рекурсивный мьютекс | Многопоточное программирование |
// C++ #9
// https://youtu.be/_jZlmgDoDOM

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

// если нам надо несколько раз захватить mutex
recursive_mutex rm;

void Foo(int a) {
  rm.lock();

  cout << a << " ";
  this_thread::sleep_for(chrono::milliseconds(300));

  if (a <= 1) {
    cout << endl;

    rm.unlock();
    return;
  }
  a--;
  Foo(a);

  rm.unlock();
}

int main() {
  SimpleTimer timer;

  thread t1(Foo, 10);
  thread t2(Foo, 10);

  t1.join();
  t2.join();

  return 0;
}
