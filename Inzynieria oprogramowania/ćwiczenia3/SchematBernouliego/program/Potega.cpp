#include "Potega.h"

double Potega::obliczPotege(double podstawa, int x) {
    if(x==0)
        return 1;
    else
        return podstawa*obliczPotege(podstawa, x-1);
}
