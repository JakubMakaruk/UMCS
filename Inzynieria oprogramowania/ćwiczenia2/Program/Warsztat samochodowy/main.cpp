#include <iostream>
#include "Budynek.h"
#include "GarazDoNapraw.h"
#include "Kolo.h"
#include "Pracownik.h"
#include "SamochodDoNaprawy.h"
#include "Silnik.h"
#include "Usluga.h"
#include "Zawod.h"
#include "ZestawNarzedzi.h"

using namespace std;

int main()
{
    GarazDoNapraw g1(3);
    g1.setNrGarazu(1);

    cout << "Garaz numer " << g1.getNrGarazu() << " ma pole rowne: " << g1.obliczPole(12, 14) << " m^2." << endl;

    Zawod *z1 = new Zawod("Wlasciciel");
    Zawod *z2 = new Zawod("Mechanik");
    Zawod *z3 = new Zawod("Kasjer");
    Zawod z4("Wlasciciel");

    Pracownik *p1 = new Pracownik(*z1, "Adam", "Kowalski", 500200100);
    Pracownik *p2 = new Pracownik(*z2, "Jan", "Florek", 200300400);

    g1.dodajPracownika(*p1);
    g1.dodajPracownika(*p2);

    Silnik *s = new Silnik("silnik", 140, 155, 1700);

    SamochodDoNaprawy *s1 = new SamochodDoNaprawy("Opel", "Astra", s, "cos zle");
    SamochodDoNaprawy *s2 = new SamochodDoNaprawy("Mazda", "6", s, "cos zle");

    g1.dodajSamochod(*s1);
    g1.dodajSamochod(*s2);

    cout << endl;

    g1.getSamochody();

    return 0;
}
