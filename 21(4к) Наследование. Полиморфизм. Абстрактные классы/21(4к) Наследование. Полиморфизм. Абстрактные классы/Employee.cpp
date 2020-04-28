#include "Employee.h"

Employee::Employee():Person() {
    post = "";
    salary = 0;
}

Employee::Employee(string name, int age, string post, double salary):Person(name, age) {
    this -> post = post;
    this -> salary = salary;
}

Employee::Employee(const Employee& employee) {
    name = employee.name;
    age = employee.age;
    post = employee.post;
    salary = employee.salary;
}

Employee::~Employee() {}

void Employee::setPost(string post) {
    this -> post = post;
}

void Employee::setSalary(double salary, double bonus = 0) {
    bonus = salary * bonus / 100;
    this -> salary = salary + bonus;
}

Employee& Employee::operator =(const Employee& employee) {
    if(&employee == this) return *this;
    name = employee.name;
    age = employee.age;
    post = employee.post;
    salary = employee.salary;
    return *this;
}

istream& operator >>(istream& in, Employee& employee) {
    cout << "Введите\nИмя: "; in >> employee.name;
    cout << "Возраст: "; in >> employee.age;
    cout << "Должность: "; in >> employee.post;
    cout << "Оклад: "; in >> employee.salary;
    return in;
}

ostream& operator <<(ostream& out, const Employee& employee) {
    out << "Имя: " << employee.name << endl;
    out << "Возраст: " << employee.age << endl;
    out << "Должность: " << employee.post << endl;
    out << "Оклад: " << employee.salary << endl;
    return out;
}
