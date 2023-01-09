// Функторы в с++ | Что такое функтор | Изучение С++ для начинающих. Урок 146
// https://youtu.be/uzZw7VzZj5E

#include <iostream>

using namespace std;

// Функтор - это класс у которого переопределены "()".

class MyFunctor {
 public:
  int operator()(int a, int b) {
    cout << "I am functor" << endl;
    return a + b;
  }

 private:
  int count = 0;
};

class EventFunctor {
 private:
  int evenSum = 0;
  int evenCount = 0;

 public:
  void operator()(int value) {
    if (value % 2 == 0) {
      evenSum += value;
      evenCount++;
    }
  }

  void ShowEventSum() { cout << "Сумма четных чисел = " << evenSum << endl; }
  void ShowEventCount() {
    cout << "Количество четных чисел = " << evenCount << endl;
  }
};

int main() {
  MyFunctor f;
  int result = f(2, 5);
  cout << result << endl;

  cout << endl;

  int arr[] = {3, 5, 6, 3, 56, 6};
  EventFunctor ef;
  for (auto el : arr) {
    ef(el);
  }
  ef.ShowEventCount();
  ef.ShowEventSum();

  return 0;
}
