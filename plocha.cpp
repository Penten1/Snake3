#include "plocha.h"


Plocha::Plocha()
{
    PocetJablek = 2;
    pocetPoli = 30;
    sirkaPole = 32;
    h = new Had(this);
    score = h->delkaHada;
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
            score = h->delkaHada;
            if(score % 4 == 1 && score != 1){
                if(score < 101){
                    zdrzeni = zdrzeni - 5;
                }
            }
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
//    cary();
    cisla.kresli(score);
    barva(BILA);
    cara(0,0,0,obrazovkaVyska);
    cara(0,0,obrazovkaSirka,0);
    cara(obrazovkaSirka,0,obrazovkaSirka-1,obrazovkaVyska);
    cara(0,obrazovkaVyska,obrazovkaSirka,obrazovkaVyska-1);
}

void Plocha::gameOverKresli(){
    gameOver2.nacti("game over2.png");
    gameOver2.umisti(obrazovkaSirka / 2 - gameOver2.w / 2,obrazovkaVyska / 2 - gameOver2.h / 2);
    gameOver2.kresli();
    obrHighScore.nacti("high score2.png");
    obrHighScore.umisti(obrazovkaSirka/2 - obrHighScore.w/2,obrazovkaVyska/3*2-obrHighScore.h-20);
    obrHighScore.kresli();
    highScore.umisti(obrazovkaSirka / 2-25,obrazovkaVyska/3*2);
    highScore.kresli(nacteneScore);

}

void Plocha::uvodniMenu(){
    exit.nacti("exit.png");
    exit.umisti(0,0);
    exit.kresli();
}


