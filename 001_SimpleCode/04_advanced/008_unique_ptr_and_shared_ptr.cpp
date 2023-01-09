// auto_ptr | unique_ptr | shared_ptr | Умные указатели. Изучение С++ для
// начинающих. Урок 131
// https://youtu.be/dpRozfXepnA

#include <string.h>

#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class SmartPointer {
 public:
  SmartPointer(T *ptr) {
    this->ptr = ptr;
    cout << "Constructor was called" << endl;
  }

  ~SmartPointer() {
    delete ptr;
    cout << "Destructor was called" << endl;
  }

  T &operator*() { return *ptr; }

 private:
  T *ptr;
};

int main() {
  // SmartPointer<int> sp1 = new int(5);
  // SmartPointer<int> sp2 = sp1;

  // auto_ptr - устарел !!!
  // auto_ptr<int> ap1(new int(5));
  // auto_ptr<int> ap2(ap1);

  /////////////////////////////////////////////////
  /////////////////////////////////////////////////

  // два указателя unique_ptr не могут ссылаться на одну область памяти!
  unique_ptr<int> p1(new int(5));
  unique_ptr<int> p2;

  cout << *p1 << endl;
  // cout << *p2 << endl;  // segmentation fault

  // чтоб сменить владельца данных
  p2 = std::move(p1);
  // или аналог -> .swap() - это метод самого unique_ptr
  // p2.swap(p1);

  // cout << *p1 << endl;  // segmentation fault
  cout << *p2 << endl;

  // .get() - возвращает указатель, в сыром чистом виде,
  // то есть указатель примитивного типа.
  int *p = p1.get();

  int *pr = new int(7);
  unique_ptr<int> pru(pr);
  pru.reset();
  // .reset() - затирает данные на которые указывает указатель pru
  // и затирает сам указатель, pru становится пустым.

  pru.release();
  // .release() - данные остаются в памяти, но указатель pru становится пустым.

  cout << endl;
  /////////////////////////////////////////////////
  /////////////////////////////////////////////////

  // shared_ptr - владение несколькими указателями одного
  // и того же объекта в памяти
  shared_ptr<int> shp1(new int(5));
  shared_ptr<int> shp2(shp1);
  cout << &shp1 << " - " << shp1 << " - " << *shp1 << endl;
  cout << &shp2 << " - " << shp2 << " - " << *shp2 << endl;

  // Когда shared_ptr указывающие на один объект, будут уничтожатся выходя из
  // зоны видимости, то ошибки не будет, потому-что данные будут уничтожены
  // только в тот момент, когда будет уничтожен самый последний shared_ptr,
  // который ссылается на эти данные.

  return 0;
}

/*
5
5

0x7ffee6daf5d0 - 0x7fe6124058b0 - 5
0x7ffee6daf5b8 - 0x7fe6124058b0 - 5
*/
