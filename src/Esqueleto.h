#ifndef _ESQUELETO_H_
#define _ESQUELETO_H_

#include "Enemigo.h"

class Esqueleto : public Enemigo {
public:
    Esqueleto();
    Esqueleto(Texture& t, Animacion* animacion, float x, float y);
    ~Esqueleto();
};

#endif