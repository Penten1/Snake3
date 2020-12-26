#include "clanek.h"
#include "had.h"
#include "grafika.h"

const int obrazovkaSirka = 608;
const int obrazovkaVyska = 608;

Clanek::Clanek(float poziceX, float poziceY, Had *had)
{
    this->poziceX = poziceX;
    this->poziceY = poziceY;
    sirkaClanku = had->sirkaHada;
    this->had = had;
}

void Clanek::kresli(){
    for(int i = 0; i < sirkaClanku;i ++){
//        barva(75, 254, 0);
        barva(MODRA);
//        cara(poziceX + i,poziceY -sirkaClanku, poziceX + i,poziceY);
        cara((poziceX-1) * had->sirkaHada + i,(poziceY - 1) * had->sirkaHada + sirkaClanku,(poziceX - 1) * had->sirkaHada + i,(poziceY - 1) * had->sirkaHada);
//        if(had->rychlostX == 0 && had->rychlostY == -had->rychlost){
//            cara(poziceX * had->sirkaHada + i,poziceY * had->sirkaHada + sirkaClanku,poziceX * had->sirkaHada + i,poziceY * had->sirkaHada);
//        }
    }

}









