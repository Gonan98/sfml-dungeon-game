#ifndef _LISTANATURALEZA_H_
#define _LISTANATURALEZA_H_

#include <vector>
#include "Naturaleza.h"

class ListaNaturaleza {
private:
    Naturaleza** lista;
    int indice;
    int max;
public:
    ListaNaturaleza(int max);
    ~ListaNaturaleza();

    int getTotal();
    Naturaleza* getNaturaleza(int pos);
    Naturaleza* getUltimo();
    void agregar(Naturaleza* n);
    void dibujarSuperiores(RenderWindow& w);
    void dibujarInferiores(RenderWindow& w);
};

#endif