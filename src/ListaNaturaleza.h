#ifndef _LISTANATURALEZA_H_
#define _LISTANATURALEZA_H_

#include <vector>
#include "Naturaleza.h"

class ListaNaturaleza {
private:
    std::vector<Naturaleza*> lista;
public:
    ListaNaturaleza();
    ~ListaNaturaleza();

    void agregar(Naturaleza* n);
    void dibujarSuperiores(RenderWindow& w);
    void dibujarInferiores(RenderWindow& w);
};

#endif