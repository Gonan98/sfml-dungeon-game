#include "Monte.h"

Monte::Monte() : Naturaleza() {

}
Monte::Monte(Texture& t, float x, float y) : Naturaleza(t, x, y) {
    this->y2 = y + 96;
    hbox = new Hitbox(x2,y2,144,48);
}
Monte::~Monte() {

}

void Monte::dibujarSuperior(RenderWindow& w) {
    sprite.setPosition(x1,y1);
    sprite.setTextureRect(IntRect(0,0,144,96));
    w.draw(sprite);
}

void Monte::dibujarInferior(RenderWindow& w) {
    hbox->dibujar(w);
    sprite.setPosition(x2,y2);
    sprite.setTextureRect(IntRect(0,96,144,48));
    w.draw(sprite);
}