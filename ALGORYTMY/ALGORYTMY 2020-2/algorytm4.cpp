#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Element
{
    int indeks;
    vector<int> zainteresowania;
};

struct Krawedz
{
    int e1, e2;
};

struct Struktura
{
    int wierzcholek, zainteresowanie;
};

class Graf
{
public:
    vector<Krawedz> krawedzie;

    void dodaj_krawedz(Krawedz a);
    void rozwiaz_zadanie();
    int Find(int x);
    void Union(int a, int b);
};

bool compare(const Struktura a, const Struktura b)
{
    return a.zainteresowanie < b.zainteresowanie;
}

int liczba_danych;

int *tablica = new int[liczba_danych];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> liczba_danych;

    Graf graf;
    Element* tablica_wierzcholkow = new Element [liczba_danych];

    vector<Struktura> wektor;

    for(int i=0; i<liczba_danych; i++)
    {
        tablica[i]=i;

        int liczba_zainteresowan;
        cin >> liczba_zainteresowan;

        for(int j=0; j<liczba_zainteresowan; j++)
        {
            int zainteresowanie;
            cin >> zainteresowanie;

            //tablica_wierzcholkow[i].zainteresowania.push_back(zainteresowanie);
            Struktura s;
            s.wierzcholek=i;
            s.zainteresowanie=zainteresowanie;
            wektor.push_back(s);
        }
        //tablica_wierzcholkow[i].indeks=i;
    }

    sort(wektor.begin(), wektor.end(), compare);

//    for(vector<Struktura>::iterator it=wektor.begin(); it!=wektor.end(); it++)
//        cout << (*it).wierzcholek << (*it).zainteresowanie << endl;

    for(vector<Struktura>::iterator it=wektor.begin(); it!=wektor.end(); it++)
    {
        vector<Struktura>::iterator it2=it+1;
        while((*it2).zainteresowanie==(*it).zainteresowanie)
        {
            Krawedz k;
            k.e1=(*it).wierzcholek;
            k.e2=(*it2).wierzcholek;
            graf.krawedzie.push_back(k);
            it2++;
        }
    }

    graf.rozwiaz_zadanie();

    return 0;
}


void Graf::dodaj_krawedz(Krawedz a)
{
    krawedzie.push_back(a);
}
void Graf::rozwiaz_zadanie()
{
    for(vector<Krawedz>::iterator it=krawedzie.begin(); it!=krawedzie.end(); it++)
    {
        int f1 = Find((*it).e1);
        int f2 = Find((*it).e2);

        if(f1==f2)
        {
            cout << "TAK";
            return;
        }
        else
            Union((*it).e1, (*it).e2);
    }
    cout << "NIE";
}
int Graf::Find(int x)
{
    if(tablica[x] != x)
        tablica[x] = Find(tablica[x]);
    return tablica[x];
}
void Graf::Union(int a, int b)
{
    int f1 = Find(a);
    int f2 = Find(b);

    tablica[f1] = f2;
}