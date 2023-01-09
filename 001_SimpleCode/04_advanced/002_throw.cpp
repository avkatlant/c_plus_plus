// Генерация исключений с++ пример. throw c++ пример. Изучение С++ для
// начинающих. Урок 121
// https://youtu.be/FhlGFJ_zdKM

// Несколько блоков catch. Обработка исключений С++. Изучение С++ для
// начинающих. Урок 122
// https://youtu.be/guLK7Up6Kmc

#include <string.h>

#include <fstream>
#include <iostream>

using namespace std;

void Foo(int value) {
  if (value < 0) {
    throw value;

  } else if (value > 100 && value < 1000) {
    throw "More than 100";

  } else if (value > 1000) {
    throw std::runtime_error("More than 1000");

  } else if (value == 0) {
    throw '\0';
  }

  cout << "Value = " << value << endl;
}

int main() {
  try {
    // Foo(-1);
    // Foo(101);
    // Foo(1001);
    Foo(0);

  } catch (const int e) {
    std::cerr << e << '\n';

  } catch (const char* e) {
    std::cerr << e << '\n';

  } catch (const exception& e) {
    std::cerr << e.what() << '\n';

  } catch (...) {
    // Ловим всё что осталось и всё подряд. Ставить только в конце!!!
    cout << "Something went wrong!" << endl;
  }

  return 0;
}
