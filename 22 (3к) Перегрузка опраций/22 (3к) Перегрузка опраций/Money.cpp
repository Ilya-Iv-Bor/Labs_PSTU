#include <iostream>
#include "Money.h"
using namespace std;

// Перегрузка глобальной функции-операции ввода
istream& operator >> (istream& in, Money& money) {
    setlocale(LC_ALL, "ru");
    cout << "Введите\nРубли: "; in >> money.rubs;
    cout << "Копеки: "; in >> money.kopeks;
    cout << endl;
    return in;
}

// Перегрузка глобальной функции-операции вывода
ostream& operator << (ostream& out, const Money& money) {
    setlocale(LC_ALL, "ru");
    long temp = money.rubs * 100 + money.kopeks;
    return (out << temp / 100 << "," << temp % 100);
}

// Перегрузка операции присваивания
Money& Money::operator = (const Money& money) {
    setlocale(LC_ALL, "ru");
    if(&money == this) return *this;
    rubs = money.rubs;
    kopeks = money.kopeks;
    return *this;
}

// Перегрузка префиксной операции инкремент
Money& Money::operator ++() {
    setlocale(LC_ALL, "ru");
    long temp = rubs * 100 + kopeks;
    temp++;
    rubs = temp / 100;
    kopeks = temp % 100;
    return *this;
}

// Перегрузка постфиксной операции инкремент
Money Money::operator ++(int) {
    setlocale(LC_ALL, "ru");
    long temp = rubs * 100 + kopeks;
    temp++;
    Money money(rubs, kopeks);
    rubs = temp / 100;
    kopeks = temp % 100;
    return money;
}

// Перегрузка бинарных операции
bool operator >(const Money& lm, const Money& rm) {
    setlocale(LC_ALL, "ru");
    long left = lm.rubs * 100 + lm.kopeks;
    long right = rm.rubs * 100 + rm.kopeks;
    return (left > right);
}

bool operator <(const Money& lm, const Money& rm) {
    setlocale(LC_ALL, "ru");
    long left = lm.rubs * 100 + lm.kopeks;
    long right = rm.rubs * 100 + rm.kopeks;
    return (left < right);
}


