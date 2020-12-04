#include <iostream>
#include <list>

using namespace std;

long liczba_uczestnikow, liczba_potraw, ilosc_dan, wynik=0;

struct Food
{
    long numer, ilosc=ilosc_dan;
    list<long> wierzcholki_przypisane;
};

struct Node
{
    list<long>::iterator wybrana_potrawa=potrawy.end();
    list<long> potrawy;
    bool skojarzony=false;
};

class Graph
{
public:
    Node* wierzcholki;
    Food* potrawy;

    Graph();
    void dodaj(long i, long potrawa);
    void rozwiaz();
    bool czy_moze_byc_cos_innego(long nr_potrawy);
};


int main()
{
    cin >> liczba_uczestnikow >> liczba_potraw >> ilosc_dan;

    Graph graf;
    for(long i=0; i<liczba_uczestnikow; i++)
    {
        graf.wierzcholki[i].skojarzony=false;
        for(long j=0; j<liczba_potraw; j++)
        {
            char c;
            cin >> c;
            if(c=='x')
                graf.dodaj(j, i);
        }
    }

    graf.rozwiaz();
    cout << wynik;

    return 0;
}

Graph::Graph()
{
    wierzcholki = new Node [liczba_uczestnikow];
    potrawy = new Food [liczba_potraw];
}
void Graph::dodaj(long potrawa, long wierzcholek)
{
    wierzcholki[wierzcholek].potrawy.push_back(potrawa);
}
void Graph::rozwiaz()
{
    for(long i=0; i<liczba_uczestnikow; i++)
    {
        if(!wierzcholki[i].potrawy.empty())
        {
            for(list<long>::iterator it=wierzcholki[i].potrawy.begin(); it!=wierzcholki[i].potrawy.end(); it++)
            {
                if(potrawy[(*it)].ilosc>0)
                {
                    potrawy[(*it)].ilosc--;
                    potrawy[(*it)].wierzcholki_przypisane.push_back(i);
                    wierzcholki[i].wybrana_potrawa = it;
                    wynik++;
                    break;
                }
                else if (czy_moze_byc_cos_innego((*it)))
                {
                    potrawy[(*it)].ilosc--;
                    potrawy[(*it)].wierzcholki_przypisane.push_back(i);
                    wierzcholki[i].wybrana_potrawa = it;
                    wynik++;
                    break;
                }
            }
        }
    }
}
bool Graph::czy_moze_byc_cos_innego(long nr_potrawy)
{
    for(list<long>::iterator it=potrawy[nr_potrawy].wierzcholki_przypisane.begin(); it!=potrawy[nr_potrawy].wierzcholki_przypisane.end(); it++)
    {
        if(wierzcholki[*it].skojarzony==false)
        {
            for(list<long>::iterator potr=wierzcholki[(*it)].potrawy.begin(); potr!=wierzcholki[(*it)].potrawy.end(); potr++)
            {
                if((*potr)!=nr_potrawy)
                {
                    if(potrawy[(*potr)].ilosc>0)
                    {
                        potrawy[(*wierzcholki[(*it)].wybrana_potrawa)].ilosc++;
                        potrawy[(*wierzcholki[(*it)].wybrana_potrawa)].wierzcholki_przypisane.erase(it);

                        potrawy[(*potr)].ilosc--;
                        potrawy[(*potr)].wierzcholki_przypisane.push_back((*it));
                        
                        wierzcholki[(*it)].wybrana_potrawa=potr;
                        wierzcholki[*it].skojarzony=true;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}