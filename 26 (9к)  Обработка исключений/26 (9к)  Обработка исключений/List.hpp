#include "iostream"

using namespace std;
const int maxSize = 3; 

class Iterator {
    friend class Vector; // Дружественный класс
    
public:
    int *element; // Указатель на элемент типа int
public:
    Iterator() { element = 0; } // Конструктор без параметров
    Iterator(const Iterator& iterator) { element = iterator.element; } // Конструктор копирования
    
    bool operator ==(const Iterator& iterator){ return element == iterator.element; }
    bool operator !=(const Iterator& iterator){ return element != iterator.element; }
    
    void operator -(int n) { element -= n; }
    void operator ++(int) { ++element; } // Инкремент
    void operator --() { --element; }  // Декремент
    int& operator *() const { return *element; } // Разыменования
};

class List {
private:
    int size; // Размер вектора
    int *data;// Указатель на динамический массив значений вектора
    Iterator beg;
    Iterator end;

public:
    List(int = 0, int = 0); // Конструктор с параметрами: выделяет память под size элементов и заполняет их значением data
    List(const List&); // Конструктор копирования
    ~List(); // Деструктор
    
    List& operator =(const List&); // Операция присваивания
    int& operator [](int); // Операция доступа по индексу
    int operator ()(); // Операция, возвращающая длину вектора
    List operator +(int); // Операция добавляения числа в начало списка
    
    friend List operator +(List, const List&); // Операция сложения
    friend ostream& operator <<(ostream& out, List const&);
    friend istream& operator >>(istream& in, List&);

    Iterator first() { return beg; }
    Iterator last() { return end; }
};
