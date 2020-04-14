#pragma once
#include "Entidad.h"

class Cofre : public Entidad {
private:
	bool desbloqueado;
public:
	Cofre();
	Cofre(Animacion* a, int x, int y, bool desbloqueado);
	~Cofre();

	void dibujar(sf::RenderWindow& w);
};

