#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    string klucz;
    vector<Node*> wskazniki;
    Node *lewy=NULL, *prawy=NULL, *ojciec=NULL;
};

class SplayTree
{
public:
    Node *korzen;

    SplayTree() { korzen=NULL; }
    void dodaj(string k);
    Node* znajdz(string k);
    void splay(Node *wierzcholek);
    void rotacjaLewo(Node *wierzcholek);
    void rotacjaPrawo(Node *wierzcholek);
};

int main()
{
    ios::sync_with_stdio(false);

    SplayTree drzewo_zespoly, drzewo_kasety;

    long n;
    cin >> n;
    cin.ignore();
    
    for(long i=0; i<n; i++)
    {
        string wybor;
        getline(cin, wybor);
        
        if(wybor.length()==1)
        {
            switch(wybor[0])
            {
            case 'd':
            {
                string zespol, kaseta, xd;

                getline(cin, zespol);
                getline(cin, kaseta);

                drzewo_zespoly.dodaj(zespol);
                drzewo_kasety.dodaj(kaseta);

                drzewo_zespoly.korzen->wskazniki.push_back(drzewo_kasety.korzen);
                drzewo_kasety.korzen->wskazniki.push_back(drzewo_zespoly.korzen);

                break;
            }
            case 'w':
            {
                string zespol, xd;
                getline(cin, zespol);

                Node *temp = drzewo_zespoly.znajdz(zespol);

                if(temp!=NULL && temp->klucz==zespol)
                {
                    drzewo_zespoly.splay(temp);
                    if(!drzewo_zespoly.korzen->wskazniki.empty())
                        for(vector<Node*>::iterator it=drzewo_zespoly.korzen->wskazniki.begin(); it!=drzewo_zespoly.korzen->wskazniki.end(); it++)
                            cout << (*it)->klucz << endl;
                }
                break;
            }
            case 'z':
            {
                string kaseta, xd;
                getline(cin, kaseta);

                Node *temp = drzewo_kasety.znajdz(kaseta);

                if(temp!=NULL && temp->klucz==kaseta)
                {
                    drzewo_kasety.splay(temp);
                    if(!drzewo_kasety.korzen->wskazniki.empty())
                        for(vector<Node*>::iterator it=drzewo_kasety.korzen->wskazniki.begin(); it!=drzewo_kasety.korzen->wskazniki.end(); it++)
                            cout << (*it)->klucz << endl;
                }
                break;
            }
            }
        }
    }

    return 0;
}

void SplayTree::dodaj(string k)
{
    Node *nowy = new Node;
    nowy->klucz = k;

    if(!korzen)
    {
        korzen = nowy;
    }
    else
    {
        Node *wsk = znajdz(k);
        if(wsk->klucz==k)
        {
            splay(wsk);
        }
        else
        {
            if(k < wsk->klucz)
            {
                wsk->lewy = nowy;
                wsk->lewy->ojciec = wsk;
            }
            else
            {
                wsk->prawy = nowy;
                wsk->prawy->ojciec = wsk;
            }
            splay(nowy);
        }
    }
}
Node* SplayTree::znajdz(string k)
{
    Node* temp=korzen, *wsk=NULL;
    while(temp!=NULL && temp->klucz!=k)
    {
        wsk = temp;
        if(k < temp->klucz)
            temp = temp->lewy;
        else
            temp = temp->prawy;
    }
    if(temp==NULL)
        return wsk;
    return temp;
}
void SplayTree::splay(Node *wierzcholek)
{
    if(wierzcholek == korzen)
        return;

    if(wierzcholek->ojciec == korzen) // zig
    {
        if(wierzcholek->klucz < korzen->klucz)
        {
            rotacjaPrawo(korzen);
            korzen = wierzcholek;
        }
        else
        {
            rotacjaLewo(korzen);
            korzen = wierzcholek;
        }
    }
    else
    {
        if(wierzcholek->ojciec->ojciec == korzen)
        {
            korzen = wierzcholek;
        }
        if(wierzcholek->ojciec->ojciec->klucz > wierzcholek->ojciec->klucz && wierzcholek->ojciec->klucz > wierzcholek->klucz) //zig-zig
        {
            rotacjaPrawo(wierzcholek->ojciec);
            rotacjaPrawo(wierzcholek->ojciec);
        }
        else if(wierzcholek->ojciec->ojciec->klucz < wierzcholek->ojciec->klucz && wierzcholek->ojciec->klucz < wierzcholek->klucz) //zig-zig
        {
            rotacjaLewo(wierzcholek->ojciec);
            rotacjaLewo(wierzcholek->ojciec);
        }
        else if(wierzcholek->ojciec->ojciec->klucz < wierzcholek->ojciec->klucz && wierzcholek->ojciec->klucz > wierzcholek->klucz) //zig-zag
        {
            rotacjaPrawo(wierzcholek->ojciec);
            rotacjaLewo(wierzcholek->ojciec);
        }
        else //zig-zag
        {
            rotacjaLewo(wierzcholek->ojciec);
            rotacjaPrawo(wierzcholek->ojciec);
        }
        splay(wierzcholek);
    }
}
void SplayTree::rotacjaLewo(Node *wierzcholek)
{
    Node *syn = wierzcholek->prawy,  *dziadek=wierzcholek->ojciec;
    if(wierzcholek->prawy!=NULL)
    {
        wierzcholek->prawy = wierzcholek->prawy->lewy;

        if(wierzcholek->prawy!=NULL)
        {
            wierzcholek->prawy->ojciec = wierzcholek;
        }
        syn->lewy = wierzcholek;
        wierzcholek->ojciec = syn;
        syn->ojciec = dziadek;

        if(dziadek!=NULL)
        {

            if(wierzcholek == dziadek->lewy)
                dziadek->lewy = syn;
            else
                dziadek->prawy = syn;
        }
    }
}
void SplayTree::rotacjaPrawo(Node *wierzcholek)
{
    Node *syn = wierzcholek->lewy, *dziadek =wierzcholek->ojciec;
    if(wierzcholek->lewy!=NULL)
    {
        wierzcholek->lewy = wierzcholek->lewy->prawy;

        if(wierzcholek->lewy!=NULL)
        {
            wierzcholek->lewy->ojciec = wierzcholek;

        }
        syn->prawy = wierzcholek;
        wierzcholek->ojciec = syn;
        syn->ojciec = dziadek;
        if(dziadek!=NULL)
        {
            if(wierzcholek == dziadek->prawy)
                dziadek->prawy = syn;
            else
                dziadek->lewy = syn;
        }
    }
}