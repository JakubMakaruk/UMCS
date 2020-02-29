#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Zadanie
{
public:
    int liczbaRozwiazan;
    vector<int> *produkty;
    int liczbaProduktow;
    int liczbaKalorii;

    Zadanie();
    void dodaj_produkty();
    void backtracking(int poziom, int suma);
};

Zadanie::Zadanie()
{
    produkty = new vector<int>;
    liczbaRozwiazan=0;
}

void Zadanie::dodaj_produkty()
{
    cin >> liczbaProduktow;
    for(int i=0; i<liczbaProduktow; i++)
    {
        int element;
        cin >> element;
        produkty->push_back(element);
    }

    cin >> liczbaKalorii;

    sort(produkty->rbegin(), produkty->rend());

	vector<int>::iterator it=produkty->begin();
	while(*it > liczbaKalorii)
	{
		produkty->pop_back();
		it++;
	}

    backtracking(0, 0);
}

void Zadanie::backtracking(int poziom, int suma)
{
    if(poziom == liczbaProduktow)
    {
        return;
    }
	else
	{
        vector<int>::iterator i = produkty->begin()+poziom;
        suma = suma + *i;

		if(suma < liczbaKalorii)
        {
            backtracking(poziom+1, suma);
        }
		else if(suma == liczbaKalorii)
        {
            liczbaRozwiazan++;
        }
        backtracking(poziom+1, suma-(*i));
	}
}


int main()
{
	ios_base::sync_with_stdio(false);

    int liczbaTestow;
    cin >> liczbaTestow;

    for(int i=0; i<liczbaTestow; i++)
    {
        Zadanie *algorytm11 = new Zadanie();
        algorytm11->dodaj_produkty();
        cout << algorytm11->liczbaRozwiazan << endl;
    }
    return 0;
}