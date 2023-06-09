#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

class Punkt
{
private:
    int x;
    int y;

public:
    void setX(int px) { x = px; }
    void setY(int py) { y = py; }
    int getX() { return x; }
    int getY() { return y; }
    double getR() { return sqrt(x * x + y * y); }
    void losuj(int a, int b);
};

void Punkt::losuj(int a, int b)
{
    if (a <= b)
    {
        x = rand() % (b - a + 1) + a;
        y = rand() % (b - a + 1) + a;
    }
    else
    {
        x = 0;
        y = 0;
    }
}

int main()
{
    Punkt tab[100];
    srand(time(NULL));
    for (int i = 0; i < 100; i++)
    {
        tab[i].losuj(-20, 100);
        // tab[i].setX(rand() % 201 - 100);
        // tab[i].setY(rand() % 201 - 100);
    }

    for (int i = 0; i < 100; i++)
        cout << "(" << tab[i].getX() << ";" << tab[i].getY() << ") ";

    double rmin = tab[0].getR(), rmax = tab[0].getR();
    for (int i = 0; i < 100; i++)
    {
        if (tab[i].getR() < rmin)
            rmin = tab[i].getR();
        if (tab[i].getR() > rmax)
            rmax = tab[i].getR();
    }
    cout << "\n----------------------------------\n";
    cout << "R min =" << rmin << endl
         << "R max=" << rmax << endl;
    return 0;
}