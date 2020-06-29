#include "Mapa.h"
#include <iostream>

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

void Mapa::_posicionarCofres(Texture& tCofre) {
	int cantidad = rand()%4;
	cofres = new ListaCofres(cantidad);
	for (int i = 0; i < cantidad; i++) {
		while (true) {
			int posX = rand()%COLUMNA * CUADRO;
			int posY = rand()%FILA * CUADRO;
			if ( matriz[posY/CUADRO][posX/CUADRO] == 0) {
				cofres->agregar(new Cofre(tCofre, new Animacion(12, 4, 3, 0.0), posX, posY));
				break;
			}
		}

	}
	
}

void Mapa::_posicionarEnemigos(Texture* tEnemigos) {
	int cantidad = rand()%4 + 3;
	enemies = new ListaEnemigos(cantidad);
	for (int i = 0; i < cantidad; i++) {
		
		while (true) {
			int posX = rand()%COLUMNA * CUADRO;
			int posY = rand()%FILA * CUADRO;
			if(matriz[posY/CUADRO][posX/CUADRO] == 0) {
				int tipo = rand()%5;
				switch (tipo)
				{
				case 0:
					enemies->agregar(new Orco(tEnemigos[tipo], new Animacion(12, 4, 3, 0.2f, 2, 0, 1, 3), (float)posX, (float)posY));
					break;
				case 1:
					enemies->agregar(new Esqueleto(tEnemigos[tipo], new Animacion(12, 4, 3, 0.2f, 2, 0, 1, 3), (float)posX, (float)posY));
					break;
				case 2:
					enemies->agregar(new Murcielago(tEnemigos[tipo], new Animacion(12, 4, 3, 0.2f, 2, 0, 1, 3), (float)posX, (float)posY));
					break;
				case 3:
					enemies->agregar(new Espectro(tEnemigos[tipo], new Animacion(12, 4, 3, 0.2f, 2, 0, 1, 3), (float)posX, (float)posY));
					break;
				case 4:
					enemies->agregar(new Segador(tEnemigos[tipo], new Animacion(12, 4, 3, 0.2f, 2, 0, 1, 3), (float)posX, (float)posY));
					break;
				default:
					break;
				}
				//std::cout << "Enemigo " << enemies->getTotal() << ": (" << enemies->getUltimo()->getHitbox()->getX() << ";" << enemies->getUltimo()->getHitbox()->getY() << ")\n";
				break;
			}
		}
	}
}

void Mapa::_posicionarNaturaleza(Texture* tNaturaleza) {
	natures = new ListaNaturaleza(200);
	for (int i = 0; i < FILA; i++) {
		for (int j = 0; j < COLUMNA; j++) {
			if (matriz[i][j] == 1) {
				natures->agregar(new Piedra(tNaturaleza[3], j*CUADRO, i*CUADRO));
				//std::cout << "Elemento " << natures->getTotal() << ": (" << natures->getUltimo()->getHitbox()->getX() << ";" << natures->getUltimo()->getHitbox()->getY() << ")\n";
			} else if (matriz[i][j] == 2) {
				natures->agregar(new Arbol(tNaturaleza[0], j*CUADRO, i*CUADRO));
				//std::cout << "Elemento " << natures->getTotal() << ": (" << natures->getUltimo()->getHitbox()->getX() << ";" << natures->getUltimo()->getHitbox()->getY() << ")\n";
			} else if (matriz[i][j] == 3) {
				natures->agregar(new Monte(tNaturaleza[1], j*CUADRO, i*CUADRO));
				//std::cout << "Elemento " << natures->getTotal() << ": (" << natures->getUltimo()->getHitbox()->getX() << ";" << natures->getUltimo()->getHitbox()->getY() << ")\n";
			} else if (matriz[i][j] == 4) {
				natures->agregar(new Roca(tNaturaleza[2], j*CUADRO, i*CUADRO));
				//std::cout << "Elemento " << natures->getTotal() << ": (" << natures->getUltimo()->getHitbox()->getX() << ";" << natures->getUltimo()->getHitbox()->getY() << ")\n";
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

Mapa::Mapa(Texture& t, Texture* tNaturaleza, Texture* tEnemigos, Texture& tCofres) {
	_generarMatriz();
	guardar();
	_posicionarNaturaleza(tNaturaleza);
	_posicionarCofres(tCofres);
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

int Mapa::getTotalNatural() {
	return natures->getTotal();
}

ListaEnemigos* Mapa::getEnemigos() { return enemies; }
ListaNaturaleza* Mapa::getNaturalezas() { return natures; }
ListaCofres* Mapa::getCofres() { return cofres; }

void Mapa::dibujar(RenderWindow& w) {
	w.draw(sprite);
}

void Mapa::dibujarNaturalezaSuperior(RenderWindow& w) {
	natures->dibujarSuperiores(w);
}

void Mapa::dibujarNaturalezaInferior(RenderWindow& w) {
	natures->dibujarInferiores(w);
}

void Mapa::dibujarCofres(RenderWindow& w) {
	cofres->dibujar(w);
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

void Mapa::moverEnemigos() {
	enemies->mover();
}

void Mapa::cambiarDireccionEnemigos() {
	enemies->cambiarDirecciones();
}

void Mapa::colisionEnemigoDecoracion() {
	int cantidadEnemigos = enemies->getTotal();
	int cantidadNaturales = natures->getTotal();

	for (int i = 0; i < cantidadEnemigos; i++) {
		Enemigo* tempEnemy = enemies->getEnemigo(i);
		Hitbox* a = tempEnemy->getHitbox();
		for (int j = 0; j < cantidadNaturales; j++) {
			Naturaleza* tempNatural = natures->getNaturaleza(j);
			Hitbox* b = tempNatural->getHitbox();
			if(a->colisiona(b)) {
				if (tempEnemy->getDireccion() == ARRIBA) {
					tempEnemy->mover(ABAJO);
				} else if (tempEnemy->getDireccion() == ABAJO) {
					tempEnemy->mover(ARRIBA);
				} else if (tempEnemy->getDireccion() == DERECHA) {
					tempEnemy->mover(IZQUIERDA);
				} else if (tempEnemy->getDireccion() == IZQUIERDA) {
					tempEnemy->mover(DERECHA);
				}
				tempEnemy->cambiarDireccion();
			}
		}
		
	}
	
}