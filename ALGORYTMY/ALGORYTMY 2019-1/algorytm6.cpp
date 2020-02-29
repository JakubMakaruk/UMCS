/*
Program ma za zadanie z podanej mapy miasta wyszukać najmniejszą długość ścieżki od siedziby(S) do miejsca spotkania(X), przy uwzględnieniu,
że przy znalezieniu dwóch dróg o tej samej długości należy wybrać tą, która zawiera mniej miejsc monitorowanych. 
Mapa miasta jest skonstruowana za pomocą grafów. Każdy element grafu posiada w swojej strukturze 4 wskaźniki(góra, dół, prawo, lewo).
Żeby zrozumieć funkcję dodawanie najlepiej pokazać na przykładzie. Na początku ustawiam "początek wiersza" na najnowszy element w wierszu(j==0).
Następnie dodaję nowy element i zapisuję wskaźniki. Na koniec wczytania całego wiersza(po skończeniu najbardziej zagłębionego fora(), ustawiam wskaźnik (wierszwyzej),
żeby wskazywał na początkowy_element w wierszu wyżej.
Po dodaniu całej mapy, należy wykonać przeszukiwanie BFS(Breadth-first search), czyli przeszukiwanie w szerz. Przechodzenie grafu zaczyna się od danego wierzchołk i
należy odwiedzić wszystkich jego sąsiadów. 
*/

#include <iostream>
#include <queue>

using namespace std;

class Punkt
{
public:
    short odleglosc;
    short kamery;
    char znak;

    Punkt *gora, *prawo, *dol, *lewo;
    Punkt(int odl, int kam, char z)
    {
        gora = prawo = dol = lewo = NULL;
        odleglosc=odl;
        kamery=kam;
        znak=z;
    }
};

class Graf
{
public:
    Punkt *start, *poczatek_wiersza, *wskaznik;
    short rozmiarn, rozmiarm, miejsca_monitorowane;

    Graf();
    void dodawanie(short n, short m);
    void BFS();
    void wyswietl();
};

int main()
{
    ios::sync_with_stdio(false);

    short n, m;
    cin >> n >> m;

    Graf graf;
    graf.dodawanie(n,m);
    //graf.wyswietl();
    graf.BFS();

    return 0;
}

Graf::Graf()
{
    start = poczatek_wiersza = wskaznik = NULL;
    rozmiarn = rozmiarm = 0;
}
void Graf::dodawanie(short n, short m)
{
    Punkt *wiersz_wyzej = NULL;
    rozmiarn = n;
    rozmiarm = m;
    for(short i=0; i<n; i++)
    {
        for(short j=0; j<m; j++)
        {
            char znak;
            cin >> znak;

            Punkt *nowy = new Punkt(-1, 0, znak);
            if(znak=='#')
                nowy->odleglosc = -2;
            if(znak=='S')
                start = nowy;

            if(i==0)
            {
                if(j==0)
                {
                    poczatek_wiersza = nowy;
                    wskaznik = poczatek_wiersza;
                }
                else
                {
                    wskaznik->prawo = nowy;
                    nowy->lewo = wskaznik;
                    wskaznik = wskaznik->prawo;
                }
            }
            else
            {
                if(j==0)
                {
                    poczatek_wiersza = nowy;
                    wskaznik = poczatek_wiersza;

                    wskaznik->gora = wiersz_wyzej;
                    wiersz_wyzej->dol = wskaznik;
                    wiersz_wyzej = wiersz_wyzej->prawo;
                }
                else
                {
                    wskaznik->prawo = nowy;
                    nowy->lewo = wskaznik;

                    nowy->gora = wiersz_wyzej;
                    wiersz_wyzej->dol = nowy;

                    wskaznik = wskaznik->prawo;
                    wiersz_wyzej = wiersz_wyzej->prawo;
                }
            }
        }
        wiersz_wyzej = poczatek_wiersza;
    }
}
void Graf::BFS()
{
    queue<Punkt*> kolejka;

    start->odleglosc = 0;

    kolejka.push(start);

    while(kolejka.size()!=0)
    {
        Punkt *temp = kolejka.front();
        kolejka.pop();

        if(temp->znak =='X')
        {
            cout << temp->odleglosc << " " << temp->kamery;
            break;
        }
        else if(temp->znak == 'M')
        {
            temp->kamery++;
        }

        //góra
        if ((temp->gora) && (temp->gora->odleglosc >= -1))
        {
            if(temp->gora->odleglosc == -1)
            {
                Punkt *t = temp->gora;
                t->odleglosc = temp->odleglosc +1;
                t->kamery = temp->kamery;
                kolejka.push(t);
            }
            else
            {
                if((temp->odleglosc+1 == temp->gora->odleglosc) && (temp->kamery < temp->gora->kamery))
                {
                    Punkt *t = temp->gora;
                    t->odleglosc = temp->odleglosc +1;
                    t->kamery = temp->kamery;
                    kolejka.push(t);
                }
            }
        }
        //prawo
        if ((temp->prawo) && (temp->prawo->odleglosc >= -1))
        {
            if(temp->prawo->odleglosc == -1)
            {
                Punkt *t = temp->prawo;
                t->odleglosc = temp->odleglosc +1;
                t->kamery = temp->kamery;
                kolejka.push(t);
            }
            else
            {
                if((temp->odleglosc+1 == temp->prawo->odleglosc) && (temp->kamery < temp->prawo->kamery))
                {
                    Punkt *t = temp->prawo;
                    t->odleglosc = temp->odleglosc +1;
                    t->kamery = temp->kamery;
                    kolejka.push(t);
                }
            }
        }
        //dół
        if ((temp->dol) && (temp->dol->odleglosc >= -1))
        {
            if(temp->dol->odleglosc == -1)
            {
                Punkt *t = temp->dol;
                t->odleglosc = temp->odleglosc +1;
                t->kamery = temp->kamery;
                kolejka.push(t);
            }
            else
            {
                if((temp->odleglosc+1 == temp->dol->odleglosc) && (temp->kamery < temp->dol->kamery))
                {
                    Punkt *t = temp->dol;
                    t->odleglosc = temp->odleglosc +1;
                    t->kamery = temp->kamery;
                    kolejka.push(t);
                }
            }
        }
        //lewo
        if ((temp->lewo) && (temp->lewo->odleglosc >= -1))
        {
            if(temp->lewo->odleglosc == -1)
            {
                Punkt *t = temp->lewo;
                t->odleglosc = temp->odleglosc +1;
                t->kamery = temp->kamery;
                kolejka.push(t);
            }
            else
            {
                if((temp->odleglosc+1 == temp->lewo->odleglosc) && (temp->kamery < temp->lewo->kamery))
                {
                    Punkt *t = temp->lewo;
                    t->odleglosc = temp->odleglosc +1;
                    t->kamery = temp->kamery;
                    kolejka.push(t);
                }
            }
        }
    }
}