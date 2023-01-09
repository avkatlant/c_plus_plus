// Итераторы STL | Библиотека стандартных шаблонов (stl) | Уроки | C++ | #2
// https://youtu.be/jLPqLW2Bp_w

// Итераторы stl c++ | prefix vs postfix | Библиотека стандартных шаблонов (stl)
// | Уроки | C++ | #4
// https://youtu.be/rOERRxd5Mqc

#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> myVector = {243, 345, 546, 32, 65};
  vector<int>::iterator it;  // создаем итератор

  it = myVector.begin();
  // метод .begin() дал доступ нашему итератору к первому элементу

  cout << *it << endl;
  it++;
  cout << *it << endl;
  it += 2;
  cout << *it << endl;
  it--;
  cout << *it << endl;

  cout << endl;

  vector<int> myVector2 = {65, 35, 67, 232, 76, 345, 90};

  // myVector2.end();
  // .end() - этот метод указывает на следующий элемент,
  // который идет после последнего элемента контейнера.

  for (vector<int>::iterator i = myVector2.begin(); i != myVector2.end(); i++) {
    cout << *i << "  ";
    // *i = 5; // Можно менять данные.
  }

  cout << endl << endl;

  // Константный итератор
  // Чтоб запретить изменения данных при итерациях
  for (vector<int>::const_iterator i = myVector2.cbegin();
       i != myVector2.cend(); i++) {
    // *i = 5; // Вызовет ошибку!
    cout << *i << "  ";
  }

  cout << endl << endl;

  // Итерация с конца
  for (vector<int>::reverse_iterator i = myVector2.rbegin();
       i != myVector2.rend(); i++) {
    cout << *i << "  ";
  }

  cout << endl << endl;

  // Сдвиг итератора
  vector<int>::iterator it2 = myVector2.begin();
  advance(it2, 3);  // сдвигаем итератор на указанное кол-во элементов
  cout << *it2 << endl;  // == cout << *(it2 + 3) << endl;

  cout << endl << endl;

  // Вставляем элемент
  vector<int>::iterator it3 = myVector.begin();
  myVector.insert(it3, 999);
  for (vector<int>::iterator it3 = myVector.begin(); it3 != myVector.end();
       it3++) {
    cout << *it3 << "  ";
  }

  cout << endl << endl;

  // Стираем элемент
  vector<int>::iterator it4 = myVector.begin();
  myVector.erase(it4);
  for (vector<int>::iterator it4 = myVector.begin(); it4 != myVector.end();
       it4++) {
    cout << *it4 << "  ";
  }

  cout << endl << endl;

  // Стираем диапазон элементов
  vector<int>::iterator it5 = myVector.begin();
  myVector.erase(it5, it5 + 3);
  for (vector<int>::iterator it5 = myVector.begin(); it5 != myVector.end();
       it5++) {
    cout << *it5 << "  ";
  }
  cout << endl;

  return 0;
}

/*
243
345
32
546

65  35  67  232  76  345  90

65  35  67  232  76  345  90

90  345  76  232  67  35  65

232


999  243  345  546  32  65

243  345  546  32  65

32  65
*/
