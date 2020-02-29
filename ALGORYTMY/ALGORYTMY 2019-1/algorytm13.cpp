#include <iostream>

using namespace std;

int liczba_zamian = 0;

struct Panstwo
{
    int id, wartosc;
};

int tablica_pomocnicza[1001];

class Kopiec
{
public:
    int indeksTablicy, rozmiar;

    Panstwo *tablica;

    Kopiec(int n);
    void dodaj(Panstwo p);
    void usun();
    void przesiewanieWGore(int start);
    void przesiewanieWDol(int ojciec);

    int indeksOjca(int syn);
    int indeksLewegoSyna(int ojciec);
    int indeksPrawegoSyna(int ojciec);
};

int main()
{
    ios_base::sync_with_stdio(false);

    int liczba_panstw, liczba_podmian;
    cin >> liczba_panstw;

    Kopiec kopiec(liczba_panstw);

    for(int i=0; i<liczba_panstw; i++)
    {
        Panstwo *nowy = new Panstwo();
        cin >> nowy->id >> nowy->wartosc;

        tablica_pomocnicza[nowy->id] = i;
        kopiec.dodaj(*nowy);
    }

    cin>>liczba_podmian;

    int id, wartosc;
    for(int j=0; j<liczba_podmian; j++)
    {
        cin >> id >> wartosc;
        kopiec.tablica[tablica_pomocnicza[id]].wartosc = wartosc;

        if(kopiec.tablica[kopiec.indeksOjca(tablica_pomocnicza[id])].wartosc <  wartosc)
            kopiec.przesiewanieWGore(tablica_pomocnicza[id]);
        else
            kopiec.przesiewanieWDol(tablica_pomocnicza[id]);
    }

    cout << liczba_zamian << endl;

    return 0;
}


Kopiec::Kopiec(int n)
{
    indeksTablicy = 0;
    rozmiar = n;
    tablica = new Panstwo[rozmiar];
}
void Kopiec::dodaj(Panstwo p)
{
    tablica[indeksTablicy] = p;
    indeksTablicy++;
}
void Kopiec::przesiewanieWGore(int start)
{
    int pom = start;
    while(pom!=0 && tablica[indeksOjca(pom)].wartosc < tablica[pom].wartosc)
    {   
        swap(tablica[indeksOjca(pom)], tablica[pom]);
        swap(tablica_pomocnicza[tablica[indeksOjca(pom)].id], tablica_pomocnicza[tablica[pom].id]);
        liczba_zamian++;
        pom = indeksOjca(pom);
    }
}
void Kopiec::przesiewanieWDol(int ojciec)
{
    int lewySyn = indeksLewegoSyna(ojciec);
    int prawySyn = indeksPrawegoSyna(ojciec);
    int ktorySynWiekszy = ojciec;
    int czyWiekszyOdOjca = ojciec;

    if(lewySyn < rozmiar && prawySyn >= rozmiar)  // jesli ojciec ma tylko jednego syna(lewy)
    {
        if(tablica[lewySyn].wartosc > tablica[ojciec].wartosc)
        {   
            swap(tablica[lewySyn], tablica[ojciec]);
            swap(tablica_pomocnicza[tablica[lewySyn].id], tablica_pomocnicza[tablica[ojciec].id]);
            liczba_zamian++;
            return przesiewanieWDol(lewySyn);
        }
    }else if(lewySyn < rozmiar && prawySyn < rozmiar)  // jesli ojciec ma dwóch synów
    {
        if(tablica[lewySyn].wartosc >= tablica[prawySyn].wartosc) // lewy syn zawsze będzie miał mniejszy indeks niż prawy
            ktorySynWiekszy = lewySyn;
        else
            ktorySynWiekszy = prawySyn;

        if(tablica[ktorySynWiekszy].wartosc > tablica[ojciec].wartosc)
        {
            czyWiekszyOdOjca = ktorySynWiekszy;
        }
    }else return;

    if(czyWiekszyOdOjca != ojciec)
    {
        swap(tablica[czyWiekszyOdOjca], tablica[ojciec]);
        swap(tablica_pomocnicza[tablica[czyWiekszyOdOjca].id],tablica_pomocnicza[tablica[ojciec].id]);
        liczba_zamian++;
        przesiewanieWDol(czyWiekszyOdOjca);
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