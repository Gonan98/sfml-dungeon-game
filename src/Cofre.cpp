#include "Cofre.h"

Cofre::Cofre() : Entidad() {
	desbloqueado = false;
}

Cofre::Cofre(Texture& t, Animacion* animacion, float x, float y) : Entidad(t, animacion, x, y) {
	desbloqueado = false;
	hitbox = new Hitbox(x,y+16, 48, 32);
	sprite.setTexture(t);
	sprite.setPosition(x,y);
	sprite.setTextureRect(animacion->rectActual());
}

Cofre::~Cofre(){}

bool Cofre::getDesbloqueado() { return desbloqueado; }
void Cofre::setDesbloqueado(bool value) { desbloqueado = value; }

void Cofre::dibujar(sf::RenderWindow& w){
	w.draw(sprite);
}

void Cofre::mover(Direccion dir) {

}