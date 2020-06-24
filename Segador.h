#ifndef _SEGADOR_H_
#define _SEGADOR_H_

#include "Enemigo.h"

class Segador : public Enemigo {
public:
    Segador();
    Segador(Texture& t, Animacion* animacion, float x, float y);
    ~Segador();
};

#endif