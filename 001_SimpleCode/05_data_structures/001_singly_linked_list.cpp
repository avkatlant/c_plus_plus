// Односвязный список | Динамические структуры данных #1
// https://youtu.be/C9FK1pHLnhI

// Реализация односвязного списка c++ Часть 1 | Урок 133
// https://youtu.be/SajrPhE6FoQ

// Реализация односвязного списка c++ Часть 2 | Урок 134
// https://youtu.be/8E6cPXE-IIA

// Реализация односвязного списка c++ Часть 3 | Урок 135
// https://youtu.be/tj17qdFMj54

#include <string.h>

#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class List {
 public:
  List();
  ~List();

  void push_back(T data);
  void pop_front();
  void clear();
  void push_front(T data);
  void insert(T data, int index);
  void removeAt(int index);
  void pop_back();

  T &operator[](const int index);

  int GetSize() { return Size; }

 private:
  template <typename>
  class Node {
   public:
    Node *pNext;
    T data;

    Node(T data = T(), Node *pNext = nullptr) {
      this->data = data;
      this->pNext = pNext;
    }
  };

  Node<T> *head;
  int Size;
};

template <typename T>
List<T>::List() {
  Size = 0;
  head = nullptr;
}

template <typename T>
List<T>::~List() {
  clear();
}

template <typename T>
void List<T>::push_back(T data) {
  if (head == nullptr) {
    head = new Node<T>(data);
  } else {
    Node<T> *current = this->head;
    while (current->pNext != nullptr) {
      current = current->pNext;
    }
    current->pNext = new Node<T>(data);
  }
  Size++;
}

template <typename T>
T &List<T>::operator[](const int index) {
  int counter = 0;
  Node<T> *current = this->head;
  while (current != nullptr) {
    if (counter == index) {
      break;
    }
    current = current->pNext;
    counter++;
  }
  return current->data;
}

template <typename T>
void List<T>::pop_front() {
  Node<T> *temp = head;
  head = head->pNext;
  delete temp;
  Size--;
}

template <typename T>
void List<T>::clear() {
  while (Size) {
    pop_front();
  }
}

template <typename T>
void List<T>::push_front(T data) {
  head = new Node<T>(data, head);
  Size++;
}

template <typename T>
void List<T>::insert(T data, int index) {
  if (index == 0) {
    push_front(data);
  } else {
    Node<T> *previous = this->head;
    for (int i = 0; i < index - 1; i++) {
      previous = previous->pNext;
    }
    Node<T> *newNode = new Node<T>(data, previous->pNext);
    previous->pNext = newNode;
    Size++;
  }
}

template <typename T>
void List<T>::removeAt(int index) {
  if (index == 0) {
    pop_front();
  } else {
    Node<T> *previous = this->head;
    for (int i = 0; i < index - 1; i++) {
      previous = previous->pNext;
    }
    Node<T> *toDelete = previous->pNext;
    previous->pNext = toDelete->pNext;
    delete toDelete;
    Size--;
  }
}

template <typename T>
void List<T>::pop_back() {
  removeAt(Size - 1);
}

template <typename T>
void PrintList(List<T> &lst) {
  for (int i = 0; i < lst.GetSize(); i++) {
    cout << lst[i] << "  ";
  }
}

int main() {
  List<int> lst;

  int numberCount;
  cin >> numberCount;
  for (int i = 0; i < numberCount; i++) {
    lst.push_back(rand() % 10);
  }

  cout << "Size: " << lst.GetSize() << endl;
  PrintList(lst);
  cout << endl << endl;

  cout << "Выполнить метод pop_front, кол-во: ";
  int numberPopFront;
  cin >> numberPopFront;
  for (int i = 0; i < numberPopFront; i++) {
    lst.pop_front();
  }
  PrintList(lst);
  cout << endl << endl;

  cout << "Выполнить метод push_front, кол-во: ";
  int numberPushFront;
  cin >> numberPushFront;
  for (int i = 0; i < numberPushFront; i++) {
    lst.push_front(rand() % 10);
  }
  PrintList(lst);
  cout << endl << endl;

  cout << "Вставить новый элемент с индексом: ";
  int numberIndex;
  cin >> numberIndex;
  lst.insert(99, numberIndex);
  PrintList(lst);
  cout << endl << endl;

  cout << "Удалить элемент с индексом: ";
  int numberDelIndex;
  cin >> numberDelIndex;
  lst.removeAt(numberDelIndex);
  PrintList(lst);
  cout << endl << endl;

  cout << "Выполнить метод pop_back, кол-во: ";
  int numberPopBack;
  cin >> numberPopBack;
  for (int i = 0; i < numberPopBack; i++) {
    lst.pop_back();
  }
  PrintList(lst);
  cout << endl << endl;

  return 0;
};
