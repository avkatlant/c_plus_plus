// Перегрузка оператора индексирования

#include <iostream>

using namespace std;

class TestClass {
 private:
  int arr[5] = {5, 44, 4, 987, 69};

 public:
  int &operator[](int index) { return arr[index]; }
};

int main() {
  TestClass a;
  cout << a[3] << endl;
  return 0;
}
