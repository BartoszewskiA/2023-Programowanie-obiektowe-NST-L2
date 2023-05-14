#include <iostream>
#include <sstream>
#include <ctime>

using namespace std;

class Punkt
{
private:
    double x;
    double y;

public:
    // Punkt() : x(0), y(0) {}
    Punkt()
    {
        x = rand() % 21 - 10;
        y = rand() % 21 - 10;
    }
    Punkt(double X, double Y) : x(X), y(Y) {}
    // double getX() { return x; }
    // double getY() { return y; }
    // void setX(double x) { this->x = x; }
    // void setY(double y) { this->y = y; }
    void przesunOWektor(double dx, double dy)
    {
        x += dx;
        y += dy;
    }
    void przesunDo(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    string toString()
    {
        stringstream s;
        s << "(" << x << ";" << y << ")";
        return s.str();
    }
    friend bool szukaj(double sx, double sy, Punkt &punkt);
};

Punkt tab[100];

bool szukaj(double sx, double sy, Punkt &punkt)
{
    if (punkt.x == sx && punkt.y == sy)
        return true;
    else
        return false;
}

int main()
{
    srand(time(NULL));
    for (int i = 0; i < 100; i += 5)
    {
        for (int j = 0; j < 5; j++)
            cout << tab[i + j].toString() << "\t\t";
        cout << endl;
    }
    double sx, sy;
    cout << "Podaj szukany x:";
    cin >> sx;
    cout << "Podaj szukany y:";
    cin >> sy;
    for (int i = 0; i < 100; i++)
    {
        if (szukaj(sx, sy, tab[i]) == true)
            cout << "Znaleziony: " << i << " " << tab[i].toString() << endl;
    }

    return 0;
}