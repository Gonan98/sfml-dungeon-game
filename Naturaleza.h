#ifndef _NATURALEZA_H_
#define _NATURALEZA_H_

#include "SFML/Graphics.hpp"

class Naturaleza {
protected:
	float x;
	float y;
	float w;
	float h;
public:
	Naturaleza();
	~Naturaleza();

	float getX();
	float getY();
	float getAncho();
	float getAlto();

	void setX(float value);
	void setY(float value);
	void setAncho(float value);
	void setAlto(float value);

	void dibujar(sf::RenderWindow& w);
};

#endif