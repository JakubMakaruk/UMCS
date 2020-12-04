#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long liczba_tropow, granicaA, granicaB, wynik;

long wynikA=-1, wynikB=-1;
bool pierwsza_odp=false;

vector<long> zbior;

struct Node
{
    long liczba;
    bool czy_miesci_sie=false;
    Node *lewy=NULL, *prawy=NULL;
};

class BST {
public:
    Node* korzen;

    BST() { korzen=NULL; }
    Node* dodaj(Node *ojciec, long x);
    void preorder(Node *temp);
    bool rozwiaz(Node *temp);
    void siema(Node *temp);
};

int main()
{
    cin >> liczba_tropow;

    BST drzewo;

    for(long i=0; i<liczba_tropow; i++)
    {
        long x;
        cin >> x;
        drzewo.korzen = drzewo.dodaj(drzewo.korzen, x);
    }

    cin >> granicaA >> granicaB >> wynik;

    drzewo.preorder(drzewo.korzen); //do zaznaczenia dobrych wierzcholkow

    drzewo.rozwiaz(drzewo.korzen);

    if(wynikA==-1 && wynikB==-1)
        cout << "NIE ZNALEZIONO";
    else
        cout << wynikA << " " << wynikB;

    return 0;
}

Node* BST::dodaj(Node* ojciec, long x)
{
    if(ojciec == NULL)
    {
        ojciec = new Node;
        ojciec->liczba = x;
    }
    else if(x < ojciec->liczba)
        ojciec->lewy = dodaj(ojciec->lewy, x);
    else if(x > ojciec->liczba)
        ojciec->prawy = dodaj(ojciec->prawy, x);
    return ojciec;
}
void BST::preorder(Node *temp)
{
    if(temp==NULL)
        return;
    if(temp->liczba >= granicaA && temp->liczba <= granicaB)
        temp->czy_miesci_sie = true;
    else
        temp->czy_miesci_sie = false;

    preorder(temp->lewy);
    preorder(temp->prawy);
}
bool BST::rozwiaz(Node *temp)
{
    if(temp==NULL)
        return false;

    if(rozwiaz(temp->lewy))
        return true;

    if(temp->czy_miesci_sie)
    {
        long szukana = wynik - temp->liczba;
        vector<long>::iterator czy = find(zbior.begin(), zbior.end(), szukana);
        if(czy!=zbior.end())
        {
            if(*czy > temp->liczba)
            {
                wynikA = temp->liczba;
                wynikB = *czy;
            }
            else
            {
                wynikA = *czy;
                wynikB = temp->liczba;
            }
            return true;
        }
        else
            zbior.push_back(temp->liczba);
    }

    if(rozwiaz(temp->prawy))
        return true;
    return false;
}