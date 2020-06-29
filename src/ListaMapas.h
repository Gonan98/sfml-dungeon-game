#ifndef _LISTAMAPA_H_
#define _LISTAMAPA_H_

#include <vector>
#include "Mapa.h"

class ListaMapas {
private:
    std::vector<Mapa*> lista;
    int indice;
public:
    ListaMapas();
    ~ListaMapas();

    Mapa* mapaActual();
    void nuevoMapa(Mapa* m);
    void mapaAnterior();
    void mapaSiguiente();
};

#endif