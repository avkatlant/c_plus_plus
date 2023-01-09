// Как измерить время выполнения кода | Изучение С++ для начинающих. Урок 145
// https://youtu.be/bN6dfoGK38Y

// #include <chrono>  // нужна если не используем <thread>
#include <iostream>
#include <thread>  // внутри уже есть <chrono>

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

int main() {
  SimpleTimer st;

  for (int i = 1; i <= 10; i++) {
    cout << "ID thread = " << this_thread::get_id() << "\t - main works- " << i
         << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
  }

  return 0;
}
