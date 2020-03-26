/**
 * Project Untitled
 */


#include "ZestawNarzedzi.h"

ZestawNarzedzi::ZestawNarzedzi(int nrZestawu) {
    if(nrZestawu==1)
    {
        this->liczbaKluczy=5;
        this->liczbaSrubokretow=2;
        this->liczbaParRekawiczek=1;
    }
    else if(nrZestawu==2)
    {
        this->liczbaKluczy=2;
        this->liczbaSrubokretow=5;
        this->liczbaParRekawiczek=3;
    }
    else if(nrZestawu==3)
    {
        this->liczbaKluczy==3;
        this->liczbaSrubokretow=3;
        this->liczbaParRekawiczek=2;
    }
}
