// Запись ОБЪЕКТА КЛАССА в файл с++. Чтение объекта из файла c++ Для начинающих.
// Урок 117
// https://youtu.be/imYmUAR4QBs

#include <string.h>

#include <fstream>
#include <iostream>

using namespace std;

class Point {
 public:
  int x;
  int y;
  int z;

  Point() { x = y = x = 0; }
  Point(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
  }
  void Print() {
    cout << "x = " << x << "\ty = " << y << "\tz = " << z << endl;
  }
};

int main() {
  const int LENGTH = 4;
  Point arrPoint[LENGTH] = {
      Point(12, 34, 67),
      Point(4, 67, 27),
      Point(67, 98, 5),
      Point(456, 35, 656),
  };

  string path = "003";

  // Записываем в файл объект класса

  ofstream fout;
  fout.open(path, ofstream::app);
  if (!fout.is_open()) {
    cout << "Error opening the file!" << endl;
  } else {
    cout << "The file is open!" << endl;
    for (int i = 0; i < LENGTH; i++) {
      fout.write((char*)&arrPoint[i], sizeof(Point));
    }
    cout << "The data was recorded." << endl;
  }
  fout.close();

  cout << endl;

  // Считываем из файла объект класса

  ifstream fin;
  fin.open(path);

  if (!fin.is_open()) {
    cout << "Error opening the file!" << endl;
  } else {
    cout << "The file is open!" << endl;
    Point pnt;  // Создаем объект куда запишем данные из файла.
    while (fin.read((char*)&pnt, sizeof(Point))) {
      // .read() - возвращает true или false
      pnt.Print();
    }
  }
  fin.close();

  return 0;
}
