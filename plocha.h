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
    Pismo highScore;
    Obrazek obrHighScore;
    int score;
    void cary();
    void kresli();
    int obrazovkaSirka;
    int obrazovkaVyska;
    int nacteneScore;
    FILE * fw;
    void gameOverKresli();
    Obrazek gameOver2;
    int zdrzeni = 190; /*ms*/
    Obrazek exit;
    void uvodniMenu();

};

#endif // PLOCHA_H
