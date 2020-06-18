#include "Enemigo.h"

Enemigo::Enemigo() : Entidad(){
	daño = 0;
	vida = 5;
	tipo = TipoEnemigo::ORCO;
}
Enemigo::Enemigo(Animacion* animacion, sf::Texture &t, TipoEnemigo tipo, int x, int y) : Entidad(animacion, t, x, y) {
	vida = 5;
	daño = 0;
	this->tipo = tipo;
	switch (this->tipo)
	{
	case TipoEnemigo::ORCO:
		vida = 15;
		daño = 3;
		dx = dy = 6;
		break;
	case TipoEnemigo::ESQUELETO:
		vida = 10;
		daño = 3;
		dx = dy = 6;
		break;
	case TipoEnemigo::MURCIELAGO:
		vida = 5;
		daño = 2;
		dx = dy = 12;
		break;
	case TipoEnemigo::ESPECTRO:
		vida = 10;
		daño = 4;
		dx = dy = 8;
		break;
	case TipoEnemigo::SEGADOR:
		vida = 10;
		daño = 5;
		dx = dy = 8;
		break;
	}
}
Enemigo::~Enemigo(){}

int Enemigo::getDaño() { return daño; }
int Enemigo::getVida() { return vida; }
TipoEnemigo Enemigo::getTipo() { return tipo; }

void Enemigo::setDaño(int value) { daño = value; }
void Enemigo::setVida(int value) { vida = value; }

void Enemigo::dibujar(sf::RenderWindow& w, int** matriz){
	mover(matriz);
	sprite.setTextureRect(animacion->update(TipoEntidad::ENEMIGO));
	w.draw(sprite);
}
void Enemigo::mover(int** matriz){
	switch (animacion->getMovimiento())
	{
	case TipoMovimiento::ARRIBA:
		if (matriz[(y - dy) / 48][(x + dx) / 48] != 1 && matriz[(y - dy) / 48][(x + w - dx) / 48] != 1)
			y -= dy;
		else {
			direccion_random();
		}
		break;
	case TipoMovimiento::ABAJO:
		if (matriz[(y + h) / 48][(x + dx) / 48] != 1 && matriz[(y + h) / 48][(x + w - dx) / 48] != 1)
			y += dy;
		else {
			direccion_random();
		}
		break;
	case TipoMovimiento::DERECHA:
		if (matriz[(y) / 48][(x + w) / 48] != 1 && matriz[(y + h - dy) / 48][(x + w) / 48] != 1)
			x += dx;
		else {
			direccion_random();
		}
		break;
	case TipoMovimiento::IZQUIERDA:
		if (matriz[(y) / 48][(x - dx) / 48] != 1 && matriz[(y + h - dy) / 48][(x - dx) / 48] != 1)
			x -= dx;
		else {
			direccion_random();
		}
		break;
	case TipoMovimiento::NINGUNO:
		break;
	}
	sprite.setPosition((float)x, (float)y);
}

void Enemigo::direccion_contra(TipoMovimiento tipo) {
	switch (tipo)
	{
	case TipoMovimiento::NINGUNO:
		break;
	case TipoMovimiento::ARRIBA:
		animacion->setMovimiento(TipoMovimiento::ABAJO);
		break;
	case TipoMovimiento::ABAJO:
		animacion->setMovimiento(TipoMovimiento::ARRIBA);
		break;
	case TipoMovimiento::DERECHA:
		animacion->setMovimiento(TipoMovimiento::IZQUIERDA);
		break;
	case TipoMovimiento::IZQUIERDA:
		animacion->setMovimiento(TipoMovimiento::DERECHA);
		break;
	default:
		break;
	}
}

void Enemigo::direccion_random() {
	TipoMovimiento temp = animacion->getMovimiento();
	animacion->setMovimiento(TipoMovimiento(rand() % 4 + 1));
	if (temp == animacion->getMovimiento())
		direccion_contra(animacion->getMovimiento());
}