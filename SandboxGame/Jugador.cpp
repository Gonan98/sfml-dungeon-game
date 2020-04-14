#include "Jugador.h"

Jugador::Jugador() : Entidad(){
	vidas = 5;
	puntaje = 0;
	nombre = "Player";
}
Jugador::Jugador(Animacion* animacion, sf::Texture& t, int x, int y, int vidas, std::string nombre) : Entidad(animacion, t, x, y){
	this->vidas = vidas;
	this->puntaje = 0;
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
	sprite.setTextureRect(animacion->update(TipoEntidad::JUGADOR));
	w.draw(sprite);
}

void Jugador::mover(int** matriz) {
	switch (animacion->getTipoMovimiento())
	{
	case Movimiento::ARRIBA:
		if (matriz[(y - dy) / 48][(x + dx) / 48] != 1 && matriz[(y - dy) / 48][(x + ancho - 2*dx) / 48] != 1)
			y -= dy;
		break;
	case Movimiento::ABAJO:
		if (matriz[(y + alto) / 48][(x + dx) / 48] != 1 && matriz[(y + alto) / 48][(x + ancho - 2*dx) / 48] != 1)
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
	sprite.setPosition((float)x, (float)y);
}

void Jugador::dañar(int daño) {
	vidas -= daño;
	if (vidas < 0)
		vidas = 0;
}