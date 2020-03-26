#include "SchematBernouliego.h"

SchematBernouliego::SchematBernouliego() {
    potega = new Potega;
    dwumianN = new SymbolNewtona;
}

void SchematBernouliego::oblicz(int k, int n, double p) {
    double result = dwumianN->obliczSymbolNewtona(n, k) * potega->obliczPotege(p, k) * potega->obliczPotege(1-p, n-k);
    cout << "Wynik: " << result << endl;
}
