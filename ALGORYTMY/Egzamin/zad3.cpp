#include <iostream>

using namespace std;

struct ElementDrzewa;

struct ElementKolejki
{
    ElementDrzewa* element;
    ElementKolejki* nastepny;
    ElementKolejki* poprzedni;
};

class Kolejka
{
public:
    ElementKolejki* glowa;
    ElementKolejki* ogon;

    Kolejka();
    void dodaj_koniec(ElementDrzewa* element);
    void usun_poczatek();
};

Kolejka::Kolejka()
{
    glowa = new ElementKolejki;
    ogon = new ElementKolejki;
    glowa = nullptr;
    ogon = nullptr;
}

void Kolejka::dodaj_koniec(ElementDrzewa* element)
{
    if((glowa == nullptr) && (ogon == nullptr))
    {
        ElementKolejki* pom = new ElementKolejki;
        pom->element = element;
        pom->nastepny = nullptr;
        pom->poprzedni = nullptr;
        glowa = pom;
        ogon = pom;
        glowa->poprzedni = ogon;
        ogon->nastepny = glowa;
    }
    else
    {
        ElementKolejki* pom = new ElementKolejki;
        pom->element = element;
        pom->nastepny = ogon;
        pom->poprzedni = nullptr;
        ogon->poprzedni = pom;
        ogon = ogon->poprzedni;
    }
}

void Kolejka::usun_poczatek()
{
    if(glowa == ogon)
    {
        ElementKolejki* pom = new ElementKolejki;
        pom = glowa;
        delete pom;
        glowa = nullptr;
        ogon = nullptr;
    }
    else
    {
        ElementKolejki* pom = new ElementKolejki;
        pom = glowa;
        glowa = glowa->poprzedni;
        delete pom;
        glowa->nastepny = nullptr;
    }
}


struct ElementDrzewa
{
    unsigned int wartosc;
    ElementDrzewa* lewySyn;
    ElementDrzewa* prawySyn;
};

class Drzewo
{
public:
    ElementDrzewa* korzen;
    Kolejka* kolej;

    Drzewo(int n);
    void dodaj(ElementDrzewa* nowy);
    void inorder(ElementDrzewa* start);
};

Drzewo::Drzewo(int n)
{
    korzen = new ElementDrzewa;
    korzen->lewySyn = nullptr;
    korzen->prawySyn = nullptr;
    korzen->wartosc = n;

    kolej = new Kolejka();
}

void Drzewo::dodaj(ElementDrzewa* nowy)
{
    ElementDrzewa* pom = new ElementDrzewa;
    pom = kolej->glowa->element;
    if(pom->lewySyn == nullptr)
    {
        pom->lewySyn = nowy;
        kolej->dodaj_koniec(pom->lewySyn);
    }

    else
    {
        pom->prawySyn = nowy;
        kolej->usun_poczatek();
        kolej->dodaj_koniec(pom->prawySyn);
    }
}

void Drzewo::inorder(ElementDrzewa *start)
{
    if(start->lewySyn != nullptr)
    {
        inorder(start->lewySyn);
    }
    cout << start->wartosc << " ";
    if(start->prawySyn != nullptr)
    {
        inorder(start->prawySyn);
    }
}



int main()
{
    unsigned int n;
    cin >> n;

    unsigned int korzeniasty;
    cin >> korzeniasty;
    Drzewo* tree = new Drzewo(korzeniasty);
    tree->kolej->dodaj_koniec(tree->korzen);

    for(unsigned int i=0; i<n-1; i++)
    {
        ElementDrzewa* pom = new ElementDrzewa;
        pom->lewySyn = nullptr;
        pom->prawySyn = nullptr;
        unsigned int wart;
        cin >> wart;
        pom->wartosc = wart;
        tree->dodaj(pom);
    }

    tree->inorder(tree->korzen);

    return 0;
}