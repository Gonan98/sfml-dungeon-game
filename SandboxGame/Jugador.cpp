#include "Jugador.h"

Jugador::Jugador() : Entidad(){
	vidas = 5;
	puntaje = 0;
	nombre = "Player";
}
Jugador::Jugador(Animacion* animacion, sf::Texture& t, int x, int y, int vidas, std::string nombre) : Entidad(animacion, t, x, y) {
	this->vidas = vidas;
	this->puntaje = 0;
	this->nombre = nombre;
	direccion = TipoMovimiento::ABAJO;
}
Jugador::~Jugador(){}

int Jugador::getVidas() { return vidas; }
int Jugador::getPuntaje() { return puntaje; }
TipoMovimiento Jugador::getDireccion() { return direccion; }
std::string Jugador::getNombre() { return nombre; }

void Jugador::setVidas(int value) { vidas = value; }
void Jugador::setPuntaje(int value) { puntaje = value; }
void Jugador::setNombre(std::string value) { nombre = value; }

void Jugador::dibujar(sf::RenderWindow &w, int** matriz) {
	sf::RectangleShape r = sf::RectangleShape(sf::Vector2f(hitbox.width, hitbox.height));

	//r.setPosition(x, y + h/2);
	mover(matriz);
	sprite.setTextureRect(animacion->update(TipoEntidad::JUGADOR));
	w.draw(sprite);
	//w.draw(r);
}

void Jugador::mover(int** matriz) {
	switch (animacion->getMovimiento())
	{
	case TipoMovimiento::ARRIBA:
		if (matriz[(y - dy) / 48][(x + dx) / 48] != 1 && matriz[(y - dy) / 48][(x + w - 2*dx) / 48] != 1)
			y -= dy;
		direccion = TipoMovimiento::ARRIBA;
		break;
	case TipoMovimiento::ABAJO:
		if (matriz[(y + h) / 48][(x + dx) / 48] != 1 && matriz[(y + h) / 48][(x + w - 2*dx) / 48] != 1)
			y += dy;
		direccion = TipoMovimiento::ABAJO;
		break;
	case TipoMovimiento::DERECHA:
		if (matriz[(y + dy) / 48][(x + w) / 48] != 1 && matriz[(y + h - dy) / 48][(x + w) / 48] != 1)
			x += dx;
		direccion = TipoMovimiento::DERECHA;
		break;
	case TipoMovimiento::IZQUIERDA:
		if (matriz[(y + dy) / 48][(x - dx) / 48] != 1 && matriz[(y + h - dy) / 48][(x - dx) / 48] != 1)
			x -= dx;
		direccion = TipoMovimiento::IZQUIERDA;
		break;
	case TipoMovimiento::NINGUNO:
		break;
	}
	sprite.setPosition((float)x, (float)y);
}

void Jugador::dañar(int daño) {
	vidas -= daño;
	if (vidas < 0)
		vidas = 0;
}

bool Jugador::interactuar(int** matriz) {
	return false;
}