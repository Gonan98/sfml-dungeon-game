#include "Jugador.h"

Jugador::Jugador() : Entidad(){
	vidas = 20;
	puntaje = 0;
	nombre = "Player";
}

Jugador::Jugador(sf::Texture& t, std::string nombre) : Entidad(t, x, y, dx, dy) {
	vidas = 20;
	puntaje = 0;
	this->nombre = nombre;
}

Jugador::~Jugador(){}

int Jugador::getVidas() { return vidas; }
int Jugador::getPuntaje() { return puntaje; }
std::string Jugador::getNombre() { return nombre; }

void Jugador::setVidas(int value) { vidas = value; }
void Jugador::setPuntaje(int value) { puntaje = value; }
void Jugador::setNombre(std::string value) { nombre = value; }

void Jugador::dibujar(sf::RenderWindow &w) {
	w.draw(sprite);
}

void Jugador::mover() {
	
}

void Jugador::hurt(int damage) {
	vidas -= damage;
	if (vidas < 0)
		vidas = 0;
}

bool Jugador::interactuar() {
	return false;
}