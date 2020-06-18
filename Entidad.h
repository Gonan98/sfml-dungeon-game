#pragma once
#include "Animacion.h"
#include "Hitbox.h"

class Entidad {
protected:
	int x;
	int y;
	int w;
	int h;
	int dx;
	int dy;
	sf::Sprite sprite;
	Animacion* animacion;
	sf::IntRect hitbox;
public:
	Entidad();
	Entidad(Animacion* animacion, sf::Texture &t, int x, int y);
	Entidad(Animacion* animacion, sf::Texture& t, int x, int y, sf::IntRect hitbox);
	Entidad(Animacion* animacion, sf::Texture& t, int x, int y, int w, int h);
	virtual ~Entidad();

	Animacion* getAnimacion();
	sf::IntRect getHitbox();
	int getX();
	int getY();
	int getW();
	int getH();
	int getDx();
	int getDy();

	void setX(int value);
	void setY(int value);
	void setW(int value);
	void setH(int value);
	void setDx(int value);
	void setDy(int value);
	void setHitbox(sf::IntRect hit);
	
	virtual void dibujar(sf::RenderWindow &w, int** matriz);
	virtual void mover(int** matriz);
};