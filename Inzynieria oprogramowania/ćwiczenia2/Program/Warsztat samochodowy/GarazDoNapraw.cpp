/**
 * Project Untitled
 */


#include "GarazDoNapraw.h"

GarazDoNapraw::GarazDoNapraw(int nr)
{
    nrGarazu = nr;
}

int GarazDoNapraw::getNrGarazu() {
    return this->nrGarazu;
}

void GarazDoNapraw::setNrGarazu(int x) {
    this->nrGarazu = x;
}

void GarazDoNapraw::dodajPracownika(Pracownik m) {
    pracownicy.push_back(m);
}

void GarazDoNapraw::dodajSamochod(SamochodDoNaprawy s) {
    samochody.push_back(s);
    std::cout << "Dodano " << samochody.size() << " samochod, raz dwa do roboty!";
}

void GarazDoNapraw::getSamochody() {
    cout << "Samochody czekajace na naprawe:" << endl;
    for(vector<SamochodDoNaprawy>::iterator it = samochody.begin(); it!=samochody.end(); it++)
        cout << (*it).getMarkaAndModel() << endl;
}
