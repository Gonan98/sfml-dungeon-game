#ifndef _NATURALEZA_H_
#define _NATURALEZA_H_

#include "Hitbox.h"

class Naturaleza {
protected:
	float x1;
	float y1;
	float x2;
	float y2;
	Sprite sprite;
	Hitbox* hbox;
public:
	Naturaleza();
	Naturaleza(Texture& t, float x, float y);
	~Naturaleza();

	float getX();
	float getY();
	Hitbox* getHitbox();

	void setX(float value);
	void setY(float value);

	virtual void dibujarInferior(RenderWindow& w) = 0;
	virtual void dibujarSuperior(RenderWindow& w) = 0;
};

#endif