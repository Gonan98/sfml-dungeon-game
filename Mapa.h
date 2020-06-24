#ifndef _MAPA_H_
#define _MAPA_H_

#include "SFML/Graphics.hpp"

using namespace sf;

#define FILA 15
#define COLUMNA 26
#define CUADRO 48

enum TipoTerreno {GRASS, TIERRA, ARENA, ADOQUIN};

class Mapa {
private:
	int dificultad;
	Sprite sprite;
public:
	Mapa(Texture& t);
	~Mapa();

	void dibujar(RenderWindow& w);
};

#endif