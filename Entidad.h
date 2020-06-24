#ifndef _ENTIDAD_H_
#define _ENTIDAD_H_

#include "Animacion.h"

enum Estado { REPOSO, MOVIMIENTO };

class Entidad {
protected:
	float x;
	float y;
	float w;
	float h;
	float dx;
	float dy;
	Animacion* animacion;
	Sprite sprite;
	Direccion direccion;
	Estado estado;
public:
	Entidad();
	Entidad(Texture& t, float x, float y, float dx, float dy);
	Entidad(Texture& t, Animacion* animacion, float x, float y);
	Entidad(Texture& t, Animacion* animacion, float x, float y, float dx, float dy);
	virtual ~Entidad();

	float getX();
	float getY();
	float getW();
	float getH();
	float getDx();
	float getDy();

	void setX(float value);
	void setY(float value);
	void setW(float value);
	void setH(float value);
	void setDx(float value);
	void setDy(float value);
	
	virtual void dibujar(sf::RenderWindow &w);
	virtual void mover(Direccion dir);
};

#endif