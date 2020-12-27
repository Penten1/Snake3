#ifndef OVOCE_H
#define OVOCE_H
#include "plocha.h"
#include "grafika.h"
#include <stdlib.h>

class Plocha;
class Ovoce
{
public:
    Ovoce(Plocha *p);
    void kresli();
    int poziceX;
    int poziceY;
    Plocha *p;
};

#endif // OVOCE_H
