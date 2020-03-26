/**
 * Project Untitled
 */


#ifndef _SILNIK_H
#define _SILNIK_H

#include <iostream>

class Silnik {
public: 

    Silnik(std::string m1, int m2, int m3, int p);
    Silnik();
private: 
    std::string model;
    int moc;
    int momentObrotowy;
    int pojemnosc;
};

#endif //_SILNIK_H
