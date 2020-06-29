#include "ListaMapas.h"

ListaMapas::ListaMapas() {
    indice = -1;
}

ListaMapas::~ListaMapas() {

}

Mapa* ListaMapas::mapaActual() {
    if (!lista.empty()) {
        return lista[indice];
    } else {
        return nullptr;
    }
}

void ListaMapas::nuevoMapa(Mapa* m) {
    lista.push_back(m);
    indice++;
}
void ListaMapas::mapaAnterior() {
    if (indice > 0)
        indice--;
}
void ListaMapas::mapaSiguiente() {
    if (indice < lista.size() - 1)
        indice++;
}