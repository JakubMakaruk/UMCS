/**
 * Project Untitled
 */


#ifndef _PRACOWNIK_H
#define _PRACOWNIK_H

#include "Zawod.h"
#include <iostream>

using namespace std;


class Pracownik : public Zawod {
public:
    Pracownik(Zawod z, std::string i, std::string n, int nr);
    void wypozyczZestawNarzedzi(int nrZestawu);
private: 
    Zawod zawod;
    std::string imie;
    std::string nazwisko;
    int nrTelefonu;
    int zestawNarzedzi;
};

#endif //_PRACOWNIK_H
