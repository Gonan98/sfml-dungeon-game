#pragma once
#include "Animacion.h"

class Entidad {
protected:
	int x;
	int y;
	int ancho;
	int alto;
	int dx;
	int dy;
	Animacion* animacion;
public:
	Entidad();
	Entidad(Animacion* animacion, int x, int y);
	Entidad(Animacion* animacion, int x, int y, int ancho, int alto, int dx, int dy);
	virtual ~Entidad();

	int getX();
	int getY();
	int getAncho();
	int getAlto();
	int getDx();
	int getDy();

	void setX(int value);
	void setY(int value);
	void setAncho(int value);
	void setAlto(int value);
	void setDx(int value);
	void setDy(int value);

	virtual void dibujar(sf::RenderWindow &w);
	virtual void mover();
};