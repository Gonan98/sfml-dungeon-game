#pragma once
#include "Entidad.h"

class Cofre : public Entidad {
private:
	bool desbloqueado;
public:
	Cofre();
	Cofre(Animacion* a, sf::Texture &t, int x, int y, bool desbloqueado);
	Cofre(Animacion* a, sf::Texture& t, int x, int y, int w, int h, bool desbloqueado);
	~Cofre();

	bool getDesbloqueado();
	void setDesbloqueado(bool value);

	void dibujar(sf::RenderWindow& w);
};

