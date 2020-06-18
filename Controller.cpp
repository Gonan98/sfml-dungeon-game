#include "Controller.h"

Controller::Controller(sf::Texture& tJugador, sf::Texture* tTerreno, sf::Texture* tEnemigos, sf::Texture* tNaturaleza, sf::Texture& tCofre) {
	this->tPlayer = tJugador;
	this->tEnemigos = tEnemigos;
	this->tTerrenos = tTerreno;
	this->tNaturaleza = tNaturaleza;
	this->tCofre = tCofre;
	Animacion* aJugador = new Animacion(CUADRO, CUADRO, 4, 3, 0.4f);
	player1 = new Jugador(aJugador, tJugador, CUADRO, CUADRO, 20, "Gonan");
	mapas.push_back(new Mapa(this->tTerrenos, this->tNaturaleza, this->tEnemigos, this->tCofre, TipoTerreno::GRASS));
	indiceMapa = 0;
	diff = Dificultad::MEDIO;
}
Controller::~Controller(){
	delete player1;
	delete[] tTerrenos;
	delete[] tEnemigos;
	delete[] tNaturaleza;
}

int Controller::getIndiceMapa() { return indiceMapa; }
Dificultad Controller::getDIff() { return diff; }
std::vector<Mapa*> Controller::getMapas() { return mapas; }
Jugador* Controller::getJugador1() { return player1; }

void Controller::dibujar_todo(sf::RenderWindow& w) {
	mapas[indiceMapa]->dibujar_fondo(w);
	mapas[indiceMapa]->dibujar_enemigos(w);
	mapas[indiceMapa]->dibujar_cofres(w);
	player1->dibujar(w, mapas[indiceMapa]->getMatriz());
	mapas[indiceMapa]->dibujar_decoracion(w);
}

void Controller::agregar_mapa(TipoTerreno tipo) {
	mapas.push_back(new Mapa(tTerrenos, tNaturaleza, tEnemigos, tCofre, tipo));
	indiceMapa++;
}
void Controller::mapa_siguiente() {
	if (indiceMapa < mapas.size() - 1)
		indiceMapa++;
}
void Controller::mapa_anterior() {
	if (indiceMapa > 0)
		indiceMapa--;
}
void Controller::jugadorAbreCofre() {

}