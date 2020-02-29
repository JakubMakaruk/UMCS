#include <iostream>
#include <queue>
#include <list>

using namespace std;

int liczbaRozwiazan=0;
int dlugoscSwiatelek;

struct Element
{
    int wartosc;
    Element *lewySyn;
    Element *prawySyn;
    int pozycja;
};

class Drzewo
{
public:
    Element* korzen;

    Drzewo()
    {
        korzen = new Element;
        korzen->wartosc = 0;
        korzen->lewySyn = NULL;
        korzen->prawySyn = NULL;
        korzen->pozycja = 0;
    }

    Element* stworzElement(int liczba, int pozycja)
    {
        Element *pom = new Element;
        pom->wartosc = liczba;
        pom->lewySyn = NULL;
        pom->prawySyn = NULL;
        pom->pozycja = pozycja;
        return pom;
    }

    void dodaj_element(int liczba, int pozycja, queue<Element*> &kolejka)
    {
        Element* pomKorzen = kolejka.front();
        if(pomKorzen->lewySyn == NULL)
        {
            pomKorzen->lewySyn = stworzElement(liczba, pozycja);
            kolejka.push(pomKorzen->lewySyn);
        }
        else
        {
            pomKorzen->prawySyn = stworzElement(liczba, pozycja);
            kolejka.push(pomKorzen->prawySyn);
            kolejka.pop();
        }
    }

    void postorder(Element *pomKorzen, list<int> &glownaLista)
    {
        list<int> listaLewychSynow;
        list<int> listaPrawychSynow;

        if(pomKorzen->lewySyn != NULL)
        {
            postorder(pomKorzen->lewySyn, listaLewychSynow);
        }
        if(pomKorzen->prawySyn != NULL)
        {
            postorder(pomKorzen->prawySyn, listaPrawychSynow);
        }

        if(pomKorzen->pozycja == 0)
        {
            for(list<int>::iterator iL = listaLewychSynow.begin(); iL != listaLewychSynow.end(); iL++)
            {
                for(list<int>::iterator iP = listaPrawychSynow.begin(); iP != listaPrawychSynow.end(); iP++)
                {
                    if((*iL)+(*iP) == dlugoscSwiatelek)
                    {
                        liczbaRozwiazan++;
                    }
                }
            }
            return;
        }


        if(pomKorzen->wartosc == dlugoscSwiatelek)
        {
            liczbaRozwiazan++;
        }
        if(pomKorzen->wartosc < dlugoscSwiatelek)
        {
            glownaLista.push_back(pomKorzen->wartosc);
        }

        if(!listaLewychSynow.empty() || !listaPrawychSynow.empty())
        {
            for(list<int>::iterator iL = listaLewychSynow.begin(); iL != listaLewychSynow.end(); iL++)
            {
                for(list<int>::iterator iP = listaPrawychSynow.begin(); iP != listaPrawychSynow.end(); iP++)
                {
                    if((*iL)+(*iP) == dlugoscSwiatelek)
                    {
                        liczbaRozwiazan++;
                    }
                }
            }
            if(!listaLewychSynow.empty())
            {

                for(list<int>::iterator lewy = listaLewychSynow.begin(); lewy != listaLewychSynow.end(); lewy++)
                {
                    int sumaL = pomKorzen->wartosc + (*lewy);
                    if(sumaL == dlugoscSwiatelek)
                    {
                        liczbaRozwiazan++;
                    }
                    else if(sumaL < dlugoscSwiatelek)
                    {
                        glownaLista.push_back(sumaL);
                    }
                }

            }
            if(!listaPrawychSynow.empty())
            {
                for(list<int>::iterator prawy = listaPrawychSynow.begin(); prawy != listaPrawychSynow.end(); prawy++)
                {
                    int sumaP = pomKorzen->wartosc + (*prawy);
                    if(sumaP == dlugoscSwiatelek)
                    {
                        liczbaRozwiazan++;
                    }
                    else if(sumaP < dlugoscSwiatelek)
                    {
                        glownaLista.push_back(sumaP);
                    }
                }

            }
        }
        delete pomKorzen;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);

    int liczbaTestow;
    cin >> liczbaTestow;
    list<int> lista;
    for(int i=0; i<liczbaTestow; i++)
    {
        liczbaRozwiazan=0;
        int liczbaGalezi;
        Drzewo *drzewo = new Drzewo();

        queue<Element*> kolejka;
        kolejka.push(drzewo->korzen);
        cin >> liczbaGalezi >> dlugoscSwiatelek;
        for(int i=0; i<liczbaGalezi; i++)
        {
            int liczba;
            cin >> liczba;
            drzewo->dodaj_element(liczba, i+1, kolejka);
        }

        drzewo->postorder(drzewo->korzen, lista);
        cout << liczbaRozwiazan << endl;

        delete drzewo;
    }

    return 0;
}