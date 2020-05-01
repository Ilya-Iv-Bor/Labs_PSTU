#include "Vector.hpp"
#include "Person.hpp"
#include "Employee.hpp"
#include <iostream>

using namespace std;

Vector::Vector(int size) {
    beg = new Object*[size];
    current = 0;
    this -> size = size;
}

Vector::~Vector() {
    if(beg != 0) delete[] beg;
    beg = 0;
}

void Vector::add() {
    Object *obj;
    int choice;
    //выбор из объектов двух возможных классов
    cout << "1.Person\n" << "2.Employee\n" << "Выбор: "; cin >> choice;
    
    if(choice == 1) {
        Person *person = new Person;
        person -> input();
        obj = person;
        if(current < size) {
            beg[current] = obj; // добавление в вектор
            current++;
        }
    } else if(choice == 2) {
        Employee *employee = new Employee;
        employee -> input();
        obj = employee;
        if(current < size) {
            beg[current] = obj;
            current++;
        }
    } else return;
}

void Vector::show() {
    if(current == 0) { cout << "Empty\n"; return; }
    
    Object **obj = beg;
    for(int i = 0; i < current; i++) {
        (*obj) -> show(); //вызов метода Show() (позднее связывание)
        obj++;
    }
}

void Vector::handleEvent(const TEvent& event) {
    if(event.what == evMessage) {
        Object **obj = beg;
        if (event.parameter <= size && event.parameter > 0) {
            for(int i = 1; i < event.parameter; i++) { obj++; };  // передвигаем указатель на следующий объект
            (*obj) -> handleEvent(event); // Вызов метода (позднее связывание)
        } else {
            cout << "Empty!"; return;
        }
    }
}


int Vector::operator ()() {
    return current;
}
//удаление элемента из вектора, память не освобождается!
void Vector::remove() {
    if(current == 0) { cout << "Empty\n"; return; }
    current--;
}
