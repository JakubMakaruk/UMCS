/**
 * Project Untitled
 */


#include "Kolo.h"

Kolo::Kolo(int s, int w, int r, bool spr) {
    szerokoscOpony=s;
    wysokoscProfiluOpony=w;
    rozmiarFelgi=r;
    sprawnosc=spr;
}

bool Kolo::getSprawnosc() {
    return this->sprawnosc;
}
