#ifndef _ENEMIGO_H_
#define _ENEMIGO_H_

#include "Entidad.h"

class Enemigo : public Entidad{
protected:
	int damage;
	int vida;
public:
	Enemigo();
	Enemigo(Texture& t, Animacion* animacion, float x, float y);
	Enemigo(Texture& t, Animacion* animacion, float x, float y, float dx, float dy);
	virtual ~Enemigo();

	int getDamage();
	int getVida();

	void setDamage(int value);
	void setVida(int value);

	void dibujar(RenderWindow& w);
	void mover(Direccion dir);
};

#endif