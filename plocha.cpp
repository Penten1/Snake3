#include "plocha.h"

Plocha::Plocha()
{
    PocetJablek = 2;
    pocetPoli = 30;
    sirkaPole = 42;
    h = new Had(this);

    for(int i = 0;i < PocetJablek;i++){
        pole[i] = new Ovoce(this);
    }

}

void Plocha::kolize(){
    for(int i = 0;i < PocetJablek;i++){
        if(h->poziceX == pole[i]->poziceX && h->poziceY == pole[i]->poziceY){
            h->delkaHada = h->delkaHada + 2;
            delete pole[i];
            pole[i] = new Ovoce(this);
        }
    }

}
