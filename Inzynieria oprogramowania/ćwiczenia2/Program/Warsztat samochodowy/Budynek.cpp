/**
 * Project Untitled
 */

#include "Budynek.h"

void Budynek::Budnek(float wymiarX, float wymiarY) {
    this->poleBudynku_m2 = obliczPole(wymiarX, wymiarY);
}
int Budynek::obliczPole(float wymiarX, float wymiarY) {
    return wymiarX*wymiarY;
}
