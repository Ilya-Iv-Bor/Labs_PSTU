#pragma once
#include <string>
#include <iostream>

using namespace std;


class Error {
    string strError;
public:
    //конструктор, инициирует атрибут str сообщением об ошибке
    Error(string error) { strError = error; }
    void what() { cout << strError << endl;} //выводит значение атрибута str

};
