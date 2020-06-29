#include "Entidad.h"

Entidad::Entidad(){
	
}

Entidad::Entidad(Texture& t, Animacion* animacion, float x, float y) {
	this->animacion = animacion;
	this->x = x;
	this->y = y;
	estado = REPOSO;
	direccion = ABAJO;
	sprite.setTexture(t);
	sprite.setPosition(x,y);
}

Entidad::Entidad(sf::Texture& t, float x, float y, float dx, float dy) {
	this->x = x;
	this->y = y;
	this->dx = dx;
	this->dy = dy;
	estado = REPOSO;
	direccion = ABAJO;
	sprite.setTexture(t);
	sprite.setPosition(x,y);
}

Entidad::Entidad(Texture& t, Animacion* animacion, float x, float y, float dx, float dy) {
	this->x = x;
	this->y = y;
	this->dx = dx;
	this->dy = dy;
	this->animacion = animacion;
	estado = REPOSO;
	direccion = ABAJO;
	sprite.setTexture(t);
	sprite.setPosition(x,y);
}

Entidad::~Entidad() {
	
}

float Entidad::getX() { return x; }
float Entidad::getY() { return y; }
float Entidad::getDx() { return dx; }
float Entidad::getDy() { return dy; }
Hitbox* Entidad::getHitbox() { return hitbox; }

void Entidad::setX(float value) { x = value; }
void Entidad::setY(float value) { y = value; }
void Entidad::setDx(float value) { dx = value; }
void Entidad::setDy(float value) { dy = value; }