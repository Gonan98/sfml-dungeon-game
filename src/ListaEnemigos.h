#ifndef _LISTAENEMIGOS_H_
#define _LISTAENEMIGOS_H_

#include <vector>
#include "Enemigo.h"

class ListaEnemigos
{
private:
    std::vector<Enemigo*> lista;
public:
    ListaEnemigos();
    ~ListaEnemigos();
    
    int getTotal();
    void agregar(Enemigo* e);
    void eliminar(int pos);
    void dibujar(RenderWindow& w);
    void mover(Direccion* dir);
    void cambiarDirecciones(Direccion* dir);
};

#endif