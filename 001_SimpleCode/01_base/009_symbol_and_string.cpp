#include <iostream>

void PrintStr(const char *str) { std::cout << str << std::endl; }

void PrintStrArray(const char *strArray[]) {
  for (int i = 0; i < 3; i++) {
    std::cout << strArray[i] << std::endl;
  }
}

int main() {
  char symbol = 'c';

  char string1[] = "hello world";
  char string2[] = {'h', 'e', 'l', 'l', 'o', '\0'};

  const char *string3 = "Hello";

  const char *strArray[] = {"Hello", "World", "TEST"};
  for (int i = 0; i < 3; i++) {
    std::cout << strArray[i] << std::endl;
  }

  std::cout << std::endl;

  PrintStr(string3);

  std::cout << std::endl;

  PrintStrArray(strArray);

  return 0;
}
