#ifndef _MONTE_H_
#define _MONTE_H_

#include "Naturaleza.h"

class Monte : public Naturaleza {
public:
    Monte();
    Monte(Texture& t, float x, float y);
    ~Monte();

    void dibujarSuperior(RenderWindow& w);
    void dibujarInferior(RenderWindow& w);
};

#endif