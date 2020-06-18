#include "Naturaleza.h"

Naturaleza::Naturaleza(){
	x = 0;
	y = 0;
	w = 48;
	h = 48;
}
Naturaleza::Naturaleza(sf::Texture* t, TipoNatural tipo, int x, int y){
	switch (tipo)
	{
	case TipoNatural::ARBOL:
		sprite.setTexture(t[0]);
		w = 48;
		h = 144;
		break;
	case TipoNatural::MONTE:
		sprite.setTexture(t[1]);
		w = 144;
		h = 96;
		break;
	case TipoNatural::ROCA:
		sprite.setTexture(t[2]);
		w = 96;
		h = 48;
		break;
	case TipoNatural::PIEDRA:
		sprite.setTexture(t[3]);
		w = h = 48;
		break;
	default:
		sprite.setTexture(t[3]);
		w = h = 48;
		break;
	}
	this->x = x;
	this->y = y;
}
Naturaleza::~Naturaleza(){}

int Naturaleza::getX() { return x; }
int Naturaleza::getY() { return y; }
int Naturaleza::getAncho() { return w; }
int Naturaleza::getAlto() { return h; }

void Naturaleza::setX(int value) { x = value; }
void Naturaleza::setY(int value) { y = value; }
void Naturaleza::setAncho(int value) { w = value; }
void Naturaleza::setAlto(int value) { h = value; }

void Naturaleza::dibujar(sf::RenderWindow& w) {
	sprite.setPosition((float)x, (float)y);
	w.draw(sprite);
}