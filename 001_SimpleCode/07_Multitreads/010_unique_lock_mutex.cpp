// unique_lock mutex | unique_lock vs lock_guard | Многопоточное
// программирование | C++ #10
// https://youtu.be/2ysGNxsKlxk

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

// unique_lock - тоже самое что и lock_guard только с расширенным функционалом.

void Print(char ch) {
  this_thread::sleep_for(chrono::milliseconds(2000));

  unique_lock<mutex> ul(mtx);  // начинаем синхронизацию

  for (int i = 0; i < 5; ++i) {
    for (int i = 0; i < 10; i++) {
      cout << ch;
      this_thread::sleep_for(chrono::milliseconds(20));
    }
    cout << endl;
  }
  cout << endl;

  ul.unlock();  // заканчиваем синхронизацию
  // если не укажем ul.unlock(), то синхронизация закончится при завершении
  // работы ф-ции Print.

  this_thread::sleep_for(chrono::milliseconds(2000));
}

void Print2(char ch) {
  unique_lock<mutex> ul(mtx, defer_lock);
  // defer_lock - делает так что mtx.lock() сразу не вызовется и синхронизацию
  // не начнется.

  this_thread::sleep_for(chrono::milliseconds(2000));

  ul.lock();  // начинаем синхронизацию

  for (int i = 0; i < 5; ++i) {
    for (int i = 0; i < 10; i++) {
      cout << ch;
      this_thread::sleep_for(chrono::milliseconds(20));
    }
    cout << endl;
  }
  cout << endl;

  ul.unlock();  // заканчиваем синхронизацию

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
