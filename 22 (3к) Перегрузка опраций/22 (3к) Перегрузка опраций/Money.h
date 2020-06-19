#include <iostream>
using namespace std;

class Dengi {
    long rubs;
    int kopeks;
    
    public:
    Dengi(long r, int p) { rubs = r; kopeks = p; }
    Dengi() {rubs = 0; kopeks = 0;};
Dengi(const Dengi &pair) { rubs = pair.rubs; kopeks = pair.kopeks; }
    ~Money(){};
    
    long getRuble() {return rubs;}
    int getPenny() {return kopeks;}
    void setRuble(long r) {rubs = r;}
    void setPenny(double p) {kopeks = p;}
    
    // Перегруженные операции
    Dengi& operator =(const Money&);
    Dengi& operator ++();
    Dengi operator ++(int); //постфиксная операция
    
    // Перегруженные операции сравнения
    friend bool operator >(const Money& lm, const Money& rm);
    friend bool operator <(const Money& lm, const Money& rm);
    
    // Глобальные функции ввода-вывода
    friend istream& operator >>(istream& in, Money& money);
    friend ostream& operator <<(ostream& out, const Money& money);
};
