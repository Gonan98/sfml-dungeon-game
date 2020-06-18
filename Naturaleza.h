#pragma once
#include "SFML/Graphics.hpp"

enum class TipoNatural { ARBOL, MONTE, ROCA, PIEDRA };

class Naturaleza {
protected:
	int x;
	int y;
	int w;
	int h;
	sf::Sprite sprite;
public:
	Naturaleza();
	Naturaleza(sf::Texture* t, TipoNatural tipo, int x, int y);
	~Naturaleza();

	int getX();
	int getY();
	int getAncho();
	int getAlto();

	void setX(int value);
	void setY(int value);
	void setAncho(int value);
	void setAlto(int value);

	void dibujar(sf::RenderWindow& w);
};