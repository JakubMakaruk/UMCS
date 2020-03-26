#ifndef _SYMBOLNEWTONA_H
#define _SYMBOLNEWTONA_H

#include "Silnia.h"

using namespace std;

class SymbolNewtona {
public:
    SymbolNewtona();
    double obliczSymbolNewtona(int n, int k);

private:
    Silnia* silnia;
};

#endif //_SYMBOLNEWTONA_H
