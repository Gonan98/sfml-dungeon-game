#ifndef _LISTACOFRES_H_
#define _LISTACOFRES_H_

#include "Cofre.h"

class ListaCofres {
private:
    Cofre** cofres;
    int indice;
    int max;
public:
    ListaCofres(int max);
    ~ListaCofres();

    int getSize();

    bool agregar(Cofre* c);
    void dibujar(RenderWindow& w);
};

#endif