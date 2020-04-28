// 21(4к) Наследование. Полиморфизм. Абстрактные классы.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include "Person.h"
#include "Employee.h"


Person getPersonFromEmployee(Person& person) {
    return person;
}

int main() {
    setlocale(LC_ALL, "ru");
    // Person 20
    Person firstPerson;
    cin >> firstPerson;
    cout << firstPerson << endl;
    Person secondPerson("Ivan", 20);
    cout << secondPerson << endl;

    firstPerson = secondPerson;
    cout << firstPerson << endl;

    firstPerson.setName("Petr");
    firstPerson.setAge(23);
    cout << firstPerson << endl;


    // Employee
    Employee firstEmployee;
    cin >> firstEmployee;
    cout << firstEmployee;

    Employee secondEmployee("Halk", 25, "Admin", 2000);
    cout << secondEmployee << endl;

    firstEmployee = secondEmployee;
    cout << firstEmployee << endl;

    firstEmployee.setPost("Teacher");
    firstEmployee.setSalary(4000, 20);
    cout << firstEmployee << endl;


    Person person = getPersonFromEmployee(secondEmployee);
    cout << "Получаем имя: " << person.getName() << endl;
    cout << "Получаем возраст: " << person.getAge() << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
