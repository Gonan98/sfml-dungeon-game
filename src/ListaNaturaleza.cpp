#include "ListaNaturaleza.h"

ListaNaturaleza::ListaNaturaleza() {
    
}

ListaNaturaleza::~ListaNaturaleza() {

}

void ListaNaturaleza::agregar(Naturaleza* n) {
    lista.push_back(n);
}

void ListaNaturaleza::dibujarSuperiores(RenderWindow& w) {
    for (auto &natural : lista) {
        natural->dibujarSuperior(w);
    }
}

void ListaNaturaleza::dibujarInferiores(RenderWindow& w) {
    for (auto &natural : lista) {
        natural->dibujarInferior(w);
    }
}