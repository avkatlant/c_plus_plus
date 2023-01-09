// Конструктор копирования. Что это. Пример. Когда вызывается Копирование
// объектов по умолчанию
// https://youtu.be/3x9nd6Tm7Pc

#include <iostream>

using namespace std;

class MyClass {
 private:
  int Size;

 public:
  int *data;

  MyClass(int size) {
    this->Size = size;
    this->data = new int[size];
    for (int i = 0; i < size; i++) {
      data[i] = i;
    }
    cout << "Size: " << Size << " The constructor is called - " << this << endl;
  }

  // Конструктор копирования
  MyClass(const MyClass &other) {
    this->Size = other.Size;
    this->data = new int[other.Size];
    for (int i = 0; i < other.Size; i++) {
      this->data[i] = other.data[i];
    }
    cout << "Size: " << Size << " The copy constructor is called - " << this
         << endl;
  }

  ~MyClass() {
    delete[] data;
    data = nullptr;
    cout << "Size: " << Size << " The destructor is called - " << this << endl;
  }
  int GetSize() { return Size; }
  void SetSize(int valueSize) { this->Size = valueSize; }
};

void Foo(MyClass value) {
  value.SetSize(5);
  cout << "Size: " << value.GetSize() << " The Foo is called - " << &value
       << endl;
}

MyClass Foo2() {
  MyClass temp(2);
  cout << "Size: " << temp.GetSize() << " The Foo2 is called." << endl;
  return temp;
}

int main() {
  cout << "#1" << endl;
  MyClass a(10);
  cout << endl;

  cout << "#2" << endl;
  Foo(a);
  cout << endl;

  cout << "#3" << endl;
  Foo2();
  cout << endl;

  cout << "#4" << endl;
  MyClass b(a);  // запись эквивалентна MyClass b = a, если b еще не был создан
  cout << endl;

  return 0;
}

/*
#1
Size: 10 The constructor is called - 0x7ffee446f658

#2
Size: 10 The copy constructor is called - 0x7ffee446f638
Size: 5 The Foo is called - 0x7ffee446f638
Size: 5 The destructor is called - 0x7ffee446f638

#3
Size: 2 The constructor is called - 0x7ffee446f628
Size: 2 The Foo2 is called.
Size: 2 The destructor is called - 0x7ffee446f628

#4
Size: 10 The copy constructor is called - 0x7ffee446f618

Size: 10 The destructor is called - 0x7ffee446f618
Size: 10 The destructor is called - 0x7ffee446f658
*/
