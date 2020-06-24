#ifndef _PIEDRA_H_
#define _PIEDRA_H_

#include "Naturaleza.h"

class Piedra : public Naturaleza {
public:
    Piedra();
    Piedra(Texture& t, float x, float y, float w, float h);
    ~Piedra();

    void dibujar(RenderWindow& w);
    void dibujarSuperior(RenderWindow& w);
    void dibujarInferior(RenderWindow& w);
};

#endif