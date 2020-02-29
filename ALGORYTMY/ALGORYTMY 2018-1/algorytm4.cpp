#include <iostream>
#include <string>

using namespace std;


template <typename T>
class Stos
{
public:
    struct ElementStosu
    {
        T znak;
        ElementStosu* poprzedni;
    };

    ElementStosu *wierzcholek;

    Stos()
    {
        wierzcholek = NULL;
    }
    ~Stos()
    {
        while(wierzcholek!=NULL)
            usun();
    }
    void dodaj(T wartosc)
    {
        ElementStosu* pom = new ElementStosu;
        pom->znak = wartosc;
        pom->poprzedni = wierzcholek;
        wierzcholek = pom;
    }
    T usun()
    {
        if(wierzcholek!=NULL)
        {
            T pomocniczy_znak;
            ElementStosu* pom = wierzcholek;
            wierzcholek = wierzcholek->poprzedni;
            pomocniczy_znak = pom->znak;

            delete pom;
            return pomocniczy_znak;
        }
        return 0;
    }
    bool czy_pusty()
    {
        return !wierzcholek;
    }
};

class Kolejka
{
public:
    struct ElementKolejki
    {
        char wyraz;
        ElementKolejki* nastepny;
        bool nastepnaLiczba = false;
    };

    ElementKolejki* pierwszy = new ElementKolejki;
    ElementKolejki* ostatni = new ElementKolejki;
    ElementKolejki* pomocniczy = new ElementKolejki;

    Kolejka()
    {
        pierwszy = NULL;
        ostatni = NULL;
        pomocniczy = NULL;
    }
    ~Kolejka()
    {
        while(pierwszy!=NULL)
            usun();
    }
    void dodaj(char wartosc, bool czy)
    {
        ElementKolejki* pom = new ElementKolejki;
        pom->nastepny = NULL;
        pom->wyraz = wartosc;
        pom->nastepnaLiczba = czy;

        if(!pierwszy)
        {
            pierwszy = pom;
            ostatni = pom;
        }
        else
        {
            ostatni->nastepny = pom;
            ostatni = pom;
            ostatni->nastepny = NULL;
        }
    }
    char usun()
    {
        if(pierwszy!=NULL)
        {
            char pomocnicza;
            ElementKolejki *pom = pierwszy;
            pomocnicza = pom->wyraz;
            pierwszy = pierwszy->nastepny;
            if(pierwszy==NULL)
                ostatni=NULL;
            delete pom;
            return pomocnicza;
        }
        return 0;
    }
    bool czy_pusty()
    {
        return !pierwszy;
    }
};

int priorytet_operatora(char op)
{
    if(op=='+' || op=='-')
        return 1;
    else if(op=='*' || op=='/')
        return 2;
    return 0;
}

int main()
{

    ios_base::sync_with_stdio(false);

    unsigned int liczba_wyrazen;
    cin >> liczba_wyrazen;

    string wyrazenie;

    Stos<char> stos;
    Stos<long double> stosLDOUBLE;
    Kolejka kolejka;

    int jesliBladNawias=0;

    for(unsigned int i=0; i<liczba_wyrazen; i++)
    {
        cin >> wyrazenie;

        int licznik_nawiasow=0;
        for(unsigned int i=0; i<wyrazenie.length(); i++)
        {
            if(wyrazenie[i]=='{' || wyrazenie[i]=='[' || wyrazenie[i]=='(' || wyrazenie[i]==')' || wyrazenie[i]==']' || wyrazenie[i]=='}')
                licznik_nawiasow++;
        }

        if(licznik_nawiasow%2==0)
        {
            for(unsigned int i=0; i<wyrazenie.length(); i++)
            {
                if(jesliBladNawias==1)
                {
                    jesliBladNawias++;
                    break;
                }
                if(wyrazenie[i]>=48 && wyrazenie[i]<=57)
                {

                    while(wyrazenie[i+1]>=48 && wyrazenie[i+1]<=57)
                    {
                        kolejka.dodaj(wyrazenie[i],true);
                        i++;
                        if(i==wyrazenie.length())
                        {
                            break;
                        }
                    }
                    kolejka.dodaj(wyrazenie[i], false);
                }
                else if(wyrazenie[i]=='(' || wyrazenie[i]=='[' || wyrazenie[i]=='{')
                {
                    stos.dodaj(wyrazenie[i]);
                }
                else if(wyrazenie[i]==')')
                {
                    if(stos.czy_pusty() == false)
                    {
                        char pom = stos.wierzcholek->znak;
                        while(pom!='(')
                        {
                            if(pom == '[' || pom == '{')
                            {
                                cout << "BLAD" << endl;
                                jesliBladNawias++;
                                break;
                            }
                            else
                            {
                                pom = stos.usun();
                                kolejka.dodaj(pom, false);
                                pom = stos.wierzcholek->znak;
                            }
                        }
                        if(pom=='(')
                        {
                            pom=stos.usun();
                        }
                    }
                    else
                    {
                        cout << "BLAD" << endl;
                        jesliBladNawias++;
                        break;
                    }
                }
                else if(wyrazenie[i]==']')
                {
                    if(stos.czy_pusty() == false)
                    {
                        char pom = stos.wierzcholek->znak;
                        while(pom!='[')
                        {
                            if(pom == '(' || pom == '{')
                            {
                                cout << "BLAD" << endl;
                                jesliBladNawias++;
                                break;
                            }
                            else
                            {
                                pom = stos.usun();
                                kolejka.dodaj(pom, false);
                                pom = stos.wierzcholek->znak;
                            }
                        }
                        if(pom=='[')
                        {
                            pom=stos.usun();
                        }
                    }
                    else
                    {
                        cout << "BLAD" << endl;
                        jesliBladNawias++;
                        break;
                    }
                }
                else if(wyrazenie[i]=='}')
                {
                    if(stos.czy_pusty() == false)
                    {
                        char pom = stos.wierzcholek->znak;
                        while(pom!='{')
                        {
                            if(pom == '(' || pom == '[')
                            {
                                cout << "BLAD" << endl;
                                jesliBladNawias++;
                                break;
                            }
                            else
                            {
                                pom = stos.usun();
                                kolejka.dodaj(pom, false);
                                pom = stos.wierzcholek->znak;
                            }
                        }
                        if(pom=='{')
                        {
                            pom=stos.usun();
                        }
                    }
                    else
                    {
                        cout << "BLAD" << endl;
                        jesliBladNawias++;
                        break;
                    }
                }
                else if(wyrazenie[i]=='+' || wyrazenie[i]=='-' || wyrazenie[i]=='*' || wyrazenie[i]=='/')
                {
                    int priorytet = priorytet_operatora(wyrazenie[i]);
                    if(stos.czy_pusty() == false)
                    {
                        while(!(stos.czy_pusty()) && priorytet_operatora(stos.wierzcholek->znak)>=priorytet)
                        {
                            char pom;
                            pom = stos.usun();
                            kolejka.dodaj(pom, false);
                        }
                        stos.dodaj(wyrazenie[i]);
                    }
                    else
                    {
                        stos.dodaj(wyrazenie[i]);
                    }
                }
            }


            if(jesliBladNawias!=1 && jesliBladNawias!=2)
            {
                while(stos.czy_pusty() == false)
                {
                    char pom;
                    pom = stos.wierzcholek->znak;
                    if(pom=='(' || pom=='[' || pom=='{')
                    {
                        cout << "BLAD" << endl;
                        jesliBladNawias++;
                        break;
                    }
                    else
                    {
                        pom = stos.usun();
                        kolejka.dodaj(pom, false);
                    }
                }

                if(jesliBladNawias==0)
                {
                    kolejka.pomocniczy=kolejka.pierwszy;
                    while(kolejka.pomocniczy!=NULL)
                    {
                        if((kolejka.pomocniczy->wyraz)>=48 && (kolejka.pomocniczy->wyraz)<=57)
                        {
                            if(kolejka.pomocniczy->nastepnaLiczba == true)
                            {
                                long double wynik=0;
                                long double zmienna=0;
                                while(kolejka.pomocniczy->nastepnaLiczba == true)
                                {
                                    zmienna=kolejka.pomocniczy->wyraz-'0';
                                    wynik = wynik*10+zmienna;
                                    kolejka.pomocniczy = kolejka.pomocniczy->nastepny;
                                }
                                zmienna=kolejka.pomocniczy->wyraz-'0';
                                wynik = wynik*10+zmienna;
                                stosLDOUBLE.dodaj(wynik);
                                kolejka.pomocniczy = kolejka.pomocniczy->nastepny;
                                continue;
                            }
                            else
                            {
                                long double pomocnicza;
                                pomocnicza = kolejka.pomocniczy->wyraz-'0';
                                stosLDOUBLE.dodaj(pomocnicza);
                            }
                        }
                        else if(kolejka.pomocniczy->wyraz=='+')
                        {
                            long double pomocnicza1, pomocnicza2, wynik;
                            pomocnicza1=stosLDOUBLE.usun();
                            pomocnicza2=stosLDOUBLE.usun();
                            wynik=pomocnicza2+pomocnicza1;
                            stosLDOUBLE.dodaj(wynik);
                        }
                        else if(kolejka.pomocniczy->wyraz=='-')
                        {
                            long double pomocnicza1, pomocnicza2, wynik;
                            pomocnicza1=stosLDOUBLE.usun();
                            pomocnicza2=stosLDOUBLE.usun();
                            wynik=pomocnicza2-pomocnicza1;
                            stosLDOUBLE.dodaj(wynik);
                        }
                        else if(kolejka.pomocniczy->wyraz=='*')
                        {
                            long double pomocnicza1, pomocnicza2, wynik;
                            pomocnicza1=stosLDOUBLE.usun();
                            pomocnicza2=stosLDOUBLE.usun();
                            wynik=pomocnicza2*pomocnicza1;
                            stosLDOUBLE.dodaj(wynik);
                        }
                        else if(kolejka.pomocniczy->wyraz=='/')
                        {
                            long double pomocnicza1, pomocnicza2, wynik;
                            pomocnicza1=stosLDOUBLE.usun();
                            pomocnicza2=stosLDOUBLE.usun();
                            if(pomocnicza1==0)
                            {
                                cout << "BLAD" << endl;
                                jesliBladNawias++;
                                break;
                            }
                            wynik=pomocnicza2/pomocnicza1;
                            stosLDOUBLE.dodaj(wynik);
                        }
                        kolejka.pomocniczy=kolejka.pomocniczy->nastepny;
                    }
                }
            }

            if(jesliBladNawias!=2 && jesliBladNawias!=1)
            {
                cout << stosLDOUBLE.usun() << endl;
            }

            while(kolejka.czy_pusty() == false)
            {
                kolejka.usun();
            }
            while(stos.czy_pusty() == false)
            {
                stos.usun();
            }

            jesliBladNawias=0;
        }
        else
        {
            cout << "BLAD" << endl;
        }
    }

    return 0;
}