#include "Cofre.h"

Cofre::Cofre() : Entidad() {
	desbloqueado = false;
}

Cofre::~Cofre(){}

bool Cofre::getDesbloqueado() { return desbloqueado; }
void Cofre::setDesbloqueado(bool value) { desbloqueado = value; }

void Cofre::dibujar(sf::RenderWindow& w){

}