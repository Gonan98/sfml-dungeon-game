#include "Entidad.h"

Entidad::Entidad(){
	x = 0;
	y = 0;
	w = 48;
	h = 48;
	dx = 0;
	dy = 0;
	animacion = new Animacion();
	hitbox = sf::IntRect(0, 0, 0, 0);
}

Entidad::Entidad(Animacion* animacion, sf::Texture& t, int x, int y) {
	this->x = x;
	this->y = y;
	w = h = 48;
	dx = dy = 8;
	this->hitbox = sf::IntRect(x, y + h / 2, w, h / 2);
	this->animacion = animacion;
	this->sprite.setTexture(t);
	this->sprite.setTextureRect(this->animacion->frameActual());
}

Entidad::Entidad(Animacion* animacion, sf::Texture& t, int x, int y, sf::IntRect hitbox) {
	this->animacion = animacion;
	this->x = x;
	this->y = y;
	w = h = 48;
	dx = dy = 8;
	this->hitbox = hitbox;
	this->sprite.setTexture(t);
	this->sprite.setTextureRect(this->animacion->frameActual());
}

Entidad::Entidad(Animacion* animacion, sf::Texture& t, int x, int y, int w, int h) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->dx = 8;
	this->dy = 8;
	this->animacion = animacion;
	this->hitbox = sf::IntRect(x, y + h / 2, w, h / 2);
	this->sprite.setTexture(t);
	this->sprite.setTextureRect(this->animacion->frameActual());
}
Entidad::~Entidad() { delete animacion; }

Animacion* Entidad::getAnimacion() { return animacion; }
sf::IntRect Entidad::getHitbox() { return hitbox; }
int Entidad::getX() { return x; }
int Entidad::getY() { return y; }
int Entidad::getW() { return w; }
int Entidad::getH() { return h; }
int Entidad::getDx() { return dx; }
int Entidad::getDy() { return dy; }

void Entidad::setX(int value) { x = value; }
void Entidad::setY(int value) { y = value; }
void Entidad::setW(int value) { w = value; }
void Entidad::setH(int value) { h = value; }
void Entidad::setDx(int value) { dx = value; }
void Entidad::setDy(int value) { dy = value; }

void Entidad::setHitbox(sf::IntRect hit) { hitbox = hit; }

void Entidad::dibujar(sf::RenderWindow& w, int** matriz) {

}

void Entidad::mover(int** matriz) {

}