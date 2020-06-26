#include "Piedra.h"

Piedra::Piedra() : Naturaleza() {}
Piedra::Piedra(Texture& t, float x, float y, float w, float h) : Naturaleza(t, x, y, w, h) {
    this->y2 = y + 24;
}
Piedra::~Piedra() {}

void Piedra::dibujar(RenderWindow& w) {
    w.draw(sprite);
}

void Piedra::dibujarSuperior(RenderWindow& w) {
    sprite.setPosition(x1,y1);
    sprite.setTextureRect(IntRect(0,0,48,24));
    w.draw(sprite);
}

void Piedra::dibujarInferior(RenderWindow& w) {
    sprite.setPosition(x2,y2);
    sprite.setTextureRect(IntRect(0,24,48,24));
    w.draw(sprite);
}