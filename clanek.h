#ifndef CLANEK_H
#define CLANEK_H
#include "had.h"

class Had;
class Clanek
{
public:
    Clanek(float poziceX, float poziceY, Had *had);
    void kresli();
    float poziceX;
    float poziceY;
    float sirkaClanku;
    Had *had;
};

#endif // CLANEK_H
