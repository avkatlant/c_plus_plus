// Потоковый ввод вывод в файл c++. Перегрузка операторов. Изучение С++ для
// начинающих. Урок 119
// https://youtu.be/z9m5XpOAxm0

#include <string.h>

#include <fstream>
#include <iostream>

using namespace std;

class Point {
 private:
  int x;
  int y;
  int z;

  // Делаем дружественные ф-ции, чтоб у нас был доступ к приватным
  // полям x, y, z.
  // Можно обойтись без дружественных ф-ций реализовав getters и setters.
  friend ostream& operator<<(ostream& os, const Point& point);
  friend istream& operator>>(istream& is, Point& point);

 public:
  Point() { x = y = x = 0; }
  Point(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
  }
};

// Перегрузка оператора вывода "<<""
ostream& operator<<(ostream& os, const Point& point) {
  os << point.x << " " << point.y << " " << point.z;
  return os;
}

// Перегрузка оператора ввода "">>""
istream& operator>>(istream& is, Point& point) {
  is >> point.x >> point.y >> point.z;
  return is;
}

int main() {
  string path = "005.txt";
  Point point(234, 345, 43);

  fstream fs;
  fs.open(path, fstream::in | fstream::out | fstream::app);

  if (!fs.is_open()) {
    cout << "Error opening the file!" << endl;
  } else {
    cout << "The file is open!" << endl;
    fs << point << '\n';

    fs.seekg(0);
    while (true) {
      Point p;
      fs >> p;
      if (fs.eof()) {
        break;
      }
      cout << p << endl;
    }
  }

  fs.close();

  return 0;
}
