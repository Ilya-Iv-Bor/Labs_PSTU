#include "List.h"
#include <cassert>
#include "iostream"

List::List(int size, int data) {
    this -> size = size;
    this -> data = new int[size];
    for(int i = 0; i < size; i++) this -> data[i] = data;
    
    beg.element = &this -> data[0];
    end.element = &this -> data[size - 1];
}

List::List(const List& list) {
    size = list.size;
    data = new int[size];
    for(int i = 0; i < size; i++) data[i] = list.data[i];
    beg = list.beg;
    end = list.end;
}

List::~List() {
    delete[] data;
    data = 0;
}

List& List::operator =(const List& list) {
    if(this == &list) return *this;
    size = list.size;
    
    if (data != 0) delete[]data;
    data = new int[size];
    for(int i = 0; i < size; i++) data[i] = list.data[i];
    
    beg = list.beg;
    end = list.end;
    
    return *this;
}

int& List::operator [](int index) {
    if (index > size) {
        cout << "\nError! index > size";
        exit(1);
    }
    return data[index];
}

List operator +(List lhs, const List& rhs) {
    if(lhs.size != rhs.size) {
        cout << "\nError! list sizes are not equal";
        exit(1);
    }
    
    for (int i = 0; i < lhs.size; i++) lhs.data[i] += rhs.data[i];
    return lhs;
}

int List::operator ()() {
    return size;
}

ostream& operator <<(ostream& out, const List& list) {
    for(int i = 0; i < list.size; i++) out << list.data[i] << " ";
    return out;
}

istream& operator >>(istream& in, List& list) {
    for(int i = 0; i < list.size; i++) in >> list.data[i];
    return in;
}
