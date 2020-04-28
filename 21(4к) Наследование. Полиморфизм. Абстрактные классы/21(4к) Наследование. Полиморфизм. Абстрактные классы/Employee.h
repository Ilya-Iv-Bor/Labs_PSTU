#pragma once
#include "iostream"
#include "Person.h"

//класс Employee наследуется от класса Person
class Employee: public Person {
    public:
        Employee();
        Employee(string, int, string, double);
        Employee(const Employee &employee);
        ~Employee();
    
        void setPost(string);
        void setSalary(double, double);
        string getPost() { return post; }
        int getSalary() { return salary; }
        
        Employee& operator =(const Employee& employee);
        friend istream& operator >>(istream& in, Employee& employee);
        friend ostream& operator <<(ostream& out, const Employee& employee);
    protected:
        string post;
        double salary;
};
