#include <iostream>
#include <vector>

using namespace std;

class Graf
{
public:
    int n;
    vector<int> *sasiedzi;
    int **macierz;

    int poziom;

    Graf(int liczbaWierzcholkow);
    void dodajSasiadow(int liczbaWytycznych);
    int rozwiaz(int n, int m, int s, int k);
    int DFS(int wierzcholek, int k, int s, int poziom);
};

Graf::Graf(int liczbaWierzcholkow)
{
    n = liczbaWierzcholkow;
    sasiedzi = new vector<int> [liczbaWierzcholkow];

    poziom=-1;
}

void Graf::dodajSasiadow(int liczbaWytycznych)
{
    for(int i=0; i<liczbaWytycznych; i++)
    {
        int wierzcholek, sasiad;
        cin >> wierzcholek >> sasiad;
        sasiedzi[wierzcholek].push_back(sasiad);
    }
}

int Graf::rozwiaz(int n, int m, int s, int k)
{
    macierz = new int * [n];

    for(int i=0; i<n; i++)
    {
        macierz[i] = new int[k+1];
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<k+1; j++)
        {
            macierz[i][j]=-1;
        }
    }

    return DFS(0, k, s, poziom);
}


int Graf::DFS(int wierzcholek, int k, int s, int poziom)
{
    poziom++;

    if(macierz[wierzcholek][poziom] == 0)
    {
        return 0;
    }
    if(macierz[wierzcholek][poziom] > 0)
    {
        return macierz[wierzcholek][poziom];
    }
    if(wierzcholek != s && poziom == k)
    {
        return 0;
    }
    if(wierzcholek == s && poziom == k)
    {
        return 1;
    }
    if(macierz[wierzcholek][poziom] == -1)
    {
        macierz[wierzcholek][poziom]=0;
    }
    for(vector<int>::iterator i=sasiedzi[wierzcholek].begin(); i != sasiedzi[wierzcholek].end(); i++)
    {
            macierz[wierzcholek][poziom] = macierz[wierzcholek][poziom] + DFS(*i, k, s, poziom);
    }
    return macierz[wierzcholek][poziom];
}

int main()
{
    int liczbaTestow;
    cin >> liczbaTestow;
    for(int i=0; i<liczbaTestow; i++)
    {
        int liczbaPunktowOdbiorow, liczbaWytycznychPrzejazdow, nrKoncowy, liczbaPaczek;
        cin >> liczbaPunktowOdbiorow >> liczbaWytycznychPrzejazdow >> nrKoncowy >> liczbaPaczek;

        Graf *g = new Graf(liczbaPunktowOdbiorow);
        g->dodajSasiadow(liczbaWytycznychPrzejazdow);
        cout << g->rozwiaz(liczbaPunktowOdbiorow, liczbaWytycznychPrzejazdow, nrKoncowy, liczbaPaczek) << endl;

    }
    return 0;
}