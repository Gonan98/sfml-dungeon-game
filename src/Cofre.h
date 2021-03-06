#ifndef _COFRE_H_
#define _COFRE_H_

#include "Entidad.h"

class Cofre : public Entidad {
private:
	bool desbloqueado;
public:
	Cofre();
	Cofre(Texture& t, Animacion* animacion, float x, float y);
	~Cofre();

	bool getDesbloqueado();
	void setDesbloqueado(bool value);

	void dibujar(sf::RenderWindow& w);
	void mover(Direccion dir);
};

#endif