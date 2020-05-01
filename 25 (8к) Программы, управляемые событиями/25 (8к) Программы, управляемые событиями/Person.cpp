#include "iostream"
#include "Person.hpp"

Person::Person() {
    setlocale(LC_ALL, "ru");
    name = ""; age = 0;
}

Person::Person(string name, int age) {
    setlocale(LC_ALL, "ru");
    this -> name = name;
    this -> age = age;
}

Person::Person(const Person& person) {
    setlocale(LC_ALL, "ru");
    name = person.name;
    age = person.age;
}

Person::~Person() {}

void Person::show() {
    setlocale(LC_ALL, "ru");
    cout << "Имя: " << name << "\nВозраст : " << age << endl;
}

void Person::input() {
    setlocale(LC_ALL, "ru");
    cout << "Введите\nИмя: "; cin >> name;
    cout << "Возраст: "; cin >> age;
}

void Person::handleEvent(const TEvent& event) {
    if(event.what == evMessage) {
        switch(event.command) {
        case cmGet:
            cout << "Имя: " << getName() << endl; break;
        }
    }
}

void Person::setName(string name) { this -> name = name; }
void Person::setAge(int age) { this -> age = age; }

Person& Person::operator =(const Person& person) {
    setlocale(LC_ALL, "ru");
    if(&person == this) return *this;
    
    name = person.name;
    age = person.age;
    return *this;
}

istream& operator >>(istream& in, Person& person) {
    setlocale(LC_ALL, "ru");
    cout << "Введите\nИмя: "; in >> person.name;
    cout << "Возраст: "; in >> person.age;
    return in;
}

ostream& operator <<(ostream& out, const Person& person) {
    setlocale(LC_ALL, "ru");
    out << "Имя: " << person.name << "\nВозраст : " << person.age;
    return out;
}

