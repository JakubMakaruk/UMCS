#include "Silnia.h"

int Silnia::obliczSilnie(int x) {
    if(x==0)
        return 1;
    else
        return x*obliczSilnie(x-1);
}
