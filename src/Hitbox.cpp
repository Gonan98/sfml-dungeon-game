#include "Hitbox.h"

Hitbox::Hitbox() {
    
}

Hitbox::Hitbox(float x, float y, float w, float h) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    rectangle.setPosition(Vector2f(x,y));
    rectangle.setSize(Vector2f(w, h));
}

Hitbox::~Hitbox() {

}

float Hitbox::getX() { return x; }
float Hitbox::getY() { return y; }
float Hitbox::getW() { return w; }
float Hitbox::getH() { return h; }

void Hitbox::setX(float value) { x = value; }
void Hitbox::setY(float value) { y = value; }
void Hitbox::setW(float value) { w = value; }
void Hitbox::setH(float value) { h = value; }

void Hitbox::dibujar(RenderWindow& w){
    w.draw(rectangle);
}

void Hitbox::posicionar(float x, float y) {
    rectangle.setPosition(x,y);
}