/**
 * Project Untitled
 */


#include "Pracownik.h"

Pracownik::Pracownik(Zawod z, string i, string n, int nr) {
    this->zawod=z;
    this->imie=i;
    this->nazwisko=n;
    this->nrTelefonu=nr;
}

void Pracownik::wypozyczZestawNarzedzi(int nrZestawu) {
    std::cout << "Wypozyczam zestaw nr " << nrZestawu << std::endl;
}
