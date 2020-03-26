#include <iostream>
#include "SchematBernouliego.h"
using namespace std;

int main()
{
    SchematBernouliego schemat;

    cout << "WPROWADZ DANE\n| 0 <= k <= n | 0 <= p <= 1\n";

    int n, k;
    double p;

    cout << "\nWprowadz n: ";
    cin >> n;

    cout << "\nWprowadz k: ";
    cin >> k;

    cout << "\nWprowadz p: ";
    cin >> p;

    if(k>n || k<0 || n<0 || p<0 || p>1)
        cout << "Bledne dane!";
    else
        schemat.oblicz(k, n, p);

    return 0;
}
