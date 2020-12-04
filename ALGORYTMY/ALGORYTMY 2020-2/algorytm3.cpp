#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long liczba_postojow;

struct ElementGrafu
{
    long x, y, postoj, index;
};
struct Krawedz
{
    long src, dest, waga;
};

class Graf
{
public:
    Krawedz *krawedzie;
    long licznik=0;

    Graf() { krawedzie = new Krawedz[liczba_postojow*4]; }
    void dodaj(ElementGrafu *p, ElementGrafu *q, long w)
    {
        krawedzie[licznik].src = p->index;
        krawedzie[licznik].dest = q->index;
        krawedzie[licznik].waga = w;
        licznik++;
    }
};

bool compareX(const ElementGrafu* a, const ElementGrafu* b)
{
    return a->x < b->x;
}

bool compareY(const ElementGrafu* a, const ElementGrafu* b)
{
    return a->y < b->y;
}
bool znajdz_cykl(Graf g, long *dystans)
{
    for(int j=0; j<g.licznik; j++)
    {
        if(dystans[g.krawedzie[j].src]!=99999999)
        {
            if(dystans[g.krawedzie[j].dest] > dystans[g.krawedzie[j].src] + g.krawedzie[j].waga)
                return true;
        }
    }

    return false;
}
long algorytm_bellman_ford(vector<ElementGrafu*> tablica, ElementGrafu *start, ElementGrafu *docelowe, long *dystans)
{
    Graf graf;

    sort(tablica.begin(), tablica.end(), compareX);
    for(long i=1; i<liczba_postojow; i++)
    {
        long roznica_x = abs(tablica[i]->x - tablica[i-1]->x);
        long roznica_y = abs(tablica[i]->y - tablica[i-1]->y);

        long waga1, waga2;
        if(roznica_x < roznica_y)
            waga1 = waga2 = roznica_x;
        else
            waga1 = waga2 = roznica_y;

        waga1 -= tablica[i]->postoj;
        waga2 -=tablica[i-1]->postoj;

        graf.dodaj(tablica[i-1], tablica[i], waga1);
        graf.dodaj(tablica[i], tablica[i-1], waga2);
    }

    sort(tablica.begin(), tablica.end(), compareY);
    for(long i=1; i<liczba_postojow; i++)
    {
        long roznica_x = abs(tablica[i]->x - tablica[i-1]->x);
        long roznica_y = abs(tablica[i]->y - tablica[i-1]->y);

        long waga1, waga2;
        if(roznica_x < roznica_y)
            waga1 = waga2 = roznica_x;
        else
            waga1 = waga2 = roznica_y;

        waga1 -= tablica[i]->postoj;
        waga2 -= tablica[i-1]->postoj;

        graf.dodaj(tablica[i-1], tablica[i], waga1);
        graf.dodaj(tablica[i], tablica[i-1], waga2);
    }

    dystans[start->index] = 0;

    for(int i=0; i<liczba_postojow-1; i++)
    {
        for(int j=0; j<graf.licznik; j++)
        {
            if(dystans[graf.krawedzie[j].src]!=99999999)
            {
                if(dystans[graf.krawedzie[j].dest] > dystans[graf.krawedzie[j].src] + graf.krawedzie[j].waga)
                    dystans[graf.krawedzie[j].dest] = dystans[graf.krawedzie[j].src] + graf.krawedzie[j].waga;
            }
        }
    }

    if(znajdz_cykl(graf, dystans))
        return -1000;
    else
        return dystans[docelowe->index];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin >> liczba_postojow;

    vector<ElementGrafu*> tab;
    long dystans[liczba_postojow];

    for(long i=0; i<liczba_postojow; i++)
    {
        ElementGrafu *n = new ElementGrafu();
        cin >> n->x >> n->y >> n->postoj;
        n->index = i;
        tab.push_back(n);
        dystans[i] = 99999999;
    }

    long start, docelowe;
    cin >> start >> docelowe;

    ElementGrafu *s = tab[start];
    ElementGrafu *d = tab[docelowe];

    long wynik = algorytm_bellman_ford(tab, s, d, dystans);
    if(wynik==-1000)
        cout << "NIE ZA DOBRZE?";
    else
        cout << wynik;

    return 0;
}