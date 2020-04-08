#pragma once
#include "Entidad.h"

enum class TipoEnemigo {ORCO, ESQUELETO, MURCIELAGO, ESPECTRO, SEGADOR};

class Enemigo : public Entidad{
protected:
	int daño;
	int vida;

	void direccion_contra(Movimiento tipo);
public:
	Enemigo();
	Enemigo(Animacion* animacion, TipoEnemigo tipo, int x, int y);
	virtual ~Enemigo();

	int getDaño();
	int getVida();

	void setDaño(int value);
	void setVida(int value);

	void dibujar(sf::RenderWindow& w, int** matriz);
	void mover(int** matriz);
	void direccion_random();
};