#ifndef _MURCIELAGO_H_
#define _MURCIELAGO_H_

#include "Enemigo.h"

class Murcielago : public Enemigo {
public:
    Murcielago();
    Murcielago(Texture& t, Animacion* animacion, float x, float y);
    ~Murcielago();
};

#endif