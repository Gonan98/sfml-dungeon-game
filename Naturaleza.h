#ifndef _NATURALEZA_H_
#define _NATURALEZA_H_

#include "SFML/Graphics.hpp"

using namespace sf;

class Naturaleza {
protected:
	float x1;
	float y1;
	float x2;
	float y2;
	float w;
	float h;
	Sprite sprite;
public:
	Naturaleza();
	Naturaleza(Texture& t, float x, float y, float w, float h);
	~Naturaleza();

	float getX();
	float getY();
	float getAncho();
	float getAlto();

	void setX(float value);
	void setY(float value);
	void setAncho(float value);
	void setAlto(float value);

	virtual void dibujarInferior(RenderWindow& w);
	virtual void dibujarSuperior(RenderWindow& w);
};

#endif