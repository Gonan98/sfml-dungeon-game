#include "Controller.h"

Controller::Controller(sf::Texture& tJugador, sf::Texture* tTerreno, sf::Texture* tEnemigos, sf::Texture* tNaturaleza) {
	this->tPlayer = tJugador;
	this->tEnemigos = tEnemigos;
	this->tTerrenos = tTerreno;
	this->tNaturaleza = tNaturaleza;
	Animacion* aJugador = new Animacion(this->tPlayer, CUADRO, CUADRO, 4, 3, 0.4f);
	player1 = new Jugador(aJugador, CUADRO, CUADRO, 20, 0, "Jugador1");
	mapas.push_back(new Mapa(this->tTerrenos, this->tNaturaleza, this->tEnemigos, TipoTerreno::GRASS));
	indiceMapa = 0;
	diff = Dificultad::MEDIO;
}
Controller::~Controller(){
	delete player1;
	for (int i = 0; i < mapas.size(); i++)
		delete mapas[i];
}

int Controller::getIndiceMapa() { return indiceMapa; }
Dificultad Controller::getDIff() { return diff; }
std::vector<Mapa*> Controller::getMapas() { return mapas; }
Jugador* Controller::getJugador1() { return player1; }

void Controller::dibujar_todo(sf::RenderWindow& w) {
	mapas[indiceMapa]->dibujar_fondo(w);
	mapas[indiceMapa]->dibujar_enemigos(w);
	player1->dibujar(w, mapas[indiceMapa]->getMatriz());
	mapas[indiceMapa]->dibujar_decoracion(w);
}

void Controller::agregar_mapa(TipoTerreno tipo){
	mapas.push_back(new Mapa(tTerrenos, tNaturaleza, tEnemigos, tipo));
	indiceMapa++;
}
void Controller::mapa_siguiente(){
	if (indiceMapa < mapas.size() - 1)
		indiceMapa++;
}
void Controller::mapa_anterior(){
	if (indiceMapa > 0)
		indiceMapa--;
}