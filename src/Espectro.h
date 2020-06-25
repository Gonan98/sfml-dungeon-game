#ifndef _ESPECTRO_H_
#define _ESPECTRO_H_

#include "Enemigo.h"

class Espectro : public Enemigo {
public:
    Espectro();
    Espectro(Texture& t, Animacion* animacion, float x, float y);
    ~Espectro();
};

#endif