// vector | Библиотека стандартных шаблонов (stl) | Уроки | C++ | #1
// https://youtu.be/1cKvMZOJeeE

#include <iostream>
#include <vector>

using namespace std;

// vector - это прокаченный динамический массив на стероидах.

int main() {
  vector<int> myVector;
  myVector.push_back(2);
  myVector.push_back(4);
  myVector.push_back(65);
  myVector.push_back(32);

  for (int i = 0; i < myVector.size(); i++) {
    cout << myVector[i] << endl;
  }

  myVector[0] = 1000;

  // myVector[10] - когда мы используем оператор [] мы не проверяем границы
  // массива, получим неопределенное поведение.

  // myVector.at(10) - проверяет вышли ли мы за границы массива, он не даст
  // получить чужие и за границей области данные.
  // Этот метод работает медленнее чем оператор [].

  myVector.clear();     // Удаляет все элементы
  myVector.pop_back();  // Удаляем элемент с конца

  vector<int> myVector2 = {0, 484, 434, 5345};

  myVector2.reserve(100);  // задаем capacity вектора

  // .shrink_to_fit() - убираем из capacity неиспользуемые ячейки памяти.
  myVector2.shrink_to_fit();

  // .capacity() - Вместимость вектора, сколько элементов в нем может быть.
  myVector2.capacity();

  myVector2.size();  // Размер вектора, сколько элементов сейчас в нем есть.

  vector<int> myVector3(20);
  // задаем вектор в котором size() = 20 и capacity() = 20 и все элементы = 0

  vector<int> myVector3(20, 44);  // все 20 элементов = 44

  myVector3.empty();
  // возвращает true - если нет элементов, false - если есть.

  vector<int> myVector4;  // size() = 0 и capacity() = 0
  myVector4.resize(20);  // size() = 20 и capacity() = 20 и все элементы = 0
  myVector4.resize(20, 3);  // size() = 20 и capacity() = 20 и все элементы = 3

  // myVector2.insert();
  // myVector2.erase();

  return 0;
}
