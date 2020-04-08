#include "Mapa.h"

void Mapa::inicializar_matriz() {
	matrizMapa = new int* [FILA];
	for (int i = 0; i < FILA; i++) {
		matrizMapa[i] = new int[COLUMNA];
		for (int j = 0; j < COLUMNA; j++)
			matrizMapa[i][j] = 0;
	}
}

bool Mapa::regionVacia(int i, int j) {
	return matrizMapa[i][j] == 0 && matrizMapa[i][j + 1] == 0 && matrizMapa[i][j + 2] == 0
		&& matrizMapa[i + 1][j] == 0 && matrizMapa[i + 1][j + 1] == 0 && matrizMapa[i + 1][j + 2] == 0
		&& matrizMapa[i + 2][j] == 0 && matrizMapa[i + 2][j + 1] == 0 && matrizMapa[i + 2][j + 2] == 0;
}

void Mapa::colocar_enemigos(sf::Texture* tEnemigos) {
	for (int i = 0; i < 5;) {
		int posX = (rand() % (COLUMNA - 4) + 2) * CUADRO;
		int posY = (rand()%(FILA - 4) + 2) * CUADRO;
		if (matrizMapa[posY / CUADRO][posX / CUADRO] == 0) {
			int tipo = rand() % 5;
			Animacion* a = new Animacion(tEnemigos[tipo], CUADRO, CUADRO, 4, 3, 0.40f);
			a->mov = Movimiento(rand() % 4 + 1);
			enemigos.push_back(new Enemigo(a, TipoEnemigo(tipo), posX, posY));
			i++;
		}
	}
}

void Mapa::colocar_decoracion(sf::Texture* naturales) {
	for (int i = 0; i < FILA; i++)
		for (int j = 0; j < COLUMNA; j++) {
			if (j == 0 || i == 0 || j == COLUMNA - 1 || i == FILA - 1) {
				matrizMapa[i][j] = 1;
				decoracion.push_back(new Naturaleza(naturales, TipoNatural::PIEDRA, j * CUADRO, i * CUADRO));
			}
			else if (i > 0 && i < FILA - 3 && j > 0 && j < COLUMNA - 3 && regionVacia(i, j)) {
				if (rand()%3 == 1) {
					TipoNatural tipo = TipoNatural(rand() % 4);
					decoracion.push_back(new Naturaleza(naturales, tipo, j * CUADRO, i * CUADRO));
					switch (tipo)
					{
					case TipoNatural::ARBOL:
						matrizMapa[i][j] = 2;
						matrizMapa[i + 1][j] = 2;
						matrizMapa[i + 2][j] = 1;
						break;
					case TipoNatural::MONTE:
						matrizMapa[i][j] = 2;
						matrizMapa[i][j+1] = 2;
						matrizMapa[i][j+2] = 2;
						matrizMapa[i+1][j] = 1;
						matrizMapa[i+1][j+1] = 1;
						matrizMapa[i+1][j+2] = 1;
						matrizMapa[i+2][j] = 1;
						matrizMapa[i+2][j+1] = 1;
						matrizMapa[i+2][j+2] = 1;
						break;
					case TipoNatural::ROCA:
						matrizMapa[i][j] = 2;
						matrizMapa[i][j+1] = 2;
						matrizMapa[i+1][j] = 1;
						matrizMapa[i+1][j+1] = 1;
						break;
					case TipoNatural::PIEDRA:
						matrizMapa[i][j] = 1;
					default:
						break;
					}
				}
			}
		}
}

Mapa::Mapa(){
	inicializar_matriz();
}
Mapa::Mapa(sf::Texture* terrenos, sf::Texture* naturales, sf::Texture* tEnemigos, TipoTerreno tipo){
	switch (tipo)
	{
	case TipoTerreno::GRASS:
		sprite.setTexture(terrenos[0]);
		break;
	case TipoTerreno::TIERRA:
		sprite.setTexture(terrenos[1]);
		break;
	case TipoTerreno::ARENA:
		sprite.setTexture(terrenos[2]);
		break;
	case TipoTerreno::ADOQUIN:
		sprite.setTexture(terrenos[3]);
		break;
	default:
		sprite.setTexture(terrenos[0]);
		break;
	}
	sprite.setTextureRect(sf::IntRect(0, 0, 1280, 720));
	inicializar_matriz();
	colocar_decoracion(naturales);
	colocar_enemigos(tEnemigos);
}
Mapa::~Mapa(){
	for (int i = 0; i < FILA; i++)
		delete[] matrizMapa[i];
	delete[] matrizMapa;
}

int** Mapa::getMatriz() { return matrizMapa; }

void Mapa::dibujar_fondo(sf::RenderWindow& w){
	w.draw(sprite);
}

void Mapa::dibujar_decoracion(sf::RenderWindow& w) {
	for (Naturaleza* n : decoracion)
		n->dibujar(w);
}

void Mapa::dibujar_enemigos(sf::RenderWindow& w) {
	for (Enemigo* e : enemigos)
		e->dibujar(w, matrizMapa);
}