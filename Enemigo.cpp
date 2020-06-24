#include "Enemigo.h"

Enemigo::Enemigo() : Entidad(){
	damage = 1;
	vida = 5;
}

Enemigo::Enemigo(Texture& t, Animacion* animacion, float x, float y) : Entidad(t, animacion, x, y) {

}

Enemigo::Enemigo(Texture& t, Animacion* animacion, float x, float y, float dx, float dy) : Entidad(t, animacion, x, y, dx, dy) {

}

Enemigo::~Enemigo(){}

int Enemigo::getDamage() { return damage; }
int Enemigo::getVida() { return vida; }

void Enemigo::setDamage(int value) { damage = value; }
void Enemigo::setVida(int value) { vida = value; }

void Enemigo::dibujar(sf::RenderWindow& w){
	sprite.setTextureRect(animacion->rectActual());
	w.draw(sprite);
}

void Enemigo::mover(Direccion dir){
	switch(dir) {
		case Direccion::ARRIBA:
			y -= dy;
			break;
		case Direccion::ABAJO:
			y += dy;
			break;
		case Direccion::DERECHA:
			x += dx;
			break;
		case Direccion::IZQUIERDA:
			x -= dx;
			break;
		default:
			break;
	}
	sprite.setPosition(x,y);
	animacion->update(dir);
}