/*
Napisz program, który wczytuje gesty graf nieskierowany i stwierdza czy podany graf jest spójny.
Fakt, ze graf jest gesty oznacza dla nas, ze liczba jego krawedzi jest rzêdu kwadratu liczby
wierzcholkow.

WEJSCIE
Na wejsciu program otrzymuje liczbe wierzcholkow n oraz liczbe krawedzi m,
a nastepnie m par a, b oznaczajacych krawedzi pomiedzy wierzcholkami a i b.

WYJSCIE
Na wyjsciu program powinien wypisac TAK jezeli wczytany graf jest spojny oraz NIE
w przeciwnym wypadku.
*/

#include <iostream>

using namespace std;

// ------------------------------------------------------ LISTA

struct ElementListy
{
    int wierzcholek;
    ElementListy* poprzedni;
};

class Lista
{
public:
    ElementListy* glowa;

    Lista();
    void dodaj(int liczba);
    void usun();
    void wyswietl();
};

Lista::Lista()
{
    glowa = new ElementListy;
    glowa = NULL;
}

void Lista::dodaj(int liczba)
{
    if(glowa == NULL)
    {
        ElementListy* pom = new ElementListy;
        pom->wierzcholek = liczba;
        pom->poprzedni = NULL;
        glowa = pom;
    }
    else
    {
        ElementListy* pom = new ElementListy;
        pom->wierzcholek = liczba;
        pom->poprzedni = glowa;
        glowa = pom;
    }
}

void Lista::usun()
{
    if(glowa->poprzedni != NULL)
    {
        ElementListy* pom = new ElementListy;
        pom = glowa;
        glowa = glowa->poprzedni;
        delete pom;
    }
    else
    {
        ElementListy* pom = new ElementListy;
        pom = glowa;
        delete pom;
        glowa = NULL;
    }
}

void Lista::wyswietl()
{
    ElementListy* pom = new ElementListy;
    for(pom = glowa; pom != NULL; pom = pom->poprzedni)
    {
        cout << pom->wierzcholek << " ";
    }
    cout << endl;
}


// ------------------------------------------------------ GRAF


class Graf
{
public:
    int rozmiar;
    Lista *lista;
    bool *odwiedzone;
    int ileOdwiedzonych;

    Graf(int n);
    void dodajSasiadow(int wierzcholek, int sasiad);

    void BFS(int wierzcholekStartowy);
};

Graf::Graf(int n)
{
    this->rozmiar = n;
    lista = new Lista [rozmiar];
    ileOdwiedzonych = 0;
}

void Graf::dodajSasiadow(int wierzcholek, int sasiad)
{
    lista[wierzcholek].dodaj(sasiad);
}

void Graf::BFS(int wierzcholekStartowy)
{
    odwiedzone = new bool [rozmiar];
    for(int i=0; i<rozmiar; i++)
        odwiedzone[i] = false;

    Lista* kolejka = new Lista;

    odwiedzone[wierzcholekStartowy] = true;
    kolejka->dodaj(wierzcholekStartowy);

    while(kolejka->glowa != NULL)
    {
        wierzcholekStartowy = kolejka->glowa->wierzcholek;

        //cout << wierzcholekStartowy << " ";

        kolejka->usun();
        ileOdwiedzonych++;

        ElementListy* pom = new ElementListy;
        pom = lista[wierzcholekStartowy].glowa;
        while(pom != NULL)
        {
            if(odwiedzone[pom->wierzcholek] == false)
            {
                odwiedzone[pom->wierzcholek] = true;
                kolejka->dodaj(pom->wierzcholek);
            }
            pom = pom->poprzedni;
        }
    }
}

// ------------------------------------------------------ MAIN

int main()
{
    ios_base::sync_with_stdio(false); // magiczna linijka

    int liczbaWierzcholkow, liczbaKrawedzi;
    int start;

    cin >> liczbaWierzcholkow >> liczbaKrawedzi;

    Graf graf(liczbaWierzcholkow);
    for(int i=0; i<liczbaKrawedzi; i++)
    {
        int wierzchol, sasia;
        cin >> wierzchol >> sasia;
        graf.dodajSasiadow(wierzchol, sasia);

        if(i == 0)
            start = wierzchol;
    }

    graf.BFS(start);

    if(graf.ileOdwiedzonych == liczbaWierzcholkow)
        cout << "TAK" << endl;
    else
        cout << "NIE" << endl;

    return 0;
}



/*
PRZYK£AD 1
wejœcie:
4 3
0 1
1 2
2 3

wyjœcie:
TAK

PRZYK£AD 2
wejœcie:
4 2
0 1
2 3

wyjœcie:
NIE
*/
