// С++ try catch. Обработка исключений С++. try catch что это. Изучение С++ для
// начинающих. Урок 120
// https://youtu.be/jCW2wRoRi0U

#include <string.h>

#include <fstream>
#include <iostream>

using namespace std;

int main() {
  string path = "0011";

  ifstream fin;

  // ifstream уже имеет внутри себя обработку ошибок.
  // Принудительно отключаем обработку ошибок, чтоб самим их поймать:
  fin.exceptions(ifstream::badbit | ifstream::failbit);

  try {
    cout << "Попытка открыть файл!" << endl;
    fin.open(path);
    cout << "Файл успешно открыт!" << endl;

  } catch (const ifstream::failure& e) {
    cout << endl;
    std::cerr << e.code() << '\n';
    std::cerr << e.what() << '\n';

  } catch (const std::exception& e) {
    cout << endl;
    std::cerr << e.what() << '\n';
  }

  return 0;
}
