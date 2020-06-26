#include "Mapa.h"

bool Mapa::_regionVacia(int i, int j, int tipo) {
	if (tipo == 0) {
		return matriz[i][j] == 0;
	} else if (tipo == 1) {
		return matriz[i][j] == 0 && matriz[i + 1][j] == 0 && matriz[i + 2][j] == 0;
	} else if (tipo == 2) {
		return matriz[i][j] == 0 &&
		matriz[i][j+1] == 0 &&
		matriz[i][j+2] == 0 &&
		matriz[i+1][j] == 0 && 
		matriz[i+1][j+1] == 0 &&
		matriz[i+1][j+2] == 0 &&
		matriz[i+2][j] == 0 && 
		matriz[i+2][j+1] == 0 &&
		matriz[i+2][j+2] == 0;
	} else if (tipo == 3) {
		return matriz[i][j] == 0 &&
		matriz[i][j+1] == 0 &&
		matriz[i+1][j] == 0 &&
		matriz[i+1][j+1] == 0;
	} else {
		return false;
	}	
}

void Mapa::_posicionarEnemigos(Texture* tEnemigos) {

}

void Mapa::_posicionarNaturaleza(Texture* tNaturaleza) {
	for (int i = 0; i < FILA; i++) {
		for (int j = 0; j < COLUMNA; j++) {
			if (matriz[i][j] == 1) {
				natures->agregar(new Piedra(tNaturaleza[3], j*CUADRO, i*CUADRO,0,0));
			} else if (matriz[i][j] == 2) {
				natures->agregar(new Arbol(tNaturaleza[0], j*CUADRO, i*CUADRO,0,0));
			} else if (matriz[i][j] == 3) {
				natures->agregar(new Monte(tNaturaleza[1], j*CUADRO, i*CUADRO,0,0));
			} else if (matriz[i][j] == 4) {
				natures->agregar(new Roca(tNaturaleza[2], j*CUADRO, i*CUADRO,0,0));
			}
		}
	}
}

void Mapa::_generarMatriz() {

	matriz = new int*[FILA];
	for (int i = 0; i < FILA; i++) {
		matriz[i] = new int[COLUMNA];
		for (int j = 0; j < COLUMNA; j++) {
			matriz[i][j] = 0;
		}
	}

	for (int i = 0; i < FILA; i++) {
		for (int j = 0; j < COLUMNA; j++) {
			if (i == 0 || j == 0 || i == FILA - 1 || j == COLUMNA - 1) {
				matriz[i][j] = 1;
			} else if (i > 0 && i < FILA - 3 && j > 0 && j < COLUMNA - 3) {
				if (rand() % 3 == 1) {
					int tipo = rand()%4;
					if (tipo == 0 && _regionVacia(i,j,tipo)) {
						matriz[i][j] = 1;
					} else if (tipo == 1 && _regionVacia(i,j,tipo)) { // Arbol
						matriz[i][j] = 2;
						matriz[i+1][j] = 9;
						matriz[i+2][j] = 9;
					} else if (tipo == 2 && _regionVacia(i,j,tipo)) { // Monte
						matriz[i][j] = 3;
						matriz[i][j+1] = 9;
						matriz[i][j+2] = 9;
						matriz[i+1][j] = 9;
						matriz[i+1][j+1] = 9;
						matriz[i+1][j+2] = 9;
						matriz[i+2][j] = 9;
						matriz[i+2][j+1] = 9;
						matriz[i+2][j+2] = 9;
					} else if (tipo == 3 && _regionVacia(i,j,tipo)) { // Roca
						matriz[i][j] = 4;
						matriz[i][j+1] = 9;
						matriz[i+1][j] = 9;
						matriz[i+1][j+1] = 9;				
					}
				}
			}
		}
	}
}

Mapa::Mapa(Texture& t, Texture* tNaturaleza, Texture* tEnemigos) {
	natures = new ListaNaturaleza();
	enemies = new ListaEnemigos();	
	_generarMatriz();
	_posicionarNaturaleza(tNaturaleza);
	sprite.setTexture(t);
	sprite.setTextureRect(IntRect(0,0,COLUMNA*CUADRO,FILA*CUADRO));
}

Mapa::~Mapa() {
	delete natures;
	delete enemies;
	
	for (int i = 0; i < FILA; i++)
		delete[] matriz[i];
	delete[] matriz;
	
}

void Mapa::dibujar(RenderWindow& w) {
	w.draw(sprite);
}

void Mapa::dibujarNaturalezaSuperior(RenderWindow& w) {
	natures->dibujarSuperiores(w);
}

void Mapa::dibujarNaturalezaInferior(RenderWindow& w) {
	natures->dibujarInferiores(w);
}