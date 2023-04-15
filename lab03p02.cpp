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
    Punkt(double X, double Y) : x(X), y(Y) {} // konstruktor z parametrami
    Punkt() // konstruktor domyslny
    {
        x = rand() % 201 - 100;
        y = rand() % 201 - 100;
    }
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
};

int main()
{
    srand(time(NULL));
    Punkt tab[40];
    for (int i = 0; i < 40; i++)
        cout << tab[i].toString() << endl;
    return 0;
}