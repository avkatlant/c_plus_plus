// Свой класс exception c++. Создание собственного класса исключений. С++ для
// начинающих. Урок 123
// https://youtu.be/wCUl7yTHWq8

#include <string.h>

#include <fstream>
#include <iostream>

using namespace std;

class MyException : public invalid_argument {
 private:
  int dataState;

 public:
  MyException(const char* msg, int dataState) : invalid_argument(msg) {
    this->dataState = dataState;
  }

  int GetDataState() { return dataState; }
};

void Foo(int value) {
  if (value < 0) {
    throw std::invalid_argument("Less than 0");

  } else if (value == 1) {
    throw MyException("Number equal 1", value);
  }

  cout << "Value = " << value << endl;
}

int main() {
  try {
    // Foo(1);
    Foo(-1);

  } catch (MyException& e) {
    std::cerr << e.what() << endl;
    cout << e.GetDataState() << endl;

  } catch (exception& e) {
    std::cerr << e.what() << endl;
  }
  return 0;
}
