#include <iostream>
#include <vector>

using namespace std;

struct Krawedz
{
    int krawedz[2], licznik=0;
};

int liczba_stacji, liczba_wolontariuszy, liczba_odcinkow;
Krawedz *tempa;

bool sprawdz(vector<Krawedz*> tab[])
{
    for(int i=0; i<liczba_stacji; ++i)
    {
        for(vector<Krawedz*>::iterator it=tab[i].begin(); it!=tab[i].end(); it++)
        {
            if((*it)->licznik==0)
            {
                tempa = *it;
                return false;
            }
        }
    }
    return true;
}

Krawedz* znajdz(vector<Krawedz*> tab[], Krawedz *aktualna) // patrzy tylko krawędzie wychodzące z danego wierzchołka np 1-2 1-3 1-4, czy któraś krawędź ma licznik=0
{
    for(vector<Krawedz*>::iterator it=tab[aktualna->krawedz[0]].begin(); it!=tab[aktualna->krawedz[0]].end(); it++)
    {
        if((*it)->licznik==0)
            return *it;
    }
    for(vector<Krawedz*>::iterator it=tab[aktualna->krawedz[1]].begin(); it!=tab[aktualna->krawedz[1]].end(); it++)
    {
        if((*it)->licznik==0)
            return *it;
    }
    return NULL;
}

bool przeszukiwanie_z_nawrotami(vector<Krawedz*> tab[], Krawedz* aktualna, int ustawieni_wolontariusze)
{
    if(ustawieni_wolontariusze>=liczba_wolontariuszy)
        return false;

    for(vector<Krawedz*>::iterator it = tab[aktualna->krawedz[0]].begin(); it!=tab[aktualna->krawedz[0]].end(); it++)
    {
        (*it)->licznik++; // inkrementuje wszystkie krawędzie gdzie jest aktualny wierzchołek
    }

    Krawedz *temp=znajdz(tab, aktualna);
    if(temp==NULL)
    {
        if(sprawdz(tab))
            return true;
        else
            temp = tempa;
    }

    if(przeszukiwanie_z_nawrotami(tab, temp, ustawieni_wolontariusze+1))
        return true;
    for(vector<Krawedz*>::iterator it=tab[aktualna->krawedz[0]].begin(); it!=tab[aktualna->krawedz[0]].end(); it++)
    {
        (*it)->licznik--;
    }
    for(vector<Krawedz*>::iterator it=tab[aktualna->krawedz[1]].begin(); it!=tab[aktualna->krawedz[1]].end(); it++)
    {
        (*it)->licznik++;
    }

    temp=znajdz(tab, aktualna);
    if(temp==NULL)
    {
        if(sprawdz(tab))
            return true;
        else temp = tempa;
    }

    if(przeszukiwanie_z_nawrotami(tab, temp, ustawieni_wolontariusze+1))
        return true;
    for(vector<Krawedz*>::iterator it = tab[aktualna->krawedz[1]].begin(); it!=tab[aktualna->krawedz[1]].end(); it++)
    {
        (*it)->licznik--;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int liczba_zestawow;
    cin >> liczba_zestawow;

    for(int i=0; i<liczba_zestawow; i++)
    {
        vector<Krawedz*> tab[30];
        cin >> liczba_stacji >> liczba_odcinkow >> liczba_wolontariuszy;

        Krawedz *start;
        for(int j=0; j<liczba_odcinkow; j++)
        {
            Krawedz *temp=new Krawedz();
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            temp->krawedz[0]=a;
            temp->krawedz[1]=b;
            tab[a].push_back(temp);
            tab[b].push_back(temp);
            if(j==0)
                start = temp;
        }

        if(przeszukiwanie_z_nawrotami(tab, start, 0))
            cout<<"TAK\n";
        else
            cout<<"NIE\n";
    }
    return 0;
}