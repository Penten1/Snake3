#include "had.h"
#include "grafika.h"


//608 protože sirka hada * pocet policek
int obrazovkaSirka;
int obrazovkaVyska;

extern int otoc;
extern int otoc2;

Had::Had()
{

    sirkaHada = 32;
    pocetPoli = 30;
    obrazovkaSirka = sirkaHada * pocetPoli;
    obrazovkaVyska = sirkaHada * pocetPoli;

    //    obrazovkaSirka = sirkaHada * pocetPoli;
    //    obrazovkaVyska = sirkaHada * pocetPoli;
    poziceY = obrazovkaVyska/3 * 2 / sirkaHada;
    poziceX = (obrazovkaSirka / 2) / sirkaHada;
    //    poziceY = 1;
    //    poziceX = 1;
    zdrzeni = 10;
    zdrzeni2 = zdrzeni * 2 + 1;
    counter = zdrzeni + 1;
    rychlost = 1;
    rychlostX = 0;
    rychlostY = 0;
    delkaHada = 1;
    for(int i = delkaHada;i > 0; i--){
        clanky.push_back(new Clanek(poziceX,poziceY + i,this));
    }
    //    poziceX = 20;
    gameOverTrue = false;
}

void Had::kresli(){
    for(int i = 0; i < sirkaHada;i ++){
        barva(75, 254, 0);
        cara((poziceX-1) * sirkaHada + i,(poziceY-1) * sirkaHada, (poziceX-1) * sirkaHada + i,(poziceY-1) * sirkaHada+sirkaHada);
    }
    for(c = clanky.begin(); c != clanky.end(); c++)
    {
        (*c)->kresli();
    }


}

void Had::pohyb(){

    if(1 == (zdrzeni2 % counter)){

        if(otoc == 1){
            rychlostX=-rychlost;
            rychlostY=0;
            otoc = 0;
        }
        if(otoc2 == 1){
            rychlostX=-rychlost;
            rychlostY=0;
            otoc2 = 0;
        }
        if(otoc == 2){
            rychlostX=0;
            rychlostY=-rychlost;
            otoc = 0;
        }
        if(otoc2 == 2){
            rychlostX=0;
            rychlostY=-rychlost;
            otoc2 = 0;
        }
        if(otoc == 3){
            rychlostX=0;
            rychlostY=rychlost;
            otoc = 0;
        }
        if(otoc2 == 3){
            rychlostX=0;
            rychlostY=rychlost;
            otoc2 = 0;
        }
        if(otoc == 4){
            rychlostX=rychlost;
            rychlostY=0;
            otoc = 0;
        }
        if(otoc2 == 4){
            rychlostX=rychlost;
            rychlostY=0;
            otoc2 = 0;
        }
        if(jeNarazDoOcasu(poziceX + rychlostX,poziceY + rychlostY)){
            gameOverTrue = true;
            gameOver();
        }

        //            if(!jeNarazDoOcasu(poziceX + rychlostX,poziceY + rychlostY)){
        if(!jeNarazDoOcasu(poziceX + rychlostX,poziceY + rychlostY)){
            poziceX = poziceX + rychlostX;
            poziceY = poziceY + rychlostY;
            //dolu
            //                for(c = clanky.begin(); c != clanky.end(); c++)
            //                {
            //                    if((*c)->poziceX == poziceX && (*c)->poziceY == poziceY){
            //                        a++;
            //                    }
            //                }
            if(rychlostX == 0 && rychlostY == rychlost){
                if(rychlostX != 0 || rychlostY != 0){
                    clanky.push_back(new Clanek(poziceX,poziceY - 1,this));
                }
            }
            //doprava
            if(rychlostX == rychlost && rychlostY == 0){
                if(rychlostX != 0 || rychlostY != 0){
                    clanky.push_back(new Clanek(poziceX - 1,poziceY,this));
                }
            }
            //doleva
            if(rychlostX == -rychlost && rychlostY == 0){
                if(rychlostX != 0 || rychlostY != 0){
                    clanky.push_back(new Clanek(poziceX + 1,poziceY,this));
                }
            }
            //nahoru
            if(rychlostX == 0 && rychlostY == -rychlost){
                if(rychlostX != 0 || rychlostY != 0){
                    clanky.push_back(new Clanek(poziceX,poziceY+1,this));
                }
            }
            //                if(ovoce->poziceX==poziceX && ovoce->poziceY==poziceY){
            //                    delkaHada = delkaHada + 5;
            //                }
            //clanky.push_back(new Clanek(poziceX,poziceY,this));
            if(delkaHada < clanky.size()){
                clanky.pop_front();
            }
        }

        //            }

    }
    //    counter = (zdrzeni % counter);

    counter++;
    if(counter == zdrzeni2){
        counter = zdrzeni + 1;
    }





}
//if(poziceX  > pocetPoli - 1){
//   return true;
//}
//if(poziceX < 0){
//      return true;
//}
//if(poziceY < 1){
//      return true;
//}
//if(poziceY > pocetPoli){
//     return true;
//}
bool Had::gameOver(){

    if(poziceX  > pocetPoli - 1){
        rychlost = 0;
        rychlostX = 0;
        rychlostY = 0;
        return true;
    }
    if(poziceX < 0){
        rychlost = 0;
        rychlostX = 0;
        rychlostY = 0;
        return true;
    }
    if(poziceY < 1){
        rychlost = 0;
        rychlostX = 0;
        rychlostY = 0;
        return true;
    }
    if(poziceY > pocetPoli){
        rychlost = 0;
        rychlostX = 0;
        rychlostY = 0;
        return true;
    }
    if(gameOverTrue == true){
        return true;
    }
    return false;
}

void Had::gameOverKresli(){
    gameOver2.nacti("game over2.png");
    gameOver2.umisti(obrazovkaSirka / 2 - gameOver2.w / 2,obrazovkaVyska / 2 - gameOver2.h / 2);
    gameOver2.kresli();
}

bool Had::jeNarazDoOcasu(int poziceX, int poziceY){
    for(c = clanky.begin(); c != clanky.end(); c++)
    {
        if((poziceX+1) == (*c)->poziceX+1 && (poziceY + 1) == (*c)->poziceY+1){
            return true;
        }
    }
    return false;
}
