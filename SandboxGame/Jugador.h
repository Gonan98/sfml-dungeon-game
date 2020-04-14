#pragma once
#include "Entidad.h"
#include <string>

class Jugador : public Entidad{
private:
	int vidas;
	int puntaje;
	std::string nombre;
public:
	Jugador();
	Jugador(Animacion* animacion, sf::Texture& t, int x, int y, int vidas, std::string nombre);
	~Jugador();

	int getVidas();
	int getPuntaje();
	std::string getNombre();

	void setVidas(int);
	void setPuntaje(int);
	void setNombre(std::string);

	void dibujar(sf::RenderWindow &w, int** matriz);
	void mover(int** matriz);
	void dañar(int daño);
};