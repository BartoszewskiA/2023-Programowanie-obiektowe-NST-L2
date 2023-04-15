#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int ile = 0;

class Zwierze
{
private:
    int id;
    string imie;
    string rasa;
    double waga;

public:
    Zwierze(string imie, string rasa, double waga)
    {
        id = ++ile;
        this->imie = imie;
        setRasa(rasa);
        this->waga = waga;
    }
    void setImie(string imie) { this->imie = imie; }
    void setRasa(string rasa)
    {
        for (int i = 0; i < rasa.length(); i++)
            rasa[i] = toupper(rasa[i]);
        if (rasa == "PIES" || rasa == "KOT")
            this->rasa = rasa;
        else
            this->rasa = "INNE";
    }
    void setWaga(double waga) { this->waga = waga; }
    string getWaga()
    {
        // if (waga > 10)
        //     return ">10 kG";
        // if (waga > 1 && waga <= 10)
        //     return "1 - 10 kG";
        // if (waga > 0.1 && waga <= 1)
        //     return "0.1 kG - 1 kG";
        // if (waga <= 0.1)
        //     return "<0.1 kG"
        if (waga > 10)
            return ">10 kG";
        else if (waga > 1)
            return "1 - 10 kG";
        else if (waga > 0.1)
            return "0.1 kG - 1 kG";
        else
            return "<0.1 kG";
    }
    string getImie() { return imie; }
    string getRasa() { return rasa; }
    int getID() { return id; }
    string getOpis()
    {
        stringstream s;
        s << "ID:\t\t" << id << endl
          << "Imie:\t" << imie << endl
          << "Rasa:\t" << rasa << endl
          << "Waga:\t" << getWaga() << endl;
        return s.str();
    }
};

int main()
{
    Zwierze *kartoteka[1000];
    string imie, rasa, temp; // uwaga - to nie pola klasy - zwykla zbierznosc nazw
    double waga;
    for (int i = 0; i < 3; i++)
    {
        cout << "Podaj imie:";
        getline(cin, imie);
        cout << "Podaj rase:";
        getline(cin, rasa);
        cout << "Podaj wage:";
        getline(cin, temp);
        waga = atof(temp.c_str());
        kartoteka[i] = new Zwierze(imie, rasa, waga);
    }
    for (int i = 0; i < 3; i++)
    {
        cout << "\n----------------------------------\n";
        cout << kartoteka[i]->getOpis();
    }
    return 0;
}