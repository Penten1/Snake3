#ifndef PLOCHA_H
#define PLOCHA_H
#include "grafika.h"
#include "had.h"
#include "ovoce.h"

class Ovoce;
class Had;
class Plocha
{
public:
    Plocha();
    Had*h;
    int PocetJablek;
    Ovoce* pole[2];
    void kolize();
    int pocetPoli;
    int sirkaPole;
    int score;

    void kresli();


};

#endif // PLOCHA_H
