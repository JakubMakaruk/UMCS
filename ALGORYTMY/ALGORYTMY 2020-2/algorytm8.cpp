#include <iostream>

using namespace std;

int T=18;//14;

struct Node
{
    double wartosc;
    string pseudonim;
};

class BTreeNode
{
public:
    Node *klucze;
    BTreeNode **dzieci;
    int rozmiar;
    bool lisc;

    BTreeNode() { rozmiar = 0;
                  klucze = new Node[2*T-1];
                            dzieci = new BTreeNode *[2*T]; };
    void dodajElement(double k, string p);
    string usunElement(double k);
    int znajdzIndeks(double k);

    void wyswietlaj(double x, double y);

    void rozdziel(BTreeNode *y, int i);
    void wezPoprzednika(int index);
    void wezNastepnika(int index);
    void zlaczenie(int index);
};

class BTree
{
public:
    BTreeNode *korzen;

    BTree() { korzen = NULL; }
    void dodaj(string p, double klucz);
    string usun(double klucz);
    void wyswietl(double x, double y);
};

int main()
{
    ios_base::sync_with_stdio(false);

    BTree drzewo;

    int liczba_osob;
    cin >> liczba_osob;

    for(int i=0; i<liczba_osob; i++)
    {
        string n;
        double w;
        cin >> n;
        cin >> w;

        drzewo.dodaj(n, w);
    }

    int liczba_operacji;
    cin >> liczba_operacji;

    for(int i=0; i<liczba_operacji; i++)
    {
        char znak;
        cin >> znak;
        switch(znak)
        {
        case 'a':
        {
            string nowyN;
            double nowyW;
            cin >> nowyN;
            cin >> nowyW;
            drzewo.dodaj(nowyN, nowyW);
            break;
        }
        case 'm':
        {
            double wartosc1, wartosc2;
            cin >> wartosc1 >> wartosc2;
            string doZmiany = drzewo.usun(wartosc1);
            if(doZmiany!="")
                drzewo.dodaj(doZmiany, wartosc2);
            break;
        }
        case 's':
        {
            double x, y;
            cin >> x >> y;
            drzewo.wyswietl(x, y);
            break;
        }
        }
    }



    //    t.dodaj("Okruszek", 5);
    //    t.dodaj("Tester", 7);
    //    t.dodaj("Interfejs", 2);
    //    t.dodaj("Agent", 4);
    //    t.dodaj("Scyzoryk", 3);

    //    cout << "1." << endl;
    //    t.wyswietl();

    //    cout << "2." << endl;
    //    t.dodaj("Kontakt", 6);
    //    t.wyswietl();

    //    cout << "3." << endl;
    //    string temp =t.usun(7);
    //    cout << "Usunieto: " << temp << endl;
    //    t.wyswietl();
    //    cout << endl;
    //    t.dodaj(temp, 8);
    //    t.wyswietl();

    //    cout << "4." << endl;
    //    cout << "CAŁOŚĆ: " << endl;
    //    t.wyswietl();

    return 0;
}

void BTree::dodaj(string p, double klucz)
{
    if (korzen == NULL)
    {
        korzen = new BTreeNode();
        korzen->klucze[0].pseudonim = p;
        korzen->klucze[0].wartosc = klucz;
        korzen->rozmiar++;
        korzen->lisc = true;
    }
    else
    {
        if(korzen->rozmiar < 2*T-1)
            korzen->dodajElement(klucz, p);
        else
        {
            BTreeNode *nowy_korzen = new BTreeNode();
            nowy_korzen->lisc = false;

            nowy_korzen->dzieci[0] = korzen;
            nowy_korzen->rozdziel(korzen, 0);

            korzen = nowy_korzen;

            int index;
            klucz < korzen->klucze[0].wartosc ? index=1 : index=0;
            korzen->dzieci[index]->dodajElement(klucz, p);
        }
    }
}
string BTree::usun(double k)
{
    if(!korzen)
    {
        return "";
    }
    else
    {
        string t = korzen->usunElement(k);

        if (korzen->rozmiar==0)
        {
            BTreeNode *tmp = korzen;
            if (korzen->lisc)
                korzen = NULL;
            else
                korzen = korzen->dzieci[0];

            delete tmp;
        }
        return t;
    }
}
void BTree::wyswietl(double x, double y)
{
    if(korzen)
        korzen->wyswietlaj(x, y);
}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

void BTreeNode::dodajElement(double k, string p)
{
    int i;

    if(this->lisc)
    {
        for(i=rozmiar-1; i>=0 && klucze[i].wartosc<k; i--)
            klucze[i+1]=klucze[i];

        klucze[i+1].wartosc = k;
        klucze[i+1].pseudonim = p;
        rozmiar++;
    }
    else
    {
        for(i=rozmiar-1; i>=0 && klucze[i].wartosc<k; i--);

        if(dzieci[i+1]->rozmiar == 2*T-1)
        {
            rozdziel(dzieci[i+1], i+1);
            if(klucze[i+1].wartosc > k)
                i++;
        }
        dzieci[i+1]->dodajElement(k, p);
    }
}

void BTreeNode::rozdziel(BTreeNode *elem, int i)
{
    BTreeNode *nowy = new BTreeNode();
    nowy->lisc = elem->lisc;
    nowy->rozmiar = T-1;

    for(int j=0; j<nowy->rozmiar; j++)
        nowy->klucze[j] = elem->klucze[j+T];
    if(!elem->lisc)
        for(int j=0; j<T; j++)
            nowy->dzieci[j] = elem->dzieci[j+T];
    elem->rozmiar = T-1;
    for(int j=rozmiar; j>=i+1; j--)
        dzieci[j+1] = dzieci[j];
    dzieci[i+1] = nowy;
    for(int j=rozmiar-1; j>=i; j--)
        klucze[j+1] = klucze[j];


    klucze[i] = elem->klucze[T-1];
    rozmiar++;
}

void BTreeNode::wyswietlaj(double x, double y)
{
    int i;
    for (i=0; i<rozmiar; i++)
    {
        if(lisc == false)
            dzieci[i]->wyswietlaj(x, y);
        if(klucze[i].wartosc >= x && klucze[i].wartosc <=y)
            cout << klucze[i].pseudonim << endl;
    }

    if(lisc == false)
        dzieci[i]->wyswietlaj(x, y);
}
int BTreeNode::znajdzIndeks(double k)
{
    int index=0;
    while (index<rozmiar && klucze[index].wartosc > k)
        index++;
    return index;
}
string BTreeNode::usunElement(double klucz)
{
    int index = znajdzIndeks(klucz);
    string temp;

    if(index<rozmiar && klucze[index].wartosc==klucz)
    {
        temp = klucze[index].pseudonim;
        if (lisc)
        {
            for (int i=index+1; i<rozmiar; ++i)
                klucze[i-1] = klucze[i];
            rozmiar--;
        }
        else
        {
            int temp = klucze[index].wartosc;
            if(dzieci[index]->rozmiar >= T)
            {
                BTreeNode *tempowy = dzieci[index+1];
                while (!tempowy->lisc)
                    tempowy = tempowy->dzieci[0];
                klucze[index].wartosc = tempowy->klucze[0].wartosc;
                dzieci[index+1]->usunElement(tempowy->klucze[0].wartosc);
            }
            else if(dzieci[index+1]->rozmiar >= T)
            {
                BTreeNode *tempowy = dzieci[index];
                while (!tempowy->lisc)
                    tempowy = tempowy->dzieci[tempowy->rozmiar-1];
                klucze[index].wartosc = tempowy->klucze[tempowy->rozmiar-1].wartosc;
                dzieci[index]->usunElement(tempowy->klucze[tempowy->rozmiar-1].wartosc);
            }
            else
            {
                zlaczenie(index);
                dzieci[index]->usunElement(temp);
            }
        }
    }
    else
    {
        if (lisc)
        {
            return "";
        }
        bool flaga;
        if(index==rozmiar)
            flaga = true;
        else
            flaga =false;
        if(dzieci[index]->rozmiar < T)
        {
            if(index!=0 && dzieci[index-1]->rozmiar>=T)
                wezPoprzednika(index);
            else if(index!=rozmiar && dzieci[index+1]->rozmiar>=T)
                wezNastepnika(index);
            else
            {
                if (index != rozmiar)
                    zlaczenie(index);
                else
                    zlaczenie(index-1);
            }
        }

        if(!flaga && index <= rozmiar)
            temp = dzieci[index]->usunElement(klucz);
        else
            temp = dzieci[index-1]->usunElement(klucz);
    }
    return temp;
}
void BTreeNode::wezPoprzednika(int index)
{
    BTreeNode *dziecko=dzieci[index];
    BTreeNode *brat=dzieci[index-1];

    for (int i=dziecko->rozmiar-1; i>=0; --i)
        dziecko->klucze[i+1] = dziecko->klucze[i];

    if (dziecko->lisc == false)
    {
        for(int i=dziecko->rozmiar; i>=0; --i)
            dziecko->dzieci[i+1] = dziecko->dzieci[i];
        dziecko->klucze[0] = klucze[index-1];

        if(!dziecko->klucze)
            dziecko->dzieci[0] = brat->dzieci[brat->rozmiar];
        klucze[index-1] = brat->klucze[brat->rozmiar-1];

        dziecko->rozmiar++;
        brat->rozmiar--;
    }
}

void BTreeNode::wezNastepnika(int idx)
{
    BTreeNode *dziecko=dzieci[idx];
    BTreeNode *brat=dzieci[idx+1];

    dziecko->klucze[(dziecko->rozmiar)] = klucze[idx];

    if (dziecko->lisc==false)
        dziecko->dzieci[(dziecko->rozmiar)+1] = brat->dzieci[0];

    klucze[idx] = brat->klucze[0];

    for (int i=1; i<brat->rozmiar; ++i)
        brat->klucze[i-1] = brat->klucze[i];

    if (brat->lisc==false)
    {
        for(int i=1; i<=brat->rozmiar; ++i)
            brat->dzieci[i-1] = brat->dzieci[i];
    }

    dziecko->rozmiar++;
    brat->rozmiar--;
}

void BTreeNode::zlaczenie(int index)
{
    BTreeNode *dziecko = dzieci[index];
    BTreeNode *brat = dzieci[index+1];

    dziecko->klucze[T-1] = klucze[index];

    for (int i=0; i<brat->rozmiar; ++i)
        dziecko->klucze[i+T] = brat->klucze[i];
    if (!dziecko->lisc)
    {
        for(int i=0; i<=brat->rozmiar; ++i)
            dziecko->dzieci[i+T] = brat->dzieci[i];
    }
    for (int i=index+1; i<rozmiar; ++i)
        klucze[i-1] = klucze[i];

    for (int i=index+2; i<=rozmiar; ++i)
        dzieci[i-1] = dzieci[i];
    dziecko->rozmiar += brat->rozmiar+1;

    rozmiar--;

    delete(brat);
}