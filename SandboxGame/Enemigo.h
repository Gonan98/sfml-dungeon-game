#pragma once
#include "Entidad.h"

enum class TipoEnemigo {ORCO, ESQUELETO, MURCIELAGO, ESPECTRO, SEGADOR};

class Enemigo : public Entidad{
protected:
	int daño;
	int vida;
	TipoEnemigo tipo;
	void direccion_contra(Movimiento tipo);
public:
	Enemigo();
	Enemigo(Animacion* animacion, sf::Texture &t, TipoEnemigo tipo, int x, int y);
	~Enemigo();

	int getDaño();
	int getVida();
	TipoEnemigo getTipo();

	void setDaño(int value);
	void setVida(int value);

	void dibujar(sf::RenderWindow& w, int** matriz);
	void mover(int** matriz);
	void direccion_random();
};