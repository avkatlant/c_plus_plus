// Перегрузка операторов пример. ООП. Перегрузка оператора присваивания
// https://youtu.be/nMM98LVJn-U

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
    cout << "Size: " << Size << " - The constructor is called - " << this
         << endl;
  }

  // оператор присваивания, возвращает ссылку
  MyClass &operator=(const MyClass &other) {
    cout << "Size: " << Size << " - The operator = is called." << this << endl;

    this->Size = other.Size;

    if (this->data != nullptr) {
      delete[] this->data;
    }

    this->data = new int[other.Size];
    for (int i = 0; i < other.Size; i++) {
      this->data[i] = other.data[i];
    }

    return *this;
  }
};

int main(int argc, char *argv[]) {
  MyClass a(10);
  MyClass b(3);
  MyClass c(7);

  a = b;  // a.operator=(b);

  c = a = b;

  return 0;
}
