#include "Jugador.h"

Jugador::Jugador() : Entidad(){
	vidas = 5;
	puntaje = 0;
	nombre = "Player";
}
Jugador::Jugador(Animacion* animacion, int x, int y, int vidas, int puntaje, std::string nombre) : Entidad(animacion, x, y){
	this->vidas = vidas;
	this->puntaje = puntaje;
	this->nombre = nombre;
}
Jugador::~Jugador(){}

int Jugador::getVidas() { return vidas; }
int Jugador::getPuntaje() { return puntaje; }
std::string Jugador::getNombre() { return nombre; }

void Jugador::setVidas(int value) { vidas = value; }
void Jugador::setPuntaje(int value) { puntaje = value; }
void Jugador::setNombre(std::string value) { nombre = value; }

void Jugador::dibujar(sf::RenderWindow &w, int** matriz) {
	mover(matriz);
	animacion->update_jugador();
	animacion->sprite.setPosition((float)x, (float)y);
	w.draw(animacion->sprite);
}

void Jugador::mover(int** matriz) {
	switch (animacion->mov)
	{
	case Movimiento::ARRIBA:
		if (matriz[(y - dy) / 48][(x + dx) / 48] != 1 && matriz[(y - dy) / 48][(x + ancho - dx) / 48] != 1)
			y -= dy;
		break;
	case Movimiento::ABAJO:
		if (matriz[(y + alto) / 48][(x + dx) / 48] != 1 && matriz[(y + alto) / 48][(x + ancho - dx) / 48] != 1)
			y += dy;
		break;
	case Movimiento::DERECHA:
		if (matriz[(y) / 48][(x + ancho) / 48] != 1 && matriz[(y + alto - dy) / 48][(x + ancho) / 48] != 1)
			x += dx;
		break;
	case Movimiento::IZQUIERDA:
		if (matriz[(y) / 48][(x - dx) / 48] != 1 && matriz[(y + alto - dy) / 48][(x - dx) / 48] != 1)
			x -= dx;
		break;
	case Movimiento::NINGUNO:
		break;
	}
}

void Jugador::dañar(int daño) {
	vidas -= daño;
	if (vidas < 0)
		vidas = 0;
}