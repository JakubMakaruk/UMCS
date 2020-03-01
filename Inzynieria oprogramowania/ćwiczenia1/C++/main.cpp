#include <iostream>

using namespace std;

class Zwierze
{
    int wiek;

public:
    int getWiek() { return this->wiek; }
    void setWiek(int w) { this->wiek = w; }
};

class Ssak : public Zwierze
{
    double dlugosc = 0;

public:
    double getDlugosc() { return this->dlugosc; }
    void setDlugosc(double d) { this->dlugosc = d; }
};

class Pies : public Ssak
{
    string rasa;

public:
    string getRasa() { return this->rasa; }
    void siad()
    {
        cout << "Siadam!" << endl;
    }
};

class Jamnik : public Pies
{
    string kolor;

public:
    string getKolor() { return this->kolor; }
    void setKolor(string k) { this->kolor = k; }
    void zmierzDlugosc()
    {
        cout << "Jamnik ma " << this->getDlugosc() << "m." << endl;
    }
};


int main()
{
    Jamnik j;

    j.setDlugosc(10);
    j.setWiek(5);

    j.siad();
    j.zmierzDlugosc();
    cout << j.getWiek() << endl;

    return 0;
}
