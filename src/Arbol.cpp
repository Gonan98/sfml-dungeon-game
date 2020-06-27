#include "Arbol.h"

Arbol::Arbol() : Naturaleza() {

}
Arbol::Arbol(Texture& t, float x, float y) : Naturaleza(t, x, y) {
    this->y2 = y + 96;
    hbox = new Hitbox(x2,y2,48,48);
}
Arbol::~Arbol() {

}

void Arbol::dibujarSuperior(RenderWindow& w) {
    
    sprite.setPosition(x1,y1);
    sprite.setTextureRect(IntRect(0,0,48,96));
    w.draw(sprite);
}

void Arbol::dibujarInferior(RenderWindow& w) {
    hbox->dibujar(w);
    sprite.setPosition(x2,y2);
    sprite.setTextureRect(IntRect(0,96,48,48));
    w.draw(sprite);
}