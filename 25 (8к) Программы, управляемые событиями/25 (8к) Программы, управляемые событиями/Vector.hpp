#pragma once
#include "Object.hpp"

class Vector {
protected:
    Object **beg; //Указатель на первый элемент вектора
    int size; //размер
    int current; //текущая позиция
public:
    Vector(int = 0);
    ~Vector();
    
    void add(); // Добавление элемента в вектор
    void remove();
    void show();
    int operator ()(); // Размер вектора
    
    void handleEvent(const TEvent&);
};
