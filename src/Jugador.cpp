#include "Jugador.h"

Jugador::Jugador() : Entidad(){
	vidas = 20;
	puntaje = 0;
	nombre = "Player";
}

Jugador::Jugador(Texture& t, Animacion* animacion, std::string nombre, float x, float y, float dx, float dy) : Entidad(t, animacion, x, y, dx, dy) {
	vidas = 20;
	puntaje = 0;
	this->nombre = nombre;
	hitbox = new Hitbox(x+8,y+16,32,32);
}

Jugador::~Jugador() {}

int Jugador::getVidas() { return vidas; }
int Jugador::getPuntaje() { return puntaje; }
std::string Jugador::getNombre() { return nombre; }

void Jugador::setVidas(int value) { vidas = value; }
void Jugador::setPuntaje(int value) { puntaje = value; }
void Jugador::setNombre(std::string value) { nombre = value; }

void Jugador::dibujar(sf::RenderWindow &w) {
	sprite.setTextureRect(animacion->rectActual());
	w.draw(sprite);
	//hitbox->dibujar(w);
}

void Jugador::mover(Direccion dir) {
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

void Jugador::hurt(int damage) {
	vidas -= damage;
	if (vidas < 0)
		vidas = 0;
}

bool Jugador::interactuar() {
	return false;
}