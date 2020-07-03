#ifndef _ENTIDAD_H_
#define _ENTIDAD_H_

#include "Animacion.h"
#include "Hitbox.h"

enum Estado { REPOSO, MOVIMIENTO };

class Entidad {
protected:
	float x;
	float y;
	float dx;
	float dy;
	Animacion* animacion;
	Hitbox* hitbox;
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
	float getDx();
	float getDy();
	Hitbox* getHitbox();
	Direccion getDireccion();

	void setDireccion(Direccion);
	void setX(float value);
	void setY(float value);
	void setDx(float value);
	void setDy(float value);
	
	virtual void dibujar(sf::RenderWindow &w) = 0;
	virtual void mover(Direccion dir) = 0;
};

#endif