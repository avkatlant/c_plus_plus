#include <iostream>
#define FOO(x, y) ((x) * (y))
#define DEBUG
#define DEBUG2 5

int main() {
  std::cout << FOO(5, 6) << std::endl;

#ifdef DEBUG
  std::cout << "Debug is defined" << std::endl;
#else
  std::cout << "Debug is not defined" << std::endl;
#endif  // DEBUG

#ifndef DEBUG
  std::cout << "Debug is not defined" << std::endl;
#else
  std::cout << "Debug is defined" << std::endl;
#endif  // DEBUG

#if DEBUG2 > 4
  std::cout << "Debug > 4" << std::endl;
#elif DEBUG2 == 6
  std::cout << "Debug == 6" << std::endl;
#else
  std::cout << "Debug < 4" << std::endl;
#endif  // DEBUG2

  return 0;
}
