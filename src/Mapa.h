#ifndef _MAPA_H_
#define _MAPA_H_

#include "ListaEnemigos.h"
#include "ListaNaturaleza.h"
#include "ListaCofres.h"
#include "Roca.h"
#include "Piedra.h"
#include "Arbol.h"
#include "Monte.h"
#include "Orco.h"
#include "Esqueleto.h"
#include "Murcielago.h"
#include "Segador.h"
#include "Espectro.h"
#include <fstream>

using namespace sf;

#define FILA 15
#define COLUMNA 26
#define CUADRO 48

enum TipoTerreno {GRASS, TIERRA, ARENA, ADOQUIN};

class Mapa {
private:
	ListaNaturaleza* natures;
	ListaEnemigos* enemies;
	ListaCofres* cofres;
	int** matriz;
	int dificultad;
	Sprite sprite;

	void _posicionarCofres(Texture& tCofre);
	void _posicionarEnemigos(Texture* tEnemigos);
	void _posicionarNaturaleza(Texture* tNaturaleza);
	void _generarMatriz();
	bool _regionVacia(int i, int j, int tipo);
public:
	Mapa(Texture& t, Texture* tNaturaleza, Texture* tEnemigos, Texture& tCofres);
	~Mapa();

	int getTotalEnemigos();
	int getTotalNatural();

	ListaEnemigos* getEnemigos();
	ListaNaturaleza* getNaturalezas();
	ListaCofres* getCofres();

	void dibujar(RenderWindow& w);
	void dibujarNaturalezaSuperior(RenderWindow& w);
	void dibujarNaturalezaInferior(RenderWindow& w);
	void dibujarCofres(RenderWindow& w);
	void guardar();
	void dibujarEnemigos(RenderWindow& w);
	void moverEnemigos();
	void cambiarDireccionEnemigos();
	void colisionEnemigoDecoracion();
};

#endif