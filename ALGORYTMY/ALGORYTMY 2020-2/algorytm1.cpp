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

    priority_queue<pair<long,ElementGrafu*>, vector<pair<long,ElementGrafu*> >, greater<pair<long, ElementGrafu*> > > kolejka;
    kolejka.push(make_pair(0,start));
    dystans[start->index] = 0;

    while(!kolejka.empty())
    {
        pair<long, ElementGrafu*> w = kolejka.top();
        kolejka.pop();
        ElementGrafu *temp = w.second;

        if(w.second == docelowe)
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
                kolejka.push(make_pair(dystans[(*it)->index], *it));
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