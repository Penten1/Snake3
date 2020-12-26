#include "ovoce.h"

#include <bits/stdc++.h>





Ovoce::Ovoce()
{
    poziceX =nahoda(29)+1;
    poziceY = nahoda(29)+1;
    sirkaOvoce = 32;
}

void Ovoce::kresli(){
    for(int i = 0; i < sirkaOvoce;i++){
        barva(CERVENA);
        cara(((poziceX-1) * sirkaOvoce) + i, (poziceY - 1) *sirkaOvoce,((poziceX-1) *sirkaOvoce) + i,((poziceY - 1) *sirkaOvoce) + sirkaOvoce);
    }
}
