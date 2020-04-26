#include <iostream>
#include <string>

using namespace std;

class Enrollee {
    //атрибуты
    string fullName;
    string specialty;
    int examPoint;
    
    public:
    Enrollee(); // конструктор без параметров
    Enrollee(string, string, int); // конструктор с параметрами
    Enrollee(const Enrollee&); // конструктор копирования
    ~Enrollee(); //деструктор
    
    string getFullName();//селектор
    void setFullName(string); // модификатор
    
    string getSpeciality();
    void setSpeciality(string);
    
    int getExamPoint();
    void setExamPoint(int);
    
    void show(); // просмотр атрибутов
};
