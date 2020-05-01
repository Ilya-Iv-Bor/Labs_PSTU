#pragma once
#include "iostream"
#include "Object.hpp"

using namespace std;

class Person: public Object {
protected:
    string name;
    int age;
public:
    Person(); // Конструктор без параметров
    Person(string, int); // Констрктор с параметрами
    Person(const Person&); // Конструктор копирования
    virtual ~Person(); // Деструктор
        
    void show();
    void input();
    
    // Селекторы // Модификаторы
    string getName() { return name; }
    int getAge() { return age; }
    void setName(string);
    void setAge(int);

    // Перегрузка операции присваивания
    Person& operator =(const Person&);

    // Глобальные операторы-функции ввода-вывода
    friend istream& operator >>(istream& in, Person& person);
    friend ostream& operator <<(ostream& out, const Person& person);
    
    void handleEvent(const TEvent&);
};
