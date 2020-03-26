#include "SymbolNewtona.h"

#include <iostream>

using namespace std;

double SymbolNewtona::obliczSymbolNewtona(int n, int k) {
    int gora1 = silnia->obliczSilnie(n);
    int dol1 = silnia->obliczSilnie(k);
    int dol2 = silnia->obliczSilnie(n-k);

    return gora1/(dol1*dol2);
}

SymbolNewtona::SymbolNewtona() {
    silnia = new Silnia;
}
