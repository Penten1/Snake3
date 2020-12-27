#include "plocha.h"

Plocha::Plocha()
{
    PocetJablek = 2;
    pocetPoli = 30;

    sirkaPole = 32;
    h = new Had(this);

    for(int i = 0;i < PocetJablek;i++){
        pole[i] = new Ovoce(this);
    }


    score = 0;
    for(int i = 0;i < PocetJablek;i++){
        pole[i] = new Ovoce(this);
    }
    cisla.umisti(20,20);
    obrazovkaSirka = sirkaPole * pocetPoli;
    obrazovkaVyska = sirkaPole * pocetPoli;

}

void Plocha::kolize(){
    for(int i = 0;i < PocetJablek;i++){
        if(h->poziceX == pole[i]->poziceX && h->poziceY == pole[i]->poziceY){
            h->delkaHada = h->delkaHada + 2;
            delete pole[i];
            pole[i] = new Ovoce(this);
            score = score + 10;
        }
    }

}
void Plocha::cary(){
    for(float i = 0;i < obrazovkaSirka;i = i + obrazovkaSirka/pocetPoli){
        barva(MODRA);
        cara(i,0,i,obrazovkaVyska);
        cara(0,i,obrazovkaSirka,i);
    }
}
void Plocha::kresli(){
    cary();
    cisla.kresli(score);

}


