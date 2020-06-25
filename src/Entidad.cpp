#include "Entidad.h"

Entidad::Entidad(){
	x = 0.f;
	y = 0.f;
	w = 48.f;
	h = 48.f;
	dx = 8.f;
	dy = 8.f;
	estado = REPOSO;
	direccion = ABAJO;
	animacion = new Animacion();
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
	delete animacion;
}

float Entidad::getX() { return x; }
float Entidad::getY() { return y; }
float Entidad::getW() { return w; }
float Entidad::getH() { return h; }
float Entidad::getDx() { return dx; }
float Entidad::getDy() { return dy; }

void Entidad::setX(float value) { x = value; }
void Entidad::setY(float value) { y = value; }
void Entidad::setW(float value) { w = value; }
void Entidad::setH(float value) { h = value; }
void Entidad::setDx(float value) { dx = value; }
void Entidad::setDy(float value) { dy = value; }

void Entidad::dibujar(sf::RenderWindow& w) {
	w.draw(sprite);
}

void Entidad::mover(Direccion dir) {

}