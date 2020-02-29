#include <iostream>

using namespace std;

int liczba_panstw;

struct Panstwo
{
    int id, wartosc;
};

int znajdz_min_index(Panstwo tablica[], int index)
{
    for(int i=1; i<liczba_panstw; i++)
    {
        if((tablica[index].wartosc == tablica[i].wartosc) && (tablica[index].id > tablica[i].id))
            index = i;
    }
    return index;
}

int zwezanie(Panstwo tablica[], int temp_start, int temp_koniec)
{
    Panstwo losowa = tablica[temp_start+((temp_koniec-temp_start)/2)];
    temp_start--;
    temp_koniec++;

    while(true)
    {
        do
        {
            temp_start++;
        }while(tablica[temp_start].wartosc < losowa.wartosc);

        do
        {
            temp_koniec--;
        }while(tablica[temp_koniec].wartosc > losowa.wartosc);

        if(temp_start>=temp_koniec)
            break;

        swap(tablica[temp_start], tablica[temp_koniec]);
    }
    return temp_koniec;
}

void algorytm_hoara(Panstwo tablica[], int start, int koniec, int ktory_element)
{
    while(start!=koniec)
    {
        int nowa_lewa=zwezanie(tablica, start, koniec);
        nowa_lewa=nowa_lewa-start+1;

        if(ktory_element<=nowa_lewa)
        {
            koniec=start+nowa_lewa-1;
        }
        else
        {
            start += nowa_lewa;
            ktory_element -= nowa_lewa;
        }
    }
    cout << tablica[znajdz_min_index(tablica, start)].id << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> liczba_panstw;

    Panstwo panstwa[liczba_panstw];

    for(int i=0; i<liczba_panstw; i++)
    {
        cin >> panstwa[i].id >> panstwa[i].wartosc;
    }

    int liczba_zapytan;
    cin >> liczba_zapytan;

    for(int i=0; i<liczba_zapytan; i++)
    {
        int ktory_element;
        cin >> ktory_element;

        algorytm_hoara(panstwa, 0, liczba_panstw-1, ktory_element);
    }

    return 0;
}