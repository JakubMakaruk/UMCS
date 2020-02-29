/*
Zadanie polega na najlepszym wyborze grup osób współpracujących ze sobą. Tworzymy okrągły stół i usadzamy poszczególne osoby. Osoby nie mogą zmieniać miejsc.
Z racji tego, że liczba osób jest zawsze parzysta, dzielimy stół na pół, a następnie sprawdzamy wynik. Odpowiedzią mogą być dwie grupy, w których różnica punktów IQ
pomiędzy najzdolniejszą i najmniej zdolną osobą nie wynosi V(różnica | max-min>=roznica). Jeżeli znajdziemy taki podział grup to z głównego fora zapamiętujemy liczbę "i" oznaczającą
ile razy dzieliliśmy stół na pół(zmieniliśmy kąt głównej kreski-podziału stołu). Głównym forem przechodzimy cały stół, a możliwości na to jest n/2. Jeżeli znajdziemy kolejny
podział to sprawdzamy czy różnica średnich między obiema grupami jest mniejsza od wcześniej znalezionego podziału grup. Jeżeli tak to ustawiamy licznik_przejść = i.
Po zakończeniu głównego fora, przechodzimy do drugiego fora, w którym odbywa się uporządkowanie kolejek, tzn. usunięcie głowy z kolejki_1 i dodanie na koniec kolejki_2 
oraz usunięcie głowy z kolejki_2 i dodanie na koniec kolejki_1. W ten sposób otrzymamy idealne kolejki wynikowe w kierunku zgodnym z kierunkiem wprowadzania danych.
Jeżeli nie uda nam się znaleźć żadnego podziału spełniającego warunek, wtedy wyświetlamy "NIE".
*/

#include <iostream>

using namespace std;

class ElementKolejki
{
public:
    string imie, nazwisko;
    long punkty_zdolnosci;
    ElementKolejki* nastepny = NULL;
    ElementKolejki* poprzedni = NULL;
    ElementKolejki(string i, string n, long p)
    {
        imie = i;
        nazwisko = n;
        punkty_zdolnosci = p;
    }
};

class Kolejka
{
public:
    ElementKolejki *glowa, *ogon, *wskaznik;
    long licznik, suma;
    ElementKolejki *max, *min;

    Kolejka();
    void dodajKoniec(string i, string n, long p);
    void usunPoczatek();
    void usunKoniec();
    void usunWskaznik();
    void wyswietl();
    void wyszukajMax();
    void wyszukajMin();
};

int main()
{
    Kolejka kolejka_slabszych, kolejka_lepszych;

    long rozmiar, roznica;
    cin >> rozmiar >> roznica;

    string simie, snazwisko;
    long iwartosc;

    for(long i=0; i<rozmiar; i++)
    {
        cin >> simie >> snazwisko >> iwartosc;
        if(i<rozmiar/2)
        {
            kolejka_slabszych.dodajKoniec(simie, snazwisko, iwartosc);
            kolejka_slabszych.suma += iwartosc;
        }
        else
        {
            kolejka_lepszych.dodajKoniec(simie, snazwisko, iwartosc);
            kolejka_lepszych.suma += iwartosc;
        }
    }

    bool czy_wynik=false;
    long licznik_przejsc=0;
    long najlepsza_roznica=999999;
    
    for(long i=0; i<rozmiar/2; i++)
    {
        if(kolejka_slabszych.max->punkty_zdolnosci-kolejka_slabszych.min->punkty_zdolnosci <= roznica && kolejka_lepszych.max->punkty_zdolnosci-kolejka_lepszych.min->punkty_zdolnosci <= roznica)
        {
            long nowa_roznica = kolejka_lepszych.suma-kolejka_slabszych.suma;
            if(nowa_roznica<0)
                nowa_roznica=nowa_roznica*(-1);

            if(najlepsza_roznica==999999)
            {
                najlepsza_roznica = nowa_roznica;
                licznik_przejsc=i;
            }
            else if(nowa_roznica < najlepsza_roznica)
            {
                najlepsza_roznica = nowa_roznica;
                licznik_przejsc=i;
            }
            czy_wynik=true;
        }

        kolejka_slabszych.dodajKoniec(kolejka_lepszych.wskaznik->imie, kolejka_lepszych.wskaznik->nazwisko, kolejka_lepszych.wskaznik->punkty_zdolnosci);
        kolejka_lepszych.dodajKoniec(kolejka_slabszych.wskaznik->imie, kolejka_slabszych.wskaznik->nazwisko, kolejka_slabszych.wskaznik->punkty_zdolnosci);

        kolejka_slabszych.suma = kolejka_slabszych.suma - kolejka_slabszych.wskaznik->punkty_zdolnosci + kolejka_lepszych.wskaznik->punkty_zdolnosci;
        kolejka_lepszych.suma = kolejka_lepszych.suma - kolejka_lepszych.wskaznik->punkty_zdolnosci + kolejka_slabszych.wskaznik->punkty_zdolnosci;

        if(kolejka_slabszych.wskaznik == kolejka_slabszych.max)
        {
            kolejka_slabszych.usunWskaznik();
            kolejka_slabszych.wyszukajMax();
        }
        else if(kolejka_slabszych.wskaznik == kolejka_slabszych.min)
        {
            kolejka_slabszych.usunWskaznik();
            kolejka_slabszych.wyszukajMin();
        }
        else
        {
            kolejka_slabszych.usunWskaznik();
        }
        
        if(kolejka_lepszych.wskaznik == kolejka_lepszych.max)
        {
            kolejka_lepszych.usunWskaznik();
            kolejka_lepszych.wyszukajMax();
        }
        else if(kolejka_lepszych.wskaznik == kolejka_lepszych.min)
        {
            kolejka_lepszych.usunWskaznik();
            kolejka_lepszych.wyszukajMin();
        }
        else
        {
            kolejka_lepszych.usunWskaznik();
        }
    }

    kolejka_slabszych.wskaznik = kolejka_slabszych.glowa;
    kolejka_lepszych.wskaznik = kolejka_lepszych.glowa;

    for(long i=0; i<licznik_przejsc; i++)
    {
        kolejka_slabszych.dodajKoniec(kolejka_lepszych.wskaznik->imie, kolejka_lepszych.wskaznik->nazwisko, kolejka_lepszych.wskaznik->punkty_zdolnosci);
        kolejka_lepszych.dodajKoniec(kolejka_slabszych.wskaznik->imie, kolejka_slabszych.wskaznik->nazwisko, kolejka_slabszych.wskaznik->punkty_zdolnosci);

        kolejka_slabszych.suma = kolejka_slabszych.suma - kolejka_slabszych.wskaznik->punkty_zdolnosci + kolejka_lepszych.wskaznik->punkty_zdolnosci;
        kolejka_lepszych.suma = kolejka_lepszych.suma - kolejka_lepszych.wskaznik->punkty_zdolnosci + kolejka_slabszych.wskaznik->punkty_zdolnosci;

        kolejka_slabszych.usunWskaznik();
        kolejka_lepszych.usunWskaznik();
    }

    if(czy_wynik==true)
    {
        kolejka_lepszych.wyswietl();
        cout << "\n";
        kolejka_slabszych.wyswietl();
    }
    else
        cout << "NIE";

    return 0;
}


Kolejka::Kolejka()
{
    glowa = NULL;
    ogon = NULL;
    wskaznik = NULL;
    max = NULL;
    min = NULL;
    licznik = 0;
    suma = 0;
}
void Kolejka::dodajKoniec(string i, string n, long p)
{
    ElementKolejki* temp = new ElementKolejki(i, n, p);

    if(licznik==0)
    {
        glowa = temp;
        ogon = temp;
        wskaznik = glowa;
        max = temp;
        min = temp;
    }
    else
    {
        ogon->nastepny = temp;
        temp->poprzedni = ogon;
        ogon = temp;

        if(p>=max->punkty_zdolnosci)
            max = temp;
        if(p<=min->punkty_zdolnosci)
            min = temp; 
    }
    licznik++;
}
void Kolejka::usunPoczatek()
{
    if(licznik>0)
    {
        ElementKolejki *temp = glowa;
        glowa = glowa->nastepny;
        delete temp;
        licznik--;
    }
}
void Kolejka::usunKoniec()
{
    if(licznik>0)
    {
        ElementKolejki *temp = ogon;
        ogon->poprzedni->nastepny = NULL;
        ogon = ogon->poprzedni;
        delete temp;
        licznik--;
    }
}
void Kolejka::usunWskaznik()
{
    if(licznik>0)
    {
        if(wskaznik==glowa)
        {
            usunPoczatek();
            wskaznik = glowa;
        }
        else if(wskaznik==ogon)
        {
            usunKoniec();
            wskaznik = glowa;
        }
        else
        {
            ElementKolejki *temp = wskaznik;
            temp->poprzedni->nastepny = temp->nastepny;
            temp->nastepny->poprzedni = temp->poprzedni;
            wskaznik = wskaznik->nastepny;
            delete temp;
            licznik--;
        }
    }
}
void Kolejka::wyswietl()
{
    if(licznik>0)
    {
        ElementKolejki *temp = glowa;
        while(temp!=NULL)
        {
            cout << temp->imie << " " << temp->nazwisko << "\n";
            if(temp->nastepny!=NULL)
                temp = temp->nastepny;
            else
                break;
        }
    }
}
void Kolejka::wyszukajMax()
{
    ElementKolejki *temp = glowa;

    max = temp;
    for(long i=0; i<licznik; i++)
    {
        if(temp->punkty_zdolnosci > max->punkty_zdolnosci)
            max = temp;
        temp = temp->nastepny;
    }
}
void Kolejka::wyszukajMin()
{
    ElementKolejki *temp = glowa;

    min = temp;
    for(long i=0; i<licznik; i++)
    {
        if(temp->punkty_zdolnosci < min->punkty_zdolnosci)
            min = temp;
        temp = temp->nastepny;
    }
}