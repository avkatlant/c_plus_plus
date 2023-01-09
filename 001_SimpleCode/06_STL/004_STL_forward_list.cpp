// forward list stl c++ | Библиотека стандартных шаблонов (stl) | Уроки | C++ |
// #5
// https://youtu.be/s0SP6euQXCc

#include <forward_list>
#include <iostream>
#include <vector>

using namespace std;

// forward_list - реализован на основе односвязного списка

// Быстро выполняются операции в начале списка,
// операции в середине и конце медленно.

int main() {
  forward_list<int> fl = {345, 756, 2, 75};
  fl.push_front(1);
  fl.push_front(4);

  // for (auto el : fl) {
  //   cout << el << "  ";
  // }

  forward_list<int>::iterator it = fl.begin();
  it++;
  cout << *it << endl;

  fl.insert_after(it, 9999);
  for (auto el : fl) {
    cout << el << "  ";
  }
  cout << endl;

  it++;
  fl.erase_after(it);
  for (auto el : fl) {
    cout << el << "  ";
  }
  cout << endl;

  return 0;
}

/*
1
4  1  9999  345  756  2  75
4  1  9999  756  2  75
*/
