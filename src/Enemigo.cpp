#include "Enemigo.h"

Enemigo::Enemigo() : Entidad(){
	damage = 1;
	vida = 5;
}

Enemigo::Enemigo(Texture& t, Animacion* animacion, float x, float y) : Entidad(t, animacion, x, y) {
	hitbox = new Hitbox(x+8,y+16,32,32);
	direccion = Direccion(rand()%4);
}

Enemigo::Enemigo(Texture& t, Animacion* animacion, float x, float y, float dx, float dy) : Entidad(t, animacion, x, y, dx, dy) {
	hitbox = new Hitbox(x+8,y+16,32,32);
	direccion = Direccion(rand()%4);
}

Enemigo::~Enemigo(){}

int Enemigo::getDamage() { return damage; }
int Enemigo::getVida() { return vida; }

void Enemigo::setDamage(int value) { damage = value; }
void Enemigo::setVida(int value) { vida = value; }

void Enemigo::dibujar(sf::RenderWindow& w){
	sprite.setTextureRect(animacion->rectActual());
	w.draw(sprite);
	//hitbox->dibujar(w);
}

void Enemigo::mover(){
	switch(direccion) {
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
	hitbox->posicionar(x+8,y+16);
	animacion->update(direccion);
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
	hitbox->posicionar(x+8,y+16);
	animacion->update(dir);
}

void Enemigo::cambiarDireccion() {
	Direccion dir = Direccion(rand()%4);
	if (dir == direccion) {
		switch (direccion)
		{
		case ARRIBA:
			direccion = ABAJO;
			break;
		case ABAJO:
			direccion = ARRIBA;
			break;
		case DERECHA:
			direccion = IZQUIERDA;
			break;
		case IZQUIERDA:
			direccion = DERECHA;
			break;
		default:
			break;
		}
	} else {
		direccion = dir;
	}
}