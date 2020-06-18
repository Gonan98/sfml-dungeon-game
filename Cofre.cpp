#include "Cofre.h"

Cofre::Cofre() : Entidad() {
	desbloqueado = false;
}
Cofre::Cofre(Animacion* a, sf::Texture &t, int x, int y, bool desbloqueado) : Entidad(a, t, x, y) {
	this->desbloqueado = desbloqueado;
}
Cofre::Cofre(Animacion* a, sf::Texture& t, int x, int y, int w, int h, bool desbloqueado) : Entidad(a, t, x, y, w, h) {
	this->desbloqueado = desbloqueado;
}
Cofre::~Cofre(){}

bool Cofre::getDesbloqueado() { return desbloqueado; }
void Cofre::setDesbloqueado(bool value) { desbloqueado = value; }

void Cofre::dibujar(sf::RenderWindow& w){
	sprite.setPosition((float)x, (float)y);
	if (desbloqueado && !animacion->secuenciaFinalizada()) {
		sprite.setTextureRect(animacion->update());
	}
	w.draw(sprite);
}