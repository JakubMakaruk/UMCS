#include <iostream>

using namespace std;

long rozmiar, drugi_rozmiar, poczatek, xtemp, ytemp;
string stemp;

class ElementListy
{
public:
    string slowo;
    long wartosc;
    ElementListy *poprzedni=NULL, *nastepny=NULL;
    ElementListy(string s, long x)
    {
        slowo = s;
        wartosc = x;
    }
};

class Lista // dwukierunkowa lista cykliczna
{
public:
    ElementListy *wskaznik, *wskDodajnik;
    long licznik;
    bool czyPierwszyRazZero;

    Lista();
    bool czyPusta();
    void dodajKoniec(string s, long x);
    void dodajPrzedWskaznik(string s, long x);
    void usunWskaznik();
    long obliczObroty();
    long obliczObrotyDlaZera();
    void przesunWskaznik(long zakres);
};

int main()
{
    ios::sync_with_stdio(false);

    Lista lista;

    cin >> rozmiar >> poczatek;
    for(long i=0; i<rozmiar; i++)
    {
        cin >> stemp >> xtemp;
        lista.dodajKoniec(stemp, xtemp);
    }

    lista.wskDodajnik = NULL;

    string result;
    while(!lista.czyPusta())
    {
        result="";
        while(lista.wskaznik->wartosc==0)
        {
            if(lista.czyPierwszyRazZero==false)
            {
                lista.czyPierwszyRazZero = true;
                cin >> drugi_rozmiar;
            }
            cin >> stemp >> xtemp >> ytemp;
            lista.dodajPrzedWskaznik(stemp, xtemp);
            lista.wskaznik->wartosc = ytemp;
            if(ytemp != 0)
            {
                long obr = lista.obliczObrotyDlaZera();
                lista.przesunWskaznik(obr);
            }
        }
        result = lista.wskaznik->slowo;
        lista.usunWskaznik();
        cout << result << " ";
        if(lista.licznik>=1)
        {
            long obroty = lista.obliczObroty();
            lista.przesunWskaznik(obroty);
        }
        else
        {
            break;
        }
    }
    return 0;
}

Lista::Lista()
{
    wskaznik = NULL;
    wskDodajnik = NULL;
    licznik = 0;
    czyPierwszyRazZero = false;
}
bool Lista::czyPusta()
{
    return licznik==0;
}
void Lista::dodajKoniec(string s, long x)
{
    ElementListy *temp = new ElementListy(s, x);
    if(licznik==0)
    {
        temp->nastepny = temp;
        temp->poprzedni = temp;
        wskDodajnik = temp;
    }
    else
    {
        ElementListy *pop = wskDodajnik->poprzedni;
        ElementListy *nast = wskDodajnik->nastepny;
        wskDodajnik->nastepny = temp;
        temp->poprzedni = wskDodajnik;
        temp->nastepny = nast;
        nast->poprzedni = temp;
        if(licznik==1)
            wskDodajnik->poprzedni = temp;
        wskDodajnik = wskDodajnik->nastepny;
    }
    if(licznik==poczatek)
        wskaznik = wskDodajnik;
    licznik++;
}
void Lista::dodajPrzedWskaznik(string s, long x)
{
    ElementListy *temp = new ElementListy(s, x);
    ElementListy *pop = wskaznik->poprzedni;
    ElementListy *nast = wskaznik->nastepny;
    wskaznik->poprzedni = temp;
    temp->nastepny = wskaznik;
    temp->poprzedni = pop;
    pop->nastepny = temp;
    if(licznik==1)
        wskaznik->poprzedni = temp;
    licznik++;
}
void Lista::usunWskaznik()
{
    if(licznik==1)
    {
        wskaznik = wskDodajnik = NULL;
    }
    else if(licznik==2)
    {
        wskaznik->poprzedni->nastepny = wskaznik->nastepny;
        wskaznik->nastepny->poprzedni = wskaznik->poprzedni;
    }
    else
    {
        wskaznik->poprzedni->nastepny = wskaznik->nastepny;
        wskaznik->nastepny->poprzedni = wskaznik->poprzedni;
    }
    licznik--;
}
long Lista::obliczObroty()
{
    if(licznik>0)
    {
        long x, zakres;
        x = wskaznik->wartosc;

        if(x>0 && x>licznik)
        {
            zakres = x%licznik;
        }
        else if(x<0 && x*(-1)>licznik)
        {
            zakres = x%licznik;
        }
        else
        {
            zakres = x;
        }

        if(licznik==1)
            zakres = 1;
        else if(x>0 && zakres%licznik==0)
            zakres = -1;
        else if(x<0 && zakres%licznik==0)
            zakres = 1;
        else if(x>0 && zakres>licznik/2)
        {
            zakres = zakres - (licznik+1);
        }
        else if(x<0 && zakres*(-1)>licznik/2)
        {
            zakres = zakres + (licznik+1);
        }

        return zakres;
    }
}
long Lista::obliczObrotyDlaZera()
{
    if(licznik>0)
    {
        long x, zakres;
        x = wskaznik->wartosc;

        if(x>0 && x>licznik)
        {
            zakres = x%licznik;
        }
        else if(x<0 && x*(-1)>licznik)
        {
            zakres = x%licznik;
        }
        else
        {
            zakres = x;
        }

        if(licznik==1)
            zakres = 1;
        else if(x>0 && zakres>licznik/2)
        {
            zakres = zakres - licznik;
        }
        else if(x<0 && zakres*(-1)>licznik/2)
        {
            zakres = zakres + licznik;
        }

        return zakres;
    }
}
void Lista::przesunWskaznik(long zakres)
{
    if(zakres>0)
    {
        for(long i=0; i<zakres; i++)
            wskaznik = wskaznik->nastepny;
    }
    else
    {
        for(long i=0; i>zakres; i--)
            wskaznik = wskaznik->poprzedni;
    }
}