// Работа с файлами с++. Запись в файл. c++ ofstream. Изучение С++ для
// начинающих. Урок 115
// https://youtu.be/CBnB2fvfu_I

#include <string.h>

#include <fstream>
#include <iostream>

using namespace std;

int main() {
  string path = "001_write_to_file.txt";

  ofstream fout;
  // fout.open(path);
  fout.open(path, ofstream::app);
  // Если файла path не существует, то ф-ция open() его создаст.
  // ofstream::app - указывает что нужно дописывать в файл, а не затирать
  // предыдущие данные

  // Для проверки открылся файл или нет, лучше использовать try ... cath
  if (!fout.is_open()) {
    cout << "Error opening the file!" << endl;
  } else {
    fout << "This is our data!" << endl;
    fout << 555 << endl;

    cout << "Inter a number: ";
    int a;
    cin >> a;
    fout << a << endl;
  }

  fout.close();

  return 0;
}
