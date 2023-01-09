// Перечисляемый тип enum С++. Изучение С++ для начинающих. Урок 124
// https://youtu.be/BMmbQ81lQd0

#include <string.h>

#include <iostream>

using namespace std;

class PC {
 public:
  enum PCState { OFF, ON, SLEEP };
  PCState GetState() { return State; }
  void SetState(PCState State) { this->State = State; }

 private:
  PCState State;
};

enum Speed { MIN = 150, RECOMMEND = 600, MAX = 800 };

int main() {
  PC pc;
  pc.SetState(PC::PCState::ON);

  if (pc.GetState() == PC::PCState::ON) {
    cout << "PC is worked!" << endl;
  }

  switch (pc.GetState()) {
    case PC::PCState::OFF:
      cout << "PC is off!" << endl;
      break;
    case PC::PCState::ON:
      cout << "PC is worked!" << endl;
      break;

    default:
      break;
  }

  cout << endl;

  Speed sp = Speed::MAX;
  cout << sp << endl;

  return 0;
}
