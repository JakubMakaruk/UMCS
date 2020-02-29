#include <iostream>

using namespace std;

class Drzewo {
public:
    int *pierwszyPotomek;
    int *rodzenstwo;
    bool *doUmieszczenia;
    int liczbaSkrzyzowan;
    int iloscDrog;

    void przeszukaj(int korzen, int przerwa)
    {
        int pierwszeDziecko = pierwszyPotomek[korzen];
        int kolejny;

        if (przerwa > 2)
        {
            doUmieszczenia[korzen] = true;
            przerwa = 0;
        }
        else if (przerwa == 0)
        {
            przerwa = 1;
        }
        else
        {
            int drogi = 1;

            if (pierwszeDziecko != -1)
            {
                drogi++;

                kolejny = rodzenstwo[pierwszeDziecko];

                while (kolejny != -1)
                {
                    drogi++;
                    kolejny = rodzenstwo[kolejny];
                }
            }

            if (drogi >= iloscDrog)
            {
                doUmieszczenia[korzen] = true;
                przerwa = 0;
            }
            else
            {
                przerwa++;
            }
        }

        if (pierwszeDziecko != -1)
        {
            przeszukaj(pierwszeDziecko, przerwa);
            kolejny = rodzenstwo[pierwszeDziecko];

            while (kolejny != -1)
            {
                przeszukaj(kolejny, przerwa);
                kolejny = rodzenstwo[kolejny];
            }
        }
    }

    void rozwiaz()
    {
        cin >> liczbaSkrzyzowan >> iloscDrog;

        pierwszyPotomek = new int[liczbaSkrzyzowan];
        rodzenstwo = new int[liczbaSkrzyzowan];
        doUmieszczenia = new bool[liczbaSkrzyzowan];

        for (int i = 0; i < liczbaSkrzyzowan; ++i)
        {
            pierwszyPotomek[i] = -1;
            rodzenstwo[i] = -1;
            doUmieszczenia[i] = false;
        }

        for (int i = 1, a, b; i < liczbaSkrzyzowan; ++i)
        {
            cin >> a >> b;
            a--;
            b--;

            if (pierwszyPotomek[a] == -1)
            {
                pierwszyPotomek[a] = b;
            }
            else
            {
                a = pierwszyPotomek[a];

                while (rodzenstwo[a] != -1)
                {
                    a = rodzenstwo[a];
                }

                rodzenstwo[a] = b;
            }
        }

        przeszukaj(0, 3);

        for (int i = 0; i < liczbaSkrzyzowan; ++i)
        {
            if (doUmieszczenia[i])
            {
                cout << (i + 1) << " ";
            }
        }

        delete[] pierwszyPotomek;
        delete[] rodzenstwo;
        delete[] doUmieszczenia;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);

    Drzewo *drzewo = new Drzewo();
    drzewo->rozwiaz();
    delete drzewo;

    return 0;
}