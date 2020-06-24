#include "Monte.h"

Monte::Monte() : Naturaleza() {

}
Monte::Monte(Texture& t, float x, float y, float w, float h) : Naturaleza(t, x, y, w, h) {
    this->y2 = y + 96;
}
Monte::~Monte() {

}

void Monte::dibujarInferior(RenderWindow& w) {
    sprite.setPosition(x2,y2);
    sprite.setTextureRect(IntRect(0,96,144,48));
    w.draw(sprite);
}
void Monte::dibujarSuperior(RenderWindow& w) {
    sprite.setPosition(x1,y1);
    sprite.setTextureRect(IntRect(0,0,144,96));
    w.draw(sprite);
}