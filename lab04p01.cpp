#include <iostream>
#include <ctime>
#include <cmath>
#include <sstream>

using namespace std;

class Punkt
{
private:
    double x;
    double y;

public:
    Punkt(double X, double Y) : x(X), y(Y) { cout << "konstruktor   "; } // konstruktor z parametrami
    // Punkt()                                   // konstruktor domyslny
    // {
    //     x = rand() % 201 - 100;
    //     y = rand() % 201 - 100;
    // }
    double getX() { return x; }
    double getY() { return y; }
    double getR() { return sqrt(x * x + y * y); }
    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
    string toString()
    {
        stringstream s;
        s << "(" << x << ";" << y << ")"
          << " R=" << getR() << "\t";
        return s.str();
    }
    ~Punkt() { cout << "destruktor  "; }
};

double sredniaOdleglosc(Punkt *t[]);

int main()
{
    srand(time(NULL));
    // Punkt p1(10, 20);        // statycznie
    // Punkt *p2;               // zmienna wskaznikowa
    // p2 = new Punkt(10, 100); // utworzenie obiektu
    // cout << p1.toString() << "  " << p2->toString();
    // delete p2;

    Punkt *tab[40]; // tablica wskaznikow
    for (int i = 0; i < 40; i++)
        tab[i] = new Punkt(i, i); // tworzenie obiektow - w petli

    for (int i = 0; i < 40; i++)
        cout << tab[i]->toString() << endl;

    cout << "\nSrednia=" << sredniaOdleglosc(tab) << endl;

    for (int i = 0; i < 40; i++)
        delete tab[i];
    return 0;
}

double sredniaOdleglosc(Punkt *t[])
{
    double suma = 0;
    for (int i = 0; i < 40; i++)
        suma += t[i]->getR();
    return suma / 40;
}