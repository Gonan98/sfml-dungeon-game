#ifndef _JUGADOR_H_
#define _JUGADOR_H_

#include "Entidad.h"
#include <SFML/Graphics.hpp>
#include <string>

class Jugador : public Entidad{
private:
	int vidas;
	int puntaje;
	std::string nombre;
public:
	Jugador();
	Jugador(Texture& t, Animacion* animacion, std::string nombre, float x, float y, float dx, float dy);
	~Jugador();

	int getVidas();
	int getPuntaje();
	std::string getNombre();

	void setVidas(int);
	void setPuntaje(int);
	void setNombre(std::string);

	void dibujar(sf::RenderWindow &w);
	void mover(Direccion dir);
	void hurt(int damage);
	bool interactuar();
};

#endif