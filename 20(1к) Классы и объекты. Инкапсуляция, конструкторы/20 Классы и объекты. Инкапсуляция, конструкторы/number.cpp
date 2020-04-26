#include <iostream>
#include "number.h"
#include <locale>


using namespace std;

void number::init(int integer, int fraction) {
    first = integer;
    second = fraction;
}

void number::read() {
   
    cout << "Целая часть числа: ";
    cin >> first;
    cout << "Дробная часть числа: ";
    cin >> second;
}

void number::show() {
    
    printf("Целая часть числа: "); cout << first << endl;
    printf("Дробная часть числа: "); cout << second << endl;
}

 double numToDouble(int integer, int fraction) {
    double num = fraction;
    while (num >= 1) {
        num /= 10;
    }
    
    return num + integer;
}

double number::multiply(float k) {
    double num = numToDouble(first, second);
    return num * k;
}


