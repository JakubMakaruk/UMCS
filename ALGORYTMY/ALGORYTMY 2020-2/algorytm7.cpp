#include <iostream>

using namespace std;

struct Node
{
    string pseudonim;
    int wartosc_niebezpieczenstwa;
    char kolor='r'; // r-red, b-black
    Node* lewy=NULL, *prawy=NULL, *ojciec=NULL;
};

class DCZCZ
{
public:
    Node* korzen;
    Node **tablica;
    int counter;
    int rozmiar;

    DCZCZ(int n)
    {
        korzen=NULL;
        counter=0;
        rozmiar = n;
        tablica = new Node* [n];

        for(int i=0; i<rozmiar; i++)
            tablica[i] = NULL;
    }
    Node* dodaj(Node* wierzcholek, string p, int x);
    void ustawRownowage(Node *&wierzcholek);
    char getKolor(Node *&w);

    void rotacjaLewo(Node *&wierzcholek);
    void rotacjaPrawo(Node *&wierzcholek);

    void r(string osobaA, string osobaB);
    void m(string a, int liczba_przejsc);
    Node* znajdz(string s, Node *ojciec);

    void wyswietl();

    void rozszerzTablice();
};


int main()
{
    ios_base::sync_with_stdio(false);

    int liczba_osob;
    cin >> liczba_osob;

    DCZCZ drzewo(liczba_osob);

    for(int i=0; i<liczba_osob; i++)
    {
        string n;
        cin >> n;

        drzewo.korzen = drzewo.dodaj(drzewo.korzen, n, drzewo.counter);
    }

    int liczba_operacji;
    cin >> liczba_operacji;

    for(int i=0; i<liczba_operacji; i++)
    {
        char znak;
        cin >> znak;
        switch(znak)
        {
        case 'r':
        {
            string osobaA, osobaB;
            cin >> osobaA >> osobaB;

            drzewo.r(osobaA, osobaB);

            break;
        }
        case 'a':
        {
            string osoba;
            cin >> osoba;

            if(drzewo.counter==drzewo.rozmiar)
                drzewo.rozszerzTablice();

            drzewo.korzen = drzewo.dodaj(drzewo.korzen, osoba, drzewo.counter);

            break;
        }
        case 'm':
        {
            string osoba;
            int liczba_przesuniec;
            cin >> osoba >> liczba_przesuniec;

            drzewo.m(osoba, liczba_przesuniec);

            break;
        }
        }
    }

    drzewo.wyswietl();

    return 0;
}


Node* DCZCZ::dodaj(Node* wierzcholek, string p, int x)
{
    if(!wierzcholek)
    {
        wierzcholek = new Node;
        wierzcholek->pseudonim = p;
        wierzcholek->wartosc_niebezpieczenstwa = x;
        wierzcholek->lewy = wierzcholek->prawy = wierzcholek->ojciec = NULL;
        ustawRownowage(wierzcholek);
        tablica[counter] = wierzcholek;
        counter++;
        return wierzcholek;
    }
    else if(p < wierzcholek->pseudonim)
    {
        wierzcholek->lewy = dodaj(wierzcholek->lewy, p, x);
        wierzcholek->lewy->ojciec = wierzcholek;
    }
    else if(p > wierzcholek->pseudonim)
    {
        wierzcholek->prawy = dodaj(wierzcholek->prawy, p, x);
        wierzcholek->prawy->ojciec = wierzcholek;
    }
    return wierzcholek;
}
void DCZCZ::ustawRownowage(Node *&wierzcholek)
{
    Node *ojcu=NULL, *grandojcu=NULL;

    while(wierzcholek != korzen)
    {
        if(getKolor(wierzcholek)=='r' && getKolor(wierzcholek->ojciec)=='r')
        {
            ojcu = wierzcholek->ojciec;
            grandojcu = ojcu->ojciec;
            if(ojcu == grandojcu->lewy)
            {
                Node *wujek = grandojcu->prawy;
                if(getKolor(wujek) == 'r')
                {
                    if(wujek)
                        wujek->kolor = 'b';
                    if(ojcu)
                        ojcu->kolor = 'b';
                    if(grandojcu)
                        grandojcu->kolor = 'r';

                    wierzcholek = grandojcu;
                }
                else
                {
                    if(wierzcholek == ojcu->prawy)
                    {
                        rotacjaLewo(ojcu);
                        wierzcholek = ojcu;
                        ojcu = wierzcholek->ojciec;
                    }
                    rotacjaPrawo(grandojcu);
                    swap(ojcu->kolor, grandojcu->kolor);
                    wierzcholek = ojcu;
                }
            }
            else
            {
                Node *wujek = grandojcu->lewy;
                if(wujek!=NULL && getKolor(wujek) == 'r')
                {
                    if(wujek)
                        wujek->kolor = 'b';
                    if(ojcu)
                        ojcu->kolor = 'b';
                    if(grandojcu)
                        grandojcu->kolor = 'r';
                    wierzcholek = grandojcu;
                }
                else
                {
                    if(wierzcholek == ojcu->lewy)
                    {
                        rotacjaPrawo(ojcu);
                        wierzcholek = ojcu;
                        ojcu = wierzcholek->ojciec;
                    }
                    rotacjaLewo(grandojcu);
                    swap(ojcu->kolor, grandojcu->kolor);
                    wierzcholek = ojcu;
                }
            }
        }
        else
            break;
    }
    wierzcholek->kolor = 'b';
}
char DCZCZ::getKolor(Node *&w)
{
    return w ? w->kolor : 'b';
}

void DCZCZ::rotacjaLewo(Node *&wierzcholek)
{
    Node *temp = wierzcholek->prawy;
    wierzcholek->prawy = temp->lewy;

    wierzcholek->prawy->ojciec = wierzcholek->prawy ? wierzcholek : NULL;
    temp->ojciec = wierzcholek->ojciec;

    if(!wierzcholek->ojciec)
        korzen = temp;
    else if(wierzcholek == wierzcholek->ojciec->lewy)
        wierzcholek->ojciec->lewy = temp;
    else
        wierzcholek->ojciec->prawy = temp;

    temp->lewy = wierzcholek;
    wierzcholek->ojciec = temp;
}
void DCZCZ::rotacjaPrawo(Node *&wierzcholek)
{
    Node *temp = wierzcholek->lewy;
    wierzcholek->lewy = temp->prawy;

    wierzcholek->lewy->ojciec = wierzcholek->lewy ? wierzcholek : NULL;
    temp->ojciec = wierzcholek->ojciec;

    if(!wierzcholek->ojciec)
        korzen = temp;
    else if(wierzcholek == wierzcholek->ojciec->lewy)
        wierzcholek->ojciec->lewy = temp;
    else
        wierzcholek->ojciec->prawy = temp;

    temp->prawy = wierzcholek;
    wierzcholek->ojciec = temp;
}
void DCZCZ::r(string osobaA, string osobaB)
{
    Node *element1=znajdz(osobaA, korzen);
    Node *element2=znajdz(osobaB, korzen);

    swap(tablica[element1->wartosc_niebezpieczenstwa], tablica[element2->wartosc_niebezpieczenstwa]);
    swap(tablica[element1->wartosc_niebezpieczenstwa]->wartosc_niebezpieczenstwa, tablica[element2->wartosc_niebezpieczenstwa]->wartosc_niebezpieczenstwa);
}
void DCZCZ::m(string a, int liczba_przejsc)
{
    Node *element=znajdz(a, korzen);
    int index = element->wartosc_niebezpieczenstwa;

    if(liczba_przejsc>0)
    {
        for(int i=0; i<liczba_przejsc; i++)
        {
            tablica[index] = tablica[index-1];
            tablica[index]->wartosc_niebezpieczenstwa++;
            index--;
        }
        tablica[index] = element;
        tablica[index]->wartosc_niebezpieczenstwa-=liczba_przejsc;
    }
    else
    {
        liczba_przejsc*=-1;
        for(int i=0; i<liczba_przejsc; i++)
        {
            tablica[index] = tablica[index+1];
            tablica[index]->wartosc_niebezpieczenstwa--;
            index++;
        }
        tablica[index] = element;
        tablica[index]->wartosc_niebezpieczenstwa+=liczba_przejsc;
    }
}
Node* DCZCZ::znajdz(string s, Node *ojciec)
{
    if(ojciec->pseudonim == s)
        return ojciec;
    else
    {
        if(s>=ojciec->pseudonim)
            return znajdz(s, ojciec->prawy);
        else if(s<ojciec->pseudonim)
            return znajdz(s, ojciec->lewy);
    }
    return NULL;
}
void DCZCZ::wyswietl()
{
    for(int i=0; i<rozmiar; i++)
    {
        if(tablica[i])
            cout << tablica[i]->pseudonim << endl;
        else
            break;
    }
}
void DCZCZ::rozszerzTablice()
{
    rozmiar=rozmiar*2;
    Node **temp_tablica = new Node* [rozmiar];

    for(int i=0; i<rozmiar; i++)
    {
        if(i<counter)
        {
            temp_tablica[i]=tablica[i];
        }
        else
            temp_tablica[i]=NULL;
    }
    delete [] tablica;
    tablica = temp_tablica;
}