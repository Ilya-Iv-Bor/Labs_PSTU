#include "enrollee.h"
#include <iostream>
#include <string>

using namespace std;

//конструктор без параметров
Enrollee::Enrollee() {
    fullName = "";
    specialty = "";
    examPoint = 0;
    cout << "Конструктор без параметров для обекта " << this << endl;
}

//конструктор с параметрами
Enrollee::Enrollee(string fn, string s, int ep) {
    fullName = fn;
    specialty = s;
    examPoint = ep;
    cout << "Конструктор c параметрами для обекта " << this << endl;
}

//конструктор копирования
Enrollee::Enrollee(const Enrollee &enrollee) {
    fullName = enrollee.fullName;
    specialty = enrollee.specialty;
    examPoint = enrollee.examPoint;
    cout << "Конструктор копирования для объекта " << this << endl;
}

// Деструктор
Enrollee::~Enrollee() {
    cout << "Деструктор для объкта " << this << endl;
}

// Селекторы
string Enrollee::getFullName() {
    return fullName;
}

string Enrollee::getSpeciality() {
    return specialty;
}

int Enrollee::getExamPoint() {
    return examPoint;
}

// Модификаторы
void Enrollee::setFullName(string fn) {
    fullName = fn;
}

void Enrollee::setSpeciality(string s) {
    specialty = s;
}

void Enrollee::setExamPoint(int ep) {
    examPoint = ep;
}

// Метод для просмотра атрибутов
void Enrollee::show() {
    
    cout << "ФИО абитуриента: " << fullName << endl;
    cout << "Специальность: " << specialty << endl;
    cout << "Балл ЕГЭ: " << examPoint << endl;
}
