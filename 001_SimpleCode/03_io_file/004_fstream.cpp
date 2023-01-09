// Чтение и запись в файл с++ используя класс fstream c++. Изучение С++ для
// начинающих. Урок 118
// https://youtu.be/bTysglLJ8No

#include <string.h>

#include <fstream>
#include <iostream>

using namespace std;

int main() {
  string path = "004.txt";

  fstream fs;
  fs.open(path, fstream::in | fstream::out | fstream::app);
  // fstream::in - можем считывать
  // fstream::out - можем записывать
  // fstream::app - можем дописывать

  if (!fs.is_open()) {
    cout << "Error opening the file!" << endl;
  } else {
    cout << "The file is open!" << endl;

    cout << "1 - запись сообщения в файл" << endl;
    cout << "2 - считать все сообщения из файла" << endl;

    string msg;
    int value;
    cin >> value;

    if (value == 1) {
      cin >> msg;
      fs << msg << endl;
    }
    if (value == 2) {
      fs.seekg(0);  // возвращаемся в начало файла
      while (!fs.eof()) {
        msg = "";
        fs >> msg;
        cout << msg << endl;
      }
    }
  }

  fs.close();

  return 0;
}
