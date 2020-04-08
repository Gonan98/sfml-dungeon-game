#include "Enemigo.h"

Enemigo::Enemigo() : Entidad(){
	daño = 0;
	vida = 5;
	tipo = TipoEnemigo::ORCO;
}
Enemigo::Enemigo(Animacion* animacion, TipoEnemigo tipo, int x, int y) : Entidad(animacion, x, y) {
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

void Enemigo::setDaño(int value) { daño = value; }
void Enemigo::setVida(int value) { vida = value; }

void Enemigo::dibujar(sf::RenderWindow& w, int** matriz){
	mover(matriz);
	animacion->update_enemigo();
	animacion->sprite.setPosition((float)x, (float)y);
	w.draw(animacion->sprite);
}
void Enemigo::mover(int** matriz){
	switch (animacion->mov)
	{
	case Movimiento::ARRIBA:
		if (matriz[(y - dy) / 48][(x + dx) / 48] != 1 && matriz[(y - dy) / 48][(x + ancho - dx) / 48] != 1)
			y -= dy;
		else {
			direccion_random();
		}
		break;
	case Movimiento::ABAJO:
		if (matriz[(y + alto) / 48][(x + dx) / 48] != 1 && matriz[(y + alto) / 48][(x + ancho - dx) / 48] != 1)
			y += dy;
		else {
			direccion_random();
		}
		break;
	case Movimiento::DERECHA:
		if (matriz[(y) / 48][(x + ancho) / 48] != 1 && matriz[(y + alto - dy) / 48][(x + ancho) / 48] != 1)
			x += dx;
		else {
			direccion_random();
		}
		break;
	case Movimiento::IZQUIERDA:
		if (matriz[(y) / 48][(x - dx) / 48] != 1 && matriz[(y + alto - dy) / 48][(x - dx) / 48] != 1)
			x -= dx;
		else {
			direccion_random();
		}
		break;
	case Movimiento::NINGUNO:
		break;
	}
}

void Enemigo::direccion_contra(Movimiento tipo) {
	switch (tipo)
	{
	case Movimiento::NINGUNO:
		break;
	case Movimiento::ARRIBA:
		animacion->mov = Movimiento::ABAJO;
		break;
	case Movimiento::ABAJO:
		animacion->mov = Movimiento::ARRIBA;
		break;
	case Movimiento::DERECHA:
		animacion->mov = Movimiento::IZQUIERDA;
		break;
	case Movimiento::IZQUIERDA:
		animacion->mov = Movimiento::DERECHA;
		break;
	default:
		break;
	}
}

void Enemigo::direccion_random() {
	Movimiento temp = animacion->mov;
	animacion->mov = Movimiento(rand() % 4 + 1);
	if (temp == animacion->mov)
		direccion_contra(animacion->mov);
}