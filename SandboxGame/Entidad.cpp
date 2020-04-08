#include "Entidad.h"

Entidad::Entidad(){
	x = 0;
	y = 0;
	ancho = 48;
	alto = 48;
	dx = 0;
	dy = 0;
	animacion = new Animacion();
}

Entidad::Entidad(Animacion* animacion, int x, int y) {
	this->x = x;
	this->y = y;
	ancho = alto = 48;
	dx = dy = 8;
	this->animacion = animacion;
}

Entidad::Entidad(Animacion* animacion, int x, int y, int ancho, int alto, int dx, int dy) {
	this->x = x;
	this->y = y;
	this->ancho = ancho;
	this->alto = alto;
	this->dx = dx;
	this->dy = dy;
	this->animacion = animacion;
}
Entidad::~Entidad() {}

int Entidad::getX() { return x; }
int Entidad::getY() { return y; }
int Entidad::getAncho() { return ancho; }
int Entidad::getAlto() { return alto; }
int Entidad::getDx() { return dx; }
int Entidad::getDy() { return dy; }

void Entidad::setX(int value) { x = value; }
void Entidad::setY(int value) { y = value; }
void Entidad::setAncho(int value) { ancho = value; }
void Entidad::setAlto(int value) { alto = value; }
void Entidad::setDx(int value) { dx = value; }
void Entidad::setDy(int value) { dy = value; }

void Entidad::dibujar(sf::RenderWindow& w) {

}

void Entidad::mover() {

}