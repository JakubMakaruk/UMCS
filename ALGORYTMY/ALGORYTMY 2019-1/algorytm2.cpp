#include <iostream>

using namespace std;

struct Osoba
{
    string nazwisko;
    int liczba_minut;
};

int main()
{
    ios_base::sync_with_stdio(false);

    unsigned int liczba_zestawow;
    cin >> liczba_zestawow;

    unsigned int liczba_nazwisk, liczba_wynikow;
    long czas;
    unsigned int licznik_osob;
    for(unsigned int i=0; i<liczba_zestawow; i++)
    {
        cin >> liczba_nazwisk >> liczba_wynikow;
        Osoba tablica[liczba_nazwisk];
        czas=licznik_osob=1; 

        for(unsigned int j=0; j<liczba_nazwisk; j++)
        {
            cin >> tablica[j].nazwisko >> tablica[j].liczba_minut;
        }

        for(unsigned int h=liczba_nazwisk-1; h>0; h--) // SelectionSort
        {
            unsigned int max=0;
            for(unsigned int j=1; j<=h; j++)
            {
                if(tablica[j].liczba_minut < tablica[max].liczba_minut)
                    max = j;
                else if((tablica[j].liczba_minut == tablica[max].liczba_minut) && (tablica[j].nazwisko > tablica[max].nazwisko))
                    max = j;
            }
			
			cout << h << ". " << tablica[h].liczba_minut << " " << tablica[max].liczba_minut << endl;
            swap(tablica[h], tablica[max]);
        }

        for(unsigned int j=1; j<liczba_nazwisk; j++)
        {
            czas = czas + 1 + (licznik_osob*tablica[j].liczba_minut); 
            licznik_osob++;
        }

        for(unsigned int j=0; j<liczba_wynikow; j++)
            cout << tablica[j].nazwisko << " ";
        cout << "\n" << czas%1000003 << "\n";
    }

    return 0;
}
