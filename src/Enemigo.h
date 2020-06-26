#ifndef _ENEMIGO_H_
#define _ENEMIGO_H_

#include "Entidad.h"

class Enemigo : public Entidad{
protected:
	int damage;
	int vida;
	Direccion direccion;
public:
	Enemigo();
	Enemigo(Texture& t, Animacion* animacion, float x, float y);
	Enemigo(Texture& t, Animacion* animacion, float x, float y, float dx, float dy);
	virtual ~Enemigo();

	int getDamage();
	int getVida();
	Direccion getDireccion();

	void setDamage(int value);
	void setVida(int value);
	void setDireccion(Direccion);

	void dibujar(RenderWindow& w);
	void mover(Direccion dir);
	void cambiarDireccion(Direccion& actual);
};

#endif