// MAP | MULTIMAP | Ассоциативные контейнеры | Библиотека стандартных шаблонов
// (stl) | Уроки | C++ #10
// https://youtu.be/QKrJRE-GnYU

#include <iostream>
#include <map>
#include <string>

using namespace std;

// map и multimap - Основаны на бинарном дереве
// Хранят в себе пару ключ и значение.
// Упорядоченная этого контейнера, построение бинарного дерева осуществляется по
// ключу, а значение к нему подвязывается.

// map - Хранит только уникальные элементы.

// multimap - Может хранить несколько одинаковых элементов в коллекции.
// Нету метода .at() и нельзя использовать [].

int main() {
  pair<int, string> p(1, "phone");
  cout << p.first << endl;
  cout << p.second << endl;

  map<int, string> myMap;

  // Добавление данных в map
  myMap.insert(make_pair(1, "phone"));
  myMap.insert(pair<int, string>(2, "notebook"));
  // insert - либо копирует либо перемещает объект
  myMap.emplace(3, "monitor");
  // emplace - создает объект в момент выполнения
  myMap.emplace(4, "keyboard");

  cout << endl;

  myMap.emplace(22, "mouse");

  // Ищем элемент по значению, если находим,
  // то возвращаем итератор который указывает на этот элемент (ключ - значение).
  auto it = myMap.find(22);
  cout << it->first << endl;
  cout << it->second << endl;
  // Если элемент не найден, то вернет myMap.end()
  auto it2 = myMap.find(44);
  if (it2 != myMap.end()) {
    cout << it2->first << endl;
    cout << it2->second << endl;
  } else {
    cout << "Element not found." << endl;
  }

  cout << endl;

  // Если попробуем добавить элемент с ключом который уже есть,
  // он не добавиться в map
  myMap.emplace(22, "qweqwrerwer");
  auto it3 = myMap.find(22);
  cout << it3->first << endl;
  cout << it3->second << endl;

  cout << endl;

  // Проверка - получилось добавить в map или нет
  auto result = myMap.emplace(55, "submonitor");
  cout << result.first->first << "  " << result.first->second << endl;
  cout << result.second << endl;  // 1 - добавлен, 0 - не добавлен

  cout << endl;

  // Получаем значение элемента по ключу
  cout << myMap[3] << endl;
  cout << myMap[4] << endl;
  cout << myMap[22] << endl;

  cout << endl;

  map<string, int> myMap2;

  myMap2.emplace("Petya", 111);
  myMap2.emplace("Masha", 222);
  myMap2.emplace("Misha", 333);

  cout << myMap2["Petya"] << endl;
  cout << myMap2["Masha"] << endl;
  cout << myMap2["Misha"] << endl;

  cout << endl;

  myMap2["Petya"] = 42324;
  // если ключ в [] есть, то заменит значение.
  myMap2["Vasia"] = 5345;
  // если ключа в [] нет, то добавит в map элемент с этим ключом и значением.
  cout << myMap2["Petya"] << endl;
  cout << myMap2["Vasia"] << endl;

  myMap2["Vasia"] = 777;
  // если обратимся к уже существующему ключу, то заменим значение.
  cout << myMap2["Vasia"] << endl;

  cout << endl;

  myMap2.at("Petya") = 8888;
  // myMap2.at("Vasilisa") = 434554;
  // если такого ключа нет в map, то будет вызвано исключение.

  cout << endl;

  // Удаление элемента
  myMap2.erase("Petya");

  cout << endl;

  auto itMap = myMap2.begin();
  for (auto i = itMap; i != myMap2.end(); i++) {
    cout << i->first << "  ";
    cout << i->second << endl;
  }
  cout << endl;
  for (auto el : myMap2) {
    cout << el.first << "  ";
    cout << el.second << endl;
  }

  return 0;
}

/*

*/
