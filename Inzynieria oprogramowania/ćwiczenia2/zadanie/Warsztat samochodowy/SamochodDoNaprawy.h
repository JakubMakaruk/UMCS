/**
 * Project Untitled
 */


#ifndef _SAMOCHODDONAPRAWY_H
#define _SAMOCHODDONAPRAWY_H

#include "Usluga.h"
#include "Usluga.h"
#include "Silnik.h"
#include "Kolo.h"
#include <iostream>
#include <vector>

using namespace std;


class SamochodDoNaprawy : public Usluga {
public:
    string znajdzUsluge(string coDoZrobienia);
    string getMarkaAndModel();
    SamochodDoNaprawy(string m1, string m2, Silnik *s, string a);
private: 
    string marka;
    string model;
    Silnik silnik;
    int liczbaKol;
    vector<Kolo> kola;
    string awaria;
};

#endif //_SAMOCHODDONAPRAWY_H
