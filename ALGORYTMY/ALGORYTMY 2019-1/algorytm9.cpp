#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Osoba
{
    long poczatek, koniec;

    Osoba(long a, long b) : poczatek(a), koniec(b) {}

    bool operator < (const Osoba &o1) const
    {
        return (koniec < o1.koniec);
    }
};


int main()
{
    ios::sync_with_stdio(false);

    int liczba_zestawow;
    cin >> liczba_zestawow;

    for(int i=0; i<liczba_zestawow; i++)
    {
        vector<Osoba> osoby;

        long liczba_osob;
        cin >> liczba_osob;

        for(int j=0; j<liczba_osob; j++)
        {
            long a, b;
            cin >> a >> b;

            Osoba o(a, b);
            osoby.push_back(o);
        }

        sort(osoby.begin(), osoby.end());

        long ostatni=osoby[0].koniec, wynik=1;
        for(long i=1; i<osoby.size(); i++)
        {
            if(osoby[i].poczatek >= ostatni)
            {
                ostatni = osoby[i].koniec;
                wynik++;
            }
        }
        cout << wynik << endl;
    }

    return 0;
}