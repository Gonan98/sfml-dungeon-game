#ifndef _ARBOL_H_
#define _ARBOL_H_

#include "Naturaleza.h"

class Arbol : public Naturaleza {

public:
    Arbol();
    Arbol(Texture& t, float x, float y, float w, float h);
    ~Arbol();

    void dibujarSuperior(RenderWindow& w);
    void dibujarInferior(RenderWindow& w);
};

#endif