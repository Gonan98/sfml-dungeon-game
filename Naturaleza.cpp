#include "Naturaleza.h"

Naturaleza::Naturaleza(){
	x = 0;
	y = 0;
	w = 48;
	h = 48;
}

Naturaleza::~Naturaleza(){}

float Naturaleza::getX() { return x; }
float Naturaleza::getY() { return y; }
float Naturaleza::getAncho() { return w; }
float Naturaleza::getAlto() { return h; }

void Naturaleza::setX(float value) { x = value; }
void Naturaleza::setY(float value) { y = value; }
void Naturaleza::setAncho(float value) { w = value; }
void Naturaleza::setAlto(float value) { h = value; }

void Naturaleza::dibujar(sf::RenderWindow& w) {

}