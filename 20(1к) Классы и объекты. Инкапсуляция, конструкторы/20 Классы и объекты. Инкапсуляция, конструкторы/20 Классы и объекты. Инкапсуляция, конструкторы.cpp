// 20 Классы и объекты. Инкапсуляция, конструкторы.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "number.h"
#include <stdlib.h>


using namespace std;

int sizes;
float k;

number makeNumber(int integer, int fraction) {
    number num;
    num.init(integer, fraction);
    return num;
}

int main() {
   

    setlocale(LC_ALL, "Russian");

   
    number a;
    number b;
    number* x = new number;

    cout << "Число a:\n";
    a.init(200, 16);
    a.show();

    cout << "\nЧисло b:\n";
    b.read();
    b.show();

    cout << "\nЧисло x:\n";
    x->init(145, 20);
    x->show();

    cout << "\nВведите число: ";
    cin >> k;

    cout << "\na.multiply(" << a.first << "." << a.second << " * " << k << ") = " << a.multiply(k) << "\n";
    cout << "b.multiply(" << b.first << "." << b.second << " * " << k << ") = " << b.multiply(k) << "\n";
    cout << "x.multiply(" << x->first << "." << x->second << " * " << k << ") = " << x->multiply(k) << "\n";

    cout << "\nМассив чисел";
    cout << "\nВведите размер массива: "; cin >> sizes;
    number* array = new number[sizes];

    for (int i = 0; i < sizes; i++) {
        cout << "Число " << i + 1 << ": \n";
        array[i].read();
    }
    cout << endl;

    for (int i = 0; i < sizes; i++) {
        cout << "Число " << i + 1 << ": \n";
        array[i].show();
    }

    for (int i = 0; i < sizes; i++) {
        cout << "array[" << i << "].multiply(";
        cout << array[i].first << ", ";
        cout << array[i].second << ") = ";
        cout << array[i].multiply(k) << endl;
    }
    cout << endl;

    int integer; // оклад
    int fraction; // кол-во отработанных дней
    cout << "Целая часть числа: "; cin >> integer;
    cout << "Дробная часть числа: "; cin >> fraction;
    number num = makeNumber(integer, fraction);
    num.show();
    cout << endl;
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
