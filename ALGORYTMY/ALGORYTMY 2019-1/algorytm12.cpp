#include <iostream>
#include <vector>

using namespace std;

long liczba_opisow;

struct Dokument
{
    long wartosci[4]={-1,-1,-1,-1}; // 0-id, 1-priorytet, 2-losowy_kod, 3-liczba_kodów
    long kody[4]={-1,-1,-1,-1};
};

void wyswietl_wektor(Dokument *tab[], int n)
{
    for(int i=0; i<n; i++)
        cout << i << ". " << tab[i]->wartosci[0] << " " << tab[i]->wartosci[1] << " " << tab[i]->wartosci[2] << " " << tab[i]->wartosci[3] << " K: " << tab[i]->kody[0] <<"|"<<tab[i]->kody[1]<<"|"<<tab[i]->kody[2]<<"|"<<tab[i]->kody[3] << endl;
    cout << endl;
}

void insertSort(vector<Dokument*> kubelki[], long typ_sortowania, long n)
{
    long b;
    for(long i=0; i<n; i++)
    {
        if(kubelki[i].size()>1)
        {
            for(long a=1; a<kubelki[i].size(); ++a)
            {
                Dokument* pom = kubelki[i][a];
                for(b=a-1; b>=0; --b)
                {
                    if(kubelki[i][b]->wartosci[2] > pom->wartosci[2])
                        kubelki[i][b+1]=kubelki[i][b];
                    else
                        break;
                }
                kubelki[i][b+1] = pom;
            }
        }
    }
}

void przed_sorotwaniem(Dokument *tab[], long typ_sortowania)
{
    if(typ_sortowania==4)
    {
        for(long a=3; a>=0; --a)
        {
            vector<Dokument*> kubelki[256];
            
            long indeks=0;
            for(long i=0; i<liczba_opisow; ++i)
            {
                if(tab[i]->kody[a]!=-1)
                    kubelki[tab[i]->kody[a]].push_back(tab[i]);
                else
                {
                    tab[indeks] = tab[i];
                    indeks++;
                }
            }
            
            for(long i=0; i<256; ++i)
            {
                for(vector<Dokument*>::iterator it=kubelki[i].begin(); it!= kubelki[i].end(); ++it)
                {
                    tab[indeks]=*it;
                    indeks++;
                }
            }
        }
    }
    else if(typ_sortowania==3)
    {
        vector<Dokument*> kubelki[liczba_opisow+1];
        long przedzial=10000000/liczba_opisow;
        
        for(long i=0; i<liczba_opisow; ++i)
        {
            kubelki[tab[i]->wartosci[2]/przedzial].push_back(tab[i]);
        }
        
        insertSort(kubelki, 3, liczba_opisow+1);
        
        long indeks=0;
        for(long i=0; i<liczba_opisow+1; ++i)
        {
            for(vector<Dokument*>::iterator it=kubelki[i].begin(); it!=kubelki[i].end(); ++it)
            {
                tab[indeks]=*it;
                indeks++;
            }
        }
    }
    else if(typ_sortowania==2)
    {
        vector<Dokument*> kubelki[11];
        
        for(long i=0; i<liczba_opisow; ++i)
        {
            kubelki[tab[i]->wartosci[1]].push_back(tab[i]);
        }
        
        long indeks=0;
        for(long i=0; i<11; ++i)
        {
            for(vector<Dokument*>::iterator it=kubelki[i].begin(); it!=kubelki[i].end(); ++it)
            {
                tab[indeks]=(*it);
                indeks++;
            }
        }
    }
    else if(typ_sortowania==1)
    {
        vector<Dokument*> kubelki[liczba_opisow];
        for(long i=0; i<liczba_opisow; ++i)
        {
            kubelki[tab[i]->wartosci[0]-1].push_back(tab[i]);
        }
        
        long indeks=0;
        for(long i=0; i<liczba_opisow; ++i)
        {
            tab[indeks]=kubelki[i][0];
            indeks++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    cin >> liczba_opisow;
    
    Dokument* tablica[liczba_opisow];
    
    for(long i=0; i<liczba_opisow; ++i)
    {
        Dokument* a = new Dokument;
        cin >> a->wartosci[0] >> a->wartosci[1] >> a->wartosci[2] >> a->wartosci[3];
        tablica[i] = a;
        
        for(long j=0; j<a->wartosci[3]; ++j)
        {
            long liczba;
            cin >> liczba;
            tablica[i]->kody[j] = liczba;
        }
    }
    long kolejnosc1, kolejnosc2, kolejnosc3, kolejnosc4;
    cin >> kolejnosc1 >> kolejnosc2 >> kolejnosc3 >> kolejnosc4;
    
    if(liczba_opisow>1)
    {
        przed_sorotwaniem(tablica, kolejnosc4);
        przed_sorotwaniem(tablica, kolejnosc3);
        przed_sorotwaniem(tablica, kolejnosc2);
        przed_sorotwaniem(tablica, kolejnosc1);
        
        long suma=0;
        for(long i=0; i<liczba_opisow; ++i)
        {
            suma = suma + i*tablica[i]->wartosci[2];
        }
        
        cout << suma%100000007;
    }
    else
        cout << 0;
    
    return 0;
}