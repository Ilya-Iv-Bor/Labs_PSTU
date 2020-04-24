// Лаба 15 ( Сортировка ).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include "sort.h"
#include <time.h>
using namespace std;

void outputArray(int* array, int lenght);
void inputArray(int* array, int lenght);

int main() {
    setlocale(LC_ALL, "ru");
    int var = 0;
    int* array = NULL;
    int size = 0;

    cout << "1.Сформировать массив\n";
    cout << "2.Отсортировать массив быстрой сортировкой\n";
    cout << "3.Отсортировать массив методом подсчёта\n";
    cout << "4.Ввывести массив\n";
    cout << "5.Выход\n";

    while (var != 5) {
        cout << "Выберите шаг: ";
        cin >> var;

        switch (var) {
        case 1:
            cout << "Введите количество элементов массива: ";
            cin >> size;
            array = new int[size];
            inputArray(array, size);
            break;
        case 2:
            quickSort(array, 0, size - 1);
            break;
        case 3:
            countingSort(array, size);
            break;
        case 4:
            outputArray(array, size);
            break;
        default:
            break;
        }
    }
}


void outputArray(int* array, int size) {
    cout << "Массив: ";
    for (int i = 0; i < size; i++) cout << array[i] << '\t';
    cout << endl;
}

void inputArray(int* array, int size) {
    srand(time(0));
    cout << "Введите элеметы: ";
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }
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
