/*
W tym zadaniu musimy utworzyć drzewo składające się z liczb(wpisów). Najlepszym wyborem będzie drzewo lewy-syn prawy-brat(left-child, right-sibbling).
Drzewo zaimplementowane przy pomocy listy sąsiadów przekraczało pamięć, dość logiczne(ostatnie elementy niepotrzebnie miały zaimplementowane listy, ale nie tylko to).
Najpierw dodajemy korzen=0 do drzewa. Następnie przy dodawaniu elementu sprawdzamy czy istnieje lewy_syn oraz czy lewy_syn==wczytywana wartość. Jeżeli nie
to przechodzimy do prawego brata. Jeżeli prawy_brat==NULL, to dodajemy wczytywaną wartość do prawego_brata. Jeśli by tak nie było to przechodzimy dalej do prawego brata,
aż na danym poziomie sprawdzimy czy wczytywana wartość jest już w drzewie. Jeżeli wartości nie udaje się znaleźć to dodajemy ją. Jednocześnie zapamiętujemy ojca danego
elementu.
Na koniec drzewo to wyświetlamy w kolejności preorder, tj. przechodzimy do lewego_syna - wyświetlamy aż lewy_syn!=NULL, następnie przechodzimy do prawego_syna i to samo.
Zapuszczamy się rekurencją do if(lewy_syn!=NULL). 
*/

#include <iostream>

using namespace std;

class ElementDrzewa;

ElementDrzewa *poprzedni = NULL;
class ElementDrzewa
{
public:
    int liczba;
    ElementDrzewa *l_syn, *p_brat;
    ElementDrzewa(int l)
    {
        liczba = l;
        l_syn = NULL;
        p_brat = NULL;
    }
};

class Drzewo
{
public:
    ElementDrzewa *korzen;
    Drzewo();
    void dodaj(int ile);
    ElementDrzewa* znajdzElement(ElementDrzewa *lsyn,int szukana);
    void preorder(ElementDrzewa *wskaznik);
};


int main()
{
    ios_base::sync_with_stdio(false);

    int liczba_wpisow;
    cin >> liczba_wpisow;

    Drzewo *drzewo = new Drzewo();

    for(int i = 0; i<liczba_wpisow;++i)
    {
        int ile;
        cin >> ile;
        drzewo->dodaj(ile);
    }
    drzewo->preorder(drzewo->korzen);

    return 0;
}


Drzewo::Drzewo()
{
    korzen = new ElementDrzewa(0);
}
void Drzewo::dodaj(int ile)
{
    ElementDrzewa *temp1 = korzen;
    int x;
    for(int i=0; i<ile; i++)
    {
        cin >> x;
        if(temp1->l_syn == NULL)
        {
            ElementDrzewa *nowy = new ElementDrzewa(x);
            temp1->l_syn = nowy;
            temp1 = nowy;
            continue;
        }
        else
        {
            ElementDrzewa *temp2 = znajdzElement(temp1->l_syn, x);
            if(temp2==NULL)
            {
                ElementDrzewa *nowy = new ElementDrzewa(x);
                poprzedni->p_brat = nowy;
                temp1 = nowy;
            }
            else
            {
                temp1 = temp2;
            }
        }
    }
}
ElementDrzewa* Drzewo::znajdzElement(ElementDrzewa *lsyn, int szukana)
{
    if(lsyn == NULL)
        return NULL;
    if(lsyn->liczba == szukana)
    {
        poprzedni = lsyn;
        return lsyn;
    }
    else{
        while(lsyn!=NULL)
        {
            if(lsyn->liczba == szukana)
                return lsyn;
            else
            {
                poprzedni = lsyn;
                lsyn = lsyn->p_brat;
            }
        }
    }
    return NULL;
}
void Drzewo::preorder(ElementDrzewa *wskaznik)
{
    if(wskaznik!=korzen)
        cout<<wskaznik->liczba<<" ";
    if(wskaznik->l_syn!=NULL)
    {
        preorder(wskaznik->l_syn);
    }
    if(wskaznik->p_brat!=NULL)
    {
        preorder(wskaznik->p_brat);
    }
}