/**
 * Project Untitled
 */


#include "Silnik.h"

Silnik::Silnik()
{

}

Silnik::Silnik(std::string m1, int m2, int m3, int p) {
    this->model = m1;
    this->moc = m2;
    this->momentObrotowy = m3;
    this->pojemnosc = p;
}
