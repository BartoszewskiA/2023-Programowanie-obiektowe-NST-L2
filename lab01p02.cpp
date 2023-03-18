#include <iostream>

using namespace std;

class Osoba
{
private:
    int id;
    string imie;
    string nazwisko;

public:
    void setId(int d) { id = d; }
    void setImie(string im) { imie = im; }
    void setNazwisko(string nazw) { nazwisko = nazw; }
    int getId() { return id; }
    string getimie() { return imie; }
    string getNazwisko() { return nazwisko; }
};

int main()
{

    return 0;
}