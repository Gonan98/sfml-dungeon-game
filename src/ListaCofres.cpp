#include "ListaCofres.h"

ListaCofres::ListaCofres(int max) {
    this->max = max;
    indice = -1;
    cofres = new Cofre*[max];
}

ListaCofres::~ListaCofres() {

}

int ListaCofres::getSize() { return indice+1; }

bool ListaCofres::agregar(Cofre* c) {
    if (indice < max - 1) {
        indice++;
        cofres[indice] = c;
        return true;
    }
    return false;
}

void ListaCofres::dibujar(RenderWindow& w) {
    for (int i = 0; i < indice+1; i++) {
        cofres[i]->dibujar(w);
    }
}