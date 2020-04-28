#include "Person.h"

Person::Person() {
    name = "";
    age = 0;
}

Person::Person(string name, int age) {
    this -> name = name;
    this -> age = age;
}

Person::Person(const Person& person) {
    name = person.name;
    age = person.age;
}

Person::~Person() {}

void Person::setName(string name) { this -> name = name; }
void Person::setAge(int age) { this -> age = age; }

Person& Person::operator =(const Person& person) {
    if(&person == this) return *this;
    
    name = person.name;
    age = person.age;
    return *this;
}

istream& operator >>(istream& in, Person& person) {
    cout << "Введите\nИмя: "; in >> person.name;
    cout << "Возраст: "; in >> person.age;
    return in;
}

ostream& operator <<(ostream& out, const Person& person) {
    out << "Имя: " << person.name << "\nВозраст : " << person.age;
    return out;
}
