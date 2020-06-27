#include "Mapa.h"

bool Mapa::_regionVacia(int i, int j, int tipo) {
	if (tipo == 1) {
		return matriz[i][j] == 0;
	} else if (tipo == 2) {
		return matriz[i][j] == 0 && matriz[i + 1][j] == 0 && matriz[i + 2][j] == 0;
	} else if (tipo == 3) {
		return matriz[i][j] == 0 &&
		matriz[i][j+1] == 0 &&
		matriz[i][j+2] == 0 &&
		matriz[i+1][j] == 0 && 
		matriz[i+1][j+1] == 0 &&
		matriz[i+1][j+2] == 0 &&
		matriz[i+2][j] == 0 && 
		matriz[i+2][j+1] == 0 &&
		matriz[i+2][j+2] == 0;
	} else if (tipo == 4) {
		return matriz[i][j] == 0 &&
		matriz[i][j+1] == 0 &&
		matriz[i+1][j] == 0 &&
		matriz[i+1][j+1] == 0;
	} else {
		return false;
	}	
}

void Mapa::_posicionarEnemigos(Texture* tEnemigos) {
	int cantidad = rand()%4 + 3;
	for (int i = 0; i < cantidad; i++) {
		int tipo = rand()%5;
		switch (tipo)
		{
		case 0:
			enemies->agregar(new Orco(tEnemigos[tipo], new Animacion(12, 4, 3, 0.2f, 2, 0, 1, 3), 48, 48));
			break;
		case 1:
			enemies->agregar(new Esqueleto(tEnemigos[tipo], new Animacion(12, 4, 3, 0.2f, 2, 0, 1, 3), 96, 48));
			break;
		case 2:
			enemies->agregar(new Murcielago(tEnemigos[tipo], new Animacion(12, 4, 3, 0.2f, 2, 0, 1, 3), 144, 48));
			break;
		case 3:
			enemies->agregar(new Espectro(tEnemigos[tipo], new Animacion(12, 4, 3, 0.2f, 2, 0, 1, 3), 196, 48));
			break;
		case 4:
			enemies->agregar(new Segador(tEnemigos[tipo], new Animacion(12, 4, 3, 0.2f, 2, 0, 1, 3), 244, 48));
			break;
		default:
			break;
		}
	}
}

void Mapa::_posicionarNaturaleza(Texture* tNaturaleza) {
	for (int i = 0; i < FILA; i++) {
		for (int j = 0; j < COLUMNA; j++) {
			if (matriz[i][j] == 1) {
				natures->agregar(new Piedra(tNaturaleza[3], j*CUADRO, i*CUADRO));
			} else if (matriz[i][j] == 2) {
				natures->agregar(new Arbol(tNaturaleza[0], j*CUADRO, i*CUADRO));
			} else if (matriz[i][j] == 3) {
				natures->agregar(new Monte(tNaturaleza[1], j*CUADRO, i*CUADRO));
			} else if (matriz[i][j] == 4) {
				natures->agregar(new Roca(tNaturaleza[2], j*CUADRO, i*CUADRO));
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
					int tipo = rand()%4 +1;
					if (tipo == 1 && _regionVacia(i,j,tipo)) {
						matriz[i][j] = tipo;
					} else if (tipo == 2 && _regionVacia(i,j,tipo)) { // Arbol
						matriz[i][j] = tipo;
						matriz[i+1][j] = 9;
						matriz[i+2][j] = 9;
					} else if (tipo == 3 && _regionVacia(i,j,tipo)) { // Monte
						matriz[i][j] = tipo;
						matriz[i][j+1] = 9;
						matriz[i][j+2] = 9;
						matriz[i+1][j] = 9;
						matriz[i+1][j+1] = 9;
						matriz[i+1][j+2] = 9;
						matriz[i+2][j] = 9;
						matriz[i+2][j+1] = 9;
						matriz[i+2][j+2] = 9;
					} else if (tipo == 4 && _regionVacia(i,j,tipo)) { // Roca
						matriz[i][j] = tipo;
						matriz[i][j+1] = 9;
						matriz[i+1][j] = 9;
						matriz[i+1][j+1] = 9;				
					}
				}
			}
		}
	}
}

bool Mapa::_colisiona() {
	return false;
}

Mapa::Mapa(Texture& t, Texture* tNaturaleza, Texture* tEnemigos) {
	natures = new ListaNaturaleza();
	enemies = new ListaEnemigos();	
	_generarMatriz();
	guardar();
	_posicionarNaturaleza(tNaturaleza);
	_posicionarEnemigos(tEnemigos);
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

int Mapa::getTotalEnemigos() {
	return enemies->getTotal();
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

void Mapa::guardar() {
	std::ofstream archivo;
	archivo.open("map.txt");
	for (int i = 0; i < FILA; i++) {
		for (int j = 0; j < COLUMNA; j++) {
			archivo << matriz[i][j] << " ";
		}
		archivo << "\n";
	}
	archivo.close();
}

void Mapa::dibujarEnemigos(RenderWindow& w) {
	enemies->dibujar(w);
}

void Mapa::moverEnemigos(Direccion* dir) {
	enemies->mover(dir);
}

void Mapa::cambiarDireccionEnemigos(Direccion* dir) {
	enemies->cambiarDirecciones(dir);
}