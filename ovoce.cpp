#include "ovoce.h"
#include <bits/stdc++.h>

Ovoce::Ovoce(Plocha *p)
{
    poziceX =nahoda(29)+1;
    poziceY = nahoda(29)+1;
    this->p = p;
}

void Ovoce::kresli(){
    for(int i = 0; i < p->sirkaPole;i++){
        barva(CERVENA);
        cara(((poziceX-1) * p->sirkaPole) + i, (poziceY - 1) *p->sirkaPole,((poziceX-1) *p->sirkaPole) + i,((poziceY - 1) *p->sirkaPole) + p->sirkaPole);
    }
}
