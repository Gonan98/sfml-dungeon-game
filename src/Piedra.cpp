#include "Piedra.h"

Piedra::Piedra() : Naturaleza() {}
Piedra::Piedra(Texture& t, float x, float y) : Naturaleza(t, x, y) {
    this->y2 = y + 20;
    hbox = new Hitbox(x2,y2,48,20);
}
Piedra::~Piedra() {}

void Piedra::dibujar(RenderWindow& w) {
    w.draw(sprite);
}

void Piedra::dibujarSuperior(RenderWindow& w) {
    
    sprite.setPosition(x1,y1);
    sprite.setTextureRect(IntRect(0,0,48,20));
    w.draw(sprite);
}

void Piedra::dibujarInferior(RenderWindow& w) {
    
    sprite.setPosition(x2,y2);
    sprite.setTextureRect(IntRect(0,24,48,28));
    w.draw(sprite);
    //hbox->dibujar(w);
}