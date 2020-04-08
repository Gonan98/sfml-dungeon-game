#pragma once
#include "Mapa.h"
#include "Jugador.h"

enum class Dificultad { FACIL, MEDIO, DIFICIL };

class Controller {
private:
	std::vector<Mapa*> mapas;
	int indiceMapa;
	Jugador* player1;
	Dificultad diff;
	sf::Texture tPlayer;
	sf::Texture* tTerrenos;
	sf::Texture* tEnemigos;
	sf::Texture* tNaturaleza;
public:
	Controller(sf::Texture &tJugador, sf::Texture* tTerreno, sf::Texture* tEnemigos, sf::Texture* tNaturaleza);
	~Controller();

	int getIndiceMapa();
	Dificultad getDIff();
	std::vector<Mapa*> getMapas();
	Jugador* getJugador1();
	
	void dibujar_todo(sf::RenderWindow& w);
	void agregar_mapa(TipoTerreno tipo);
	void mapa_siguiente();
	void mapa_anterior();
};