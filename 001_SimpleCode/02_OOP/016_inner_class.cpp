// Вложенные классы с++ пример. Внутренние классы. Зачем нужны. inner class.
// ООП. Для начинающих #95
// https://youtu.be/wPzP8G6OLJM

#include <string.h>

#include <iostream>

using namespace std;

class Image {
 public:
  void GetImageInfo() {
    for (int i = 0; i < LENGTH; i++) {
      cout << "#" << i << " - " << pixel[i].GetInfo() << endl;
    }
  }

  class Pixel2 {
   public:
    Pixel2(int r, int g, int b) {
      this->r = r;
      this->g = g;
      this->b = b;
    }

    string GetInfo() {
      return "Pixel2: r = " + to_string(r) + " g = " + to_string(g) +
             " b = " + to_string(b);
    }

   private:
    int r;
    int g;
    int b;
  };

 private:
  class Pixel {
   public:
    Pixel(int r, int g, int b) {
      this->r = r;
      this->g = g;
      this->b = b;
    }

    string GetInfo() {
      return "Pixel: r = " + to_string(r) + " g = " + to_string(g) +
             " b = " + to_string(b);
    }

   private:
    int r;
    int g;
    int b;
  };

  static const int LENGTH = 5;

  Pixel pixel[5] = {Pixel(0, 4, 64), Pixel(4, 14, 10), Pixel(111, 4, 24),
                    Pixel(244, 244, 14), Pixel(111, 179, 64)};
};

int main() {
  Image image;
  image.GetImageInfo();

  Image::Pixel2 pixel2(24, 44, 111);
  cout << pixel2.GetInfo() << endl;

  return 0;
}
