// 27 (10к) Сохранение данных в файле с использованием потоков.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Pair.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include "FileWork.h"

using namespace std;
const string errorFindFile = "Не удалось найти файл с таким именем!\n";

void menu();

int main() {
    setlocale(LC_ALL, "ru");
    // menu();
    Pair pair, newPair;
    cout << "Введите первую пару: " << endl;
    cin >> pair;
    cout << "Введите вторую пару: " << endl;
    cin >> newPair;
    if (pair > newPair) cout << "Первая пара больше" << endl;
    else cout << "Вторая пара больше" << endl;
    pair--;
    cout << pair << endl;
    --pair;
    cout << pair << endl;
    if (pair > newPair) cout << "Первая пара больше" << endl;
    else cout << "Вторая пара больше" << endl;

}

void menu() {
    setlocale(LC_ALL, "ru");
    Pair newPair, secondPair;
    int numbers, answer, choice, number;
    double value, c;
    char fileName[30] = "file.txt";

    cout << "1. Создать файл";
    cout << "\n2. Вывести файл";
    cout << "\n3. Удалить запись из файла";
    cout << "\n4. Добавить запись в файл";
    cout << "\n5. Изменить запись в файле";
    cout << "\n6. Удалить все записи больше заданного значения";
    cout << "\n7. Увеличить все записи с заданным значением на число L";
    cout << "\n8. Добавить K записей после записи с номером N.";
    cout << "\n0. Выход\n";

    do {
        cout << "Выберете: "; cin >> choice;
        cout << "Имя файла: "; cout << "file.txt\n";// cin >> fileName;

        switch (choice) {
        case 1:
            cout << "Введите количество пар: "; cin >> numbers;
            answer = makeFile(fileName, numbers);
            if (answer < 0) cout << "Невозможно создать файл!";
            break;
        case 2:
            answer = printFile(fileName);
            if (answer == 0) cout << "Файл пуст\n";
            if (answer < 0) cout << errorFindFile;
            break;
        case 3:
            cout << "Введите номер записи, которую собираетесь удалить: "; cin >> number;
            answer = deleteRecordFromFile(fileName, number);
            if (answer < 0) cout << errorFindFile;
            if (answer > 0) cout << "Запись удалена\n";
            break;
        case 4:
            cout << "Введите номер для записи: "; cin >> number;
            cout << "Введите новую пару: \n"; cin >> newPair;
            answer = addRecordToFile(fileName, number, newPair);
            if (answer < 0) cout << errorFindFile;
            if (answer == 0) answer = addEnd(fileName, newPair);
            break;
        case 5:
            cout << "Введите номер записи, которую собираетесь изменить: "; cin >> number;
            answer = changeFile(fileName, number);
            if (answer < 0) cout << errorFindFile;
            else if (answer == 0) cout << "Не удалось найти запись!\n";
            else cout << "Запись изминена!\n";
            break;
        case 6:
            cout << "Введите значение: "; cin >> value;
            answer = deleteRecordsFromFile(fileName, value);
            if (answer < 0) cout << errorFindFile;
            else if (answer == 0) cout << "Не удалось найти запись!\n";
            else cout << "Записи удалены\n";
            break;
        case 7:
            cout << "Введите значение числа: "; cin >> value;
            cout << "Введите число: "; cin >> c;
            answer = changeRecordsFromFile(fileName, value, c);
            if (answer < 0) cout << errorFindFile;
            else if (answer == 0) cout << "Не удалось найти запись!\n";
            else cout << "Записи изменены\n";
            break;
        case 8:
            cout << "Введите номер записи после которой добавить новые записи: "; cin >> number;
            cout << "Введите количество пар: "; cin >> numbers;
            cout << "Введите новые пары: \n";
            do {
                cin >> newPair;
                answer = addRecordToFile(fileName, number + 1, newPair);
                if (answer < 0) cout << errorFindFile;
                if (answer == 0) answer = addEnd(fileName, newPair);
                number++; numbers--;
            } while (numbers > 0);
        }
    } while (choice != 0);
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
