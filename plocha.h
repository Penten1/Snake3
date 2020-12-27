#ifndef PLOCHA_H
#define PLOCHA_H
#include "grafika.h"
#include "had.h"
#include "ovoce.h"

class Had;
class Plocha
{
public:
    Plocha();
    Had*h;
    int Pocet;
    Ovoce* pole[2];
    void kolize();

    int pocetPoli;
};

#endif // PLOCHA_H
