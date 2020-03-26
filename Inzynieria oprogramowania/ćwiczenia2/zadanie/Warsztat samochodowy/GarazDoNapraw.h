/**
 * Project Untitled
 */


#ifndef _GARAZDONAPRAW_H
#define _GARAZDONAPRAW_H

#include "Budynek.h"
#include "Pracownik.h"
#include "SamochodDoNaprawy.h"
#include <vector>
#include <iostream>

using namespace std;

class GarazDoNapraw: public Budynek {
public:
    GarazDoNapraw(int nr);
    int getNrGarazu();
    void setNrGarazu(int x);
    void dodajPracownika(Pracownik m);
    void dodajSamochod(SamochodDoNaprawy s);
    void getSamochody();
private: 
    int nrGarazu;

    vector<Pracownik> pracownicy;
    vector<SamochodDoNaprawy> samochody;
};

#endif //_GARAZDONAPRAW_H
