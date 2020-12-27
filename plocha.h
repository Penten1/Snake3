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
    Pismo cisla;
    int score;
    void cary();
    void kresli();
    int obrazovkaSirka;
    int obrazovkaVyska;

};

#endif // PLOCHA_H
