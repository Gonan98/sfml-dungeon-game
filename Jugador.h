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
	Jugador(sf::Texture& t, std::string nombre);
	~Jugador();

	int getVidas();
	int getPuntaje();
	std::string getNombre();

	void setVidas(int);
	void setPuntaje(int);
	void setNombre(std::string);

	void dibujar(sf::RenderWindow &w);
	void mover();
	void hurt(int damage);
	bool interactuar();
};

#endif