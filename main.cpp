#include <SDL/SDL.h>
#include <list>
#include "grafika.h"
#include "had.h"
#include "clanek.h"
#include "ovoce.h"
#include "plocha.h"
#include "math.h"


Plocha *p;
Clanek *clanek;

int otoc = 0;
int otoc2 = 0;




void Domecek(int bod1X,int bod1Y ,int bod2X, int bod2Y, int pocet, int barvaC){

    pocet++;
    if(pocet <= 10){
        barvaC = barvaC + 15;
        int a= 255-barvaC;
        int b= 255-barvaC*2;
        barva(b,a,0);
        int sirkaX = bod2X - bod1X;
        int sirkaY = bod1Y - bod2Y;
        int velikost = sqrt((sirkaX * sirkaX) + (sirkaY * sirkaY));
        int bod3X = bod1X - sirkaY;
        int bod3Y = bod1Y - sirkaX;
        int bod4X = bod2X - sirkaY;
        int bod4Y = bod2Y - sirkaX;
        int bod6X = bod3X - sirkaY;
        int bod6Y = bod3Y - sirkaX;
        int bod7X = bod4X - sirkaY;
        int bod7Y = bod4Y - sirkaX;
        //        int bod5X = (bod4X + bod6X *2)/3;
        int bod5X = (bod4X + bod6X)/2+10;
        int bod5Y = (bod3Y + bod7Y)/2;

        cara(bod1X,bod1Y,bod2X,bod2Y);
        cara(bod1X,bod1Y,bod3X,bod3Y);
        cara(bod2X,bod2Y,bod4X,bod4Y);
        cara(bod3X,bod3Y,bod5X,bod5Y);
        cara(bod4X,bod4Y,bod5X,bod5Y);
        //        cara(bod1X,bod1Y,bod4X,bod4Y);
        //        cara(bod2X,bod2Y,bod3X,bod3Y);
        cara(bod4X,bod4Y,bod3X,bod3Y);

        Domecek(bod3X,bod3Y,bod5X,bod5Y, pocet,barvaC);
        Domecek(bod5X,bod5Y,bod4X,bod4Y, pocet,barvaC);
    }
}

void stromecek(){
    Domecek(288,520,384,520, 0, 1);
    //    Domecek(stromekX,stromekY,stromekX+velikost/2,stromek2Y -velikost/2);
}
int main(int argc, char** argv)
{
    Obrazovka* obrazovka = Obrazovka::instance();
    int ac;
    p = new Plocha;



//    obrazovka->inicializuj(p->obrazovkaSirka, p->obrazovkaVyska, 0,SDL_FULLSCREEN);
         obrazovka->inicializuj(p->obrazovkaSirka, p->obrazovkaVyska, 0,0);
    //    SDL_WM_SetIcon(SDL_LoadBMP("icon.BMP"), NULL);
    SDL_WM_SetCaption("Snake by Matyáš Skřenek", NULL);

    bool menuKresli = true;

    p->cisla.nacti("cisla.png","1234567890");
    p->highScore.nacti("cisla.png","1234567890");

    while(1)
    {
        int t1 = SDL_GetTicks();
        int otocP;
        int otocP2;

        obrazovka->smaz();

        /* zacatek kresleni */

        otocP=otoc;
        otocP2=otoc2;




        //        stromecek();

        for(int i = 0;i < p->PocetJablek;i++){
            p->pole[i]->kresli();
        }

        p->h->kresli();

        otocP=otoc;
        otocP2=otoc2;




        if(p->h->gameOver()){
            p->h->gameOverTrue = true;
            p->fw = fopen("high score", "r");
            p->nacteneScore = 0;
            fscanf(p->fw,"%d",&p->nacteneScore);
            if(p->score > p->nacteneScore){
                p->fw = fopen("high score", "w");
                fprintf(p->fw,"%d",p->score);
                fclose(p->fw);
            }

            p->gameOverKresli();
        }




        otocP=otoc;
        otocP2=otoc2;
        p->kresli();

        if(menuKresli){
            p->uvodniMenu();
        }

        /* konec kresleni */
        obrazovka->aktualizuj();

        SDL_Event event;

        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    SDL_Quit();
                    return 0;
                case SDLK_a:
                    if(menuKresli){
                        menuKresli=false;
                    }
                    if(p->h->gameOverTrue == false){
                        if((p->h->rychlostX != p->h->rychlost && p->h->rychlostY != 0)|| (p->h->rychlostX == 0 && p->h->rychlostY == 0)){
                            otocP=otoc;
                            otocP2=otoc2;

                            if(otoc != 0 && otoc2 == 0){
                                otoc2 = 1;
                            }
                            if(otoc == 0 && otoc2 == 0){
                                otoc = 1;
                            }
                        }
                    }
                    break;
                case SDLK_w:
                    if(menuKresli){
                        menuKresli=false;
                    }
                    if(p->h->gameOverTrue == false){
                        if((p->h->rychlostX != 0 && p->h->rychlostY != p->h->rychlost) || (p->h->rychlostX == 0 && p->h->rychlostY == 0)){
                            if(otoc != 0 && otoc2 == 0){
                                otoc2 = 2;
                            }
                            if(otoc == 0 && otoc2 == 0){
                                otoc = 2;
                            }
                        }
                    }
                    break;

                case SDLK_s:
                    if(menuKresli){
                        menuKresli=false;
                    }
                    if(p->h->gameOverTrue == false){
                        if((p->h->rychlostX != 0 && p->h->rychlostY != -p->h->rychlost)){
                            if(otoc != 0 && otoc2 == 0){
                                otoc2 = 3;
                            }
                            if(otoc == 0 && otoc2 == 0){
                                otoc = 3;
                            }
                        }
                    }
                    break;
                case SDLK_d:
                    if(menuKresli){
                        menuKresli=false;
                    }
                    if(p->h->gameOverTrue == false){
                        if((p->h->rychlostX != -p->h->rychlost && p->h->rychlostY != 0) || (p->h->rychlostX == 0 && p->h->rychlostY == 0)){
                            ac = otoc;
                            if(otoc != 0 && otoc2 == 0){
                                otoc2 = 4;
                            }
                            if(otoc == 0 && otoc2 == 0){
                                otoc = 4;
                            }
                        }
                    }
                    break;
                case SDLK_RETURN:
                    if(menuKresli){
                        menuKresli=false;
                    }
                    //                    if(p->h->gameOverTrue==true){
                    //                        delete p->h;
                    //                        p->h = new Had(p);
                    //                        for(int i = 0; i <= p->PocetJablek; i++){
                    //                            delete p->pole[i];
                    //                            p->pole[i] = new Ovoce(p);
                    //                        }
                    //                        p->score = 0;
                    //                    }
                    if(p->h->gameOverTrue==true){
                        delete p;
                        p = new Plocha;
                    }
                    break;
                }
                break;
            case SDL_QUIT:
                SDL_Quit();
                return 0;

            }
        }
        p->h->pohyb();
        p->kolize();
        int t2 = SDL_GetTicks();
        int t3 = t2 - t1;//5
        int delay = p->zdrzeni - t3;
        if(delay < 0){
            delay = 0;
        }
        SDL_Delay(delay);
    }
}
