/**
 * Project Untitled
 */


#include "SamochodDoNaprawy.h"

SamochodDoNaprawy::SamochodDoNaprawy(string m1, string m2, Silnik *s, string a)
{
    marka=m1;
    model=m2;
    silnik=*s;
    awaria=a;
}

string SamochodDoNaprawy::znajdzUsluge(string coDoZrobienia) {
    return znajdzRoboteDoZrobienia(coDoZrobienia);

}

string SamochodDoNaprawy::getMarkaAndModel() {
    return marka + " " + model;
}
