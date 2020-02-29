#include <iostream>
#include <vector>

using namespace std;

struct Krawedz
{
    int a, c, d;
    Krawedz(int a, int c, int d) : a(a), c(c), d(d) {}
};

int main()
{
    ios_base::sync_with_stdio(false);
    int liczba_mediow, start, dzien, liczba_krawedzi, liczba_dni;

    cin >> liczba_mediow >> start >> dzien >> liczba_dni >> liczba_krawedzi;

    vector<Krawedz> krawedzie[7];
    long wyniki[liczba_mediow][7];

    for(int i=0; i<liczba_mediow; i++)
    {
        for(int j=0; j<7; j++)
        {
            wyniki[i][j] = 0;
        }
    }

    for(int i=0; i<liczba_krawedzi; i++)
    {
        int kto, kiedy, od_kogo, od_kogo_kiedy;
        cin >> kto >> kiedy >> od_kogo >> od_kogo_kiedy;

        Krawedz k(kto, od_kogo, od_kogo_kiedy);
        krawedzie[kiedy].push_back(k);
    }

    long wynik = 1;
    wyniki[start][dzien] = 1;

    dzien++;

    for(int j=dzien; j<dzien+liczba_dni-1; j++)
    {
        for(int a=0; a<liczba_mediow; a++)
            wyniki[a][j%7]=0;

        for(vector<Krawedz>::iterator it=krawedzie[j%7].begin(); it!=krawedzie[j%7].end(); it++)
        {
            if(wyniki[(*it).c][(*it).d]>0)
            {
                wyniki[(*it).a][j%7] = wyniki[(*it).a][j%7] + wyniki[(*it).c][(*it).d];
                wyniki[(*it).a][j%7]%=100000007;
            }
        }

        for(int h=0; h<liczba_mediow; h++)
        {
            wynik+=wyniki[h][j%7];
            wynik%=100000007;
        }
    }

    cout << wynik;

    return 0;
}