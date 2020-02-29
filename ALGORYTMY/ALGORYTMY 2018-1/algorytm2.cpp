#include <iostream>
#include <string>

using namespace std;

typedef struct Tablica
{
    string kod;
    double srednia;
    int odleglosc;
    int miesiac;
};

string wieksze="wieksze";
string rowne="rowne";
string mniejsze="mniejsze";

string sortowanie_miesiac(Tablica a, Tablica b)
{
    if(a.miesiac > b.miesiac)
    {
        return wieksze;
    }
    else if(a.miesiac == b.miesiac)
    {
        return rowne;
    }
    else if(a.miesiac < b.miesiac)
    {
        return mniejsze;
    }
}

string sortowanie_odleglosc(Tablica a, Tablica b)
{
    if(a.odleglosc > b.odleglosc)
    {
        return wieksze;
    }
    else if(a.odleglosc == b.odleglosc)
    {
        return rowne;
    }
    else if(a.odleglosc < b.odleglosc)
    {
        return mniejsze;
    }
}

string sortowanie_srednia(Tablica a, Tablica b)
{
    if(a.srednia > b.srednia)
    {
        return wieksze;
    }
    else if(a.srednia == b.srednia)
    {
        return rowne;
    }
    else if(a.srednia < b.srednia)
    {
        return mniejsze;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    string (*wsk_1)(Tablica a, Tablica b);
    string (*wsk_2)(Tablica a, Tablica b);
    string (*wsk_3)(Tablica a, Tablica b);

    int liczba_par;
    cin >> liczba_par;

    Tablica chlopcy[liczba_par];
    Tablica dziewczyny[liczba_par];
    Tablica pom1, pom2;

    int j;

    char a1, a2, a3;

    cin>>a1>>a2>>a3;

    if(a1=='m' && a2=='s')
    {
        wsk_1=sortowanie_miesiac;
        wsk_2=sortowanie_srednia;
        wsk_3=sortowanie_odleglosc;
    }
    if(a1=='m' && a2=='d')
    {
        wsk_1=sortowanie_miesiac;
        wsk_2=sortowanie_odleglosc;
        wsk_3=sortowanie_srednia;
    }
    if(a1=='s' && a2=='m')
    {
        wsk_1=sortowanie_srednia;
        wsk_2=sortowanie_miesiac;
        wsk_3=sortowanie_odleglosc;
    }
    if(a1=='s' && a2=='d')
    {
        wsk_1=sortowanie_srednia;
        wsk_2=sortowanie_odleglosc;
        wsk_3=sortowanie_miesiac;
    }
    if(a1=='d' && a2=='m')
    {
        wsk_1=sortowanie_odleglosc;
        wsk_2=sortowanie_miesiac;
        wsk_3=sortowanie_srednia;
    }
    if(a1=='d' && a2=='s')
    {
        wsk_1=sortowanie_odleglosc;
        wsk_2=sortowanie_srednia;
        wsk_3=sortowanie_miesiac;
    }

    for(int i=0; i<liczba_par; i++)
    {
        cin>>pom1.kod>>pom1.srednia>>pom1.odleglosc>>pom1.miesiac>>pom2.kod>>pom2.srednia>>pom2.odleglosc>>pom2.miesiac;

        if(i==0)
        {
            chlopcy[0]=pom1;
            dziewczyny[0]=pom2;
        }
        else
        {
            for(j=i-1; j>=0; j--)
            {
                if(wsk_1(pom1, chlopcy[j])== wieksze)
                {
                    if(j==0)
                    {
                        chlopcy[1]=chlopcy[0];
                        chlopcy[0]=pom1;
                    }
                    else
                    {
                        chlopcy[j+1] = chlopcy[j];
                        continue;
                    }
                }
                else if(wsk_1(pom1, chlopcy[j])== rowne)
                {
                    if(wsk_2(pom1, chlopcy[j])== wieksze)
                    {
                        if(j==0)
                        {
                            chlopcy[1]=chlopcy[0];
                            chlopcy[0]=pom1;
                        }
                        else
                        {
                            chlopcy[j+1] = chlopcy[j];
                            continue;
                        }
                    }
                    else if(wsk_2(pom1, chlopcy[j])== rowne)
                    {
                        if(wsk_3(pom1, chlopcy[j])== wieksze)
                        {
                            if(j==0)
                            {
                                chlopcy[1]=chlopcy[0];
                                chlopcy[0]=pom1;
                            }
                            else
                            {
                                chlopcy[j+1] = chlopcy[j];
                                continue;
                            }
                        }
                        else
                        {
                            chlopcy[j+1] = pom1;
                            break;
                        }
                    }
                    else
                    {
                        chlopcy[j+1] = pom1;
                        break;
                    }
                }
                else
                {
                    chlopcy[j+1] = pom1;
                    break;
                }
            }

            for(j=i-1; j>=0; j--)
            {
                if(wsk_1(pom2, dziewczyny[j])== wieksze)
                {
                    if(j==0)
                    {
                        dziewczyny[1]=dziewczyny[0];
                        dziewczyny[0]=pom2;
                    }
                    else
                    {
                        dziewczyny[j+1] = dziewczyny[j];
                        continue;
                    }
                }
                else if(wsk_1(pom2, dziewczyny[j])== rowne)
                {
                    if(wsk_2(pom2, dziewczyny[j])== wieksze)
                    {
                        if(j==0)
                        {
                            dziewczyny[1]=dziewczyny[0];
                            dziewczyny[0]=pom2;
                        }
                        else
                        {
                            dziewczyny[j+1] = dziewczyny[j];
                            continue;
                        }
                    }
                    else if(wsk_2(pom2, dziewczyny[j])== rowne)
                    {
                        if(wsk_3(pom2, dziewczyny[j])== wieksze)
                        {
                            if(j==0)
                            {
                                dziewczyny[1]=dziewczyny[0];
                                dziewczyny[0]=pom2;
                            }
                            else
                            {
                                dziewczyny[j+1] = dziewczyny[j];
                                continue;
                            }
                        }
                        else
                        {
                            dziewczyny[j+1] = pom2;
                            break;
                        }
                    }
                    else
                    {
                        dziewczyny[j+1] = pom2;
                        break;
                    }
                }
                else
                {
                    dziewczyny[j+1] = pom2;
                    break;
                }
            }
        }
    }

    for(int i=0; i<liczba_par; i++)
    {
        cout << chlopcy[i].kod <<" "<< dziewczyny[i].kod << " ";
    }

    return 0;
}