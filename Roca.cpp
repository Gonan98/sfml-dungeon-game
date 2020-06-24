#include "Roca.h"

Roca::Roca() : Naturaleza() {}
Roca::Roca(Texture& t, float x, float y, float w, float h) : Naturaleza(t, x, y, w, h) {
    this->y2 = y + 48;
}
Roca::~Roca() {}

void Roca::dibujarSuperior(RenderWindow& w) {
    sprite.setPosition(x1,y1);
    sprite.setTextureRect(IntRect(0,0,96,48));
    w.draw(sprite);
}

void Roca::dibujarInferior(RenderWindow& w) {
    sprite.setPosition(x2,y2);
    sprite.setTextureRect(IntRect(0,48,96,48));
    w.draw(sprite);
}