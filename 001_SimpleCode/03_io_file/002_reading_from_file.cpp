// Работа с файлами с++. Чтение из файла с++ ifstream. Изучение С++ для
// начинающих. Урок 116
// https://youtu.be/aUP0eAEIxog

#include <string.h>

#include <fstream>
#include <iostream>

using namespace std;

int main() {
  string path = "001_write_to_file.txt";

  ifstream fin;
  fin.open(path);
  // Если файла path не существует, то ф-ция open() его НЕ создаст.

  // Для проверки открылся файл или нет, лучше использовать try ... cath
  if (!fin.is_open()) {
    cout << "Error opening the file!" << endl;
  } else {
    cout << "The file is open!" << endl;

    // char ch;
    // // fin.get(n);
    // // Считывает посимвольно и записывает в переменную n,
    // // возвращает true или false.
    // while (fin.get(ch)) {
    //   cout << ch;
    // }

    string str1;
    while (!fin.eof()) {
      str1 = "";

      // fin >> str;
      // fin >> - считывает до первого пробела

      std::getline(fin, str1);
      // getline - считывает построчно

      cout << str1 << endl;
    }
    fin.close();

    cout << endl;

    ifstream fin;
    fin.open(path);
    // Можно использовать getline от ifstream, но он не совсем удобен,
    // необходимо указывать длину массива char.
    char str2[50];
    while (!fin.eof()) {
      fin.getline(str2, 50);
      cout << str2 << endl;
    }
  }

  fin.close();

  return 0;
}
