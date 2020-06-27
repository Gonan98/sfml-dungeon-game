#include "Naturaleza.h"

Naturaleza::Naturaleza(){
	x1 = 0;
	y1 = 0;
	x2 = 24;
	y2 = 24;
}

Naturaleza::Naturaleza(Texture& t, float x, float y) {
	this->x1 = x;
	this->y1 = y;
	this->x2 = x;
	sprite.setTexture(t);
	sprite.setPosition(x,y);
}

Naturaleza::~Naturaleza(){}

float Naturaleza::getX() { return x1; }
float Naturaleza::getY() { return y1; }
Hitbox* Naturaleza::getHitbox() { return hbox; }

void Naturaleza::setX(float value) { x1 = value; }
void Naturaleza::setY(float value) { y1 = value; }