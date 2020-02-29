#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int liczba_zestawow;
    cin >> liczba_zestawow;

    long int liczba_tropow, liczba_metod;
    int x, y;

    int najwieksza_roznica;
    int najwiekszeX;
    int najmniejszeY;
    int roznica;
    for(int i=0; i<liczba_zestawow; i++)
    {
        najwieksza_roznica = najwiekszeX = najmniejszeY = roznica = 0;
        cin >>liczba_tropow >> liczba_metod;
        for(long int j=0; j<liczba_metod; j++)
        {
            cin >> x >> y;
            roznica = x-y;
            if(roznica > najwieksza_roznica)
            {
                najwieksza_roznica = roznica;
            }
            if(x > najwiekszeX)
            {
                najwiekszeX=x;
            }
            if(y < najmniejszeY)
            {
                najmniejszeY=y;
            }
        }
        if(najwiekszeX >= liczba_tropow || ((liczba_tropow+najmniejszeY) <= 0)) 
        {
            cout << 1 << "\n";
        }
        else if(najwieksza_roznica <= 0)
        {
            cout << "BRAK METOD\n";
        }
        else
        {
            int czyReszta = ((liczba_tropow-najwiekszeX)%najwieksza_roznica != 0);
            cout << (liczba_tropow-najwiekszeX)/najwieksza_roznica + czyReszta + 1 << "\n";
        }
    }
    return 0;
}