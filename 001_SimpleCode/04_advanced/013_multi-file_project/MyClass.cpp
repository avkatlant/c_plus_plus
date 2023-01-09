#include "MyClass.h"

namespace myNamespace {

MyClass::MyClass() {}

MyClass::~MyClass() {}

void MyClass::PrintMessage(const char str[]) { std::cout << str << std::endl; }

}  // namespace myNamespace
