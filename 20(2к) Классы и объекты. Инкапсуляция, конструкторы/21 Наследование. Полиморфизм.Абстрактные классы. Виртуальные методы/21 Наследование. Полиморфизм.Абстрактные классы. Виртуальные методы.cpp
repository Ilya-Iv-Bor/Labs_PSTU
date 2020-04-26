// 21 Наследование. Полиморфизм.Абстрактные классы. Виртуальные методы.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "enrollee.h"
#include <iostream>
#include <string>


using namespace std;

// Функция для возврата объекта как результата
Enrollee makeEnrollee() {
  
    string fn;
    string s;
    int ep;
    //Stepanov Stepan Stepanovich

    cout << "Введите ФИО абитуриента: "; getline(cin, fn);
    cout << "Введите специальность: "; getline(cin, s);
    cout << "Введите балл ЕГЭ: "; cin >> ep;

    Enrollee enrollee(fn, s, ep);
    return enrollee;
}


// Функция для передачи объекта как параметра
void printEnrollee(Enrollee enrollee) {
    enrollee.show();
}

int main() {
    setlocale(LC_ALL, "ru");
    //конструктор без параметров
    Enrollee firstEnrollee;
    firstEnrollee.show();

    //коструктор с параметрами
    Enrollee secondEnrollee("Ivanov Ivan Ivanovich", "IVT", 300);
    secondEnrollee.show();

    //конструктор копирования
    Enrollee thirdEnrollee = secondEnrollee;
    thirdEnrollee.setFullName("Petrov Petr Petrovich");
    thirdEnrollee.setSpeciality("RIS");
    thirdEnrollee.setExamPoint(250);

    //конструктор копирования
    printEnrollee(thirdEnrollee);

    //конструктор копирования
    firstEnrollee = makeEnrollee();
    firstEnrollee.show();
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
