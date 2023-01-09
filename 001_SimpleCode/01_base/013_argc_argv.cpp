#include <iostream>

int main(int argc, char *argv[]) {
  // argc - количество переданных параметров
  // argv - значение параметров
  for (int i = 0; i < argc; i++) {
    std::cout << argv[i] << std::endl;
  }

  return 0;
}
