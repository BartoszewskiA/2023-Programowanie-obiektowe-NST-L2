#include <iostream>
#include <ctime>

using namespace std;

class Waga
{
private:
    double waga; // w Kg
public:
    Waga(double kg) : waga(kg) {}
    // Waga(double kg = 0) : waga(kg) {}
    // Waga() : waga(0) {}
    Waga()
    {
        waga = rand() % 101;
    }
    void setKg(double kg) { waga = kg; }
    double getKg() { return waga; }
    double getFunty() { return waga / 0.4535; }
    void setFunty(double funty) { waga = funty * 0.4535; }
    double getUncje() { return waga / 0.0283; }
    void setuncje(double uncja) { waga = uncja * 0.0283; }

    ~Waga()
    {
        cout << "Obiekt zawierajacy wage " << waga << " zostal usuniety z pamieci" << endl;
    }
};

int main()
{
    srand(time(NULL));
    Waga tab[100];
    for(int i = 0; i<100; i++)
    {
        cout<<tab[i].getKg()<<"Kg="<<tab[i].getFunty()<<"Lb"<<endl;
    }
    return 0;
}