#include "Naturaleza.h"

Naturaleza::Naturaleza(){
	x1 = 0;
	y1 = 0;
	x2 = 24;
	y2 = 24;
	w = 48;
	h = 48;
}

Naturaleza::Naturaleza(Texture& t, float x, float y, float w, float h) {
	this->x1 = x;
	this->y1 = y;
	this->w = w;
	this->h = h;
	this->x2 = x;
	sprite.setTexture(t);
	sprite.setPosition(x,y);
}

Naturaleza::~Naturaleza(){}

float Naturaleza::getX() { return x1; }
float Naturaleza::getY() { return y1; }
float Naturaleza::getAncho() { return w; }
float Naturaleza::getAlto() { return h; }

void Naturaleza::setX(float value) { x1 = value; }
void Naturaleza::setY(float value) { y1 = value; }
void Naturaleza::setAncho(float value) { w = value; }
void Naturaleza::setAlto(float value) { h = value; }

void Naturaleza::dibujarInferior(RenderWindow& w) {

}
void Naturaleza::dibujarSuperior(RenderWindow& w) {

}