#ifndef HAD_H
#define HAD_H
#include "clanek.h"
#include "grafika.h"
#include <list>

#include "plocha.h"

class Plocha;
class Clanek;
class Had
{
public:
    Had(Plocha *p);
    void pohyb();
    void kresli();
    float poziceX;
    float poziceY;
    float rychlost;
    float rychlostX;
    float rychlostY;
    int sirkaHada;
    bool gameOver();
    void gameOverKresli();
    bool gameOverTrue;
    int delkaHada;
//    std::list<Clanek*>;
    Clanek *clanek;
    std::list<Clanek*> clanky;
    std::list<Clanek*>::iterator c;
    int counter;
    int zdrzeni;
    int zdrzeni2;

    int pocetPoli;
    Plocha *p;

private:
    bool jeNarazDoOcasu(int poziceX, int poziceY);
};

#endif // HAD_H
