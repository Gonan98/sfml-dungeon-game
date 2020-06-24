#include "Arbol.h"

Arbol::Arbol() : Naturaleza() {

}
Arbol::Arbol(Texture& t, float x, float y, float w, float h) : Naturaleza(t, x, y , w, h) {
    this->y2 = y + 96;
}
Arbol::~Arbol() {

}

void Arbol::dibujarSuperior(RenderWindow& w) {
    sprite.setPosition(x1,y1);
    sprite.setTextureRect(IntRect(0,0,48,96));
    w.draw(sprite);
}

void Arbol::dibujarInferior(RenderWindow& w) {
    sprite.setPosition(x2,y2);
    sprite.setTextureRect(IntRect(0,96,48,48));
    w.draw(sprite);
}