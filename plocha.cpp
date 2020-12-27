#include "plocha.h"

Plocha::Plocha()
{
    Pocet = 2;
    h = new Had();
    pocetPoli = 30;
    for(int i = 0;i < Pocet;i++){
        pole[i] = new Ovoce;
    }


}

void Plocha::kolize(){
    for(int i = 0;i < Pocet;i++){
        if(h->poziceX == pole[i]->poziceX&& h->poziceY == pole[i]->poziceY){
            h->delkaHada = h->delkaHada + 2;
            delete pole[i];
            pole[i] = new Ovoce;
        }
    }

}
