#include "ListaNaturaleza.h"

ListaNaturaleza::ListaNaturaleza(int max) {
    this->max = max;
    indice = -1;
    lista = new Naturaleza*[this->max];
}

ListaNaturaleza::~ListaNaturaleza() {

}

void ListaNaturaleza::agregar(Naturaleza* n) {
    if (indice < max-1) {
        indice++;
        lista[indice] = n;
    }
}

void ListaNaturaleza::dibujarSuperiores(RenderWindow& w) {
    for (int i = 0; i < indice+1; i++)
        lista[i]->dibujarSuperior(w);
}

void ListaNaturaleza::dibujarInferiores(RenderWindow& w) {
    for (int i = 0; i < indice+1; i++)
        lista[i]->dibujarInferior(w);
}

int ListaNaturaleza::getTotal() { return indice+1; }
Naturaleza* ListaNaturaleza::getNaturaleza(int pos) { return lista[pos]; }
Naturaleza* ListaNaturaleza::getUltimo() { 
    if (indice > -1) {
        return lista[indice];
    } else {
        return nullptr;
    }
}