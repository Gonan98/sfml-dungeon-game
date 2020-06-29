#include "ListaEnemigos.h"

ListaEnemigos::ListaEnemigos(int max) {
    this->max = max;
    indice = -1;
    enemigos = new Enemigo*[max];
}

ListaEnemigos::~ListaEnemigos() {

}

int ListaEnemigos::getTotal() { return indice+1; }
Enemigo* ListaEnemigos::getEnemigo(int pos) { return enemigos[pos]; }
Enemigo* ListaEnemigos::getUltimo() {
    if (indice > -1) {
        return enemigos[indice];
    } else {
        return nullptr;
    }
}

void ListaEnemigos::agregar(Enemigo* e) {
    if (indice < max - 1) {
        indice++;
        enemigos[indice] = e;
    }
}
void ListaEnemigos::eliminar(int pos) {
    
}
void ListaEnemigos::dibujar(RenderWindow& w) {
    for (int i = 0; i < indice+1; i++)
        enemigos[i]->dibujar(w);
    
}
void ListaEnemigos::mover() {
    for (int i = 0; i < indice+1; i++)
        enemigos[i]->mover();
}

void ListaEnemigos::cambiarDirecciones() {
    for (int i = 0; i < indice+1; i++)
        enemigos[i]->cambiarDireccion();    
}