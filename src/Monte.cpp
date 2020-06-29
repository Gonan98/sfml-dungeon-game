#include "Monte.h"

Monte::Monte() : Naturaleza() {

}
Monte::Monte(Texture& t, float x, float y) : Naturaleza(t, x, y) {
    this->y2 = y + 48;
    hbox = new Hitbox(x2,y2,144,80);
}
Monte::~Monte() {

}

void Monte::dibujarSuperior(RenderWindow& w) {
    sprite.setPosition(x1,y1);
    sprite.setTextureRect(IntRect(0,0,144,48));
    w.draw(sprite);
}

void Monte::dibujarInferior(RenderWindow& w) {
    
    sprite.setPosition(x2,y2);
    sprite.setTextureRect(IntRect(0,48,144,96));
    w.draw(sprite);
    //hbox->dibujar(w);
}