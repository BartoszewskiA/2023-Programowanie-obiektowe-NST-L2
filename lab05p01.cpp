#include <iostream>

using namespace std;

class Liczba
{
private:
    int dana;
    static int ile;
    static int suma;

public:
    Liczba(int x) : dana(x)
    {
        ile++;
        suma += dana;
    }
    ~Liczba()
    {
        ile--;
        suma -= dana;
    }
    void setDana(int dana)
    {
        suma -= this->dana;
        this->dana = dana;
        suma += this->dana;
    }
    int getDana() { return dana; }
    int getIle() { return ile; }
    int getSuma() { return suma; }
};
int Liczba::ile = 0;
int Liczba::suma = 0;

int main()
{
    // Liczba x1(10), x2(11), x3(14);

    // cout << "x=" << x1.getDana() << " ile=" << x1.getIle() << endl;
    // cout << "x=" << x2.getDana() << " ile=" << x2.getIle() << endl;
    // cout << "x=" << x3.getDana() << " ile=" << x3.getIle() << endl;
    // Liczba x4(23);
    // cout << "x=" << x1.getDana() << " ile=" << x1.getIle() << endl;

    Liczba *x1 = new Liczba(10);
    Liczba *x2 = new Liczba(20);
    Liczba *x3 = new Liczba(30);
    x1->setDana(1000);
    cout << "x=" << x1->getDana()
         << " ile=" << x1->getIle()
         << " suma=" << x1->getSuma()
         << endl;
    delete x1;
    delete x2;
    delete x3;
    return 0;
}