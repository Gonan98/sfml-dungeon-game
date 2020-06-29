#ifndef _LISTAENEMIGOS_H_
#define _LISTAENEMIGOS_H_

#include <vector>
#include "Enemigo.h"

class ListaEnemigos
{
private:
    Enemigo** enemigos;
    int indice;
    int max;
public:
    ListaEnemigos(int max);
    ~ListaEnemigos();
    
    int getTotal();
    Enemigo* getEnemigo(int pos);
    Enemigo* getUltimo();

    void agregar(Enemigo* e);
    void eliminar(int pos);
    void dibujar(RenderWindow& w);
    void mover();
    void cambiarDirecciones();
};

#endif