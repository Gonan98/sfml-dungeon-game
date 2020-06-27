#ifndef _ROCA_H_
#define _ROCA_H_

#include "Naturaleza.h"

class Roca : public Naturaleza {
public:
    Roca();
    Roca(Texture& t, float x, float y);
    ~Roca();

    void dibujarSuperior(RenderWindow& w);
    void dibujarInferior(RenderWindow& w);
};

#endif