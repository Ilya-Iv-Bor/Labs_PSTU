#pragma once
#include "iostream"
#include "Person.hpp"

//класс Employee наследуется от класса Person
class Employee: public Person {
protected:
    string post;
    float salary;
public:
    Employee();
    Employee(string, int, string, float);
    Employee(const Employee &employee);
    ~Employee();

    void show();
    void input();

    void setPost(string);
    void setSalary(float);
    string getPost() { return post; }
    float getSalary() { return salary; }
    
    Employee& operator =(const Employee& employee);
    friend istream& operator >>(istream& in, Employee& employee);
    friend ostream& operator <<(ostream& out, const Employee& employee);
};
