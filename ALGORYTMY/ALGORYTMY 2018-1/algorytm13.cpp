#include <iostream>
#include <list>

using namespace std;

int iloscProduktowMagazyn = 0;


struct Produkt;


struct Klient
{
    int id;
    int pieniadze;
    int pozycjaWKolejce;
    list<int> listaProduktow;
};


struct Produkt
{
    int cena;
    int iloscMagazyn;
};


class Kopiec
{
public:
    int rozmiar;
    int numerDodania;
    Klient* tablicaKlientow;
    int indeksTablicy;

    list<int>* kupione;

    Kopiec(int n);
    void dodaj(Klient k);
    void usun();
    int indeksOjca(int syn);
    int indeksLewySyn(int ojciec);
    int indeksPrawySyn(int ojciec);

    void przesiewanieWGore(Klient k, int pom);
    void przesiewanieWDol(int ojciec);
};

Kopiec::Kopiec(int n)
{
    rozmiar = n;
    tablicaKlientow = new Klient [rozmiar];
    kupione = new list<int> [n];
    indeksTablicy = 0;
    numerDodania = 0;
}

void Kopiec::dodaj(Klient k)
{
    k.pozycjaWKolejce = numerDodania;
    tablicaKlientow[indeksTablicy] = k;

    przesiewanieWGore(k, indeksTablicy);

    indeksTablicy++;
}

void Kopiec::usun()
{
    swap(tablicaKlientow[0], tablicaKlientow[indeksTablicy-1]);
    indeksTablicy--;
    rozmiar--;
    przesiewanieWDol(0);
    tablicaKlientow[indeksTablicy].pieniadze = 0;
}

int Kopiec::indeksOjca(int syn)
{
    return (syn-1)/2;
}

int Kopiec::indeksLewySyn(int ojciec)
{
    return (2*ojciec)+1;
}

int Kopiec::indeksPrawySyn(int ojciec)
{
    return (2*ojciec)+2;
}

void Kopiec::przesiewanieWGore(Klient k, int pom)
{
    int pomocnicza = pom;

    while(k.pieniadze > tablicaKlientow[indeksOjca(pomocnicza)].pieniadze && indeksTablicy != 0)
    {
        swap(tablicaKlientow[indeksOjca(pomocnicza)], tablicaKlientow[pomocnicza]);
        pomocnicza = indeksOjca(pomocnicza);
    }
}

void Kopiec::przesiewanieWDol(int ojciec)
{
    int lewySyn = indeksLewySyn(ojciec);
    int prawySyn = indeksPrawySyn(ojciec);
    int pomocnicza = ojciec;
    int pomocnicza2 = ojciec;

	if(lewySyn < rozmiar && prawySyn >= rozmiar)
    {
        if(tablicaKlientow[lewySyn].pieniadze > tablicaKlientow[ojciec].pieniadze)
        {
            swap(tablicaKlientow[lewySyn], tablicaKlientow[ojciec]);
            przesiewanieWDol(lewySyn);
        }
    }
    if(lewySyn < rozmiar && prawySyn < rozmiar)
    {
        if(tablicaKlientow[lewySyn].pieniadze > tablicaKlientow[prawySyn].pieniadze)
            pomocnicza = lewySyn;
        else if(tablicaKlientow[lewySyn].pieniadze < tablicaKlientow[prawySyn].pieniadze)
            pomocnicza = prawySyn;
        else
        {
            if(tablicaKlientow[lewySyn].pozycjaWKolejce < tablicaKlientow[prawySyn].pozycjaWKolejce)
                pomocnicza = lewySyn;
            else
                pomocnicza = prawySyn;
        }
        if(tablicaKlientow[pomocnicza].pieniadze > tablicaKlientow[ojciec].pieniadze)
        {
            pomocnicza2 = pomocnicza;
        }
		else if(tablicaKlientow[pomocnicza].pieniadze == tablicaKlientow[ojciec].pieniadze)
		{
			if(tablicaKlientow[pomocnicza].pozycjaWKolejce < tablicaKlientow[ojciec].pozycjaWKolejce)
				pomocnicza2 = pomocnicza;
			else
				pomocnicza2 = ojciec;
		}
        if(pomocnicza2 != ojciec)
        {
            swap(tablicaKlientow[pomocnicza2], tablicaKlientow[ojciec]);
            przesiewanieWDol(pomocnicza2);
        }
    }
}


int main()
{
	ios_base::sync_with_stdio(false);

    int liczbaProduktow;
    int liczbaKlientow;

    cin >> liczbaProduktow >> liczbaKlientow;

    Kopiec* kopiec = new Kopiec(liczbaKlientow);
    Produkt *tablicaProduktow = new Produkt [liczbaProduktow];

    for(int i=0; i<liczbaProduktow; i++)
    {
        cin >> tablicaProduktow[i].iloscMagazyn >> tablicaProduktow[i].cena;
        iloscProduktowMagazyn = iloscProduktowMagazyn + tablicaProduktow[i].iloscMagazyn;
    }

    for(int i=0; i<liczbaKlientow; i++)
    {
        Klient k;
        int ileProduktowKupic;
        cin >> k.pieniadze >> ileProduktowKupic;
        k.id = i;
        k.pozycjaWKolejce = kopiec->numerDodania;
        for(int j=0; j<ileProduktowKupic; j++)
        {
            int idProduktu;
            cin >> idProduktu;
            k.listaProduktow.push_back(idProduktu);
        }
        kopiec->dodaj(k);
        if(i < liczbaKlientow-1)
            kopiec->numerDodania++;
    }

    while(kopiec->rozmiar !=0 && iloscProduktowMagazyn !=0)
    {
        if(kopiec->tablicaKlientow[0].pieniadze <= 0 || kopiec->tablicaKlientow[0].listaProduktow.empty())
        {
            kopiec->usun();
        }
        else
        {
            int pomProdukt = kopiec->tablicaKlientow[0].listaProduktow.front();
            kopiec->tablicaKlientow[0].listaProduktow.pop_front();

            if((tablicaProduktow[pomProdukt].iloscMagazyn > 0) && (kopiec->tablicaKlientow[0].pieniadze >= tablicaProduktow[pomProdukt].cena))
            {
                kopiec->kupione[kopiec->tablicaKlientow[0].id].push_back(pomProdukt);
                iloscProduktowMagazyn--;
                tablicaProduktow[pomProdukt].iloscMagazyn--;
                kopiec->tablicaKlientow[0].pieniadze = kopiec->tablicaKlientow[0].pieniadze - tablicaProduktow[pomProdukt].cena;

                if((kopiec->tablicaKlientow[0].pieniadze <= 0) || (kopiec->tablicaKlientow[0].listaProduktow.empty()))
                {
                    kopiec->usun();
                }
                else
                {
                    kopiec->numerDodania++;
                    kopiec->tablicaKlientow[0].pozycjaWKolejce = kopiec->numerDodania;
                    kopiec->przesiewanieWDol(0);
                }
            }
        }
    }

    for(int i=0; i<liczbaKlientow; i++)
    {
        if(kopiec->kupione[i].empty())
            cout << "-" << endl;
        else
        {
            for(list<int>::iterator it = kopiec->kupione[i].begin(); it != kopiec->kupione[i].end(); it++)
            {
                cout << *it << " ";
            }
            cout << endl;
        }
    }

    return 0;
}