#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

struct Osoba
{
    int liczba_tras;
    vector<string> sasiedzi;
};

int main()
{
    ios::sync_with_stdio(false);

    int liczba_zestawow;
    cin >> liczba_zestawow;

    for(int i=0; i<liczba_zestawow; i++)
    {
        int l_nazwisk, l_par_nazwisk;
        cin >> l_nazwisk >> l_par_nazwisk;

        map<string, Osoba> osoby;
        for(int j=0; j<l_nazwisk; j++)
        {
            string nazwisko;
            cin >> nazwisko;

            osoby[nazwisko].liczba_tras = 0;
        }
        for(int j=0; j<l_par_nazwisk; j++)
        {
            string n1, n2;
            cin >> n1 >> n2;

            osoby[n1].sasiedzi.push_back(n2); 
			
            osoby[n2].liczba_tras++;
        }

        bool czy_wynik = true;

        queue<string> wynik; 
        for(int j=0; j<l_nazwisk; j++)
        {
            string osoba;
            cin >> osoba;
            wynik.push(osoba);
        }
        for(int j=0; j<l_nazwisk; j++)
        {
            string obecna_osoba = wynik.front();
            wynik.pop();
            Osoba badany = osoby[obecna_osoba]; 

            if(badany.liczba_tras==0)
            {
                if(!badany.sasiedzi.empty())
                {
                    for(vector<string>::iterator wsk=badany.sasiedzi.begin(); wsk!=badany.sasiedzi.end(); ++wsk) 
                    {
                        osoby[*wsk].liczba_tras--;
                    }
                }
            }
            else
            {
                czy_wynik = false;
                break;
            }
        }
        if(czy_wynik==true)
            cout << "TAK" << endl;
        else
        {
            cout << "NIE" << endl;
        }
    }

    return 0;
}