#pragma once
#include <iostream>

using namespace std;

class Person {
    public:
        Person(); // Конструктор без параметров
        Person(string, int); // Констрктор с параметрами
        Person(const Person&); // Конструктор копирования
        virtual ~Person(); // Деструктор
    
        // Селекторы
        string getName() { return name; }
        int getAge() { return age; }
        // Модификаторы
        void setName(string);
        void setAge(int);
    
        // Перегрузка операции присваивания
        Person& operator =(const Person&);
    
        // Глобальные операторы-функции ввода-вывода
        friend istream& operator >>(istream& in, Person& person);
        friend ostream& operator <<(ostream& out, const Person& person);
    // Атрибуты
    protected:
        string name;
        int age;
};
