/**
 * Project Untitled
 */


#include "Usluga.h"

string Usluga::znajdzRoboteDoZrobienia(string n)
{
    if(n=="cos z silnikiem")
        return "Sprawdz dzialanie silnika!";
    else if(n=="cos z hamulcami")
        return "Sprawdz klocki/tarcze hamulcowe!";
    else if(n=="malo powietrza w kolach")
        return "Sprawdz powietrze opon!";
}
