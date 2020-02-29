#include <iostream>

using namespace std;

class Kopiec
{
public:
    int *tablica;
    int rozmiar;
    int indeksTablicy;

    Kopiec(int roz);
    void dodaj(int liczba);
    void usun();
    void przesiewanieWGore(int start);
    void przesiewanieWDol(int ojciec);

    int indeksOjca(int syn);
    int indeksLewegoSyna(int ojciec);
    int indeksPrawegoSyna(int ojciec);
};

Kopiec::Kopiec(int roz)
{
    rozmiar = roz;
    indeksTablicy = 0;
    tablica = new int [rozmiar];
}

void Kopiec::dodaj(int liczba)
{
    tablica[indeksTablicy] = liczba;
    przesiewanieWGore(indeksTablicy);
    indeksTablicy++;
}

void Kopiec::usun()
{
    if(tablica[0] != 0)
    {
        int pom = tablica[0];
        tablica[0] = tablica[indeksTablicy-1];
        rozmiar--;
        indeksTablicy--;
        przesiewanieWDol(0);
        tablica[indeksTablicy] = 0;
        cout << pom << endl;
    }
    else
    {
        cout << "BLAD" << endl;
    }
}

void Kopiec::przesiewanieWGore(int start)
{
    int pomocnicza = start;
    while(indeksTablicy != 0 && tablica[start] > tablica[indeksOjca(pomocnicza)])
    {
        swap(tablica[indeksOjca(pomocnicza)], tablica[pomocnicza]);
        pomocnicza = indeksOjca(pomocnicza);
    }
}

void Kopiec::przesiewanieWDol(int ojciec)
{
    int lewySyn = indeksLewegoSyna(ojciec);
    int prawySyn = indeksPrawegoSyna(ojciec);
    int lepszySyn = ojciec;
    int pom = ojciec;

    if(lewySyn < rozmiar && prawySyn >= rozmiar)
    {
        if(tablica[lewySyn] > tablica[ojciec])
        {
            swap(tablica[lewySyn], tablica[ojciec]);
            przesiewanieWDol(lewySyn);
        }
    }
    if(lewySyn < rozmiar && prawySyn < rozmiar)
    {
        if(tablica[lewySyn] > tablica[prawySyn])
        {
            lepszySyn = lewySyn;
        }
        else
        {
            lepszySyn = prawySyn;
        }

        if(tablica[lepszySyn] > tablica[ojciec])
        {
            pom = lepszySyn;
        }
    }

    if(pom != ojciec)
    {
        swap(tablica[pom], tablica[ojciec]);
        przesiewanieWDol(pom);
    }
}

int Kopiec::indeksOjca(int syn)
{
    return (syn-1)/2;
}

int Kopiec::indeksLewegoSyna(int ojciec)
{
    return (2*ojciec)+1;
}

int Kopiec::indeksPrawegoSyna(int ojciec)
{
    return (2*ojciec)+2;
}


int main()
{
    int ileOperacji, rozmiar;

    cin >> ileOperacji >> rozmiar;

    Kopiec kolejkaPriorytetowa(rozmiar);

    for(int i=0; i<ileOperacji; i++)
    {
        char operacja;
        cin >> operacja;
        if(operacja == 'd')
        {
            int liczba;
            cin >> liczba;
            kolejkaPriorytetowa.dodaj(liczba);
        }
        else if(operacja == 't')
        {
            kolejkaPriorytetowa.usun();
        }
    }
    return 0;
}
