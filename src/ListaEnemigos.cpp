#include "ListaEnemigos.h"

ListaEnemigos::ListaEnemigos() {

}

ListaEnemigos::~ListaEnemigos() {
    for(auto &e : lista) {
        delete e;
    }
    lista.clear();
}

int ListaEnemigos::getTotal() { return lista.size(); }
void ListaEnemigos::agregar(Enemigo* e) {
    lista.push_back(e);
}
void ListaEnemigos::eliminar(int pos) {
    lista.erase(lista.begin() + pos);
}
void ListaEnemigos::dibujar(RenderWindow& w) {
    for(Enemigo* &e : lista) {
        e->dibujar(w);
    }
}
void ListaEnemigos::mover(Direccion* dir) {
    int i = 0;
    for(Enemigo* &e : lista) {
        e->mover(dir[i]);
        i++;
    }
}