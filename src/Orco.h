#ifndef _ORCO_H_
#define _ORCO_H_

#include "Enemigo.h"

class Orco : public Enemigo {
public:
    Orco();
    Orco(Texture& t, Animacion* animacion, float x, float y);
    ~Orco();
};

#endif