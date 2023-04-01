#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int ile = 0;

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
    string getImie() { return imie; }
    string getNazwisko() { return nazwisko; }

    void wczytajDane();
    void wypiszOsobe();
};

void Osoba::wczytajDane()
{
    id = ile + 1;
    cout << "Podaj imie: ";
    getline(cin, imie);
    cout << "Podaj nazwisko: ";
    getline(cin, nazwisko);
}

void Osoba::wypiszOsobe()
{
    cout << "\n-----------------------------\n"
         << "ID:\t\t" << id
         << "\nImie:\t\t" << imie
         << "\nNazwisko:\t" << nazwisko
         << "\n-----------------------------\n";
}

Osoba *baza[1000];

void wypiszBaze();
void dodajOsobe();
void usunBaze();
void eksportDoPliku();
void importZPliku();
int main()
{
    int wybor = 0;
    while (true)
    {
        cout << "\n---------------------------------\n"
             << "1 - Dodaj osobe" << endl
             << "2 - Wypisz baze" << endl
             << "3 - eksportuj do pliku" << endl
             << "4 - importuj z pliku" << endl
             << "8 - usun baze" << endl
             << "9 - wyjdz z programu" << endl
             << "Wybierz opcje: ";
        cin >> wybor;
        cin.clear();
        cin.ignore(10, '\n'); // czyszczenie bufor pamięci
        cout << "\n---------------------------------\n";

        switch (wybor)
        {
        case 1:
            dodajOsobe();
            break;
        case 2:
            wypiszBaze();
            break;
        case 3:
            eksportDoPliku();
            break;
        case 4:
            importZPliku();
            break;
        case 8:
            usunBaze();
            break;
        case 9:
            usunBaze();
            return 0;
        }
    }

    return 0;
}

void wypiszBaze()
{
    for (int i = 0; i < ile; i++)
        baza[i]->wypiszOsobe();
}

void dodajOsobe()
{
    baza[ile] = new Osoba;
    baza[ile]->wczytajDane();
    ile++;
}

void usunBaze()
{
    for (int i = 0; i < ile; i++)
        delete baza[i];
    ile = 0;
}

void eksportDoPliku()
{
    fstream plik;
    plik.open("baza.txt", ios::out);
    plik << ile << endl;
    for (int i = 0; i < ile; i++)
    {
        plik << baza[i]->getImie() << endl;
        plik << baza[i]->getNazwisko() << endl;
    }
    plik.close();
}

void importZPliku()
{
    fstream plik;
    plik.open("baza.txt", ios::in);
    if (!plik.good())
        return;
    string imie, nazwisko, s;
    getline(plik, s);
    int n = atoi(s.c_str());
    for (int i = 0; i < n; i++)
    {
        getline(plik, imie);
        getline(plik, nazwisko);
        baza[ile] = new Osoba;
        baza[ile]->setImie(imie);
        baza[ile]->setNazwisko(nazwisko);
        baza[ile]->setId(ile + 1);
        ile++;
    }

    plik.close();
}