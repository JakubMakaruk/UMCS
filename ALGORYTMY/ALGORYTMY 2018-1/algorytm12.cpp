#include <iostream>

using namespace std;

int liczbaSkrzynek, liczbaButelek, pojemnoscSamolotu;

struct ElementListy
{
    int indeks;
    double suma;
};

class Lista
{
public:
    ElementListy* tablica;
    int indeksTablicy;
    int wielkosc;

    Lista();
    void dodaj(double suma, int indeks);
    void insertSort();
};

Lista::Lista()
{
    indeksTablicy=0;
    wielkosc=4;
    tablica = new ElementListy[wielkosc];
}

void Lista::dodaj(double sum, int indek)
{
    if(indeksTablicy == wielkosc)
    {
        wielkosc = wielkosc*2;
        ElementListy* tablica_pom = new ElementListy[wielkosc];
        for(int i=0; i<indeksTablicy; i++)
            tablica_pom[i] = tablica[i];
        delete [] tablica;
        tablica = tablica_pom;
    }
    tablica[indeksTablicy].indeks = indek;
    tablica[indeksTablicy].suma = sum;
    indeksTablicy++;
}

void Lista::insertSort()
{
    int j;
    for(int i=1; i<indeksTablicy; i++)
    {
        ElementListy pom = tablica[i];
        for(j=i-1; j>=0; j--)
        {
            if(tablica[j].suma < pom.suma)
                tablica[j+1]=tablica[j];
            else
                break;
        }
        tablica[j+1]=pom;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);

    cin >> liczbaSkrzynek >> liczbaButelek >> pojemnoscSamolotu;

    double dwaTablica[liczbaSkrzynek][liczbaButelek];

    Lista *kubelki = new Lista [liczbaSkrzynek+1];
    for(int i=0; i<liczbaSkrzynek; i++)
    {
        double suma=0;
        for(int j=0; j<liczbaButelek; j++)
        {
            cin >> dwaTablica[i][j];
            suma = suma + dwaTablica[i][j];
        }
        int iteratorPomocny = (liczbaSkrzynek-1)*(int)suma/liczbaButelek;

        kubelki[iteratorPomocny].dodaj(suma, i);
    }

    for(int i=liczbaSkrzynek; i>=0; i--)
    {
        if(pojemnoscSamolotu == 0)
            break;
        if(kubelki[i].tablica[0].suma != 0 && kubelki[i].tablica[1].suma != 0)
        {
            if(pojemnoscSamolotu != 0)
            {
                kubelki[i].insertSort();

                int iter1=0;
                while(iter1<kubelki[i].indeksTablicy)
                {
                    int iter2=0;
                    while(iter2<liczbaButelek)
                    {
                        cout << dwaTablica[kubelki[i].tablica[iter1].indeks][iter2] << " ";
                        iter2++;
                    }
                    pojemnoscSamolotu--;
                    iter1++;
                    cout << endl;
                    if(pojemnoscSamolotu == 0)
                    {
                        break;
                    }
                }
            }
            else
            {
                break;
            }
        }
        else if(kubelki[i].tablica[0].suma != 0 && kubelki[i].tablica[1].suma == 0)
        {
            if(pojemnoscSamolotu != 0)
            {
                int iter=0;
                while(iter<liczbaButelek)
                {
                    cout << dwaTablica[kubelki[i].tablica[0].indeks][iter] << " ";
                    iter++;
                }
                cout << endl;
                pojemnoscSamolotu--;
            }
            else
            {
                break;
            }
        }
    }

    return 0;
}