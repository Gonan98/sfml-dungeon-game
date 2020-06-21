#include "Enemigo.h"

Enemigo::Enemigo() : Entidad(){
	damage = 0;
	vida = 5;
}

Enemigo::~Enemigo(){}

int Enemigo::getDamage() { return damage; }
int Enemigo::getVida() { return vida; }

void Enemigo::setDamage(int value) { damage = value; }
void Enemigo::setVida(int value) { vida = value; }

void Enemigo::dibujar(sf::RenderWindow& w){

}
void Enemigo::mover(){

}