#ifndef _MY_CLASS_H_
#define _MY_CLASS_H_

#include <iostream>

namespace myNamespace {

class MyClass {
 public:
  MyClass();
  ~MyClass();

  void PrintMessage(const char str[]);
};

}  // namespace myNamespace

#endif  //  _MY_CLASS_H_
