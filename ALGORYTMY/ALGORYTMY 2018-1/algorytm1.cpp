#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef struct Samochod{
    string opis_samochodu;
    double przebieg;
    long int srednica;
    long int liczba_obrotow;
};

int main()
{
    ios_base::sync_with_stdio(false);

    unsigned int liczba_ogloszen;
    cin>>liczba_ogloszen;

    Samochod tablica[3];
    for(unsigned int i=0; i<3; i++)
    {
        tablica[i].opis_samochodu="";
        tablica[i].przebieg=0;
        tablica[i].srednica=0;
        tablica[i].liczba_obrotow=0;
    }
    Samochod temp, pom;
    for(unsigned int i=0; i<liczba_ogloszen; i++)
        {
            if(i<3)
                {
                    getline(cin, tablica[i].opis_samochodu);
                    getline(cin, tablica[i].opis_samochodu);
                    cin>>tablica[i].przebieg>>tablica[i].srednica;
                    if(tablica[i].przebieg==0)
                    {
                        tablica[i].liczba_obrotow = 0;
                    }
                    else
                    {
                        tablica[i].liczba_obrotow=(tablica[i].przebieg*100000)/(2*3.141593*((tablica[i].srednica*2.54)/2));
                    }
                    for(unsigned int j=0; j<3; j++)
                        {
                            if(tablica[i].liczba_obrotow < tablica[j].liczba_obrotow)
                                {
                                    swap(tablica[i], tablica[j]);
                                }
                            else if(tablica[i].liczba_obrotow == tablica[j].liczba_obrotow)
                                {
                                    if(tablica[i].opis_samochodu < tablica[j].opis_samochodu)
                                        {
                                            swap(tablica[i], tablica[j]);
                                        }
                                }
                        }
                }


            else
                {
                    getline(cin, temp.opis_samochodu);
                    getline(cin, temp.opis_samochodu);
                    cin>>temp.przebieg>>temp.srednica;

                    if(temp.przebieg==0)
                    {
                        temp.liczba_obrotow=0;
                    }
                    else
                    {
                        temp.liczba_obrotow=(temp.przebieg*100000)/(2*3.141593*((temp.srednica*2.54)/2));
                    }
                    for(unsigned int j=0; j<3; j++)
                        {
                            if(temp.liczba_obrotow < tablica[j].liczba_obrotow)
                                {
                                    swap(temp, tablica[j]);
                                }
                            else if(temp.liczba_obrotow == tablica[j].liczba_obrotow)
                                {
                                    if(temp.opis_samochodu < tablica[j].opis_samochodu)
                                        {
                                            swap(temp, tablica[j]);
                                        }
                                }

                        }
                }
        }

		for(int i=0; i<3; i++)
			cout << tablica[i]. opis_samochodu << "\n" << tablica[i].liczba_obrotow << endl;

    return 0;
}
