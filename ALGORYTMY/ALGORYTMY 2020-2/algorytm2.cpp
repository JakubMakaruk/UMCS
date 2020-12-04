#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

long liczba_postojow;

struct ElementGrafu
{
    long x, y, index;
    vector<ElementGrafu*> sasiedzi;
};

struct ElementKopca
{
    ElementGrafu* wierzcholek;
    int dyst;
    int stopien;
    bool mark;
    ElementKopca *lewo, *prawo, *dziecko, *ojciec;
};

class KopiecFibbonacciego
{
public:
    ElementKopca* korzen;
    int rozmiar;

    KopiecFibbonacciego();
    ElementKopca* zrob_pare(int d, ElementGrafu *wierzcholek);
    void dodaj(ElementKopca *ret);
    ElementKopca* polacz(ElementKopca* a, ElementKopca* b);
    void usun();
    ElementKopca* decreaseKey(ElementKopca *temp);
    void dodajDziecko(ElementKopca *ojciec, ElementKopca *dziecko);
    bool czyPusty();
};

bool compareX(const ElementGrafu* a,const ElementGrafu* b)
{
    return a->x < b->x;
}

bool compareY(const ElementGrafu* a,const ElementGrafu* b)
{
    return a->y < b->y;
}
long algorytm_dijkstry(vector<ElementGrafu*> tablica, ElementGrafu *start, ElementGrafu *docelowe, long *dystans)
{
    sort(tablica.begin(), tablica.end(), compareX);
    for(long i=1; i<liczba_postojow; i++)
    {
        tablica[i]->sasiedzi.push_back(tablica[i-1]);
        tablica[i-1]->sasiedzi.push_back(tablica[i]);
    }

    sort(tablica.begin(), tablica.end(), compareY);
    for(long i=1; i<liczba_postojow; i++)
    {
        tablica[i]->sasiedzi.push_back(tablica[i-1]);
        tablica[i-1]->sasiedzi.push_back(tablica[i]);
    }

    KopiecFibbonacciego kopiec;
    kopiec.dodaj(kopiec.zrob_pare(0, start));
    dystans[start->index] = 0;

    while(!kopiec.czyPusty())
    {
        ElementKopca w = *kopiec.korzen;

        kopiec.usun();
        ElementGrafu* temp = w.wierzcholek;

        if(w.wierzcholek == docelowe)
            return dystans[temp->index];

        for(vector<ElementGrafu*>::iterator it=temp->sasiedzi.begin();it!=temp->sasiedzi.end();++it)
        {
            long roznica_x = abs(temp->x - (*it)->x);
            long roznica_y = abs(temp->y - (*it)->y);

            long waga;
            if(roznica_x < roznica_y)
                waga = roznica_x;
            else
                waga = roznica_y;

            if(dystans[(*it)->index]>dystans[temp->index]+waga)
            {
                dystans[(*it)->index] = dystans[temp->index] + waga;
                kopiec.dodaj(kopiec.zrob_pare(dystans[(*it)->index], *it));
            }
        }
    }
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
        cin >> n->x >> n->y;
        n->index = i;
        tab.push_back(n);
        dystans[i] = 99999999;
    }

    long start, docelowe;
    cin >> start >> docelowe;

    ElementGrafu *s = tab[start];
    ElementGrafu *d = tab[docelowe];

    cout << algorytm_dijkstry(tab, s, d, dystans);

    return 0;
}

KopiecFibbonacciego::KopiecFibbonacciego()
{
    korzen = NULL;
}
ElementKopca* KopiecFibbonacciego::zrob_pare(int d, ElementGrafu *wierzcholek)
{
    ElementKopca *temp = new ElementKopca;
    temp->dyst = d;
    temp->mark = false;
    temp->stopien = 0;
    temp->lewo = temp->prawo = temp;
    temp->dziecko = temp->ojciec = NULL;
    temp->wierzcholek = wierzcholek;

    return temp;
}
void KopiecFibbonacciego::dodaj(ElementKopca *ret)
{
    if(czyPusty())
        korzen = ret;
    else
    {
        korzen->lewo->prawo = ret;
        ret->lewo = korzen->lewo;
        korzen->lewo = ret;
        ret->prawo = korzen;
        if(ret->dyst < korzen->dyst)
            korzen=ret;
    }
    rozmiar++;
}
ElementKopca* KopiecFibbonacciego::polacz(ElementKopca *a, ElementKopca *b)
{
    ElementKopca *nowyKopiec = new ElementKopca();

    a->prawo->lewo = b->lewo;
    b->lewo->prawo = a->prawo;
    a->prawo = b;
    b->lewo  = a;
    if(b->dyst < nowyKopiec->dyst)
        swap(b->dyst, a->dyst);

    return a;
}
void KopiecFibbonacciego::usun()
{
    ElementKopca *temp = korzen;

    if(temp->prawo!=temp)
    {
        temp->prawo->lewo = temp->lewo;
        temp->lewo->prawo = temp->prawo;
        if(temp->dziecko)
            temp = polacz(temp->prawo, temp->dziecko);
        else
            temp = temp->prawo;
    }
    else if(temp->prawo==temp && temp->dziecko)
    {
        temp=temp->dziecko;
    }
    else
    {
        temp = NULL;
        return;
    }

    ElementKopca *drzewa[20];
    for(int i=0; i<20; i++)
        drzewa[i] = NULL;

    while(true)
    {
        if(temp!=drzewa[temp->stopien])
            break;
        if(drzewa[temp->stopien]==NULL)
            drzewa[temp->stopien] = temp;
        else
        {
            drzewa[temp->stopien] = polacz(temp, drzewa[temp->stopien]);
            drzewa[temp->stopien]->stopien++;
        }
        temp = temp->prawo;
    }
    ElementKopca *min = temp;
    ElementKopca *stary_korzen = temp;
    temp = temp->prawo;
    while(temp!=stary_korzen)
    {
        if(temp->dyst < min->dyst)
            min = temp;
        temp = temp->prawo;
    }
    korzen = min;
    temp=NULL;
}
bool KopiecFibbonacciego::czyPusty()
{
    return !korzen;
}