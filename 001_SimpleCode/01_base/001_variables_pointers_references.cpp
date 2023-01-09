// переменные, указатели, ссылки

#include <iostream>

int main() {
  int a = 5;      // переменная = значение
  int *pa = &a;   // указатель = адрес ячейки
  int &aref = a;  // ссылка = переменная (но хранится адрес ячейки)

  std::cout << "*pa\t" << *pa << std::endl;     // *pa     5
  std::cout << "pa\t" << pa << std::endl;       // pa      0x7ffee39465e8
  std::cout << "&aref\t" << aref << std::endl;  // &aref   5

  (*pa)++;
  std::cout << "*pa\t" << *pa << std::endl;     // *pa     6
  std::cout << "pa\t" << pa << std::endl;       // pa      0x7ffee91ac5e8
  std::cout << "&aref\t" << aref << std::endl;  // &aref   6

  *pa = -20;
  std::cout << "*pa\t" << *pa << std::endl;     // *pa     -20
  std::cout << "pa\t" << pa << std::endl;       // pa      0x7ffee4fb75e8
  std::cout << "&aref\t" << aref << std::endl;  // &aref   -20

  // Смотрим что в соседних ячейках (арифметика указателей):
  std::cout << "*(pa + 1)\t" << *(pa + 1) << std::endl;  // *(pa + 1)       0
  std::cout << "*(pa + 1)\t" << *(pa + 2) << std::endl;  // *(pa + 1) -274250232

  aref++;
  std::cout << "aref++\t" << aref << std::endl;  // aref++  -19
  aref = aref + 2;
  std::cout << "aref++\t" << aref << std::endl;  // aref++  -17
  aref = 55;
  std::cout << "aref++\t" << aref << std::endl;  // aref++  55
  std::cout << "a\t" << a << std::endl;          // a  55
  std::cout << "*pa\t" << *pa << std::endl;      // *pa  55

  //
  // int *pp;  // так можно
  // int *pp = NULL;
  // int *pp = 0;
  // int *pp = nullptr;
  // int &pref;  // так нельзя! нам нужно обязательно инициализировать ссылку.

  // взаимодействие ссылок и указателей
  int b = 8;
  int *pb = &b;
  int &bref2 = *pb;
  int *ppb = &bref2;  // записываем в указатель ссылку
  std::cout << "b\t" << b << std::endl;  // b       8
  *ppb = 12;
  std::cout << "b\t" << b << std::endl;  // b       12

  return 0;
}

// Ссылка и указатель хранят в себе адрес ячейки.
// У ссылок нет оператора разыменования.
// У указателей есть арифметика указателей, у ссылок такого нет.
