#ifndef _SCHEMATBERNOULIEGO_H
#define _SCHEMATBERNOULIEGO_H

#include "Potega.h"
#include "SymbolNewtona.h"
#include <iostream>
#include <iomanip>


class SchematBernouliego {
public: 
    SchematBernouliego();
    void oblicz(int k, int n, double p);
private: 
    Potega* potega;
    SymbolNewtona* dwumianN;
};

#endif //_SCHEMATBERNOULIEGO_H
