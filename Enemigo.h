#ifndef _ENEMIGO_H_
#define _ENEMIGO_H_

#include "Entidad.h"

class Enemigo : public Entidad{
protected:
	int damage;
	int vida;
	int resistenciaFisica;
	int resistenciaMagica;
public:
	Enemigo();
	~Enemigo();

	int getDamage();
	int getVida();

	void setDamage(int value);
	void setVida(int value);

	void dibujar(sf::RenderWindow& w);
	void mover();
};

#endif