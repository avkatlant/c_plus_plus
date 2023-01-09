// Пространства имен с++. namespace c++ что это. Изучение С++ для начинающих.
// Урок 125
// https://youtu.be/Ec4RBF11S3I

#include <string.h>

#include <iostream>

using namespace std;

namespace firstNS {
void Foo() { cout << "firstNS Foo" << endl; }
}  // namespace firstNS

namespace secondNS {
void Foo() { cout << "secondNS Foo" << endl; }
}  // namespace secondNS

namespace thirdNS {
namespace secondNS {
void Foo() { cout << "thirdNS secondNS Foo" << endl; }
}  // namespace secondNS
}  // namespace thirdNS

int main() {
  firstNS::Foo();
  secondNS::Foo();
  thirdNS::secondNS::Foo();

  return 0;
}
