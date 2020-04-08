#pragma once
#include "SFML/Graphics.hpp"
#include "Naturaleza.h"
#include "Enemigo.h"
#include <vector>

#define FILA 15
#define COLUMNA 26
#define CUADRO 48

enum class TipoTerreno {GRASS, TIERRA, ARENA, ADOQUIN};

class Mapa {
private:
	int** matrizMapa;
	std::vector<Naturaleza*> decoracion;
	std::vector<Enemigo*> enemigos;
	sf::Sprite sprite;

	bool regionVacia(int i, int j);
	void inicializar_matriz();
	void colocar_decoracion(sf::Texture* naturales);
	void colocar_enemigos(sf::Texture* tEnemigos);
public:
	Mapa();
	Mapa(sf::Texture* terrenos, sf::Texture* naturales, sf::Texture* tEnemigos, TipoTerreno tipo);
	~Mapa();

	int** getMatriz();

	void dibujar_fondo(sf::RenderWindow& w);

	void dibujar_decoracion(sf::RenderWindow& w);

	void dibujar_enemigos(sf::RenderWindow& w);
};